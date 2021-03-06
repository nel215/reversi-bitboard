#include <gtest/gtest.h>
#include "../bitboard.hpp"

class Test : public ::testing::Test{};

namespace bitboard {

TEST_F(Test, Diag) {
  uint64_t b = 0xf00f00000000f00f;
  uint64_t res = Diag(b);
  EXPECT_EQ(0x8282828241414141, res);
  EXPECT_EQ(b, Diag(res));
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

TEST_F(Test, FlipVertical) {
  uint64_t b = 0x8040201008040201;
  uint64_t res = FlipVertical(b);
  EXPECT_EQ(0x0102040810204080, res);
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

TEST_F(Test, GetCandidatesUpperRight) {
  uint64_t b = 0x0000000400000000;
  uint64_t w = 0x00000e0a0e000000;
  uint64_t c = GetCandidatesUpperRight(b, w);
  EXPECT_EQ(0x0000000000100000, c);
}

TEST_F(Test, GetCandidatesHalf) {
  uint64_t b = 0x0000000400000000;
  uint64_t w = 0x00000e0a0e000000;
  uint64_t c = GetCandidatesHalf(b, w);
  EXPECT_EQ(0x0000001000150000, c);
}

TEST_F(Test, GetCandidates) {
  uint64_t b = 0x0000000400000000;
  uint64_t w = 0x00000e0a0e000000;
  uint64_t c = GetCandidates(b, w);
  EXPECT_EQ(0x0015001100150000, c);
}

}  // namespace bitboard
