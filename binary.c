#include <stdio.h>

void read_array(int, int[]);
void search(int, int[], int);

void main()
{
    int a, key;
    printf("Enter the number of elements: ");
    scanf("%d", &a);
    int arr[10];

    read_array(a, arr);

    printf("Enter the key to be searched: ");
    scanf("%d", &key);

    search(a, arr, key);
}

void read_array(int n, int arr[])
{
    int i;
    printf("Enter the elements in ascending order:\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
}

void search(int n, int arr[], int key)
{
    int begin = 0, end = n - 1, mid;
    int found = 0;

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

    if (!found)
        printf("Key not found\n");
}
