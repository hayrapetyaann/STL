#include "HashMap.h"
#include <iostream>

namespace atlas {

    HashMap::HashMap(int cap) : capacity(cap) {
        table.resize(capacity);
    }

    int HashMap::hashFunction(const std::string& key) const {
        int hash = 0;
        for (char c : key) {
            hash = (hash * 31 + c) % capacity;
        }
        return hash;
    }

    void HashMap::insert(const std::string& key, int value) {
        int hashIndex = hashFunction(key);
        auto& bucket = table[hashIndex];
        
        for (auto& kv : bucket) {
            if (kv.key == key) {
                kv.value = value;
                return;
            }
        }

        bucket.push_back(KeyValue(key, value));
    }

    bool HashMap::get(const std::string& key, int& value) const {
        int hashIndex = hashFunction(key);
        const auto& bucket = table[hashIndex];

        for (const auto& kv : bucket) {
            if (kv.key == key) {
                value = kv.value;
                return true;
            }
        }

        return false;
    }

    bool HashMap::remove(const std::string& key) {
        int hashIndex = hashFunction(key);
        auto& bucket = table[hashIndex];

        for (auto it = bucket.begin(); it != bucket.end(); ++it) {
            if (it->key == key) {
                bucket.erase(it);
                return true;
            }
        }

        return false;
    }

    void HashMap::print() const {
        for (int i = 0; i < capacity; ++i) {
            const auto& bucket = table[i];
            for (const auto& kv : bucket) {
                std::cout << kv.key << " -> " << kv.value << "\n";
            }
        }
    }

} // namespace atlas
