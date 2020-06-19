#include<cstdio>
#include<stdio.h>
#include<string.h>
#include<iostream>
using namespace std;
///ACGT
int ans;
struct trie *root;
struct trie
{
    int con=0;
    trie *next[4];
    trie()
    {
        con=0;
        for(int i=0; i<4; i++)
            next[i]=NULL;
    }
};

int findid(char f)
{
    if(f=='A')
        return 0;
    else if(f=='C')
        return 1;
    else if(f=='T')
        return 2;
    else
        return 3;
}

void insert(char *str, trie *curr)
{
    int x;
    for(int i=0; str[i]; i++)
    {
        int id=findid(str[i]);
        if(curr->next[id]==NULL)
            curr->next[id]=new trie();

        curr=curr->next[id];
        curr->con++;

        x=curr->con*(i+1);
        ans=max(ans,x);
    }
}

void del(trie *curr)
{
    for(int i=0; i<4; i++)
        if(curr->next[i])
            del(curr->next[i]);
    delete(curr);
}


int main()
{
    char str[60];
    int t,n,m,i,j,a,b;

    scanf("%d",&t);
    for(i=1; i<=t; i++)
    {
        scanf("%d",&n);

        root=new trie();

        ans=0;
        for(j=1; j<=n; j++)
        {
            scanf("%s",&str);
            insert(str,root);

            int size=strlen(str);
            ans=max(ans,size);
        }

        printf("Case %d: %d\n",i,ans);
        del(root);
    }
    return 0;
}
