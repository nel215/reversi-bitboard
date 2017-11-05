image:
	sudo docker build -t nel215/bitboard:0.1 .
test:
	sudo docker run --rm -e TEST=1 -v $(PWD):/bitboard nel215/bitboard:0.1 ./test.sh
