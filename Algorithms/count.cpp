/*
    Аналог: std::count
    
    Принцип работы: проходим по всем элементам и увеличиваем 
    счётчик при каждом совпадении с заданным значением.
*/
#include <iostream>
#include <vector>
using namespace std;

// Собственная реализация count
template <typename Iterator, typename T>
int my_count(Iterator first, Iterator last, const T& value) {
    int counter;
    
    while (first != last) {
        if (*first == value) {
            counter++;
        } 
        first++;
    }
    
    return counter;
}

int main() {
    vector<int> v = {1, 2, 3, 2, 4, 2, 5};

    cout << "Count of 2: "
         << my_count(v.begin(), v.end(), 2)
         << endl;

    cout << "Count of 5: "
         << my_count(v.begin(), v.end(), 5)
         << endl;

    return 0;
}
