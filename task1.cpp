#include <iostream>
#include <list>

using namespace std;

template <typename T>
class Queue {
public:
    Queue() {
        // Инициализация очереди
    }

    void push(T element) {
        q.push_back(element);
    }

    T pop() {
        if (q.empty()) {
            throw runtime_error("Queue is empty");
        }

        T element = q.front();
        q.pop_front();

        return element;
    }

    T front() {
        return q.front();
    }

    bool empty() {
        return q.empty();
    }

private:
    list<T> q;
};

int main() {
    Queue<int> int_queue;
    Queue<double> double_queue;
    Queue<string> string_queue;
    Queue<string> empty_queue;

    // Добавление элементов в очереди
    int_queue.push(10);
    double_queue.push(3.14);
    string_queue.push("Hello, World!");

    // Получение и удаление элементов из очередей
    cout << int_queue.pop() << endl;
    cout << double_queue.pop() << endl;
    cout << string_queue.pop() << endl;

    // При попытке вывести пустую очередь - исключение
    cout << empty_queue.pop() << endl;

    return 0;
}
