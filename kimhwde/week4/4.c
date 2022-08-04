#include<stdio.h>
long long int gcd(long long a,long long b) {//최대 공약수를 출력해주는 함수 작은 수인 a와 큰 수인 b가 주어지면 재귀를 통해 나머지가 0이 되는 순간 나눈 수를 출력하고 그 수가 최대 공약수
	if (b == 0)
		return a;
	else
		return gcd(b, a % b);//2번쨰 매개 변수에는 작은 수보다 작은 값들 중 하나가 다음 재귀의 입력값으로 들어감
}
int main() {
    long long a,b;
	scanf("%lld %lld", &a, &b);
	long long answer = gcd(a, b);
	for (int i = 0; i < answer; i++) {//최대공약수의 수만큼 1을 출력한다.
		printf("1");
	}
	
	return 0;

}