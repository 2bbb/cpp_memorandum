#include <iostream>
#include <vector>

//

struct Comparable {
	bool operator==(const Comparable &x) { return true; }
	bool operator!=(const Comparable &x) { return this->operator==(x); }
};

//

struct ConstComparable {
	bool operator==(const ConstComparable &x) const { return true; }
	bool operator!=(const ConstComparable &x) const { return this->operator==(x); }
};

//

struct NotConstComparableGlobal {
	bool operator==(const NotConstComparableGlobal &x) { return true; }
	bool operator!=(const NotConstComparableGlobal &x) { return this->operator==(x); }
};

bool operator==(const NotConstComparableGlobal &x, const NotConstComparableGlobal &y) { return true; }
bool operator!=(const NotConstComparableGlobal &x, const NotConstComparableGlobal &y) { return !operator==(x, y); }

//

struct GlobalComparable {};

bool operator==(const GlobalComparable &x, const GlobalComparable &y) { return true; }
bool operator!=(const GlobalComparable &x, const GlobalComparable &y) { return !operator==(x, y); }

using namespace std;

int main(int argc, char *argv[]) {
// Error!!
//	{
//		vector<Comparable> x, y;
//		if(x == y) {}
//	}
	
	{
		vector<ConstComparable> x, y;
		if(x == y) {}
	}
	
	{
		vector<NotConstComparableGlobal> x, y;
		if(x == y) {}
	}
	
	{
		vector<GlobalComparable> x, y;
		if(x == y) {}
	}
	
	return EXIT_SUCCESS;
}