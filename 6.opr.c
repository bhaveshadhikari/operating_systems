#include<stdio.h>
#include<string.h>
#define N 3
int reference[]={7,0,1,2,0,3,0,4,2,3,0,3,2,1,2,0,1,7,0,1};
int size = 20;
int time[N];
int arrivalCounter =0;
int placement[N];
int hitCounter = 0;



int calcFarthestTime(int currentRef, int currentPage){
    for (int j = currentRef+1; j < size; j++)
            if(currentPage==reference[j])
                return j;
    return 50;
    
}


int hitCase(int x, int ref) {
    for (int i = 0; i < N; i++) {
        if (placement[i] == x) {
            time[i] = calcFarthestTime(ref, x);
            return 1;
        }
    }
    return 0;
}

int farthestLivingPeriod(){
    int farthest = time[0];
    int index = 0;
    for(int i = 0; i< N; i++){
        if (time[i]> farthest){
            farthest = time[i];
            index = i;
        }
    }
    return index;
}
int main(){

    

    memset(placement, -1, sizeof(placement));
    memset(time, 0, sizeof(time));
    
    for (int ref = 0; ref < size; ref++)
    {
      
        //checkHit
        if (hitCase(reference[ref],ref))
        {
            hitCounter++;
           continue; 
           
        }

        //assign to vacant space if theres any
        for (int i = 0; i < N; i++){
            if (placement[i]== -1){
                placement[i] = reference[ref];
                time[i] = calcFarthestTime(ref,placement[i]);
                printf("added: %d\n",placement[i]);
                break;
            }
        }
        
        // replacement
        if(!hitCase(reference[ref],ref)){
            int replaceIndex = farthestLivingPeriod();
            printf("replaced : %d\n",placement[replaceIndex]);
            placement[replaceIndex] = reference[ref];
            time[replaceIndex] = calcFarthestTime(ref,placement[replaceIndex]);
            
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
replaced : 1
replaced : 0
replaced : 4
replaced : 3
replaced : 2
hit = 11
*/