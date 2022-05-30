#include<stdio.h>

int max(int d[], int size)
{
    int max_v = -1;
    
    for (int i = 0; i < size; i++)
    {
        if (max_v < d[i])
        {
            max_v = d[i];
        }
    }

    return max_v;
}

void bub_srt(int p[], int d[], int size)
{
    int temp = 0;
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - 1 - i; j++)
        {
            if (p[j] < p[j+1])
            {
                temp = p[j];
                p[j] = p[j+1];
                p[j+1] = temp;

                temp = d[j];
                d[j] = d[j+1];
                d[j+1] = temp;
            }
        }
    }
}

int main()
{
    int size = 0;

    printf("Enter total number of jobs: ");
    scanf("%d", &size);

    int p[size], d[size];

    for (int i = 0; i < size; i++)
    {
        printf("Enter Job %d :-\nProfit: ", i+1);
        scanf("%d", &p[i]);
        printf("Deadline: ");
        scanf("%d", &d[i]);
        printf("\n");
    }

    // int p_bkp[size], d_bkp[size];

    // for (int i = 0; i < size; i++)
    // {
    //     p_bkp[i] = p[i];
    //     d_bkp[i] = d[i];
    // }

    int max_d = max(d, size);
    int deadl[max_d];
    
    for (int i = 0; i < max_d; i++)
        deadl[i] = 0;

    bub_srt(p, d, size);
    int job_i = 0, deadl_i = 0, count = 0;
    
    while (count != max_d && job_i != size)
    {
        deadl_i = d[job_i] - 1;
        while (deadl_i != -1)
        {
            if (deadl[deadl_i] == 0)
            {
                deadl[deadl_i] = p[job_i];
                count++;
                break;
            }
            deadl_i--;
        }
        job_i++;
    }
    
    int n_profit = 0;

    for (int k = 0; k < max_d; k++)
       n_profit = n_profit + deadl[k];

    printf("Net Profit is: %d", n_profit);
}