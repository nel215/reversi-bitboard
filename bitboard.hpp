#ifndef BITBOARD_HPP_
#define BITBOARD_HPP_
#include <iostream>

namespace bitboard {
void Show(uint64_t b) {
  for (int i=63; i >= 0; i--) {
    std::cout << ((b >> i)&1);
    if (i%8 == 0) std::cout << std::endl;
  }
  std::cout << std::endl;
}
uint64_t Rotate45(uint64_t b) {
  b = (b & 0xaaaaaaaaaaaaaaaa) | ((b & 0x5555555555555555) >> 8);
  b = (b & 0xcccccccccccccccc) | ((b & 0x3333333333333333) >> 16);
  b = (b & 0xf0f0f0f0f0f0f0f0) | ((b & 0x0f0f0f0f0f0f0f0f) >> 32);
  return b;
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
