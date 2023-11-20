#include <stdio.h>
#include <stdlib.h>
#include "arraydinword.h"

ArrayDinWord MakeArrayDinWord(){
	ArrayDinWord array;
	array.A = (Word*) malloc (InitialSize*sizeof(Word));
	array.Neff = 0; array.Capacity = InitialSize;
	return array;
}

void DeallocateArrayDinWord(ArrayDinWord *array) {
	free((*array).A); (*array).Neff = 0;
}

boolean IsEmptyArrayDinWord(ArrayDinWord array) {
	return array.Neff == 0;
}

int LengthArrayDinWord(ArrayDinWord array) {
	return array.Neff;
}

Word GetArrayDinWord(ArrayDinWord array, int i) {
	return array.A[i];
}

int GetCapacityArrayDinWord(ArrayDinWord array) {
	return array.Capacity;
}

void InsertAtArrayDinWord(ArrayDinWord *array, Word el, int i) {
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
        Word *temp = (Word *)malloc((*array).Capacity* sizeof(Word));
        for (j = 0; j < (*array).Capacity; j++)
        {
            temp[j] = (*array).A[j];
        }
        free((*array).A);
        (*array).A = (Word *)malloc(((*array).Capacity * 2 ) *sizeof(Word));
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

void InsertLastArrayDinWord(ArrayDinWord *array, Word el) {
	InsertAtArrayDinWord(array, el,(*array).Neff);
}

void InsertFirstArrayDinWord(ArrayDinWord *array, Word el) {
	InsertAtArrayDinWord(array, el, 0);
}

void DeleteAtArrayDinWord(ArrayDinWord *array, int i) {
    int j;
    Word e = GetArrayDinWord(*array, i);
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
        Word *temp = (Word *)malloc(Bcapacity * sizeof(Word));
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
        (*array).A = (Word *)malloc(Bcapacity * sizeof(Word));
        for (j = 0; j < (*array).Neff; j++)
        {
            (*array).A[j] = temp[j];
        }
        (*array).Capacity = Bcapacity;
        free(temp);
    }
}

void DeleteLastArrayDinWord(ArrayDinWord *array) {
	DeleteAtArrayDinWord(array, (*array).Neff-1);
}

void DeleteFirstArrayDinWord(ArrayDinWord *array) {
	DeleteAtArrayDinWord(array, 0);
}

void PrintArrayDinWord(ArrayDinWord array) {
	int j;
	printf("[");
	for (j = 0; j < (array).Neff; j++) {
		PrintWord((array).A[j]);
		if (j != (array).Neff -1) {
			printf(", ");
		}
	}
	printf("]\n");
}

void ReverseArrayDinWord(ArrayDinWord *array) {
	int j;
	Word *temp = (Word*) malloc ((*array).Capacity * sizeof(Word));
	for (j = 0; j < (*array).Neff; j++) {
		temp[j] = (*array).A[(*array).Neff - (1+j)];
	}
	for (j = 0; j < (*array).Neff; j++) {
		(*array).A[j] = temp[j];
	}
	free(temp);
}

ArrayDinWord CopyArrayDinWord(ArrayDinWord array) {
	ArrayDinWord newArray;
	int j;
	newArray.A = (Word*) malloc (array.Capacity * sizeof(Word));
	newArray.Capacity = array.Capacity; newArray.Neff = array.Neff;
	for (j = 0; j < newArray.Neff; j++) {
		newArray.A[j] = array.A[j];
	}
	return newArray;
}

int SearchArrayDinWord(ArrayDinWord array, Word el) {
	int j = 0;
	while (!WordCompare((array).A[j], el) && (j <= (array).Neff)) {
		j++;
	}
	if (j > (array).Neff) {
		j = -1;
	}
	return j;
}