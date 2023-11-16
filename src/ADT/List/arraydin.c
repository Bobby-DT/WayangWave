#include <stdio.h>
#include <stdlib.h>
#include "arraydin.h"

ArrayDin MakeArrayDin(){
	ArrayDin array;
	array.A = (ElType*) malloc (InitialSize*sizeof(ElType));
	array.Neff = 0; array.Capacity = InitialSize;
	return array;
}

void DeallocateArrayDin(ArrayDin *array) {
	free((*array).A); (*array).Neff = 0;
}

boolean IsEmpty(ArrayDin array) {
	return array.Neff == 0;
}

int Length(ArrayDin array) {
	return array.Neff;
}

ElType Get(ArrayDin array, IdxType i) {
	return array.A[i];
}

int GetCapacity(ArrayDin array) {
	return array.Capacity;
}

void InsertAt(ArrayDin *array, ElType el, IdxType i) {
	int j;
    if ((*array).Neff < (*array).Capacity)
    {
        for (j = (*array).Neff; j >= i + 1; j--)
        {
            (*array).A[j] = (*array).A[j - 1];
        }
        (*array).A[i] = el;
        (*array).Neff += 1;
    }
    else
    {
        ElType *temp = (ElType *)malloc((*array).Capacity* sizeof(ElType));
        for (j = 0; j < (*array).Capacity; j++)
        {
            temp[j] = (*array).A[j];
        }
        free((*array).A);
        (*array).A = (ElType *)malloc(((*array).Capacity * 2 ) *sizeof(ElType));
        for (j = 0; j < i; j++)
        {
            (*array).A[j] = temp[j];
        }
        (*array).A[i] = el;
        for (j = i; j < (*array).Capacity; j++)
        {
            (*array).A[j + 1] = temp[j];
        }
        free(temp);
        (*array).Capacity *= 2;
        (*array).Neff += 1;
    }
}

void InsertLast(ArrayDin *array, ElType el) {
	InsertAt(array, el,(*array).Neff);
}

void InsertFirst(ArrayDin *array, ElType el) {
	InsertAt(array, el, 0);
}

void DeleteAt(ArrayDin *array, IdxType i) {
    int j;
    ElType e = Get(*array, i);
    if ((*array).Neff > ((*array).Capacity / 4))
    {
        (*array).Neff -= 1;
        for (j = i; j < (*array).Neff; j++)
        {
            (*array).A[j] = (*array).A[j + 1];
        }
    }
    else
    {
        int Bcapacity = InitialSize;
        if (Bcapacity < ((*array).Capacity / 2)) Bcapacity = (*array).Capacity / 2;
        ElType *temp = (ElType *)malloc(Bcapacity * sizeof(ElType));
        for (j = 0; j < i; j++)
        {
            temp[j] = (*array).A[j];
        }
        (*array).Neff -= 1;
        for (j = i; j < (*array).Neff; j++)
        {
            temp[j] = (*array).A[j + 1];
        }
        free((*array).A);
        (*array).A = (ElType *)malloc(Bcapacity * sizeof(ElType));
        for (j = 0; j < (*array).Neff; j++)
        {
            (*array).A[j] = temp[j];
        }
        (*array).Capacity = Bcapacity;
        free(temp);
    }
}

void DeleteLast(ArrayDin *array) {
	DeleteAt(array, (*array).Neff-1);
}

void DeleteFirst(ArrayDin *array) {
	DeleteAt(array, 0);
}

void PrintArrayDin(ArrayDin array) {
	IdxType j;
	printf("[");
	for (j = 0; j < (array).Neff; j++) {
		printf("%d", (array).A[j]);
		if (j != (array).Neff -1) {
			printf(", ");
		}
	}
	printf("]\n");
}

void ReverseArrayDin(ArrayDin *array) {
	IdxType j;
	ElType *temp = (ElType*) malloc ((*array).Capacity * sizeof(ElType));
	for (j = 0; j < (*array).Neff; j++) {
		temp[j] = (*array).A[(*array).Neff - (1+j)];
	}
	for (j = 0; j < (*array).Neff; j++) {
		(*array).A[j] = temp[j];
	}
	free(temp);
}

ArrayDin CopyArrayDin(ArrayDin array) {
	ArrayDin newArray;
	IdxType j;
	newArray.A = (ElType*) malloc (array.Capacity * sizeof(ElType));
	newArray.Capacity = array.Capacity; newArray.Neff = array.Neff;
	for (j = 0; j < newArray.Neff; j++) {
		newArray.A[j] = array.A[j];
	}
	return newArray;
}

IdxType SearchArrayDin(ArrayDin array, ElType el) {
	IdxType j = 0;
	while (!WordCompare((array).A[j], el) && (j <= (array).Neff)) {
		j++;
	}
	if (j > (array).Neff) {
		j = -1;
	}
	return j;
}