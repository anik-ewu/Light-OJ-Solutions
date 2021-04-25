#include<bits/stdc++.h>
using namespace std;

#define ff first
#define ss second
const int N=1e5+7;
int dis[N], dis2[N];
vector< pair< int , int > > adj[N];

void diajkstra(int s, int n){

    priority_queue< pair< int, int > > pq;
    for(int i=1; i<=n; i++)dis[i]=INT_MAX;
    dis[s]=0;
    pq.push({0, s});
    while(!pq.empty()){
        int u=pq.top().ss;
        int deep=pq.top().ff*-1;
        pq.pop();
        for(auto v: adj[u]){
            int d=dis[u]+v.ss;
            if(dis[v.ff]>d){
                dis[v.ff]=d;
                pq.push({-(deep+1),v.ff});
            }
        }
    }
}

int main(){

    int t, a, b, n, w, m;
    cin>>t;
    for(int tc=1; tc<=t; tc++){
        cin>>n>>m;
        for(int i=1; i<=n; i++)adj[i].clear();

        for(int i=1; i<=m; i++){
            cin>>a>>b>>w;
            adj[a].push_back({b, w});
            adj[b].push_back({a, w});
        }

        diajkstra(1,n);
        for(int i=1; i<=n; i++)dis2[i]=dis[i];
        diajkstra(n,n);

        int ans=INT_MAX;
        for(int i=1; i<=n; i++){
            for(auto v: adj[i]){
                int d=dis2[i]+dis[v.ff]+v.ss;
                if(d>dis2[n]){
                    ans=min(ans, d);
                }
            }
        }
        cout<<"Case "<<tc<<": "<<ans<<endl;
    }

    return 0;
}
