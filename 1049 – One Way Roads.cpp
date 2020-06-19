///Idea is to start from 1 and traverse through the whole graph once in clockwise and
///another in counter clockwise and then pick the minimum cost of these above paths
#include<bits/stdc++.h>
using namespace std;
int vis[101];
int mat[101][101];
vector < pair < int , int > > vp;

void dfs(int u, int n){
      vis[u]=1;
      for(int i=1; i<=n; i++){
        if(vis[i]==0 and mat[u][i]){
            vp.push_back({u,i});///saving the path
            dfs(i,n);
         }
      }
}

void init(){
    vp.clear();
    memset(mat,0,sizeof(mat));
    for(int i=0; i<=100; i++){
        vis[i]=0;
    }
}

int main(){

    int t,tc,a,c,b,i,j,n;
    cin>>t;
    for(tc=1; tc<=t; tc++){
        cin>>n;
        init();
        for(i=1; i<=n; i++){
            cin>>a>>b>>c;
            mat[a][b]=-1;
            mat[b][a]=c;
        }
        dfs(1,n);
        vp.push_back({vp[vp.size()-1].second,1});///making cycle

        int temp=0,temp2=0;
        for(i=0; i<vp.size(); i++){
            a=vp[i].first; b=vp[i].second;
            if(mat[a][b]>0)
                temp+=mat[a][b];
            if(mat[b][a]>0){
                temp2+=mat[b][a];
            }
        }
        printf("Case %d: %d\n",tc,min(temp,temp2));
    }
    return 0;
}
