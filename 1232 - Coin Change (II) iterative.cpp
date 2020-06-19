#include<bits/stdc++.h>
using namespace std;
#define mod 100000007
#define FastRead   ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

int freq;
int arr[101];///value
int dp[101][10001];

void init(int n, int k){

    for(int i=1; i<=n; i++){
        for(int j=1; j<=k; j++){
            dp[i][j]=-1;
        }
    }
}

int Dp(int n, int k){

    int i,j;
    for(i=0; i<=k; i++)dp[0][i]=0;
    for(i=0; i<=n; i++)dp[i][0]=1;
    for(i=1; i<=n; i++){
        for(j=1; j<=k; j++){
            if(arr[i]>j)
                dp[i][j]=(dp[i-1][j])%mod;
            else
                dp[i][j]=(dp[i-1][j]+dp[i][j-arr[i]])%mod;
        }
    }
    return dp[n][k]%mod;
}



int main(){

    FastRead
    int n,k,i,j,m,a,b,c,ans,t;
    cin>>t;
    for(i=1; i<=t; i++){
        cin>>n>>k;
        init(n,k);
        for(j=1; j<=n; j++)cin>>arr[j];
        ans =Dp(n,k);
        cout<<"Case "<<i<<": "<<ans<<endl;
    }
    return 0;
}

