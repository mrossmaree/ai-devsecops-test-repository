#include <iostream>

int add(int first, int second) {
    return first + second;
}

int main() {
    const int result = add(10, 20);
    std::cout << "Result: " << result << '\n';
    return 0;
}