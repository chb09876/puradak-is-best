#include <stdio.h>
#define ll long long
//gcd(a, b) == |ab| / lcm(a, b)  => lcm(a, b) * gcd(a, b) == |ab|
//lcm(a, b) == |ab| / gcd(a, b). 

ll gcd(ll A, ll B)
{
	if (B == 0)
		return (A);
	else
		return (gcd(B, A % B));
}

int main(void)
{
	ll int A, B, ans;
	scanf("%lld %lld", &A, &B);
	ans = gcd(A, B);
	for (int i = 0; i < ans; i++)
		printf("%lld", (A * B) / ans);
	return (0);
}