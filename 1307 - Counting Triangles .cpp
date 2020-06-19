#include<bits/stdc++.h>
using namespace std;

vector < int > v;
int main()
{

    int n,m,i,j,k, t,a,b;
    scanf("%d",&t);

    for(k=1; k<=t; k++)
    {
        scanf("%d",&n);
        for(i=0; i<n; i++)
        {
            scanf("%d",&a);
            v.push_back(a);
        }
        sort(v.begin(),v.end());
        int up,ans=0;
        for(i=0; i<n; i++)
        {
            for(j=i+1; j<n-1; j++)
            {
                int two_side=v[i]+v[j]-1;
                up=upper_bound(v.begin()+j+1,v.end(),two_side)-v.begin();
                up--;
                ans+=(up-j);
            }
        }
        printf("Case %d: %d\n",k,ans);
        v.clear();
    }
    return 0;
}
