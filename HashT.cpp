#include <iostream>
#include <vector>
#include "Elem.h"
#include "HashT.h"

Table::Table() {
    Elems.resize(table_size);
}

void Table::push(std::string input_str, int data) {
    uint64_t hash_index = get_hash(input_str);
    Elem *temp = new Elem(input_str, data);
    if(Elems[hash_index] == nullptr) {
        Elems[hash_index] = temp;
    }
    else {
        Elem *head = Elems[hash_index];
        temp->next = head;
        Elems[hash_index] = temp;
    }
}

int Table::get_hash(std::string str) {
    uint64_t result = 0;
    uint64_t table_constant = 1;
    for (size_t i = 0; i < str.length(); ++i) {
        result += table_constant * int(str[i]);
        table_constant = (this->tab_const * table_constant) % this->table_size;
    }
    return result % this->table_size;
}

void Table::search(std::string input_str) {
    uint64_t hash_index = get_hash(input_str);
    Elem *current = Elems[hash_index];
    if (current == nullptr) {
        std::cout << "Element" << " " << input_str << " " <<  "not found" << std::endl;
    }
    while(current->input_str != input_str) {
        if (!current->next) {
            std::cout << "Element" << " " << input_str << " " <<  "not found" << std::endl;
            break;
        }
        current = current->next;
    }
}

void Table::print() {
    for(int i = 0; i < this->table_size; i++)
    {
        if(Elems[i] != nullptr)
        {
            Elem *current = Elems[i];
            while (current != nullptr)
            {
                std::cout << current->data << " ";
                current = current->next;
            }
            std::cout << std::endl;
        }
    }

}

void Table::remove(std::string input_str) {
    uint64_t hash_index = get_hash(input_str);
    Elem *current = Elems[hash_index];
    if (Elems[hash_index] == nullptr) {
        std::cout << "Fail, because element is not found!" << std::endl;
        return;
    }
    if (current->input_str == input_str) {
        if (current->next == nullptr) {
            Elems[hash_index] = nullptr;
            return;
        } else {
            Elems[hash_index] = current->next;
            delete current;
            return;
        }
    } else {
        if (current->next == nullptr) {
            std::cout << "Fail, because element is not found!" << std::endl;
            return;
        }
        while (current->next != nullptr) {
            if (current->next->input_str == input_str) {
                current = current->next;
                current->next = current->next->next;
            }
        }
        current->next = nullptr;
        delete current;
    }
}








