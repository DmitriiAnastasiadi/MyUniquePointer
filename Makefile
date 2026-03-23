all: clean build run
build:
	g++ -std=c++17 -fsanitize=address main.cpp -o main
run:
	./main
clean:
	rm -f main