#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define MIN(a,b) a < b ? a : b;

int cmp(const void *a, const void *b)
{
	return *(int*)a - *(int*)b;
}

int main()
{
	int N;
	scanf("%d", &N);
	int C;
	scanf("%d", &C);
	int sum = 0, min = 0;;
	int *nums = malloc(N*sizeof(int));
	int avg = C/N;
	int ctd = C;
	int p = 0;
	for (int i=0; i < N; i++) {
		int B;
		scanf("%d", &B);
		nums[i] = B;
		sum += B;
	}
	if (sum < C) printf("IMPOSSIBLE\n");
	else {
		qsort(nums,N,sizeof(int),cmp);
		for (int i=0; i<N; i++) {
			min = MIN(avg,nums[i]);
			ctd -= min;
			if (i == N-1) {
				if (ctd == 1) min++;
			}
			else 
				avg = ctd / (N-i-1);
			printf("%d\n",min);
		}
	}
	return 0;
}
