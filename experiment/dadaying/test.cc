#include <iostream>
#include <vector>

int main() {
    std::cout << "Hello World\n";
    std::cout << "__clang__: " << __clang__ << std::endl;
    std::cout << "__cplusplus: " << __cplusplus << std::endl;
    const std::vector<int> vec_nums(3, 1);
    std::cout << "vec nums:\n";
    for (int i = 0; i < vec_nums.size(); ++i) {
        std::cout << "i = " << i << ", num is:" << vec_nums[i] << "\n";
    }
    std::cout << "\n";
    return 0;
}