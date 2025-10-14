#include <stdio.h>

void read_array(int n, int arr[]);
void binary_search(int arr[], int n, int key);

void main()
{
    int n, key;
    int arr[10];

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    read_array(n, arr);

    printf("Enter the key to be searched: ");
    scanf("%d", &key);

    binary_search(arr, n, key);
}

void read_array(int n, int arr[])
{
    int i;
    printf("Enter the elements in sorted order:\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
}

void binary_search(int arr[], int n, int key)
{
    int begin = 0, end = n - 1, mid, found = 0;

    while (begin <= end)
    {
        mid = (begin + end) / 2;

        if (arr[mid] == key)
        {
            printf("Key found at position: %d\n", mid + 1);
            found = 1;
            break;
        }
        else if (arr[mid] < key)
        {
            begin = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }

    if (found == 0)
        printf("Key not found.\n");
}
