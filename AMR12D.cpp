#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;
int main(){
	int test;
	cin>>test;
	string s;

	while(test--){
		int flag=0;
		cin>>s;
		for(int i=0;i<s.size();i++){
			for(int j=1;j<s.size()-i;j++){
				if(s.substr(i,j)==reverse(s.substr(i,j)))
					continue;
				
				else{
					cout<<"No\n";
					flag=1;
					break;
				}
			}
		}
			
	}
	return 0;
}