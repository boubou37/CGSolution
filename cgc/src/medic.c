
#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#define M_PI 3.14159265358979323846


char *tokAt(char *word,int index,char delimiter);
char* strreplace(char* word, char old, char new);
/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/
double toRad(double degrees) 
{
	return degrees * M_PI / 180;
}
int main()
{
	char LON[51];
	scanf("%s", LON);
	char LAT[51];
	scanf("%s", LAT);
	int N;
	double x,y,latA,latB,lonA,lonB,dist=9999,tempDist;
	latA = toRad(strtod(strreplace(LAT,',','.'),NULL));
	lonA = toRad(strtod(strreplace(LON,',','.'),NULL));
	scanf("%d", &N); fgetc(stdin);
	char* name = malloc(50*sizeof(char));
	for (int i = 0; i < N; i++) {
		char DEFIB[257];
		fgets(DEFIB, 257, stdin);
		lonB = toRad(strtod(strreplace(tokAt(DEFIB,4,';'),',','.'),NULL));
		latB = toRad(strtod(strreplace(tokAt(DEFIB,5,';'),',','.'),NULL));
		x = (lonB-lonA)*cos((latA+latB)/2);
		y = latB - latA;
		tempDist = sqrt(x*x+y*y)*6371;
		if (dist > tempDist) {
			dist = tempDist;
			name = tokAt(DEFIB,1,';');
		}
	}

	// Write an action using printf(). DON'T FORGET THE TRAILING \n
	// To debug: fprintf(stderr, "Debug messages...\n");

	printf("%s\n",name);

	return 0;
}

char *tokAt(char *word,int index,char delimiter)
{
	char* cop = malloc(strlen(word)*sizeof(char));
	strcpy(cop,word);
	for (int i=0; i<index; i++) {
		cop = strchr(cop,delimiter);
		cop++;
	}
	char *ret = malloc(strlen(word)*sizeof(char));
	//No delimiter => take all cop
	if (strchr(cop,delimiter) == NULL) {
		strncpy(ret,cop,strlen(cop));
	}
	//else copy till next delimiter (strchr - current)
	else {
		strncpy(ret,cop,strchr(cop,delimiter)-cop);
	}
	return ret;
}

char* strreplace(char* word, char old, char new) 
{
	char *copy = malloc(strlen(word)*sizeof(char));
	strcpy(copy,word);
	char *p = strchr(copy,old);
	while (p != NULL) {
		*p = new;
		p = strchr(copy,old);
	}
	return copy;
}


