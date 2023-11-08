#include <stdio.h>
#include "boolean.h"
#include "queue.h"
#include "../MesinKata/mesinkata.h"

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

void enqueue(Queue *q, ElType val){
    if (isEmpty(*q)){
        IDX_HEAD(*q) = 0;
        IDX_TAIL(*q) = 0;
        TAIL(*q) = val;
    }
    else{
        IDX_TAIL(*q) = (IDX_HEAD(*q) + length(*q)) % CAPACITY;
        TAIL(*q) = val;
    }
}

void dequeue(Queue *q, ElType *val){
    *val = HEAD(*q);
    if (length(*q) == 1){
        IDX_HEAD(*q) = IDX_UNDEF;
        IDX_TAIL(*q) = IDX_UNDEF;
    }
    else{
        IDX_HEAD(*q) = ((IDX_HEAD(*q)+1) % CAPACITY);
    }
}

void insert(Queue *q, ElType X){
    if (isEmpty(*q)){
        enqueue(q, X);
    }
    else{
        IDX_TAIL(*q) = (IDX_HEAD(*q) + length(*q)) % CAPACITY;
        for (int i = (*q).idxTail-1 ; i >= 0; i--){
            (*q).buffer[i+1] = (*q).buffer[i];
        }
        HEAD(*q) = X;
    }
}

/* not ready
void displayQueue(Queue q){
    int i;
    Word input;
    if (isEmpty(q)){
        printf("[]");
    }
    else{
        printf("[");
        if (q.idxHead > q.idxTail){
            for (i = q.idxHead; i <= CAPACITY-1; i++){
                input = (q).buffer[i];
                while (!EndWord){
                    concatWord(&input, currentWord);
                    ADVWORD();
                }
                PrintWord(input);
                if (i != q.idxTail){
                    printf(",");
                }
            }
            for (i = 0; i <= q.idxTail; i++){
                input = (q).buffer[i];
                while (!EndWord){
                    concatWord(&input, currentWord);
                    ADVWORD();
                }
                PrintWord(input);
                if (i != q.idxTail){
                    printf(",");
                }
            }
        }
        else{
            for (i = q.idxHead; i <= q.idxTail; i++){
                input = (q).buffer[i];
                while (!EndWord){
                    concatWord(&input, currentWord);
                    ADVWORD();
                }
                PrintWord(input);
                if (i != q.idxTail){
                    printf(",");
                }
            }
        }
        printf("]\n");
    }
}
*/
