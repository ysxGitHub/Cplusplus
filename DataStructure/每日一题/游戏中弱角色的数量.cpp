/*
你正在参加一个多角色游戏，每个角色都有两个主要属性：攻击 和 防御 。
    给你一个二维整数数组 properties ，其中 properties[i] = [attacki, defensei] 表示游戏中
    第 i 个角色的属性。

如果存在一个其他角色的攻击和防御等级 都严格高于 该角色的攻击和防御等级，
    则认为该角色为 弱角色 。更正式地，如果认为角色 i 弱于 存在的另一个角色 j ，
    那么 attackj > attacki 且 defensej > defensei 。

返回 弱角色 的数量。
*/
#include<iostream>
#include<vector>
#include<unordered_set>
#include<algorithm>
using namespace std;

int numberOfWeakCharacters(vector<vector<int>>& properties) {
    unordered_set<int> seen;
    int nums = 0;
    for(int i = 0; i < properties.size(); i++){
        for(int j=i+1; j<properties.size(); j++){
            if(seen.find(i)!=seen.end()||seen.find(j)!=seen.end()){
                continue;                
            }
            if(properties[i][0]>properties[j][0]&&properties[i][1]>properties[j][1]){
                nums++;
                seen.insert(j);
            }else if(properties[i][0]<properties[j][0]&&properties[i][1]<properties[j][1]){
                nums++;
                seen.insert(i);
            }
        }
    } 
    return nums;
}


bool cmp(vector<int>a, vector<int>b){
    return a[0]==b[0]?a[1]<b[1]:a[0]>b[0]; 
}

int numberOfWeakCharacters1(vector<vector<int>>& properties){
    /*
    在按照攻击降序，且攻击相同时防御升序排列后，记录最大防御，假设当前的防御比之前的最大防御小，
    即可确认当前的是弱角色;
    理由是：在相同的攻击内，防御是升序，出现的防御大于当前，肯定是来自于攻击更大的那些组
    */
    int ans=0;
    int maxdefense = 0;
    stable_sort(properties.begin(), properties.end(), [](vector<int>a, vector<int>b){
            return a[0]==b[0] ? a[1]<b[1] : a[0]>b[0];
        });

    for(int i=0; i<properties.size(); i++){
        int defense = properties[i][1];
        if(defense<maxdefense){
            ans++;
        }else{
            maxdefense = defense;
        }
    }
    return ans;
}

int main(int argc, char const *argv[])
{
    vector<vector<int>> properties = {{7,7},{1,2},{9,7},{7,3},{3,10},{9,8},{8,10},{4,3},{1,5},{1,5}};
    cout<<numberOfWeakCharacters1(properties)<<endl;
    return 0;
}
