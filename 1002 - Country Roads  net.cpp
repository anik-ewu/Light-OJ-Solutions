#include<bits/stdc++.h>
#define fi(n, m) for(int i=n; i<=m; i++)
#define fd(n, m) for(int i=n; i>=m; i--)
using namespace std;
vector<int>vt[1009], cost[1009];
int dis[1009], n;

struct node
{
    int u, w;
    node(int a, int b)
    {
        u=a, w=b;
    }
    bool operator < (const node & p)const
    {
        return p.w<w;
    }
};

void dijkstra(int st)
{
    priority_queue<node>q;
    fi(0, n)dis[i]=20001;
    dis[st]=0;
    q.push(node(st, 0));
    while(!q.empty())
    {
        node top=q.top();
        q.pop();
        int u=top.u;
        int sz=vt[u].size();
        fi(0, sz-1)
        {
            int v=vt[u][i];
            int temp=max(dis[u], cost[u][i]);
            if(temp<dis[v])
            {
                dis[v]=temp;
                q.push(node(v, dis[v]));
            }
        }
    }
}

int main()
{
    int e, u, v, w, m, t, cs=1;
    cin>>t;
    while(t--)
    {
        cin>>n>>e;
        fi(0, e-1)
        {
            cin>>u>>v>>w;
            vt[u].push_back(v);
            vt[v].push_back(u);
            cost[u].push_back(w);
            cost[v].push_back(w);
        }
        cin>>m;
        dijkstra(m);
        cout<<"Case "<<cs++<<":"<<endl;
        fi(0, n-1)
        {
            if(dis[i]==20001)
                cout<<"Impossible"<<endl;
            else
                cout<<dis[i]<<endl;
        }
        fi(0, n-1)
        {
            vt[i].clear();
            cost[i].clear();
        }
    }
    return 0;
}
