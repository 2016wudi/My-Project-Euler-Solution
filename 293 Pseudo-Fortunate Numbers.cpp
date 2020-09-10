#include <set>
#include <cstdio>
using namespace std;
int quick_power(int a,int b,int Mod){
	int ans=1;
	while(b){
		if(b&1){
			ans=1ll*ans*a%Mod;
		}
		b>>=1;
		a=1ll*a*a%Mod;
	}
	return ans;
}
typedef long long ll;
const int Maxn=1000000000;
const int P_len=19;
const int p[P_len]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,24251};
bool miller_rabin(ll x,ll b){
	ll d,p=0;
	d=x-1;
	while((d&1)==0){
		d>>=1;
		p++;
	}
	ll cur=quick_power(b,d,x);
	if(cur==1||cur==x-1){
		return 1;
	}
	for(int i=1;i<=p;i++){
		cur=1ll*cur*cur%x;
		if(cur==x-1){
			return 1;
		}
	}
	return 0;
}
bool miller_rabin(ll x){
	if(x==46856248255981||x<2){
		return 0;
	}
	for(int i=0;i<P_len;i++){
		if(x==p[i]){
			return 1;
		}
	}
	for(int i=0;i<P_len;i++){
		if(!miller_rabin(x,p[i])){
			return 0;
		}
	}
	return 1;
}
ll answer;
set<int> st;
void calc(int x){
	for(int i=x+2;;i++){
		if(miller_rabin(1ll*i)){
			st.insert(i-x);
			break;
		}
	}
}
void work_dfs(int pos,int now){
	for(int i=1;1ll*now*p[pos]<=Maxn;i++){
		now*=p[pos];
		calc(now);
		work_dfs(pos+1,now);
	}
}
int main(){
	freopen("output.txt","w",stdout);
	work_dfs(0,1);
	set<int>::iterator it;
	it=st.begin();
	while(it!=st.end()){
		answer+=(*it);
		it++;
	}
	printf("%lld\n",answer);
	return 0;
}

