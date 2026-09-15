#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int word_break(char *s, char **word_dict, int n) {
    int len = strlen(s);
    int *dp = (int *)calloc(len + 1, sizeof(int));
    dp[0] = 1;

    int *dict_lens = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        dict_lens[i] = strlen(word_dict[i]);
    }

    for (int i = 1; i <= len; i++) {
        for (int k = 0; k < n; k++) {
            int wlen = dict_lens[k];
            if (i >= wlen && dp[i - wlen]) {
                if (strncmp(s + (i - wlen), word_dict[k], wlen) == 0) {
                    dp[i] = 1;
                    break;
                }
            }
        }
    }        

    int result = dp[len];
    free(dp);
    free(dict_lens);
    return result;
}

int main() {
    char s[1000];
    if (scanf("%s", s) != 1) return 0;

    int n;
    if (scanf("%d", &n) != 1) return 0;

    char **word_dict = (char **)malloc(n * sizeof(char *));
    for (int i = 0; i < n; i++) {
        word_dict[i] = (char *)malloc(100 * sizeof(char));
        scanf("%s", word_dict[i]);
    }

    int result = word_break(s, word_dict, n);
    printf("%s\n", result ? "true" : "false");

    for (int i = 0; i < n; i++) {
        free(word_dict[i]);
    }
    free(word_dict);

    return 0;
}
