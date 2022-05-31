#include<stdio.h>

int min_v (int arr[], int size, int arr_f[], int arr_f_size)
{
    int m = 99999, min_i = 0, skip;
    for (int i = 1; i <= size; i++)
    {
        skip = 0;
        for (int k = 0; k < arr_f_size; k++)
        {
            if (arr_f[k] == i)
            {
                skip = 1;
                break;
            }
        }
        if (skip == 1){
            continue;
        }
        else 
        {
            if (m >= arr[i])
            {
                m = arr[i];
                min_i = i;
            }
        } 
    }

    return min_i;
}

int main()
{
    int tot_v = 0;
    printf("Enter total number of vertices: ");
    scanf("%d", &tot_v);
    int dist_arr[tot_v][tot_v];
    for (int i = 0; i < tot_v; i++)
    {
        for (int j = 0; j < tot_v; j++)
        {
            if (i == j)
                dist_arr[i][j] = 0;
            else
                dist_arr[i][j] = 9999;
        }
    }
    
    printf("Vertices generated: ");
    for (int i = 0; i < tot_v; i++){
        printf(" %d ", i);
    }
    printf("\n");
    int edge_n = 0, exit_v = 0;
    printf("Enter number of edges: ");
    scanf("%d", &edge_n);
    printf("\n");
    int init_v = 0, fin_v = 0, weight = 0;
   
    while (exit_v < edge_n){
        printf("Enter initial vertex: ");
        scanf("%d", &init_v);
        printf("Enter final vertex: ");
        scanf("%d", &fin_v);
        printf("Enter weight: ");
        scanf("%d", &weight);
        dist_arr[init_v][fin_v] = weight;
        exit_v++;
        printf("\n");
    }
    
    int fixed_v[tot_v-1], s_path[tot_v-1], dist_v = 0, v = 0, temp_sum = 0, fix_v_len = 1;
    fixed_v[fix_v_len-1] = 0;
    
    for (int j = 1 ; j < tot_v; j++)
    {
        s_path[j] = dist_arr[v][j] + dist_v;
    }
    v = min_v(s_path, tot_v-1, fixed_v, fix_v_len);
    fix_v_len++;
    fixed_v[fix_v_len-1] = v;
    dist_v = s_path[v];
    
    int skip = 0;
    
    for (int i = 1; i < tot_v; i++)
    {
        for (int j = 1 ; j < tot_v; j++)
        {
            skip = 0;
            for (int k = 0; k < fix_v_len; k++)
            {
                if (fixed_v[k] == j)
                {
                    skip = 1;
                    break;
                }
            }
            if (skip == 1){
                continue;
            }

            else
            {
                temp_sum = dist_arr[v][j] + dist_v;
                if (s_path[j] > temp_sum)
                    s_path[j] = temp_sum;
            }
        }
        v = min_v(s_path, tot_v-1, fixed_v, fix_v_len);
        fix_v_len++;
        fixed_v[fix_v_len-1] = v;
        dist_v = s_path[v];
    }

    printf("\nSingle Pair Shortest Path (using Dijikstra Algo) we get:-\n");
    for (int i = 1; i < tot_v; i++)
    {
        printf("0 - %d -> %d\n", i, s_path[i]);
    }

    return 0;
}
