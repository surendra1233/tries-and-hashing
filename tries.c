#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct nodes
{
	struct nodes * arr[26];
	int flag;
	int no;
}node;

node *trie;

void insertion()
{
	char temp[10];

	scanf("%s",&temp);
	
	node* ptr = trie;
	int i=0;
	int len = strlen(temp);
	while(i<len)
	{
		int ind = temp[i] - 'a';
		if(ptr->arr[ind]==NULL)
		{
			ptr->arr[ind] = (node* )malloc(sizeof(node));

			for(int j = 0 ;j <26;j++)
				ptr->arr[ind]->arr[j]=NULL;
		}
		ptr = ptr->arr[ind];
		i++;
	}

	ptr->flag = 1;

	return;
}

void search()
{
	char temp[10];
	node * ptr = trie;
	scanf("%s",&temp);
	int i=0;
	int len = strlen(temp);

	while(i<strlen(temp))
	{
		int ind = temp[i] - 'a';
		if(ptr->arr[ind] == NULL)
		{
			printf("not found\n");
		}
		else
		{
			ptr = ptr->arr[ind];
		}
	
		i++;
	}
	if(ptr->flag)
		printf("found\n");
	else
		printf("not found\n");
	return;
}

int main()
{
	int i;
	trie = (node*)malloc(sizeof(node));	
	for(i=0;i<26;i++)
	{
		trie->arr[i] = NULL;
	}
	while(1)
	{
		printf("1 for insertion 2 for search :");
		scanf("%d",&i);
		printf("input a string having less than 10 characters :");
		if(i==1)
		{
			insertion();
		}
		else
		{
			search();
		}
	}

	return 0;
}
