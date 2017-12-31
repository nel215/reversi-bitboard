#include <gtest/gtest.h>
#include "../bitboard.hpp"

class Test : public ::testing::Test{};

TEST_F(Test, Sample) {
  bitboard::Reversi();
}

TEST_F(Test, Rotate45) {
  uint64_t b = 0xfffefcf8f0e0c080;
  EXPECT_EQ(0x80c0e0f0f8fcfeff, bitboard::Rotate45(b));
}
