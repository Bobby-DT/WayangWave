# include <stdio.h>
# include "queue.h"
# include "../Lagu/lagu.h"

// gcc -o driver ../Lagu/lagu.c ../Lagu/song.c ../Mesin/mesinkata.c ../Mesin/mesinkarakter.c queue.c driverQueue.c

int main(){
    Queue Antrian;
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

    // MENAMBAHKAN ELEMEN DI INDEKS TAIL
    enqueue(&Antrian, Infolagu1);
    printf("Berhasil memasukkan lagu1\n");
    printf("Panjang antrian : %d\n", queue_length(Antrian));

    printf("\n");
    // MENAMBAHKAN ELEMEN DI INDEKS TAIL
    enqueue(&Antrian, Infolagu2);
    printf("Berhasil memasukkan lagu2\n");
    printf("Panjang antrian : %d\n", queue_length(Antrian));

    printf("\n");
    // INPUT ELEMEN DI INDEKS HEAD
    queue_insert(&Antrian, Infolagu3);
    printf("Berhasil memasukkan lagu3\n");
    printf("Panjang antrian : %d\n", queue_length(Antrian));
    printf("ID lagu head : %d\n", HEAD(Antrian).LaguID);
    printf("ID lagu tail : %d\n", TAIL(Antrian).LaguID);

    printf("\n");
    // MENGHAPUS ELEMEN DI TENGAH QUEUE
    Song temp;
    CreateEmptyLagu(&temp);
    queue_delIn(&Antrian, 2, &temp);
    printf("ID Lagu yang dihapus : %d\n", temp.LaguID);
    printf("Panjang antrian : %d\n", queue_length(Antrian));
    printf("ID lagu head : %d\n", HEAD(Antrian).LaguID);
    printf("ID lagu tail : %d\n", TAIL(Antrian).LaguID);
    
    printf("\n");
    // MENGHAPUS ELEMEN DI INDEKS HEAD
    dequeue(&Antrian, &temp);
    printf("ID Lagu yang dihapus : %d\n", temp.LaguID);
    printf("Panjang antrian : %d\n", queue_length(Antrian));
    printf("ID lagu head : %d\n", HEAD(Antrian).LaguID);
    printf("ID lagu tail : %d\n", TAIL(Antrian).LaguID);
    return 0;
}