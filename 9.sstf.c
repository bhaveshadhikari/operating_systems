#include<stdio.h>
#include<stdlib.h>
int seekTime=0;
int head = 50;
int seq[] = {82,170,43,140,24,16,190};
int totalMoves = 7;

int sstf(){
    int minSeek = abs(seq[0]-head);
    int index = 0;
    for (int i = 0; i < 7; i++)
    {   
        if (seq[i]== -1)
            continue;
        
        if (abs(seq[i]-head)<minSeek)
        {
            minSeek = abs(seq[i]-head);
            index = i;
        }
         
    }
    return index;
}
int main(){
    
    for (int i = 0; i < totalMoves; i++)
    {
        int toRead = seq[sstf()];
        seq[sstf()] = -1;
        seekTime += abs(head - toRead);
        head = toRead;
        printf("head: %d\n",head);
    }
    printf("seektime: %d",seekTime);
    return 0;
}
/*
head: 43
head: 24
head: 16
head: 82
head: 140
head: 170
head: 190
seektime: 208
*/