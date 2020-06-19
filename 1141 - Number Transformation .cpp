#include<bits/stdc++.h>
using namespace std;

vector < int > prime;
int vis[1005],cost[1005];

void init(){
    memset(vis,0,sizeof(vis));
    memset(cost,INT_MAX,sizeof(cost));
}

void factor (int n, int k){
 for(int i=2; i*i<=n; i++){
    if(n%i==0){
        prime.push_back(i);
        while(n%i==0)n/=i;
    }
  }
 if(n>1 and n!=k)prime.push_back(n);
}

int bfs(int s, int t){

    queue < int > q;
    vis[s]=1;
    cost[s]=0;
    q.push(s);

    while(!q.empty()){

        int x=q.front();
        if(x==t)return cost[t];
        q.pop();
        prime.clear();
        factor(x,x);
        for(int i=0; i<prime.size(); i++){
        int y=x+prime[i];
        if(y>t)break;
        if(vis[y]==0){
            vis[y]=1;
            cost[y]=cost[x]+1;
            q.push(y);
          }
          else cost[y]=min(cost[y],cost[x]+1);
        }
    }
    return -1;
}

int main(){

    int n, i, j, k, x ,s,t, ans, temp;
    cin>>n;
    for(i=1; i<=n; i++){
        cin>>s>>t;
        init();
        ans=bfs(s,t);
        cout<<"Case "<<i<<": "<<ans<<endl;
    }
    return 0;
}
