targets = main.bin 
CC = gcc
C_OPTS =  -I./src src/*.c 

all: clean prep compile run

clean:
	rm -rf dist
prep:
	mkdir dist

compile: main.bin 

main.bin: main.c
	$(CC) $(C_OPTS) $< -o ./dist/$@
	

run: clean prep compile
	./dist/main.bin
doxygen:
	doxygen Doxyfile
format: #TODO

tidy: # TODO

