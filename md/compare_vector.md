# std::vectorの比較

[source code](../sources/compare_vector.cpp)

あんまり使わない気がするけど.

## ofColorだけ比較出来ない...？

of0.8.4を使っております.
手前味噌ですが [ofxPubSubOsc](https://github.com/2bbb/ofxPubSubOsc) を開発してたときのこと.

```cpp
// 動く
vector<ofRectangle> x, y;
if(x == y) { ... }
```

```cpp
// 動かない
vector<ofColor> x, y;
if(x == y) { ... }
```

なんでや！！

## 君もconst教団に入ろう

`vector` に関する `operator==` の[定義](http://www.cplusplus.com/reference/vector/vector/operators/)を見てみると

```cpp
template <class T, class Alloc>
bool operator== (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);
```

で, of0.8.4のofColorの定義を見てみると

```cpp
bool operator == (const ofColor_<PixelType>& color);
bool operator != (const ofColor_<PixelType>& color);

```

なんですね. なるほど.
PRは投げて受理されたので0.9.0使う場合は大丈夫だろうけど0.8.4使う人ははまるはずなので

```cpp
template <typename PixelType>
bool operator==(const ofColor_<PixelType> &x, const ofColor_<PixelType> &y) {
	return x == y;
}

template <typename PixelType>
bool operator!=(const ofColor_<PixelType> &x, const ofColor_<PixelType> &y) {
	return x != y;
}
```

を追加しましたとさ.