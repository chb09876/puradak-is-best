/*간단한 문제해석을 써보자면 일과마치고 집돌아오니까 일곱난쟁이가 있어야되는데 아홉난쟁이가 있어서 그중에 리얼 난쟁이를 찾아내고 그에 대한 힌트는 모두 키를 합치면 100되고 오름차순으로 출력하라는 내용이다. 
그러고 정답이 여러개가 나온다면 아무거나 랜덤으로 하라니까 복수 정답일 경우는 생각을 따로 안해도 될것 같다.*/
#include <stdio.h>
#define SWAP(x, y, t) ( (t) = (x), (x) = (y), (y) = (t) )

int main()
{
	int height[9]; //가짜 난쟁이 2명이 있어
	int sum = 0; //전체 합을 다루는 변수
	int over_check; //초과 양을 다루는 변수
	int non_dwarf1 = 0, non_dwarf2 = 0; //난쟁이가 아닌 것을 찾기위한 변수
	int x, tmp; //x는 리얼 난쟁이 찾기위해! tmp는 스왑!
	int real_height[7]; //이제 진짜 7난쟁이를 찾아봐야지~
	
	for(int i = 0; i < 9; i++)
	{
		scanf("%d", &height[i]);
		sum = sum + height[i];
	}

	over_check = sum - 100;	//100초과하냐 안하냐 확인

	//난쟁이 아닌 놈 찾아 내기!
	for(int i = 0; i < 9; i++)
	{
		for(int j = i + 1; j < 9; j++)
		{
			if((height[i] + height[j]) == over_check)
			{
				non_dwarf1 = i;
				non_dwarf2 = j;
				break;
			}
		}
	}

	//본격적으로 7난쟁이들을 찾아볼까?
	for(int i = 0; i < 9; i++)
	{
		if(i != non_dwarf1 && i != non_dwarf2)
		{
			real_height[x] = height[i];
			x++;
		}
	}

	//리스트를 이용해서 오름차순 정렬
	for(int i = 0; i < 7; i++)
	{
		for(int j = i + 1; j < 7; j++)
		{
			if(real_height[i] > real_height[j])
				SWAP(real_height[i], real_height[j], tmp);
		}
	}

	for(int i = 0; i < 7; i++)
		printf("%d\n", real_height[i]);
	return 0;
}