all: bin/main

bin/main: obj/main.o obj/gfx.o obj/cls.o
	g++ -Wall -Werror obj/main.o obj/gfx.o obj/cls.o -o bin/main -lX11 -lm

obj/cls.o: src/cls.cpp 
	g++ -I include -Wall -Werror -c src/cls.cpp -o obj/cls.o -lX11 -lm

obj/gfx.o: src/gfx.cpp 
	g++ -I include -Wall -Werror -c src/gfx.cpp -o obj/gfx.o -lX11 -lm

obj/main.o: src/main.cpp
	mkdir bin
	mkdir obj
	g++ -I include -Wall -Werror -c src/main.cpp -o obj/main.o -lX11

clean:
	rm -rf bin/ obj/

PHONY: all clean
