targets = main.bin 
CC = gcc
C_OPTS = -std=gnu11  -Wall -g -Wextra  -Wformat-security -Wfloat-equal -Wshadow -Wconversion -Wlogical-not-parentheses -Wnull-dereference -I./  

all: clean prep compile run

clean:
	rm -rf dist
prep:
	mkdir dist
compile: main.bin 

main.bin: ex5.c 
	$(CC) $(C_OPTS) $< -o ./dist/$@
run: clean prep compile
	./dist/main.bin
doxygen:
	doxygen Doxyfile
format: #TODO

tidy: # TODO

