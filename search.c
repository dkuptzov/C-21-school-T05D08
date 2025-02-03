/*
    Search module for the desired value from data array.

    Returned value must be:
        - "even"
        - ">= mean"
        - "<= mean + 3 * sqrt(variance)"
        - "!= 0"

        OR

        0
*/

#include <math.h>
#include <stdio.h>
#define NMAX 30

int input(int *a, int *n);
int max(int const *a, int n);
int min(int const *a, int n);
double mean(int *a, int n);
double variance(int *a, int n);

int main() {
    int n, arr[NMAX];
    int error = input(arr, &n);
    if (error == 1) {
        printf("n/a");
        return 0;
    }
    double mean_rez = mean(arr, n);
    double variance_rez = variance(arr, n);
    for (int i = 0; i < n; ++i) {
        if (arr[i] == 0 || arr[i] % 2 != 0 || (double)arr[i] < mean_rez ||
            (double)arr[i] > mean_rez + (3 * sqrt(variance_rez))) {
            continue;
        } else {
            printf("%d", arr[i]);
            break;
        }
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

double mean(int *a, int n) {
    double mean = ((double)max(a, n) + (double)min(a, n)) / 2.0;
    return mean;
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

double variance(int *a, int n) {
    double mean_v = mean(a, n);
    double x = 0.0;
    for (int i = 0; i < n; ++i) {
        x += (((double)a[i] * (double)a[i]) - (mean_v * mean_v)) / (double)n;
    }
    return x;
}
