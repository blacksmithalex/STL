/*
     Принцип работы: последовательно просматриваем элементы контейнера. 
     Если найдено искомое значение, возвращаем итератор на него. 
     Если значение отсутствует — возвращаем last.

     template — ключевое слово, объявляющее шаблон.
     typename — указывает, что следующий идентификатор обозначает параметр типа.
     Iterator — произвольное имя типа итератора.
     T — произвольное имя типа искомого значения.
*/
#include <iostream>
#include <vector>
using namespace std;

// Собственная реализация find
template <typename Iterator, typename T>
Iterator my_find(Iterator first, Iterator last, const T& value) {
    while (first != last) {
        if (*first == value) {
            return first;
        }
        ++first;
    }
    return last;
}

int main() {
    vector<int> v = {10, 20, 30, 40, 50};

    auto it = my_find(v.begin(), v.end(), 30);

    if (it != v.end()) {
        cout << "Element found: " << *it << endl;
    } else {
        cout << "Element not found" << endl;
    }

    return 0;
}
