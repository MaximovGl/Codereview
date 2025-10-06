#include "containers.h"
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <iterator>
#include <vector>

bool fill_list(std::list<int>& container, int size) {
    int input_method;
    std::cout << "Выберите способ заполнения контейнера:" << std::endl;
    std::cout << "1) Ввод с клавиатуры" << std::endl;
    std::cout << "2) Заполнение случайными числами" << std::endl;
    std::cout << "3) Чтение из текстового файла" << std::endl;
    std::cin >> input_method;

    switch (input_method) {
    case 1: {
        std::vector<int> temp_vector;
        std::cout << "Введите " << size << " элементов: ";
        for (int i = 0; i < size; i++) {
            int value;
            std::cin >> value;
            temp_vector.push_back(value);
        }
        container = std::list<int>(temp_vector.begin(), temp_vector.end());
        return true;
    }

    case 2: {
        std::vector<int> temp_vector;
        std::srand(static_cast<unsigned>(std::time(0)));
        for (int i = 0; i < size; i++) {
            temp_vector.push_back(std::rand() % 101 - 50);
        }
        container = std::list<int>(temp_vector.begin(), temp_vector.end());
        return true;
    }

    case 3: {
        std::string filename;
        std::cout << "Введите имя файла: ";
        std::cin >> filename;
        
        std::ifstream input_file(filename);
        if (!input_file.is_open()) {
            std::cerr << "Ошибка: файл не открыт" << std::endl;
            return false;
        }
        
        std::vector<int> temp_vector;
        int value;
        for (int i = 0; i < size && input_file >> value; i++) {
            temp_vector.push_back(value);
        }
        
        if (temp_vector.size() != static_cast<size_t>(size)) {
            std::cerr << "Ошибка: в файле недостаточно данных" << std::endl;
            input_file.close();
            return false;
        }
        
        container = std::list<int>(temp_vector.begin(), temp_vector.end());
        input_file.close();
        return true;
    }

    default:
        std::cerr << "Ошибка: некорректный метод ввода" << std::endl;
        return false;
    }
}

void print_list(const std::list<int>& container) {
    for (std::list<int>::const_iterator iterator = container.begin(); 
         iterator != container.end(); ++iterator) {
        std::cout << *iterator << " ";
    }
    std::cout << std::endl;
}

void print_list_reverse(const std::list<int>& container) {
    for (std::list<int>::const_reverse_iterator reverse_iterator = container.rbegin(); 
         reverse_iterator != container.rend(); ++reverse_iterator) {
        std::cout << *reverse_iterator << " ";
    }
    std::cout << std::endl;
}

void move_middle_element(std::list<int>& source_list, std::list<int>& destination_list) {
    if (source_list.empty()) {
        std::cerr << "Ошибка: список источник пуст" << std::endl;
        return;
    }

    std::list<int>::iterator middle_iterator = source_list.begin();
    std::advance(middle_iterator, source_list.size() / 2);
    destination_list.splice(destination_list.end(), source_list, middle_iterator);
}
