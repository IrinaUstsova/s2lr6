#ifndef QUEUELIST_H
#define QUEUELIST_H

#include <algorithm>
#include <iterator>

struct MyType{
    std::string _a;
    int _c;
    bool operator<(const MyType& other) {
      return _c < other._c;
    }
};

template<class T>
class Iterator {
    T* _pos;
        public:
            using iterator_category = std::random_access_iterator_tag;
            using value_type = T;
            using difference_type = int;
            using pointer = T*;
            using reference = T&;
            Iterator(T* pos) : _pos(pos) {}
            bool operator==(Iterator const& other) const
            {
                return _pos == other._pos;
            }
            bool operator!=(Iterator const& other) const
            {
                return _pos != other._pos;
            }
            reference operator*() const
            {
                return *_pos;
            }
            pointer operator->() const
            {
                return _pos;
            }
            Iterator<T>& operator++()
            {
                ++_pos;
                return *this;
            }
            Iterator<T> operator++(int)
            {
                Iterator<T> tmp = *this;
                ++_pos;
                return tmp;
            }
            Iterator<T>& operator--()
            {
                --_pos;
                return *this;
            }
            Iterator<T> operator--(int)
            {
                Iterator<T> tmp = *this;
                --_pos;
                return tmp;
            }
            reference operator[](size_t index) const
            {
                return _pos[index];
            }
            Iterator<T> operator+(difference_type const& diff) const
            {
                return Iterator<T>(_pos + diff);
            }
            friend inline Iterator<T> operator+(difference_type const& diff, Iterator<T> const& it);
            Iterator<T> operator-(difference_type const& diff) const
            {
                return Iterator<T>(_pos - diff);
            }
            difference_type operator-(Iterator<T> const& other) const
            {
                return std::distance(other._pos, _pos);
            }
            Iterator<T>& operator+=(difference_type const& diff){
                _pos += diff;
                return *this;
            }
            Iterator<T>& operator-=(difference_type const& diff){
                _pos -= diff;
                return *this;
            }
            bool operator>(Iterator<T> const& other) const
            {
                return _pos > other._pos;
            }
            bool operator<(Iterator<T> const& other) const
            {
            return _pos < other._pos;
            }
            bool operator>=(Iterator<T> const& other) const
            {
                return _pos >= other._pos;
            }
            bool operator<=(Iterator<T> const& other) const
            {
                return _pos <= other._pos;
            }
        };

template<class T>
class QueueList {
    T* _array;
    size_t _len;
    size_t _capacity;
        public:
            QueueList(T* arr, size_t size);
            size_t length() const
            {
                return _len;
            }
            size_t size() const
            {
                return _len;
            }
            size_t capacity() const
            {
                return _capacity - 1;
            }
            T front() const
            {
                return _array[0];
            }
            T back() const
            {
                return _array[_len - 1];
            }
            bool empty()
            {
                return !_len;
            }
            void clear();
            void push_back(T a);
            T pop_front();
            ~QueueList()
            {
                delete[] _array;
            }
            QueueList<T>(QueueList<T> const& other);
            QueueList<T>& operator=(QueueList<T> const& other);
            Iterator<T> begin() const;
            Iterator<T> end() const;
        };

#endif