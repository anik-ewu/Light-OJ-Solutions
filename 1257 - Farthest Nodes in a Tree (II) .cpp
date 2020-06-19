#include<bits/stdc++.h>
using namespace std;

vector < int > edge[30005],cost[30005];
int d[30005],d1[30005],vis[30005];
int s1;

void init(int n)
{
    for(int i=0; i<=n; i++)
    {
        edge[i].clear();
        cost[i].clear();
        vis[i]=0;
        d[i]=0;
        d1[i]=0;
    }
}


int bfs2(int s)
{
    queue< int > q;
    q.push(s);
    d1[s]=0;
    vis[s]=1;
    int i,u,v;
    while(!q.empty())
    {
        u=q.front();
        q.pop();

        for(i=0; i<edge[u].size(); i++)
        {
            v=edge[u][i];

            if(vis[v]==0)
            {
                vis[v]=1;
                if(d1[v]<d1[u]+cost[u][i])
                    d1[v]=d1[u]+cost[u][i];
                q.push(v);
            }
        }
    }
}


int bfs(int s)
{
    queue< int > q;
    q.push(s);
    d[s]=0;
    vis[s]=1;
    int i,u,v,x,mx=-1;
    while(!q.empty())
    {
        u=q.front();
        q.pop();
        if(d[u]>mx)
        {
            mx=d[u];
            x=u;
        }
        for(i=0; i<edge[u].size(); i++)
        {
            v=edge[u][i];

            if(d[v]<d[u]+cost[u][i] && vis[v]==0)
            {
                vis[v]=1;
                d[v]=d[u]+cost[u][i];
                q.push(v);
            }
        }
    }
    return x;
}


int main()
{
    int t,y,n,i,j,s,x,a,b,w;

    scanf("%d",&t);
    for(i=1; i<=t; i++)
    {

        scanf("%d",&n);
        init(n);
        for(j=1; j<n; j++)
        {

            scanf("%d%d%d",&a,&b,&w);
            edge[a].push_back(b);
            edge[b].push_back(a);
            cost[a].push_back(w);
            cost[b].push_back(w);
        }
        x=bfs(0);
        for(j=0; j<=n; j++)
            d[j]=0,vis[j]=0;

        y=bfs(x);
        for(j=0; j<=n; j++)
            vis[j]=0;

        bfs2(y);


        printf("Case %d:\n",i);
        for(j=0; j<n; j++)
        {
            x=max(d[j],d1[j]);
            printf("%d\n",x);
        }

    }

    return 0;
}
