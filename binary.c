#include <stdio.h>

void read_array(int n, int arr[]);
void print_array(int n, int arr[]);
void search(int key, int arr[], int n);

int main() {
    int n, key;
    int arr[10];

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    printf("Enter elements in sorted order: ");
    read_array(n, arr);

    print_array(n, arr);

    printf("\nEnter the element to search: ");
    scanf("%d", &key);

    search(key, arr, n);

    return 0;
}

void read_array(int n, int arr[]) {
    int i;
    for(i = 0; i < n; i++)
        scanf("%d", &arr[i]);
}

void print_array(int n, int arr[]) {
    int i;
    printf("The array is: ");
    for(i = 0; i < n; i++)
        printf("%d ", arr[i]);
}

void search(int key, int arr[], int n) {
    int low = 0, high = n - 1, mid, found = 0;

    while(low <= high) {
        mid = (low + high) / 2;
        if(arr[mid] == key) {
            found = 1;
            break;
        } else if(key < arr[mid])
            high = mid - 1;
        else
            low = mid + 1;
    }

    if(found == 1)
        printf("\nSearch successful. Key found at position %d.", mid + 1);
    else
        printf("\nSearch unsuccessful. Key not found.");
}
