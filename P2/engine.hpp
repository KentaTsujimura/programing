#pragma once            //読み込み回数のエラーを防ぐ
#include <iostream>


class ENGINE{
    public:
        int i;      //回転数
        std::string name;
        ENGINE();
        void print();           //仕様、関数の存在を宣言 関数の中身は書いていない
        //void print() {  //メンバ関数の定義 仕様書の方に関数を書くこともある
//    std::cout << name << "の回転数" << i << std::endl;
//}
};
