.PHONY: clean tree docs

all: debug release docs

clean:
	rm -rf ./build ./*/build ./docs/ ./*/docs

tree:
	tree --dirsfirst -I 'build|resources|docs' .

docs:
	doxygen ./doxygen

release:
	mkdir -p build/release; cd build/release; cmake -DCMAKE_BUILD_TYPE=Release ../../; make

debug:
	mkdir -p build/debug; cd build/debug; cmake -DCMAKE_BUILD_TYPE=Debug ../../; make

test: debug
	cd build/Debug; ctest ../..