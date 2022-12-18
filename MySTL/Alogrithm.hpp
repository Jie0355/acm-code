#ifndef _ALGORITHM_H_
#define _ALGORITHM_H_

namespace mySTL {
    /* Copy */
    template<class Iterator>
    Iterator copy(Iterator _first, Iterator _last, Iterator _result) {

    }
    /* Search */
    template<class Iterator, class T>
    Iterator binary_search(Iterator _first, Iterator _last, const T& value) {

    }
    /* MAX & MIN*/
    template<class T>
    T& max(T& a, T& b) {
        return a > b ? a : b;
    }
    template<class T, class Cmp>
    T& max(T& a, T& b) {
        return Cmp(a, b) ? a : b;
    }
    template<class T>
    T& min(T& a, T& b) {
        return a < b ? a : b;
    }
    template<class T, class Cmp>
    T& min(T& a, T& b) {
        return !Cmp(a, b) ? a : b;
    }
    /* Swap */
    template<class T>
    void swap(T& a, T& b) {
        T t = a;
        a = b;
        b = t;
    }

}

#endif