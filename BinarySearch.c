#include <stdio.h>
#include<time.h>
#define N 100
int binarySearch(int arr[], int low, int high, int x)
{
    if (high >= low) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == x)
            return mid;
        if (arr[mid] > x)
            return binarySearch(arr, low, mid - 1, x);
        return binarySearch(arr, mid + 1, high, x);
    }

    return -1;
}

int main()
{
    clock_t start, end;
    double cpu_time_used;
    start = clock();
    int a[N];
    for(int i=0;i<N;i++){
        scanf("%d",&a[i]);
    }
    int x = 1576858;
    int result = binarySearch(a, 0, N-1, x);
    if (result == -1) printf("Element is not present in array");
    else printf("Element is present at index %d", result);
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Time: ");
    printf("%lf",cpu_time_used);
}
