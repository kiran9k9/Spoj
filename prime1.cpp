#include <bits/stdc++.h>
#define ll long long
#define mp make_pair
#define pb push_back
#define fir first
#define sec second
#define mod 1000000009
using namespace std;
vector<int>primes;
void sieve(int n){
	int x=sqrt(n);
	int visited[x+10];
	memset(visited,0,sizeof visited);
	visited[1]=1;
	for(int i=2;i<=sqrt(x);i++){
		if(!visited[i]){
			for(int j=i*i;j<=x;j+=i)
				visited[j]=1;
		}
	}
	for(int i=2;i<=x;i++)
		if(!visited[i])
			primes.pb(i);
}
vector<int>ans;
void segmented_sieve(int n,int m){
	set<int>s;
	//for(int i=0;i<primes.size();i++)
	//	cout<<primes[i]<<" ";
	for(int i=n;i<=m;i++){
		if(i==1)
			continue;
		s.insert(i);
	}
	for(int i=0;i<primes.size();i++){
		int val=n/primes[i];
		val*=primes[i];
		if(val==0 or val==primes[i])
			val=2*primes[i];
		for(int j=val;j<=m;j+=primes[i]){
			s.erase(j);
		}
	}
	set<int>::iterator it;
	for(it=s.begin();it!=s.end();it++)
		printf("%d\n",*it);
	return ;
}
int main(){
	int test;
	scanf("%d",&test);
	while(test--){
		primes.clear();
		ans.clear();
		int n,m;
		scanf("%d%d",&n,&m);
		sieve(m);
		segmented_sieve(n,m);
		printf("\n");
	}
	return 0;
}