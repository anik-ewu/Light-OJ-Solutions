#include<bits/stdc++.h>
using namespace std;

bool vis[21][21];

int solve(int n, int m){

    set< int > st;
    queue< int > line;
    queue< pair< int , int > > q;
    memset(vis, 0, sizeof(vis));
    for(int i=1; i<=m; i++)q.push({i,0});
    for(int i=1; i<=n; i++)line.push(i);
    long long sum=0;

    while(true){
        if(st.size()==m)break;
        int u=q.front().first;
        int v=q.front().second;
        cout<<u<<' '<<v<<endl;
        q.pop();

        bool ok=true;
        if(v){
            for(int i=1; i<=m; i++){
                if(vis[i][v]==0){
                    line.push(v);
                    ok=false;
                    break;
                }
            }
        }
        if(ok)st.insert(v);
        if(st.size()==m)break;
        sum+=5;
        stack< int > STK;
        if(line.empty()){
            q.push({u,0});
        }
        while(!line.empty()){
            int x=line.front();
            line.pop();
            if(vis[u][x]==0){
                vis[u][x]=1;
                q.push({u,x});
                break;
            }
            else
                STK.push(x);
        }
       while(!STK.empty()){
            line.push(STK.top());
            STK.pop();
        }
    }

    return sum;

}

int main(){

    freopen("in.txt", "r", stdin);

    int t, n, m;
    cin>>t;
    for(int i=1; i<=t; i++){
        cin>>n>>m;
        cout<<"Case "<<": "<<solve(n, m)<<endl;
    }

    return 0;
}
