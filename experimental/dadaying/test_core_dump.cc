#include <iostream>

int main() {
    int *test_core_dump = nullptr;
    std::cout << "I want to crash...\n";
    int num = *test_core_dump;
    std::cout << "num: " << num << std::endl;
    return 0;
}