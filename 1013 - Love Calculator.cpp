///Date     :   22.4.2020
///LightOJ  :   1025 - The Specials Menu
///Approach :   Dynamic Programming
///Notes    :   Find LCS to calculate the length then calculate the ways of making it

#include<bits/stdc++.h>
using namespace std;
string s,p;
#define sz 65
#define ll long long
int len;
int dp[sz][sz];
ll dp2[sz][sz][sz];

int LCS(int i, int j){
    if(i>=s.size() || j>=p.size())return 0;
    if(dp[i][j]!=-1)return dp[i][j];
    int a=0,b=0;
    if(s[i]==p[j])a=1+LCS(i+1,j+1);
    else a=max(LCS(i+1,j),LCS(i,j+1));
    return dp[i][j]=a;
}
ll cal(int i, int j, int l){
    if(i>=s.size()){
        l+=p.size()-j;
        if(l==len)return 1;
        return 0;
    }
    if(j>=p.size()){
        l+=s.size()-i;
        if(l==len)return 1;
        return 0;
    }
    if(dp2[i][j][l]!=-1)return dp2[i][j][l];
    ll ways=0;
    if(s[i]==p[j])ways=cal(i+1,j+1,l+1);
    else{
        ways+=cal(i,j+1,l+1);
        ways+=cal(i+1,j,l+1);
    }
    return dp2[i][j][l]=ways;
}

int main(){

    int t,cs=1;
    cin>>t;
    while(t--){
        cin>>s>>p;
        memset(dp,-1,sizeof(dp));
        memset(dp2,-1,sizeof(dp2));
        len=s.size()+p.size()-LCS(0,0);
        cout<<"Case "<<cs++<<": "<<len<<" "<<cal(0,0,0)<<endl;
    }



    return 0;
}
