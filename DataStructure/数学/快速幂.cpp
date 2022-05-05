#include<iostream>
#include<unordered_map>
#include<vector>
#include<cmath>

using namespace std;

#define MOD 1000000007
typedef long long ll;
ll qpow(ll a, ll n)
{
    if (n == 0) return 1;
    else if (n % 2 == 1) return qpow(a, n - 1) * a % MOD;
    else{
        ll temp = qpow(a, n / 2) % MOD;
        return temp * temp % MOD;
    }
}

ll quick_pow(ll a, ll b, ll mod){
    ll ans = 1;
    if(b==0){ return 1; }
    while(b){
        if(b & 1){ ans = (ans * a)%mod; }
        b >>= 1;
        a = (a * a)%mod;
    }
    return ans;
}

ll quick_mul(ll a, ll b, ll mod){
    if(a==0||b==0){ return 0; }
    ll ans = 0;
    while(b){
        if(b & 1){ ans = (ans + a)%mod; }
        b >>= 1;
        a = (a + a)%mod;
    }
    return ans;
}


int main(int argc, char const *argv[])
{
    cout<<qpow(3,14)<<endl;
    cout<<quick_pow(3,14,1000000007)<<endl;
    cout<<quick_mul(0,5,INT32_MAX)<<endl;
    return 0;
}
