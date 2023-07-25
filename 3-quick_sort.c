# include "sort.h"

void partition(int *array, size_t lb, size_t ub, size_t size)
{
	int pivot = array[lb], temp;
	size_t start = lb;
	size_t end = ub;

	if(lb == ub)
		return;
	while (start < end)
	{
		while (array[start] <= pivot)
			start++;
		while (array[end] > pivot)
			end--;

		if (start < end)
		{
			temp = array[end];
			array[end] = array[start];
			array[start] = temp;
			print_array(array, size);
		}
	}
	array[lb] = array[end];
	array[end] = pivot;
	print_array(array, size);
	
	if (end > lb + 1)
		partition(array, lb, end - 1, size);
	if (end + 1 < ub)
		partition(array, end + 1, ub, size);

}
void quick_sort(int *array, size_t size)
{
	partition(array, 0, (size - 1), size);
}
