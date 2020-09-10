#include <cstdio>
const int Maxn=100000000;
int n;
double f_1[Maxn+5],f_2[Maxn+5];
int main(){
	freopen("1.out","w",stdout);
	scanf("%d",&n);
	double ans=0.0;
	/*for(int i=1;i<=n;i++){
		f_1[i]=f_1[i-1]+1.0*n/i;
		f_2[i]=f_2[i-1]+2.0*(i-1)/(n-i+1)*f_1[i]+2*f_1[i-1]+1.0*n/(n-i+1);
	}*/
	for(int i=1;i<=n;i++){
		f_1[i]=f_1[i-1]+1.0/i;
	}
	for(int i=1;i<=n;i++){
		ans+=f_1[i]/i;
	}
	ans*=n;
	printf("%.10lf\n",ans);
	return 0;
}

