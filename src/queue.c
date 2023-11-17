#include <stdio.h>
#include "../src/ADT/Queue/queue.h"
#include "../src/ADT/Mesin/MesinKata.h"
#include "../src/ADT/SetMap/map.h"
// #include "../src/ADT/List/arraydin.h"

void QueueSong(Queue *queueputar, Map penyanyi, Map album){
    int i;

    printf("Daftar Penyanyi :\n");
    for (i = 1; i <= penyanyi.Count; i++){
        printf("%d. %s\n", i, penyanyi.Elements[i].Key);
    }
    printf("\n");
    printf("Masukkan nama penyanyi :\n");
    
    GetCommand();

    Word nama_penyanyi = currentWord;
    
    Set set_album;
    SetCreateEmpty(&set_album);
    MapValue(penyanyi, currentWord, &set_album);

    printf("Daftar Album oleh ");
    PrintWord(currentWord);
    printf(" :\n");
    displaySet(set_album);

    printf("Masukkan Nama Album yang dipilih :\n");
    
    GetCommand();

    Set set_lagu;
    SetCreateEmpty(&set_lagu);
    MapValue(album, currentWord, &set_lagu);

    printf("Daftar lagu Album \"");
    PrintWord(currentWord);
    printf("\" oleh \"");
    PrintWord(nama_penyanyi);
    printf("\" :\n");
    displaySet(set_lagu);

    
    printf("Masukkan ID Lagu yang dipilih:\n");
    GetCommand();
    int idx = WordToInt(currentWord);
    printf("Berhasil menambahkan lagu \"");

    Word judul_lagu = set_lagu.buffer[idx-1];
    enqueue(queueputar, judul_lagu);
    PrintWord(judul_lagu);

    printf("\" oleh \"");
    printf("\" ke queue.");
}

// void QueuePlaylist(Queue queuePutar, arr){
//     printf("Masukkan ID Playlist: ");
//     GetCommand();
//     WordToInt(currentWord);
//     if ()

// }

void QueueSwap (Queue *queuePutar, Word a, Word b){
    int a_int = WordToInt(a);
    int b_int = WordToInt(b);

    if (queue_IsMember(*queuePutar, a_int-1) && queue_IsMember(*queuePutar, b_int-1)){
        Word temp = (*queuePutar).buffer[a_int-1];
        (*queuePutar).buffer[a_int-1] = (*queuePutar).buffer[b_int-1];
        (*queuePutar).buffer[b_int-1] = temp;
    }

    else if (!queue_IsMember(*queuePutar, a_int-1) || !queue_IsMember(*queuePutar, b_int-1)){
        if (!queue_IsMember(*queuePutar, a_int-1)){
            printf("Lagu dengan urutan ke %d tidak terdapat dalam queue!", a_int);
        }
        else if (!queue_IsMember(*queuePutar, b_int-1)){
            printf("Lagu dengan urutan ke %d tidak terdapat dalam queue!", b_int);
        }
        else{
            printf("Lagu dengan urutan ke %d dan %d tidak terdapat dalam queue!", a_int, b_int);
        }
    }
}

void QueueRemove(Queue *queuePutar, Word a){
    int a_int = WordToInt(a);
    if (queue_IsMember(*queuePutar, a_int-1)){
        printf("Lagu \"");
        PrintWord((*queuePutar).buffer[a_int-1]);
        printf("\" oleh “Aoi Teshima” telah dihapus dari queue!\n");
        queue_delIn(queuePutar, a_int-1);
    }
    else{
        printf("Lagu dengan urutan ke %d tidak ada.", a_int);
    }
}

void QueueClear(Queue *queuePutar){
    while (!queue_isEmpty(*queuePutar))
    {
        ElType del;
        dequeue(queuePutar, &del);
    }
    printf("Queue berhasil dikosongkan.\n");
}
