#include <stdio.h>

void find_student_positions(int n, int heights[], int k, int queries[], int results[]) {
    for(int i=0;i<k;i++){
        int target = queries[i];
        int left = 0;
        int right = n;

        while(left<right){
            int mid=left+(right-left)/2;

            // if(heights[mid]==target){
            //     left=mid;
            //     break;
            // }
            if(heights[mid]<target){
                left = mid+1;
            }
            else{
                right=mid;
            }
        }
        results[i]=left;
    }
}

int main() {
    int n, k;
    scanf("%d", &n);
    int heights[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &heights[i]);
    }
    scanf("%d", &k);
    int queries[k];
    for (int i = 0; i < k; i++) {
        scanf("%d", &queries[i]);
    }
    int results[k];
    find_student_positions(n, heights, k, queries, results);
    for (int i = 0; i < k; i++) {
        printf("%d\n", results[i]);
    }
    return 0;
}
