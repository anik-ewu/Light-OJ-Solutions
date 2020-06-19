///Date     : 5/5/2020
///ALGO     : Dynamic Programming ( Digit DP)
///Notes    : Position of the numbers in the array doesn't matter
///Comments : Just because someone stumbles, loses their way, doesn't mean they lost forever.

#include<bits/stdc++.h>
using namespace std;
#define sz 11
int s,n;
int arr[sz];
int dp[sz][sz];

int cal(int curr, int prev){
    if(curr==n)return 1;

    if(dp[curr][prev]!=-1)return dp[curr][prev];
    int sum=0;
    for(int i=1; i<=s; i++){
        if(abs(arr[i]-prev)<=2){
            sum+=cal(curr+1,arr[i]);
        }
    }
    return dp[curr][prev]=sum;
}

int main(){

    int cs=1,i,t;
    cin>>t;
    while(t--){
        cin>>s>>n;
        for(i=1; i<=s; i++)
            cin>>arr[i];
        memset(dp,-1,sizeof(dp));
        int sum=0;
        for(i=1; i<=s; i++){
            sum+=cal(1,arr[i]);
        }
        cout<<"Case "<<cs++<<": "<<sum<<endl;
    }
    return 0;
}
