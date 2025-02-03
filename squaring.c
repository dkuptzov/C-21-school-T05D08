#include <stdio.h>
#define NMAX 10

int input(int *a, int *n);
void output(int *a, int n);
void squaring(int *a, int n);

int main() {
    int n, data[NMAX];
    int error = input(data, &n);
    if (error == 1) {
        printf("n/a");
    } else {
        squaring(data, n);
        output(data, n);
    }

    return 0;
}

int input(int *a, int *n) {
    if (!scanf("%d", n) || (*n > 10) || (*n <= 0)) {
        return 1;
    }
    for (int *p = a; p - a < *n; p++) {
        if (!scanf("%d", p)) {
            return 1;
        }
    }
    return 0;
}

void output(int *a, int n) {
    for (int i = 0; i < n - 1; ++i) {
        printf("%d ", a[i]);
    }
    printf("%d", a[n - 1]);
}

void squaring(int *a, int n) {
    for (int i = 0; i < n; ++i) {
        a[i] = a[i] * a[i];
    }
}
