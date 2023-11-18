#include "queue.h"

void QueueSong(TabKata Penyanyi, Queue *Antrian, Map Album, Map lagu){
    printf("Daftar Penyanyi :");
    for (int i = 0; i < (Penyanyi).Neff; i++) {
        printf("\n\t%d. ", i+1);
        PrintWord((Penyanyi).TK[i]);
    }
    
    printf("\n");
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

    printf("Daftar Album oleh ");
    PrintWord(currentWord);
    printf(" :\n");
    for (int i = 0; i < (Album).Elements[PenyanyiID - 1].Value.length; i++) {
        printf("\n\t%d. ", i+1);
        PrintWord((Album).Elements[PenyanyiID - 1].Value.buffer[i]);
    }
    printf("\n");

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

    printf("Daftar Lagu Album ");
    PrintWord((Album).Elements[PenyanyiID - 1].Value.buffer[AlbumID - 1]);
    printf(" oleh ");
    PrintWord((Penyanyi).TK[PenyanyiID - 1]);
    printf(" :\n");

    int AlbumLength = (lagu).Elements[AlbumID - 1].Value.length;
    for (int i = 0; i < AlbumLength; i++) {
        printf("\n\t%d. ", i+1);
        PrintWord((lagu).Elements[AlbumID - 1].Value.buffer[i]);
    }
    printf("\n");
    
    do {
        printf("Masukkan ID Lagu yang dipilih : ");
        GetCommand();
        if (WordToInt(currentWord) >= AlbumLength) {
            printf("Album %d tidak ada dalam daftar. Silakan coba lagi.\n", WordToInt(currentWord));
        }
    } while (WordToInt(currentWord) >= AlbumLength);  
    int LaguID = WordToInt(currentWord);

    Lagu judul_lagu;
    judul_lagu.PenyanyiID = PenyanyiID;
    judul_lagu.LaguID = LaguID;
    judul_lagu.AlbumID = AlbumID;

    enqueue(Antrian, judul_lagu);

    printf("Berhasil menambahkan lagu \"");
    PrintWord((lagu).Elements[AlbumID - 1].Value.buffer[LaguID-1]);
    printf("\" oleh \"");
    PrintWord((Penyanyi).TK[PenyanyiID - 1]);
    printf("\" ke queue");
}

void QueuePlaylist(Queue *Antrian, ArrayDinWord PlaylistTitle, ArrayDin PlaylistData, Map lagu){
    printf("Masukkan ID Playlist yang dipilih : ");
    GetCommand();
    int playlistID = WordToInt(currentWord) + 1;
    while (playlistID > (PlaylistTitle).Neff || playlistID < 1){
        printf("Tidak ada playlist dengan ID %d dalam daftar playlist pengguna. Silakan coba lagi.\n", playlistID);
        printf("Masukkan ID Playlist yang dipilih : ");
        GetCommand();
        int playlistID = WordToInt(currentWord) + 1;
    }
    int jumlahPlaylistSebelumnya = (PlaylistData).Neff;
    Word playlistTitle = (PlaylistTitle).A[playlistID - 1];
    
    // Ambil informasi lagu dari playlist dengan ID tertentu
    ArrayDin playlistSongs = (PlaylistData).Elements[playlistID].Value;

    // Enqueue semua lagu dari playlist ke dalam antrian
    for (int i = 0; i < playlistSongs.Neff; i++) {
        int laguID = playlistSongs.A[i]; // ID lagu dalam playlist
        // Tambahkan lagu ke dalam antrian
        Lagu currentSong = (lagu).Elements[laguID].Value;
        enqueue(Antrian, currentSong);
    }

    printf("Berhasil menambahkan playlist \"");
    PrintWord(playlistTitle);
    printf("\" ke queue.");
}

void QueueSwap (Queue *Antrian, Word a, Word b){
    int a_int = WordToInt(a);
    int b_int = WordToInt(b);

    if (queue_IsMember(*Antrian, a_int-1) && queue_IsMember(*Antrian, b_int-1)){
        Lagu temp = (*Antrian).buffer[a_int-1];
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

void QueueRemove(Queue *Antrian, Word a, Map lagu, TabKata Penyanyi, Map Album){
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
