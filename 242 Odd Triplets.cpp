#include <cstdio>
typedef long long ll;
ll n=1000000000000ll;
ll f[65][2];
int main(){
	freopen("output.txt","w",stdout);
//	scanf("%lld",&n);
	if(!(n&1)){
		n--;
	}
	f[61][1]=1;
	for(int i=60;i>=2;i--){
		f[i][0]=(f[i+1][0]*3);
		if((n>>i)&1){
			f[i][0]+=f[i+1][1];
			f[i][1]=f[i+1][1]*2;
		}
		else{
			f[i][1]=f[i+1][1];
		}
	}
	printf("%lld\n",f[2][0]+f[2][1]);
	return 0;
}

