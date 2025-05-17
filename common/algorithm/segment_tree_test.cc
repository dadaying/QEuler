#include "common/algorithm/segment_tree.h"

#include <numeric>
#include <vector>

#include "gtest/gtest.h"

TEST(SegmentTreeTest, ConstructorInt) {
  constexpr int kNumSize = 10;
  std::vector<int> nums(kNumSize);
  std::iota(nums.begin(), nums.end(), -3);
  // nums = {-3, -2, -1, 0, 1, 2, 3, 4, 5, 6}
  qeuler::SegmentTreeInt segment_tree(nums);
  for (int i = 0; i < nums.size(); ++i) {
    int sum = 0;
    for (int j = i; j < nums.size(); ++j) {
      sum += nums[j];
      EXPECT_EQ(segment_tree.QueryInterval(i, j), sum);
    }
  }
}

TEST(SegmentTreeTest, ConstructorDouble) {
  constexpr int kNumSize = 10;
  std::vector<double> nums(kNumSize);
  std::iota(nums.begin(), nums.end(), -3.2);
  // nums = {-3.2, -2.2, -1.2, 0.2, 1.2, 2.2, 3.2, 4.2, 5.2, 6.2}
  qeuler::SegmentTreeDouble segment_tree(nums);
  for (int i = 0; i < nums.size(); ++i) {
    double sum = 0.0;
    for (int j = i; j < nums.size(); ++j) {
      sum += nums[j];
      EXPECT_DOUBLE_EQ(segment_tree.QueryInterval(i, j), sum);
    }
  }
}

TEST(SegmentTreeTest, UpdateIntervalInt) {
  constexpr int kNumSize = 10;
  std::vector<int> nums(kNumSize);
  std::iota(nums.begin(), nums.end(), -3);
  // nums = {-3, -2, -1, 0, 1, 2, 3, 4, 5, 6}
  qeuler::SegmentTreeInt segment_tree(nums);
  const std::vector<std::vector<int>> update_intervals = {
      {0, 0, 0},  {0, 0, 1}, {0, 9, 2},  {0, 9, -4}, {4, 9, 3},
      {0, 4, -2}, {4, 9, 1}, {4, 5, -1}, {5, 8, 0},  {3, 6, -3},
  };
  for (const auto& update_interval : update_intervals) {
    const int left = update_interval[0];
    const int right = update_interval[1];
    const int value = update_interval[2];
    for (int i = left; i <= right; ++i) {
      nums[i] += value;
    }
    segment_tree.UpdateInterval(left, right, value);
    for (int i = 0; i < nums.size(); ++i) {
      int sum = 0;
      for (int j = i; j < nums.size(); ++j) {
        sum += nums[j];
        EXPECT_EQ(segment_tree.QueryInterval(i, j), sum);
      }
    }
  }
}

int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
