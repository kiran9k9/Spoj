#include <bits/stdc++.h>
#define ll long long
#define sec second
#define fir first
#define pb push_back
#define mp make_pair
using namespace std;
int main(){
	int value=1;
	while(1){
		string s;
		cin>>s;
		if(s[0]=='-')
			break;
		stack<int>st,st1;
		int count=0;
		for(int i=0;i<s.size();i++){
			if(s[i]=='{')
				st.push(1);
			if(s[i]=='}'){
				if(st.empty()){
					st1.push(1);
				}
				else st.pop();
			}
		}
		count=ceil(st.size()/2.0)+ceil(st1.size()/2.0);
		cout<<value++<<". "<<count<<endl;
	}
	return 0;
}