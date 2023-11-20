#include <stdio.h>
#include "../../boolean.h"
#include "queue.h"

void CreateQueue(Queue *q){
    IDX_HEAD(*q) = IDX_UNDEF;
    IDX_TAIL(*q) = IDX_UNDEF;
}

boolean queue_isEmpty(Queue q){
    return ((q.idxHead == IDX_UNDEF) && (q.idxTail == IDX_UNDEF));
}

boolean queue_isFull(Queue q){
    return (queue_length(q) == CAPACITY);
}

int queue_length(Queue q){
    int length;
    if (queue_isEmpty(q)){
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

void enqueue(Queue *q, Song val){
    if (queue_isEmpty(*q)){
        IDX_HEAD(*q) = 0;
        IDX_TAIL(*q) = 0;
        TAIL(*q) = val;
    }
    else{
        IDX_TAIL(*q) = (IDX_HEAD(*q) + queue_length(*q)) % CAPACITY;
        TAIL(*q) = val;
    }
}

void dequeue(Queue *q, Song *val){
    *val = HEAD(*q);
    if (queue_length(*q) == 1){
        IDX_HEAD(*q) = IDX_UNDEF;
        IDX_TAIL(*q) = IDX_UNDEF;
    }
    else{
        IDX_HEAD(*q) = ((IDX_HEAD(*q)+1) % CAPACITY);
    }
}

void queue_insert(Queue *q, Song X){
    if (queue_isEmpty(*q)){
        enqueue(q, X);
    }
    else{
        IDX_TAIL(*q) = (IDX_HEAD(*q) + queue_length(*q)) % CAPACITY;
        for (int i = (*q).idxTail-1 ; i >= 0; i--){
            (*q).buffer[i+1] = (*q).buffer[i];
        }
        HEAD(*q) = X;
    }
}

boolean queue_IsMember(Queue q, int a){
    boolean member = false;
    if (!queue_isEmpty(q)){
        if (a >= q.idxHead && a <= q.idxTail){
            member = true;
        }
    }
    return member;
}

void queue_delIn(Queue *q, int a){
    int currentIdx = ((*q).idxHead + a) % CAPACITY;

    // Menghapus elemen pada posisi yang diinginkan dan menyimpannya
    Song deletedElement = (*q).buffer[currentIdx];

    // Memindahkan elemen-elemen setelah posisi yang dihapus ke posisi sebelumnya
    while (currentIdx != (*q).idxTail) {
        (*q).buffer[currentIdx] = (*q).buffer[(currentIdx + 1) % CAPACITY];
        currentIdx = (currentIdx + 1) % CAPACITY;
    }

    // Memperbarui idxTail karena satu elemen dihapus
    (*q).idxTail = ((*q).idxTail - 1 + CAPACITY) % CAPACITY;
}
