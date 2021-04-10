///9-April-2021
///Classical Segment Tree / Range Query

#include<bits/stdc++.h>
using namespace std;
#define Fast   ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int      N =1e5+5;

int L, R;
int arr[N];
int tree[4*N];

void build(int at, int l, int r){

    if(l==r){
        tree[at]=arr[l];
        return;
    }
    int mid=(l+r)/2;
    build(at*2, l, mid);
    build(at*2+1, mid+1, r);
    tree[at]=min(tree[at*2], tree[at*2+1]);
}


int query(int at, int l, int r){
    if(R<l || r<L)return INT_MAX;
    if(L<=l and r<=R)return tree[at];
    int mid=(l+r)/2;
    return min(query(at*2, l, mid),query(at*2+1, mid+1, r));
}

int main(){

    Fast;
    //read(x);
    //write(x);

    int n, t, q;
    cin>>t;
    for(int tc=1; tc<=t; tc++){
        cin>>n>>q;
        for(int i=1; i<=n; i++)cin>>arr[i];
        build(1, 1, n);
        cout<<"Case "<<tc<<":"<<endl;
        while(q--){
            cin>>L>>R;
            cout<<query(1, 1, n)<<endl;
        }
    }
    return 0;
}

