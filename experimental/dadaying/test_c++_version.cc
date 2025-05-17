#include <iostream>

namespace {
    auto func_14 (const int num) { return num; }
}  // namespace

int main() {
    const int num_1 = 1;
    const auto num_2 = num_1;
    std::cout << "It is support c++11\n";
    const int num_3 = func_14(4);
    std::cout << "It is support c++14\n";
    [[mybe_unused]] const int num_4 = num_3;
    std::cout << "It is support c++17\n";
    return 0;
}