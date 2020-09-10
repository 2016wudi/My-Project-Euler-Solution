#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
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
const int Maxn=10000000;
const int Maxm=14000;
const int Mod=1000000007;
bool check(int x){
	int tmp=(int)sqrt(x)*1.0;
	return tmp*tmp==x;
}
vector<pair<int,int> > a;
int f[Maxm+5];
int frac[Maxn<<1|5],inv_f[Maxn<<1|5];
void init(){
	frac[0]=1;
	for(int i=1;i<=(Maxn<<1);i++){
		frac[i]=1ll*frac[i-1]*i%Mod;
	}
	inv_f[Maxn<<1]=quick_power(frac[Maxn<<1],Mod-2,Mod);
	for(int i=(Maxn<<1)-1;i>=0;i--){
		inv_f[i]=1ll*inv_f[i+1]*(i+1)%Mod;
	}
}
int C(int n,int m){
	return 1ll*frac[n]*inv_f[m]%Mod*inv_f[n-m]%Mod;
}
int main(){
	freopen("2.out","w",stdout);
	int n;
	scanf("%d",&n);
	init();
	a.push_back(make_pair(0,0));
	for(int i=1;i*i<=n;i++){
		for(int j=1;j*j<=n;j++){
			if(check(i*i+j*j)){
				a.push_back(make_pair(i*i,j*j));
			}
		}
	}
	a.push_back(make_pair(n,n));
	f[0]=Mod-1;
	for(int i=1;i<(int)a.size();i++){
		for(int j=i-1;j>=0;j--){
			if(a[i].first<a[j].first||a[i].second<a[j].second){
				continue;
			}
			f[i]=(f[i]-1ll*f[j]*C(a[i].first-a[j].first+a[i].second-a[j].second,a[i].second-a[j].second)%Mod+Mod)%Mod;
		}
	}
	printf("%d\n",f[a.size()-1]);
	return 0;
}

