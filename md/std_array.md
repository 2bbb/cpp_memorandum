# std::array

[source code](../sources/std_array.cpp)

もう `std::vector` で良いじゃんって話でもあるんですけど.

## 配列って難しい

```cpp
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
```

よくありますね. こういうの.
これの問題は何か, というと `Color` の内部では `sizeof(components) / sizeof(components[0]) == 4` だと分かってるのに `Color c;` みたいなインスタンスに対して `getComponents()` を使う側からは(クラス内部でもだけど) `sizeof(c.getComponents()) == sizeof(float *)` になっちゃうってことですね.

もちろん, `getComponentsNum()` も付いてるので普通に使う分には問題無いわけですが, templateで色々やりたいときに例外処理がこいつらのためだけに色々増えるわけですね.

じゃあどうしたら良いのよ！という話になるんですが, 

```cpp
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
```

こうやるときちんと `float[4]` 型の配列としての情報を失わずにカプセル化出来ます. constも付けれます. すると,

```cpp
template <typename T>
void doHogeHoge(T &t) {
	...
}

template <typename T, size_t Size>
void doHogeHoge(T (&arr)[Size]) {
	for(size_t i = 0; i < Size; i++) {
		doHogeHoge(arr[i]);
	}
}
```

みたいなテンプレートで `doHogeHoge(c.getComponents())` みたいに受けれますね. やったー解決.
と言いたいのですが, C++11にはもっとイカした奴が居るんだぜ？

## てことで std::array

`std::array` の使い方は簡単で `#include <array>` して型とサイズを指定するのみ.

```cpp
std::array<float, 4> components;
```

これでOK. 素敵.

`std::vector` のサイズ変更以外はだいたい使える感じですね.
`size()` もあるし, 一応 `empty()` も. (`std::array<T, 0>` の使い道は知らないけど...)
`front()`, `back()` も完備. `data()` で先頭要素へのポインタも返せます.
`fill()`, `swap()` も使えるし, イテレータも.（詳細はリファレンス見てください）

## std::array には std::vector とかと同じ優しさで接する

ただ, 安易な考えで

```cpp
std::array<float, 1024> hoge(std::array<float, 1024> arr) {
	...
	return arr;
}
```

とか書いちゃダメです. コピコンが毎回働きます.
右辺値参照だとか `std::move` とか使えばこういうのも出来ないことは無いと思いますが素直にこういうことやりたいときは参照使いましょう.

```cpp
void hoge(std::array<float, 1024> &arr) {
	...
	return arr;
}
```

こんな.

## 仕方ないんだけども

とはいえ, せっかく `size()` とかも付いたのにやっぱりテンプレートで受けようと思ったら

```cpp
template <typename T, size_t Size>
void doHogeHoge(std::array<T, Size> &arr)
```

としなきゃいけなくて

```cpp
template <template <typename, typename> class Container, typename T>
void doHogeHoge(Container<T, std::allocator<T> > &v)
```

みたいによく使うコンテナのテンプレートに含むことは出来ないのがちょっと残念な感じですね.

## 結論

もう `std::vector` で良くね？