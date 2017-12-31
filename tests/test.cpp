#include <gtest/gtest.h>
#include "../bitboard.hpp"

class Test : public ::testing::Test{};

TEST_F(Test, Sample) {
  bitboard::Reversi();
}
