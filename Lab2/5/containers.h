#ifndef CONTAINERS_H
#define CONTAINERS_H

#include <list>
#include <iostream>

bool fill_list(std::list<int>& container, int size);
void print_list(const std::list<int>& container);
void print_list_reverse(const std::list<int>& container);
void move_middle_element(std::list<int>& source_list, std::list<int>& destination_list);

#endif
