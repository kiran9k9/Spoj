#include <bits/stdc++.h>
#define ll long long
#define sec second
#define fir first
#define pb push_back
#define mp make_pair
using namespace std;
int main(){
	int test;
	scanf("%d",&test);
	while(test--){
		int n,x;
		scanf("%d",&n);
		std::vector<int> v;
		for(int i=0;i<n;i++){
			scanf("%d",&x);
			v.pb(x);
		}
		int flag=0;
		for(int i=0;i<v.size()-1;i++)
			if(v[i]<v[i+1])
				flag=1;
		if(flag==0){
			cout<<-1<<endl;
			continue;
		}
		next_permutation(v.begin(), v.end());
		for(int i=0;i<v.size();i++)
			printf("%d",v[i]);
		printf("\n");
	}
	return 0;
}