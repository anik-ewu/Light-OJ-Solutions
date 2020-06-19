///Idea: Build 2 next array ( i.e: we will know from every index the index of next a'b'...z)
///string must be 1 based indexing
#include<bits/stdc++.h>
using namespace std;
#define sz 102

int len;
string s,p;
int dp[sz][sz];
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

void make(int n, int m){
    int i,j;
    for(i=0; i<26; i++)arr1[n][i]=n*n;
    for(i=0; i<26; i++)arr2[m][i]=m*m;
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

void path(int p1, int p2, int step){

    if(step==len)return;
    for(int i=0; i<26; i++){
        if(lcs(arr1[p1][i],arr2[p2][i])==len-step){
            cout<<char(i+'a');
            path(arr1[p1][i],arr2[p2][i],step+1);
            break;
        }
    }
}

int main(){

    int t,cs=1;
    cin>>t;
    while(t--){
        cin>>s>>p;
        ///making one base
        s.insert(s.begin(),'0');
        p.insert(p.begin(),'-1');

        make(s.size()-1,p.size()-1);///making next array
        memset(dp,-1,sizeof(dp));

        len=lcs(1,1);///calculating LCS

        cout<<"Case "<<cs++<<": ";
        if(len==0)cout<<":(";
        else path(0,0,0);///printing lexicographically smallest LCS
        cout<<endl;
    }
    return 0;
}
