# include <stdio.h>
# include "queue.h"
# include "../Lagu/lagu.h"

// gcc -o ji ../Lagu/lagu.c ../Lagu/song.c ../Mesin/mesinkata.c ../Mesin/mesinkarakter.c queue.c driverQueue.c

int main(){
    Queue Antrian;
    CreateQueue(&Antrian);

    Object lagu1;
    Object lagu2;
    Object lagu3;

    Object album1;
    Object album2;

    Object penyanyi;
    
    Object playlist;

    Word nama_lagu1 = toKata("lagu1");
    Word nama_lagu2 = toKata("lagu2");
    Word nama_lagu3 = toKata("lagu3");

    Word nama_album1 = toKata("Album1");
    Word nama_album2 = toKata("Album2");

    Word nama_penyanyi = toKata("Penyanyi");

    Word nama_playlist = toKata("Playlist");

    playlist.Title = nama_playlist;
    playlist.ID = 1;
    
    lagu1.Title = nama_lagu1;
    lagu1.ID = 1;

    lagu2.Title = nama_lagu2;
    lagu2.ID = 2;

    lagu3.Title = nama_lagu3;
    lagu3.ID = 3;

    album1.Title = nama_album1;
    album1.ID = 1;
    album2.Title = nama_album2;
    album2.ID = 2;

    penyanyi.Title = nama_penyanyi;
    penyanyi.ID = 1;

    Song Infolagu1;
    CreateEmptyLagu(&Infolagu1);

    Song Infolagu2;
    CreateEmptyLagu(&Infolagu2);

    Song Infolagu3;
    CreateEmptyLagu(&Infolagu3);

    Infolagu1 = CreateLagu(penyanyi.ID, album1.ID, lagu1.ID, playlist.ID);
    Infolagu2 = CreateLagu(penyanyi.ID, album1.ID, lagu2.ID, playlist.ID);
    Infolagu3 = CreateLagu(penyanyi.ID, album1.ID, lagu3.ID, playlist.ID);

    // ENQUEUE
    enqueue(&Antrian, Infolagu1);
    printf("Berhasil memasukkan lagu1\n");
    printf("Panjang antrian : %d\n", queue_length(Antrian));

    printf("\n");
    // ENQUEUE
    enqueue(&Antrian, Infolagu2);
    printf("Berhasil memasukkan lagu2\n");
    printf("Panjang antrian : %d\n", queue_length(Antrian));

    printf("\n");
    // INPUT ELEMEN DI AWAL
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