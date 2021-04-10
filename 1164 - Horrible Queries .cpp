/*
Date: 9-April-2021
Tags: Classical Segment Tree
Approach: Segment Tree With Lazy Update
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N= 1e5+5;

int L, R;
ll tree[4*N];
ll lazy[4*N];

void prop(int at, int l, int r){
    tree[at]+=(lazy[at]*(r-l+1));
    if(l!=r){
        lazy[at*2]+=lazy[at];
        lazy[at*2+1]+=lazy[at];
    }
    lazy[at]=0;
}

void update(int at, int  l, int r, int v){
    if(lazy[at])prop(at, l, r);///propagate
    if(R<l || r<L)return ;
    if(L<=l and r<=R){
        tree[at]+=(r-l+1)*v;
        if(l!=r){
            lazy[at*2]+=v;
            lazy[at*2+1]+=v;
        }
        return ;
    }
    int mid=(l+r)/2;
    update(at*2, l, mid, v);
    update(at*2+1, mid+1, r, v);
    tree[at]=tree[at*2]+tree[at*2+1];
}

ll query(int at, int l, int r){
    if(lazy[at])prop(at,l,r);
    if(R<l || r<L)return 0;
    if(L<=l and r<=R)return tree[at];
    int mid=(l+r)/2;
    return (query(at*2, l, mid)+query(at*2+1, mid+1, r));
}

int main(){

    //freopen("in.txt", "r", stdin);

    int t, n, type, q, v;
    cin>>t;
    for(int tc=1; tc<=t; tc++){
        cin>>n>>q;
        memset(lazy, 0, sizeof(lazy));
        memset(tree, 0, sizeof(tree));
        cout<<"Case "<<tc<<":"<<endl;
        while(q--){
            cin>>type>>L>>R;
            L++;R++;///converting into 1 base indexing
            if(type==1){
                cout<<query(1, 1, n)<<endl;
            }
            else{
                cin>>v;
                update(1, 1, n,v);
            }
        }
    }
    return 0;
}
