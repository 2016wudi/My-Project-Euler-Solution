
#include <cstdio>
const int Maxn=100000000;
typedef long long ll;
int num[Maxn+5];
int sz[Maxn+5];
int n,k;
void work(){
	for(int i=0;i<=n;i++){
		sz[i]=num[i]=0;
	}
	for(int i=1;i*i<=n;i++){
		if(i&1){
			for(int j=1;j<i;j+=2){
				num[(5*i*i-j*j)/4]++;
			}
		}
		else{
			for(int j=0;j<i;j+=2){
				num[(5*i*i-j*j)/4]++;
			}
		}
	}
	int ans=0;
	for(int i=0;i<=n;i++){
		sz[num[i]]++;
	}
	for(int i=1;i<=100;i++){
		printf("%d ",sz[i]);
	}
	puts("");
}
int main(){
	freopen("output.txt","w",stdout);
	scanf("%d",&n);
	work();
	return 0;
}

/*#include <stdio.h>
#include <string.h>

#define EXCLUDE_A_EQUAL_B
//#define N 100000
//#define K 3
#define N 1000000000000000LL
#define K 40
//#define N 100000000
//#define K 6
#define NSQRT 31622776

static char primes[NSQRT+1];
static int count1[NSQRT+1]; // product of 5, 5k+2, 5k+3

int isprime(long long n)
{
	int p;
	for (p = 2; (long long)p*p <= n; p++) if (primes[p])
		if (n % p == 0)
			return 0;
	return 1;
}

int isqrt(long long x) {
	long long x1, g0, g1;
	int s;

	if (x <= 1) return x;
	s = 1;
	x1 = x - 1;
	if (x1 > 0xFFFFFFFF) {s = s + 16; x1 = x1 >> 32;}
	if (x1 > 0xFFFF)     {s = s + 8; x1 = x1 >> 16;}
	if (x1 > 0xFF)       {s = s + 4; x1 = x1 >> 8;}
	if (x1 > 0xF)        {s = s + 2; x1 = x1 >> 4;}
	if (x1 > 3)          {s = s + 1;}

	g0 = 1 << s;                // g0 = 2**s.
	g1 = (g0 + (x >> s)) >> 1;  // g1 = (g0 + x/g0)/2.

	while (g1 < g0) {           // Do while approximations
		g0 = g1;                 // strictly decrease.
		g1 = (g0 + (x/g0)) >> 1;
	}
	return g0;
}

long long recurse2(int en, int ei, char e[], int p, long long n, int allow5, long long mult)
{
	if (ei == en)
		return (allow5 != 2 ? count1[isqrt(n)] : 0) + (allow5 ? count1[isqrt(n / 5)] : 0);
	int eleft = 0;
	int i;
	for (i = ei + 1; i < en; i++)
		eleft += e[i];
	long long result = 0;
	for (;;) {
		while (p <= NSQRT && (p % 5 != 1 && p % 5 != 4 || !primes[p]))
			p++;
		if (p > NSQRT) {
			printf("internal error\n");
			while (p%5 != 1 && p%5 != 4 || !isprime(p))
				p++;
		}
		long long n2 = n;
		long long mult2 = mult;
		for (i = 0; i < e[ei]; i++) {
			n2 /= p, mult2 *= p;
			if (!n2)
				return result;
		}
		long long n3 = n2;
		for (i = 0; i < eleft; i++)
			n3 /= p + 1;
		if (!n3)
			return result;
		result += recurse2(en, ei + 1, e, p + 1, n2, allow5, mult2);
		p++;
	}
}

long long recurse(int count, int en, char e[], int allow5)
{
	if (count == 1) {
		// p0**e[0] * p1**e[1] * ... * pk**e[en-1] * square(product of 5k+2, 5k+3) * 5**s; pi = 5k+1 or 5k-1
		return recurse2(en, 0, e, 2, N, allow5, 1);
	} else {
		long long result = 0;
		for (e[en] = 1; e[en] < count; e[en]++)
			if (count % (e[en] + 1) == 0)
				result += recurse(count / (e[en] + 1), en + 1, e, allow5);
		return result;
	}
}
int main(){
	freopen("output.txt","w",stdout);
	int i, j;
	memset(primes, 1, sizeof(primes));
	for (i = 2; i*i <= NSQRT; i++) if (primes[i])
		for (j = i*i; j <= NSQRT; j += i) primes[j] = 0;
	count1[0] = 0;
	for (i = 1; i <= NSQRT; i++)
		count1[i] = 1;
	for (i = 11; i <= NSQRT; i += 10) if (primes[i])
		for (j = i; j <= NSQRT; j += i)
			count1[j] = 0;
	for (i = 9; i <= NSQRT; i += 10) if (primes[i])
		for (j = i; j <= NSQRT; j += i)
			count1[j] = 0;
	for (i = 2; i <= NSQRT; i++)
		count1[i] += count1[i - 1];
	char e[10];
	printf("%lld\n", recurse(2*K, 0, e, 1) + recurse(2*K+1, 0, e, 0) + recurse(2*K-1, 0, e, 2));
	return 0;
}
*/
