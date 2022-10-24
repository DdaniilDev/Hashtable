#include <iostream>
#include <vector>

#ifndef LAB_05_HASH_H
#define LAB_05_HASH_H

class Elem {

public:
    std::string input_str;
    int data;
    Elem* next;
    Elem();
    Elem(std::string basicString, int i);
};


#endif //LAB_05_HASH_H
