///15-11-2020
///Segment tree + divide and conquer

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

void build(int at, int l, int r){

    if(l==r){
        tree[at].index=l;
        tree[at].val=arr[l];
        return ;
    }
    int mid=(l+r)/2;
    build(at*2, l, mid);
    build(at*2+1, mid+1, r);
    tree[at]=tree[at*2].val<=tree[at*2+1].val?tree[at*2]:tree[at*2+1];
}

node query(int at, int l, int r){

    if(R<l or r<L){
        return {0,sz};
    }
    if(L<=l and r<=R){
        return tree[at];
    }
    int mid=(l+r)/2;
    node left=query(at*2, l, mid);
    node right=query(at*2+1, mid+1, r);
    return left.val<=right.val?left:right;
}

int main(){

    Fast;

    int t, n, cs=1;
    cin>>t;
    while(t--){
        cin>>n;
        for(int i=1; i<=n; i++)cin>>arr[i];
        build(1, 1, n);
        queue < pair< int , int > > q;
        int ans=0;

        q.push({1,n});
        while(!q.empty()){
            L=q.front().first;
            R=q.front().second;
            q.pop();
            node temp=query(1, 1, n);
            int idx=temp.index;
            int vl=temp.val;
            ans=max(ans, vl*(R-L+1));
            if(idx-1>=L){
                q.push({L, (idx-1)});
            }
            if(idx+1<=R){
                q.push({(idx+1), R});
            }
        }
        cout<<"Case "<<cs++<<": "<<ans<<endl;

    }


    return 0;
}
