#include<stdio.h>

void knapsack(int arr_size, int weight[], int profit[], int max_weight)
{
	float net_profit = 0.0;
	int cap = max_weight;

	for (int i = arr_size-1; i >= 0; i--)
	{
		if (weight[i] > cap)
		{
			int temp_cap = cap;
			cap = 0;
			net_profit += (temp_cap * 1.0 / weight[i]) * profit[i]; 
		}
		else
		{
			net_profit += (profit[i] * 1.0);
			cap -= weight[i];
		}
		
	}
	
	printf("\nNet Profit: %f", net_profit);
}

void ratio_sort(int arr_size, int weight[], int profit[], float ratio[])
{  
	float temp;
	int temp_0; 
	for(int i=0 ; i < arr_size-1 ; i++)
	{
		for(int j=0 ; j<arr_size-i-1 ; j++)
		{
			if (ratio[j] > ratio[j+1])
			{
				temp = (ratio[j] * 1.0);
				ratio[j] = (ratio[j+1] * 1.0);
				ratio[j+1] = temp;
				
				temp_0 = profit[j];
				profit[j] = profit[j+1];
				profit[j+1] = temp_0;
				
				temp_0 = weight[j];
				weight[j] = weight[j+1];
				weight[j+1] = temp_0;
			}
		}
	}
}

int main()
{ 
	int arr_size = 0;
	printf("Enter no. of elements: ");
	scanf("%d",&arr_size);
	int weight[arr_size],profit[arr_size];
	float ratio[arr_size];
	int max_weight = 0;
	
	for(int i=0;i<arr_size;i++)
	{
		printf("\nEnter Profit: ");
		scanf("%d",&profit[i]);
		printf("\nEnter Weight: ");
		scanf("%d",&weight[i]);
		
		ratio[i] = (profit[i] * 1.0) / weight[i] ;
	}

	printf("\nEnter Max Weight: ");
	scanf("%d",&max_weight);
	ratio_sort(arr_size, weight, profit, ratio);                                             
	knapsack(arr_size,weight,profit,max_weight);	
	return 0;
}
