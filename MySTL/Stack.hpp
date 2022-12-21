#ifndef _STACK_HPP_
#define _STACK_HPP_

#include "Deque.hpp"

template<class T>
class Stack {
    private:
        //用deque作为底层实现stack
        Deque<T> _container;
    public:
        T top() {
            return _container.back();
        }
        void push(T e) {
            _container.push_back(e);
        }
        void pop() {
            _container.pop_back();
        }
        bool empty() {
            return _container.empty();
        }
        int size() {
            return _container.size();
        }
};

#endif