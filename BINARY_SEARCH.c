#include<stdio.h>
#define MAX 100
void bin_search(int arr[], int left, int right, int item)
{
	int mid = (left+right)/2 ;
	
	if (left > right)
	{
		printf("The item does not exist.");
	}
	else
	{
		if (arr[mid] == item)
		{
			printf("%d is located at pos %d", item, mid);
		}
		else if (item < arr[mid])
		{
			bin_search(arr, left, mid-1, item);
		}
		else if (item > arr[mid])
		{
			bin_search(arr, mid+1, right, item);
		}
	}
}

int main()
{
	int arr[MAX], size = 0, search_data = 0;
	printf("Enter size of array: ");
	scanf("%d", &size);
	
	for (int i = 0; i < size; i++)
	{
		scanf("%d", &arr[i]);
	}
	printf("Enter data to be searched: ");
	scanf("%d", &search_data);
	bin_search(arr, 0, size-1, search_data);
	
	return 0;
}
