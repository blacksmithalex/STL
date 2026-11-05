/*
    Поиск минимального элемента — аналог std::min_element
    
    Принцип работы: предполагаем, что первый элемент минимальный. 
    Затем последовательно сравниваем его с остальными. 
    Если найден меньший элемент, обновляем итератор минимума.
*/

#include <iostream>
#include <vector>
using namespace std;

// Собственная реализация min_element
template <typename Iterator>
Iterator my_min_element(Iterator first, Iterator last) {
    if (first == last) {
        return last;
    }
    Iterator min_it = first;
    first++;
    
    while (first != last) {
        if (*min_it > *first){
            min_it = first;
        }
        first++;
    }
    return min_it;
}

int main() {
    vector<int> v = {12, 45, 7, 89, 23};

    auto it = my_min_element(v.begin(), v.end());

    if (it != v.end()) {
        cout << "Minimum: " << *it << endl;
    }

    return 0;
}
