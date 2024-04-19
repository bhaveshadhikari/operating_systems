#include<stdio.h>

#define N 4
char *PID[]={"P1","P2","P3","P4"};
int BT[] = {4,3,5,2};
int CT[N],TAT[N],WT[N],totalTAT=0,totalWT=0,sumBT=0;

int RemBT[N], TQ = 2;

int allExecuted(){
    for (int i = 0; i < N; i++)
        if (RemBT[i]>0)
            return 0; 
    return 1;
}

int main(){
    //assumed every process has arrived
    
    //copy BT to remainingBT (RemBT)
    for (int i = 0; i < N; i++)
        RemBT[i] = BT[i];

    
    int presentTime = 0; //ganttchart
 
    while (!allExecuted())
    { 
        for (int i = 0; i < N; i++)
        {
            if(RemBT[i]== 0)
                continue;

            if (RemBT[i]>TQ){
                presentTime += TQ;
                RemBT[i] -= TQ;
            }
            
            else{
                presentTime += RemBT[i];
                RemBT[i] = 0;
                // the process is now executed successfully
                CT[i] = presentTime;

                TAT[i] = CT[i];
                totalTAT+=TAT[i];
                
                WT[i] = TAT[i] - BT[i];
                totalWT+=WT[i];
            }
        }
        
    }


    printf("PID\tBT\tCT\tTAT\tWT\n");
    for (int i = 0; i < N; i++)
        printf("%s\t%d\t%d\t%d\t%d\n",PID[i],BT[i],CT[i],TAT[i],WT[i]);
    
    printf("Average TAT = %.2f\n",(float)totalTAT/N);
    printf("Average WT = %.2f\n",(float)totalWT/N);
    
    return 0;
}

/*
PID     BT      CT      TAT     WT
P1      4       10      10      6
P2      3       11      11      8
P3      5       14      14      9
P4      2       8       8       6
Average TAT = 10.75
Average WT = 7.25
*/