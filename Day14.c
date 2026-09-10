#include <stdio.h>
#include <stdlib.h>

int user_logic(int n, int* arr) {
    long long MOD = 1000000007;
    
    // 1. Calculate the sum of all original indices in O(1) time
    long long original_sum = (1LL * n * (n - 1) / 2) % MOD;
    
    // 2. Find the maximum value to size our frequency array efficiently
    int max_val = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] > max_val) {
            max_val = arr[i];
        }
    }
    
    // 3. Populate the frequency array
    int* freq = (int*)calloc(max_val + 1, sizeof(int));
    for (int i = 0; i < n; i++) {
        freq[arr[i]]++;
    }
    
    // 4. Calculate the sum of last occurrences
    long long last_occ_sum = 0;
    long long elements_before = 0;
    
    for (int i = 0; i <= max_val; i++) {
        if (freq[i] > 0) {
            long long last_index = elements_before + freq[i] - 1;
            long long contribution = ((last_index % MOD) * (freq[i] % MOD)) % MOD;
            
            last_occ_sum = (last_occ_sum + contribution) % MOD;
            elements_before += freq[i];
        }
    }
    
    free(freq);
    
    // 5. Combine and apply final modulo
    long long total_measurement = (original_sum + last_occ_sum) % MOD;
    return (int)total_measurement;
}

int main() {
    int n;
    if (scanf("%d", &n) != 1) return 0;
    
    // Use malloc to prevent stack overflow on N = 10^6
    int *arr = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    int measurement = user_logic(n, arr);
    printf("%d\n", measurement);
    
    free(arr);
    return 0;
}
