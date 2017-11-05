cmake_minimum_required(VERSION 3.1)

add_executable(Test test.cpp)
target_link_libraries(Test ${GTEST_BOTH_LIBRARIES} pthread)
GTEST_ADD_TESTS(Test "" AUTO)
