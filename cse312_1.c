#include <stdio.h>

void waitingTime(int p[], int n, int b[], int w[]) {
    w[0] = 0;
    for (int i = 1; i < n; i++) {
        w[i] = b[i - 1] + w[i - 1];
    }
}

void turnTime(int p[], int n, int b[], int w[], int t[]) {
    for (int i = 0; i < n; i++) {
        t[i] = b[i] + w[i];
    }
}

void printAll(int p[], int b[], int w[], int n, int t[]) {
    printf("P\tBT\tWT\tTT\n");

    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t%d\t%d\n", p[i], b[i], w[i], t[i]);
    }
}

void avgTime(int p[], int n, int b[]) {
    int t_w = 0, t_t = 0, w_t[n], tat[n];

    waitingTime(p, n, b, w_t);
    turnTime(p, n, b, w_t, tat);

    for (int i = 0; i < n; i++) {
        t_w = t_w + w_t[i];
        t_t = t_t + tat[i];
    }

    printf("P\tBT\tWT\tTT\n");

    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t%d\t%d\n", p[i], b[i], w_t[i], tat[i]);
    }

    printf("Average Waiting Time: %.2f\n", (float)t_w / n);
    printf("Average Turnaround Time: %.2f\n", (float)t_t / n);
}

int main() {
    int process[] = {1, 2, 3};
    int n = sizeof(process) / sizeof(process[0]);

    int burst_time[] = {10, 5, 8};

    avgTime(process, n, burst_time);

    return 0;
}
