#include<bits/stdc++.h>
using namespace std;
#define sz 12
char matrix[sz+1][sz+1];
int color[sz+5][sz+5],dist[sz+5][sz+5];
vector < pair < char ,pair < int , int > > > vp;

int dx[]={1, -1, 0, 0};
int dy[]={0, 0, 1, -1};

void init(){
    memset(color,0,sizeof(color));
    memset(dist,0,sizeof(dist));
}

bool valid(int x, int y, int n){
    if(x>=1 and x<=n and y>=1 and y<=n and matrix[x][y]=='.' and color[x][y]==0)return true;///inside grid
    return false;
}

int bfs(int x1,int y1,int x2,int y2, int n)
{
    queue< pair < int, int > > q;
    q.push({x1,y1}),color[x1][y1]=1, dist[x1][y1]=0;

    while(!q.empty()){
        int x=q.front().first;
        int y=q.front().second;
        q.pop();
        if(x==x2 and y==y2){return dist[x][y];} /// reached destination

        for(int i=0; i<4; i++){
            int xx=x+dx[i];
            int yy=y+dy[i];

            if(valid(xx,yy,n)){
                q.push({xx,yy});/// newly visited
                color[xx][yy]=1;
                dist[xx][yy]=dist[x][y]+1;
            }
        }
    }
    return -1; ///not rechable
}

int main()
{
    int x1,y1,x2,y2;
    int n,m, i, j, k, ts, x, y, cnt, step;
    cin>>ts;
    for(int ii=1; ii<=ts; ii++){
        cin>>n;
        init();
        cnt=0;

        for(j=1; j<=n; j++){
            for(k=1; k<=n; k++){
                cin>>matrix[j][k];
                if(matrix[j][k]=='A')x=j,y=k;
                if(matrix[j][k]>='A' and matrix[j][k]<='Z')cnt++,vp.push_back({matrix[j][k],{j,k}});
            }
        }
        sort(vp.begin(),vp.end());
        step=0;
        for(i=0; i<cnt-1; i++){
             init();
             x1=vp[i].second.first, y1=vp[i].second.second;
             x2=vp[i+1].second.first, y2=vp[i+1].second.second;
             matrix[x1][y1]='.', matrix[x2][y2]='.';

             int temp=bfs(x1,y1,x2,y2,n);

             if(temp<0){step=-1;break;}
             step+=temp;
        }
        if(step<0)cout<<"Case "<<ii<<": "<<"Impossible"<<endl;
        else cout<<"Case "<<ii<<": "<<step<<endl;

        vp.clear();
    }

    return 0;
}

