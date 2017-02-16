#include <stdlib.h>
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
			for (int j=H*l; j < H*(l+1); j++) {
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
	int L;
	int H;
	int cnt = 0;
	FILE *f = fopen("lib/test.txt","r");
	scanf("%d%d", &L, &H);
	int W = 20*L;
	char **letters = malloc(H*sizeof(char*));
	char debug[L];
	for (int i = 0; i < H; i++) {
		char numeral[W];
		letters[i] = malloc(W*sizeof(char));
		scanf("%s", numeral);
		strcpy(letters[i],numeral);
	}

	int S1;
	scanf("%d", &S1);
	char **num1 = malloc(S1*sizeof(char*));
	for (int i = 0; i < S1; i++) {
		num1[i] = malloc((L+1)*sizeof(char));
		char num1Line[L+1];
		scanf("%s", num1Line);
		strcpy(num1[i],num1Line);
	}
	int *dig1 = (int*)getDigits(letters, num1, S1, H, L, W);
	unsigned long op1 = getNumber(dig1,S1/H);

	int S2;
	scanf("%d", &S2);
	char **num2 = malloc(S2*sizeof(char*));
	for (int i = 0; i < S2; i++) {
		num2[i] = malloc((L+1)*sizeof(char));
		char num2Line[L+1];
		scanf("%s", num2Line);
		strcpy(num2[i],num2Line);
	}
	int *dig2 = getDigits(letters, num2, S2, H, L, W);
	unsigned long op2 = getNumber(dig2,S2/H);

	char operation[2];
	scanf("%s", operation);
	switch (operation[0]) {
		case '+': 
			op1+=op2;
			break;
		case '-':
			op1-=op2;
			break;
		case '/':
			op1/=op2;
			break;
		case '*':
			op1*=op2;
			break;
		default: break;
	}

	free(dig1);
	dig1 = malloc(sizeof(int));
	if (!op1) dig1[cnt++] = 0;
	while (op1) {
		dig1[cnt++] = op1 % 20;
		dig1 = realloc(dig1,(1+cnt)*sizeof(int));
		op1 /= 20;
	}

	for (int i=0; i<cnt; i++) {
		for (int m=0; m<H; m++) {
			printf("%.*s",L,letters[m]+dig1[cnt-i-1]*L);
			printf("\n");
		}
	}

	return 0;
}
