#include <iostream>
#include "QueueList.h"

bool IsEven(int i) {
    return !(bool)(i % 2);
}

std::ostream& operator<<(std::ostream& out, const MyType& mt){
    out << mt.a << ": " << mt.c << "\n";
}

int main() {

    // double
    size_t size = 10;
    double* a = new double[size];
    for (size_t i = 0; i < size; ++i) {
        a[i] = rand() % 100;
    }

    QueueList<double> ql(a, size);

    // 1
    for (auto pos : ql) {
        std::cout << pos << " ";
    }
    std::cout << "\n";

    // 2
    for(auto &pos : ql){
        std::cout << ++pos << " ";
    }
    std::cout << "\n";

    // 3
    int elem;
    std::cout << "Enter element: "; std::cin >> elem;
    Iterator<double> it = std::find(ql.begin(), ql.end(), elem);
    if (it == ql.end()) {
        std::cout << "No such item!\n";
    }
    else std::cout << *it << "\n";

    // 4
    std::cout << "Minimal element: " << *std::min_element(ql.begin(), ql.end()) << "\n";

    // 5
    std::cout << "Max element: " << *std::max_element(ql.begin(), ql.end()) << "\n";

    // 6
    std::cout << "Number of even elements: " << std::count_if(ql.begin(), ql.end(), IsEven) << "\n";

    // 7
    std::cout << "Enter element: "; std::cin >> elem;
    std::for_each(ql.begin(), ql.end(), [&elem](auto& i) { if (i > elem){ i += 10; }
        else { i -= 10; } });
    for (auto pos : ql) {
        std::cout << pos << " ";
    }
    std::cout << "\n";

    // MyType
    MyType* arr = new MyType[3];
    for (int i = 0; i < 3; ++i) {
        MyType mt = { "s" , i };
        arr[i] = mt;
    }

    QueueList<MyType> ql1(arr, 3);

    MyType mt = { "New", 5 };
    ql1.push_back(mt);

    for (auto pos : ql1) {
        std::cout << pos;
    }

    std::cout << "Max: " << *std::max_element(ql1.begin(), ql1.end());
    return 0;
}
