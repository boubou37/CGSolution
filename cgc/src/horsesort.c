#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <limits.h>

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/

int cmpfunc (const void * a, const void * b);
int main()
{
    int N;
    scanf("%d", &N);
    int vals[N];
    for (int i = 0; i < N; i++) {
        int Pi;
        scanf("%d", &Pi);
	vals[i] = Pi;
    }

    // Write an action using printf(). DON'T FORGET THE TRAILING \n
    // To debug: fprintf(stderr, "Debug messages...\n");
    qsort(vals,N,sizeof(int),cmpfunc);
    int dist = INT_MAX;
    int temp;
    for (int i=1; i<N; i++) {
	    temp = vals[i] - vals[i-1];
	    dist = dist > temp ? temp : dist;
    }

    printf("%d\n",dist);

    return 0;
}

int cmpfunc (const void * a, const void * b)
{
   return ( *(int*)a - *(int*)b );
}

