#include<bits/stdc++.h>
using namespace std;
#define fl(n)           for(int i=0; i<n; i++)
#define fl1(n)          for(int i=1; i<=n; i++)

#define sf              scanf
#define pf              printf
#define pb              push_back
#define nl              printf("\n")
#define ll              long long int

#define F               first
#define S               second
#define PI              2*acos(0.0)

#define gcd(x,y)        __gcd(x,y)
#define lcm(a,b)        (a*(b/gcd(a,b)))

#define MOD             1000000007
#define MX              INT_MAX
#define Sz              100005
#define FastIO          { ios_base::sync_with_stdio(false); cin.tie(0); }

int vertex,edge;
vector < int>adj[600];
vector < int >cost[605];
int dis[600];

int diajkstra(int src)
{
    priority_queue<pair<int,int> > Q;
    Q.push(make_pair(0,src));
    dis[src]=0;
    while(!Q.empty())
    {
        int u=Q.top().S;
        Q.pop();
        for(int i=0; i<adj[u].size(); i++)
        {

            int v=adj[u][i];
            int temp=max(dis[u],cost[u][i]);
            if(temp<dis[v])
            {
                dis[v]=temp;
                Q.push(make_pair(dis[v]*-1,v));
            }
        }
    }
}

int main()
{

    int t,i,j,a,b,c,src;

    sf("%d",&t);

    for(i=1; i<=t; i++)
    {
        sf("%d%d",&vertex,&edge);
        for(int ii=0; ii<=vertex; ii++)
            dis[ii]=INT_MAX;

        for(j=1; j<=edge; j++)
        {
            sf("%d%d%d",&a,&b,&c);
            adj[b].pb(a);
            adj[a].pb(b);
            cost[a].pb(c);
            cost[b].pb(c);
        }
        sf("%d",&src);
        diajkstra(src);

        pf("Case %d:\n",i);
        for(int k=0; k<vertex; k++)
        {
            if(dis[k]==INT_MAX)
                pf("Impossible\n");
            else
                pf("%d\n",dis[k]);
        }
        for(int k=0; k<vertex; k++)
        {
            adj[k].clear();
            cost[k].clear();
        }

    }

    return 0;
}


