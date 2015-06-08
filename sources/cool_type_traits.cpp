#include <iostream>
#include <type_traits>

using namespace std;

template <typename T, typename enable_if<is_same<T, bool>::value>::type* = nullptr>
void divide_by_type(T t) {
	cout << "this is bool type: " << t << endl;
}

template <typename T, typename enable_if<!is_same<T, bool>::value && is_arithmetic<T>::value>::type* = nullptr>
void divide_by_type(T t) {
	cout << "this is arithmetic type: " << t << endl;
}

template <typename T, typename enable_if<!is_arithmetic<T>::value>::type* = nullptr>
void divide_by_type(T t) {
	cout << "this is NOT arithmetic type: " << t << endl;
}

int main(int argc, char *argv[]) {
	divide_by_type(1);
	divide_by_type(1.1f);
	divide_by_type('c');
	divide_by_type(false);
	divide_by_type("abc");
}