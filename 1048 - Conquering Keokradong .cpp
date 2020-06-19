#include<bits/stdc++.h>
using namespace std;
vector < int > v,va,vb;

bool bisection(int n, int k)
{
    int sum=0;
    for(int i=0; i<v.size(); i++)
    {
        if(v[i]>n || k==0)
            return false;
        sum+=v[i];
        if(sum>n)
        {
            sum=v[i];
            k--;
        }
        else if(sum==n)
        {
            sum=0;
            k--;
        }
    }
    if(sum)
        k--;
    if(k<0)
        return false;
    return true;
}

bool print(int n, int k)
{
    int j,sum=0,cnt=0,x=0;

    cnt=v.size()-k;
    for(int i=0; i<v.size(); i++)
    {
        sum=v[i];
        j=i+1;
        while(j<v.size() and cnt)
        {
            if(sum+v[j]>n)
                break;
            else
                sum+=v[j];
            cnt--;
            j++;
        }
        i=j-1;
        va.push_back(sum);
    }
    for(int i=0; i<va.size(); i++)
    {
        printf("%d\n",va[i]);
    }
    va.clear();
}

int main()
{

    int a,n,t,i,j,k,ans,mx;
    scanf("%d",&t);

    for(i=1; i<=t; i++)
    {
        scanf("%d%d",&n,&k);
        mx=0;
        for(j=1; j<=n+1; j++)
        {
            scanf("%d",&a);
            v.push_back(a);
            mx=max(mx,a);
        }

        int low,high,mid,x,cnt=0;

        low=1;
        high=10000007;
        k++;
        while(low<high and cnt<50)
        {
            cnt++;

            mid=(low+high)/2;
            if(bisection(mid,k))
            {
                ans=mid;
                high=mid;
            }
            else
            {
                low=mid+1;
            }
        }
        printf("Case %d: %d\n",i,ans);
        print(ans,k);

        v.clear();
    }
    return 0;
}
