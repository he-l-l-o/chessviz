all:bin/chessviz
bin/chessviz:build/main.o build/board_start.o build/board_read.o build/board_print_plain.o
	g++ build/main.o build/board_start.o build/board_read.o build/board_print_plain.o -o bin/chessviz -Wall -Werror -std=c++11
build/main.o:src/main.cpp
	g++ -c src/main.cpp -o build/main.o -Wall -Werror -std=c++11
build/board_start.o:src/board_start.cpp
	g++ -c src/board_start.cpp -o build/board_start.o -Wall -Werror -std=c++11
build/board_read.o:src/board_read.cpp
	g++ -c src/board_read.cpp -o build/board_read.o -Wall -Werror -std=c++11
build/board_print_plain.o:src/board_print_plain.cpp
	g++ -c src/board_print_plain.cpp -o build/board_print_plain.o -Wall -Werror -std=c++11

.PHONY: clean test

build/test/test.o:test/test.cpp
	g++ -c test/test.cpp -o build/test/test.o -Wall -Werror -std=c++11
build/test/board_start.o:src/board_start.cpp
	g++ -c src/board_start.cpp -o build/test/board_start.o -Wall -Werror -std=c++11
build/test/board_read.o:src/board_read.cpp
	g++ -c src/board_read.cpp -o build/test/board_read.o -Wall -Werror -std=c++11
bin/test:build/test/test.o build/test/board_read.o build/test/board_start.o
	g++ build/test/test.o build/test/board_read.o build/test/board_start.o -o bin/test -Wall -Werror -std=c++11
test:bin/test

clean: 
	rm -rf build/*.o
	rm -rf build/test/*.o