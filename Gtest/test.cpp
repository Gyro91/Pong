#include <gtest/gtest.h>
TEST(MathTest, TwoPlusTwoEqualsFour) {
EXPECT_EQ(2 + 2, 4);
}

int main(int argc, char **argv) {
  std::cout << "Running main() from gtest_main.cc\n";
  ::testing::GTEST_FLAG(output) = "xml:./hello.xml";
  testing::InitGoogleTest(&argc, argv);

  return RUN_ALL_TESTS();
}


