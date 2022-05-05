// 同一个文件不会被包含多次。这里所说的”同一个文件”是指物理上的一个文件，而不是指内容相同的两个文件。无法对一个头文件中的一段代码作#pragma once声明，而只能针对文件。
#pragma once

int add1(int a, int b);
int sub1(int a, int b);
int mult1(int a, int b);
double div1(int a, int b);

