#include <stdio.h>
#define ll long long int//long long으로 하면 틀림
//gcd(a, b) == |ab| / lcm(a, b)  => lcm(a, b) * gcd(a, b) == |ab|
//lcm(a, b) == |ab| / gcd(a, b). 

ll gcd(ll A, ll B)
{
	if (B == 0)
		return (A);
	return (gcd(B, A % B));
}

int main(void)
{
	ll A, B, ans;
	scanf("%lld %lld", &A, &B);
	ans = gcd(A, B);
	printf("%lld", (A * B) / ans);
	return (0);
}