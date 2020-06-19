///Date     :   25.4.2020
///LOJ      :   1157 - LCS Revisited
///Approach :   Dynamic Programming
///Idea     :   Build 2 next array (i.e: we will know from every index the index of next a to z)
///Note     :   string must be 1 based indexing

#include<bits/stdc++.h>
using namespace std;
#define sz  1002
#define mod 1000007
#define ll  long long

int len;
string s,p;
int dp[sz][sz];
int dp2[sz][sz];
int arr1[sz][26];
int arr2[sz][26];

int lcs(int i, int j){
    if(i>=s.size() || j>=p.size())return 0;
    if(dp[i][j]!=-1)return dp[i][j];
    int ret=0;
    if(s[i]==p[j])ret=1+lcs(i+1,j+1);
    else  ret=max(lcs(i,j+1),lcs(i+1,j));
    return dp[i][j]=ret;
}

int path(int p1, int p2, int step){

    if(step==len)return 1;
    if(dp2[p1][p2]!=-1)return dp2[p1][p2]%mod;
    ll ret=0;
    for(int i=0; i<26; i++){
        if(lcs(arr1[p1][i],arr2[p2][i])==len-step){
            ret=(ret+(path(arr1[p1][i],arr2[p2][i],step+1)%mod))%mod;
        }
    }
    return dp2[p1][p2]=ret%mod;
}

void make(int n, int m){
    int i,j;
    for(i=0; i<26; i++)arr1[n][i]=n+n;
    for(i=0; i<26; i++)arr2[m][i]=m+m;
    for(i=n; i>=0; i--){
        for(j=0; j<26; j++){
            arr1[i-1][j]=arr1[i][j];
        }
        arr1[i-1][s[i]-'a']=i;
    }
    for(i=m; i>=0; i--){
        for(j=0; j<26; j++){
            arr2[i-1][j]=arr2[i][j];
        }
        arr2[i-1][p[i]-'a']=i;
    }
}

int main(){

    int t,cs=1;
    cin>>t;
    while(t--){
        cin>>s>>p;
        s.insert(s.begin(),'0');///1 base
        p.insert(p.begin(),'-1');///1 base
        make(s.size()-1,p.size()-1);///creating next array
        memset(dp,-1,sizeof(dp));
        memset(dp2,-1,sizeof(dp2));
        len=lcs(1,1);///find lcs
        path(0,0,0);///count ways
        cout<<"Case "<<cs++<<": "<<path(0,0,0)<<endl;
    }
    return 0;
}
