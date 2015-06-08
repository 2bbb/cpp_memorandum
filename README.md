# C++のちょっとしたこと

* C++の知ってるとちょっとカッコイイことだとか, 知らないとダサいこととかをちょこちょこまとめていこうというレポジトリです.
* 特に体系立てて書くつもりはないので出てくる順序は思いついた順で適当です.
* 使い方チュートリアル的なことは基本的には書きません. 詳細な使い方を知りたい場合は [C++日本語リファレンス](http://cpprefjp.github.io) とかで各自調べてください.
* C++11を前提として書きます. 出来る限りC++11でしか使えない場合はその旨を明記する予定です.

----

## TOC

### [map? unordered_map?](md/map_or_unordered_map.md) 2015/05/30

何かと便利な `map` と最近C++11から入ったっていう `unordered_map` についてちょこっと.

* 2015/05/31 計測追加

### [std::array](md/std_array.md) 2015/05/30

templateやってると配列の頭のポインタを返しちゃうと失われる情報がなかなか辛いわけですが, C++11から導入された `std:array` の美味しさを.

### [type_traits](md/cool_type_traits.md) 2015/06/08

書きたかった割に雑です.

