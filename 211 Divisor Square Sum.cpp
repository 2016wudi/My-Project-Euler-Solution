#include <cmath>
#include <cstdio>
#include <cstdlib>
typedef __int128 ll;
const int Maxn=64000000;
bool np[Maxn+5];
int p[Maxn+5],p_len;
ll f[Maxn+5];
void write(ll x){
	if(x<10){
		putchar(x+'0');
		return;
	}
	write(x/10);
	putchar(x%10+'0');
}
void init(){
	np[0]=np[1]=1;
	f[1]=1;
	for(int i=2;i<=Maxn;i++){
		if(!np[i]){
			p[++p_len]=i;
			f[i]=1ll*i*i+1;
		}
		for(int j=1,x;(x=i*p[j])<=Maxn&&j<=p_len;j++){
			np[x]=1;
			if(i%p[j]==0){
				int num=x;
				int k=0;
				ll sum=0,tmp=1;
				while(num%p[j]==0){
					num/=p[j];
					k++;
					sum+=tmp*tmp;
					tmp*=p[j];
				}
				sum+=tmp*tmp;
				if(num!=1){
					f[x]=f[num]*f[x/num];
				}
				else{
					f[x]=sum;
				}
				break;
			}
			f[x]=f[i]*f[p[j]];
		}
	}
}
bool check(ll x){
	ll tmp=sqrt(x);
	return tmp*tmp==x;
}
int main(){
	freopen("output.txt","w",stdout);
	init();
	long long ans=0;
	for(int i=1;i<Maxn;i++){
		if(check(f[i])){
			ans+=i;
		}
	}
	printf("%lld\n",ans);
	return 0;
}

