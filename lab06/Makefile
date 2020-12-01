targets = ex1.bin ex2.bin ex3.bin ex4.bin ex5.bin ex6.bin 
CC = gcc
C_OPTS = -std=gnu11  -Wall -g -Wextra -Wformat-security -Wfloat-equal -Wshadow -Wconversion -Wlogical-not-parentheses -Wnull-dereference 

all: clean prep compile run

clean:
	rm -rf dist
prep:
	mkdir dist
compile: ex1.bin ex2.bin ex3.bin ex4.bin ex5.bin ex6.bin

ex1.bin: src/ex1.c
	$(CC) $(C_OPTS) $< -o ./dist/$@
ex2.bin: src/ex2.c
	$(CC) $(C_OPTS) $< -o ./dist/$@
ex3.bin: src/ex3.c
	$(CC) $(C_OPTS) $< -o ./dist/$@
ex4.bin: src/ex4.c
	$(CC) $(C_OPTS) $< -o ./dist/$@
ex5.bin: src/ex5.c
	$(CC) $(C_OPTS) $< -o ./dist/$@
ex6.bin: src/ex6.c
	$(CC) $(C_OPTS) $< -o ./dist/$@

run: clean prep compile
	./dist/ex1.bin
	./dist/ex2.bin
	./dist/ex3.bin
	./dist/ex4.bin
	./dist/ex5.bin
	./dist/ex6.bin
doxygen:
	doxygen Doxyfile
format: #TODO

tidy: # TODO

