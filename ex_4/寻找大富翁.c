#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

void select_sort(int *nums, int num, int count) {
    int *max;
    for (int i = 0; i < num; ++i) {
        if (i >= count)
            break;

        max = &nums[i];
        for (int j = i; j < num; ++j) {
            if (nums[j] > *max)
                max = &nums[j];
        }
        swap(&nums[i], max);
    }
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    int nums[n];
    for (int i = 0; i < n; ++i) {
        scanf("%d", &nums[i]);
    }

    m = n < m ? n : m;
    select_sort(nums, n, m);
    for (int i = 0; i < m; ++i) {
        if (i > 0)
            printf(" ");
        printf("%d", nums[i]);
    }

    return 0;
}
