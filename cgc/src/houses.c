#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int comp(const void *a, const void *b)
{
	return *(int*) a - *(int*) b;
}

int main()
{
	int N;
	scanf("%d", &N);
	unsigned long int res = 0;
	if (N <= 1) {
		printf("%lu\n",res);
		return 0;
	}
	else {
		int houses[N];
		int xmax=0, xmin=0;
		for (int i = 0; i < N; i++) {
			int X;
			int Y;
			scanf("%d%d", &X, &Y);
			if (i==0) {
				xmax = xmin = X;
			}
			if (X>xmax) xmax = X;
			if (X<xmin) xmin = X;
			houses[i] = Y;
		}
		qsort(&houses[0],N,sizeof(int),comp);
		int mid = N%2 == 0 ? N/2 - 1 : N/2+0.5;
		int ymed = houses[mid];
		res+=xmax-xmin;
		for (int i = 0; i < N; i++) {
			res+=abs(houses[i]-ymed);
		}
		printf("%lu\n",res);
	}


	return 0;
}
