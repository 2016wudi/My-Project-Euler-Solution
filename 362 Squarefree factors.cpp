#include <map>
#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;
const int Maxn=100000;
ll n;
bool np[Maxn+5];
int mu[Maxn+5],p[Maxn+5],p_len;
int a[Maxn+5],len;
void init(){
	np[0]=np[1]=1;
	mu[1]=1;
	for(int i=2;i<=Maxn;i++){
		if(!np[i]){
			p[++p_len]=i;
			mu[i]=-1;
		}
		for(int j=1,x;(x=i*p[j])<=Maxn;j++){
			np[x]=1;
			if(i%p[j]==0){
				mu[x]=0;
				break;
			}
			mu[x]=-mu[i];
		}
	}
	for(int i=2;i<=Maxn;i++){
		if(mu[i]){
			a[++len]=i;
		}
	}
}
map<ll,ll> g;
ll find_num(ll x){
	if(g.count(x)>0){
		return g[x];
	}
	ll ans=0;
	for(int i=1;1ll*i*i<=x;i++){
		ans+=1ll*mu[i]*(x/(1ll*i*i));
	}
	return g[x]=ans;
}
map<pair<int,ll>,ll> f;
ll dfs(int x,ll n){
	pair<int,ll> u=make_pair(x,n);
	if(f.count(u)>0){
		return f[u];
	}
	if(x>len||1ll*a[x]*a[x]>n){
		return find_num(n)-x;
	}
	return f[u]=dfs(x+1,n)+dfs(x,n/a[x])+1;
}
int main(){
	init();
	ll ans=0,n;
	scanf("%lld",&n);
	ans=dfs(1,n);
	freopen("output.txt","w",stdout);
	printf("%lld\n",ans);
	return 0;
}

