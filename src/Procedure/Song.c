#include "../ADT/Queue/queue.h"
#include "../ADT/Stack/stack.h"
#include "../ADT/SetMap/map.h"
#include <stdio.h>

void SongNext(Queue *lagu, Stack *riwayat, Map penyanyi, Map Album){
    if(length(*lagu) > 1){
        printf("Memutar lagu selanjutnya\n");

        printf("\n");
        
        dequeue(lagu, &currentWord);
        printf("\"");
        PrintWord(currentWord);
        printf("\" oleh \"New Jeans\"\n");
        Push(riwayat, currentWord);
    }

    else if (length(*lagu) == 1){
        printf("Queue kosong, memutar kembali lagu\n");
        printf("\"%d\" oleh \"Yasuda Rei\"\n", (*lagu).buffer[(*lagu).idxHead]);
    }
}

void SongPrevious(Queue *lagu, Stack *riwayat, Map penyanyi, Map album){
    infotype X;
    if (!IsEmpty(*riwayat)){
        Pop(riwayat, &X);
        insert(lagu, X);
        printf("Memutar lagu sebelumnya\n");
        printf("\"%d\" oleh \"New Jeans\"\n", (*riwayat).T[(*riwayat).TOP + 1]);
    }
    else{
        printf("lagu kosong, memutar kembali lagu\n");
        printf("\"%d\" oleh \"Yasuda Rei\"\n", (*lagu).buffer[(*lagu).idxHead]);
    }
}

int main(){
    Queue lagu;
    CreateQueue(&lagu);
    Stack riwayat;
    CreateEmpty(&riwayat);

    enqueue(&lagu, 1);
    enqueue(&lagu, 2);
    enqueue(&lagu, 3);
    enqueue(&lagu, 4);
    enqueue(&lagu, 5);

    int X;
    SongNext(&lagu, &riwayat);
    displayQueue(lagu);
    Pop(&riwayat, &X);
    printf("lagu sebelumnya : %d\n", X);
    Push(&riwayat, X);
    printf("\n");

    SongNext(&lagu, &riwayat);
    displayQueue(lagu);
    Pop(&riwayat, &X);
    printf("lagu sebelumnya : %d\n", X);
    Push(&riwayat, X);
    printf("\n");

    SongPrevious(&lagu, &riwayat);
    displayQueue(lagu);
    printf("\n");

    SongPrevious(&lagu, &riwayat);
    displayQueue(lagu);
    printf("\n");

    SongPrevious(&lagu, &riwayat);
    displayQueue(lagu);
    printf("\n");
    
    SongNext(&lagu, &riwayat);
    displayQueue(lagu);
    Pop(&riwayat, &X);
    printf("lagu sebelumnya : %d\n", X);
    Push(&riwayat, X);
    printf("\n");

    SongPrevious(&lagu, &riwayat);
    displayQueue(lagu);
    printf("\n");
}
