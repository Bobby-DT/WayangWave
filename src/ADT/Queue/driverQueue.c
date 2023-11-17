# include <stdio.h>
# include "queue.h"

int main(){
    Queue q;
    CreateQueue(&q);
    if (isEmpty(q)){
        printf("Queue kosong\n"); //Jika Queue kosong
    }

    // Bisa melakukan Queue dengan kalimat
    // toLower masih belum bisa
    printf("Masukkan kata : ");
    STARTINPUT();

    while(!WordCompare(currentWord, toKata("keluar"))){
        Word input = GetWord();
        toLower(input);
        ADVWORD();
        while (!EndWord)
        {
            concatWord(&input, currentWord);
            ADVWORD();
        }

        enqueue(&q, input); //memasukkan kata ke dalam queue
        printf("Berhasil melakukan queue.\n");
        printf("Masukkan kata : ");
        STARTINPUT();
    }

    while(!WordCompare(currentWord, toKata("keluar"))){
        Word input = GetWord();
        toLower(input);
        ADVWORD();
        while (!EndWord)
        {
            concatWord(&input, currentWord);
            ADVWORD();
        }

        enqueue(&q, input); //memasukkan kata ke dalam queue
        printf("Berhasil melakukan queue.\n");
        printf("Masukkan kata : ");
        STARTINPUT();
    }

    while(!isEmpty(q)){
        printf("Banyak antrian : %d\n", length(q)); 
        dequeue(&q, &currentWord); //mengeluarkan kata dari dalam queue dengan sistem FIFO
        PrintWord(currentWord);
        printf("\n");
    }
    return 0;
}