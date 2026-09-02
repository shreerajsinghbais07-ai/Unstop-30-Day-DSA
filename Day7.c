#include <stdio.h>
#include <stdbool.h>

// Helper function to calculate the sum of the squares of digits
int sum_of_squares(int n) {
    int sum = 0;
    while (n > 0) {
        int digit = n % 10;
        sum += digit * digit;
        n /= 10;
    }
    return sum;
}

bool is_happy_number(int n) {
    int slow = n;
    int fast = n;

    // Fast pointer moves 2 steps, slow moves 1 step
    do {
        slow = sum_of_squares(slow);
        fast = sum_of_squares(sum_of_squares(fast));
    } while (slow != fast && fast != 1);

    // If it broke the loop because it reached 1, it's happy.
    return fast == 1;
}

int main() {
    int n;
    scanf("%d", &n);

    bool result = is_happy_number(n);
    printf(result ? "true\n" : "false\n");

    return 0;
}
