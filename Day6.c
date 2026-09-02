#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    // Use long long to prevent integer overflow during calculation
    long long val = 1; 
    
    for (int i = 0; i <= n; i++) {
        printf("%lld ", val);
        
        // Calculate the next value in the row using the current value
        val = val * (n - i) / (i + 1);
    }
    
    printf("\n");
    return 0;
}
