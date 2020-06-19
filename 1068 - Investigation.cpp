///Date     :   23/5/2020
///Approach :   Dynamic Programming ( Digit DP)
///Notes    :   For k>90 the result will be always zero, because sum of digit will never be greater than 90
///Comments :   Faiths can move the mountain.
#include<bits/stdc++.h>
using namespace std;
#define ll long long

string s;
int len,k;
ll dp[11][2][92][92];

ll cal(int pos, bool smaller, int num, int sum){
    if(k>90)return 0;
    if(pos==len){
        return (num==0 ||num%k==0) && sum%k==0 ? 1:0;
    }
    if(dp[pos][smaller][num][sum]!=-1)return dp[pos][smaller][num][sum];
    ll total=0;
    int limit=9;
    if(!smaller)limit=s[pos]-'0';
    for(int i=0; i<=limit; i++){
        total+=cal(pos+1,smaller||(i<limit), ((num*10)+i)%k, (sum+i)%k);
    }
    return dp[pos][smaller][num][sum]=total;
}

void convert(ll n){
    stringstream ss;
    ss<<n;
    ss>>s;
    return;
}

int main(){

    ///freopen("out.txt","w",stdout);
    ll total,t,a,b,cs=1;
    scanf("%lld",&t);
    while(t--){

        scanf("%lld%lld%lld",&a,&b,&k);

        convert(b);
        len=s.size();
        memset(dp,-1,sizeof(dp));
        total=cal(0,0,0,0);

        convert(a-1);
        len=s.size();
        memset(dp,-1,sizeof(dp));
        if(a-1>=0)total-=cal(0,0,0,0);

        printf("Case %lld: %lld\n",cs++,total);
    }
    return 0;
}
