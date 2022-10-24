#include <iostream>
#include <vector>
#include "Elem.h"

#ifndef LAB_05_HASHT_H
#define LAB_05_HASHT_H

class Table {
private:
    int table_size = 10000537;
    int tab_const = 999;
public:
    Table();
    void push(std::string input_str, int data);
    int get_hash(std::string str);
    void search(std::string input_str);
    void print();
    void remove(std::string input_str);

    std::vector<Elem *> Elems;
};


#endif //LAB_05_HASHT_H
