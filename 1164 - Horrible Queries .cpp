#include<bits/stdc++.h>
using namespace std;
#define size 100009
typedef long long int ll;
long long int tree[4 * size];
long long int arr[size+5];
long long int lazy[4 * size];

ll sum;
int L,R;

void build(int node , int l, int r)
{
    if(l==r)
    {
        tree[node]=arr[l];
        return ;
    }

    int left=node*2;
    int right=(node*2)+1;
    int mid=(l+r)/2;

    build(left,l,mid);
    build(right,mid+1,r);
    tree[node]=tree[left]+tree[right];

}

ll update( int node , int l, int r, int val)
{
    if(lazy[node])
    {
        tree[node]+=lazy[node]* ((r-l)+1);

        if(l!=r)
        {
            lazy[node*2]+=lazy[node];
            lazy[node*2+1]+=lazy[node];
        }
        lazy[node]=0;
    }

    if(r<L || l>R) /// outside of the range
        return 0;

    if(l>=L and r<=R)  ///total overlap
    {
        tree[node]+=val * ( (r-l)+1 );

        if(l!=r) /// not a leaf
        {
            lazy[node*2]+=val;
            lazy[node*2+1]+=val;
        }
        return 0;
    }

    int left=node*2;
    int right=(node*2)+1;
    int mid=(l+r)/2;

    update(left,l,mid,val);
    update(right,mid+1,r,val);
    tree[node]=tree[left]+tree[right];
}

ll query(int node , int l , int r)
{

    if(R<l || L>r) /// outside of the range
    {
        return 0;
    }
    if(lazy[node])
    {
        tree[node]+=lazy[node]* ((r-l)+1);
        if(l!=r) /// not a leaf
        {
            lazy[node*2]+=lazy[node];
            lazy[node*2+1]+=lazy[node];
        }
        lazy[node]=0;
    }

    if(L<=l and r<=R) ///total overlap
    {
        return tree[node];
    }
    int left=node*2;
    int right=(node*2)+1;
    int mid=(l+r)/2;

    ll  q1=query(left,l,mid);
    ll  q2=query(right,mid+1,r);
    return q1+q2;
}

int main()
{
    bool mark;
    int t,n,a,b,i,q,key,val;

    scanf("%d",&t);
    for(i=1; i<=t ; i++)
    {
        scanf("%d%d",&n,&q);

        memset(arr,0,sizeof(arr));
        memset(lazy,0,sizeof(lazy));
        memset(tree,0,sizeof(tree));

        build(1,1,n);

        mark=true;
        while(q--)
        {
            scanf("%d",&key);
            if(key==0)
            {
                scanf("%d%d%d",&L,&R,&val);
                L++;
                R++;
                update(1,1,n,val);
            }
            else
            {
                scanf("%d%d",&L,&R);
                L++;
                R++;
                sum=query(1,1,n);

                if(mark)
                    printf("Case %d:\n",i);
                printf("%lld\n",sum);
                mark=false;
            }
        }
    }
}
