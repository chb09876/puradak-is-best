#include <stdio.h>


int main() {

	char arr[51][51];
	int n, m;

	scanf("%d %d", &n, &m);

	for(int i=0; i<n;i++)
		scanf("%s", arr[i]);

	int min = n * m;

	for (int a = 0; a + 7 < n; a++) 
    	{
		for (int b = 0; b + 7 < m; b++) 
        	{
			int B_cnt = 0;
			int W_cnt = 0;
			for (int i = a; i < a + 8; i++) 
            		{
				for (int j = b; j < b + 8; j++) 
                		{
                    			if((i+j) %2 ==0)
                    			{
					    if (arr[i][j] == 'B')
                            			W_cnt++;
					    else 
                            			B_cnt++;
                    			}
                   			 else
					 {
					    if (arr[i][j] == 'B')
                            			B_cnt++;
					    else 
                            			W_cnt++;
                   			 }
				}
			}

			int min_cnt = B_cnt;
			if (min_cnt > W_cnt) 
                		min_cnt = W_cnt;			
			if (min > min_cnt) 
				min = min_cnt;
		}
	}	
	
	printf("%d\n", min);
}


