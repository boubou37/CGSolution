#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/
int main()
{
    int W; // width of the building.
    int H; // height of the building.
    int hSwitch=0;
    int vSwitch=0;
    scanf("%d%d", &W, &H);
    int N; // maximum number of turns before game over.
    int **grid = calloc(W,sizeof(int*));
	for (int i=0; i<W; i++) {
	    grid[i] = calloc(H,sizeof(int));
    }

    scanf("%d", &N);
    int X0;
    int Y0;
    int start=1;
    scanf("%d%d", &X0, &Y0);

    // game loop
    while (1) {
        char bombDir[4]; // the direction of the bombs from batman's current location (U, UR, R, DR, D, DL, L or UL)
        scanf("%s", bombDir);

	if (strcmp(bombDir,"U") == 0) {
		Y0 /= 2;
		H -=Y0;
	}
	else if (strcmp(bombDir,"UR") == 0) {
		X0 += (W-X0)/2;
		Y0 /= Y0;
	}
	else if (strcmp(bombDir,"UL") == 0) {
		X0 /= 2;
		Y0 /=2 ;
	}
	else if (strcmp(bombDir,"DR") == 0) {
		X0 += (W-X0)/2;
		Y0 += (H-Y0)/2;
	}
	else if (strcmp(bombDir,"DL") == 0) {
		X0 /= 2;
		Y0 += (H-Y0)/2;
	}
	else if (strcmp(bombDir,"D") == 0) {
		Y0 += (H-Y0)/2;
	}
	else if (strcmp(bombDir,"L") == 0) {
		X0 /= X0;
	}
	else if (strcmp(bombDir,"R") == 0) {
		X0 += (W-X0)/2;
	}
	printf("%d %d\n",X0,Y0);
	

        // Write an action using printf(). DON'T FORGET THE TRAILING \n
        // To debug: fprintf(stderr, "Debug messages...\n");


        // the location of the next window Batman should jump to.
    }

    return 0;
}
