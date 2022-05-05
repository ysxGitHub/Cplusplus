/*
C++11 中提供了日期和时间相关的库 chrono，通过 chrono 库可以很方便地处理日期和时间，为程序的开发提供了便利。
    chrono 库主要包含三种类型的类：时间间隔duration、时钟clocks、时间点time point。
*/

#include <chrono>
#include <iostream>
using namespace std;

// chrono::duration 表示一段时间间隔, 用来记录时间长度,
// std::ratio 表示每个时钟周期的秒数

int test1() {

    // h(1) 时钟周期为 1 小时，共有 1 个时钟周期，所以 h 表示的时间间隔为 1 小时
    chrono::hours h(1); // 1 h

    // ms(3) 时钟周期为 1 毫秒，共有 3 个时钟周期，所以 ms 表示的时间间隔为 3 毫秒
    chrono::milliseconds ms{3};  // 3 ms

    // ks(3) 时钟周期为 1000 秒，一共有三个时钟周期，所以 ks 表示的时间间隔为 3000 秒
    chrono::duration<int, ratio<1000>> ks(3); // 3000 s

    // d3(3.5) 时钟周期为 1000 秒，时钟周期数量只能用整形来表示，但是此处指定的是浮点数，因此语法错误
    // chrono::duration<int, ratio<1000>>d3(3.5); // error

    // dd(6.6) 时钟周期为默认的 1 秒，共有 6.6 个时钟周期，所以 dd 表示的时间间隔为 6.6 秒
    chrono::duration<double> dd(6.1); //6.1 s

    // 使用小数表示时钟周期的次数
    // hz(3.5) 时钟周期为 1/30 秒，共有 3.5 个时钟周期，所以 hz 表示的时间间隔为 1/30*3.5 秒
    chrono::duration<double, ratio<1, 30>> hz(3.5); //
    // hz1(3) 时钟周期为 1/1000 秒，共有 3 个时钟周期，所以 hz1 表示的时间间隔为 1/1000*3 秒
    chrono::duration<int, ratio<1, 1000>> hz1(3); // 3 ms


    chrono::microseconds us = 2*ms; // 6000 微秒

    std::cout <<  "3 ms duration has " << ms.count() << " ticks\n"
            <<  "6000 us duration has " << us.count() << " ticks\n"
            <<  "3.5 hz duration has " << hz.count() << " ticks\n";

    // 操作符重载, 可以直接运算
    chrono::minutes t1(10);
    chrono::seconds t2(60);
    chrono::seconds t3 = t1 - t2;
    cout << t3.count() << " second" << endl;

    return 0;
}

/*
注意: duration 的加减运算有一定的规则，当两个 duration 时钟周期不相同的时候，会先统一成一种时钟，
    然后再进行算术运算，统一的规则如下：假设有 ratio<x1,y1> 和 ratio<x2,y2 > 两个时钟周期，
    首先需要求出 x1，x2 的最大公约数 X，然后求出 y1，y2 的最小公倍数 Y，
    统一之后的时钟周期 ratio 为 ratio<X,Y>。
*/
int test2() {
    chrono::duration<double, ratio<9, 7>> d1(3);
    chrono::duration<double, ratio<6, 5>> d2(1);
    // d1 和 d2 统一之后的时钟周期
    chrono::duration<double, ratio<3, 35>> d3 = d1 - d2;
    std::cout <<  "d1 duration has " << d1.count() << " ticks\n" // 3
            <<  "d2 duration has " << d2.count() << " ticks\n"   // 1
            <<  "d3 duration has " << d3.count() << " ticks\n";  // 31

    return 0;
}




// chrono::time_point 表示时间点, 通过这个类可以得到时间中的某一点时间,
// time_since_epoch()函数, 获得 1970.1.1 到 time_point 对象中记录的时间经过的时间间隔

// chrono::system_clock: 系统的时钟，系统的时钟可以修改，甚至可以网络对时，
//                                 因此使用系统时间计算时间差可能不准。

// chrono::steady_clock: 是固定的时钟，相当于秒表。开始计时后，时间只会增长并且不能修改，
//                                             适合用于记录程序耗时

// chrono::high_resolution_clock: 和时钟类 steady_clock 是等价的（是它的别名）。


/*
时钟类成员类型               描述
rep	               表示时钟周期次数的有符号算术类型
period	           表示时钟计次周期的 std::ratio 类型
duration	       时间间隔，可以表示负时长
time_point	       表示在当前时钟里边记录的时间点
*/


// chrono::system_clock
int test3() {

    // 新纪元 1970.1.1 时间
    chrono::system_clock::time_point epoch;

    // 定义一天
    chrono::duration<int, ratio<60*60*24>> day(1);

    // 新纪元 1970.1.1 时间 + 1 天
    chrono::system_clock::time_point ppt(day);

    using dday = chrono::duration<int, ratio<60*60*24>>;

    // 新纪元 1970.1.1 时间 + 10 天
    chrono::time_point<chrono::system_clock, dday> t(dday(10));

    // 当前系统时间
    chrono::system_clock::time_point today = chrono::system_clock::now();


    // 转换为time_t时间类型
    time_t tm = chrono::system_clock::to_time_t(today);
    cout << "today:    " << ctime(&tm);

    time_t tm1 = chrono::system_clock::to_time_t(today+day);
    cout << "tomorrow:    " << ctime(&tm1);

    time_t tm2 = chrono::system_clock::to_time_t(epoch);
    cout << "epoch time:      " << ctime(&tm2);

    time_t tm3 = chrono::system_clock::to_time_t(ppt);
    cout << "epoch time +1 day:  " << ctime(&tm3);

    time_t tm4 = chrono::system_clock::to_time_t(t);
    cout << "epoch time +10 day: " << ctime(&tm4);


    return 0;
}


void f(){
    cout<<"print 1000 stars ... "<<endl;
    for(int i=0; i<1000; ++i){
        cout<<"*";
    }
    cout<<endl;
}


// chrono::steady_clock
int test4() {
    // 获取开始时间点
    chrono::steady_clock::time_point start = chrono::steady_clock::now();
    // 开始业务
    f();
    // 获取结束时间点
    chrono::steady_clock::time_point last = chrono::steady_clock::now();
    // 计算差值
    auto dt = last - start;
    cout << "consuming time: " << dt.count() << "ns" << endl;

    return 0;
}


/*
转换函数
chrono::duration_cast
    duration_cast 是 chrono 库提供的一个模板函数，这个函数不属于 duration 类。
        通过这个函数可以对 duration 类对象内部的时钟周期 Period，和周期次数的类型 Rep 进行修改.

    如果是对时钟周期进行转换：源时钟周期必须能够整除目的时钟周期（比如：小时到分钟）。
    如果是对时钟周期次数的类型进行转换：低等类型默认可以向高等类型进行转换（比如：int 转 double）。
    如果时钟周期和时钟周期次数类型都变了，根据第二点进行推导（也就是看时间周期次数类型）。
    以上条件都不满足，那么就需要使用 duration_cast 进行显示转换。
*/


int test5() {
    auto t1 = chrono::steady_clock::now();
    f();
    auto t2 = chrono::steady_clock::now();
    // 整数时长：时钟周期纳秒转毫秒，要求 duration_cast
    auto int_ms = chrono::duration_cast<chrono::milliseconds>(t2 - t1);
    // 小数时长：不要求 duration_cast
    chrono::duration<double, ratio<1, 1000>> fp_ms = t2 - t1;
    cout << "f() took " << fp_ms.count() << " ms, "
        << "or " << int_ms.count() << " whole milliseconds\n";

    return 0;
}


/*
chrono::time_point_cast
    time_point_cast 也是 chrono 库提供的一个模板函数，这个函数不属于 time_point 类。
        函数的作用是对时间点进行转换，因为不同的时间点对象内部的时钟周期 Period，
        和周期次数的类型 Rep 可能也是不同的，一般情况下它们之间可以进行隐式类型转换，
        也可以通过该函数显示的进行转换
*/
using Clock = chrono::high_resolution_clock;
using Ms = chrono::milliseconds;
using Sec = chrono::seconds;

template<class Duartion>
using TimePoint = chrono::time_point<Clock, Duartion>;

void print_ms(const TimePoint<Ms>& time_point){
    cout<<time_point.time_since_epoch().count()<<" ms\n";
}

int test6(){
    TimePoint<Sec> time_point_sec(Sec(6));

    TimePoint<Ms> time_point_ms(time_point_sec); // 无精度损失, 可以进行隐式类型转换
    print_ms(time_point_ms); // 6000 ms

    time_point_ms = TimePoint<Ms>(Ms(6789));

    TimePoint<Sec> sec(time_point_ms);  // error, 会损失精度. 不允许进行隐式的类型转换

    // 显示类型转换,会损失精度.
    time_point_sec = chrono::time_point_cast<Sec>(time_point_ms);
    print_ms(time_point_sec); // 6000 ms

    return 0;
}


int main(int argc, char const *argv[])
{
    test6();
    return 0;
}
