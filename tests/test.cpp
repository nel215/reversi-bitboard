#include <gtest/gtest.h>
#include "../bitboard.hpp"

class Test : public ::testing::Test{};

namespace bitboard {
TEST_F(Test, Sample) {
  Reversi();
}

TEST_F(Test, Rotate45) {
  uint64_t b = -1;
  std::tuple<uint64_t, uint64_t> res = Rotate45(b);
  EXPECT_EQ(0xff7f3f1f0f070301, std::get<0>(res));
  EXPECT_EQ(0x80c0e0f0f8fcfe00, std::get<1>(res));
  uint64_t rev = Rotate45Reverse(res);
  EXPECT_EQ(0xffffffffffffffff, rev);
}

TEST_F(Test, Mirror) {
  uint64_t b = 0xfffefcf8f0e0c080;
  EXPECT_EQ(0xff7f3f1f0f070301, Mirror(b));
}

TEST_F(Test, GetCandidatesRowRight) {
  uint8_t b = 0x04;
  uint8_t w = 0x0a;
  uint8_t c = GetCandidatesRowRight(b, w);
  EXPECT_EQ(0x10, c);
}

TEST_F(Test, GetCandidatesRight) {
  uint64_t b = 0x0001010101010101;
  uint64_t w = 0x0202020202020200;
  uint64_t c = GetCandidatesRight(b, w);
  EXPECT_EQ(0x0004040404040400, c);
}

TEST_F(Test, GetCandidatesRightAndUpperRight) {
  uint64_t b = 0x0000000400000000;
  uint64_t w = 0x00000e0a0e000000;
  uint64_t c = GetCandidatesRightAndUpperRight(b, w);
  EXPECT_EQ(0x0000001000100000, c);
}

}  // namespace bitboard
