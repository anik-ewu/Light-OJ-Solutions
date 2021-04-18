/*
Date: 16-4-2021
Algo: BFS
IDEA: There is large cycle consisting of each node. So, consider two path from node 1. One
      is clockwise and another is anticlockwise.
      And to calculate the cost, just consider those transition which is (b->a);
*/
#include<bits/stdc++.h>
using namespace std;

const int N= 105;
int mat[N][N];
int vis[N];
vector< int > path;
vector< int > adj[N];


void BFS(){

    queue< int > q;
    memset(vis, 0, sizeof(vis));
    path.clear();
    vis[1]=1;
    q.push(1);
    path.push_back(1);
    while(!q.empty()){
        int u=q.front();
        q.pop();
        for(int v: adj[u]){
            if(vis[v]==0){
                vis[v]=1;
                path.push_back(v);
                q.push(v);
                break;
            }
        }
    }
}

int main(){

    int t, n, m, a, b, c;
    cin>>t;
    for(int tc=1; tc<=t; tc++){
        cin>>n;
        memset(mat, 0, sizeof(mat));
        for(int i=1; i<=n; i++)adj[i].clear();
        for(int i=1; i <=n; i++){
            cin>>a>>b>>c;
            adj[a].push_back(b);
            adj[b].push_back(a);
            mat[b][a]=c;
        }
        BFS();
        path.push_back(1);
        int x=0;
        for(int i=0; i<path.size()-1; i++){
            a=path[i];
            b=path[i+1];
            x+=mat[a][b];
        }
        int sum=x;
        reverse(path.begin(), path.end());
        x=0;
        for(int i=0; i<path.size()-1; i++){
            a=path[i];
            b=path[i+1];
            x+=mat[a][b];
        }
        sum=min(sum, x);
        cout<<"Case "<<tc<<": "<<sum<<endl;

    }
    return 0;

}

