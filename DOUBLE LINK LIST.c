#include<stdio.h>
#include<malloc.h>

struct node{
	struct node *prev_node;
	int data;
	struct node *next_node;
};

struct node *start = NULL;

void insert_beg();
void insert_end();
void insert_in_pos();
void delete_node_in_pos();
int node_count();
void display();
void create(int);

void insert_beg()
{
	struct node *p = start, *temp;
	int item = 0;
	
	temp = (struct node*)malloc(sizeof(struct node));
	
	printf("Input data: ");
	scanf("%d", &item);
	
	temp -> prev_node = NULL;
	temp -> data = item;
	temp -> next_node = p;
	
	start = temp;
}

void insert_end()
{
	struct node *p = start, *temp;
	int item = 0;
	
	temp = (struct node*)malloc(sizeof(struct node));
	
	printf("Input data: ");
	scanf("%d", &item);
	
	temp -> data = item;
	temp -> next_node = NULL;
	
	if (p == NULL)
	{
		start = temp;
		temp -> prev_node = NULL;
	}
	else
	{
		while (p -> next_node != NULL)
		{
			p = p -> next_node;
		}
		
		p -> next_node = temp;
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
			p = p -> next_node;
		}
	}
	
	return count;
}

void delete_node_in_pos()
{
	
	
	struct node *p = start;
	int count = node_count(), node_num = 0;
	printf("\nEnter Node Number: ");
	scanf("%d", &node_num);
	if (node_num == 1)
	{
		p -> next_node -> prev_node = NULL;
		start = p -> next_node;
	}
	else if (node_num == count)
	{
		
		while (p -> next_node != NULL)
		{
			p = p -> next_node;
		}
		
		p -> prev_node -> next_node = NULL;
	}
	
	else
	{
		for (int i = 1; i < node_num - 1; i++)
		{
			p = p -> next_node;
		}
		p -> next_node = p -> next_node -> next_node;
		p -> next_node -> prev_node = p;
	}
}

void insert_in_pos()
{
	struct node *p = start, *temp;
	temp = (struct node*)malloc(sizeof(struct node));
	
	int item = 0, node_num = 0;
	printf("\nEnter Node Number: ");
	scanf("%d", &node_num);
	
	printf("Input data: ");
	scanf("%d", &item);
	
	temp -> data = item;
	
	if (0 == node_num)
	{
		temp -> prev_node = NULL;
		temp -> next_node = p;
		start = temp;
	}
	else if (node_num == node_count())
	{
		while (p -> next_node != NULL)
		{
			p = p -> next_node;
		}
		temp -> next_node = NULL;
		temp -> prev_node = p;
		p -> next_node = temp;
	}
	else
	{
		for (int i = 1; i < node_num; i++)
		{
			p = p -> next_node;
		}
		temp -> prev_node = p -> prev_node;
		temp -> next_node = p;
		p -> prev_node -> next_node = temp;
		p -> prev_node = temp;
	}
}

void create(int size)
{
	int item0 = 0, item =0;
	struct node *p, *temp;
	p = (struct node*)malloc(sizeof(struct node));
	start = p;
	printf("Input data: ");
	scanf("%d", &item0);
	
	p -> prev_node = NULL;
	p -> data = item0;
	p -> next_node = NULL;
	
	for (int i = 1; i < size; i++)
	{
		temp = p;

		p -> next_node = (struct node*)malloc(sizeof(struct node));
		p = p -> next_node;
		
		printf("Input data: ");
		scanf("%d", &item);
		
		p -> prev_node = temp;
		p -> data = item;
		p -> next_node = NULL;
	}
}

void display()
{
	struct node *p = start;
	
	if (p == NULL)
	{
		printf("No node exist.");
	}
	else
	{
		printf("\nNULL --> ");
		while (p != NULL)
		{
			printf("%d --> ", p -> data);
			p = p -> next_node;
		}
		printf("NULL\n");
	}
}

int main()
{
	int no_of_nodes = 0, choose = -999999, loop_exit = -1;
		
	printf("Enter number of nodes: ");
	scanf("%d", &no_of_nodes);
		
	create(no_of_nodes);
		
	while(loop_exit != 0)
	{
		printf("\n---------------------------------------------------\n");
		printf("\nChoose the given options: \n");
		printf("1. INSERT AT BEGINNING\n");
		printf("2. INSERT AT END\n");
		printf("3. INSERT IN BETWEEN AT A GIVEN POSITION\n");
		printf("4. DELETE A NODE WITH A GIVEN POS\n");
		printf("5. DISPLAY\n");
		printf("0. EXIT\n");
		printf("\n");
		printf("Choose: ");
		scanf("%d", &choose);
		
		switch(choose)
		{
			case 0:		loop_exit = 0;
						break;
			case 1:		insert_beg();
						break;
			case 2:		insert_end();
						break;
			case 3:		insert_in_pos();
						break;
			case 4:		delete_node_in_pos();
						break;
			case 5:		display();
						break;
			
			default:	printf("\nInvalid input\n");	
		}	
	}
	
	return 0;
}
