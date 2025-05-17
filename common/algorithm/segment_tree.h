#ifndef COMMON_ALGORITHM_SEGMENT_TREE_H_
#define COMMON_ALGORITHM_SEGMENT_TREE_H_

#include <iostream>
#include <vector>

namespace qeuler {

template <typename ValueType, typename ReturnType>
class SegmentTree {
 public:
  explicit SegmentTree(const std::vector<ValueType>& nums) : num_(nums.size()) {
    tree_.resize(num_ * 4);
    marks_.resize(num_ * 4);
    Build(nums, init_left_, num_, init_node_);
  }
  ~SegmentTree() = default;

  void UpdateInterval(const int update_left, const int update_right,
                      const ValueType value) {
    // The outer index starts at 0, the inner index starts at 1.
    UpdateIntervalImpl(init_left_, num_, update_left + 1, update_right + 1,
                       value, init_node_);
  }

  ReturnType QueryInterval(const int query_left, const int query_right) {
    // The outer index starts at 0, the inner index starts at 1.
    return QueryIntervalImpl(init_left_, num_, query_left + 1, query_right + 1,
                             init_node_);
  }

  // For debug.
  void PrintTreeAndMarks() const {
    for (int i = 0; i < tree_.size(); i++) {
      std::cout << "i=" << i << ", tree_[i]=" << tree_[i]
                << ", marks_[i]=" << marks_[i] << std::endl;
    }
  }

 private:
  void Build(const std::vector<ValueType>& nums, const int left,
             const int right, const int node) {
    if (left == right) {
      // The outer index starts at 0, the inner index starts at 1.
      tree_[node] = nums[left - 1];
      return;
    }
    const int mid = GetMid(left, right);
    Build(nums, left, mid, GetLeftChild(node));
    Build(nums, mid + 1, right, GetRightChild(node));
    tree_[node] = tree_[GetLeftChild(node)] + tree_[GetRightChild(node)];
  }

  void UpdateIntervalImpl(const int left, const int right,
                          const int update_left, const int update_right,
                          const ValueType value, const int node) {
    // The update interval does not intersect with the target interval.
    if (update_left > right || update_right < left) {
      return;
    }
    // The update interval contains the target interval.
    if (update_left <= left && update_right >= right) {
      tree_[node] += value * (right - left + 1);
      if (left != right) {
        marks_[node] += value;
      }
      return;
    }
    // The update interval does intersect with the target interval.
    const int mid = GetMid(left, right);
    PushDown(node, right - left + 1);
    UpdateIntervalImpl(left, mid, update_left, update_right, value,
                       GetLeftChild(node));
    UpdateIntervalImpl(mid + 1, right, update_left, update_right, value,
                       GetRightChild(node));
    tree_[node] = tree_[GetLeftChild(node)] + tree_[GetRightChild(node)];
  }

  ReturnType QueryIntervalImpl(const int left, const int right,
                               const int query_left, const int query_right,
                               const int node) {
    // The query interval does not intersect with the target interval.
    if (query_left > right || query_right < left) {
      return static_cast<ReturnType>(0);
    }
    // The query interval contains the target interval.
    if (query_left <= left && query_right >= right) {
      return tree_[node];
    }
    // The query interval does intersect with the target interval.
    const int mid = GetMid(left, right);
    PushDown(node, right - left + 1);
    const ReturnType left_sum = QueryIntervalImpl(
        left, mid, query_left, query_right, GetLeftChild(node));
    const ReturnType right_sum = QueryIntervalImpl(
        mid + 1, right, query_left, query_right, GetRightChild(node));
    return left_sum + right_sum;
  }

  int GetLeftChild(const int node) const { return 2 * node; }

  int GetRightChild(const int node) const { return 2 * node + 1; }

  int GetMid(const int left, const int right) const {
    return (left + right) / 2;
  }

  void PushDown(const int node, const int length) {
    if (length == 1) {
      return;
    }
    marks_[GetLeftChild(node)] += marks_[node];
    marks_[GetRightChild(node)] += marks_[node];
    tree_[GetLeftChild(node)] += marks_[node] * (length - length / 2);
    tree_[GetRightChild(node)] += marks_[node] * (length / 2);
    marks_[node] = static_cast<ReturnType>(0);
  }

  std::vector<ReturnType> tree_;
  std::vector<ReturnType> marks_;
  const int num_ = 0;
  const int init_left_ = 1;
  const int init_node_ = 1;
};

using SegmentTreeInt = SegmentTree<int, long long int>;
using SegmentTreeDouble = SegmentTree<double, double>;

}  // namespace qeuler

#endif  // COMMON_ALGORITHM_SEGMENT_TREE_H_