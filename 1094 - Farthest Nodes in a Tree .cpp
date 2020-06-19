#include<bits/stdc++.h>
using namespace std;

vector < int > edge[30010],cost[30010];
int d[30010],vis[30010];
int mx,p;

void bfs(int s)
{
    queue< int > q;
    int u,v,i;
    q.push(s);
    d[s]=0;
    vis[s]=1;
    while(!q.empty())
    {
        u=q.front();
        q.pop();
        if(d[u]>mx)
        {
            mx=d[u];
            p=u;
        }
        for(i=0; i<edge[u].size(); i++)
        {
            v=edge[u][i];
            if(d[v]<d[u]+cost[u][i] && vis[v]==0)
            {
                d[v]=d[u]+cost[u][i];
                q.push(v);
                vis[v]=1;
            }

        }
    }
}

void all_clear(int n)
{
    for(int i=0; i<=n; i++)
    {
        edge[i].clear();
        vis[i]=0;
        d[i]=0;
        cost[i].clear();
    }
    mx=0;
}


int main()
{

    int src,t,n,i,j,a,b,w;

    cin>>t;
    for(j=1; j<=t; j++)
    {
        scanf("%d",&n);
        all_clear(n);
        for(i=1; i<n; i++)
        {
            scanf("%d%d%d",&a,&b,&w);

            edge[a].push_back(b);
            edge[b].push_back(a);

            cost[a].push_back(w);
            cost[b].push_back(w);
        }

        bfs(0);
        for(i=0; i<n; i++)
        {
            d[i]=0;
            vis[i]=0;
        }
        mx=0;
        bfs(p);

        printf("Case %d: %d\n",j,mx);
    }
    return 0;
}
