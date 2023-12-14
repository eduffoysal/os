#include<stdio.h>
int waitingTime(int proc[],int n,int burst_time[],int wait_time[],int priority[]){
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(priority[j]>priority[j+1]){

                int temp = priority[j];
                priority[j] = priority[j+1];
                priority[j+1] = temp;

                temp = burst_time[j];
                burst_time[j] = burst_time[j+1];
                burst_time[j+1] = temp;

                temp = proc[j];
                proc[j] = proc[j+1];
                proc[j+1] = temp;
            }
        }
    }
    wait_time[0]=0;
    for(int i=1;i<n;i++){
        wait_time[i] = burst_time[i-1]+wait_time[i-1];
    }
}
int turnaroundTime(int proc[],int n,int burst_time[],int wait_time[],int tat[]){
    for(int i=0;i<n;i++){
        tat[i] = burst_time[i]+wait_time[i];
    }
}

int avgTime(int proc[],int n,int burst_time[],int priority[]){
    int wait_time[n],tat[n],total_wt =0,total_tat = 0;
    waitingTime(proc,n,burst_time,wait_time,priority);
    turnaroundTime(proc,n,burst_time,wait_time,tat);
    for(int i=0;i<n;i++){
        total_wt+=wait_time[i];
        total_tat+=tat[i];
    }
     printf("Process\tB.T\t  Priority\tW.T\tT.A.T\n");
    for(int i=0;i<n;i++){
        printf("%d\t%d\t\t%d\t%d\t%d\n",proc[i],burst_time[i],priority[i],wait_time[i],tat[i]);
    }
    printf("Average Waiting Time = %.2f\n",(float)total_wt/n);
    printf("Average Turnaround Time = %.2f",(float)total_tat/n);
}
int main()
{
    int n;
    printf("Enter the number of processes: ");
    scanf("%d",&n);
    int proc[n], burst_time[n],priority[n];
    printf("Enter the process and burst_time and priority respectively: ");
    for(int i=0;i<n;i++){
        scanf("%d %d %d",&proc[i],&priority[i],&burst_time[i]);
    }
    avgTime(proc,n,burst_time,priority);
}
