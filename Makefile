CXX = clang++-3.5
CXXFLAGS = -std=c++11 -Wall -Wextra -pedantic -ggdb

main: manager plugin1 plugin2
	$(CXX) main.cpp manager.o plugin1.o -o main $(CXXFLAGS) -ldl -rdynamic -Wl,-rpath=.

manager: 
	$(CXX) -c manager.cpp -o manager.o $(CXXFLAGS)

plugin1:
	$(CXX) -c plugin1.cpp -o plugin1.o $(CXXFLAGS)


plugin2:
	$(CXX) -shared -fPIC plugin2.cpp -o plugin2.so $(CXXFLAGS)

clean:
	rm -f *.so *.o main

check: main
	valgrind -v --leak-check=full --show-leak-kinds=all ./main


# dependency based partial rebuilds are overrated <- NOT
# anyways, this is how I roll...
.PHONY: all main manager plugin1 plugin2 clean check
