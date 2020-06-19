#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
char f,g;
string s,p;
map< int, int > mi;
map< string, int > ms;
vector < int > v,va;
double arr[1000005];//brr[100005];

void fill_mark()
{

    double sum=0;
    for(int i=1.0; i<=1000001; i++)
    {
        sum+=1.0/i;
        arr[i]=sum;
    }
}

int main()
{
    fill_mark();

    int a,b,c,i,n;
    double k,p;
    p=0.5772156699;
    cin>>n;
    for(i=1; i<=n; i++)
    {
        scanf("%d",&a);

        k=log(a+0.5);
        k+=p;
        printf("Case %d: %0.10f\n",i,k);
    }
    return 0;

}

