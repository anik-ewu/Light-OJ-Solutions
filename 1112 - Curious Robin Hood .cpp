#include<bits/stdc++.h>
using namespace std;
#define sz 100005
bool mark;
int arr[sz+5];
int tree[sz*4];
int L,R,sum,ans;

void build(int node , int l , int r)
{
    if(l==r){
        tree[node]=arr[l];
        return;
    }
    int left=node*2;
    int right=(node*2)+1;
    int mid=(l+r)/2;
    build(left,l,mid);
    build(right,mid+1,r);
    tree[node]=(tree[left]+tree[right]);
}

void update(int node , int l , int r,int pos, int val,int key)
{
    if(pos<l || pos>r)
        return;
    if(l==r){
        if(key==1){
        ans=tree[node];
        tree[node]=0;
        }
        else
            tree[node]+=val;
        return;
    }
    int left=node*2;
    int right=(node*2)+1;
    int mid=(l+r)/2;
    update(left,l,mid,pos,val,key);
    update(right,mid+1,r,pos,val,key);
    tree[node]=(tree[left]+tree[right]);
}

int query( int node, int l, int r)
{
    if(R<l || L>r)
        return 0;
    if(L<=l and R>=r){
        return tree[node];
    }
    int left=node*2;
    int right=(node*2)+1;
    int mid=(l+r)/2;
    int x=query(left,l,mid);
    int y=query(right,mid+1,r);
    return x+y;
}

int main()
{
    int n,i,j,t,op,q,pos,val;

    scanf("%d",&t);
    for(i=1; i<=t; i++){
        scanf("%d%d",&n,&q);

        for(j=1; j<=n; j++){
            scanf("%d",&arr[j]);
        }

        build(1,1,n);
        mark=false;
        while(q--){
           scanf("%d",&op);

           if(op==1){
            scanf("%d",&pos);
            update(1,1,n,pos+1,0,op);
            if(mark==false)
            printf("Case %d:\n",i);
            printf("%d\n",ans);
            mark=true;
            }

           else if(op==2){
            scanf("%d%d",&pos,&val);
            update(1,1,n,pos+1,val,op);
           }

           else{
            scanf("%d%d",&L,&R);
            sum=0;
            L++,R++;
            sum=query(1,1,n);
            if(mark==false)
            printf("Case %d:\n",i);
            printf("%d\n",sum);
            mark=true;
           }
        }
    }
    return 0;
}
