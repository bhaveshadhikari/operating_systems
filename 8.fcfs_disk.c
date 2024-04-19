#include<stdio.h>
#include<stdlib.h>
int seekTime=0;
int head = 50;
int seq[] = {82,170,43,140,24,16,190};
int totalMoves = 7;
int main(){
    
    for (int i = 0; i < totalMoves; i++)
    {
        int toRead = seq[i];
        seekTime += abs(head - toRead);
        head = toRead;
        printf("head: %d\n",head);
    }
    printf("seektime: %d",seekTime);
    return 0;
}
/*
head: 82
head: 170
head: 43
head: 140
head: 24
head: 16
head: 190
seektime: 642
*/