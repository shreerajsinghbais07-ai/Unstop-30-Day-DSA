#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    int arr[n];
    
    for(int i=0; i<n; i++) {
        scanf("%d", &arr[i]);
    }
    
    int write_idx = 0;
    for (int i=0; i<n; i++) {
        if (arr[i] != 0) {
            arr[write_idx] = arr[i];
            write_idx++;
        }
    }
    
    while (write_idx < n) {
        arr[write_idx] = 0;
        write_idx++;
    }
    
    for (int i=0; i<n; i++) {
        // Added a space after %d right here:
        printf("%d ", arr[i]); 
    }
    printf("\n");
    
    return 0;
}
