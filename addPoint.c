#include <stdio.h>

typedef struct {
    float x, y;
} Point;

Point addPoints(Point a, Point b) {
    return (Point){a.x + b.x, a.y + b.y};
}

int main(void) {
    Point result = addPoints(
        (Point){.x = 10, .y = 20},
        (Point){.x = 5, .y = 7}
    );
    printf("Point: (%.3f, %.3f)\n", result.x, result.y);

    return 0;
}
