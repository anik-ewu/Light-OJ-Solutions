///Date     : 6/5/2020
///ALGO     : Dynamic Programming ( Digit DP )
///Notes    : For cnt state on cal function, 32 is enough because the depth of the TREE will be < 32
///Comments : Just because someone stumbles, loses their way, doesn't mean they lost forever.

#include<bits/stdc++.h>
using namespace std;
#define ll long long

int len;
string s;
ll dp[32][2][2][32];

ll cal(int pos, bool small, bool prev, ll cnt){
    if(pos==len)return cnt;
    if(dp[pos][small][prev][cnt]!=-1)return dp[pos][small][prev][cnt];
    ll sum=0;
    int limit=1;
    if(!small)limit=s[pos]-'0';
    for(int i=0; i<=limit; i++){
        sum+=cal(pos+1, small||(i<limit), i, cnt+(i==1 && prev==1));
    }
    return dp[pos][small][prev][cnt]=sum;
}
void bin(int n){
    s="";
    while(n){
        s+=((n%2)+'0');
        n/=2;
    }
    reverse(s.begin(),s.end());
    len=s.size();
}

int main(){

    int t,n,cs=1;
    cin>>t;
    while(t--){
        cin>>n;
        bin(n);    ///converting into binary string
        memset(dp,-1,sizeof(dp));
        cout<<"Case "<<cs++<<": "<<cal(0,0,0,0)<<endl;
    }
    return 0;
}

