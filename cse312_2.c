#include <stdio.h>

void waitingTime(int p[], int n, int b[], int w[]) {

    //sorting(p,b,n);

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (b[j] > b[j + 1]) {
                int tempB = b[j];
                b[j] = b[j + 1];
                b[j + 1] = tempB;

                int tempP = p[j];
                p[j] = p[j + 1];
                p[j + 1] = tempP;
            }
        }
    }

    w[0] = 0;
    for (int i = 1; i < n; i++) {

        w[i] = b[i - 1] + w[i - 1];
    }
}

void sorting(int p[],int b[], int n){
    for(int j=0; j<n-1; j++){
        for(int i=0; i<n-j-1; i++){
        if(b[i]>b[i+1]){
            int temp = b[i+1];
            b[i+1] = b[i];
            b[i+1] = temp;
            int tempP = p[i+1];
            p[i+1] = p[i];
            p[i] = tempP;
        }
    }
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

    //printAll(p, b, w_t, n, tat);
    printf("P\tBT\tWT\tTT\n");

    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t%d\t%d\n", p[i], b[i], w_t[i], tat[i]);
    }

    printf("Average Waiting Time: %.2f\n", (float)t_w / n);
    printf("Average Turnaround Time: %.2f\n", (float)t_t / n);
}

int main() {
    //int process[] = {1, 2, 3};
    //int n = sizeof(process) / sizeof(process[0]);

    //int burst_time[] = {10, 5, 8};


    int n=0;
    printf("Please Enter Number Of Processes: ");
    scanf("%d",&n);
    printf("Enter Processes Id & Burst Time: ");
    int process[n];
    int burst_time[n];

    for(int i=0; i<n; i++){
        scanf("%d %d",&process[i],&burst_time[i]);
    }

    avgTime(process, n, burst_time);

    return 0;
}
