#include<bits/stdc++.h>
using namespace std;

#define sz      30005
#define Fast    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

int L, R;
int arr[sz];
struct node{
    int index;
    int val;
}tree[4*sz];

void build(int node, int l, int r){

    if(l==r){
        tree[node].index=l;
        tree[node].val=arr[l];
        return ;
    }
    int mid=(l+r)/2;
    build(node*2, l, mid);
    build(node*2+1, mid+1, r);
    tree[node]=tree[node*2].val<=tree[node*2+1].val?tree[node*2]:tree[node*2+1];
}

node query(int node, int l, int r){

    if(R<l or r<L){
        return {0,sz};
    }
    if(L<=l and r<=R){
        return tree[node];
    }
    int mid=(l+r)/2;
    query(node*2, l, mid);
    query(node*2+1, mid+1, r);
    return (tree[node*2].val<=tree[node*2+1].val?tree[node*2]:tree[node*2+1];
}

int main(){

    Fast;

    int t, n, cs=1;
    cin>>t;
    while(t--){
        cin>>n;
        for(int i=1; i<=n; i++)cin>>arr[i];
        build(1, 1, n);
        L=R=1;
        node temp=query(1, 1, n);
        cout<<temp.index<<' '<<temp.val<<' '<<endl;

    }

    return 0;
}
/*
1
7
2 1 4 5 1 3 3
*/

