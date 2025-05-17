#ifndef COMMON_ALGORITHM_BINARY_INDEX_TREE_H_
#define COMMON_ALGORITHM_BINARY_INDEX_TREE_H_

#include <vector>

template <typename ValueType>
class BinaryIndexTree {
 public:
  explicit BinaryIndexTree(const std::vector<ValueType>& nums)
      : nums_(nums.size(), static_cast<ValueType>(0)) {
    for (int i = 0; i < nums_.size(); ++i) {
      Update(i, nums[i]);
    }
  }
  ~BinaryIndexTree() = default;

  void Update(const int index, const ValueType value) {
    const auto real_index = index + 1;
    for (int i = real_index; i <= nums_.size(); i += Lowbit(i)) {
      nums_[i - 1] += value;
    }
  }

  ValueType Query(const int index) const {
    const ValueType default_value = static_cast<ValueType>(0);
    const auto real_index = index + 1;
    ValueType sum = default_value;
    for (int i = real_index; i > 0; i -= Lowbit(i)) {
      sum += nums_[i - 1];
    }
    return sum;
  }

 private:
  int Lowbit(const int x) const { return x & -x; }

  std::vector<ValueType> nums_;
};

using BinaryIndexTreeInt = BinaryIndexTree<int>;

#endif  // COMMON_ALGORITHM_BINARY_INDEX_TREE_H_