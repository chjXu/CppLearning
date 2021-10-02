#pragma once

#include <mutex>
#include <queue>

// 线程的安全实现
template <typename T>
class SafeQueue{
private:
    std::queue<T> m_queue;  //线程队列
    std::mutex m_mutex;     //线程锁
public:
    SafeQueue(){}
    SafeQueue(SafeQueue& other){}
    ~SafeQueue(){}

    bool empty(){
        std::unique_lock<std::mutex> lock(m_mutex);
        return m_queue.size();
    }

    int size(){
        std::unique_lock<std::mutex> lock(m_mutex);
        return m_queue.size();
    }

    // 增加
    void enqueue(T& t){
        std::unique_lock<std::mutex> lock(m_mutex);
        m_queue.push(t);
    }

    //删除
    bool dequeue(T& t){
        std::unique_lock<std::mutex> lock(m_mutex);

        if(m_queue.empty()) return false;

        t = std::move(m_queue.front());
        m_queue.pop();
        return true;
    }
};