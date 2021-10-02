#pragma once

#include <functional>
#include <future>
#include <mutex>
#include <queue>
#include <thread>
#include <utility>
#include <vector>

#include "SafeQueue.h"

class ThreadPool{
private:
    class ThreadWorker{
    private:
        int m_id;
        ThreadPool *m_pool;
    public:
        ThreadWorker(ThreadPool *pool, const int id):
            m_pool(pool), m_id(id){}

        void operator()(){
            std::function<void()> func;
            bool dequeued;
            while(!m_pool->m_shutdown){
                {
                    std::unique_lock<std::mutex> lock(m_pool->m_conditional_mutex);
                    if(m_pool->m_queue.empty()){
                        m_pool->m_conditional_lock.wait(lock);
                    }
                    dequeued = m_pool->m_queue.dequeue(func);
                }
                if(dequeued){
                    func();
                }
            }
        }
    };

    bool m_shutdown;
    SafeQueue<std::function<void()>> m_queue;
    std::vector<std::thread> m_threads;
    std::mutex m_conditional_mutex;
    std::condition_variable m_conditional_lock;

public:
    ThreadPool(const int n_threads)
        : m_threads(std::vector<std::thread>(n_threads)), m_shutdown(false){}

    ThreadPool(const ThreadPool &) = delete;    //禁止使用该函数
    ThreadPool(ThreadPool &&) = delete;      //禁止使用该函数

    ThreadPool & operator=(const ThreadPool &) = delete;     //禁止使用该函数
    ThreadPool & operator=(ThreadPool &) = delete;       //禁止使用该函数

    // 初始化线程池
    void init(){
        for(int i=0; i<m_threads.size(); ++i)
            m_threads[i] = std::thread(ThreadWorker(this, i));
    }

    // 等待线程结束它们当前的任务并关闭池子
    void shutdown(){
        m_shutdown = true;
        m_conditional_lock.notify_all();

        for(int i=0; i<m_threads.size(); ++i){
            if(m_threads[i].joinable()){
                m_threads[i].join();
            }
        }
    }

    // 提交一个由线程池异步执行的函数
    template<typename F, typename...Args>
    auto submit(F&& f, Args&&... args) -> std::future<decltype(f(args...))>{
        // 创建一个具有有限参数的函数，以便执行
        std::function<decltype(f(args...))()> func = std::bind(std::forward<F>(f), std::forward<Args>(args)...);
        // 将其封装到共享ptr中，以便能够复制构造/赋值
        auto task_ptr = std::make_shared<std::packaged_task<decltype(f(args...))()>>(func);

        // 将打包的任务封装到void函数中
        std::function<void()> wrapper_func = [task_ptr](){
            (*task_ptr)();
        };

        // 排队通用包装器函数
        m_queue.enqueue(wrapper_func);

        // 唤醒一个正在等待的线程
        m_conditional_lock.notify_one();

        // 从承诺中返回未来
        return task_ptr->get_future();
    }
};