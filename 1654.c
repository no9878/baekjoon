#include <stdio.h>

int K, N;
int have[10000];

void INPUT(void) {
	scanf_s("%d %d", &K, &N);
	for (int i = 0; i < K; ++i) {
		scanf_s("%d", &have[i]);
	}
}

int MAKELAN(int length) {
	
	int sum=0;

	for (int i = 0; i < K; ++i) {
	
			sum += have[i] / length;
		
	}
	return sum;
}

int SearchMAX() {
	int high = 0;
	int low = 1;
	int MAX = 0;
	for (int i = 0; i < K; ++i) {
		if (high < have[i]) {
			high = have[i];
		}
	}
	int mid = 0;
	while (low <= high) {
		 mid = low + (high - low) / 2;
		if (MAKELAN(mid) >= N) {
			MAX = mid;
			if (mid == 2147483647)
				break;
			low = mid + 1;
		}
		else {
			high = mid - 1;
		}
	}
	return MAX;
}

int main(void) {
	INPUT();
	int MAX = SearchMAX();
	printf("%d\n", MAX);
	
	return 0;
}
