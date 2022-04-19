#include<stdio.h>

void bin_search(int*, int, int, int);

int main()
{
    int arr_size = 0;

    printf("Enter array size: ");
    scanf("%d", &arr_size);

    int arr[arr_size];
    printf("Enter sorted array: \n");
    for (int i = 0; i < arr_size; i++)
    {
        scanf("%d", &arr[i]);
    }

    int search_element = 0;
    printf("\nEnter element to search: ");
    scanf("%d", &search_element);

    bin_search(arr, 0, arr_size-1, search_element);
    return 0;
}

void bin_search(int arr[], int left, int right, int s_element)
{   
    if (left == right)
    {
        if (s_element == arr[left])
        {
            printf("Element available on index: %d", left);
        }
        else{
            printf("Element not available in the array.");
        }
    }
    else
    {
        int mid = (left+right) / 2;

        if (s_element <= arr[mid])
        {
            bin_search(arr, left, mid, s_element);
        }
        else{
            bin_search(arr, mid+1, right, s_element);
        }
    }
}