#include <iostream>
#include "HashT.h"

int main() {
    /*int elements_number;
    int tab_const;
    size_t first_it = 0;
    size_t second_it = 0;
    std::cout << "Enter a number of your elements: "; std::cin >> elements_number;
    std::cout << "Enter a constant: "; std::cin >> tab_const;
    Table* example = new Table(elements_number, tab_const); //создание таблицы
    while(first_it < elements_number) {
        std::string str_value;
        int data_value;
        std::cout << "Enter a string key: "; std::cin >> str_value;
        std::cout << "Enter a value: ";  std::cin >> data_value;
        example->push(str_value, data_value);
        ++first_it;
    }
    while (second_it < elements_number) {
        example->print();
        ++second_it;
        break;
    }*/
    Table* example = new Table();
    example->push("str5", 10);
    example->push("str2", 6);
    example->push("str3", 1);
    example->push("str4", 7);
    example->push("str5", 9);
    example->print();
    std::string s_el;
    std::string deleted_el;
    std::cout << "Deleting: "; std::cin >> deleted_el;
    example->remove(deleted_el);
    std::cout << "Searching: "; std::cin >> s_el;
    example->search(s_el);
    std::cout <<  "Ending";
}

