#include <stdio.h>

void waitingTime(int P[], int n, int AT[], int BT[], int WT[], int Pr[]);
void turnAroundTime(int n, int WT[], int BT[], int TT[]);
void printArr(int n, int P[], int Pr[], int BT[], int WT[], int TT[], int AT[]);

int main()
{
    int n;
    printf("Enter the total number of process: ");
    scanf("%d", &n);
    int P[n], Pr[n], BT[n], WT[n], AT[n], TT[n];
    for(int i=0; i<n; i++)
    {
        printf("\nEnter the Process ID: ");
        scanf("%d", &P[i]);
        printf("And priority for P%d?\n", P[i]);
        scanf("%d", &Pr[i]);
        printf("And Burst time for P%d?\n", P[i]);
        scanf("%d", &BT[i]);
        printf("And Arrival time for P%d?\n", P[i]);
        scanf("%d", &AT[i]);
    }
    waitingTime(P,n, AT, BT, WT, Pr);
    turnAroundTime(n,BT,WT,TT);
    printArr(n ,P, Pr, BT, WT,TT, AT);
}
void waitingTime(int P[], int n, int AT[], int BT[], int WT[], int Pr[])
{
    int rem_bt[n];
    for (int i = 0; i < n; i++)
    {
        rem_bt[i] = BT[i];
    }
    int completed = 0;
    int t = 0;
    while (completed < n)
    {
        int s = -1;
        int m = -2;
        for (int i = 0; i < n; i++)
        {

            if (AT[i] <= t && rem_bt[i] > 0 && (s == -1 || Pr[i] < Pr[s] || (Pr[i] == Pr[s] && AT[i] < AT[s]) || (Pr[i] == Pr[s] && AT[i] == AT[s] && P[i] < P[s])))
            {
                m = Pr[i];
                s = i;
            }

        }

        if (s == -1)
        {
            t++;
            continue;
        }

        rem_bt[s]--;

        if (rem_bt[s] == 0)
        {
            completed++;
            WT[s] = t + 1 - AT[s] - BT[s];
        }

        t++;
    }
}


void turnAroundTime(int n, int WT[],int BT[], int TT[])
{
    for(int i=0; i<n; i++)
    {
        TT[i] = BT[i] + WT[i];
    }
}
void printArr(int n, int P[], int Pr[], int BT[], int WT[], int TT[], int AT[])
{
    printf("Process Id\tPriority\tBurst Time\tWaiting Time\tTurn Around Time\tArrival Time\n");
    for(int i=0; i<n; i++)
    {
        printf("P%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t\t\t%d\n", P[i], Pr[i], BT[i], WT[i], TT[i], AT[i]);
    }
}
