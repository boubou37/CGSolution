#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/

long long findS(long long num)
{
	long long ret = 0;
	while (num>>=1) {
		ret+= num & 0x01 ? 3 : 4;
	}
	return ret;
}

int main()
{
    long long start;
    long long n;
    scanf("%lld%lld", &start, &n);
    long long res = findS(start);
    for (long long i=1; i<n; i++) {
	    res = findS(res);
	    if (res == 18 || res == 13) break; //S repeats at 13 or 18
    }
    printf("%lld",res);


    return 0;
}
