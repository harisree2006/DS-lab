#include <stdio.h>

void read_array(int, int[]);
void search(int, int[], int);

void main()
{
    int n, key;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[10];
    read_array(n, arr);

    printf("Enter the key to be searched: ");
    scanf("%d", &key);

    search(n, arr, key);
}

void read_array(int n, int arr[])
{
    int i;
    printf("Enter the elements:\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
}

void search(int n, int arr[], int key)
{
    int i, found = 0;
    for (i = 0; i < n; i++)
    {
        if (arr[i] == key)
        {
            printf("Key found at position: %d\n", i + 1);
            found = 1;
            break;
        }
    }

    if (!found)
        printf("Key not found\n");
}
