#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct List {
	size_t size;
	int *nums;
} List;

void append(List *list, int num)
{
	list->nums = realloc(list->nums,((list->size)+1)*sizeof(int));
	list->size++;
	list->nums[list->size-1] = num;
}

void clear(List *list)
{
	free(list->nums);
	list->nums = NULL;
	list->size = 0;
}

int get(List *list, int index)
{
	if (list->size <= index) return -1;
	return list->nums[index];
}

void move(List *from, List *to)
{
	clear(to);
	for (int i=0; i<from->size; i++) {
		append(to,from->nums[i]);
	}
	clear(from);
}

void print(List *list)
{
	for (int i=0; i<list->size; i++) {
		if (i == list->size-1)
			printf("%d",list->nums[i]);
		else
			printf("%d ",list->nums[i]);
	}
	printf("\n");
}


int main()
{
	int R;
	scanf("%d", &R);
	int L;
	scanf("%d", &L);
	List l = {.size = 0};
	List l2 = {.size = 0};
	append(&l,R);
	int curr=R,countCurr=0;
	for (int i=1; i<L; i++) {
		for (int j=0; j<l.size; j++) {
			countCurr++;
			curr = get(&l,j); 
			if (curr != get(&l,j+1) || j == l.size - 1) {
				append(&l2,countCurr);
				append(&l2,curr);
				countCurr=0;
			}
		}
		move(&l2,&l);
	}
	print(&l);
	return 0;
}
