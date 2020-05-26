all: main

main: bin/main

test:bin/main-test

bin/main: build/main.o build/board.o build/printboard.o
	gcc -Wall -Werror build/main.o build/board.o build/printboard.o -o bin/main

bin/main-test: build/test/main-test.o build/board.o build/printboard.o
	gcc build/test/main-test.o  build/board.o build/printboard.o -o bin/main-test

build/test/main-test.o: test/main-test.c
	gcc -I thirdparty -I src -c test/main-test.c -o build/test/main-test.o

build/main.o: src/main.c
	gcc -I includes -Wall -lncurses -ltinfo -Werror -c src/main.c -o build/main.o

build/board.o: src/board.c
	gcc -Wall -Werror -c src/board.c -o build/board.o

build/printboard.o: src/printboard.c
	gcc -Wall -Werror -c src/printboard.c -o build/printboard.o

.PHONY: clean


clean:
	rm -rf build/*.o
