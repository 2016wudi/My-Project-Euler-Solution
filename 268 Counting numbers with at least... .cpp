#include <cstdio>
#include <cstdlib>
template<typename Elem>
void write(Elem a){
	if(a<10){
		putchar(a+'0');
		return;
	}
	write(a/10);
	putchar(a%10+'0');
}
typedef long long ll;
const int Maxn=100;
ll n;
bool np[Maxn+5];
ll p[Maxn+5],p_len;
ll C[30][30];
ll num[Maxn+5];
bool out[(1<<25)|5];
ll val[(1<<25)|5];
int sum[(1<<25)|5];
void init(){
	np[0]=np[1]=1;
	for(int i=2;i<=Maxn;i++){
		if(!np[i]){
			p[++p_len]=i;
			for(int j=i*i;j<=Maxn;j+=i){
				np[j]=1;
			}
		}
	}
	val[0]=1;
	sum[0]=0;
	for(int i=1;i<=p_len;i++){
		val[1<<(i-1)]=p[i];
	}
	for(int i=1;i<(1<<p_len);i++){
		sum[i]=sum[i-(i&(-i))]+1;
		if(val[i]){
			continue;
		}
		if(out[i-(i&(-i))]){
			out[i]=1;
			continue;
		}
		val[i]=val[i-(i&(-i))]*val[i&(-i)];
		if(val[i]>10000000000000000ll){
			out[i]=1;
		}
	}
	C[0][0]=1;
	for(int i=1;i<30;i++){
		C[i][0]=C[i][i]=1;
		for(int j=1;j<i;j++){
			C[i][j]=C[i-1][j]+C[i-1][j-1];
		}
	}
	num[4]=1;
	for(int i=5;i<=p_len;i++){
		num[i]=1;
		for(int j=i-1;j>=4;j--){
			num[i]-=C[i][j]*num[j];
		}
	}
}
int main(){
	freopen("output.txt","w",stdout);
	init();
	scanf("%lld",&n);
	ll ans=0;
	for(int i=0;i<(1<<p_len);i++){
		if(sum[i]<4||out[i]){
			continue;
		}
		ans+=(n/val[i])*num[sum[i]];
	}
	write(ans);
	return 0;
}

