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

// My Terms
#define pb push_back
#define mp make_pair
#define ins insert
#define fir first
#define sec second
#define PRINT(x)        cout << #x << " " << x << endl
#define pi acos(-1)
#define ll long long
#define EM empty()
#define sz(a) int((a).size())
#define all(c) (c).begin(),(c).end()
#define fill(a,v)     memset(a, v, sizeof(a))
using namespace std;


int main(){
	int a,b,c;
	while(1){
		cin>>a>>b>>c;
		if(a==0 and b==0 and c==0)
			return 0;
		if(b-a==c-b){
			cout<<"AP ";
			cout<<(2*c-b)<<endl;
		}
		else{
			cout<<"GP ";
			cout<<c*c/b<<endl;
		}
	}
	return 0;
}




