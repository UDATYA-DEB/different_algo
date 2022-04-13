#include<stdio.h>
#define MAX 100

int lin_search(int*, int, int);

int main()
{
	int arr[MAX], size = 0, search_data = 0, pos = 0;
	printf("Enter size of array: ");
	scanf("%d", &size);
	
	for (int i = 0; i < size; i++)
	{
		scanf("%d", &arr[i]);
	}
	printf("Enter data to be searched: ");
	scanf("%d", &search_data);
	pos = lin_search(arr, size, search_data);
	
	if (pos != -1)
	{
		printf("The data exist on pos %d", pos);	
	}	
}

int lin_search(int arr[], int size, int item)
{
	for (int i = 0; i < size; i++)
	{
		if (arr[i] == item)
		{
			return i;
		}
	}
	
	printf("The data does not exist.");
	
	return -1;
}
