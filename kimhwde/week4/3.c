#include <stdio.h>
#include <stdbool.h>

int		ft_is_prime(int nb)//소수 판단
{
	int i;

	i = 2;
	if (nb <= 1)
		return 0;
	while (i <= nb / i)
	{
		if (nb % i == 0)
			return (0);
		else
		{
			i++;
		}	
	}
	return 1 ;
}




int main(void)
{
    int n;
    int num;
 
    scanf("%d", &n);
    
    for (int i = 0; i < n; ++i)//n의 횟수만큼 반복
    {
        scanf("%d", &num);
        while(!(ft_is_prime(num)))//num을 입력받은 후 소수 판별함
        {
            num++;
        }
        printf("%d",num);
    }
    return 0;
    
}