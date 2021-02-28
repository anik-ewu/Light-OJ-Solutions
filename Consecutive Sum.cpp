/*
Algo: Trie Tree
Date: 29-02-2021
Idea: Make cumilitative xor or array elements push in trie. 
Then just find a pair of number from cumilitative arry to get min and max xor. 
Before getting min we just need to decrease the frequency num by 1, from trie.
And after saving the min res, we have to push that num in trie again. bingo :) 
*/

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int sz;
int cum[50005];
int fre[1700005];
int trie[1700000][2];

void init(){
	sz=0;
	memset(cum, 0, sizeof(cum));
	memset(fre, 0, sizeof(fre));
	memset(trie, -1, sizeof(trie));
}

int power(int i){
	int num=1;
	while(i--)num*=2;
	return num;
}

void insert(string s){
	int n=32;
	int curr=0, next;
	for(int i=0; i<n; i++){
		next=trie[curr][s[i]-'0'];
		fre[curr]++;
		if(next==-1){
			trie[curr][s[i]-'0']=++sz;
		}
		curr=trie[curr][s[i]-'0'];
	}
	fre[curr]++;
}

void remove(string s){
	int n=32;
	int curr=0, next;
	for(int i=0; i<n; i++){
		next=trie[curr][s[i]-'0'];
		fre[curr]--;
		curr=next;
	}
	fre[curr]--;
}

string query(string s){
	int n=32;
	int curr=0, next;
	for(int i=0; i<n; i++){
		next=trie[curr][s[i]-'0'];
		if(next==-1 || fre[next]<1){
			if(s[i]=='0')s[i]='1';
			else s[i]='0';
		}
		curr=trie[curr][s[i]-'0'];
	}
	return s; 
}

int main(){

	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	
	int mx,mn;
	int a, t, n, cs=1;
	scanf("%d", &t);
	while(t--){
		
		init();//clear
		mx=0;
		mn=INT_MAX;
		scanf("%d", &n);
		for(int i=1; i<=n; i++){
			scanf("%d", &a);
			mn=min(mn, a);
			mx=max(mx, a);
			cum[i]=cum[i-1]^a;///cumulitative xor
		}
		
		string s;
		bitset< 32 > bits;
		for(int i=0; i<=n; i++){
			bits=cum[i];
			s=bits.to_string();
		    insert(s);///push in trie
		}

		int num;
		for(int i=1; i<=n; i++){
			bits=cum[i];
			s=bits.to_string();
			for(int j=0; j<32; j++){
				if(s[j]=='0')s[j]='1';
				else s[j]='0';
			}
		    s=query(s);///get max
		    
		    num=0;
		    for(int j=0; j<32; j++){
		    	if(s[j]=='1'){
		    		num+=power(32-(j+1));
		    	}
		    }
		    num=num^cum[i];
		    mx=max(mx, num);
		}

		for(int i=1; i<=n; i++){
			bits=cum[i];
			s=bits.to_string();
			remove(s); ///decreading the frequency of s by 1
		    s=query(s);///get min
		    num=0;
		    for(int j=0; j<32; j++){
		    	if(s[j]=='1'){
		    		num+=power(32-(j+1));
		    	}
		    }
		    num=num^cum[i];
		    mn=min(mn, num);

		    bits=cum[i];
			s=bits.to_string();///adding the removed bit stream
		    insert(s);
		}
		printf("Case %d: %d %d\n",cs++,mx, mn);

	}

	return 0;
}