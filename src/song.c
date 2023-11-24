#include "song.h"

void SongNext(TabKata *Penyanyi, Queue *Antrian, Stack *Riwayat, Map *Lagu, Song *Playing) {
    if(!queue_isEmpty(*Antrian)){
        /*
        Command SONG NEXT digunakan untuk memutar lagu yang berada di dalam queue.
        Lagu yang sedang diputar kemudian ditambah ke dalam daftar riwayat putar lagu.
        Jika queue kosong, yang diputar adalah lagu yang sedang diputar.

        Antrian -> Playing
        Playing -> Riwayat
        */
        Song nextSong;
        dequeue(Antrian, &nextSong);
        if(!SongIsEmpty(*Playing)){
            PushStack(Riwayat, *Playing);
        }
        
        *Playing = nextSong;
        

        printf("Memutar lagu selanjutnya\n\"");
        PrintWord(GetLagu(Lagu, nextSong.AlbumID, nextSong.LaguID));
        printf("\" oleh \"");
        PrintWord(GetPenyanyi(Penyanyi, nextSong.PenyanyiID));
        printf("\"\n\n");
    }
    else {
        if (SongIsEmpty(*Playing)) {
            printf("Queue kosong dan belum ada lagu yang diputar!\n\n");
        } else {
            printf("Queue kosong, memutar kembali lagu\n\"");
            PrintWord(GetLagu(Lagu, (*Playing).AlbumID, (*Playing).LaguID));
            printf("\" oleh \"");
            PrintWord(GetPenyanyi(Penyanyi, (*Playing).PenyanyiID));
            printf("\"\n\n");
        }
    }
}

void SongPrevious(TabKata *Penyanyi, Queue *Antrian, Stack *Riwayat, Map *Lagu, Song *Playing) {
    if (!IsEmptyStack(*Riwayat)){
        /*
        Command SONG PREVIOUS digunakan untuk memutar lagu yang terakhir kali diputar.
        Lagu yang sedang diputar kemudian ditambah ke dalam queue dengan urutan pertama.
        Jika daftar riwayat lagu kosong, yang diputar adalah lagu yang sedang diputar.
        */
        Song previousSong;
        PopStack(Riwayat, &previousSong);
        queue_insert(Antrian, *Playing);
        *Playing = previousSong;

        printf("Memutar lagu sebelumnya\n\"");
        PrintWord(GetLagu(Lagu, previousSong.AlbumID, previousSong.LaguID));
        printf("\" oleh \"");
        PrintWord(GetPenyanyi(Penyanyi, previousSong.PenyanyiID));
        printf("\"\n\n");
    }
    else{
        if (SongIsEmpty(*Playing)) {
            printf("Riwayat lagu kosong dan belum ada lagu yang diputar!\n\n");
        } else {
            printf("Riwayat lagu kosong, memutar kembali lagu\n\"");
            PrintWord(GetLagu(Lagu, (*Playing).AlbumID, (*Playing).LaguID));
            printf("\" oleh \"");
            PrintWord(GetPenyanyi(Penyanyi, (*Playing).PenyanyiID));
            printf("\"\n\n");
        }
    }
}
