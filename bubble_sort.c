#include<stdio.h>

void bub_sort(int* , int);
void arr_disp(int*, int);

int main()
{
    int arr_size = 0;

    printf("Enter array size: ");
    scanf("%d", &arr_size);

    int arr[arr_size];
    printf("Enter values:- ");

    for (int i = 0; i < arr_size; i++)
    {
        scanf("%d", &arr[i]);
    }

    bub_sort(arr, arr_size);
    printf("Sorted Array:-\n");
    arr_disp(arr, arr_size);

    return 0;
}

void bub_sort(int arr[], int size)
{
    for(int i = 0; i < size-1; i++)
    {
        for (int j = 0; j < size-1-i; j++)
        {
            if (arr[j] > arr[j+1])
            {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

void arr_disp(int arr[], int size)
{
    for(int i = 0; i < size; i++)
    {
        printf("%d, ", arr[i]);
    }
}