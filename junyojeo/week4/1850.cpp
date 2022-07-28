#include <bits/stdc++.h>
using namespace std;

long long gcd(long long A, long long B)
{
	if (B == 0)
		return (A);
	return (gcd(B, A % B));
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	long long A, B, ans;
	cin >> A >> B;
	ans = gcd(A, B);
	for (int i = 0; i < ans; i++)
		cout << 1;
	return (0);
}