.PHONY := clean

crypt: main.c chacha.c chacha.h
	gcc main.c chacha.c -O2 -o crypt

clean:
	rm -f crypt
