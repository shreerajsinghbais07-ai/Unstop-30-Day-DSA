#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, k;
    
    // Read n and k
    scanf("%d %d", &n, &k);
    
    // Dynamically allocate memory for a string of size 10^6 + 1 (for the null terminator)
    char* str = (char*)malloc((n + 1) * sizeof(char));
    
    // Read the string
    scanf("%s", str);
    
    // Apply the O(1) math trick to find the target index
    int target_index = n - k;
    
    // Print the single character
    printf("%c\n", str[target_index]);
    
    // Free the allocated memory
    free(str);
    
    return 0;
}
