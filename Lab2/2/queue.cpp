#include "queue.h"

Queue::Queue() : front_node(nullptr), back_node(nullptr), element_count(0) {}

Queue::~Queue() {
    while (front_node != nullptr) {
        Node* temporary_node = front_node;
        front_node = front_node->next;
        delete temporary_node;
    }
}

void Queue::enqueue(int value) {
    Node* new_node = new Node(value);
    if (back_node == nullptr) {
        front_node = new_node;
        back_node = new_node;
    } else {
        back_node->next = new_node;
        back_node = new_node;
    }
    element_count++;
}

void Queue::dequeue() {
    if (front_node == nullptr) return;
    
    Node* temporary_node = front_node;
    front_node = front_node->next;
    if (front_node == nullptr) {
        back_node = nullptr;
    }
    delete temporary_node;
    element_count--;
}

bool Queue::is_empty() const {
    return front_node == nullptr;
}

int Queue::get_front() const {
    if (front_node == nullptr) {
        throw std::runtime_error("Queue is empty");
    }
    return front_node->data;
}

int Queue::get_size() const {
    return element_count;
}

void Queue::display_initial() const {
    Node* current_node = front_node;
    std::cout << std::endl << "Исходный адрес первого элемента: " << front_node << " " << front_node->data;
    std::cout << std::endl << "Исходная очередь: ";
    while (current_node != nullptr) {
        std::cout << current_node->data << " ";
        current_node = current_node->next;
    }
    std::cout << std::endl << "Исходный адрес последнего элемента: " << back_node << " " << back_node->data << std::endl;
}

void Queue::remove_first_n_elements(int n) {
    for (int i = 0; i < n; i++) {
        if (front_node == nullptr) break;
        Node* temporary_node = front_node;
        std::cout << temporary_node->data << " " << temporary_node->next << " ";
        front_node = front_node->next;
        delete temporary_node;
        element_count--;
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

void Queue::display_after_removal() const {
    if (front_node == nullptr) {
        std::cout << "Очередь после удаления элементов оказалась пустой" << std::endl;
        std::cout << "Начало очереди: " << nullptr << std::endl;
        std::cout << "Конец очереди: " << nullptr << std::endl;
    } else {
        std::cout << "Новое начало очереди: " << front_node << " " << front_node->data << std::endl;
        std::cout << "Оставшиеся элементы очереди: ";
        Node* current_node = front_node;
        Node* last_node = nullptr;
        while (current_node != nullptr) {
            last_node = current_node;
            std::cout << current_node->data << " ";
            current_node = current_node->next;
        }
        std::cout << std::endl << "Новый конец очереди: " << last_node << " " << last_node->data << std::endl;
    }
}

Queue create_queue_from_input(int& elements_to_remove) {
    int queue_size;
    Queue queue;
    
    std::cout << "Добро пожаловать!" << std::endl;
    std::cout << "Перед нами новая задача:" << std::endl;
    std::cout << "Дано число N (> 0) и указатели P1 и P2 на начало и конец непустой очереди." << std::endl;
    std::cout << "Извлечь из очереди N начальных элементов" << std::endl;
    std::cout << "---------------------------------------------------------" << std::endl;
    std::cout << "Вам необходимо ввести количество элементов очереди и их значения через пробел " << std::endl;
    std::cout << "Мы выведем новые адреса начала и конца очереди, извлечем n значений и выведем на экран" << std::endl;
    std::cout << std::endl << std::endl << "----------------------------------------------------------------------------" << std::endl;
    std::cout << "Введите число m - количество элементов очереди: ";
    std::cin >> queue_size;
    
    if (std::cin.fail() || queue_size <= 0) {
        std::cerr << "Ошибка ввода: m должно быть положительным целым числом." << std::endl;
        exit(1);
    }
    
    std::cout << std::endl << "Введите " << queue_size << " значений элементов очереди через пробел ";
    for (int i = 0; i < queue_size; i++) {
        int value;
        std::cin >> value;
        if (std::cin.fail()) {
            std::cerr << "Ошибка ввода: элемент очереди должен быть целым числом." << std::endl;
            exit(1);
        }
        queue.enqueue(value);
    }
    
    std::cout << std::endl << std::endl << "Введите число n(n>0) - количество элементов" << std::endl;
    std::cout << "очереди, которые нужно извлечь из очереди: ";
    std::cin >> elements_to_remove;
    
    if (std::cin.fail() || elements_to_remove <= 0) {
        std::cerr << "Ошибка ввода: n должно быть положительным целым числом." << std::endl;
        exit(1);
    }
    
    return queue;
}
