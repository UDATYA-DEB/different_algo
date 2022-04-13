#include<stdio.h>
#define MAX 100

int main()
{
	int arr[MAX], size = 0;
	
	printf("Enter size of array: ");
	scanf("%d", &size);
	
	for (int i = 0; i < size; i++)
	{
		scanf("%d", &arr[i]);
	}
	printf("Initial array:-\n");
	for (int i = 0; i < size; i++)
	{
		printf("%d ", arr[i]);
	}
	
	for (int i = 0; i < size-1; i++)
	{
		for (int j = 0; j < size-1-i; j++)
		{
			if (arr[j] > arr[j+1])
			{
				int temp = arr[j+1];
				arr[j+1] = arr[j];
				arr[j] = temp;
			}
		}
	}
	printf("\nFinal Array:-");
	for (int i = 0; i < size; i++)
	{
		printf("%d ", arr[i]);
	}
	return 0;
}
