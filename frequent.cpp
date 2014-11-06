#include <bits/stdc++.h>
#define ll long long
#define sec second
#define fir first
#define pb push_back
#define mp make_pair
#define Max 100010
using namespace std;
int a[100010];
struct Tree{
	int maxcount,countl,countr;
};
Tree tree[5*Max];
void build(int lo,int hi,int i){
	if(lo==hi){
		tree[i].countl=tree[i].countr=tree[i].maxcount=1;
		return ;
	}
	int mid=(lo+hi)/2;
	int lc=2*i;
	int rc=lc+1;
	build(lo,mid,lc);
	build(mid+1,hi,rc);
	if(a[mid]==a[mid+1]){
		tree[i].countl=tree[lc].countl;
		if(a[lo]==a[mid])
			tree[i].countl+=tree[rc].countl;
		tree[i].countr=tree[rc].countr;
		if(a[mid+1]==a[hi])
			tree[i].countr+=tree[lc].countr;
		tree[i].maxcount=max(tree[lc].maxcount,max(tree[rc].maxcount,tree[lc].countr+tree[rc].countl));
	}
	else{
		tree[i].countl=tree[lc].countl;
		tree[i].countr=tree[rc].countr;
		tree[i].maxcount=max(tree[lc].maxcount,tree[rc].maxcount);
	}
//	cout<<i<<" "<<lo<<" "<<hi<<" "	<<tree[i].countl<<" "<<tree[i].countr<<" "<<tree[i].maxcount<<endl;
	return ;
}
int query(int lo,int hi , int i,int quer_lo,int quer_hi){
//	cout<<lo<<" "<<hi<<" "<<endl;
	if(lo>=quer_lo and hi<=quer_hi){
		return tree[i].maxcount;
	}
	if(lo>quer_hi or hi<quer_lo)
		return 0;
	int mid=(lo+hi)/2;
	int lc=2*i;
	int rc=2*i+1,ans=0;
	int leftans=query(lo,mid,lc,quer_lo,quer_hi);
	int rightans=query(mid+1,hi,rc,quer_lo,quer_hi);
	if(a[mid]==a[mid+1]){
		int temp=min(tree[lc].countr,mid-quer_lo+1)+min(tree[rc].countl,quer_hi-mid);
		ans=max(temp,max(leftans,rightans));
	}
	else ans=max(leftans,rightans);
//	cout<<lo<<" "<<hi<<" "<<ans<<endl;
	return ans;
}
int main(){
	while(1){
		memset(tree,0,sizeof tree);
		memset(a,0,sizeof a);
		int n,m,x,y;
		scanf("%d",&n);
		if(n==0)
			break;
		scanf("%d",&m);
		for(int i=1;i<=n;i++)
			scanf("%d",&a[i]);
		build(1,n,1);
		for(int i=0;i<m;i++){
			scanf("%d%d",&x,&y);
			printf("%d\n",query(1,n,1,x,y));
		}
		//for(int i=1;i<26;i++)
	//		cout<<tree[i].lval<<" "<<tree[i].rval<<" "<<tree[i].countl<<" "<<tree[i].countr<<" "<<tree[i].maxcount<<endl;
	}
	return 0;
}