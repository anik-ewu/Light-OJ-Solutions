#include<bits/stdc++.h>
#define MOD  100000007
using namespace std;

int arr[55], num[1005];
int dp[52][1005];

int fun(int pos, int n)
{
    if(n==0)
        return 1;
    if(pos==0)
        return 0;
    if(dp[pos][n]!=-1)
        return dp[pos][n];

    int a=0, b=0;
    b=fun(pos-1,n)%MOD;
    for(int i=1; i<=num[pos]; i++)
        if(n-(arr[pos]*i)>=0)
            a+=fun(pos-1,n-(arr[pos]*i))%MOD;

    return dp[pos][n]=(a+b)%MOD;
}

int main()
{
    int test, n, k;

    scanf("%d",&test);
    for(int t=1; t<=test; t++)
    {
        memset(dp,-1,sizeof(dp));

        scanf("%d %d",&n,&k);
        for(int i=1; i<=n; i++)
            scanf("%d",&arr[i]);
        for(int i=1; i<=n; i++)
            scanf("%d",&num[i]);

        printf("Case %d: %d\n",t,fun(n,k)%MOD);
    }

    return 0;
}
