targets = main.bin 
CC = g++
C_OPTS =  -I./src src/*.cpp 

all: clean prep compile run

clean:
	rm -rf dist
prep:
	mkdir dist

compile: main.bin 

main.bin: main.cpp
	$(CC) $(C_OPTS) $< -o ./dist/$@
	

run: clean prep compile
	./dist/main.bin
doxygen:
	doxygen Doxyfile
format: #TODO

tidy: # TODO

