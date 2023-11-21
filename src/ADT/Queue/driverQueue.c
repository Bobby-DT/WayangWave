# include <stdio.h>
# include "queue.h"
# include "../Lagu/lagu.h"

// gcc -o driver ../Lagu/lagu.c ../Lagu/song.c ../Mesin/mesinkata.c ../Mesin/mesinkarakter.c queue.c driverQueue.c

int main(){
    printf("Declaring Queue . . .\nQueue Antrian;\n\n");
    Queue Antrian;
    
    printf("Creating Empty Queue . . .\nCreateQueue(&Antrian);\n\n");
    CreateQueue(&Antrian);

    Song Infolagu1;
    CreateEmptyLagu(&Infolagu1);

    Song Infolagu2;
    CreateEmptyLagu(&Infolagu2);

    Song Infolagu3;
    CreateEmptyLagu(&Infolagu3);

    //CreateLagu(IDPenyanyi, IDAlbum, IDLagu, IDPlaylist);
    Infolagu1 = CreateLagu(1, 1, 1, 1);
    Infolagu2 = CreateLagu(1, 1, 2, 1);
    Infolagu3 = CreateLagu(1, 2, 3, 1);

    printf("IsEmpty: %d\n", queue_isEmpty(Antrian));
    printf("IsFull: %d\n", queue_isFull(Antrian));
    printf("Panjang: %d\n\n", queue_length(Antrian));

    printf("\n");

    printf("MENAMBAHKAN ELEMEN DI INDEKS TAIL\n");
    enqueue(&Antrian, Infolagu1);

    printf("IsEmpty: %d\n", queue_isEmpty(Antrian));
    printf("IsFull: %d\n", queue_isFull(Antrian));
    printf("Panjang: %d\n\n", queue_length(Antrian));

    printf("MENAMBAHKAN ELEMEN DI INDEKS TAIL\n");
    enqueue(&Antrian, Infolagu2);

    printf("IsEmpty: %d\n", queue_isEmpty(Antrian));
    printf("IsFull: %d\n", queue_isFull(Antrian));
    printf("Panjang: %d\n\n", queue_length(Antrian));

    printf("MENAMBAHKAN ELEMEN DI INDEKS HEAD\n");
    queue_insert(&Antrian, Infolagu3);
    printf("IsEmpty: %d\n", queue_isEmpty(Antrian));
    printf("IsFull: %d\n", queue_isFull(Antrian));
    printf("Panjang: %d\n", queue_length(Antrian));
    printf("ID lagu head : %d\n", HEAD(Antrian).LaguID);
    printf("ID lagu tail : %d\n\n", TAIL(Antrian).LaguID);

    printf("MENGHAPUS ELEMEN DI TENGAH QUEUE\n");
    Song temp;
    CreateEmptyLagu(&temp);
    queue_delIn(&Antrian, 2, &temp);
    printf("IsEmpty: %d\n", queue_isEmpty(Antrian));
    printf("IsFull: %d\n", queue_isFull(Antrian));
    printf("Panjang: %d\n", queue_length(Antrian));
    printf("ID Lagu yang dihapus : %d\n", temp.LaguID);
    printf("ID lagu head : %d\n", HEAD(Antrian).LaguID);
    printf("ID lagu tail : %d\n\n", TAIL(Antrian).LaguID);
    
    printf("MENGHAPUS ELEMEN DI INDEKS HEAD\n");
    dequeue(&Antrian, &temp);
    printf("IsEmpty: %d\n", queue_isEmpty(Antrian));
    printf("IsFull: %d\n", queue_isFull(Antrian));
    printf("Panjang: %d\n", queue_length(Antrian));
    printf("ID Lagu yang dihapus : %d\n", temp.LaguID);
    printf("ID lagu head : %d\n", HEAD(Antrian).LaguID);
    printf("ID lagu tail : %d\n\n", TAIL(Antrian).LaguID);

    printf("queue_IsMember(Antrian, 1)\n");
    if(queue_IsMember(Antrian, 1)){
        printf("indeks ke-0 ada dalam queue\n\n");
    }
    
    return 0;
}
