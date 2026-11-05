/*
    Поиск максимального элемента — аналог std::max_element
    
    Принцип работы: предполагаем, что первый элемент максимальный. 
    Затем последовательно сравниваем его с остальными. 
    Если найден больший элемент, обновляем итератор максимума.
*/

#include <iostream>
#include <vector>
using namespace std;

// Собственная реализация max_element
template <typename Iterator>
Iterator my_max_element(Iterator first, Iterator last) {
    if (first == last) {
        return last;
    }
    Iterator max_it = first;
    first++;
    
    while (first != last) {
        if (*max_it < *first){
            max_it = first;
        }
        first++;
    }
    return max_it;
}

int main() {
    vector<int> v = {12, 45, 7, 89, 23};

    auto it = my_max_element(v.begin(), v.end());

    if (it != v.end()) {
        cout << "Maximum: " << *it << endl;
    }

    return 0;
}
