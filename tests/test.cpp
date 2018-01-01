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

TEST_F(Test, Mirror) {
  uint64_t b = 0xfffefcf8f0e0c080;
  EXPECT_EQ(0xff7f3f1f0f070301, Mirror(b));
}

TEST_F(Test, GetCandidateRowLeft) {
  uint8_t b = 1<<0;
  uint8_t w = 1<<1;
  uint8_t c = GetCandidateRowLeft(b, w);
  EXPECT_EQ(1<<2, c);
}

TEST_F(Test, GetCandidateLeft) {
  uint64_t b = 0x0101010101010101;
  uint64_t w = 0x0202020202020202;
  uint64_t c = GetCandidateLeft(b, w);
  EXPECT_EQ(0x0404040404040404, c);
}

TEST_F(Test, GetCandidateHorizontal) {
  uint64_t b = 0x0404040404040404;
  uint64_t w = 0x0a0a0a0a0a0a0a0a;
  uint64_t c = GetCandidateHorizontal(b, w);
  EXPECT_EQ(0x1111111111111111, c);
}

}  // namespace bitboard
