#include <stdio.h>

void timGiaTriLonNhatVaDiaChi(int arr[], int n, int *max_value, int *max_index) {
    *max_value = arr[0]; 
    *max_index = 0;      
    for (int i = 1; i < n; ++i) {
        if (arr[i] > *max_value) {
            *max_value = arr[i];
            *max_index = i;      
        }
    }
}

int main() {
    int arr[] = {10, 5, 7, 15, 20, 3};
    int n = sizeof(arr) / sizeof(arr[0]);
    int max_value, max_index;
    timGiaTriLonNhatVaDiaChi(arr, n, &max_value, &max_index);
    printf("Gia tri lon nhat trong mang la: %d\n", max_value);
    printf("Dia chi cua gia tri lon nhat trong mang la: %p\n", (void *)&arr[max_index]);

    return 0;
}
