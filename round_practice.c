#include<stdio.h>

void waitingTime(int n, int p[], int b[], int a[], int w[], int tat[],int r[],int q){


    int t=0;
    int completed = 0;

    while(completed<n){
        for(int i=0; i<n; i++){
            if(r[i]>0){
                if(r[i]>q){
                    t+=q;
                    r[i]-=q;

                }else{
                    t+=r[i];
                    w[i] = t - b[i];
                    r[i] = 0;
                    completed++;
                }
            }
        }
    }


}

void turnaroundTime(int n, int p[],int b[], int a[], int w[],int t[]){
    for(int i=0; i<n; i++){
        t[i] = b[i] + w[i];
    }
}
void printAll(int n, int p[], int b[], int a[], int w_t[], int tat[]){
    printf("Processes\tB Time\tA Time\tW Time\tT Time\n");
    for(int i=0; i<n; i++){
        printf("%d\t%d\t%d\t%d\t%d\n",p[i],b[i],a[i],w_t[i],tat[i]);
    }
}
void avgTime(int n,int p[],int b[],int a[], int r[],int q){
    int w_t[n], tat[n], t_w=0, t_t=0;

    waitingTime(n,p,b,a,w_t,tat,r,q);
    turnaroundTime(n,p,b,tat,w_t,tat);
    printAll(n,p,b,a,w_t,tat);

    printf("Average Waiting Time : %.2f\nAverage Turn Around Time : %.2f",(float)t_w/n,(float)t_t/n);

}
int main()
{
    int n,q;
    printf("Please Enter Number of Processes and Quantum : ");
    scanf("%d %d",&n,&q);
    int p[n], b[n], a[n], r[n];

    printf("Enter Process Id, Burst Time and Arrival Time : ");
    for(int i=0; i<n; i++){
        scanf("%d %d %d",&p,&b,&a);
        r[i] = b[i];
    }

    avgTime(n,p,b,a,r,q);


    return 0;
}
