#include<stdio.h>
#include<string.h>
#define N 3
int reference[]={7,0,1,2,0,3,0,4,2,3,0,3,1,2,0};
int size = 15;
int time[N];
int arrivalCounter =0;
int placement[N];
int hitCounter = 0;

int hitCase(int x){
    for (int i = 0; i < N; i++)
    {
        if(placement[i] == x)
        return 1;
    }
    return 0;   
}

int longestLivingPeriod(){
    int earliest = time[0];
    int index = 0;
    for(int i = 0; i< N; i++){
        if (time[i]< earliest){
            earliest = time[i];
            index = i;
        }
    }
    return index;
}
int main(){

    

    memset(placement, -1, sizeof(placement));
    memset(time, 0, sizeof(time));
    
    for (int ref = 0; ref < 15; ref++)
    {
      
        //checkHit
        if (hitCase(reference[ref]))
        {
            hitCounter++;
           continue; 
           
        }

        //assign to vacant space if theres any
        for (int i = 0; i < N; i++){
            if (placement[i]== -1){
                placement[i] = reference[ref];
                time[i] = ref;
                printf("added: %d\n",placement[i]);
                break;
            }
        }
        
        // replacement
        if(!hitCase(reference[ref])){
        int indexToReplace = longestLivingPeriod();
        printf("replaced : %d\n",placement[indexToReplace]);
        placement[indexToReplace]= reference[ref];
        time[indexToReplace]=ref;
        }
        
        
    }
    
    
    printf("hit = %d",hitCounter);
    return 0;
}

/*
added: 7
added: 0
added: 1
replaced : 7
replaced : 0
replaced : 1
replaced : 2
replaced : 3
replaced : 0
replaced : 4
replaced : 2
replaced : 3
hit = 3
*/