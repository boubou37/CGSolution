#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/
int main()
{
	int n;
	scanf("%d", &n);
	int arr[n];
	int max=0, min=0;
	int tempDiff=0, diff=0;;
	for (int i = 0; i < n; i++) {
		int v;
		scanf("%d", &v);
		arr[i] = v;
		if (arr[i] < min) {
			min = arr[i];
			tempDiff = max - min;
		}
		if (arr[i] >= max) {
			max = min = arr[i];
			tempDiff = 0;
		}
		diff = tempDiff >= diff ? tempDiff :  diff;
	}
	// Write an action using printf(). DON'T FORGET THE TRAILING \n
	// To debug: fprintf(stderr, "Debug messages...\n");

	int res = -diff;
	printf("%d\n",res);

	return 0;
}
