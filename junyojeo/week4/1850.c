#include <stdio.h>

long long gcd(long long A, long long B)
{
	if (B == 0)
		return (A);
	else
		return (gcd(B, A % B));
}

int main(void)
{
	long long A, B, ans;
	scanf("%lld %lld", &A, &B);
	ans = gcd(A, B);
	for (int i = 0; i < ans; i++)
		printf("1");
	return (0);
}