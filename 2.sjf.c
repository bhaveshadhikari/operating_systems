    
#include<stdio.h>
#define N 4
int main(){
    //assumed every process has arrived
    char *PID[]={"P1","P2","P3","P4"};
    int BT[]={5,3,8,6};
    int CT[N],TAT[N],WT[N],totalTAT=0,totalWT=0,sumBT=0;
    

    //sorting on the basis of shortest BT

    for (int i = 0; i < N; i++){
        for (int j = 0; j < N-i-1; j++){
            
            if (BT[j]>BT[j+1]){
                int t = BT[j];
                BT[j] = BT[j+1];
                BT[j+1] = t;

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

    printf("PID\tBT\tCT\tTAT\tWT\n");
    for (int i = 0; i < N; i++)
        printf("%s\t%d\t%d\t%d\t%d\n",PID[i],BT[i],CT[i],TAT[i],WT[i]);
    
    printf("Average TAT = %.2f\n",(float)totalTAT/N);
    printf("Average WT = %.2f\n",(float)totalWT/N);
    
    return 0;
}