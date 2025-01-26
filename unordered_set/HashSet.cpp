#include "HashSet.h"
#include <iostream>

namespace atlas {

    void HashSet::insert(int key) {
        size_t index = hashFunction(key);
        for (int val : m_table[index]) {
            if (val == key) {
                return;
            }
        }
        m_table[index].push_back(key);
    }

    void HashSet::remove(int key) {
        size_t index = hashFunction(key);
        m_table[index].remove(key);
    }

    bool HashSet::contains(int key) {
        size_t index = hashFunction(key);
        for (int val : m_table[index]) {
            if (val == key) {
                return true;
            }
        }
        return false;
    }

    void HashSet::print() {
        for (int i = 0; i < capacity; i++) {
            if (!m_table[i].empty()) {
                std::cout << "Bucket " << i << ": ";
                for (int val : m_table[i]) {
                    std::cout << val << " ";
                }
                std::cout << std::endl;
            }
        }
    }

} // namespace atlas
