/*
Algorithm: BFS/DFS
There is an unlimited supply of commando troops for the mission, so we can assign one commando
for destroying one building. So, the i'th commando have to:
1. Start from the building s and go to the i'th building
2. From the i'th building, go to building d
So, we have to calculate (shortest path from s to i) + (shortest path from d to i)
for all commandos, and find the maximum value among these.
*/

#include<bits/stdc++.h>
using namespace std;
#define sz 101
int dis[sz];
int dis2[sz];
bool vis[101];
vector < int > adj[101];

void bfs(int src){

    queue < int > q;
    q.push(src);
    vis[src]=1;
    dis[src]=0;
    while(!q.empty()){
       int u=q.front();
       q.pop();
       for(int i=0; i<adj[u].size(); i++){
           int v=adj[u][i];
           if(vis[v]==0){
               vis[v]=1;
               dis[v]=dis[u]+1;
               q.push(v);
           }
       }
    }
}

void bfs2(int src){

    queue < int > q;
    q.push(src);
    vis[src]=1;
    dis2[src]=0;
    while(!q.empty()){
       int u=q.front();
       q.pop();
       for(int i=0; i<adj[u].size(); i++){
           int v=adj[u][i];
           if(vis[v]==0){
               vis[v]=1;
               dis2[v]=dis2[u]+1;
               q.push(v);
           }
       }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int tc,t,i,j,a,b,c,n,m;
    cin>>t;
    for(tc=1; tc<=t; tc++){
        cin>>n>>m;
        for(i=0; i<n; i++)adj[i].clear();
        for(i=1; i<=m; i++){
            cin>>a>>b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }

        int src,des,ans=-1;
        cin>>src>>des;

        memset(vis,0,sizeof(vis));
        memset(dis,0,sizeof(dis));
        bfs(src);

        memset(vis,0,sizeof(vis));
        memset(dis2,0,sizeof(dis2));
        bfs2(des);

        for(i=0; i<n; i++){
            ans=max(ans,dis[i]+dis2[i]);
        }

        cout<<"Case "<<tc<<": "<<ans<<endl;
    }

    return 0;
}
