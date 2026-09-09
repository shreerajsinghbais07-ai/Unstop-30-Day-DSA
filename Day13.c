// Comparator function to sort in descending order
int compare_desc(const void *a, const void *b) {
    int int_a = *((int*)a);
    int int_b = *((int*)b);
    
    if (int_a == int_b) return 0;
    else if (int_a < int_b) return 1;  // Returns 1 to push smaller numbers down
    else return -1;
}

int find_kth_largest(int* nums, int numsSize, int k) {
    // Sort the array in descending order
    qsort(nums, numsSize, sizeof(int), compare_desc);
    
    // Return the Kth element (subtract 1 because arrays are 0-indexed)
    return nums[k - 1];
}
