#ifndef HASHMAP_H
#define HASHMAP_H

#include <string>
#include <vector>
#include <list>
#include <iostream>

namespace atlas {

    class HashMap {
    private:
        struct KeyValue {
            std::string key;
            int value;
            KeyValue(std::string k, int v) : key(k), value(v) {}
        };

        std::vector<std::list<KeyValue>> table;
        int capacity;

        int hashFunction(const std::string& key) const;

    public:
        HashMap(int cap = 10);

        void insert(const std::string& key, int value);
        bool get(const std::string& key, int& value) const;
        bool remove(const std::string& key);
        void print() const;
    };

}

#endif // HASHMAP_H
