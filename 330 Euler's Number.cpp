#include <cstdio>
#include <iostream>
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
const int Mod=77777777;
const int Maxn=20000;
int a[10],m[10]={0,7,11,73,101,137};
//int len=1;
int len=5;
int C[Maxn+5][Maxn+5];
int frac[Maxn+5];
void init(int n,int Mod){
	C[0][0]=1;
	for(int i=1;i<=n;i++){
		C[i][0]=C[i][i]=1;
		for(int j=1;j<i;j++){
			C[i][j]=(C[i-1][j-1]+C[i-1][j])%Mod;
		}
	}
	frac[0]=1;
	for(int i=1;i<=n;i++){
		frac[i]=1ll*frac[i-1]*i%Mod;
	}
}
int D[Maxn+5];
int work(int n,int Mod){
	init(Mod*(Mod-1)+Mod,Mod);
	D[0]=1;
	for(int i=1;i<=Mod*(Mod-1)+Mod;i++){
		D[i]=frac[i];
		for(int j=1;j<=i;j++){
			D[i]=(D[i]+1ll*C[i][j]*D[i-j])%Mod;
		}
	}
	if(n<Mod){
		return D[n];
	}
	n-=Mod;
	n%=Mod*(Mod-1);
	return D[n+Mod];
}
int merge(){
	int ans=0;
	for(int i=1;i<=len;i++){
		int tmp_m=Mod/m[i];
		int x=quick_power(tmp_m,m[i]-2,m[i]);
		ans=(ans+1ll*a[i]*tmp_m%Mod*x)%Mod;
	}
	return ans;
}
int main(){
	freopen("output.txt","w",stdout);
	int n;
	scanf("%d",&n);
	/*D[0]=1;
	init(n,Mod);
	for(int i=1;i<=n;i++){
		D[i]=frac[i];
		for(int j=1;j<=i;j++){
			D[i]=(D[i]+1ll*C[i][j]*D[i-j])%Mod;
		}
	}
	int ans=D[n];
	int sum=ans;
	ans=Mod-(ans<<1)%Mod;
	int tmp=1;
	for(int i=1;i<=n;i++){
		tmp=1ll*tmp*i%Mod;
	}
	ans=(ans+tmp)%Mod;
	printf("%d %d\n",sum,ans);*/
	for(int i=1;i<=len;i++){
		a[i]=work(n,m[i]);
	}
	int ans=merge();
	int sum=ans;
	ans=Mod-(ans<<1)%Mod;
	int tmp=1;
	for(int i=1;i<=n;i++){
		tmp=1ll*tmp*i%Mod;
	}
	ans=(ans+tmp)%Mod;
//	printf("%d %d\n",sum,ans);
	printf("%d\n",(sum+ans)%Mod);
	return 0;
}

