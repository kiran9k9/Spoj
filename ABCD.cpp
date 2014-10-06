#include <iostream>
#include <cstdio>
using namespace std;
int main(){
	int n,count[4];
	for(int i=0;i<4;i++)
		count[i]=0;
	string s,ans;
	cin>>n;
	cin>>s;
	int a,b,c,d;
	for(int i=0;i<s.size();i+=2){
		a=0,b=0,c=0,d=0;
		for(int j=i;j<i+2;j++){
			if(s[j]=='A')
				a=1;
			if(s[j]=='B')
				b=1;
			if(s[j]=='C')
				c=1;
			if(s[j]=='D')
				d=1;
		}
		for(int j=i;j<i+2;j++){
			if(i==0){
				if(a==0)
					ans+='A',a=1;
				if(b==0)
					ans+='B',b=1;
				if(c==0)
					ans+='C',c=1;
				if(d==0)
					ans+='D',d=1;
			}
			else{
				//cout<<a<<" "<<b<<" "<<c<<" "<<d<<" "<<j<<endl;
				if(a==0 and ans[j-1]!='A')
					ans+='A',a=1;
				if(b==0 and ans[j-1]!='B')
					ans+='B',b=1;
				if(c==0 and ans[j-1]!='C')
					ans+='C',c=1;
				if(d==0 and ans[j-1]!='D')
					ans+='D',d=1;
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}