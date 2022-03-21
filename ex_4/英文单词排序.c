#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define STR_NUM 21
#define STR_LEN 10
typedef char *string;

void swap(string *a, string *b) {
    string t = *a;
    *a = *b;
    *b = t;
}

void select_sort(string *strs, int num) {
    string *min;
    for (int i = 0; i < num; ++i) {
        min = &strs[i];
        for (int j = i; j < num; ++j) {
            if (strlen(strs[j]) < strlen(*min))
                min = &strs[j];
        }
        swap(&strs[i], min);
    }
}

int main() {
    string words[STR_NUM];
    for (int i = 0; i < STR_NUM; ++i)
        words[i] = malloc(sizeof(char) * STR_LEN);

    int n = 0;
    do {
        scanf("%s", words[n++]);
    } while (strcmp(words[n - 1], "#") != 0);
    n--;

    select_sort(words, n);
    for (int i = 0; i < n; ++i) {
        printf("%s ", words[i]);
    }

    return 0;
}
