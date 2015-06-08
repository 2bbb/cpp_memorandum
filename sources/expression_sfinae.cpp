#include <iostream>
#include <map>

template <typename T>
auto dump(T t)
	-> decltype(t.first, void())
{
	std::cout << "(" << t.first << "," << t.second << ")" << std::endl;
}

template <typename T>
auto dump(T t)
	-> decltype(t->first, void())
{
	std::cout << "(" << t->first << "," << t->second << ")" << std::endl;
}

int main(int argc, char *argv[]) {
	std::map<int, int> m = {{1, 1}, {2, 2}, {3, 3}};
	
	for(const auto &v : m) {
		dump(v);
	}
	
	for(auto it = begin(m); it != end(m); it++) {
		dump(it);
	}
	
	return EXIT_SUCCESS;
}