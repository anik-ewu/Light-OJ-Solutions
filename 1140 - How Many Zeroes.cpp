///Date     : 6/5/2020
///ALGO     : Dynamic Programming ( Digit DP )
///Notes    : Add one for "0"
///Comments : Just because someone stumbles, loses their way, doesn't mean they lost forever.

#include<bits/stdc++.h>
using namespace std;
#define ll long long
int len;
string str;
ll dp[22][2][2][10];

ll cal(int p, bool isSmall, bool isSig, ll zero){
    if(p==len)return zero;
    if(dp[p][isSmall][isSig][zero]!=-1)return dp[p][isSmall][isSig][zero];
    ll sum=0;
    int limit=9;
    if(!isSmall)limit=str[p]-'0';
    for(int i=0; i<=limit; i++){
        sum+=cal(p+1, isSmall || (i<limit), isSig ||(i>0), zero+(i==0 && isSig));
    }
    return dp[p][isSmall][isSig][zero]=sum;
}

void convert(ll n){
    stringstream ss;
    ss<<n;
    str=ss.str();
}

int main(){

    ll zeros,n,m,t,i,cs=1;
    cin>>t;
    while(t--){
        cin>>m>>n;
        convert(n);
        memset(dp,-1,sizeof(dp));
        len=str.size();
        zeros=cal(0,0,0,0)+1;
        convert(m-1);
        len=str.size();
        memset(dp,-1,sizeof(dp));
        if(m-1>=0)
           zeros-=cal(0,0,0,0)+1;
        cout<<"Case "<<cs++<<": "<<zeros<<endl;
    }
    return 0;
}
