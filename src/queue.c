#include "queue.h"

void QueueSong(TabKata *Penyanyi, Queue *Antrian, Map *Album, Map *Lagu){
    PrintDaftarPenyayi(&Penyanyi);

    do {
        printf("Masukkan Nama Penyanyi yang dipilih : ");
        GetCommand();
        if (!IsMember(Penyanyi, currentWord)) {
            printf("Penyanyi ");
            PrintWord(currentWord);
            printf(" tidak ada dalam daftar. Silakan coba lagi.\n");
        }
    } while (!IsMember(Penyanyi, currentWord));
    int PenyanyiID = searchList(Penyanyi, currentWord) + 1;

    PrintDaftarAlbum(&Penyanyi, &Album, PenyanyiID);

    do {
        printf("Masukkan Judul Album yang dipilih : ");
        GetCommand();
        if (!MapIsMember(Album, currentWord)) {
            printf("Album ");
            PrintWord(currentWord);
            printf(" tidak ada dalam daftar. Silakan coba lagi.\n");
        }
    } while (!MapIsMember(Album, currentWord));
    int AlbumID = searchMap(Album, currentWord) + 1;

    PrintDaftarLagu(&Penyanyi, &Album, &Lagu, PenyanyiID, AlbumID);
    
    do {
        printf("Masukkan ID Lagu yang dipilih : ");
        GetCommand();
        if (WordToInt(currentWord) >= AlbumLength) {
            printf("Album %d tidak ada dalam daftar. Silakan coba lagi.\n", WordToInt(currentWord));
        }
    } while (WordToInt(currentWord) >= AlbumLength);  
    int LaguID = WordToInt(currentWord);

    Song antrianBaru = CreateLagu(PenyanyiID, AlbumID, LaguID, -1);
    enqueue(&Antrian, antrianBaru);

    printf("Berhasil menambahkan lagu \"");
    PrintWord((*Lagu).Elements[AlbumID - 1].Value.buffer[LaguID - 1].Title);
    printf("\" oleh \"");
    PrintWord((*Penyanyi).TK[PenyanyiID - 1]);
    printf("\" ke queue");
}

void QueuePlaylist(Queue *Antrian, ArrayDinWord *PlaylistTitle, ArrayDin *PlaylistData, Map *Lagu){
    ListPlaylist(&PlaylistTitle);

    do {
        printf("Masukkan ID Playlist yang dipilih : ");
        GetCommand();
        if (WordToInt(currentWord) >= (*PlaylistTitle).Neff || WordToInt(currentWord) < 0) {
            printf("Album %d tidak ada dalam daftar. Silakan coba lagi.\n", WordToInt(currentWord));
        }
    } while (WordToInt(currentWord) >= (*PlaylistTitle).Neff || WordToInt(currentWord) < 0);
    int PlaylistID = WordToInt(currentWord);
    Word playlistTitle = (*PlaylistTitle).A[playlistID - 1];
    
    // Ambil informasi lagu dari playlist dengan ID tertentu
    address playlistSongs = First((*PlaylistData).Elements[playlistID - 1]);

    // Enqueue semua lagu dari playlist ke dalam antrian
    while (playlistSongs != NULL) {
        enqueue(Antrian, Info(playlistSongs));
        playlistSongs = Next(playlistSongs);
    }

    printf("Berhasil menambahkan playlist \"");
    PrintWord(playlistTitle);
    printf("\" ke queue.");
}

void QueueSwap (Queue *Antrian, Word a, Word b){
    int a_int = WordToInt(a);
    int b_int = WordToInt(b);

    if (queue_IsMember(*Antrian, a_int-1) && queue_IsMember(*Antrian, b_int-1)){
        Song temp = (*Antrian).buffer[a_int-1];
        (*Antrian).buffer[a_int-1] = (*Antrian).buffer[b_int-1];
        (*Antrian).buffer[b_int-1] = temp;
    }

    else{
        if (!queue_IsMember(*Antrian, a_int-1) && !queue_IsMember(*Antrian, b_int-1)){
            printf("Lagu dengan urutan ke %d dan %d tidak terdapat dalam queue!", a_int, b_int);
        }
        else if (!queue_IsMember(*Antrian, b_int-1)){
            printf("Lagu dengan urutan ke %d tidak terdapat dalam queue!", b_int);
        }
        else if (!queue_IsMember(*Antrian, a_int-1)){
            printf("Lagu dengan urutan ke %d tidak terdapat dalam queue!", a_int);
        }
    }
}

void QueueRemove(Queue *Antrian, Word a, Map *Lagu, TabKata *Penyanyi, Map *Album){
    int a_int = WordToInt(a);
    if (queue_IsMember(*Antrian, a_int-1)){
        Word Judul_lagu = (lagu).Elements[(*Antrian).buffer[a_int-1].AlbumID - 1].Value.buffer[(*Antrian).buffer[a_int-1].LaguID - 1];
        printf("Lagu \"");
        PrintWord(Judul_lagu);
        printf("\" oleh \"");

        Word Nama_penyanyi = Penyanyi.TK[(*Antrian).buffer[a_int-1].PenyanyiID - 1];

        printf("\" telah dihapus dari queue!\n");
        queue_delIn(Antrian, a_int-1);
    }
    else{
        printf("Lagu dengan urutan ke %d tidak ada.", a_int);
    }
}

void QueueClear(Queue *Antrian){
    while (!queue_isEmpty(*Antrian))
    {
        ElType del;
        dequeue(Antrian, &del);
    }
    printf("Queue berhasil dikosongkan.\n");
}
