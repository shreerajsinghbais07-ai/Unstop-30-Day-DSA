struct ListNode* middleNode(struct ListNode* head) {
    if (head == NULL) return NULL;
    
    // Step 1: Tally the frequencies of each value (0 to 100)
    int counts[105] = {0};
    int total_nodes = 0;
    
    struct ListNode* current = head;
    while (current != NULL) {
        counts[current->val]++;
        total_nodes++;
        current = current->next;
    }
    
    // Step 2: Overwrite the linked list with sorted values
    current = head;
    for (int i = 0; i <= 100; i++) {
        while (counts[i] > 0) {
            current->val = i;
            counts[i]--;
            current = current->next;
        }
    }
    
    // Step 3: Find the exact middle node mathematically
    int target_index = (total_nodes - 1) / 2;
    
    current = head;
    for (int i = 0; i < target_index; i++) {
        current = current->next;
    }
    
    return current;
}
