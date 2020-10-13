#include <cstdio>
typedef long long ll;
const int Maxn=200;
const int Maxm=1000000;
const int Mod=1000000007;
bool np[Maxn+5];
int p[Maxn+5],p_len;
int a[Maxn+5];
int n;
ll m;
void init(){
	np[0]=np[1]=1;
	for(int i=2;i<=n;i++){
		if(!np[i]){
			p[++p_len]=i;
		}
		for(int j=i*i;j<=n;j+=i){
			np[j]=1;
		}
	}
}
int num_id[Maxm<<1|5];
int find_id(ll x){
	if(x<=Maxm){
		return x;
	}
	return m/x+Maxm;
}
int work(ll n){
	int id=find_id(n);
	if(num_id[id]){
		return num_id[id];
	}
	int ans=0;
	for(ll i=1,j;i<=n;i=j+1){
		j=n/(n/i);
		ans=(ans+(j-i+1)%Mod*(n/i))%Mod;
	}
	return num_id[id]=ans;
}
int find_sum(int x){
	return 1ll*(x+1)*(x+2)/2%Mod;
}
int answer;
void dfs(int x,int mu=1,int ans=1,ll num=1){
	if(num>m){
		return;
	}
	if(x>p_len){
		answer=((answer+1ll*mu*ans*work(m/num))%Mod+Mod)%Mod;
		return;
	}
	dfs(x+1,mu,1ll*ans*find_sum(a[x])%Mod,num);
	dfs(x+1,-mu,1ll*ans*find_sum(a[x]-1)%Mod,num*p[x]);
}
int main(){
	freopen("output.txt","w",stdout);
	scanf("%d",&n);
	scanf("%lld",&m);
	init();
	for(int i=1;i<=p_len;i++){
		int tmp=n;
		while(tmp){
			a[i]+=(tmp/=p[i]);
		}
	}
	dfs(1);
	printf("%d\n",answer);
	return 0;
}

