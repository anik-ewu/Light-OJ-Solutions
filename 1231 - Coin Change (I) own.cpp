#include<bits/stdc++.h>
using namespace std;

#define mod  100000007
int arr[100],brr[100];
int n, k;
int dp[65][1100];

void init()
{
    for(int i=0; i<=60; i++)
        for(int j=0; j<=1001; j++)
            dp[i][j]=-1;
}


int coin(int s, int taka)
{
    if(taka==0)
        return 1;
    if(s==0)
        return 0;

    if(dp[s][taka]!=-1)
        return dp[s][taka];


    int a=0,b=0;

    for(int i=1; i<=brr[s]; i++)
        if(taka-(arr[s]*i)>=0)
            a+=coin(s-1,taka-i*arr[s])%mod;
    b=coin(s-1,taka)%mod;

    return dp[s][taka]=(a+b)%mod;

}

int main()
{
    int a,b,c, m,t, i,j;

    cin>>t;

    for(i=1; i<=t; i++)
    {
        cin>>n>>k;
        for(j=1; j<=n; j++)
            cin>>arr[j];///coin array

        for(j=1; j<=n; j++)
            cin>>brr[j];///frequency of coins
        init();///initialization
        cout<<"Case "<<i<<": "<<coin(n,k)<<endl;
    }
    return 0;
}
