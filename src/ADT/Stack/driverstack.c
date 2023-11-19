#include <stdio.h>
#include "../Lagu/lagu.h"
#include "stack.h"

Song createLagu(int n) {
    return CreateLagu(n, n, n, -1);
}

int main() {
    Song temp;

    printf("Declaring Stack . . .\nStack test;\n\n");
    Stack test;

    printf("Creating Empty Stack . . .\nCreateEmptyStack(&test);\n\n");
    CreateEmptyStack(&test);

    printf("IsEmpty: %d\n", IsEmptyStack(test));
    printf("IsFull: %d\n", IsFullStack(test));
    printf("NbElmtStack: %d\n\n", NbElmtStack(test));

    printf("Pushing random value until full . . .\n\n");

    printf("Pushing stack (random number = 1)\n");
    PushStack(&test, createLagu(1));
    printf("InfoTop(test).PenyanyiID = %d\n", InfoTop(test).PenyanyiID);
    printf("InfoTop(test).AlbumID = %d\n", InfoTop(test).AlbumID);
    printf("InfoTop(test).LaguID = %d\n\n", InfoTop(test).LaguID);

    printf("IsEmpty: %d\n", IsEmptyStack(test));
    printf("IsFull: %d\n", IsFullStack(test));
    printf("NbElmtStack: %d\n\n", NbElmtStack(test));

    printf("Pushing stack 2-99 . . .\n\n");
    for (int i = 2; i < MaxEl; i++) {
        PushStack(&test, createLagu(i));
    }

    printf("Pushing stack (random number = 100)\n");
    PushStack(&test, createLagu(100));
    printf("InfoTop(test).PenyanyiID = %d\n", InfoTop(test).PenyanyiID);
    printf("InfoTop(test).AlbumID = %d\n", InfoTop(test).AlbumID);
    printf("InfoTop(test).LaguID = %d\n\n", InfoTop(test).LaguID);

    printf("IsEmpty: %d\n", IsEmptyStack(test));
    printf("IsFull: %d\n", IsFullStack(test));
    printf("NbElmtStack: %d\n\n", NbElmtStack(test));

    printf("Popping stack until empty . . .\n\n");

    printf("Popping stack . . .\n");
    PopStack(&test, &temp);
    printf("InfoTop(test).PenyanyiID = %d\n", InfoTop(test).PenyanyiID);
    printf("InfoTop(test).AlbumID = %d\n", InfoTop(test).AlbumID);
    printf("InfoTop(test).LaguID = %d\n\n", InfoTop(test).LaguID);

    printf("IsEmpty: %d\n", IsEmptyStack(test));
    printf("IsFull: %d\n", IsFullStack(test));
    printf("NbElmtStack: %d\n\n", NbElmtStack(test));

    printf("Popping stack 99-2 . . .\n\n");
    for (int i = 2; i < MaxEl; i++) {
        PopStack(&test, &temp);
    }

    printf("IsEmpty: %d\n", IsEmptyStack(test));
    printf("IsFull: %d\n", IsFullStack(test));
    printf("NbElmtStack: %d\n\n", NbElmtStack(test));

    printf("Popping stack . . .\n\n");
    PopStack(&test, &temp);

    printf("IsEmpty: %d\n", IsEmptyStack(test));
    printf("IsFull: %d\n", IsFullStack(test));
    printf("NbElmtStack: %d\n\n", NbElmtStack(test));
    return 0;
}