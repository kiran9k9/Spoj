#include <bits/stdc++.h>
#define ll long long
#define mp make_pair
#define pb push_back
#define fir first
#define sec second
#define mod 1000000009
using namespace std;
int main(){
	int test=10;
	while(test--){
		string s,t;
		cin>>s;
		cin>>t;
		int carry=0;
		int chk=s.size()-1;
		for(int i=t.size()-1;i>=0;i--){
			if((s[chk]-'0')-(t[i]-'0')-carry>=0){
				s[chk]=(s[chk]-'0')-(t[i]-'0')+'0';
				chk--;
			}
			else{
				s[chk]=10+(s[chk]-'0')-(t[i]-'0');
				carry=1;
				chk--;
			}
		}
		if(carry){
			s[s.size()-t.size()-1]=(s[s.size()-t.size()-1]-'0'+1)+'0';
		}
		cout<<s<<endl;
		carry=0;
		string r;
		for(int i=0;i<s.size();i++){
			if((s[i]-'0')/2>=2){
				int x=carry*10+(s[i]-'0');
				carry=0;
				r+=((x/2)+'0');
				if(x%2!=0)
					carry=1;
			}
		}
		carry=0;
		string u="";
		for(int i=t.size()-1;i>=0;i--){
			if(carry+(t[i]-'0')+(r[i]-'0')>=10){
				string temp=u;
				u=(((carry+(t[i]-'0')+(r[i]-'0'))%10)+'0');
				u=u+temp;
				carry=1;
			}
			else{
				string temp=u;
				u=(((carry+(t[i]-'0')+(r[i]-'0'))%10)+'0');
				u=u+temp;
				carry=0;
			}
		}
		if(carry)
			u="1"+u;
		cout<<u<<" "<<r<<endl;
	}
	return 0;
}