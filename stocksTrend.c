#include<stdio.h>
#include<stdlib.h>


int main(int argc, char const *argv[])
{
	/* code */

	int n;

	printf("Enter the value of n : ");
	scanf("%d",&n);

	int *arr = (int *)malloc(sizeof(int)*n);

	for(int i=0;i<n;i++)
	{
		int ele;
		printf("Enter element number%d : ",(i+1));
		scanf("%d",&ele);

		arr[i] = ele;
	
	}

	int *min_arr = (int *)malloc(sizeof(int)*n);

	min_arr[0] = 0;

	for(int i=1;i<n;i++)
	{
		if(arr[i]<arr[min_arr[i-1]])
		{
			min_arr[i] = i;
		}
		else
		{
			min_arr[i] = min_arr[i-1];
		}
	}

	int min_pos,max_pos,diff;

	diff = INT_MIN;

	for(int i=0;i<n;i++)
	{
		int d = arr[i] - arr[min_arr[i]];

		if(d > diff)
		{
			diff = d;
			min_pos = min_arr[i];
			max_pos = i;
		}
	} 

	printf("Buy at %d and sell at %d\n",min_pos,max_pos);
	return 0;
}