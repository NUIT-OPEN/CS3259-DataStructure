#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
    int x;
    int y;
    double r;
} PointS, *Point;

typedef struct {
    Point *points;
    int size;
    int **matrix;
} MapS, *Map;

Map new_map(int size) {
    Map m = malloc(sizeof(MapS));
    m->size = size;
    m->points = malloc(sizeof(Point) * size);
    m->matrix = malloc(sizeof(int *) * size);
    for (int i = 0; i < size; ++i) {
        m->matrix[i] = malloc(sizeof(int) * size);
    }
    return m;
}

Point new_point(int x, int y, double r) {
    Point p = malloc(sizeof(PointS));
    p->x = x;
    p->y = y;
    p->r = r;
    return p;
}

void set_point(Map m, int i, Point p) {
    m->points[i] = p;
}

int check_jump(Point p1, Point p2, int d) {
    return (sqrt(pow(p1->x - p2->x, 2) + pow(p1->y - p2->y, 2)) - (p1->r + p2->r)) <= d;
}

void update_matrix(Map m, int d) {
    for (int i = 0; i < m->size; ++i) {
        for (int j = 0; j < m->size; ++j) {
            m->matrix[i][j] = check_jump(m->points[i], m->points[j], d);
        }
    }
}

int check_clear(Point p, int d) {
    d += p->r;
    return (p->x + d) >= 50 || (p->x - d) <= -50 || (p->y + d) >= 50 || (p->y - d) <= -50;
}

int check_go_out(Map map, int d, int start) {
    Point sp = map->points[start];
    if (check_clear(sp, d))
        return 1;

    int flag = 0;
    for (int i = 0; i < map->size; ++i) {
        if (map->matrix[start][i]) {
            map->matrix[i][start] = 0;
            flag = check_go_out(map, d, i);
            map->matrix[i][start] = 1;
        }

        if (flag) {
            break;
        }
    }

    return flag;
}

int main() {
    int n, d;
    scanf("%d %d", &n, &d);

    Map map = new_map(n + 1);
    int x, y;
    for (int i = 0; i < n; ++i) {
        scanf("%d %d", &x, &y);
        set_point(map, i, new_point(x, y, 0));
    }
    set_point(map, n, new_point(0, 0, 7.5));
    update_matrix(map, d);

    printf(check_go_out(map, d, n) ? "Yes" : "No");
    printf("\n");
    return 0;
}
