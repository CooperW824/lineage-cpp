cc = g++ -g -Wall -Wextra -c -o
lc = g++ -Wall -Wextra -g -o

build: build/main.o build/factorial.o build/MyClass.o
	${lc} build/app.bin build/*.o

clean:
	rm -rf build
	mkdir build

build/main.o: src/main.cpp
	${cc} build/main.o src/main.cpp 

build/factorial.o: src/factorial.cpp
	${cc} build/factorial.o src/factorial.cpp

build/MyClass.o: src/MyClass.cpp
	${cc} build/MyClass.o src/MyClass.cpp