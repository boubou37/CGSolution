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
	scanf("%d%d", &W, &H);
	int YMin = 0;
	int XMin = 0;
	int N; // maximum number of turns before game over.
	scanf("%d", &N);
	int X0;
	int Y0;
	int start=1;
	scanf("%d%d", &X0, &Y0);

	// game loop
	while (1) {
		char bombDir[4]; // the direction of the bombs from batman's current location (U, UR, R, DR, D, DL, L or UL)
		scanf("%s", bombDir);
		switch(bombDir[0]) {
			case 'U':
				H=Y0;
				Y0=(YMin+H)/2;
				break;
			case 'D':
				YMin = Y0;
				Y0=(YMin+H)/2;
				break;
			case 'L':
				W=X0;
				X0 = (XMin+W)/2;
				break;
			case 'R':
				XMin=X0;
				X0 = (XMin+W)/2;
				break;
			default:
				break;
		}
		switch(bombDir[1]) {
			case 'L':
				W=X0;
				X0 = (XMin+W)/2;
				fprintf(stderr,"W : %d \n X0 : %d \n Xmin : %d",W,X0,XMin);
				break;
			case 'R':
				XMin=X0;
				X0 = (XMin+W)/2;
				break;
			default:
				break;
		}
		printf("%d %d\n",X0,Y0);
	}

	return 0;
}
