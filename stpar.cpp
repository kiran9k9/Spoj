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
		if(n==0) 
			break;
		int a[n];
		for(int i=0;i<n;i++)
			scanf("%d",&a[i]);
		int value=1;
		stack<int>s;
		for(int i=0;i<n;i++){
			//	cout<<value<<" "<<s.size()<<endl;
			if(a[i]!=value){
				if(!s.empty() and value==s.top()){
					value++;
					s.pop();
					while(!s.empty() and s.top()==value){
						value++;
						s.pop();
					}
					s.push(a[i]);
				}
				else
					s.push(a[i]);
			}
			else
				value++;
		}
		while(!s.empty()){
			if(value==s.top()){
				value++;
				s.pop();
			}
			else break;
		}
		//cout<<value<<" "<<s.size()<<endl;
		if(value==n+1 and s.empty())
			cout<<"yes\n";
		else cout<<"no\n";
	}
	return 0;
}