#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/

typedef struct Card {
	char *data;
	struct Card *next;
}Card;

typedef struct Deck {
	int ind;
	int size;
	struct Card *head;
	struct Card *tail;
}Deck;

int count=0;
char *ranks="2345678910JQKA";

int empty(Deck *deck)
{
	return deck->head == NULL && deck->tail == NULL;
}

void queue(Deck *deck, char *crd)
{
	Card *card = malloc(sizeof(Card));
	card->data = crd;
	if (empty(deck)) {
		deck->head = card;
		deck->tail = card;
	}
	else {
		deck->tail->next = card;
		deck->tail = card;
	}
	deck->size++;
}


void dequeue(Deck *deck)
{
	Card *temp = deck->head;
	if (temp ==NULL) return;
	if (deck->head == deck->tail) {
		deck->head = NULL;
		deck->tail = NULL;
	}
	else{
		temp = temp->next;
		deck->head = temp;
	}
	deck->size--;
}


void transfer(Deck *from, Deck *to, int lim)
{
	int inf=lim == -1 ? 1 : 0;
	int i=0;
	while(!empty(from) && (i<lim || inf)) {
		queue(to,from->head->data);
		dequeue(from);
		i++;
	}
}
// >0 if c1 greater than c2
int cmp(Card *c1, Card *c2)
{
	char ch1[2] = {c1->data[0],'\0'};
	char ch2[2] = {c2->data[0],'\0'};
	return strstr(ranks,ch1) - strstr(ranks,ch2);
}

int main()
{
	int roundWin = 0;
	Deck *d1 = malloc(sizeof(Deck));
	Deck *d1War = malloc(sizeof(Deck));
	d1->ind=1;
	Deck *d2 = malloc(sizeof(Deck));
	Deck *d2War = malloc(sizeof(Deck));
	d2->ind=2;
	int n; // the number of cards for player 1
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		char cardp1[4]; // the n cards of player 1
		char *rec = malloc(4*sizeof(char));
		scanf("%s", cardp1);
		queue(d1,strcpy(rec,cardp1));
	}
	int m; // the number of cards for player 2
	scanf("%d", &m);
	fprintf(stderr,"\n");
	for (int i = 0; i < m; i++) {
		char cardp2[4]; // the m cards of player 2
		char *rec = malloc(4*sizeof(char));
		scanf("%s", cardp2);
		queue(d2,strcpy(rec,cardp2));
	}
	while (!empty(d1) && !empty(d2)) {
		count++;
		Card *cp1 = d1->head;
		Card *cp2 = d2->head;
		if (cmp(cp1,cp2) > 0) {
			transfer(d1,d1,1);
			transfer(d2,d1,1);
		}
		else if (cmp(cp1,cp2) < 0) {
			transfer(d2,d2,1);
			transfer(d1,d2,1);
		}
		else {
			while (!cmp(cp1,cp2)) {
				transfer(d1,d1War,4);
				transfer(d2,d2War,4);
				cp1 = d1->head;
				cp2 = d2->head;
			}
			if (cmp(cp1,cp2) > 0) {
				transfer(d1War,d1,-1);
				transfer(d1,d1,1);
				transfer(d2War,d1,-1);
				transfer(d2,d1,1);
			}
			else if (cmp(cp1,cp2) < 0) {
				transfer(d2War,d2,-1);
				transfer(d2,d2,1);
				transfer(d1War,d2,-1);
				transfer(d1,d2,1);
			}
		}
	}
	int winner=empty(d2) ? 1 : 2;
	printf("%d %d\n",winner,count);

	return 0;
}
