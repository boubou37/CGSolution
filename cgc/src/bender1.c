#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct State {
	int dir;
	int rev;
	int uber;
	int pos[2];
	char currentChar;
}State;

//return 0 if match
int cmp(State *s1, State *s2)
{
	return !(s1->dir == s2-> dir 
			&& s1->rev == s2->rev
			&& s1->uber == s2->uber
			&& s1->pos[0] == s2->pos[0]
			&& s1->pos[1] == s2->pos[1]);
}

int *nextPos(char **grid, int *pos, int dir)
{
	int *ret = malloc(2*sizeof(int));
	int x=pos[1], y=pos[0];
	switch (dir) {
		case 0: y++; break;
		case 1: x++; break;
		case 2: y--; break;
		case 3: x--; break;
	}
	ret[0] = y;
	ret[1] = x;
	return ret;
}

char nextChar(char **grid, int *pos, int dir)
{
	int *np = nextPos(grid,pos,dir);
	return grid[np[0]][np[1]];
}

State *addState(int dir, int *pos, int uber, int rev)
{
	State *ret = malloc(sizeof(State));
	ret->dir=dir;
	ret->pos[0]=pos[0];
	ret->pos[1]=pos[1];
	ret->uber=uber;
	ret->rev=rev;
	return ret;
}

char *dirs[] = {"SOUTH","EAST","NORTH","WEST"};

int main()
{
	int L;
	int C;
	scanf("%d%d", &L, &C); fgetc(stdin);
	char **grid = malloc(L*sizeof(char*));
	for (int i=0;i<L;i++) grid[i] = malloc(C*sizeof(char));
	int count=0, moveCount=0;
	int rev=0, uber=0, look=0, dir=0, tempDir=0;
	int term=0;
	int *pos = malloc(2*sizeof(int));
	int *tempPos = malloc(2*sizeof(int));
	int tppos[2][2];
	char *temp;
	char tempChar='@', nextC;
	State *visited[100];
	char *moves[1000];
	for (int i = 0; i < L; i++) {
		char row[102];
		fgets(row, 102, stdin);
		strcpy(grid[i],row);
		if ( (temp = strchr(row,'@')) != NULL) {
			pos[0] = i;
			pos[1] = temp - &row[0];
		}
		if ( (temp = strchr(row,'T')) != NULL) {
			tppos[look][0] = i;
			tppos[look++][1] = temp - &row[0];
		}
	}

	while (tempChar != '$' && !term) { 
		switch (tempChar) {
			case 'S': dir=0; break;
			case 'E': dir=1; break;
			case 'N': dir=2; break;
			case 'W': dir=3; break;
			case 'I': rev = !rev; break;
			case 'B': uber = !uber; break;
			case 'T': if (tppos[0][0] == pos[0] && tppos[0][1] == pos[1]) 
					  pos = tppos[1];
				  else
					  pos = tppos[0];
				  break;
			default: break;
		}
		nextC =nextChar(grid,pos,dir);
		switch(nextC) {
			case 'X': if (uber) {
					  tempPos = nextPos(grid,pos,dir);
					  grid[tempPos[0]][tempPos[1]] = ' ';
					  memset(visited,0,sizeof(visited));
					  count = 0;
					  break;
				  }
			case '#': 
				  if (!rev) {
					  dir=0;
					  for (;dir < 3; dir++) {
						  tempChar = nextChar(grid,pos,dir);
						  if (tempChar != '#' && tempChar != 'X') break;
					  } 
				  }
				  else {
					  dir=3;
					  for (;dir >= 0; dir--) {
						  tempChar = nextChar(grid,pos,dir);
						  if (tempChar != '#' && tempChar != 'X') break;
					  } 
				  }
				  nextC = tempChar;
				  break;

			default: break;
		}
		visited[count++] = addState(dir,pos,uber,rev);
		moves[moveCount++] = dirs[dir];
		for (int i=0; i<count-1; i++) {
			if (!cmp(visited[i],visited[count-1])) {
				term = 1;
				break;
			}
		}
		pos = nextPos(grid,pos,dir);
		tempChar = nextC;
	}


	if (term) printf("LOOP\n");
	else {
		for (int i=0; i<moveCount; i++) {
			printf("%s\n",moves[i]);
		}
	}

	return 0;
}
