///LightOJ  :   1025 - The Specials Menu
///Approach :   Dynamic Programming+( inclusion exclusion )
///Notes    :   ***
#include<bits/stdc++.h>
using namespace std;
#define ll long long int

string s;
ll dp[61][61];

ll cal(int l, int r){
    if(l>r)return 0;
    if(l==r)return 1;
    if(dp[l][r]!=-1)return dp[l][r];

    ll tot=cal(l+1,r)+cal(l,r-1)-cal(l+1,r-1);///subtracting overlapping part
    if(s[l]==s[r])tot+=(1+cal(l+1,r-1));///SALADS adding 1 for "SS" and (l+1,r-1) for ALAD
    return dp[l][r]=tot;
}

int main(){

    int t,cs=1;
    cin>>t;
    while(t--){
        cin>>s;
        memset(dp,-1,sizeof(dp));
        cout<<"Case "<<cs++<<": "<<cal(0,s.size()-1)<<endl;
    }

    return 0;
}
