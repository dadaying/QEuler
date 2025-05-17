#include "gtest/gtest.h"

#include "common/math/vec_2.h"

TEST(Vec2Test, Constructor) {
  qeuler::Vec2d v1;
  EXPECT_EQ(v1.x(), 0.0);
  EXPECT_EQ(v1.y(), 0.0);

  qeuler::Vec2d v2(1.0, 2.0);
  EXPECT_EQ(v2.x(), 1.0);
  EXPECT_EQ(v2.y(), 2.0);
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
