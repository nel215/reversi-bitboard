#include <gtest/gtest.h>
#include "../bitboard.hpp"

class Test : public ::testing::Test{};

namespace bitboard {
TEST_F(Test, Sample) {
  Reversi();
}

TEST_F(Test, Rotate45) {
  uint64_t b = 0xfffefcf8f0e0c080;
  EXPECT_EQ(0x80c0e0f0f8fcfeff, Rotate45(b));
}

TEST_F(Test, GetCandiateRowLeft) {
  uint8_t b = 1<<0;
  uint8_t w = 1<<1;
  uint8_t c = GetCandiateRowLeft(b, w);
  EXPECT_EQ(1<<2, c);
}
}  // namespace bitboard
