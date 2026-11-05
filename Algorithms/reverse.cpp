/*
    Разворот последовательности — аналог std::reverse
    
    Принцип работы: используем два итератора, указывающих 
    на начало и конец последовательности. Меняем соответствующие 
    элементы местами, постепенно двигаясь к центру.
*/

#include <iostream>
#include <vector>
#include <iterator>
#include <utility>
using namespace std;

template <typename T> 
void my_swap(T &a, T &b) {
    T tmp = a;
    a = b;
    b = tmp;
}

// Собственная реализация reverse
template <typename Iterator>
void my_reverse(Iterator first, Iterator last) {
    while(first != last){
        last--;
        if (first == last) {
            break;
        }
        my_swap(*first, *last);
        first++;
    }
}

int main() {
    vector<int> v = {1, 2, 3, 4, 5};

    my_reverse(v.begin(), v.end());

    cout << "Reversed: ";

    for (int x : v) {
        cout << x << " ";
    }

    cout << endl;
    return 0;
}
