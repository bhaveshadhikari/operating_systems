
    
#include<stdio.h>
#define N 4
int main(){
    //assumed every process has arrived
    char *PID[]={"P1","P2","P3","P4"};
    int BT[] = {6,2,14,6};
    int PR[] = {3,2,1,4};  //1 indicates highest priority
    int CT[N],TAT[N],WT[N],totalTAT=0,totalWT=0,sumBT=0;
    

    //sorting on the basis of priority

    for (int i = 0; i < N; i++){
        for (int j = 0; j < N-i-1; j++){
            
            if (PR[j]>PR[j+1]){
                
                int tempPR = PR[j];
                PR[j] = PR[j+1];
                PR[j+1] = tempPR;

                int tempBT = BT[j];
                BT[j] = BT[j+1];
                BT[j+1] = tempBT;

                char *tempPID = PID[j];
                PID[j] = PID[j + 1];
                PID[j + 1] = tempPID;  
            }
        }
    }

    for (int i = 0; i < N; i++){
        sumBT += BT[i];
        CT[i] = sumBT;
        TAT[i] = CT[i];
        totalTAT+=TAT[i];
        WT[i] = TAT[i] - BT[i];
        totalWT+=WT[i];
    }

    printf("PID\tPRIORITY\tBT\tCT\tTAT\tWT\n");
    for (int i = 0; i < N; i++)
        printf("%s\t%d\t\t%d\t%d\t%d\t%d\n",PID[i],PR[i],BT[i],CT[i],TAT[i],WT[i]);
    
    printf("Average TAT = %.2f\n",(float)totalTAT/N);
    printf("Average WT = %.2f\n",(float)totalWT/N);
    
    return 0;
}

/*
PID     PRIORITY        BT      CT      TAT     WT
P3      1               14      14      14      0
P2      2               2       16      16      14
P1      3               6       22      22      16
P4      4               6       28      28      22
Average TAT = 20.00
Average WT = 13.00
*/