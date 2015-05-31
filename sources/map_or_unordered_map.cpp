#include <iostream>
#include <string>
#include <sstream>
#include <map>
#include <unordered_map>
#include <vector>
 
#include <chrono>
 
struct StopWatch {
	decltype(std::chrono::system_clock::now()) _start, _end;
	void start() {
		_start = std::chrono::system_clock::now();
	}
	template <typename T = std::chrono::microseconds>
	T stop() {
		_end = std::chrono::system_clock::now();
		return std::chrono::duration_cast<T>(_end - _start);
	}
};
 
using namespace std;
 
string toString(int i) {
	stringstream s;
	s << i;
	return s.str();
}
 
void calc_speed(size_t size) {
	map<string, int> m;
	unordered_map<string, int> um;
	vector<string> s;
	for(int i = 0; i < size; i++) {
		s.push_back(toString(i));
		m.insert(make_pair(s[i], i));
		um.insert(make_pair(s[i], i));
	}
	int n;
	StopWatch w;
	{
		w.start();
		for(size_t i = 0; i < 1000000; i++) {
			n = m[s[i % s.size()]];
		}
		cout << "map           " << w.stop().count() << endl;
	}
	{
		w.start();
		for(size_t i = 0; i < 1000000; i++) {
			n = um[s[i % s.size()]];
		}
		cout << "unordered_map " << w.stop().count() << endl;
	}
}
 
void speed_calc_test() {
	cout << endl;
	cout << "speed_calc_test" << endl;
	
	cout << "size = " << 100 << endl;
	calc_speed(100);
	cout << "size = " << 1000 << endl;
	calc_speed(1000);
	cout << "size = " << 10000 << endl;
	calc_speed(10000);
}

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
	
	speed_calc_test();
	
	return EXIT_SUCCESS;
}