#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <cstddef>
#include <initializer_list>
#include <stdexcept>
#include <iterator>
#include <algorithm>
#include <iostream>

namespace atlas {

template <typename T>
class vector {
private:
    T* m_ptr;
    std::size_t m_size;
    std::size_t m_cap;

    void resize();

public:
    using value_type = T;
    using reference = T&;
    using const_reference = const T&;
    using pointer = T*;
    using size_type = std::size_t;
    using difference_type = std::ptrdiff_t;

    vector();
    vector(std::initializer_list<T> init_list);
    explicit vector(size_type size);
    vector(const vector& other);
    vector(vector&& other) noexcept;
    vector& operator=(const vector& other);
    vector& operator=(vector&& other) noexcept;
    ~vector();

    reference operator[](size_type index);
    const_reference operator[](size_type index) const;
    size_type size() const;
    size_type capacity() const;
    bool empty() const;
    void reserve(size_type new_cap);
    void push_back(const T& value);
    void push_back(T&& value);
    void pop_back();
    reference at(size_type index);
    const_reference at(size_type index) const;
    void insert(size_type position, T&& value);
    void shrink_to_fit();
    void erase(size_type index);
    void clear();

    class Iterator {
    private:
        T* it;

    public:
        using value_type = T;
        using reference = T&;
        using const_reference = const T&;
        using pointer = T*;
        using difference_type = std::ptrdiff_t;
        using iterator_category = std::random_access_iterator_tag;

        Iterator(pointer ptr);
        reference operator*();
        const_reference operator*() const;
        pointer operator->();
        pointer operator->() const;
        Iterator& operator++();
        Iterator operator++(int);
        Iterator& operator--();
        Iterator operator--(int);
        Iterator operator+(difference_type n) const;
        Iterator operator-(difference_type n) const;
        difference_type operator-(const Iterator& other) const;
        bool operator==(const Iterator& other) const;
        bool operator!=(const Iterator& other) const;
    };

    class ConstIterator {
    private:
        const T* it;

    public:
        using value_type = T;
        using reference = const T&;
        using const_reference = const T&;
        using pointer = const T*;
        using difference_type = std::ptrdiff_t;
        using iterator_category = std::random_access_iterator_tag;

        ConstIterator(pointer ptr);
        reference operator*() const;
        pointer operator->() const;
        ConstIterator& operator++();
        ConstIterator operator++(int);
        ConstIterator& operator--();
        ConstIterator operator--(int);
        ConstIterator operator+(difference_type n) const;
        ConstIterator operator-(difference_type n) const;
        difference_type operator-(const ConstIterator& other) const;
        bool operator==(const ConstIterator& other) const;
        bool operator!=(const ConstIterator& other) const;
    };

    class ReverseIterator {
    private:
        T* it;

    public:
        using value_type = T;
        using reference = T&;
        using const_reference = const T&;
        using pointer = T*;
        using difference_type = std::ptrdiff_t;
        using iterator_category = std::random_access_iterator_tag;

        ReverseIterator(pointer ptr);
        reference operator*();
        const_reference operator*() const;
        pointer operator->();
        pointer operator->() const;
        ReverseIterator& operator++();
        ReverseIterator operator++(int);
        ReverseIterator& operator--();
        ReverseIterator operator--(int);
        ReverseIterator operator+(difference_type n) const;
        ReverseIterator operator-(difference_type n) const;
        difference_type operator-(const ReverseIterator& other) const;
        bool operator==(const ReverseIterator& other) const;
        bool operator!=(const ReverseIterator& other) const;
    };

    Iterator begin();
    Iterator end();
    ConstIterator begin() const;
    ConstIterator end() const;
    ReverseIterator rbegin();
    ReverseIterator rend();
};

} // namespace atlas

#include "vector.cpp"

#endif 
