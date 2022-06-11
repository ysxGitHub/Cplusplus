/*
结构体内成员按照声明顺序存储，第一个成员地址和整个结构体地址相同。
未特殊说明时，按结构体中size最大的成员对齐（若有double成员，按8字节对齐。）

alignof可以计算出类型的对齐方式，alignas可以指定结构体的对齐方式。
*/

#include <iostream>

// alignas 生效的情况
void test1(){
    struct Info {
    uint8_t a;
    uint16_t b;
    uint8_t c;
    };

    struct alignas(4) Info2 {
    uint8_t a;
    uint16_t b;
    uint8_t c;
    };

    std::cout << sizeof(Info) << std::endl;   // 6  2 + 2 + 2
    std::cout << alignof(Info) << std::endl;  // 2

    std::cout << sizeof(Info2) << std::endl;   // 8  4 + 4
    std::cout << alignof(Info2) << std::endl;  // 4
}

// // alignas 失效的情况
// void test2(){
//     struct Info {
//     uint8_t a;
//     uint32_t b;
//     uint8_t c;
//     };

//     struct alignas(2) Info2 {
//     uint8_t a;
//     uint32_t b;
//     uint8_t c;
//     };

//     std::cout << sizeof(Info) << std::endl;   // 12  4 + 4 + 4
//     std::cout << alignof(Info) << std::endl;  // 4

//     std::cout << sizeof(Info2) << std::endl;   // 12  4 + 4 + 4
//     std::cout << alignof(Info2) << std::endl;  // 4
// }

// 如果想使用单字节对齐的方式，使用alignas是无效的。应该使用#pragma pack(push,1)或者使用__attribute__((packed))。

void test3(){
#if defined(__GNUC__) || defined(__GNUG__)
  #define ONEBYTE_ALIGN __attribute__((packed))
#elif defined(_MSC_VER)
  #define ONEBYTE_ALIGN
  #pragma pack(push,1)
#endif

struct Info {
  uint8_t a;
  uint32_t b;
  uint8_t c;
} ONEBYTE_ALIGN;

#if defined(__GNUC__) || defined(__GNUG__)
  #undef ONEBYTE_ALIGN
#elif defined(_MSC_VER)
  #pragma pack(pop)
  #undef ONEBYTE_ALIGN
#endif

    std::cout << sizeof(Info) << std::endl;   // 6 1 + 4 + 1
    std::cout << alignof(Info) << std::endl;  // 6
}

// 确定结构体中每个元素大小可以通过下面这种方法:
void test4(){

#if defined(__GNUC__) || defined(__GNUG__)
  #define ONEBYTE_ALIGN __attribute__((packed))
#elif defined(_MSC_VER)
  #define ONEBYTE_ALIGN
  #pragma pack(push,1)
#endif

/**
* 0 1   3     6   8 9            15
* +-+---+-----+---+-+-------------+
* | |   |     |   | |             |
* |a| b |  c  | d |e|     pad     |
* | |   |     |   | |             |
* +-+---+-----+---+-+-------------+
*/
struct Info {
  uint16_t a : 1;
  uint16_t b : 2;
  uint16_t c : 3;
  uint16_t d : 2;
  uint16_t e : 1;
  uint16_t pad : 7;
} ONEBYTE_ALIGN;

#if defined(__GNUC__) || defined(__GNUG__)
  #undef ONEBYTE_ALIGN
#elif defined(_MSC_VER)
  #pragma pack(pop)
  #undef ONEBYTE_ALIGN
#endif

    std::cout << sizeof(Info) << std::endl;   // 2
    std::cout << alignof(Info) << std::endl;  // 1
}


int main(int argc, char const *argv[])
{
    test1();
    std::cout<<"************************"<<std::endl;
    // test2();
    test3();
    std::cout<<"************************"<<std::endl;
    test4();
    std::cout<<"************************"<<std::endl;

    // int *p = (int*)malloc(sizeof(int));

    return 0;
}

