#include <bits/stdc++.h>
#define ll long long
#define mp make_pair
#define pb push_back
#define fir first
#define sec second
#define mod 1000000009
using namespace std;
int main(){
	int test;
	scanf("%d",&test);
	while(test--){
		string s,t;
		cin>>s;
		if(s.size()==1){
			if(s[0]-'0'<9)
				cout<<(char)((s[0]-'0'+1)+'0')<<endl;
			else cout<<"11"<<endl;
			continue;
		}
		t=s;
		int chk=0,len=s.size();
		for(int i=0;i<len/2;i++){
			if(s[i]==s[len-1-i])
				continue;
			else{
					chk=1;
					s[len-1-i]=s[i];
				}
		}
		if(chk==0 or s<t){
			int flag=0;
			for(int i=len/2;i>=0;i--){
				if(s[i]-'0'<9){
					flag=1;
					s[i]=((s[i]-'0')+1)+'0';
					s[len-i-1]=s[i];
					for(int j=i+1;j<=len/2;j++){
						s[j]='0';
						s[len-j-1]='0';
					}
					break;
				}
			}
			if(flag==0){
				cout<<"1";
				for(int i=0;i<s.size()-1;i++)
					cout<<"0";
				cout<<"1"<<endl;
				continue;
			}
		}
		cout<<s<<endl;
	}
	return 0;
}