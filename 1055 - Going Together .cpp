#include<bits/stdc++.h>
using namespace std;
#define ff    first
#define ss    second
#define pi    make_pair
#define pii   pair < int , int >
const int fx[]= {+1,-1,+0,+0};
const int fy[]= {+0,+0,+1,-1};

int n;
char graph[10][10];
map < pii, bool >mp;
int  dis[10][10][10][10][10][10];
bool vis[10][10][10][10][10][10];

struct data{
    pii a,b,c;
};

void init(){
    mp.clear();
    memset(vis,0,sizeof(vis));
    memset(dis,0,sizeof(vis));
}

bool check(pii aa){
    if(aa.ff>=0 and aa.ff<n and aa.ss>=0 and aa.ss<n and graph[aa.ff][aa.ss]!='#')return 1;
    return 0;
}

int bfs(data src){

    queue < data > q;
    q.push(src);
    vis[src.a.ff][src.a.ss][src.b.ff][src.b.ss][src.c.ff][src.c.ss]=1;
    dis[src.a.ff][src.a.ss][src.b.ff][src.b.ss][src.c.ff][src.c.ss]=0;

    while(!q.empty()){

        data u=q.front();
        q.pop();
        if(mp[u.a]&& mp[u.b] && mp[u.c] && u.a!=u.b && u.a!=u.c && u.b!=u.c){
            return dis[u.a.ff][u.a.ss][u.b.ff][u.b.ss][u.c.ff][u.c.ss];
        }
        for(int i=0; i<4; i++){

            pii aa=make_pair(u.a.ff+fx[i],u.a.ss+fy[i]);
            if(!check(aa))aa=u.a;
            pii bb=make_pair(u.b.ff+fx[i],u.b.ss+fy[i]);
            if(!check(bb))bb=u.b;
            pii cc=make_pair(u.c.ff+fx[i],u.c.ss+fy[i]);
            if(!check(cc))cc=u.c;

            if(aa==bb){
                aa=u.a;
                bb=u.b;
            }
            if(aa==cc){
                aa=u.a;
                cc=u.c;
            }
            if(bb==cc){
                bb=u.b;
                cc=u.c;
                if(aa==bb || aa==cc)aa=u.a;
            }
            data v;
            v.a=aa;
            v.b=bb;
            v.c=cc;
            if(vis[aa.ff][aa.ss][bb.ff][bb.ss][cc.ff][cc.ss]==0){
                q.push(v);
                vis[v.a.ff][v.a.ss][v.b.ff][v.b.ss][v.c.ff][v.c.ss]=1;
                dis[v.a.ff][v.a.ss][v.b.ff][v.b.ss][v.c.ff][v.c.ss]=dis[u.a.ff][u.a.ss][u.b.ff][u.b.ss][u.c.ff][u.c.ss]+1;

            }
        }
    }
    return -1;
}
int main(){

    int a,b,c,t,tc,i,j,ans;
    cin>>t;
    for(tc=1; tc<=t; tc++){
        cin>>n;
        init();
        data src;
        for(i=0; i<n; i++){
            for(j=0; j<n; j++){
                cin>>graph[i][j];
            if(graph[i][j]=='X') mp[pi(i,j)]=1;
            if(graph[i][j]=='A') src.a=pi(i,j);
            if(graph[i][j]=='B') src.b=pi(i,j);
            if(graph[i][j]=='C') src.c=pi(i,j);
            }
        }
        ans=bfs(src);
        if(ans==-1)
            printf("Case %d: trapped\n",tc);
        else
            printf("Case %d: %d\n",tc,ans);
    }
    return 0;
}

///idea from : https://turing13.wordpress.com/2016/09/11/light-oj-1055-going-together/
