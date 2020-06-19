#include<bits/stdc++.h>
using namespace std;
#define S 100500
int arry[S];
int tree[4*S];
int N,L,R,M,inf=100000000;

void build(int node , int l, int r)
{
    if(l==r){
        tree[node]=arry[l];
        return ;
    }
    int left=node*2;
    int right=(node*2)+1;
    int mid=(l+r)/2;

    build(left,l,mid);
    build(right,mid+1,r);
    tree[node]=min(tree[left],tree[right]);
}

int query(int node , int l , int r)
{
    if(R<l || L>r)
        return inf;
    if(L<=l and r<=R){
        return tree[node];
    }
    int left=node*2;
    int right=(node*2)+1;
    int mid=(l+r)/2;

    int q1=query(left,l,mid);
    int q2=query(right,mid+1,r);
    return min(q1,q2);
}


int main()
{
    int i,j,a,b,n,m,t;

    scanf("%d",&t);

    for(i=1; i<=t; i++){
        scanf("%d%d",&n,&m);
        for(j=1; j<=n; j++){
            scanf("%d",&arry[j]);
        }
        build(1,1,n);
        printf("Case %d:\n",i);

        while(m--){
            scanf("%d%d",&L,&R);
            int ans=query(1,1,n);
            printf("%d\n",ans);
        }
    }
    return 0;
}
