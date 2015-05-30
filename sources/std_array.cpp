#include <iostream>
#include <array>

namespace NoTypeInfo {
	class Color {
		float components[4];
	public:
		float *getComponents() {
			return components;
		}
		const float *getComponents() const {
			return components;
		}
		size_t getComponentsNum() const {
			return sizeof(components) / sizeof(components[0]);
		}
	};
};

namespace WithTypeInfo {
	class Color {
		float components[4];
	public:
		float (&getComponents())[4] {
			return components;
		}
		float const (&getComponents() const)[4] {
			return components;
		}
		size_t getComponentsNum() const {
			return sizeof(components) / sizeof(components[0]);
		}
	};
};

namespace UsingStdArray {
	class Color {
		std::array<float, 4> components;
	public:
		std::array<float, 4> &getComponents() {
			return components;
		}
		const std::array<float, 4> &getComponents() const {
			return components;
		}
		size_t getComponentsNum() const {
			return components.size();
		}
	};
};

using namespace std;
int main(int argc, char *argv[]) {
	std::array<int, 4> cs = {1, 2, 3, 4};
	int as[4] = {1, 2, 3, 4};
	for(auto &c : as) {
		cout << c++ << endl;
	}
}