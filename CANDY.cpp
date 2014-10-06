#include<iostream>
#include<cstdio>
using namespace std;
int main(){
	int n;
	while(1){
		cin>>n;
		if(n==-1)
			break;
		int a[n];
		long long sum=0;
		for(int i=0;i<n;i++){
			scanf("%d",&a[i]);
			sum+=a[i];
		}
		if(sum%n!=0){
			cout<<-1<<endl;
			continue;
		}
		long long ans=0;
		int avg=sum/n;
		for(int i=0;i<n;i++){
			if(a[i]<avg)
				ans+=avg-a[i];
		}
		cout<<ans<<endl;
	}
	return 0;

}