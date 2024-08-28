#include "list.hpp"

namespace atlas {

    template <typename T>
    T& List<T>::iterator::operator*() { return node->m_data; }

    template <typename T>
    T* List<T>::iterator::operator->() { return &(node->m_data); }

    template <typename T>
    typename List<T>::iterator& List<T>::iterator::operator++() { 
        node = node->m_next; 
        return *this; 
    }

    template <typename T>
    typename List<T>::iterator List<T>::iterator::operator++(int) {
        iterator temp = *this;
        node = node->m_next;
        return temp;
    }

    template <typename T>
    typename List<T>::iterator& List<T>::iterator::operator--() { 
        node = node->m_prev; 
        return *this; 
    }

    template <typename T>
    typename List<T>::iterator List<T>::iterator::operator--(int) {
        iterator temp = *this;
        node = node->m_prev;
        return temp;
    }

    template <typename T>
    bool List<T>::iterator::operator==(const iterator& other) const { return node == other.node; }

    template <typename T>
    bool List<T>::iterator::operator!=(const iterator& other) const { return node != other.node; }

    template <typename T>
    typename List<T>::Node* List<T>::iterator::get_node() const { return node; }

    template <typename T>
    const T& List<T>::const_iterator::operator*() const { return node->m_data; }

    template <typename T>
    const T* List<T>::const_iterator::operator->() const { return &(node->m_data); }

    template <typename T>
    typename List<T>::const_iterator& List<T>::const_iterator::operator++() { 
        node = node->m_next; 
        return *this; 
    }

    template <typename T>
    typename List<T>::const_iterator List<T>::const_iterator::operator++(int) {
        const_iterator temp = *this;
        node = node->m_next;
        return temp;
    }

    template <typename T>
    typename List<T>::const_iterator& List<T>::const_iterator::operator--() { 
        node = node->m_prev; 
        return *this; 
    }

    template <typename T>
    typename List<T>::const_iterator List<T>::const_iterator::operator--(int) {
        const_iterator temp = *this;
        node = node->m_prev;
        return temp;
    }

    template <typename T>
    bool List<T>::const_iterator::operator==(const const_iterator& other) const { return node == other.node; }

    template <typename T>
    bool List<T>::const_iterator::operator!=(const const_iterator& other) const { return node != other.node; }

    template <typename T>
    const typename List<T>::Node* List<T>::const_iterator::get_node() const { return node; }

    template <typename T>
    T& List<T>::reverse_iterator::operator*() { return node->m_data; }

    template <typename T>
    T* List<T>::reverse_iterator::operator->() { return &(node->m_data); }

    template <typename T>
    typename List<T>::reverse_iterator& List<T>::reverse_iterator::operator++() {
        node = node->m_prev;
        return *this;
    }

    template <typename T>
    typename List<T>::reverse_iterator List<T>::reverse_iterator::operator++(int) {
        reverse_iterator temp = *this;
        node = node->m_prev;
        return temp;
    }

    template <typename T>
    typename List<T>::reverse_iterator& List<T>::reverse_iterator::operator--() {
        node = node->m_next;
        return *this;
    }

    template <typename T>
    typename List<T>::reverse_iterator List<T>::reverse_iterator::operator--(int) {
        reverse_iterator temp = *this;
        node = node->m_next;
        return temp;
    }

    template <typename T>
    bool List<T>::reverse_iterator::operator==(const reverse_iterator& other) const { return node == other.node; }

    template <typename T>
    bool List<T>::reverse_iterator::operator!=(const reverse_iterator& other) const { return node != other.node; }

    template <typename T>
    typename List<T>::Node* List<T>::reverse_iterator::get_node() const { return node; }

    template <typename T>
    const T& List<T>::const_reverse_iterator::operator*() const { return node->m_data; }

    template <typename T>
    const T* List<T>::const_reverse_iterator::operator->() const { return &(node->m_data); }

    template <typename T>
    typename List<T>::const_reverse_iterator& List<T>::const_reverse_iterator::operator++() {
        node = node->m_prev;
        return *this;
    }

    template <typename T>
    typename List<T>::const_reverse_iterator List<T>::const_reverse_iterator::operator++(int) {
        const_reverse_iterator temp = *this;
        node = node->m_prev;
        return temp;
    }

    template <typename T>
    typename List<T>::const_reverse_iterator& List<T>::const_reverse_iterator::operator--() {
        node = node->m_next;
        return *this;
    }

    template <typename T>
    typename List<T>::const_reverse_iterator List<T>::const_reverse_iterator::operator--(int) {
        const_reverse_iterator temp = *this;
        node = node->m_next;
        return temp;
    }

    template <typename T>
    bool List<T>::const_reverse_iterator::operator==(const const_reverse_iterator& other) const { return node == other.node; }

    template <typename T>
    bool List<T>::const_reverse_iterator::operator!=(const const_reverse_iterator& other) const { return node != other.node; }

    template <typename T>
    const typename List<T>::Node* List<T>::const_reverse_iterator::get_node() const { return node; }

    template <typename T>
    List<T>::List() : m_head(nullptr), m_tail(nullptr), m_node_count(0) {}

    template <typename T>
    List<T>::List(size_type count) : m_head(nullptr), m_tail(nullptr), m_node_count(0) {
        while (count--) push_back(T());
    }

    template <typename T>
    List<T>::List(const List& other) : m_head(nullptr), m_tail(nullptr), m_node_count(0) {
        for (auto it = other.begin(); it != other.end(); ++it) {
            push_back(*it);
        }
    }

    template <typename T>
    List<T>::List(List&& other) noexcept : m_head(other.m_head), m_tail(other.m_tail), m_node_count(other.m_node_count) {
        other.m_head = other.m_tail = nullptr;
        other.m_node_count = 0;
    }

    template <typename T>
    List<T>& List<T>::operator=(const List& other) {
        if (this == &other) return *this;
        clear();
        for (auto it = other.begin(); it != other.end(); ++it) {
            push_back(*it);
        }
        return *this;
    }

    template <typename T>
    List<T>& List<T>::operator=(List&& other) noexcept {
        if (this == &other) return *this;
        clear();
        m_head = other.m_head;
        m_tail = other.m_tail;
        m_node_count = other.m_node_count;
        other.m_head = other.m_tail = nullptr;
        other.m_node_count = 0;
        return *this;
    }

    template <typename T>
    List<T>::~List() {
        clear();
    }

    template <typename T>
    bool List<T>::empty() const { return m_node_count == 0; }

    template <typename T>
    typename List<T>::size_type List<T>::size() const { return m_node_count; }

    template <typename T>
    typename List<T>::reference List<T>::front() { return m_head->m_data; }

    template <typename T>
    typename List<T>::const_reference List<T>::front() const { return m_head->m_data; }

    template <typename T>
    typename List<T>::reference List<T>::back() { return m_tail->m_data; }

    template <typename T>
    typename List<T>::const_reference List<T>::back() const { return m_tail->m_data; }

    template <typename T>
    typename List<T>::iterator List<T>::begin() { return iterator(m_head); }

    template <typename T>
    typename List<T>::iterator List<T>::end() { return iterator(nullptr); }

    template <typename T>
    typename List<T>::const_iterator List<T>::begin() const { return const_iterator(m_head); }

    template <typename T>
    typename List<T>::const_iterator List<T>::end() const { return const_iterator(nullptr); }

    template <typename T>
    typename List<T>::reverse_iterator List<T>::rbegin() { return reverse_iterator(m_tail); }

    template <typename T>
    typename List<T>::reverse_iterator List<T>::rend() { return reverse_iterator(nullptr); }

    template <typename T>
    typename List<T>::const_reverse_iterator List<T>::rbegin() const { return const_reverse_iterator(m_tail); }

    template <typename T>
    typename List<T>::const_reverse_iterator List<T>::rend() const { return const_reverse_iterator(nullptr); }

    template <typename T>
    typename List<T>::const_iterator List<T>::cbegin() const { return const_iterator(m_head); }

    template <typename T>
    typename List<T>::const_iterator List<T>::cend() const { return const_iterator(nullptr); }

    template <typename T>
    typename List<T>::const_reverse_iterator List<T>::crbegin() const { return const_reverse_iterator(m_tail); }

    template <typename T>
    typename List<T>::const_reverse_iterator List<T>::crend() const { return const_reverse_iterator(nullptr); }

    template <typename T>
    void List<T>::clear() {
        Node* current = m_head;
        while (current) {
            Node* tmp = current->m_next;
            delete current;
            current = tmp;
        }
        m_head = m_tail = nullptr;
        m_node_count = 0;
    }

    template <typename T>
    void List<T>::push_back(const T& value) {
        Node* new_node = new Node(value);
        if (m_tail) {
            m_tail->m_next = new_node;
            new_node->m_prev = m_tail;
            m_tail = new_node;
        } else {
            m_head = m_tail = new_node;
        }
        ++m_node_count;
    }

    template <typename T>
    void List<T>::pop_back() {
        if (!m_tail) return;
        Node* old_m_tail = m_tail;
        m_tail = m_tail->m_prev;
        if (m_tail) {
            m_tail->m_next = nullptr;
        } else {
            m_head = nullptr;
        }
        delete old_m_tail;
        --m_node_count;
    }

    template <typename T>
    void List<T>::push_front(const T& value) {
        Node* new_node = new Node(value);
        if (m_head) {
            m_head->m_prev = new_node;
            new_node->m_next = m_head;
            m_head = new_node;
        } else {
            m_head = m_tail = new_node;
        }
        ++m_node_count;
    }

    template <typename T>
    void List<T>::pop_front() {
        if (!m_head) return;
        Node* old_m_head = m_head;
        m_head = m_head->m_next;
        if (m_head) {
            m_head->m_prev = nullptr;
        } else {
            m_tail = nullptr;
        }
        delete old_m_head;
        --m_node_count;
    }

    template <typename T>
    typename List<T>::iterator List<T>::insert(iterator position, const T& value) {
        if (position == begin()) {
            push_front(value);
            return begin();
        }

        if (position == end()) {
            push_back(value);
            return iterator(m_tail);
        }

        Node* m_next_node = position.get_node();
        Node* m_prev_node = m_next_node->m_prev;
        Node* new_node = new Node(value);

        new_node->m_next = m_next_node;
        new_node->m_prev = m_prev_node;
        m_prev_node->m_next = new_node;
        m_next_node->m_prev = new_node;

        ++m_node_count;
        return iterator(new_node);
    }

    template <typename T>
    typename List<T>::iterator List<T>::erase(iterator position) {
        Node* node_to_remove = position.get_node();
        if (!node_to_remove) return end();

        Node* m_prev_node = node_to_remove->m_prev;
        Node* m_next_node = node_to_remove->m_next;

        if (m_prev_node) { m_prev_node->m_next = m_next_node; }
        else { m_head = m_next_node; }

        if (m_next_node) m_next_node->m_prev = m_prev_node;
        else m_tail = m_prev_node;

        delete node_to_remove;
        --m_node_count;

        return iterator(m_next_node);
    }

    template <typename T>
    void List<T>::swap(List& other) {
        std::swap(m_head, other.m_head);
        std::swap(m_tail, other.m_tail);
        std::swap(m_node_count, other.m_node_count);
    }

    template <typename T>
    void List<T>::reverse() {
        Node* current = m_head;
        Node* temp = nullptr;
        while (current) {
            temp = current->m_prev;
            current->m_prev = current->m_next;
            current->m_next = temp;
            current = current->m_prev;
        }

        if (temp) { 
            m_head = temp->m_prev;
        }
    }

    template <typename T>
    void List<T>::sort() {
        if (m_node_count < 2) return;

        for (iterator i = begin(); i != end(); ++i) {
            for (iterator j = i; j != end(); ++j) {
                if (*j < *i) std::swap(*i, *j);
            }
        }
    }

} // namespace atlas

