#include <iostream>
using namespace std;

const int MAX = 200000 + 1;

int N, M, V;
int arr[MAX];

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> M >> V;

	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}

	int head = --V;
	int tempLength = N - head;

	for (int i = 0; i < M; i++)
	{
		int K;
		cin >> K;

		if (K < head)
		{
			cout << arr[K] << "\n";
		}
		else
		{
			cout << arr[(K - head) % tempLength + head] << "\n";
		}
	}

	return 0;
}1