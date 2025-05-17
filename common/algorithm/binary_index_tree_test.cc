#include "common/algorithm/binary_index_tree.h"

#include <memory>
#include <vector>

#include "gtest/gtest.h"

class BinaryIndexTreeIntTest : public ::testing::Test {
 public:
  BinaryIndexTreeIntTest() = default;
  ~BinaryIndexTreeIntTest() = default;

  void SetUp() override {
    binary_index_tree_ = std::make_shared<BinaryIndexTreeInt>(nums_);
  }

 protected:
  std::shared_ptr<BinaryIndexTreeInt> binary_index_tree_ = nullptr;
  std::vector<int> nums_ = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
};

TEST_F(BinaryIndexTreeIntTest, ConstructTest) {
  EXPECT_TRUE(binary_index_tree_ != nullptr);
  int sum = 0;
  for (int i = 0; i < nums_.size(); ++i) {
    sum += nums_[i];
    EXPECT_EQ(binary_index_tree_->Query(i), sum);
  }
}

TEST_F(BinaryIndexTreeIntTest, UpdateTest) {
  EXPECT_TRUE(binary_index_tree_ != nullptr);
  for (int i = 0; i < nums_.size(); ++i) {
    const auto update_index = i;
    const auto update_value = 2 * i + 1;
    binary_index_tree_->Update(update_index, update_value);
    nums_[update_index] += update_value;
    int sum = 0;
    for (int j = 0; j <= update_index; ++j) {
      sum += nums_[j];
      EXPECT_EQ(binary_index_tree_->Query(j), sum);
    }
  }
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}