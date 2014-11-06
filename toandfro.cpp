#include <bits/stdc++.h>
#define ll long long
#define mp make_pair
#define pb push_back
#define fir first
#define sec second
#define mod 1000000009
using namespace std;
int main(){
	while(1){
		int n;
		cin>>n;
		string s;
		if(n==0)
			break;
		cin>>s;
		for(int i=n;i<s.size();i+=(2*n)){
			int k=0;
			int r=(2*i+n)/2;
			for(int j=i;j<r;j++){
				swap(s[j],s[i+n-1-k]);
				k++;
			}
		}
		//cout<<s<<endl;
		for(int i=0;i<n;i++){
			for(int j=i;j<s.size();j+=n)
				cout<<s[j];
		}
		cout<<endl;
	}
	return 0;
}