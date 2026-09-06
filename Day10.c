// Helper function to simulate backspaces in-place
void processString(char* str) {
    int write_idx = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] != '#') {
            str[write_idx++] = str[i];
        } else if (write_idx > 0) {
            write_idx--; // Erase the previous character
        }
    }
    str[write_idx] = '\0'; // Terminate the new string
}

int userLogic(char bob[], char alice[]) {
    processString(bob);
    processString(alice);
    
    // strcmp returns 0 if strings are identical
    if (strcmp(bob, alice) == 0) {
        return 1;
    }
    return 0;
}
