#include <stdio.h>

#define INF 99999

int min(int a, int b) {
    return a > b ? b : a;
}

int max(int a, int b) {
    return a > b ? a : b;
}

int main() {
    int n, m, src, dest, sp_len;
    int matrix[101][101];
    scanf("%d%d", &n, &m);

    // 初始化矩阵
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            if (i == j)
                matrix[i][j] = 0;
            else
                matrix[i][j] = INF;

    // 加载基本动物变化所需咒语长度
    for (int i = 0; i < m; i++) {
        scanf("%d %d %d", &src, &dest, &sp_len);
        matrix[src][dest] = matrix[dest][src] = sp_len;
    }

    // 根据基本规则，计算所有动物变化所需咒语长度
    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                matrix[i][j] = min(matrix[i][j], matrix[i][k] + matrix[k][j]);

    // 获取每只动物变化所需的最大咒语长度
    int max_len = INF, num = 0, impossible = 0;
    for (int i = 1; i <= n; i++) {
        int len = 0;
        for (int j = 1; j <= n; j++) {
            if (matrix[i][j] == INF) {
                impossible = 1;
                break;
            } else
                len = max(matrix[i][j], len);
        }

        if (len < max_len) {
            max_len = len;
            num = i;
        }
    }

    if (impossible)
        printf("0\n");
    else
        printf("%d %d\n", num, max_len);

    return 0;
}
