#include <stdio.h>
#include "queue.h"
#include "../ADT/Set dan Map/set.h"
#include "../ADT/Set dan Map/map.h"
#include "list.h"

void QueueSong(Queue Q, Queue *result){
    Set temp_peny;
    CreateEmpty(&temp_peny);
    Set temp_alb;
    CreateEmpty(&temp_alb);
    
    printf("Daftar Penyanyi :\n");
    boolean found;
    int j, i;
    int num;

    for (i = Q.idxHead; i < length(Q); i++){
        Insert(&temp_peny, Q.buffer[i].penyanyi);
    }

    for (i = 0; i < temp_peny.Count; i++){
        printf("%d. ", (i+1));
        printf("%d\n", temp_peny.Elements[i]);
    }

    printf("\n");

    ElType peny;
    printf("Masukkan Nama Penyanyi: ");
    scanf("%d", &peny);
    printf("\n");

    printf("Daftar Album oleh %d :\n", peny);
    
    /* Asumsi tidak ada artis dengan album bernama sama*/
    for(int i = 0; i < length(Q); i++){
        if ((Q).buffer[i].penyanyi == peny){
            Insert(&temp_alb, Q.buffer[i].album);
        }
    }

    for (i = 0; i < temp_alb.Count; i++){
        printf("%d. ", (i+1));
        printf("%d\n", temp_alb.Elements[i]);
    }

    printf("\n");

    ElType alb;
    printf("Masukkan Nama Album yang dipilih : ");
    scanf("%d", &alb);
    printf("\n");

    printf("Daftar Lagu Album %d oleh %d :\n", alb, peny);
    int number[length(Q)];
    int idx_num = 0;
    num = 1;
    for(int i = 0; i < length(Q); i++){
        if((Q).buffer[i].penyanyi == peny && (Q).buffer[i].album == alb){
            printf("%d. ", num);
            printf("%d\n", (Q).buffer[i].lagu);
            number[idx_num] = i;
            idx_num++;
        }
        num++;
    }
    printf("\n");

    ElType input;
    printf("Masukkan ID Lagu yang dipilih: ");
    scanf("%d", &input);
    printf("\n");
    if (input <= num){
        int loc = number[input-1];
        enqueue(result, (Q).buffer[loc].album, (Q).buffer[loc].penyanyi, (Q).buffer[loc].lagu);
        printf("Berhasil menambahkan lagu \"%d\" oleh \"%d\" ke queue.\n", (Q).buffer[loc].lagu), (Q).buffer[loc].penyanyi;
    }
}

void QueuePlaylist(List playlist, Queue *Q){
    ElType id;
    printf("Masukkan ID Playlist: ");
    scanf("%d", &id);
    printf("\n");
    int i = 0;
    boolean found = false;
    /*harusnya ngecek dulu apakah nama  playlist nya ada*/
    while (i < Length(playlist) && !found){
        if (playlist.A[i] == id){
            enqueue(Q, (*Q).buffer[i].album, (*Q).buffer[i].penyanyi, (*Q).buffer[i].lagu);
            printf("Berhasil menambahkan playlist \"&d\" ke queue.", playlist.A[id-1]);
        }
    }
}

int main(){
    Queue lagu;
    CreateQueue(&lagu);
    Queue q;
    CreateQueue(&q);
    List play = MakeList();
    

    enqueue(&lagu, 1, 2, 7);
    enqueue(&lagu, 1, 2, 8);
    enqueue(&lagu, 2, 2, 3);
    enqueue(&lagu, 3, 1, 4);
    enqueue(&lagu, 1, 1, 5);
    enqueue(&lagu, 2, 3, 6);
    /* lagu = seluruh lagu yang ada; q = Queue lagu*/
    QueuePlaylist()

    displayQueue(q);
}