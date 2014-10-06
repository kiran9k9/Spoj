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

int a[20020],tree[80080],ans[20020];
void build(int lo,int hi,int i){
    if(lo==hi){
        tree[i]=a[lo];
        return;
    }
    int mid=(lo+hi)/2;
    build(lo,mid,2*i);
    build(mid+1,hi,2*i+1);
    tree[i]=tree[2*i] & tree[2*i+1];
}
int query(int lo,int hi,int i,int quer_lo,int quer_hi){
    int res=0;
    if(quer_lo>hi or quer_hi<lo)
        return INT_MAX;

    if(lo>=quer_lo and hi<=quer_hi)
        return tree[i];
    int mid=(lo+hi)/2;
    return query(lo,mid,2*i,quer_lo,quer_hi) &
    query(mid+1,hi,2*i+1,quer_lo,quer_hi);

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
int main(){
    int test,n,k;
    scanf("%d",&test);
    while(test--){
        memset(ans,0,sizeof ans);
        memset(a,0,sizeof a);
        scanf("%d%d",&n,&k);
        for(int i=1;i<=n;i++)
            scanf("%d",&a[i]);
        build(1,n,1);
       // display(1,1,n);
        if(k>=ceil((double)n/2.0))
            for(int i=1;i<=n;i++){
                ans[i]=tree[1];
            }
        else{
            for(int i=1;i<=n;i++){
                if(i+k>n)
                    ans[i]=query(1,n,1,i,n) & query(1,n,1,1,i+k-n);

                else if(i+k<=n)
                    ans[i]=query(1,n,1,i,i+k);
                if(i-k>=1)
                    ans[i]=ans[i] & query(1,n,1,i-k,i);
                else if(i-k<1)
                    ans[i]=ans[i] & query(1,n,1,1,i)& query(1,n,1,n+i-k,n);

            }
        }
        for(int i=1;i<=n;i++)
            printf("%d ",ans[i]);
        printf("\n");
    }
    return 0;
}
