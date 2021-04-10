/*9-April-2021
Segment Tree-With Lazy Update
Idea: Build the initial tree each child having a frequency of {1,2,3}->{0,0,1};
Once you get a node to update just make a cyclic shift among the
frequency of 1  2 and 3. So no of 1 become no of two and no of 2 become no of three
and no of 3 become no of one
*/

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define read(x)         freopen("in.txt","r",stdin);
#define write(x)        freopen("out.txt","w",stdout);
#define Fast            ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int               N =1e5+5;

int L, R;
int lazy[4*N];

struct st{
    int one, two, three;
}tree[4*N];

struct st combine(st x, st y){
    return {(x.one+y.one),(x.two+y.two),(x.three+y.three)};
}

void build(int at, int l, int r){
    if(l==r){
        tree[at]={0,0,1};
        return;
    }
    int mid=(l+r)/2;
    build(at*2, l, mid);
    build(at*2+1, mid+1, r);
    tree[at]=combine(tree[at*2], tree[at*2+1]);
}

void move(int at){
    swap(tree[at].one, tree[at].three);
    swap(tree[at].two, tree[at].three);
}
void propagate(int at, int l, int r){
    while(lazy[at]){
        move(at);
        if(l!=r){
            lazy[at*2]++;
            lazy[at*2+1]++;
        }
        lazy[at]--;
    }
}

void update(int at , int l, int r){
    lazy[at]=lazy[at]%3;
    propagate(at,l,r);
    if(R<l || r<L)return;
    if(L<=l and r<=R){
        move(at);
        if(l!=r){
            lazy[at*2]++;
            lazy[at*2+1]++;
        }
        return;
    }
    int mid=(l+r)/2;
    update(at*2, l, mid);
    update(at*2+1, mid+1, r);
    tree[at]=combine(tree[at*2], tree[at*2+1]);
}

int query(int at, int l, int r){
    lazy[at]=lazy[at]%3;
    propagate(at,l,r);
    if(R<l || r<L)return 0;
    if(L<=l and r<=R)return tree[at].three;
    int mid=(l+r)/2;
    return (query(at*2, l, mid)+query(at*2+1, mid+1, r));
}


int main(){

    Fast;
    //read(x);
    //write(x);

    int n, t, q, type;
    cin>>t;
    for(int tc=1; tc<=t; tc++){
        cin>>n>>q;
        build(1, 1, n);
        cout<<"Case "<<tc<<":"<<endl;
        memset(lazy,0,sizeof(lazy));
        while(q--){
            cin>>type>>L>>R;
            L++;R++;///converting into 1 base indexing
            if(type==0)update(1, 1, n);
            if(type==1)cout<<query(1, 1, n)<<endl;
        }
    }
    return 0;
}

