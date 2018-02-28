#include <stdio.h>

typedef struct daata
{
	int val;
	int b;
}data;

data arr[101];

int hash1(int a)
{
	return a%101;
}

int hash2(int a)
{
	return (a%37 +1);
}

void insertion()
{
	int a,i;
	scanf("%d",&a);
		
	int h1 = hash1(a);
	int h2 = hash2(a);

	i=h1;
	while(arr[i].b != 0)
	{
		i+=h2;
	}

	arr[i].val = a;
	arr[i].b = 1;

	return;
}

void deletion()
{
	int a,i;
         scanf("%d",&a);
                  
         int h1 = hash1(a);
         int h2 = hash2(a);
 
	 i=h1;
         while(arr[i].b != 1 && arr[i].val != a)
         {
                 i+=h2;
         }
 
         arr[i].b = -1;

	 return;
}

void search()
{
	int a,i;
	scanf("%d",&a);
	int h1 = hash1(a);
	int h2 = hash2(a);
	
	i=h1;
	while(arr[i].val !=a && arr[i].b!=0)
	{
		i+=h2;
	}

	if(arr[i].val==a)
	{
		printf("%d found in %d of arr\n",a,i);
	}
	else
	{
		printf("%d not found\n",a);
	}
	return;
}

int main()
{

	int i,a,n=0;

	for(i=0;i<101;i++)
	{
		arr[i].b=0;
	}

	while(1)
	{
		printf("current n = %d .1 for insertion 2 for deletion 3 for search :",n);
		scanf("%d",&i);
	
		if(i==1)
		{
			printf("input a non-negative integer :");
			insertion();
			n++;
		}
		else if(i==2)
		{
			printf("input a non-negative integer :");
			deletion();
			n--;
		}
		else if(i==3)
		{
			printf("input a non-negative integer :");
			search();
		}
		else
		{
			printf("invalid input");
		}
	}
	return 0;
}
