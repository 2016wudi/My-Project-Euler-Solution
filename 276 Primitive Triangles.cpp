#include <cstdio>
#include <cstdlib>
typedef long long ll;
const int Maxn=10000000;
ll num[Maxn+5];
int p[Maxn+5],p_len;
bool np[Maxn+5];
int mu[Maxn+5];
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
			mu[x]=-mu[i];
			if(i%p[j]==0){
				mu[x]=0;
				break;
			}
		}
	}
}
int main(){
	freopen("output.txt","w",stdout);
	/*for(ll i=1;i<=Maxn;i++){
		if(i&1){
			num[i+1]=(ll)(1ll*(i+3)*(i+3)/48.0+0.5);
		}
		else{
			num[i+1]=(ll)(1ll*i*i/48.0+0.5);
		}
	}*/
	for(int i=3;i<=Maxn;i++){
		int left=(i+2)/3,right=(i+1)/2-1;
		num[i]+=1ll*(left+right)*(right-left+1)/2;
		num[i]+=(right-left+1);
		if((i-left)&1){
			int sum=(right-left+2)/2;
			num[i]-=1ll*((i-left)/2+1+(i-left)/2+1-sum+1)*sum/2;
			sum=right-left+1-sum;
			num[i]-=1ll*((i-1-left)/2+(i-1-left)/2-sum+1)*sum/2;
		}
		else{
			int sum=(right-left+2)/2;
			num[i]-=1ll*((i-left)/2+(i-left)/2-sum+1)*sum/2;
			sum=right-left+1-sum;
			num[i]-=1ll*((i-left)/2+(i-left)/2-sum+1)*sum/2;
		}
	}
	for(int i=1;i<=Maxn;i++){
		num[i]+=num[i-1];
	}
	ll ans=0;
	/*for(int i=1;i<=Maxn;i++){
		for(int j=i;j<=Maxn;j+=i){
			p[j]++;
		}
	}
	for(int i=1;i<=Maxn;i++){
		if(p[i]&1){
			ans+=num[Maxn/i];
		}
		else{
			ans-=num[Maxn/i];
		}
	}*/
	init();
	for(int i=1;i<=Maxn;i++){
		ans+=mu[i]*num[Maxn/i];
	}
	printf("%lld\n",ans);
	return 0;
}

