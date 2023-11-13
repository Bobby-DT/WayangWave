#include <stdio.h>
#include "queue.h"

void CreateQueue(Queue *q){
    IDX_HEAD(*q) = IDX_UNDEF;
    IDX_TAIL(*q) = IDX_UNDEF;
}

boolean isEmpty(Queue q){
    return ((q.idxHead == IDX_UNDEF) && (q.idxTail == IDX_UNDEF));
}

boolean isFull(Queue q){
    return (length(q) == CAPACITY);
}

int length(Queue q){
    int length;
    if (isEmpty(q)){
        length = 0;
    }
    else{
        if (q.idxHead <= q.idxTail){
            length = (q.idxTail - q.idxHead + 1);
        }
        else {
            length = ((CAPACITY - q.idxHead) + q.idxTail + 1);
        }
    }
    return length;
}

/* Gabung Set?*/
void enqueue(Queue *q, ElType alb, ElType peny, ElType lag){
    if (isEmpty(*q)){
        IDX_HEAD(*q) = 0;
        IDX_TAIL(*q) = 0;
        (*q).buffer[(*q).idxTail].album = alb;
        (*q).buffer[(*q).idxTail].penyanyi = peny;
        (*q).buffer[(*q).idxTail].lagu = lag;
    }
    else{
        IDX_TAIL(*q) = (IDX_HEAD(*q) + length(*q)) % CAPACITY;
        (*q).buffer[(*q).idxTail].album = alb;
        (*q).buffer[(*q).idxTail].penyanyi = peny;
        (*q).buffer[(*q).idxTail].lagu = lag;
    }
}

void insert(Queue *q, ElType alb, ElType peny, ElType lag){
    if (isEmpty(*q)){
        IDX_HEAD(*q) = 0;
        IDX_TAIL(*q) = 0;
        (*q).buffer[(*q).idxTail].album = alb;
        (*q).buffer[(*q).idxTail].penyanyi = peny;
        (*q).buffer[(*q).idxTail].lagu = lag;
    }
    else{
        IDX_TAIL(*q) = (IDX_HEAD(*q) + length(*q)) % CAPACITY;
        for (int i = (*q).idxTail-1 ; i >= 0; i--){
            (*q).buffer[i+1] = (*q).buffer[i];
        }
        (*q).buffer[(*q).idxTail].album = alb;
        (*q).buffer[(*q).idxTail].penyanyi = peny;
        (*q).buffer[(*q).idxTail].lagu = lag;
    }
}

void dequeue(Queue *q, ElType *alb, ElType *peny, ElType *lag){
    *alb = HEAD(*q).album;
    *peny = HEAD(*q).penyanyi;
    *lag = HEAD(*q).lagu;
    if (length(*q) == 1){
        IDX_HEAD(*q) = IDX_UNDEF;
        IDX_TAIL(*q) = IDX_UNDEF;
    }
    else{
        IDX_HEAD(*q) = ((IDX_HEAD(*q)+1) % CAPACITY);
    }
}

void displayQueue(Queue q){
    int i;
    if (isEmpty(q)){
        printf("[]");
    }
    else{
        printf("[");
        if (q.idxHead > q.idxTail){
            for (i = q.idxHead; i <= CAPACITY-1; i++){
                printf("(");
                printf("%d,", q.buffer[i].album);
                printf("%d,", q.buffer[i].penyanyi);
                printf("%d", q.buffer[i].lagu);
                printf(")");
            }
            for (i = 0; i <= q.idxTail; i++){
                printf("(");
                printf("%d,", q.buffer[i].album);
                printf("%d,", q.buffer[i].penyanyi);
                printf("%d", q.buffer[i].lagu);
                printf(")");
                if (i != q.idxTail){
                    printf(",");
                }
            }
        }
        else{
            for (i = q.idxHead; i <= q.idxTail; i++){
                printf("(");
                printf("%d,", q.buffer[i].album);
                printf("%d,", q.buffer[i].penyanyi);
                printf("%d", q.buffer[i].lagu);
                printf(")");
                if (i != q.idxTail){
                    printf(",");
                }
            }
        }
        printf("]\n");
    }
}
