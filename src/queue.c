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
    PrintWord(GetLagu(&Lagu, AlbumID, LaguID));
    printf("\" oleh \"");
    PrintWord(GetPenyanyi(&Penyanyi, PenyanyiID));
    printf("\" ke queue");
}

void QueuePlaylist(Queue *Antrian, Map *Lagu, ArrayDinWord *PlaylistTitle, ArrayDin *PlaylistData){
    ListPlaylist(&PlaylistTitle);

    do {
        printf("Masukkan ID Playlist yang dipilih : ");
        GetCommand();
        if (WordToInt(currentWord) >= (*PlaylistTitle).Neff || WordToInt(currentWord) < 0) {
            printf("Playlist %d tidak ada dalam daftar. Silakan coba lagi.\n", WordToInt(currentWord));
        }
    } while (WordToInt(currentWord) >= (*PlaylistTitle).Neff || WordToInt(currentWord) < 0);
    int PlaylistID = WordToInt(currentWord);
    Word playlistTitle = (*PlaylistTitle).A[playlistID - 1];
    
    // Ambil informasi lagu dari playlist dengan ID tertentu
    address playlistSongs = First((*PlaylistData).Elements[playlistID - 1]);

    // Enqueue semua lagu dari playlist ke dalam antrian
    while (playlistSongs != NULL) {
        enqueue(&Antrian, Info(playlistSongs));
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

void QueueRemove(TabKata *Penyanyi, Queue *Antrian, Map *Album, Map *Lagu, Word a){
    int a_int = WordToInt(a);
    if (queue_IsMember(*Antrian, a_int-1)){
        Song del;
        queue_delIn(&Antrian, a_int-1, &del);

        printf("Lagu \"");
        PrintWord(GetLagu(&Lagu, del.AlbumID, del.LaguID));
        printf("\" oleh \"");
        PrintWord(GetPenyanyi(&Penyanyi, del.PenyanyiID));
        printf("\" telah dihapus dari queue!\n");
    }
    else{
        printf("Lagu dengan urutan ke %d tidak ada.", a_int);
    }
}

void QueueClear(Queue *Antrian){
    while (!queue_isEmpty(*Antrian))
    {
        Song del;
        dequeue(Antrian, &del);
    }
    printf("Queue berhasil dikosongkan.\n");
}
