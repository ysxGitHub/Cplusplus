/*
1 <= s.length <= 15
I 1; V 5; X 10; L 50; C 100; D 500; M 1000
I 可以放在 V (5) 和 X (10) 的左边，来表示 4 和 9。
X 可以放在 L (50) 和 C (100) 的左边，来表示 40 和 90。 
C 可以放在 D (500) 和 M (1000) 的左边，来表示 400 和 900。
*/
#include<iostream>
using namespace std;

int romanToInt(string s) {
    int num=0;
    int lens = s.length();
    for(int i=0; i<lens; i++){
        if(s[i]=='I'){
            num+=1;
        }
        else if(s[i]=='V'){
            if(i!=0&&s[i-1]=='I'){
                num+=(4-1);
            }else{
                num+=5;
            }
        }
        else if(s[i]=='X'){
            if(i!=0&&s[i-1]=='I'){
                num+=(9-1);
            }else{
                num+=10;
            }
        }
        else if(s[i]=='L'){
            if(i!=0&&s[i-1]=='X'){
                num+=(40-10);
            }else{
                num+=50;
            }
        }
        else if(s[i]=='C'){
            if(i!=0&&s[i-1]=='X'){
                num+=(90-10);
            }else{
                num+=100;
            }
        }
        else if(s[i]=='D'){
            if(i!=0&&s[i-1]=='C'){
                num+=(400-100);
            }else{
                num+=500;
            }
        }
        else if(s[i]=='M'){
            if(i!=0&&s[i-1]=='C'){
                num+=(900-100);
            }else{
                num+=1000;
            }
        }
    }
    return num;
}



int main(int argc, char const *argv[])
{
    cout<<romanToInt("MCMXCIV");
    return 0;
}
