#include <stdio.h>
#include <math.h>
int main(void)
{
	int M, N;
	scanf_s("%d %d", &M, &N);
	int flag;
	
	
	if (M == 1)
		++M;
	for (int i = M; i <= N;++i)
	{
		if (i == 2)
			printf("%d\n", i);
		flag = 0;

		
		if (i % 2 == 1)
		{
			
				
			for (int j = 3; j <= (int)sqrt(i); j+=2)
			{
				if (i % j == 0)
				{
					flag = 1;
					break;

				}
			
			}
			if (flag == 0)
				printf("%d\n", i);
		}
		
	}

	return 0;
}