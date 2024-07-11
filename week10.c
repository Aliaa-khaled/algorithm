#include <stdio.h>

int sum_array(int arr[], int size)
{
    if (size == 0)
    {
        return 0;
    }
    return arr[size- 1] + sum_array(arr, size - 1);
}
int count_items(int arr[], int size)
{
    if (size == 0)
    {
        return 0;
    }
    return 1 + count_items(arr, size - 1);
}

int find_max(int arr[], int size)
{
    if (size == 1)
    {
        return arr[0];
    }
    int max_array = find_max(arr, size - 1);
    return (arr[size - 1] > max_array) ? arr[size - 1] : max_array;
}


int main() {
    int arr[] = {3, 7, 8, 10, 1, 2, 10};
    int size = sizeof(arr) / sizeof(arr[0]);

    printf("Sum of array elements: %d\n", sum_array(arr, size));
    printf("Number of items in the array: %d\n", count_items(arr, size));
    printf("Maximum number in the array: %d\n",find_max(arr, size));

}
