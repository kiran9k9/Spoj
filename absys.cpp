#include <bits/stdc++.h>
#define ll long long
#define sec second
#define fir first
#define pb push_back
#define mp make_pair
using namespace std;
int main(){
	int test;
	cin>>test;
	string s;
	while(test--){
		scanf("\n");
		//cin>>s;
		getline(cin,s);
		//cout<<s<<endl<<"hell";
		int n[3],mark[3];
		n[0]=n[1]=n[2]=mark[0]=mark[1]=mark[2]=0;
		int flag=0,plus=0,equal=0;
		vector<int>temp;
		for(int i=0;i<s.size();i++){
			if(s[i]==' ')
				continue;
			else temp.pb(s[i]);
		}
		for(int i=0;i<temp.size();i++){
			if(temp[i]=='+'){
				plus=1;
				flag++;
				continue;
			}
			if(temp[i]=='='){
				flag++;
				equal=1;
				continue;
			}


			if(temp[i]=='m'){
				if(plus==0){
					mark[0]=1;
					//flag++;
				}
				if(plus==1 and equal==0){
					mark[1]=1;
					//flag++;
				}
				if(equal==1 and plus==1){
					mark[2]=1;
					//flag++;
				}
				i+=6;
			}
			n[flag]=n[flag]*10+temp[i]-'0';
		}
		if(mark[0]==1){
			cout<<n[2]-n[1]<<" + "<<n[1]<<" = "<<n[2]<<endl;
		}
		if(mark[1]==1){
			cout<<n[0]<<" + "<<n[2]-n[0]<<" = "<<n[2]<<endl;
		}
		if(mark[2]==1){
			cout<<n[0]<<" + "<<n[1]<<" = "<<n[1]+n[0]<<endl;
		}
	}
	return 0;
}	