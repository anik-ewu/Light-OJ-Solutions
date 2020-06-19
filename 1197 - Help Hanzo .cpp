#include<bits/stdc++.h>
using namespace std;
#define S 10000000
bool mark[S+7];
vector< int >prime,segment;
bool seive()
{
    int i,j;
    for( i=4; i<S; i+=2)
        mark[i]=1;
    for(i=3; i*i<=S; i+=2)
    {
        if(mark[i]==0)
        {
            for(j=i*i; j<S; j+=i+i)
                mark[j]=1;
        }
    }
    prime.push_back(2);
    for(i=3; i<S; i+=2)
    {
        if(mark[i]==0)
        {
            prime.push_back(i);
        }
    }
}

int segment_seive(long long int l, long long int u)
{
    long long int root,start,si,i,j,count=0;
    root=sqrt(u)+1;
    segment.clear();
    for(i=l; i<=u; i++)
        segment.push_back(i);

    if(l==1)
        count++;
    for(i=0; prime[i]<=root; i++)
    {
        si=prime[i];
        start=si*si;
        if(start<l)
        {
            start=((l+si-1)/si)*si;
        }
        for(j=start; j<=u; j+=si)
        {
            if(segment[j-l]!=0)
            {
                segment[j-l]=0;
                count++;
            }
        }

    }
    return count;
}

int main()
{
    seive();
    long long int a,b,c,l,u,n,i,j,k,count;
    cin>>n;
    for(i=1; i<=n; i++)
    {
        cin>>l>>u;
        int ans=segment_seive(l,u);
        a=(u-l)+1;
        ans=a-ans;
        cout<<"Case "<<i<<": "<<ans<<endl;
    }
    return 0;
}
