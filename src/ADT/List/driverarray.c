#include <stdio.h>
#include "../../boolean.h"
#include "../Mesin/mesinkata.h"
#include "array.h"

int main() {
    printf("Declaring TabKata . . .\nTabKata newList;\n\n");
    TabKata newList;
    printf("Creating Empty TabKata . . .\nMakeEmpty(&newList);\n\n");
    MakeEmpty(&newList);

    printf("NbElmt(newList): %d\n", NbElmt(newList));
    printf("MaxNbEl(newList): %d\n", MaxNbEl(newList));
    printf("GetFirstIdx(newList): %d\n", GetFirstIdx(newList));
    printf("GetLastIdx(newList): %d\n\n", GetLastIdx(newList));
    
    printf("IsIdxValid(newList, 50): %d\n", IsIdxValid(newList, 50));
    printf("IsIdxEff(newList, 0): %d\n", IsIdxEff(newList, 0));
    printf("IsEmpty(newList): %d\n", IsEmpty(newList));
    printf("IsFull(newList): %d\n\n", IsFull(newList));

    printf("SetEl(&newList, 0, toKata('Test 1')):\n");
    SetEl(&newList, 0, toKata("Test 1"));
    printf("IsIdxEff(newList, 0): %d\n", IsIdxEff(newList, 0));
    printf("IsIdxEff(newList, 1): %d\n", IsIdxEff(newList, 1));
    printf("IsEmpty(newList): %d\n", IsEmpty(newList));
    printf("IsFull(newList): %d\n", IsFull(newList));
    printf("GetLastIdx(newList): %d\n\n", GetLastIdx(newList));

    printf("SetEl(&newList, 1, toKata('Test 2')):\n");
    SetEl(&newList, 1, toKata("Test 2"));
    printf("IsIdxEff(newList, 1): %d\n", IsIdxEff(newList, 1));
    printf("IsIdxEff(newList, 2): %d\n", IsIdxEff(newList, 2));
    printf("IsEmpty(newList): %d\n", IsEmpty(newList));
    printf("IsFull(newList): %d\n", IsFull(newList));
    printf("GetLastIdx(newList): %d\n\n", GetLastIdx(newList));

    printf("IsMember(newList, toKata('Test 2')): %d\n", IsMember(newList, toKata("Test 1")));
    printf("searchList(newList, toKata('Test 2')): %d\n", searchList(newList, toKata("Test 2")));
    return 0;
}