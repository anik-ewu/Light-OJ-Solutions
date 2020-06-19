#include<bits/stdc++.h>
using namespace std;
#define sz 200005
int L,R;
int lazy[4*sz];
set < int > st;

void shift(int at, int l, int r){
    if(lazy[at]){
        if(l!=r){
            lazy[at*2]=lazy[at*2+1]=lazy[at];
            lazy[at]=0;
        }
    }
    return;
}

void update(int at, int l, int r, int val){
    shift(at,l,r);
    if(R<l || r<L)return;
    if(L<=l && r<=R){
        lazy[at]=val;
        shift(at,l,r);
        return;
    }
    int mid=(l+r)/2;
    update(at*2,l,mid,val);
    update(at*2+1,mid+1,r,val);

}
void cnt(int at, int l, int r){

    if(lazy[at]){
        st.insert(lazy[at]);
        return;
    }
    if(l==r)return;
    int mid=(l+r)/2;
    cnt(at*2,l,mid);
    cnt(at*2+1,mid+1,r);

}
int main(){


    int t,n,m,q,i,cs=1;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        st.clear();
        memset(lazy,0,sizeof(lazy));
        for(i=1; i<=n; i++){
            scanf("%d%d",&L,&R);
            update(1,1,n*2,i);
        }
        cnt(1,1,n*2);
        int ans=st.size();
        printf("Case %d: %d\n",cs++,ans);
    }
    return 0;
}
