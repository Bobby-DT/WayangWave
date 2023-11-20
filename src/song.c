#include <stdio.h>
#include "boolean.h"
#include "ADT/Queue/queue.h"
#include "ADT/Stack/stack.h"
#include "ADT/Lagu/lagu.h"
#include "ADT/SetMap/map.h"
#include "ADT/List/array.h"

void SongNext(Queue *Antrian, Stack *Riwayat, Lagu *CurrentLagu, Map lagu, TabKata Penyanyi){
    if(!queue_isEmpty(*Antrian)){
        printf("Memutar lagu selanjutnya\n");
        printf("\"");
        Word Judul_lagu = (lagu).Elements[(*Antrian).buffer[(*Antrian).idxHead].AlbumID - 1].Value.buffer[(*Antrian).buffer[(*Antrian).idxHead].LaguID - 1];
        PrintWord(Judul_lagu);
        printf("\" oleh \"");
        Word Nama_penyanyi = Penyanyi.TK[(*Antrian).buffer[(*Antrian).idxHead].PenyanyiID - 1];
        PrintWord(Nama_penyanyi);
        printf("\"\n");

        (*CurrentLagu).AlbumID = (*Antrian).buffer[(*Antrian).idxHead].AlbumID;
        (*CurrentLagu).PenyanyiID = (*Antrian).buffer[(*Antrian).idxHead].PenyanyiID;
        (*CurrentLagu).LaguID = (*Antrian).buffer[(*Antrian).idxHead].LaguID;

        Lagu temp;
        dequeue(Antrian, &temp);
        PushStack(Riwayat, temp);
    }
    else {
        printf("Queue kosong, memutar kembali lagu\n");
        printf("\"");
        Word Judul_lagu = (lagu).Elements[(*Antrian).buffer[(*Antrian).idxHead].AlbumID - 1].Value.buffer[(*Antrian).buffer[(*Antrian).idxHead].LaguID - 1];
        PrintWord(Judul_lagu);
        printf("\" oleh \"");
        Word Nama_penyanyi = Penyanyi.TK[(*Antrian).buffer[(*Antrian).idxHead].PenyanyiID - 1];
        PrintWord(Nama_penyanyi);
        printf("\"\n");
    }
}


void SongPrevious(Lagu *CurrentLagu, Queue *Antrian, Stack *Riwayat, Map lagu, TabKata Penyanyi){
    if (!IsEmptyStack(*Riwayat)){
        Lagu temp;
        Pop(Riwayat, &temp);
        insert(lagu, *CurrentLagu);
        *CurrentLagu = temp;
        printf("Memutar lagu sebelumnya\n");
        printf("\"");
        Word Judul_lagu = (lagu).Elements[(*Antrian).buffer[(*Antrian).idxHead].AlbumID - 1].Value.buffer[(*Antrian).buffer[(*Antrian).idxHead].LaguID - 1];
        PrintWord(Judul_lagu);
        printf("\" oleh \"");
        Word Nama_penyanyi = Penyanyi.TK[(*Antrian).buffer[(*Antrian).idxHead].PenyanyiID - 1];
        PrintWord(Nama_penyanyi);
        printf("\"\n");
    }
    else{
        printf("lagu kosong, memutar kembali lagu\n");
        printf("\"");
        Word Judul_lagu = (lagu).Elements[(*Antrian).buffer[(*Antrian).idxHead].AlbumID - 1].Value.buffer[(*Antrian).buffer[(*Antrian).idxHead].LaguID - 1];
        PrintWord(Judul_lagu);
        printf("\" oleh \"");
        Word Nama_penyanyi = Penyanyi.TK[(*Antrian).buffer[(*Antrian).idxHead].PenyanyiID - 1];
        PrintWord(Nama_penyanyi);
        printf("\"\n");
    }
}
