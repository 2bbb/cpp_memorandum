# type_traits

[source code](../sources/cool_type_traits.cpp)

## TMP is 最高

みなさま, TMPという単語を聞いたことがあるかと思います.
が, 一応TMPって言葉を知らない坊や達のために簡単な説明をしておきますと, TMP は "**T**emplate **M**eta **P**rogramming" の略ですね. **t**e**mp**orary の略じゃないです.
そう, テンプレートのメタなプログラミング. ファッキンクールです. ファッキンエキサイティンです.

そんなときに役立つ心強い仲間達のお話.

## TMP is 難しい

ということで, ファッキンクーリッシュなTMPですが, 一つだけ問題があります.
それはファッキン難しいってことです. template書いたことある人は分かると思いますがそもそもエラーメッセージが大変. どんくらい大変かというと太宰治の短編小説くらいの長さをもつエラーメッセージが吐かれたりするわけですね. それもみたことない名前達と共に.

ということで, TMP自体の解説をするには余白が狭すぎますし, そもそも僕の手に負えないので各自よしなにやって頂くことにします.

## type_traits

さてさて, そういう暗い気持ちを払拭すべく, type_traitsを使いましょう.
何はともあれ取り敢えずincludeしましょう.

```
#include <type_traits>
```

そんだらばこんなことが出来るだ.

```
template <typename T, typename std::enable_if<std::is_same<T, bool>::value>::type* = nullptr>
void divide_by_type(T t) {
	cout << "this is bool type: " << t << endl;
}

template <typename T, typename std::enable_if<!std::is_same<T, bool>::value && std::is_arithmetic<T>::value>::type* = nullptr>
void divide_by_type(T t) {
	cout << "this is arithmetic type: " << t << endl;
}

template <typename T, typename std::enable_if<!std::is_arithmetic<T>::value>::type* = nullptr>
void divide_by_type(T t) {
	cout << "this is NOT arithmetic type: " << t << endl;
}
```

マーヴェラスですね. 超マーヴェラスですね. アドレナリンが勇気りんりんですね.
大体書きたいこと終わりましたね.

ということで [cpprefjp type_traits](http://cpprefjp.github.io/reference/type_traits.html) でも読んでTMPの海へダイブ！

## まとめ

TMP is 難しい