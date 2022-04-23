#include<stdio.h>
#include<malloc.h>

struct node{
	int data;
	struct node *next;
};

struct node *start = NULL;

void create(int);
void insert_beg();
void insert_end();
void disp(struct node*);
void insert_bw();
void insert_after_node();
int node_count();
void delete_node();
void delete_node_first();
void delete_node_last();
void disp_rev(struct node*);
// void disp_rev();

// struct node* allocate_mem(struct node *x)
// {
// 	x = (struct node*)malloc(sizeof(struct node));
// 	return x;
// }

void main()
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
		printf("4. INSERT IN BETWEEN AFTER A GIVEN NODE\n");
		printf("5. COUNT THE NUMBER OF THE NODE\n");
		printf("6. DELETE A NODE WITH A GIVEN VALUE\n");
		printf("7. DELETE FIRST NODE\n");
		printf("8. DELETE LAST NODE\n");
		printf("9. REVERSE THE LIST\n");
		printf("10. DISPLAY\n");
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
			case 3:		insert_bw();
						break;
			case 4:		insert_after_node();
						break;
			case 5:		printf("No of nodes: %d", node_count());
						break;
			case 6:		delete_node();
						break;
			case 7:		delete_node_first();
						break;
			case 8:		delete_node_last();
						break;
			case 9:		disp_rev(start);
						break;
			case 10:	disp(start);
						break;
			
			default:	printf("\nInvalid input\n");	
		}	
	}
}

void create(int no_of_nodes)
{
	struct node *p;
	p = (struct node*)malloc(sizeof(struct node));
	//allocate_mem(p);
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

void insert_beg()
{
	struct node *temp;
	int item = 0;
	temp = (struct node*)malloc(sizeof(struct node));
	printf("Enter the data: ");
	scanf("%d", &item);
	
	temp -> data = item;
	temp -> next = start;
	start = temp;
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

void insert_bw()
{
	struct node *p = start, *temp;
	temp = (struct node*)malloc(sizeof(struct node));
	
	int item = 0, node_num = 0;
	
	printf("Enter node number: ");
	scanf("%d", &node_num);
	
	printf("Enter the data: ");
	scanf("%d", &item);
	
	temp -> data = item;
	
	for (int i = 1; i < node_num - 1; i++)
	{
		p = p -> next;
	}
	
	temp -> next = p -> next;
	p -> next = temp;
}

void insert_after_node()
{
	struct node *p = start, *temp;
	temp = (struct node*)malloc(sizeof(struct node));
	
	int item = 0, node_num = 0;
	
	printf("Enter node number: ");
	scanf("%d", &node_num);
	
	printf("Enter the data: ");
	scanf("%d", &item);
	
	temp -> data = item;
	
	for (int i = 1; i < node_num; i++)
	{
		p = p -> next;
	}
	
	temp -> next = p -> next;
	p -> next = temp;
}

void delete_node()
{
	int node_num = 0;
	struct node *p = start, *temp;
	printf("Enter node number: ");
	scanf("%d", &node_num);
	if (node_num == 1){
		delete_node_first();
	}
	else
	{
		for (int i = 1; i < node_num - 1; i++)
		{
			p = p -> next;
		}
		temp = p -> next;
		p -> next = (p -> next) -> next;

		free(temp);
	}
}

void delete_node_first()
{
	struct node *p = start;
	start = p -> next;
	free(p);
}

void delete_node_last()
{
	struct node *p = start, *temp;
	int no_of_nodes = node_count();
	if (no_of_nodes == 1)
	{
		delete_node_first();
		return;
	}
	for (int i = 1; i < no_of_nodes-1; i++)
	{
		p = p -> next;
	}
	temp = p -> next;
	p -> next = NULL;

	free(temp);
}

// void disp()															// printing link list
// {
// 	struct node *p = start;
// 	if (p == NULL)
// 	{
// 		printf("No link list found.");
// 	}
// 	else
// 	{
// 		while(p != NULL)
// 		{
// 			printf("%d --> ", p -> data);
// 			p = p -> next;
// 		}
// 		printf("NULL");
// 	}
// }

void disp(struct node *p)													// recursion of printing link list
{
	if (p == NULL){
		printf("NULL");
		return;
	}
	printf("%d --> ", p->data);
	disp(p->next);
}

// void disp_rev(struct node *p)											// printing link list in reverse order
// {
// 	if (p == NULL){
// 		printf("NULL");
// 		return;
// 	}
// 	disp_rev(p->next);
// 	printf(" <-- %d", p->data);
	
// }

// void disp_rev()
// {
// 	int node_num = node_count();
// 	struct node *p;
// 	printf("NULL ");
// 	for (int i = 1; i <= node_num; i++)
// 	{
// 		p = start;
// 		for (int j = 1; j <= node_num - i; j++)
// 		{
// 			p = p -> next;
// 		}
// 		printf("<-- %d ", p -> data);	
// 	}
// }

// void disp_rev()																// iteration of reverse link list
// {
// 	struct node *p = start, *prev = NULL, *next = NULL;
// 	while (p != NULL)
// 	{
// 		next = p -> next;
// 		p -> next = prev;
// 		prev = p;
// 		p = next;
// 	}

// 	start = prev;
// }

void disp_rev(struct node *p)													// recursion of reverse link list
{
	if (p->next == NULL)
	{
		start = p;
		return;
	}
	disp_rev(p->next);

	struct node *q = p->next;
	q -> next = p;
	p -> next = NULL;
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
