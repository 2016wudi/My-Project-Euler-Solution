#include <cstdio>
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
const int Maxn=20000000;
const int Mod=1000000007;
const int inv_2=(Mod+1)>>1;
int n,k;
bool np[Maxn+5];
int p[Maxn+5],p_len;
int val[Maxn+5];
int f[Maxn+5];
void init(){
	np[0]=np[1]=1;
	val[1]=1;
	for(int i=2;i<n;i++){
		if(!np[i]){
			p[++p_len]=i;
			val[i]=p_len;
		}
		for(int j=1,x;(x=i*p[j])<n;j++){
			np[x]=1;
			val[x]=j;
			if(i%p[j]==0){
				break;
			}
		}
	}
	for(int i=2;i<n;i++){
		if(val[i]==1){
			val[i]=0;
		}
	}
	for(int i=1;i<n;i++){
		f[val[i]]++;
	}
}
void FWT_xor(int *a,int flag,int len){
	for(int i=1;i<len;i<<=1){
		for(int j=0;j<len;j+=(i<<1)){
			for(int k=0;k<i;k++){
				int Nx=a[j+k],Ny=a[i+j+k];
				a[j+k]=(Nx+Ny)%Mod;
				a[i+j+k]=(Nx-Ny+Mod)%Mod;
				if(flag==-1){
					a[j+k]=1ll*a[j+k]*inv_2%Mod;
					a[i+j+k]=1ll*a[i+j+k]*inv_2%Mod;
				}
			}
		}
	}
}
int main(){
	freopen("output.txt","w",stdout);
	scanf("%d%d",&n,&k);
	init();
	int len=1;
	while(len<=p_len){
		len<<=1;
	}
	FWT_xor(f,1,len);
	for(int i=0;i<len;i++){
		f[i]=quick_power(f[i],k,Mod);
	}
	FWT_xor(f,-1,len);
	printf("%d\n",f[0]);
	return 0;
}

