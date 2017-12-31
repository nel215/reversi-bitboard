#ifndef BITBOARD_HPP_
#define BITBOARD_HPP_

namespace bitboard {
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
