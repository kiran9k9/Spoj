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

using namespace std;
int visited[1000010];
int level[1000010];
int main()
{
	memset(visited,0,sizeof visited);
	memset(level,0,sizeof level);
	queue<int> q;
	int num,start,up,down,goal;
	cin>>num>>start>>goal>>up>>down;
	q.push(start);
	visited[start]=1;
	level[start]=0;
	while(!q.empty()){
		int now=q.front();
		if(now==goal){
			cout<<level[goal]<<endl;
			scanf("\n");
			return 0;
		}
		q.pop();
		if(now+up<=num and !visited[now+up]){
			visited[now+up]=1;
			q.push(now+up);
			level[now+up]=level[now]+1;
		}
		if(now-down>0 and !visited[now-down]){
			q.push(now-down);
			visited[now-down]=1;
			level[now-down]=level[now]+1;
		}
	}
	cout<<"use the stairs\n";
	scanf("\n");
	return 0;
}
		
