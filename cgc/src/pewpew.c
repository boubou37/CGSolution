#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/**
 * Don't let the machines win. You are humanity's last hope...
 **/
int main()
{
    int width; // the number of cells on the X axis
    scanf("%d", &width);
    int height; // the number of cells on the Y axis
    char* fu = malloc(32);
    scanf("%d", &height); fgetc(stdin);
    char grid[height][width];
    int hasRight = 0;
    int hasDown = 0;
    for (int i = 0; i < height; i++) {
        char line[32]; // width characters, each either 0 or .
        fgets(line, 32, stdin); // width characters, each either 0 or .
	strcpy(grid[i],line);

    }

    for (int i=0; i<height; i++) {
	    for (int j=0; j<width; j++) {
		    fprintf(stderr,"%c",grid[i][j]);
	    }
		    fprintf(stderr,"\n");
    }

    for (int i=0; i<height; i++) {
	    for (int j=0; j<width; j++) {
		    if (grid[i][j] == '0') {
			    printf("%d %d",j,i);
			    //right lookup
			    for (int k=j+1; k<width; k++) {
				    if (grid[i][k] == '0') {
					   hasRight = 1;
					   printf(" %d %d",k,i);
					   break;
				    }
			    }
			    if (!hasRight) printf(" -1 -1");
			    //down lookup
			    for (int l=i+1; l<height; l++) {
				    if (grid[l][j] == '0') {
					    hasDown = 1;
					    printf(" %d %d\n",j,l);
					    break;
				    }
			    }
			    if (!hasDown) printf(" -1 -1\n");
		    }
		    hasRight = 0;
		    hasDown = 0;
	    }
    }

    // Write an action using printf(). DON'T FORGET THE TRAILING \n
    // To debug: fprintf(stderr, "Debug messages...\n");


    // Three coordinates: a node, its right neighbor, its bottom neighbor
    printf("0 0 1 0 0 1\n");
    printf("0 1 -1 -1 -1 -1\n");

    return 0;
}
