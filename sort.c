#include <stdio.h>
#include <stdlib.h>

void read_array(int, int[]);
void print_array(int, int[]);
void bubbleSort(int, int[]);
void insertionSort(int, int[]);
void selectionSort(int, int[]);
int findMin(int, int[], int);

void main()
{
    int n, choice;
    int arr[10];

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    read_array(n, arr);

    do
    {
        printf("\nWhich sorting method would you like to use?\n");
        printf("1. Bubble Sort\n");
        printf("2. Insertion Sort\n");
        printf("3. Selection Sort\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            bubbleSort(n, arr);
            break;

        case 2:
            insertionSort(n, arr);
            break;

        case 3:
            selectionSort(n, arr);
            break;

        case 4:
            exit(0);

        default:
            printf("Invalid choice! Please try again.\n");
        }

    } while (choice != 4);
}

void read_array(int n, int arr[])
{
    int i;
    printf("Enter the elements: ");
    for (i = 0; i < n; i++)
        scanf("%d", &arr[i]);
}

void print_array(int n, int arr[])
{
    int i;
    printf("The sorted array is: ");
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

void bubbleSort(int n, int arr[])
{
    int i, j, temp;
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    print_array(n, arr);
}

void insertionSort(int n, int arr[])
{
    int i, j, key;
    for (i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
    print_array(n, arr);
}


void selectionSort(int n, int arr[])
{
    int i, minLoc, temp;
    for (i = 0; i < n - 1; i++)
    {
        minLoc = findMin(n, arr, i);
        temp = arr[i];
        arr[i] = arr[minLoc];
        arr[minLoc] = temp;
    }
    print_array(n, arr);
}

int findMin(int n, int arr[], int i)
{
    int locMin = i;
    for (int j = i + 1; j < n; j++)
    {
        if (arr[j] < arr[locMin])
            locMin = j;
    }
    return locMin;
}
