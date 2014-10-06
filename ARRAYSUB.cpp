#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<cstdio>
#include<ctime>
#include<cctype>
#include<cassert>
#include<climits>
#include<cerrno>
#include<cfloat>
#include<ciso646>
#include<clocale>
#include<csetjmp>
#include<csignal>
#include<cstdarg>
#include<cstddef>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<ctime>
#include<cwchar>
#include<cwctype>

//containers
#include<vector>
#include<list>
#include<map>
#include<queue>
#include<deque>
#include<set>
#include<complex>
#include<string>
#include<stack>
#include<bitset>
#include<istream>
#include<valarray>

//IOs
#include<iostream>
#include<sstream>
#include<iomanip>
#include<fstream>
#include<exception>
#include<ios>
#include<iosfwd>
#include<ostream>
#include<iterator>
#include<stdexcept>
#include<streambuf>


//algorithm & miscellaneous
#include<algorithm>
#include<functional>
#include<numeric>
#include<utility>
#include<limits>
#include<locale>
#include<memory>
#include<new>
#define pb push_back
#define mp make_pair
#define ll long long
#define ull unsigned long long
using namespace std;
template<class T1> void deb(T1 e1){cout<<e1<<"\n";}
template<class T1,class T2> void deb(T1 e1,T2 e2){cout<<e1<<" "<<e2<<"\n";}
template<class T1,class T2,class T3> void deb(T1 e1,T2 e2,T3 e3){cout<<e1<<" "<<e2<<" "<<e3<<"\n";}
template<class T1,class T2,class T3,class T4> void deb(T1 e1,T2 e2,T3 e3,T4 e4){cout<<e1<<" "<<e2<<" "<<e3<<" "<<e4<<"\n";}
template<class T1,class T2,class T3,class T4,class T5> void deb(T1 e1,T2 e2,T3 e3,T4 e4,T5 e5){cout<<e1<<" "<<e2<<" "<<e3<<" "<<e4<<" "<<e5<<"\n";}
template<class T1,class T2,class T3,class T4,class T5,class T6>
void deb(T1 e1,T2 e2,T3 e3,T4 e4,T5 e5,T6 e6){cout<<e1<<" "<<e2<<" "<<e3<<" "<<e4<<" "<<e5<<" "<<e6<<"\n";}

int tree[2020020],a[1000020];
void build(int lo,int hi,int i){
	if(lo==hi){
		tree[i]=a[lo];
		return;
	}
	int mid=(lo+hi)/2;
	build(lo,mid,2*i);
	build(mid+1,hi,2*i+1);
	tree[i]=max(tree[2*i],tree[2*i+1]);
	return;
}
void display(int node,int tl,int tr)
{
	deb(node,tl,tr,tree[node],tree[node]);
	if(tl==tr)
		return;
	int tm = (tl+tr)>>1;
	int cl = node<<1;
	int cr = cl|1;
	display(cl,tl,tm);
	display(cr,tm+1,tr);
}
int query(int lo,int hi,int i,int ind1,int ind2){
	if(ind1>hi || ind2<lo)
		return INT_MIN;
	if(lo>=ind1 and hi<=ind2)
		return tree[i];
	int mid=(lo+hi)/2;
	return max(query(lo,mid,2*i,ind1,ind2),
	query(mid+1,hi,2*i+1,ind1,ind2));
}
int main(){
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	build(1,n,1);
//	display(1,1,n);
	int k;
	scanf("%d",&k);
	for(int i=1;i<=n-k+1;i++)
		printf("%d\n",query(1,n,1,i,i+k-1));
	return 0;
}
