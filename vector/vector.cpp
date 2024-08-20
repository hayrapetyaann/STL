#include "vector.hpp"

namespace atlas {

    template <typename T>
    vector<T>::vector() : m_ptr(nullptr), m_size(0), m_cap(0) {}

    template <typename T>
    vector<T>::vector(std::initializer_list<T> init_list) : m_ptr(nullptr), m_size(0), m_cap(0) {
        reserve(init_list.size());
        for (const T& value : init_list) {
            m_ptr[m_size++] = value;
        }
    }

    template <typename T>
    vector<T>::vector(size_type size) : m_ptr(new T[size]()), m_size(size), m_cap(size) {}

    template <typename T>
    vector<T>::vector(const vector& other) : m_ptr(new T[other.m_cap]), m_size(other.m_size), m_cap(other.m_cap) {
        std::copy(other.m_ptr, other.m_ptr + other.m_size, m_ptr);
    }

    template <typename T>
    vector<T>::vector(vector&& other) noexcept : m_ptr(other.m_ptr), m_size(other.m_size), m_cap(other.m_cap) {
        other.m_ptr = nullptr;
        other.m_size = 0;
        other.m_cap = 0;
    }

    template <typename T>
    vector<T>& vector<T>::operator=(const vector& other) {
        if (this != &other) {
            T* new_ptr = new T[other.m_cap];
            std::copy(other.m_ptr, other.m_ptr + other.m_size, new_ptr);
            delete[] m_ptr;
            m_ptr = new_ptr;
            m_size = other.m_size;
            m_cap = other.m_cap;
        }
        return *this;
    }

    template <typename T>
    vector<T>& vector<T>::operator=(vector&& other) noexcept {
        if (this != &other) {
            delete[] m_ptr;
            m_ptr = other.m_ptr;
            m_size = other.m_size;
            m_cap = other.m_cap;
            other.m_ptr = nullptr;
            other.m_size = 0;
            other.m_cap = 0;
        }
        return *this;
    }

    template <typename T>
    typename vector<T>::reference vector<T>::operator[](size_type index) {
        return m_ptr[index];
    }

    template <typename T>
    typename vector<T>::const_reference vector<T>::operator[](size_type index) const {
        return m_ptr[index];
    }

    template <typename T>
    typename vector<T>::size_type vector<T>::size() const {
        return m_size;
    }

    template <typename T>
    typename vector<T>::size_type vector<T>::capacity() const {
        return m_cap;
    }

    template <typename T>
    bool vector<T>::empty() const {
        return m_size == 0;
    }

    template <typename T>
    void vector<T>::reserve(size_type new_cap) {
        if (new_cap > m_cap) {
            T* new_ptr = new T[new_cap];
            std::move(m_ptr, m_ptr + m_size, new_ptr);
            delete[] m_ptr;
            m_ptr = new_ptr;
            m_cap = new_cap;
        }
    }

    template <typename T>
    void vector<T>::resize() {
        size_type new_cap = m_cap ? m_cap * 2 : 1;
        reserve(new_cap);
    }

    template <typename T>
    void vector<T>::push_back(const T& value) {
        if (m_size == m_cap) {
            resize();
        }
        m_ptr[m_size++] = value;
    }

    template <typename T>
    void vector<T>::push_back(T&& value) {
        if (m_size == m_cap) {
            resize();
        }
        m_ptr[m_size++] = std::move(value);
    }

    template <typename T>
    void vector<T>::pop_back() {
        if (m_size > 0) {
            --m_size;
        }
    }

    template <typename T>
    typename vector<T>::reference vector<T>::at(size_type index) {
        if (index >= m_size) {
            throw std::out_of_range("Index out of range");
        }
        return m_ptr[index];
    }

    template <typename T>
    typename vector<T>::const_reference vector<T>::at(size_type index) const {
        if (index >= m_size) {
            throw std::out_of_range("Index out of range");
        }
        return m_ptr[index];
    }

    template <typename T>
    void vector<T>::insert(size_type position, T&& value) {
        if (position > m_size) {
            throw std::out_of_range("Index out of range");
        }
        if (m_size == m_cap) {
            resize();
        }
        std::move_backward(m_ptr + position, m_ptr + m_size, m_ptr + m_size + 1);
        m_ptr[position] = std::move(value);
        ++m_size;
    }

    template <typename T>
    void vector<T>::shrink_to_fit() {
        if (m_size < m_cap) {
            T* new_ptr = new T[m_size];
            std::move(m_ptr, m_ptr + m_size, new_ptr);
            delete[] m_ptr;
            m_ptr = new_ptr;
            m_cap = m_size;
        }
    }

    template <typename T>
    void vector<T>::erase(size_type index) {
        if (index >= m_size) {
            throw std::out_of_range("Index out of range");
        }
        std::move(m_ptr + index + 1, m_ptr + m_size, m_ptr + index);
        --m_size;
    }

    template <typename T>
    void vector<T>::clear() {
        m_size = 0;
    }

    template <typename T>
    vector<T>::~vector() {
        delete[] m_ptr;
    }

    template <typename T>
    vector<T>::Iterator::Iterator(pointer ptr) : it(ptr) {}

    template <typename T>
    typename vector<T>::Iterator::reference vector<T>::Iterator::operator*() {
        return *it;
    }

    template <typename T>
    typename vector<T>::Iterator::const_reference vector<T>::Iterator::operator*() const {
        return *it;
    }

    template <typename T>
    typename vector<T>::Iterator::pointer vector<T>::Iterator::operator->() {
        return it;
    }

    template <typename T>
    typename vector<T>::Iterator::pointer vector<T>::Iterator::operator->() const {
        return it;
    }

    template <typename T>
    typename vector<T>::Iterator& vector<T>::Iterator::operator++() {
        ++it;
        return *this;
    }

    template <typename T>
    typename vector<T>::Iterator vector<T>::Iterator::operator++(int) {
        Iterator tmp = *this;
        ++it;
        return tmp;
    }

    template <typename T>
    typename vector<T>::Iterator& vector<T>::Iterator::operator--() {
        --it;
        return *this;
    }

    template <typename T>
    typename vector<T>::Iterator vector<T>::Iterator::operator--(int) {
        Iterator tmp = *this;
        --it;
        return tmp;
    }

    template <typename T>
    typename vector<T>::Iterator vector<T>::Iterator::operator+(difference_type n) const {
        return Iterator(it + n);
    }

    template <typename T>
    typename vector<T>::Iterator vector<T>::Iterator::operator-(difference_type n) const {
        return Iterator(it - n);
    }

    template <typename T>
    typename vector<T>::Iterator::difference_type vector<T>::Iterator::operator-(const Iterator& other) const {
        return it - other.it;
    }

    template <typename T>
    bool vector<T>::Iterator::operator==(const Iterator& other) const {
        return it == other.it;
    }

    template <typename T>
    bool vector<T>::Iterator::operator!=(const Iterator& other) const {
        return it != other.it;
    }

    template <typename T>
    vector<T>::ConstIterator::ConstIterator(pointer ptr) : it(ptr) {}

    template <typename T>
    typename vector<T>::ConstIterator::reference vector<T>::ConstIterator::operator*() const {
        return *it;
    }

    template <typename T>
    typename vector<T>::ConstIterator::pointer vector<T>::ConstIterator::operator->() const {
        return it;
    }

    template <typename T>
    typename vector<T>::ConstIterator& vector<T>::ConstIterator::operator++() {
        ++it;
        return *this;
    }

    template <typename T>
    typename vector<T>::ConstIterator vector<T>::ConstIterator::operator++(int) {
        ConstIterator tmp = *this;
        ++it;
        return tmp;
    }

    template <typename T>
    typename vector<T>::ConstIterator& vector<T>::ConstIterator::operator--() {
        --it;
        return *this;
    }

    template <typename T>
    typename vector<T>::ConstIterator vector<T>::ConstIterator::operator--(int) {
        ConstIterator tmp = *this;
        --it;
        return tmp;
    }

    template <typename T>
    typename vector<T>::ConstIterator vector<T>::ConstIterator::operator+(difference_type n) const {
        return ConstIterator(it + n);
    }

    template <typename T>
    typename vector<T>::ConstIterator vector<T>::ConstIterator::operator-(difference_type n) const {
        return ConstIterator(it - n);
    }

    template <typename T>
    typename vector<T>::ConstIterator::difference_type vector<T>::ConstIterator::operator-(const ConstIterator& other) const {
        return it - other.it;
    }

    template <typename T>
    bool vector<T>::ConstIterator::operator==(const ConstIterator& other) const {
        return it == other.it;
    }

    template <typename T>
    bool vector<T>::ConstIterator::operator!=(const ConstIterator& other) const {
        return it != other.it;
    }

    template <typename T>
    vector<T>::ReverseIterator::ReverseIterator(pointer ptr) : it(ptr) {}

    template <typename T>
    typename vector<T>::ReverseIterator::reference vector<T>::ReverseIterator::operator*() {
        return *it;
    }

    template <typename T>
    typename vector<T>::ReverseIterator::const_reference vector<T>::ReverseIterator::operator*() const {
        return *it;
    }

    template <typename T>
    typename vector<T>::ReverseIterator::pointer vector<T>::ReverseIterator::operator->() {
        return it;
    }

    template <typename T>
    typename vector<T>::ReverseIterator::pointer vector<T>::ReverseIterator::operator->() const {
        return it;
    }

    template <typename T>
    typename vector<T>::ReverseIterator& vector<T>::ReverseIterator::operator++() {
        --it;
        return *this;
    }

    template <typename T>
    typename vector<T>::ReverseIterator vector<T>::ReverseIterator::operator++(int) {
        ReverseIterator tmp = *this;
        --it;
        return tmp;
    }

    template <typename T>
    typename vector<T>::ReverseIterator& vector<T>::ReverseIterator::operator--() {
        ++it;
        return *this;
    }

    template <typename T>
    typename vector<T>::ReverseIterator vector<T>::ReverseIterator::operator--(int) {
        ReverseIterator tmp = *this;
        ++it;
        return tmp;
    }

    template <typename T>
    typename vector<T>::ReverseIterator vector<T>::ReverseIterator::operator+(difference_type n) const {
        return ReverseIterator(it - n);
    }

    template <typename T>
    typename vector<T>::ReverseIterator vector<T>::ReverseIterator::operator-(difference_type n) const {
        return ReverseIterator(it + n);
    }

    template <typename T>
    typename vector<T>::ReverseIterator::difference_type vector<T>::ReverseIterator::operator-(const ReverseIterator& other) const {
        return other.it - it;
    }

    template <typename T>
    bool vector<T>::ReverseIterator::operator==(const ReverseIterator& other) const {
        return it == other.it;
    }

    template <typename T>
    bool vector<T>::ReverseIterator::operator!=(const ReverseIterator& other) const {
        return it != other.it;
    }

    template <typename T>
    typename vector<T>::Iterator vector<T>::begin() {
        return Iterator(m_ptr);
    }

    template <typename T>
    typename vector<T>::Iterator vector<T>::end() {
        return Iterator(m_ptr + m_size);
    }

    template <typename T>
    typename vector<T>::ConstIterator vector<T>::begin() const {
        return ConstIterator(m_ptr);
    }

    template <typename T>
    typename vector<T>::ConstIterator vector<T>::end() const {
        return ConstIterator(m_ptr + m_size);
    }

    template <typename T>
    typename vector<T>::ReverseIterator vector<T>::rbegin() {
        return ReverseIterator(m_ptr + m_size - 1);
    }

    template <typename T>
    typename vector<T>::ReverseIterator vector<T>::rend() {
        return ReverseIterator(m_ptr - 1);
    }

} // namespace atlas
