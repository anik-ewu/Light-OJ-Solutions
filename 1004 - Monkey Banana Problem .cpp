#include<bits/stdc++.h>
using namespace std;

int n;
int dp[510][510];
int w[510][510];

int main()
{

    int n,t,i,j,k,x,y,z=1;
    cin>>t;
    while(t--)
    {
        cin>>n;
        memset(dp,-1,sizeof(dp));
        for(j=1; j<=n; j++)
            for(k=1; k<=j; k++)
                cin>>w[j][k];
        x=n-1;
        for(j=n+1; j<n*2; j++)
        {
            for(k=1; k<=x; k++)
                cin>>w[j][k];
            x--;
        }
        dp[1][1]=w[1][1];
        for(i=1; i<=n; i++)
        {
            for(j=1; j<=i; j++)
            {
                dp[i+1][j]=max(dp[i+1][j],w[i+1][j]+dp[i][j]);
                dp[i+1][j+1]=max(dp[i+1][j+1],w[i+1][j+1]+dp[i][j]);
            }

        }
        x=n-1;
        for(i=n+1; i<n*2; i++)
        {
            for(j=1; j<=x; j++)
            {
                y=max(dp[i-1][j],dp[i-1][j+1]);
                dp[i][j]=w[i][j]+y;
            }
            x--;
        }
        cout<<"Case "<<z++<<": "<<dp[n*2-1][1]<<endl;
    }
    return 0;
}

