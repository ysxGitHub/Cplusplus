#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <unordered_set>
#include <unordered_map>
using namespace std;

vector<int> v{ 1,2,3,4,5,6 };
vector<int>& getRange()
{
    cout << "get vector range..." << endl;
    return v;
}

int main(void){
    vector<int> t{ 1,2,3,4,5,6 };

    cout << "遍历修改之前的容器: ";

    for (auto &value : t){ // 该过程会发生copy, 所以使用 & 引用的效率会高些
        cout << value++ << " ";
    }

    cout << endl << "遍历修改之后的容器: ";


    for (const auto value : t){ // 不想修改其值，但还是想提高效率，所以使用 const
        cout << value << " ";
    }
    cout << endl;




    map<int, string> m{
        {1, "lucy"},{2, "lily"},{3, "tom"}
    };

    // 基于范围的for循环方式
    for (auto& it : m){  //auto == pair<const int, std::string>
        cout << "id: " << it.first << ", name: " << it.second << endl;
    }

    // 普通的for循环方式
    for (auto it = m.begin(); it != m.end(); ++it){ // it 类似指针
        cout << "id: " << it->first << ", name: " << it->second << endl;
    }





    set<int> st{ 1,2,3,4,5,6 }; // 只读
    for (auto &item : st){
        cout << item++ << endl;		// error, 不能给常量赋值
    }

    for (auto& item : m){
        // item.first 是一个常量
        cout << "id: " << item.first++ << ", name: " << item.second << endl;  // error
    }





    unordered_map<int, string>umap{
        {1, "lucy"},{2, "lily"},{3, "tom"}};

    unordered_set<int> uset{ 1,2,3,4,5,6 };

    for (auto &item : uset){
        cout << item++ << endl;		// error, 不能给常量赋值
    }

    for (auto& item : umap){
        // item.first 是一个常量
        cout << "id: " << item.first++ << ", name: " << item.second << endl;  // error
    }


    /*
    对应基于范围的 for 循环来说，冒号后边的表达式只会被执行一次。
        在得到遍历对象之后会先确定好迭代的范围，基于这个范围直接进行遍历。
        如果是普通的 for 循环，在每次迭代的时候都需要判断是否已经到了结束边界。
    */
    for (auto val : getRange()){
        cout << val << " ";
    }
    cout << endl;


    return 0;
}

