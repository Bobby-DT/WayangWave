#include <stdio.h>
#include <stdlib.h>
#include "arraydin.h"

ArrayDin MakeArrayDin(){
	ArrayDin array;
	array.A = (ElTypeArrDin*) malloc (InitialSize*sizeof(ElTypeArrDin));
	array.Neff = 0; array.Capacity = InitialSize;
	return array;
}

void DeallocateArrayDin(ArrayDin *array) {
	free((*array).A); (*array).Neff = 0;
}

boolean IsEmptyArrayDin(ArrayDin array) {
	return array.Neff == 0;
}

int LengthArrayDin(ArrayDin array) {
	return array.Neff;
}

ElTypeArrDin GetArrayDin(ArrayDin array, IdxType i) {
	return array.A[i];
}

int GetCapacityArrayDin(ArrayDin array) {
	return array.Capacity;
}

void InsertAtArrayDin(ArrayDin *array, ElTypeArrDin el, IdxType i) {
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
        ElTypeArrDin *temp = (ElTypeArrDin *)malloc((*array).Capacity* sizeof(ElTypeArrDin));
        for (j = 0; j < (*array).Capacity; j++)
        {
            temp[j] = (*array).A[j];
        }
        free((*array).A);
        (*array).A = (ElTypeArrDin *)malloc(((*array).Capacity * 2 ) *sizeof(ElTypeArrDin));
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

void InsertLastArrayDin(ArrayDin *array, ElTypeArrDin el) {
	InsertAtArrayDin(array, el,(*array).Neff);
}

void InsertFirstArrayDin(ArrayDin *array, ElTypeArrDin el) {
	InsertAtArrayDin(array, el, 0);
}

void DeleteAtArrayDin(ArrayDin *array, IdxType i) {
    int j;
    ElTypeArrDin e = Get(*array, i);
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
        ElTypeArrDin *temp = (ElTypeArrDin *)malloc(Bcapacity * sizeof(ElTypeArrDin));
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
        (*array).A = (ElTypeArrDin *)malloc(Bcapacity * sizeof(ElTypeArrDin));
        for (j = 0; j < (*array).Neff; j++)
        {
            (*array).A[j] = temp[j];
        }
        (*array).Capacity = Bcapacity;
        free(temp);
    }
}

void DeleteLastArrayDin(ArrayDin *array) {
	DeleteAtArrayDin(array, (*array).Neff-1);
}

void DeleteFirstArrayDin(ArrayDin *array) {
	DeleteAtArrayDin(array, 0);
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
	ElTypeArrDin *temp = (ElTypeArrDin*) malloc ((*array).Capacity * sizeof(ElTypeArrDin));
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
	newArray.A = (ElTypeArrDin*) malloc (array.Capacity * sizeof(ElTypeArrDin));
	newArray.Capacity = array.Capacity; newArray.Neff = array.Neff;
	for (j = 0; j < newArray.Neff; j++) {
		newArray.A[j] = array.A[j];
	}
	return newArray;
}

IdxType SearchArrayDin(ArrayDin array, ElTypeArrDin el) {
	IdxType j = 0;
	while (!WordCompare((array).A[j], el) && (j <= (array).Neff)) {
		j++;
	}
	if (j > (array).Neff) {
		j = -1;
	}
	return j;
}