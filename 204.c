#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int N;
	if (scanf_s("%d", &N) != 1 || N < 1 || N>500000)
		return 1;
	int* nlist = (int*)malloc(sizeof(int) * (2*N));
	for (int i = 1; i <= N;++i)
	{
		nlist[i] = i;
	}

	nlist[0] = 0;
	

	int temp;

	for (int j = 1; j < N ;++j)
	{
		nlist[(2*j)-1] = 0;
		temp = nlist[2*j];
		nlist[N+j] = temp;
	}

	printf("%d\n", nlist[(2*N)-1]);
	free(nlist);
	return 0;
}
