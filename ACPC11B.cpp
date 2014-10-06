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
    int test;
    scanf("%d",&test);
    while(test--){
        int n,m,mini=INT_MAX;
        scanf("%d",&n);
        int a[n];
        for(int i=0;i<n;i++)
            scanf("%d",&a[i]);
        scanf("%d",&m);
        int b[m];
        for(int i=0;i<m;i++)
            scanf("%d",&b[i]);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                mini=min(mini,abs(a[i]-b[j]));
            }
        }
        printf("%d\n",mini);
    }
    return 0;
}
