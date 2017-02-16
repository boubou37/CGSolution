#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/
int main()
{
	char MESSAGE[101];
	fgets(MESSAGE, 101, stdin);

	// Write an action using printf(). DON'T FORGET THE TRAILING \n
	// To debug: fprintf(stderr, "Debug messages...\n");

	char *p = &MESSAGE[0];
	fprintf(stderr,"%c",*p);
	//2 is initial state
	int statut=2;
	int it=statut;
	while (*p != '\0' && *p != '\n') {
		for (int i=6; i>=0; i--) {
			it = (*p >> i) & 0x01;
			if (it != statut) {
				//space after each change (excluding initilialization)
				if (statut != 2) printf(" ");
				if (it) {
					printf("0 ");
					statut = 1;
				}
				else {
					printf("00 ");
					statut = 0;
				}
			}
			printf("0");
		}
		p++;
	}
	free(p);

	return 0;
}
