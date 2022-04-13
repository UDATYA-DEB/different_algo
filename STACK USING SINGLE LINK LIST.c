#include<stdio.h>
#include<malloc.h>

void create(int);
void insert_end();
void delete_node_last();
void disp();
int node_count();

struct node{
	int data;
	struct node *next;
};

struct node *start = NULL;

void main()
{
	int no_of_nodes = 0, choose = -999999, loop_exit = -1;
	
	printf("Enter number of nodes: ");
	scanf("%d", &no_of_nodes);
	
	create(no_of_nodes);
	disp();
	
	while(loop_exit != 0)
	{
		printf("\n---------------------------------------------------\n");
		printf("\nChoose the given options: \n");
		printf("1. PUSH\n");
		printf("2. POP\n");
		printf("3. DISPLAY\n");
		printf("0. EXIT\n");
		printf("\n");
		printf("Choose: ");
		scanf("%d", &choose);
		
		switch(choose)
		{
			case 0:		loop_exit = 0;
						break;
			case 1:		insert_end();
						disp();
						break;
			case 2:		delete_node_last();
						disp();
						break;
			case 3:		disp();
						break;
			
			default:	printf("\nInvalid input\n");	
		}	
	}
}

void create(int no_of_nodes)
{
	struct node *p;
	p = (struct node*)malloc(sizeof(struct node));
	start = p;
	
	int item0 = 0, item = 0;
	printf("Enter the data: ");
	scanf("%d", &item0);
	
	p -> data = item0;
	p -> next = NULL;
	
	for (int i = 2; i <= no_of_nodes; i++)
	{
		p -> next = (struct node*)malloc(sizeof(struct node));
		p = p -> next;
		printf("Enter the data: ");
		scanf("%d", &item);
		
		p -> data = item;
		p -> next = NULL;
	}
}

void insert_end()
{
	struct node *p = start, *temp;
	int item = 0;
	
	temp = (struct node*)malloc(sizeof(struct node));
	
	printf("Enter the data: ");
	scanf("%d", &item);
	
	temp -> data = item;
	temp -> next = NULL;
	
	if (p == NULL)
	{
		start = temp;
	}
	else
	{
		while(p -> next != NULL)
		{
			p = p -> next;
		}
		p -> next = temp;
	}
}

void delete_node_last()
{
	struct node *p = start;
	int no_of_nodes = node_count();
	
	for (int i = 1; i < no_of_nodes-1; i++)
	{
		p = p -> next;
	}
	
	p -> next = NULL;
}

void disp()
{
	struct node *p = start;
	if (p == NULL)
	{
		printf("No link list found.");
	}
	else
	{
		while(p != NULL)
		{
			printf("%d --> ", p -> data);
			p = p -> next;
		}
		printf("NULL");
	}
}

int node_count()
{
	struct node *p = start;
	int count = 0;
	if (p == NULL)
	{
		count = 0;
	}
	else
	{
		while(p != NULL)
		{
			count++;
			p = p -> next;
		}
	}
	
	return count;
}
