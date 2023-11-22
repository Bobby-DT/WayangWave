#include "queue.h"

void QueueSong(TabKata *Penyanyi, Queue *Antrian, Map *Album, Map *Lagu){
    PrintDaftarPenyanyi(Penyanyi);

    do {
        printf("Masukkan Nama Penyanyi yang dipilih : ");
        GetCommand();
        if (!IsMember(*Penyanyi, currentWord)) {
            printf("Penyanyi ");
            PrintWord(currentWord);
            printf(" tidak ada dalam daftar. Silakan coba lagi.\n");
        }
    } while (!IsMember(*Penyanyi, currentWord));
    int PenyanyiID = searchList(*Penyanyi, currentWord) + 1;

    PrintDaftarAlbum(Penyanyi, Album, PenyanyiID);

    do {
        printf("Masukkan Judul Album yang dipilih : ");
        GetCommand();
        if (!MapIsMember(*Lagu, currentWord)) {
            printf("Album ");
            PrintWord(currentWord);
            printf(" tidak ada dalam daftar. Silakan coba lagi.\n");
        }
    } while (!MapIsMember(*Lagu, currentWord));
    int AlbumID = searchMap(*Lagu, currentWord) + 1;
    int AlbumLength = (*Lagu).Elements[AlbumID - 1].Value.length;

    PrintDaftarLagu(Penyanyi, Album, Lagu, PenyanyiID, AlbumID);
    
    int LaguID;
    do {
        printf("Masukkan ID Lagu yang dipilih : ");
        GetCommand();
        LaguID = WordToInt(currentWord);
        if (LaguID > AlbumLength || LaguID < 1) {
            printf("Lagu dengan ID %d tidak ada dalam daftar. Silakan coba lagi.\n", LaguID);
        }
    } while (LaguID > AlbumLength || LaguID < 1);

    Song antrianBaru = CreateLagu(PenyanyiID, AlbumID, LaguID, -1);
    enqueue(Antrian, antrianBaru);

    printf("Berhasil menambahkan lagu \"");
    PrintWord(GetLagu(Lagu, AlbumID, LaguID));
    printf("\" oleh \"");
    PrintWord(GetPenyanyi(Penyanyi, PenyanyiID));
    printf("\" ke queue.\n\n");
}

void QueuePlaylist(Queue *Antrian, Map *Lagu, ArrayDinWord *PlaylistTitle, ArrayDin *PlaylistData){
    ListPlaylist(PlaylistTitle);
    
    int jumlahPlaylist = (*PlaylistTitle).Neff;

    if (jumlahPlaylist > 0){
        int PlaylistID;
        do {
            printf("Masukkan ID Playlist yang dipilih : ");
            GetCommand();
            PlaylistID = WordToInt(currentWord);
            if (PlaylistID > (*PlaylistTitle).Neff || PlaylistID < 1) {
                printf("Playlist %d tidak ada dalam daftar. Silakan coba lagi.\n", PlaylistID);
            }
        } while (PlaylistID > (*PlaylistTitle).Neff || PlaylistID < 1);
        Word playlistTitle = (*PlaylistTitle).A[PlaylistID - 1];
        
        // Ambil informasi lagu dari playlist dengan ID tertentu
        address playlistSongs = First((*PlaylistData).A[PlaylistID - 1]);

        // Enqueue semua lagu dari playlist ke dalam antrian
        while (playlistSongs != NULL) {
            enqueue(Antrian, Info(playlistSongs));
            playlistSongs = Next(playlistSongs);
        }

        printf("Berhasil menambahkan playlist \"");
        PrintWord(playlistTitle);
        printf("\" ke queue.\n\n");
    } else {
        printf("Kamu tidak memiliki playlist.\n\n");
    }
}

void QueueSwap (Queue *Antrian, Word a, Word b, Map *Lagu){
    int a_int = WordToInt(a);
    int b_int = WordToInt(b);

    if (queue_IsMember(*Antrian, a_int-1) && queue_IsMember(*Antrian, b_int-1)){
        Song temp = (*Antrian).buffer[a_int-1];
        (*Antrian).buffer[a_int-1] = (*Antrian).buffer[b_int-1];
        (*Antrian).buffer[b_int-1] = temp;

        printf("Lagu \"");
        PrintWord(GetLagu(Lagu, (*Antrian).buffer[b_int-1].AlbumID, (*Antrian).buffer[b_int-1].LaguID));
        printf("\" berhasil ditukar dengan \"");
        PrintWord(GetLagu(Lagu, (*Antrian).buffer[a_int-1].AlbumID, (*Antrian).buffer[a_int-1].LaguID));
        printf("\"\n\n");
    }

    else{
        if (!queue_IsMember(*Antrian, a_int-1) && !queue_IsMember(*Antrian, b_int-1)){
            printf("Lagu dengan urutan ke %d dan %d tidak terdapat dalam queue!\n\n", a_int, b_int);
        }
        else if (!queue_IsMember(*Antrian, b_int-1)){
            printf("Lagu dengan urutan ke %d tidak terdapat dalam queue!\n\n", b_int);
        }
        else if (!queue_IsMember(*Antrian, a_int-1)){
            printf("Lagu dengan urutan ke %d tidak terdapat dalam queue!\n\n", a_int);
        }
    }
}

void QueueRemove(TabKata *Penyanyi, Queue *Antrian, Map *Album, Map *Lagu, Word a){
    int a_int = WordToInt(a);
    if (queue_IsMember(*Antrian, a_int-1)){
        Song del;
        queue_delIn(Antrian, a_int-1, &del);

        printf("Lagu \"");
        PrintWord(GetLagu(Lagu, del.AlbumID, del.LaguID));
        printf("\" oleh \"");
        PrintWord(GetPenyanyi(Penyanyi, del.PenyanyiID));
        printf("\" telah dihapus dari queue!\n\n");
    }
    else{
        printf("Lagu dengan urutan ke %d tidak ada.\n\n", a_int);
    }
}

void QueueClear(Queue *Antrian){
    while (!queue_isEmpty(*Antrian))
    {
        Song del;
        dequeue(Antrian, &del);
    }
    printf("Queue berhasil dikosongkan.\n\n");
}