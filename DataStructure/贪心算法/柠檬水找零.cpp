/*
在柠檬水摊上，每一杯柠檬水的售价为 5 美元。顾客排队购买你的产品，（按账单 bills 支付的顺序）一次购买一杯。

每位顾客只买一杯柠檬水，然后向你付 5 美元、10 美元或 20 美元。你必须给每个顾客正确找零，也就是说净交易是每位顾客向你支付 5 美元。

注意，一开始你手头没有任何零钱。

给你一个整数数组 bills ，其中 bills[i] 是第 i 位顾客付的账。如果你能给每位顾客正确找零，返回 true ，否则返回 false 。
*/
#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

bool lemonadeChange(vector<int>& bills) {
    if(bills[0]>5) return 0;
    int n = bills.size();
    int five = 0, ten = 0;
    for(const auto&bill: bills){
        if(bill==5) five++;
        else if(bill==10){
            if(five<=0){
            return false;
            } else {
                five--;
                ten++;
            }
        }
        if(bill==20){
            if(five<=0||(ten==0&&five<3)) {
                return false;
            } else{
                if(ten>0){
                    five--;
                    ten--;
                }else{
                    five-=3;
                }
            }
        }
    }
    return true;
}