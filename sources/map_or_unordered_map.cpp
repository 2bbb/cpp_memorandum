#include <iostream>
#include <string>
#include <map>
#include <unordered_map>

using namespace std;

int main(int argc, char *argv[]) {
	char const *names[] = {
		"Tarou",
		"Jirou",
		"Saburou",
		"Gorou",
		"Hanako",
		"Pikachu",
		"Sebastian"
	};
	
	map<string, int> m;
	unordered_map<string, int> um;
	
	// どちらにも names[i] をキーに i を値として挿入する
	for(int i = 0; i < 7; i++) {
		string name = string(names[i]);
		m.insert(make_pair(name, i));
		um.insert(make_pair(name, i));
	}
	
	// map はキーでソートされるからちょっと遅い.
	// v[key] でのアクセス時間は o(log N)
	cout << "print map" << endl;
	for(const auto &kv : m) {
		cout << kv.first << ", " << kv.second << endl;
	}
	
	cout << endl;
	
	// unordered_map は内部的にはキーの代わりにhashが使われているのでソートされない分高速.
	// v[key] でのアクセス時間は o(1)
	// 本当は hash_map って名前にしたかったらしいけど hash_map ってライブラリがよくあるから苦肉の索でunordered_map になった.
	// string はデフォルトで std::hash<std::string> が準備されてるので良いですが, 独自クラスをキーにするためには std::hash<T> を自分で特殊化したりしなきゃいけなくて大変.
	cout << "print unordered_map" << endl;
	
	for(const auto &kv : um) {
		cout << kv.first << ", " << kv.second << endl;
	}
	
	return EXIT_SUCCESS;
}