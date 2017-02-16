#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/
int main()
{
	int L;
	scanf("%d", &L);
	int H;
	scanf("%d", &H); fgetc(stdin);
	char T[257];
	char ascT[H][1025];
	int *ind = malloc(257*sizeof(int));
	int *start = ind;
	int r=0;
	char *c = sizeof(1025*sizeof(char));
	fgets(T, 257, stdin);
	for (int i = 0; i < H; i++) {
		char ROW[1025];
		c= fgets(ROW, 1025, stdin);
		strcpy(ascT[i],c);
	}

	// Write an action using printf(). DON'T FORGET THE TRAILING \n
	// To debug: fprintf(stderr, "Debug messages...\n");
	c = &T[0];
	while (*c != '\0' && *c != '\n') {
		//Upper char
		if (*c >= 65 && *c <= 90) {
			//get rank of letter (A=0, B=1 etc)
			r = *c - 65;
		}
		//lower char
		else if (*c >= 97 && *c <= 122) {
			r = *c - 97;
		}
		else r = 26;
		*ind=r*L;
		fprintf(stderr,"factor is %d for char %c\n",r,*c);
		c++;
		ind++;
	}
	*ind = -1;
	ind = start;
	r = *ind;
	for (int i=0; i<H; i++) {
		while (*ind != -1) {
			for (int j=*ind; j<*ind+L; j++) {
				printf("%c",ascT[i][j]);
			}
			ind++;
		}
		printf("\n");
		ind = start;
	}


	return 0;
}
