# map? unordered_map?

[source code](../sources/map_or_unordered_map.cpp)

## そもそも map とはなんぞ？

`std::map` は `map` をインクル〜ドすることで使えるようになるキーと値のペアを保持するコンテナです.
`std::map<int, std::string>` は `int` をキーに持ち `std::string` を値に持つペアを複数持つことができます.
`std::map<std::string, int>` は `std::string` をキーに持ち `int` を値に持つペアを複数持つことができます.
値は同じ値を取っても良いですが, キーは重複出来ません.

```cpp
std::map<int, std::string> v;
v.insert(std::make_pair(0, "hoge"));
v.insert(std::make_pair(1, "hoge")); // OK
v.insert(std::make_pair(1, "bar")); // NG
```

(キーの重複を許したい場合は `std::multimap` というものがあります. 一つのキーで複数の値が取れるので使い方はだいぶ違います.)

ちなみに, 僕は昔 `std::map` を知らなかった頃に `std::vector<int>` と `std::vector<string>` を使って似たようなことをやってた記憶があります. 超恥ずかしいですね.

## そんじゃあ unordered_map って？ (C++11)

`std::unoredered_map` はC++11から使えるようになった名前の通り *unodered* な *map* です.
内部的にキーをhash化して保持します. なので速い. その代わりキーでソートしてくれないのでunorderedなわけですね.

どんくらい速いかっていうと要素へのアクセスが平均 `o(1)` ってくらい速い. `std::map` だと `o(log N)` ですね. 速い.

ただ, C++11から入った `std::hash` を使ってるらしいので `std::hash` が準備されてないクラスをキーにしようとすると自分で特殊化を実装しなきゃいけません.

unorderedなことが問題になるのはイテレータで回すときくらいですかね. イテレータ使うときでも僕は別にそこがソートされてるってことを意識して使った事は無いのでunorderedで全然良いですね.

## 結論

キーが `string` とか数値のときは積極的に `unordered_map` 使っていきたい.