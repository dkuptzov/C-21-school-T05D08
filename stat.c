#include <stdio.h>
#define NMAX 10

int input(int *a, int *n);
void output(int *a, int n);
int max(int const *a, int n);
int min(int const *a, int n);
double mean(int *a, int n);
double variance(int *a, int n);

void output_result(int max_v, int min_v, double mean_v, double variance_v);

int main() {
    int n, data[NMAX];
    int error = input(data, &n);
    if (error == 1) {
        printf("n/a");
    } else {
        output(data, n);
        output_result(max(data, n), min(data, n), mean(data, n), variance(data, n));
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
    printf("%d ", a[n - 1]);
    printf("\n");
}

int max(int const *a, int n) {
    int max = a[0];
    for (int i = 1; i < n; ++i) {
        if (a[i] > max) {
            max = a[i];
        }
    }
    return max;
}

int min(int const *a, int n) {
    int min = a[0];
    for (int i = 1; i < n; ++i) {
        if (a[i] < min) {
            min = a[i];
        }
    }
    return min;
}

double mean(int *a, int n) {
    double mean = ((double)max(a, n) + (double)min(a, n)) / 2.0;
    return mean;
}

double variance(int *a, int n) {
    double mean_v = mean(a, n);
    double x = 0.0;
    for (int i = 0; i < n; ++i) {
        x += (((double)a[i] * (double)a[i]) - (mean_v * mean_v)) / (double)n;
    }
    return x;
}

void output_result(int max_v, int min_v, double mean_v, double variance_v) {
    printf("%d ", max_v);
    printf("%d ", min_v);
    printf("%.6lf ", mean_v);
    printf("%.6lf", variance_v);
}
