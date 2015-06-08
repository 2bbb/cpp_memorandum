# Expression SFINAE

[source code](../sources/expression_sfinae.cpp)

@motoishmz の [これ](https://github.com/motoishmz/ore_cpp11/blob/master/4-auto_decltype.h) の話から

## dumpしたい

```cpp
// mapの中身をdumpする用
// sample code内で iteratorとvalue の両方渡したいのでtemplateに
// これがbiking on a tightrope...
template <typename T>
void dump(const T &t) {
	cout << t->first << ": " << t->second << endl;
}
```

と書いてあるんだけど, これだと折角のrange-based for loop使うときに

```cpp
for(const auto &v : map_instance) dump(&v);
```

って書かなきゃじゃん？なんか嫌じゃん？出来そうじゃん？
って思ったんだけど出来なかった.
で, まあ, SFINAE使えば出来るとは思ってたんだけど `struct ゴニョゴニョ` するくらいなら `&v` ってしたが良いかなと思ってモヤモヤしてた所 C++11 からは式スフィネエという素敵な奴が居るらしい.

## 式スフィネエとはこういうことだ！！

```cpp
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
```

ファッキンクールですね. `decltype` の中にカンマ演算子ぶっ込んで返り値の型自体はvoidにしてるけどその前にそれぞれ転けるからSFINAEが起きるわけですね. 素敵. 抱いて！

## but Visual Studio is dead.

[C++11/14/17 Features in VS 2015 RC](http://blogs.msdn.com/b/vcblog/archive/2015/04/29/c-11-14-17-features-in-vs-2015-rc.aspx)

残念です.

## 結論

Visual Studio辛過ぎる.