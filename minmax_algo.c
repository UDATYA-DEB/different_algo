#include<stdio.h>

int max = -99999, min = 99999;

void maxmin(int *, int, int);

int main()
{
    int size = 0;
    printf("Enter array size: ");
    scanf("%d", &size);

    int arr[size];

    for (int i = 0; i < size; i++)
    {
        scanf("%d", &arr[i]);
    }

    maxmin(arr, 0, size-1);

    printf("MAX = %d, min = %d\n", max, min);
    
    return 0;
}

void maxmin(int arr[], int l, int h)
{
    int M = 0, m = 0;

    if (l == h)
    {
        M = arr[l];
        m = arr[l];

        max = M > max ? M : max ;
        min = m < min ? m : min ;
    }
    else if (l == h - 1)
    {
        M = arr[h] > arr[l] ? arr[h] : arr[l];
        m = arr[l] > arr[h] ? arr[h] : arr[l];

        max = M > max ? M : max ;
        min = m < min ? m : min ;
    }
    else
    {
        int mid = (h + l) / 2;
        maxmin(arr, l, mid);
        maxmin(arr, mid+1, h);
    }
}
