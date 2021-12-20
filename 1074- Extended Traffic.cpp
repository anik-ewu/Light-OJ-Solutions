/*
Date: 27 April 2021
Algo: Bellman ford
Idea: Just simply run Bellman ford.
*/

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=210;
int arr[N];
ll cost[N];
vector< pair< int , int > > adj[N];


int cube(int val){
    return (val*val*val);
}

void bellmanford(int n){

    for(int i=1; i<=n; i++)
        cost[i]=INT_MAX;

    cost[1]=0;
    for(int k=1; k<n; k++){
        for(int i=1; i<=n; i++){
            for(auto x: adj[i]){
                int v=x.first;
                ll w=x.second;
                ll y=w+cost[i];
                if(cost[v]>y){
                    cost[v]=y;
                }
            }
        }
    }
    //**************************************************
    ///marking those nodes which are in a negative cycle
    queue< int > q;
    for(int i=1; i<=n; i++){
        for(auto x: adj[i]){
            int v=x.first;
            ll w=x.second;
            ll y=w+cost[i];
            if(cost[v]!=INT_MAX and cost[v]>y){
                q.push(v);
            }
        }
    }
    while(!q.empty()){
        int u=q.front();
        q.pop();
        cost[u]=-INT_MAX;
        for(auto x: adj[u]){
            int v=x.first;
            if(cost[v]!=-INT_MAX){
                q.push(v);
            }
        }
    }
    //*****************************************
}

int main(){

    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

    int t, n, m, a, b, w;
    cin>>t;
    for(int tc=1; tc<=t; tc++){
        cin>>n;
        for(int i=1; i<=n; i++)
            adj[i].clear();
        for(int i=1; i<=n; i++)
            cin>>arr[i];

        cin>>m;
        for(int i=1; i<=m; i++){
            cin>>a>>b;
            int x=cube(arr[b]-arr[a]);
            adj[a].push_back({b, x});
        }

        int des, q;
        cout<<"Case "<<tc<<":"<<endl;
        cin>>q;

        bellmanford(n); ///to check negative cycle

        while(q--){
            cin>>des;
            if(cost[des]<INT_MAX/3 and cost[des]>2)
                cout<<cost[des]<<endl;
            else
                cout<<'?'<<endl;
        }
    }

    return 0;
}
