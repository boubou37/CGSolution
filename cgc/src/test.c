#include <stdlib.h>
#include <assert.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

//void printOffset(char **grid, int H, int L, int offst)


int *getDigits(char **letters, char **num, int Si, int H, int L, int W)
{
	int digits = Si/H;
	int count = 0;
	int matchcount=0;
	int *ret = malloc(digits*sizeof(int));
	for (int l=0; l<digits; l++) {
		for (int i=0; i < W; i+=L) {
			for (int j=H*l; j < (l+1)*H; j++) {
				if (strncmp(&letters[j%H][i],num[j],L)) break;
				else matchcount++;
				if (matchcount == H) ret[count++] = i/L;
			}
			matchcount=0;
		}
	}
	return ret;
}

unsigned long getNumber(int *digits, int len)
{
	unsigned long res = 0;
	for (int i=0; i < len; i++) {
		res += digits[i] * pow(20,len-i-1);
	}
	return res;
}

int main()
{
	FILE *f = fopen("lib/community/gravity/Test0.txt","r");
	int width;
	int height;
	fscanf(f,"%d%d", &width, &height);
	char grid[height][width];
	char cpy[height][width];
	int cnt=height-1;
	for (int i = 0; i < height; i++) {
		char line[257];
		fscanf(f,"%s", line);
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

}
