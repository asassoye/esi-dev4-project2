.PHONY: clean tree docs

clean:
	rm -rf ./build ./*/build ./docs/ ./*/docs

tree:
	tree --dirsfirst -I 'build|resources|docs' .

docs:
	doxygen ./doxygen