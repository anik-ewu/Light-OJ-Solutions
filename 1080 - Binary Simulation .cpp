#include<bits/stdc++.h>
using namespace std;
#define size 100009

int L,R;
char  arr[size+5];
int tree[4 * size];
int lazy[4 * size];

void build(int node , int l, int r)
{
    if(l==r)
    {
        tree[node]=arr[l-1]-'0';
        return ;
    }
    int left=node*2;
    int right=(node*2)+1;
    int mid=(l+r)/2;

    build(left,l,mid);
    build(right,mid+1,r);
}

void update( int node , int l, int r)
{
    if(lazy[node])
    {
        tree[node]=(tree[node]+1)%2;
        if(l!=r) /// not a leaf
        {
            lazy[node*2]=(lazy[node*2]+1)%2;
            lazy[node*2+1]=(lazy[node*2+1]+1)%2;
        }
        lazy[node]=0;
    }

    if(r<L || l>R) /// outside of the range
        return;

    if(l>=L and r<=R)  ///total overlap
    {
        tree[node]=(tree[node]+1)%2;

        if(l!=r) /// not a leaf
        {
            lazy[node*2]=(lazy[node*2]+1)%2;
            lazy[node*2+1]=(lazy[node*2+1]+1)%2;
        }
        return;
    }

    int left=node*2;
    int right=(node*2)+1;
    int mid=(l+r)/2;

    update(left,l,mid);
    update(right,mid+1,r);
}

void query(int node ,int l ,int r,int index)
{

    if(index<l || index>r) /// outside of the range
    {
        return;
    }
    if(lazy[node])
    {
        tree[node]=(tree[node]+1)%2;
        if(l!=r) /// not a leaf
        {
            lazy[node*2]=(lazy[node*2]+1)%2;
            lazy[node*2+1]=(lazy[node*2+1]+1)%2;
        }
        lazy[node]=0;
    }

    if(l==r) ///total overlap
    {
        printf("%d\n",tree[node]);
        return;
    }
    int left=node*2;
    int right=(node*2)+1;
    int mid=(l+r)/2;

    query(left,l,mid,index);
    query(right,mid+1,r,index);
}

int main()
{
    bool mark;
    char f,brr[2];
    int t,n,a,b,i,q,key,val,index;

    scanf("%d",&t);
    for(i=1; i<=t ; i++)
    {
        scanf("%s",&arr);
        scanf("%d",&q);

        memset(lazy,0,sizeof(lazy));

        n=strlen(arr);
        build(1,1,n);

        mark=true;
        while(q--)
        {
            scanf("%s",&brr);
            f=brr[0];

            if(f=='I')
            {
                scanf("%d%d",&L,&R);
                update(1,1,n);
            }
            else
            {
                if(mark)
                    printf("Case %d:\n",i);
                mark=false;

                scanf("%d",&index);
                query(1,1,n,index);
            }
        }
    }
    return 0;
}
