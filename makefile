all: main

main: bin/main

test:bin/maintest

bin/main: build/main.o build/board.o build/printboard.o
	gcc -Wall -Werror build/main.o build/board.o build/printboard.o -o bin/main

bin/maintest: build/test/maintest.o build/board.o build/printboard.o
	gcc build/test/maintest.o  build/board.o build/printboard.o -o bin/maintest

build/test/maintest.o: test/maintest.c
	gcc -I thirdparty -I src -c test/maintest.c -o build/test/maintest.o

build/main.o: src/main.c
	gcc -I includes -Wall -lncurses -ltinfo -Werror -c src/main.c -o build/main.o

build/board.o: src/board.c
	gcc -Wall -Werror -c src/board.c -o build/board.o

build/printboard.o: src/printboard.c
	gcc -Wall -Werror -c src/printboard.c -o build/printboard.o

.PHONY: clean

clean:
	rm -rf build/*.o
