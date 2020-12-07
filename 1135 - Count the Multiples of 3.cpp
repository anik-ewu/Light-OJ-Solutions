///Date     : 16-Nov-2020
///Approach : Segment Tree + Lazy Propagation

#include<bits/stdc++.h>
using namespace std;

const int N = 100005;
int L, R;
int lazy[4*N];
struct st{
    int one, two , three;
}tree[4*N];

st combine(st a, st b){
    return {a.one+b.one, a.two+b.two, a.three+b.three};
}

void build(int node, int l, int r){
    if(l==r){
        tree[node]={0, 0, 1};
        lazy[node]=0;
        return;
    }
    int mid=(l+r)/2;
    build(node*2, l, mid);
    build(node*2+1, mid+1, r);
    tree[node]=combine(tree[node*2], tree[node*2+1]);
}

void update_lazy(int node, int l, int r){

    while(lazy[node]){
        swap(tree[node].one, tree[node].two);
        swap(tree[node].one, tree[node].three);
        if(l!=r){
            lazy[node*2]=(lazy[node*2]+1)%3;
            lazy[node*2+1]=(lazy[node*2+1]+1)%3;
        }
        lazy[node]-=1;
    }
}
void update(int node, int l, int r){
    if(lazy[node])update_lazy(node, l, r);
    if(R<l || r<L)return;
    if(L<=l && r<=R){
        swap(tree[node].one, tree[node].two);
        swap(tree[node].one, tree[node].three);
        if(l!=r){
            lazy[node*2]=(lazy[node*2]+1)%3;
            lazy[node*2+1]=(lazy[node*2+1]+1)%3;
        }
        return ;
    }
    int mid=(l+r)/2;
    update(node*2, l, mid);
    update(node*2+1, mid+1, r);
    tree[node]=combine(tree[node*2], tree[node*2+1]);
}

int query(int node, int l, int r){

    if(R<l || r<L)return 0;
    if(lazy[node])update_lazy(node, l, r);
    if(L<=l && r<=R){
        return tree[node].three;
    }
    int mid=(l+r)/2;
    return (query(node*2, l, mid)+query(node*2+1, mid+1, r));
}


int main(){

    ios_base::sync_with_stdio(false);cin.tie(0); cout.tie(0);
    int n, t, q, cs=1, type;
    cin>>t;
    while(t--){
        cin>>n>>q;
        memset(tree, 0, sizeof(tree));
        memset(lazy, 0, sizeof(lazy));
        build(1, 1, n);
        cout<<"Case "<<cs++<<":"<<endl;
        while(q--){
            cin>>type>>L>>R;L++;R++;
            if(type==0){
                update(1, 1, n);
            }
            else{
                cout<<query(1, 1, n)<<endl;
            }
        }
    }

    return 0;
}
