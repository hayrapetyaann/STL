#include <iostream>
#include "HashSet.h"

int main() {
    atlas::HashSet mySet(10);
    mySet.insert(5);
    mySet.insert(15);
    mySet.insert(15);
    mySet.insert(15);
    mySet.insert(15);
    mySet.insert(15);
    mySet.insert(15);
    mySet.insert(34);
    mySet.insert(23);
    mySet.insert(90);
    mySet.insert(33);

    mySet.print();
    return 0;
}
