#include<stdio.h>
#define N 4
int main(){
    int AT[]={0,1,2,3};
    int BT[]={5,3,8,6};
    int CT[N],TAT[N],WT[N],totalTAT=0,totalWT=0,sumBT=0;
    

    //fcfs scheduling
    for (int i = 0; i < N; i++)
    {
        sumBT += BT[i];
        CT[i] = sumBT;

        TAT[i] = CT[i] - AT[i];
        totalTAT+=TAT[i];
        
        WT[i] = TAT[i] - BT[i];
        totalWT+=WT[i];
    }

    printf("AT\tBT\tCT\tTAT\tWT\n");
    for (int i = 0; i < N; i++)
        printf("%d\t%d\t%d\t%d\t%d\n",AT[i],BT[i],CT[i],TAT[i],WT[i]);
    
    printf("Average TAT = %.2f\n",(float)totalTAT/N);
    printf("Average WT = %.2f\n",(float)totalWT/N);
    
    return 0;
}

/*

AT      BT      CT      TAT     WT
0       5       5       5       0
1       3       8       7       4
2       8       16      14      6
3       6       22      19      13
Average TAT = 11.25
Average WT = 5.75

*/
