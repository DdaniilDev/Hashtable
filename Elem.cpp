#include <iostream>
#include <list>
#include "Elem.h"

Elem::Elem() {
    this->next = nullptr;
}

Elem::Elem(std::string basicString, int i) {
    this->input_str = basicString;
    this->data = i;
    this->next = nullptr;
}
