#include<stdio.h>


void waitingTime(int n, int pro[], int b[], int pri[], int w[]){

    for(int i= 0; i<n-1; i++){
        for(int j=0; j<n-i-1; j++){
            if(pri[j]>pri[j+1]){
                int temp = pri[j];
                pri[j]=pri[j+1];
                pri[j+1]=temp;

                temp = pro[j];
                pro[j]=pro[j+1];
                pro[j+1]=temp;

                temp=b[j];
                b[j]=b[j+1];
                b[j+1]=temp;
            }
        }
    }

    w[0] = 0;

    for(int i=1; i<n; i++){
        w[i] = b[i-1] + w[i-1];
    }

}

void turnaroundTime(int n, int pro[], int b[], int pri, int w[], int t[]){

    for(int i=0; i<n; i++){
        t[i] = b[i] + w[i];
    }

}

void avgTime(int n, int pro[], int b[], int pri[]){

    int t_w = 0, t_t = 0, w_t[n], t_a_t[n];

    waitingTime(n,pro,b,pri,w_t);
    turnaroundTime(n,pro,b,pri,w_t,t_a_t);

    for(int i=0; i<n; i++){
        t_w=t_w+w_t[i];
        t_t=t_t+t_a_t[i];
    }

    printf("P\Pri\tBT\tWT\tTT\n");

    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t%d\t%d\t%d\n", pro[i], pri[i], b[i], w_t[i], t_a_t[i]);
    }

    printf("Average Waiting Time: %.2f\nAverage Turn Around Time: %.2f",(float)t_w/n,(float)t_t/n);

}

int main(){


    int n;
    printf("Please Enter the Number of Processes: ");
    scanf("%d",&n);
    int pro[n];
    int b[n];
    int pri[n];

    printf("Enter the process Id, burst time, and priority respectively: ");
    for(int i=0; i<n; i++){
        scanf("%d %d %d",&pro[i], &b[i], &pri[i]);
    }

    avgTime(n,pro,b,pri);



return 0;
}
