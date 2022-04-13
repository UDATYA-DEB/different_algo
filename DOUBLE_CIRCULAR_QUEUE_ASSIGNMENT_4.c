#include<stdio.h>

int dqinsert_front(int dq[], int front, int rear, int item)
{
	if (front == 0)
	{
		printf("DQ Underflow");
	}
	else
	{
		front -= 1;
		dq[front] = item;
	}
	return front; 
}

int dqinsert_rear(int dq[], int front, int rear, int size, int item)
{
	if (rear == size - 1)
	{
		printf("DQ Overflow.");
	}
	else
	{
		rear += 1;
		dq[rear] = item;
	}
	return rear;
}

int dqdelete_front(int dq[], int front, int rear, int item)
{
	if (front == rear)
	{
		printf("Element NOT ACCESSIBLE: ");
	}
	else
	{
		item = dq[front];
		front += 1;
	}
	return front;
}

int dqdelete_rear(int dq[], int front, int rear, int item)
{
	if (front == rear)
	{
		printf("Element NOT ACCESSIBLE: ");
	}
	else
	{
		item = dq[rear];
		rear -= 1;
	}
	return rear;
}

void dq_display(int dq[], int front, int rear, int size)
{
	if (front <= rear)
	{
		for (int i = 0; i < front; i++)
		{
			printf("$, ");
		}
		for (int i = front; i <= rear; i++)
		{
			printf("%d, ", dq[i]);
		}
		for (int i = rear + 1; i <size; i++)
		{
			printf("$, ");
		}
	}
	else
	{
		printf("DQ Empty.");
	}
}

int main()
{
	int front = -1, rear = -1, size = 0, item = 0;
	int dq[100];
	
	printf("Enter size of the array: ");
	scanf("%d", &size);
	
	front = size / 2;
	rear = front + 1;
	
	int choice = -1;
	
	while (choice != 4)
	{
		printf("Menu\n");
		printf("1.Insert from FRONT.\n");
		printf("2.Delete from FRONT.\n");
		printf("3.Insert from REAR.\n");
		printf("4.Delete from REAR\n");
		printf("5.Display DEQUE.\n");
		printf("0.EXIT.\n");
		
		
		printf("\nChoice: ");
		scanf("%d", &choice);
		
		switch(choice)
		{
			case 1 : 	printf("Enter item: ");
						scanf("%d", &item);
						front = dqinsert_front(dq, front, rear, item);
						break;
			case 2 : 	front = dqdelete_front(dq, front, rear, item);
						break;
			case 3 : 	printf("Enter item: ");
						scanf("%d", &item);
						rear = dqinsert_rear(dq, front, rear, size, item);
						break;
			case 4 : 	rear = dqdelete_rear(dq, front, rear, item);	
						break;
			case 5 : 	dq_display(dq, front, rear, size);	
						break;	
			case 0 : 	break;
			
			default : printf("Invalid Input.");
						break;
		}	
	}
	
	return 0;
}
