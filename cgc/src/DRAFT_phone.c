#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/
typedef struct TrieNode {
	char c;
	struct TrieNode *child;
	struct TrieNode *next; //right neighb
}TrieNode;

void insert(TrieNode *root, char *word, int *count)
{
	TrieNode *temp = root;
	TrieNode *tempD = temp;
	int stop=0;
	//search
	while (*word != '\0' && *word != '\n' && !stop) {
		if (temp->next ==NULL) {
			temp->next = malloc(sizeof(TrieNode));
			temp = temp->next;
			stop = 1;
			continue;
		}
		temp = temp->next;
		tempD = tempD->child;
	}
	//suffixing
	while (*word != '\0' && *word != '\n') {
		temp->c = *word;
		temp->child = malloc(sizeof(TrieNode));
		temp = temp->child;
	}


}

int main()
{
	int N;
	int count=0;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		char telephone[21];
		scanf("%s", telephone);
	}

	// Write an action using printf(). DON'T FORGET THE TRAILING \n
	// To debug: fprintf(stderr, "Debug messages...\n");


	// The number of elements (referencing a number) stored in the structure.
	printf("number\n");

	return 0;
}
