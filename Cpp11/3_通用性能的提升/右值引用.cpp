/*
lvalue 是 loactor value 的缩写，rvalue 是 read value 的缩写
    左值是指存储在内存中、有明确存储地址（可取地址）的数据；
    右值是指可以提供数据值的数据（不可取地址）；
*/

// 左值
int num = 9;
// 左值引用
int& a = num;
// 右值

// 右值引用
int && b = 1;

// 常量右值引用
const int && c = 6;

// 常量左值引用
const int & d = num;

const int & e = a;
const int & f = b;
const int & g = c;

const int && j = a;
const int && h = b;
const int && i = d;

