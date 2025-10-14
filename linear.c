#include <stdio.h>

void read_array(int n, int arr[]);
void print_array(int n, int arr[]);
void search(int key, int arr[], int n);

int main() {
    int n, key;
    int arr[10];

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    read_array(n, arr);
    print_array(n, arr);

    printf("\nEnter the element to search: ");
    scanf("%d", &key);

    search(key, arr, n);

    return 0;
}

void read_array(int n, int arr[]) {
    int i;
    printf("Enter the elements: ");
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
    int i, found = 0, loc = -1;

    for(i = 0; i < n; i++) {
        if(arr[i] == key) {
            found = 1;
            loc = i;
            break;
        }
    }

    if(found == 0)
        printf("\nSearch unsuccessful. Key not found.");
    else
        printf("\nSearch successful. Key found at position %d.", loc + 1);
}
