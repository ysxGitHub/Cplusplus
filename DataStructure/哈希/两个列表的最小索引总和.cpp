/*
假设 Andy 和 Doris 想在晚餐时选择一家餐厅，并且他们都有一个表示最喜爱餐厅的列表，
    每个餐厅的名字用字符串表示。

你需要帮助他们用最少的索引和找出他们共同喜爱的餐厅。 如果答案不止一个，则输出所有答案并且不考虑顺序。 
    你可以假设答案总是存在。
*/

#include<unordered_map>
#include<iostream>
#include<vector>
using namespace std;

vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
    unordered_map<string, int> index;
    for (int i = 0; i < list1.size(); i++) {
        index[list1[i]] = i;
    }

    vector<string> ret;
    int indexSum = INT_MAX;
    for (int i = 0; i < list2.size(); i++) {
        if (index.count(list2[i]) > 0) {
            int j = index[list2[i]];
            if (i + j < indexSum) {
                ret.clear();
                ret.push_back(list2[i]);
                indexSum = i + j;
            } else if (i + j == indexSum) {
                ret.push_back(list2[i]);
            }
        }
    }
    return ret;
}