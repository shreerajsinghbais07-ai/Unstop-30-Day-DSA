#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    int n, k;
    if (scanf("%d %d", &n, &k) != 2) return 0;

    // Use calloc to initialize the frequency array with zeros
    long long *mod_count = (long long *)calloc(k, sizeof(long long));
    
    // A prefix sum that is already a perfect multiple of k counts as 1 valid run from the very start
    mod_count[0] = 1; 

    long long prefix_sum = 0;
    long long total_runs = 0;

    for (int i = 0; i < n; i++) {
        long long val;
        scanf("%lld", &val);

        prefix_sum += val;

        // Force a mathematically positive modulo in C
        long long mod = (prefix_sum % k + k) % k;

        // Add the number of times we've seen this exact remainder before
        total_runs += mod_count[mod];

        // Tally that we've seen this remainder again
        mod_count[mod]++;
    }

    printf("%lld\n", total_runs);

    free(mod_count);
    return 0;
}
