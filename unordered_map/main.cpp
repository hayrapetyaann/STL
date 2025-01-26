#include <iostream>
#include "HashMap.h"

int main() {
    atlas::HashMap myMap;

    myMap.insert("apple", 10);
    myMap.insert("banana", 20);
    myMap.insert("grape", 30);

    std::cout << "HashMap contents:\n";
    myMap.print();

    int value;
    if (myMap.get("banana", value)) {
        std::cout << "Value for 'banana': " << value << "\n";
    } else {
        std::cout << "'banana' not found in the map.\n";
    }

    if (myMap.remove("apple")) {
        std::cout << "'Apple' removed from the map.\n";
    } else {
        std::cout << "'Apple' not found in the map.\n";
    }

    std::cout << "HashMap contents after removal:\n";
    myMap.print();

    return 0;
}
