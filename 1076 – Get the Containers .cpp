#include<bits/stdc++.h>
using namespace std;
#define s 1000005
#define mod 1000000009
char Q,Z;
double l,r;
vector < int > v;

bool fitting(int m, int mid)
{
    long long int i,sum=0,count=0;
    for(i=0; i<v.size(); i++)
    {
        if(v[i]>mid)return false;
        if(sum+v[i]<=mid)
        {
            sum+=v[i];
        }
        else
        {
            m--;
            i--;
            sum=0;
        }
        if(m==0)break;
    }
    if(i>=v.size()-1)return true;
    return false;
}

int bisection(int m,long long int Max)
{
    long long int low=0,high=Max,mid,ans=999999999;
    while(low<=high)
    {
        mid=low+(high-low)/2;
        if(fitting(m,mid))
        {
            ans=min(ans,mid);
            high=mid-1;
        }
        else
            low=mid+1;
    }
    return ans;
}

int main()
{
    long long int a,b,c,i,j,k,t,n,m,q,x,y,Max;
    cin>>t;
    for(i=1; i<=t; i++)
    {

        scanf("%lld%lld",&n,&m);
        Max=0;
        for(j=1; j<=n; j++)
        {
            scanf("%lld",&a);
            v.push_back(a);
            Max+=a;
        }
        int z=bisection(m,Max);
        printf("Case %lld: %d\n",i,z);

    }
    return 0;
}
