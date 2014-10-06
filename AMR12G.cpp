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
    int test,n,m,k;
    scanf("%d",&test);
    while(test--){
        vector<pair<int,int> >v;
        scanf("%d%d%d",&n,&m,&k);
        char a[n][m];
        for(int i=0;i<n;i++){
            getchar();
            for(int j=0;j<m;j++)
                scanf("%c",&a[i][j]);
        }
        for(int i=0;i<n;i++){
            int on=0;
            for(int j=0;j<m;j++){
                if(a[i][j]=='*')
                    on++;
            }
            v.pb(mp(m-on,on));
        }
        sort(v.rbegin(),v.rend());
        for(int i=0;i<v.size();i++){
            if(v[i].first>=v[i].second and k!=0){
                int x=v[i].first;
                v[i].first=v[i].second;
                v[i].second=x;
                k--;
            }
        }

        sort(v.rbegin(),v.rend());


        if(k!=0 and k%2!=0){
            int x=v[0].first;
            v[0].first=v[0].second;
            v[0].second=x;
        }
        int ans=0;
        for(int i=0;i<v.size();i++)
            ans+=v[i].second;
        printf("%d\n",ans);
    }

    return 0;
}
