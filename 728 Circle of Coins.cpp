/*
#include <cstdio>
#include <cstring>
const int Mod=1000000007;
int a[30];
void init(){
	memset(a,0,sizeof a);
}
void add(int x){
	for(int i=29;i>=0;i--){
		if((x>>i)&1){
			if(a[i]){
				x^=a[i];
			}
			else{
				a[i]=x;
				return;
			}
		}
	}
}
int calc(){
	int num=0;
	for(int i=0;i<30;i++){
		if(a[i]){
			num++;
		}
	}
	return (1<<num);
}
int work(int n,int k){
	init();
	for(int i=0;i<n;i++){
		int tmp=0;
		for(int j=0;j<k;j++){
			tmp^=(1<<((i+j)%n));
		}
		add(tmp);
	}
	return calc();
}
int main(){
	freopen("output.txt","w",stdout);
	int n;
	scanf("%d",&n);
	int ans=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=i;j++){
			ans=(ans+work(i,j))%Mod;
			printf("%7d ",work(i,j));
		}
		puts("");
	}
	puts("");
	printf("%d\n",ans);
	return 0;
}
*/
/*
#include <cstdio>
int gcd(int a,int b){
	if(b==0){
		return a;
	}
	return gcd(b,a%b);
}
const int Mod=1000000007;
const int Maxn=10000000;
const int inv_2=(Mod+1)>>1;
int pow_2[Maxn+5];
int n;
void init(){
	pow_2[0]=1;
	for(int i=1;i<=n;i++){
		pow_2[i]=(pow_2[i-1]<<1)%Mod;
	}
}
int main(){
	freopen("output.txt","w",stdout);
	scanf("%d",&n);
	init();
	int ans=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=i;j++){
			if((j/gcd(i,j))&1){
				ans=(ans+pow_2[i-gcd(i,j)+1])%Mod;
			}
			else{
				ans=(ans+pow_2[i-gcd(i,j)])%Mod;
			}
		}
	}
	printf("%d\n",ans);
	return 0;
}
*/
#include <cstdio>
int gcd(int a,int b){
	if(b==0){
		return a;
	}
	return gcd(b,a%b);
}
const int Maxn=10000000;
const int Mod=1000000007;
const int inv_2=(Mod+1)>>1;
int pow_2[Maxn+5],pow_inv_2[Maxn+5];
bool np[Maxn+5];
int p[Maxn+5],p_len,mu[Maxn+5];
int f_1[Maxn+5],f_2[Maxn+5],f_3[Maxn+5],f_4[Maxn+5];
int n;
void init(){
	np[0]=np[1]=1;
	mu[1]=1;
	for(int i=2;i<=n;i++){
		if(!np[i]){
			p[++p_len]=i;
			mu[i]=Mod-1;
		}
		for(int j=1,x;(x=i*p[j])<=n;j++){
			np[x]=1;
			if(i%p[j]==0){
				mu[x]=0;
				break;
			}
			mu[x]=Mod-mu[i];
		}
	}
	pow_2[0]=1;
	for(int i=1;i<=n;i++){
		pow_2[i]=(pow_2[i-1]<<1)%Mod;
	}
	pow_inv_2[0]=1;
	for(int i=1;i<=n;i++){
		pow_inv_2[i]=1ll*pow_inv_2[i-1]*inv_2%Mod;
	}
	for(int T=1;T<=n;T++){
		for(int i=1;i<=n/T;i++){
			f_1[T]=(f_1[T]+1ll*pow_2[i*T]*i)%Mod;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j+=i){
			f_2[j]=(f_2[j]+1ll*pow_inv_2[i]*mu[j/i])%Mod;
		}
	}
	for(int T=1;T<=n;T++){
		for(int i=1;i<=n/T;i++){
			f_3[T]=(f_3[T]+1ll*pow_2[i*T]*((i+1)>>1))%Mod;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j+=i){
			if(!((j/i)&1)){
				continue;
			}
			f_4[j]=(f_4[j]+1ll*pow_inv_2[i]*mu[j/i])%Mod;
		}
	}
}
int work_1(){
	int ans=0;
	for(int i=1;i<=n;i++){
		ans=(ans+1ll*f_2[i]*f_1[i])%Mod;
	}
	return ans;
}
int work_2(){
	int ans=0;
	for(int i=1;i<=n;i++){
		ans=(ans+1ll*f_4[i]*f_3[i])%Mod;
	}
	return ans;
}
int main(){
	freopen("output.txt","w",stdout);
	scanf("%d",&n);
	init();
	printf("%d\n",(work_1()+work_2())%Mod);
	return 0;
}

