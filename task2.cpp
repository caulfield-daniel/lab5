#include <iostream>
#include <list>

template <typename T>
class PriorityQueue {
private:
    // Создание очереди с приоритетами на основе стандартной библиотеки list
    std::list<std::pair<int, T>> list;

public:
    // Функция для добавления элемента в очередь с приоритетом
    void push(int priority, const T& data) {
        // Итерация по элементам очереди с приоритетами, пока не найдем
        // элемент с приоритетом меньшим или равным переданному приоритету
        auto it = list.begin();
        while (it != list.end() && it->first > priority) {
            it++;
        }
        // Вставка элемента перед найденным итератором
        list.insert(it, std::make_pair(priority, data));
    }

    // Функция для извлечения элемента с наивысшим приоритетом из очереди
    std::pair<int, T> pop() {
        if (list.empty()) {
            // Проверка очереди на пустоту
            throw std::runtime_error("Queue is empty");
        }
        // Итерация по элементам очереди с приоритетами и извлечение
        // элемента с наивысшим приоритетом
        auto it = list.begin();
        std::pair<int, T> element = *it;
        list.erase(it);
        return element;
    }

    // Функция для проверки очереди на пустоту
    bool isEmpty() const {
        return list.empty();
    }

    // Функция для получения количества элементов в очереди
    int size() const {
        return list.size();
    }

    // Функция для печати очереди с приоритетами
    void print() const {
        std::cout << "Queue: ";
        for (const auto& element : list) {
            std::cout << element.first << " " << element.second << " ";
        }
        std::cout << std::endl;
    }
};

int main() {
  
  // Обработка исключений
    try {
        // Инстанцирование шаблона для типов int, double, std::string
        PriorityQueue<int> intQueue;
        PriorityQueue<double> doubleQueue;
        PriorityQueue<std::string> stringQueue;

        // Добавление элементов в очереди с приоритетами
        intQueue.push(3, 10);
        intQueue.push(1, 20);
        intQueue.push(2, 30);

        doubleQueue.push(3, 1.5);
        doubleQueue.push(1, 2.5);
        doubleQueue.push(2, 3.5);

        stringQueue.push(3, "hello");
        stringQueue.push(1, "world");
        stringQueue.push(2, "!");

        // Проверка размера очередей и пустоты
        std::cout << "Size of intQueue: " << intQueue.size() << std::endl;
        std::cout << "Size of doubleQueue: " << doubleQueue.size() << std::endl;
        std::cout << "Size of stringQueue: " << stringQueue.size() << std::endl;

        std::cout << "Is intQueue empty? " << (intQueue.isEmpty() ? "Yes" : "No") << std::endl;
        std::cout << "Is doubleQueue empty? " << (doubleQueue.isEmpty() ? "Yes" : "No") << std::endl;
        std::cout << "Is stringQueue empty? " << (stringQueue.isEmpty() ? "Yes" : "No") << std::endl;

        // Извлечение элементов из очередей с приоритетами
        std::cout << "Popped from intQueue: " << intQueue.pop().second << std::endl;
        std::cout << "Popped from doubleQueue: " << doubleQueue.pop().second << std::endl;
        std::cout << "Popped from stringQueue: " << stringQueue.pop().second << std::endl;

        // Проверка размера очередей и пустоты после извлечения элементов
        std::cout << "Size of intQueue: " << intQueue.size() << std::endl;
        std::cout << "Size of doubleQueue: " << doubleQueue.size() << std::endl;
        std::cout << "Size of stringQueue: " << stringQueue.size() << std::endl;

        // Если очередь пуста - "Yes", в противном случае - "No"
        std::cout << "Is intQueue empty? " << (intQueue.isEmpty() ? "Yes" : "No") << std::endl;
        std::cout << "Is doubleQueue empty? " << (doubleQueue.isEmpty() ? "Yes" : "No") << std::endl;
        std::cout << "Is stringQueue empty? " << (stringQueue.isEmpty() ? "Yes" : "No") << std::endl;

        // Печать очередей
        intQueue.print();
        doubleQueue.print();
        stringQueue.print();
      
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}
