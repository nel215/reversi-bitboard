FROM ubuntu:xenial

RUN apt update -y
RUN apt install -y cmake
RUN apt install -y wget
RUN apt install -y build-essential

# googletest
WORKDIR /usr/local
RUN wget https://github.com/google/googletest/archive/release-1.8.0.tar.gz
RUN ls -la
RUN tar xzf release-1.8.0.tar.gz
RUN ln -s ./googletest-release-1.8.0 googletest
RUN cd googletest && mkdir -p build && cd build && cmake .. && make && make install

WORKDIR /bitboard
