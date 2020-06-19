///Topic : Rolling Hash

#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007

char s[1000006];
char pat[1000006];

int big_mod(long long int base, long long int power)
{
    if(power==0)
        return 1;
    else if(power%2==1)
    {
        long long int p1 = base % mod;
        long long int p2 = (big_mod(base,power-1))%mod;
        return (p1*p2)%mod;
    }
    else if(power%2==0)
    {
        long long int p1 = (big_mod(base,power/2))%mod;
        return (p1*p1)%mod;
    }
}

long long int find_ans()
{
    long long int pow,i,x;
    long long int h_value=0,ans=0,match_value=0;

    int pat_len=strlen(pat);
    pow=pat_len-1;

    for(i=0; i<pat_len; i++)
    {
        x=pat[i];
        x*=big_mod(27,pow--);
        h_value=(h_value+(x%mod))%mod;
    }

    pow=pat_len-1;
    int str_len=strlen(s);
    int sub=big_mod(27,pow);

    for(i=0; i<str_len; i++)
    {
        if(i<pat_len)
        {
            x=s[i];
            x*=big_mod(27,pow--);
            match_value=(match_value+(x%mod))%mod;
        }
        else
        {
            x=s[i-pat_len];
            x*=sub;
            match_value=((match_value+mod)-(x%mod))%mod;
            match_value=(((match_value*27)%mod)+s[i])%mod;
        }
        if(match_value==h_value)
            ans++;
    }
    return ans;
}

int main()
{

    int i,x,t;
    scanf("%d",&t);
    for(i=1; i<=t; i++)
    {
        scanf("%s%s",&s,&pat);
        x=find_ans();
        printf("Case %d: %d\n",i,x);
    }

    return 0;
}
///Over Flow
///Multiple Hash

