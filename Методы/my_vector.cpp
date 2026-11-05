/*
    push_back() — добавить элемент в конец.
    pop_back() — удалить последний элемент.
    size() — получить количество элементов.
    empty() — проверить, пуст ли контейнер.
    clear() — удалить все элементы.
*/

#include <iostream>
#include <stdexcept>
using namespace std;

template <typename T>
class MyVector {
private:
    T* data;
    size_t count;
    size_t capacity;

public:
    // Конструктор
    MyVector() {
        data = nullptr;
        count = 0;
        capacity = 0;
    }

    // Деструктор
    ~MyVector() {
        delete[] data;
    }

    // 1. Добавление элемента
    void push_back(const T& value) {
        if (count == capacity) {
            size_t new_capacity = (capacity == 0) ? 1 : capacity * 2;

            T* new_data = new T[new_capacity];

            for (size_t i = 0; i < count; i++) {
                new_data[i] = data[i];
            }

            delete[] data;
            data = new_data;
            capacity = new_capacity;
        }

        data[count] = value;
        count++;
    }

    // 2. Удаление последнего элемента
    void pop_back() {
        if (count == 0) {
            throw out_of_range("Vector is empty");
        }

        count--;
    }

    // 3. Количество элементов
    size_t size() const {
        return count;
    }

    // 4. Проверка на пустоту
    bool empty() const {
        return count == 0;
    }

    // 5. Очистка контейнера
    void clear() {
        count = 0;
    }

    // Дополнительный оператор для доступа к элементам
    T& operator[](size_t index) {
        return data[index];
    }
};

int main() {
    MyVector<int> v;

    v.push_back(10);
    v.push_back(20);
    v.push_back(30);

    cout << "Elements: ";
    for (size_t i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }

    cout << "\nSize: " << v.size() << endl;

    v.pop_back();

    cout << "After pop_back: ";
    for (size_t i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }

    cout << "\nEmpty: " << boolalpha << v.empty() << endl;

    v.clear();

    cout << "After clear, size: " << v.size() << endl;
    cout << "Empty: " << v.empty() << endl;

    return 0;
}