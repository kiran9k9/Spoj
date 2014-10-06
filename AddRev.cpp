#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
	int t,n,m;
	cin>>t;
	while(t--)
	{
		int x=0,y=0;
		cin>>n>>m;
		while(n!=0)
		{
			int i=n%10;
			n/=10;
			x=x*10+i;
		}
		while(m!=0)
		{
			int j=m%10;
			m/=10;
			y=y*10+j;
		}
		x=x+y;
		y=0;
		while(x!=0)
		{
			int i=x%10;
			x/=10;
			y=y*10+i;
		}
		cout<<y<<endl;
	}
	cin>>n;
	return 0;
}
	
