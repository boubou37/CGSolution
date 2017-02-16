#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/
int main()
{
	int width;
	int height;
	scanf("%d%d", &width, &height);
	char grid[height][width];
	char cpy[height][width];
	int cnt=height-1;
	for (int i = 0; i < height; i++) {
		char line[257];
		scanf("%s", line);
		strcpy(grid[i],line);
	}
	for (int j = 0; j < width; j++) {
		for (int i = 0; i < height; i++) {
			if (grid[i][j] == '#') {
				cpy[cnt--][j] = '#';
			}
		}
		while (cnt >= 0 ) {
			cpy[cnt--][j] = '.';
		}
		cnt=height-1;
	}
	for (int i=0; i<height; i++) {
		for (int j=0; j<width; j++) {
			printf("%c",cpy[i][j]);
		}
		printf("\n");
	}
	return 0;
}
