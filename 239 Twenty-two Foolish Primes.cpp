#include <cstdio>
const int Maxn=100;
const int p[30]={0,2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97};
const int p_len=25;
long double f[30];
long double C[30][30];
long double find_div(int x,int y){
	long double ans=1.0;
	for(int i=x+1;i<=y;i++){
		ans/=i;
	}
	return ans;
}
int main(){
	freopen("output.txt","w",stdout);
	C[0][0]=1.0;
	for(int i=1;i<=25;i++){
		C[i][0]=C[i][i]=1.0;
		for(int j=1;j<i;j++){
			C[i][j]=C[i-1][j-1]+C[i-1][j];
		}
	}
	f[0]=1.0;
	for(int i=1;i<=p_len;i++){
		f[i]=C[p_len][i]*find_div(100-i,100);
	}
	for(int i=p_len-1;i>=0;i--){
		for(int j=i+1;j<=p_len;j++){
			f[i]-=f[j]*C[j][i];
		}
	}
	printf("%.12Lf\n",f[3]);
	return 0;
}

