/*
n 张多米诺骨牌排成一行，将每张多米诺骨牌垂直竖立。在开始时，同时把一些多米诺骨牌向左或向右推。

每过一秒，倒向左边的多米诺骨牌会推动其左侧相邻的多米诺骨牌。同样地，
    倒向右边的多米诺骨牌也会推动竖立在其右侧的相邻多米诺骨牌。

如果一张垂直竖立的多米诺骨牌的两侧同时有多米诺骨牌倒下时，由于受力平衡， 该骨牌仍然保持不变。

就这个问题而言，我们会认为一张正在倒下的多米诺骨牌不会对其它正在倒下或
    已经倒下的多米诺骨牌施加额外的力。

给你一个字符串 dominoes 表示这一行多米诺骨牌的初始状态，其中：

    dominoes[i] = 'L'，表示第 i 张多米诺骨牌被推向左侧，
    dominoes[i] = 'R'，表示第 i 张多米诺骨牌被推向右侧，
    dominoes[i] = '.'，表示没有推动第 i 张多米诺骨牌。
返回表示最终状态的字符串。
*/

#include<iostream>
using namespace std;

string pushDominoes(string dominoes) {
    int len = dominoes.length();
    int pos = 0;
    char first=' ';
    char second=' ';
    string ans = dominoes;
    for(int i=0; i<len; i++){
        char tmp = dominoes[i];
        if(tmp!='.'){
            if(tmp=='L'){
                second = first;
                first = 'L'; 
            }
            else{
                second = first;
                first = 'R';
            }
            if(first=='L'&&second==' '&&pos==0){
                while(pos<=i){
                    ans[pos++] = 'L';
                }
            }
            if(first=='R'&&second==' '&&pos==0){
                while(pos<i){
                    ans[pos++] = '.';
                }
                ans[pos++] = 'R';

            }
            if(first=='L'&&second=='L'){
                while(pos<=i){
                    ans[pos++] = 'L';
                }
            }
            if(first=='R'&&second=='L'){
                while(pos<i){
                    ans[pos++] = '.';
                }
                ans[pos++] = 'R';
            }
            if(first=='R'&&second=='R'){
                while(pos<i){
                    ans[pos++] = 'R';
                }
                ans[pos++] = 'R';
            }
            if(first=='L'&&second=='R'){
                if((pos+i-1)%2==0){
                    for(int k=pos-1; k<=i; k++){
                        if(k<(pos+i-1)/2){
                            ans[k]='R'; 
                        }
                        else if(k==(pos+i-1)/2){
                            ans[k]='.';
                        }
                        else{
                            ans[k]='L';
                        }
                    }
                }
                else{
                    for(int k=pos-1; k<=i; k++){
                        if(k<=(pos+i-1)/2){
                            ans[k]='R';
                        }
                        else{
                            ans[k]='L';
                        }
                    }                    
                }
                pos=i+1;
            }
        }
        if(first=='L'&&i==len-1){
            while(pos<=i){
                ans[pos++] = '.';
            }
        }
        if(first=='R'&&i==len-1){
            while(pos<=i){
                ans[pos++] = 'R';
            }            
        }
    }
    
    return ans;
}

/*
'R......R' => 'RRRRRRRR'
'R......L' => 'RRRRLLLL' or 'RRRR.LLLL'
'L......R' => 'L......R'
'L......L' => 'LLLLLLLL'
所以给dominoes的左边加上一个‘L’, 右边加一个‘R’
*/

string pushDominoes1(string dominoes) {
    dominoes = 'L' + dominoes + 'R'; // 添加虚拟的牌
    string res;
    int l = 0;
    for(int r = 1; r < dominoes.length(); r ++){
        if(dominoes[r] == '.'){
            continue;
        }
        // 中间的‘.’的个数
        int mid = r - l - 1;
        // 放入两端的 L or R 
        if(l){  // 虚拟的牌不放入结果
            res += dominoes[l];
        }
        // 'R......R' => 'RRRRRRRR' or 'L......L' => 'LLLLLLLL'
        if(dominoes[l] == dominoes[r]){
            for(int i = 0; i < mid; i ++){
                res += dominoes[l];
            }
        }
        // 'L......R' => 'L......R' 
        else if(dominoes[l] == 'L' && dominoes[r] == 'R'){
            for(int i = 0; i < mid; i ++){
                res += '.';
            }
        } // 'R......L' => 'RRRRLLLL' or 'RRRR.LLLL'
        else{
            int half = mid/2;
            for(int i = 0; i < half; i ++){
                res += 'R';
            }
            if(mid % 2){
                res += '.';
            }
            for(int i = 0; i < half; i ++){
                res += 'L';
            }            
        }
        // l等于，相当于保存上一次的结果（L or R）
        l = r;
    }
    return res;
}

int main(int argc, char const *argv[])
{
    string dominoes = "R.LL.R..R.L...R...L...R....L....R...LLLL....RRR....LRLRLR.....LLL....R";
    cout<<pushDominoes1(dominoes);
    // "R.LL.RRRR.L...RR.LL...RRRLLL....RR.LLLLL....RRRRRLLLRLRLRRR.LLLLL....R"
    return 0;
}
