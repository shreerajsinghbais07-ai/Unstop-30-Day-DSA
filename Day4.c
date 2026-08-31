#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int val;
    struct Node* next;
} Node;

// Your Logic Function
Node* user_logic(Node* head) {
    // If the list is empty, just return
    if (head == NULL) {
        return NULL;
    }

    Node* current = head;

    // Traverse until we reach the last node
    while (current->next != NULL) {
        if (current->val == current->next->val) {
            // Duplicate found: Bypass the next node
            Node* temp = current->next;
            current->next = current->next->next;
            free(temp); // Free the memory of the skipped node
        } else {
            // No duplicate: Move pointer forward
            current = current->next;
        }
    }
    
    return head;
}

// Unstop's Boilerplate Main Function
int main() {
    int n;
    scanf("%d", &n);
    if (n == 0) {
        printf("0\n");
        return 0;
    }

    Node* head = NULL;
    Node* current = NULL;
    for (int i = 0; i < n; ++i) {
        int val;
        scanf("%d", &val);
        Node* new_node = (Node*)malloc(sizeof(Node));
        new_node->val = val;
        new_node->next = NULL;
        if (i == 0) {
            head = new_node;
            current = head;
        } else {
            current->next = new_node;
            current = current->next;
        }
    }

    Node* updated_head = user_logic(head);

    if (!updated_head) {
        printf("0\n");
    } else {
        int count = 0;
        current = updated_head;
        while (current) {
            ++count;
            current = current->next;
        }
        printf("%d\n", count);
        current = updated_head;
        while (current) {
            printf("%d ", current->val);
            current = current->next;
        }
        printf("\n");
    }
    return 0;
}
