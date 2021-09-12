#include "QueueList.h"

template<class T>
QueueList<T>::QueueList(T* arr, size_t size)
{
    _len = size;
    _capacity = size + 10;
    _array = new T[_capacity];
    for (size_t i = 0; i < size; ++i) {
        _array[i] = arr[i];
    }
}

template<class T>
QueueList<T>::QueueList(QueueList const& other) : _len(other._len), _capacity(other._capacity)
{
    if (_capacity == 1)
        _array = new T[1];
    else
    {
        _array = new T[_capacity];
        for (size_t i = 0; i < _len; ++i)
            _array[i] = other._array[i];

    }
}

template<class T>
QueueList<T>& QueueList<T>::operator=(QueueList const& other){
    if (this != &other)
    {
        if (_capacity != other._capacity)
        {
            delete[] _array;
            _capacity = other._capacity;
            _array = new T[_capacity];
        }
        _len = other._len;
        for (size_t i = 0; i < _len; ++i)
            _array[i] = other._array[i];

    }
    return *this;
}

template<class T>
Iterator<T> operator+(typename Iterator<T>::difference_type const& diff, Iterator<T> const& it)
{
    return Iterator<T>(it._pos + diff);
}

template<class T>
Iterator<T> QueueList<T>::begin() const
{
    return Iterator<T>(&_array[0]);
}

template<class T>
Iterator<T> QueueList<T>::end() const
{
    return Iterator<T>(&_array[_len]);
}

template<class T>
void QueueList<T>::clear() {
    if(!empty()){
        delete[] _array;
        _len = 0;
        _capacity = 1;
        _array = new T[_capacity];
    }
}

template<class T>
void QueueList<T>::push_back(T a) {
    if ((_len + 1) == _capacity){
        _capacity += 10;
        T* newarray = new T[_capacity];
        for (size_t i = 0; i < _capacity - 10; ++i) {
            newarray[i] = _array[i];
        }
        delete[] _array;
        _array = newarray;
    }
    _array[_len] = a;
    _len++;
}

template<class T>
T QueueList<T>::pop_front() {
    T tmp = _array[0];
    T* newarray = new T[_capacity];
    for (int i = 1; i < _len; ++i) {
        newarray[i - 1] = _array[i];
    }
    delete[] _array;
    _array = newarray;
    return tmp;
}
