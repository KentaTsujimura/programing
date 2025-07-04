#include "engine.hpp"       //仕様書の読み込み
ENGINE::ENGINE() {
    i = 0;         //コンストラクタ
    name = "noname-engine";
    std::cout << name << "created" << std::endl;
};
void ENGINE::print() {  //メンバ関数の定義
    std::cout << name << "の回転数" << i << std::endl;
}

int main() {
    ENGINE E1,E2;         //エンジンのインスタンスを生成
    E1.name = "ENGINE1";  //インスタンスのメンバに値を代入
    E2.name = "ENGINE2";
    E1.i = 1000;
    E2.i = 2000;
    E1.print();           //インスタンスのメンバ関数を呼び出す
    E2.print();
    return 0;
}