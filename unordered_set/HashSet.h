#ifndef HASHSET_H
#define HASHSET_H

#include <vector>
#include <list>
#include <cstddef>
#include <iostream>

namespace atlas {

    class HashSet {
    private:
        std::vector<std::list<int>> m_table;
        size_t capacity;

        size_t hashFunction(int key) {
            return key % capacity;
        }

    public:
        HashSet(size_t cap) : capacity(cap), m_table(cap) {}

        void insert(int key);
        void remove(int key);
        bool contains(int key);
        void print();
    };

} // namespace atlas

#endif
