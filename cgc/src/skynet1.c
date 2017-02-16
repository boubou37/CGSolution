#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct Queue{
	int num;
	struct Queue *next;
} Queue;

Queue *headQ;
Queue *tailQ;

void queue(int x)
{
	Queue *t = malloc(sizeof(Queue));
	t->num=x;
	if (headQ == NULL && tailQ == NULL) {
		headQ = t;
		tailQ = t;
		return;
	}
	tailQ->next = t;
	tailQ = t;
}

int getHead() {
	if (headQ != NULL) {
		return headQ->num;
	}
	return -1;
}

void dequeue()
{
	int ret=0;
	Queue *t = headQ;
	if (t ==NULL) {
		return;
	}
	if (headQ == tailQ) {
		headQ = NULL;
		tailQ = NULL;
	}
	t = t->next;
	headQ = t;
}


int main()
{
	int N; // the total number of nodes in the level, including the gateways
	int L; // the number of links
	int E; // the number of exit gateways
	scanf("%d%d%d", &N, &L, &E);
	int *adj[N];
	for (int i=0; i<N; i++) {
		adj[i] = calloc(100,sizeof(int*));
	}
	int *gates = calloc(N,sizeof(int));
	int *marked = calloc(N,sizeof(int));
	int flag=1;
	int temp=0;
	int curr=0;

	for (int i = 0; i < L; i++) {
		int N1; // N1 and N2 defines a link between these nodes
		int N2;
		scanf("%d%d", &N1, &N2);
		adj[N1][N2]=1;
		adj[N2][N1]=1;
	}
	for (int i = 0; i < E; i++) {
		int EI; // the index of a gateway node
		scanf("%d", &EI);
		gates[EI]=1;
	}

	// game loop
	while (1) {
		int SI; // The index of the node on which the Skynet agent is positioned this turn
		scanf("%d", &SI);
		marked[SI]=1;
		queue(SI);
		temp=0;
		do {
			curr=getHead();
			dequeue();
			for (int i=0; i<N; i++) {
				temp = adj[curr][i];
				if (temp && !marked[i]) {
					queue(i);
					marked[i]=1;
					if (gates[i]) {
						flag=0;
						printf("%d %d\n",curr,i);
						break;
					}
				}
			}
		}
		while (!gates[curr] && flag); //neightbor is not gate
		flag = 1;
		for (int i=0; i<N; i++) {marked[i] = 0;}
		headQ = NULL;
		tailQ = NULL;
	}

	return 0;
}
