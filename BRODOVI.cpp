#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int main(){
	int n;
	cin>>n;
	int a[n],count=0,visited[n];
	for(int i=0;i<n;i++)
		visited[i]=0;
	for(int i=0;i<n;i++)
		cin>>a[i];
	for(int i=1;i<n-1;i++){
		int flag=0;
		if(visited[i])
			continue;
		int diff=a[i]-a[0];
		int diff_counter=a[i];
		for(int j=i+1;j<n;j++){
			if(a[j]-diff_counter==diff){
				visited[j]=1;
				diff_counter=a[j];
				continue;
			}
			if(a[j]-diff_counter<diff)
				continue;
			if(a[j]-diff_counter>diff){
				flag=1;
				break;
			}
		}
		if(flag==0){
			count++;
		}
	}
	if(n==2 and count==0)
		count=1;
	cout<<count;
	return 0;
}	