#ifndef _QUEUE_HPP_
#define _QUEUE_HPP_

#include "Deque.hpp"

template<class T>
class Queue {
    private:
        //用deque作为底层实现queue
        Deque<T> _container;
    public:
        T front() {
            return _container.front();
        }
        T back() {
            return _container.back();
        }
        void push(T e) {
            _container.push_back(e);
        }
        void pop() {
            _container.pop_front();
        }
        bool empty() {
            return _container.empty();
        }
        int size() {
            return _container.size();
        }
};

#endif