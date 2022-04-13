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
	
	for (int i = 1; i < size; i++)
	{
		int temp = arr[i];
		int j = i - 1;
		
		while (temp < arr[j] && j >= 0)
		{
			arr[j+1] = arr[j];
			j -= 1;
		}
		arr[j+1] = temp;
	}
	
	for (int i = 0; i < size; i++)
	{
		printf("%d ", arr[i]);
	}
	
	return 0;
}
