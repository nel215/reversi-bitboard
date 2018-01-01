#ifndef BITBOARD_HPP_
#define BITBOARD_HPP_
#include <iostream>
#include <tuple>

namespace bitboard {
void Show(uint64_t b) {
  for (int i=0; i < 64; i++) {
    std::cout << ((b >> i)&1);
    if (i%8 == 7) std::cout << std::endl;
  }
  std::cout << std::endl;
}
uint64_t Mirror(uint64_t b) {
  b = ((b & 0xf0f0f0f0f0f0f0f0) >> 4) | ((b & 0x0f0f0f0f0f0f0f0f) << 4);
  b = ((b & 0xcccccccccccccccc) >> 2) | ((b & 0x3333333333333333) << 2);
  b = ((b & 0xaaaaaaaaaaaaaaaa) >> 1) | ((b & 0x5555555555555555) << 1);
  return b;
}
std::tuple<uint64_t, uint64_t> Rotate45(uint64_t b) {
  uint64_t lhs = b & 0x0103070f1f3f7fff;
  lhs = ((lhs & 0xf0f0f0f0f0f0f0f0) << 32) | (lhs & 0x0f0f0f0f0f0f0f0f);
  lhs = ((lhs & 0xcccccccccccccccc) << 16) | (lhs & 0x3333333333333333);
  lhs = ((lhs & 0xaaaaaaaaaaaaaaaa) << 8)  | (lhs & 0x5555555555555555);

  uint64_t rhs = b & 0xfefcf8f0e0c08000;
  rhs = ((rhs & 0x0f0f0f0f0f0f0f0f) >> 32) | (rhs & 0xf0f0f0f0f0f0f0f0);
  rhs = ((rhs & 0x3333333333333333) >> 16) | (rhs & 0xcccccccccccccccc);
  rhs = ((rhs & 0x5555555555555555) >> 8)  | (rhs & 0xaaaaaaaaaaaaaaaa);
  return std::tuple<uint64_t, uint64_t>(lhs, rhs);
}
uint64_t Rotate45Reverse(std::tuple<uint64_t, uint64_t> rot) {
  uint64_t lhs = std::get<0>(rot);
  lhs = ((lhs & 0xf0f0f0f0f0f0f0f0) >> 32) | (lhs & 0x0f0f0f0f0f0f0f0f);
  lhs = ((lhs & 0xcccccccccccccccc) >> 16) | (lhs & 0x3333333333333333);
  lhs = ((lhs & 0xaaaaaaaaaaaaaaaa) >> 8) | (lhs & 0x5555555555555555);

  uint64_t rhs = std::get<1>(rot);
  rhs = ((rhs & 0x0f0f0f0f0f0f0f0f) << 32) | (rhs & 0xf0f0f0f0f0f0f0f0);
  rhs = ((rhs & 0x3333333333333333) << 16) | (rhs & 0xcccccccccccccccc);
  rhs = ((rhs & 0x5555555555555555) << 8)  | (rhs & 0xaaaaaaaaaaaaaaaa);
  return lhs ^ rhs;
}
uint8_t GetCandidatesRowRight(uint8_t b, uint8_t w) {
  uint8_t left = b << 1;
  return ~(left | w) & (left + w);
}
uint64_t GetCandidatesRight(uint64_t b, uint64_t w) {
  uint64_t c = 0;
  for (int y=0; y < 8; y++) {
    uint64_t res = GetCandidatesRowRight(static_cast<uint8_t>(b), static_cast<uint8_t>(w));
    c = c | (res << (y*8));
    b = b >> 8;
    w = w >> 8;
  }
  return c;
}
uint64_t GetCandidatesUpperRight(uint64_t b, uint64_t w) {
  auto rotB = Rotate45(b);
  auto rotW = Rotate45(w);
  return Rotate45Reverse(
    std::tuple<uint64_t, uint64_t>(
      GetCandidatesRight(std::get<0>(rotB), std::get<0>(rotW)),
      GetCandidatesRight(std::get<1>(rotB), std::get<1>(rotW))
    )
  );
}
uint64_t GetCandidatesHorizontal(uint64_t b, uint64_t w) {
  uint64_t c = 0;
  c = c | GetCandidatesRight(b, w);
  c = c | GetCandidatesUpperRight(b, w);

  auto miB = Mirror(b);
  auto miW = Mirror(w);
  c = c | Mirror(GetCandidatesRight(miB, miW));
  c = c | Mirror(GetCandidatesUpperRight(miB, miW));
  return c;
}
class Reversi {
  int size = 8;
  uint64_t black;
  uint64_t white;
  int ToPos(int y, int x) {
    return y * size + x;
  }
  void SetBlack(int y, int x) {
    black |= 1 << ToPos(y, x);
  }
  void SetWhite(int y, int x) {
    white |= 1 << ToPos(y, x);
  }
 public:
  Reversi() {
    SetBlack(3, 3);
    SetBlack(4, 4);
    SetBlack(3, 4);
    SetBlack(4, 3);
  }
};
}  // namespace bitboard
#endif  // BITBOARD_HPP_
