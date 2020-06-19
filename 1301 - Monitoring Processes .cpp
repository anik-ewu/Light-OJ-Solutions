#include<bits/stdc++.h>
using namespace std ;
int main()
{
    int t,n,a,b,i,j,k,x,y,count=0;
    vector < pair < int, int > > v,va;

    scanf("%d",&t);
    for(i=1; i<=t; i++)
    {
        v.clear();
        scanf("%d",&n);

        for(j=1; j<=n; j++)
        {
            scanf("%d%d",&a,&b);
            v.push_back(make_pair(a,b));
        }

        sort(v.begin(),v.end());
        count =0;
        priority_queue < pair < int, int > >pq;

        for(j=0; j<n; j++)
        {
            if(!j)
            {
                pq.push(make_pair(-v[j].second,v[j].first));
            }
            else
            {
                x=v[j].first;
                y=v[j].second;

                while(!pq.empty() and pq.top().first*-1<x)
                {
                    pq.pop();
                }
                pq.push(make_pair(-y,x));
            }
            int sz=pq.size();
            count=max(count,sz);
        }
        printf("Case %d: %d\n",i,count);
    }
    return 0;
}


