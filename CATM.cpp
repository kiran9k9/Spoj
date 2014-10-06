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
int main(){
    int a,b,c,d,e,f,n,m,test;
    scanf("%d%d%d",&n,&m,&test);
    while(test--){
        scanf("%d%d%d%d%d%d",&a,&b,&c,&d,&e,&f);
        if(a==1 or a==n or b==1 or b==m)
            cout<<"YES\n";
        else if((a>c and e>a and b>d and f>b and a-c==b-d and e-a==f-b)or(a>e and c>a and b>f and d>b and a-e==b-f and c-a==d-b))
            cout<<"NO\n";
        else if((a>c and e>a and b<d and f<b and a-c==d-b and e-a==b-f)or(a>e and c>a and b<f and d<b and a-e==f-b and c-a==b-d))
            cout<<"NO\n";
        else cout<<"YES\n";
    }
    return 0;
}
