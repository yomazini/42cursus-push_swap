#include <stdio.h>

//TODO: must finish
/*

Bubble sort
insertion sort
merge sort
selection sort

*/

int	*bubble_sort(int *arr, int len)
{
	int i = 0;
	int j = 0;
	int temp;
	while(len - 1 > i)
	{
		j = 0;
		while (j < len - i - 1)
		{
			if(arr[j] > arr[j + 1])
			{
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
			j++;
		}
		i++;
	}
	return (arr);
}

int *insertion_sort(int *arr, int len)
{
	int i = 1;
	int j ;
	int current;
	while (i < len)
	{
		current = arr[i];
		j = i - 1;
		while (j > -1 && current < arr[j])
		{
			arr[j + 1] = arr[j];
			j--;
		}
		arr[j + 1] = current;
		i++;
	}
	return (arr);
}

int main()
{
    int arr[] = {5, 6, 8, 9, 1, 10, 78, 2};
    int len = sizeof(arr) / sizeof(arr[0]); 
    int *buble_sort_arr = bubble_sort(arr, len);
    int *insetion_sort_arr = insertion_sort01(arr ,len);
	int i = 0;
	while (i < len)
	{
		printf("%d\n", insetion_sort_arr[i]);
		i++;
	}
    return 0;
}
