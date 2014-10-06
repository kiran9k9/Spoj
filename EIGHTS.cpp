#include<iostream>
#include<cstdio>
using namespace std;
int main(){
int n;
cin>>n;
int a[n];
for(int i=1;i<=5;i++)
	cin>>a[i];
for(int i=1;i<=n-1;i++){
	int flag=0;
	for(int j=1;j<=n-i+1;j++){
		if(a[j]>a[j+1]){
			swap(a[j],a[j+1]);
			flag=1;
		}
		if(flag==0)
			return 0;
	}
}


for(int i=1;i<=n;i++)
	cout<<a[i]<<" ";
return 0;
}