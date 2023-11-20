#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "../../boolean.h"
#include "set.h"


void SetCreateEmpty(Set *s) {
    Length(*s) = 0;
}

boolean SetIsEmpty(Set s) {
    return Length(s) == 0;
}

boolean SetIsFull(Set s) {
    return Length(s) == CAPACITY;
}

void SetAdd(Set *s, Object O)
{
    if (!SetIsIn(*s, O) && !SetIsFull(*s)) {
        (*s).buffer[Length(*s)] = O;
        (*s).length++;
    }
}

void SetRemoveElmt(Set *s, Object O) {
    int ElmtIdx = SearchSet(*s, O);
    if (ElmtIdx != -1) {
        for (int i = ElmtIdx; i < Length(*s); i++) {
            (*s).buffer[i] = (*s).buffer[i+1];
        }
        (*s).length--;
    }
}

boolean SetIsIn(Set s, Object O) {
    for (int i = 0; i < Length(s); i++) {
        if (ObjectIsEqual(s.buffer[i], O)) {
            return true;
        }
    }
    return false;
}

int SearchSet(Set s, Object O) {
    int i = 0;
    boolean found = false;
    while (!found && i < Length(s)) {
        if (ObjectIsEqual(s.buffer[i], O)) {
            return i;
        }
        i++;
    }
    return -1;
}

boolean SetsIsEqual(Set s1, Set s2) {
    boolean equal = true;
    int i = 0;
    if (Length(s1) == Length(s2)) {
        while (equal && i < Length(s1)) {
            if (!ObjectIsEqual((s1).buffer[i], (s2).buffer[i])) {
                equal = false;
            }
            i++;
        }
    } else {
        equal = false;
    }

    return equal;
}

Set SetUnion(Set s1, Set s2) {
    Set s3;
    int i;
    SetCreateEmpty(&s3);

    for (i = 0; i < Length(s1); i++) {
        SetAdd(&s3, (s1).buffer[i]);
    }

    i = 0;
    while (i < Length(s2) && Length(s3) < (CAPACITY-1)) {
        if (!SetIsIn(s3, (s2).buffer[i])) {
            SetAdd(&s3, (s2).buffer[i]);
        }
        i++;
    }

    return s3;
}

Set SetIntersection(Set s1, Set s2) {
    Set s3;
    int i;
    SetCreateEmpty(&s3);

    for (i = 0; i < Length(s1); i++) {
        if (SetIsIn(s2, (s1).buffer[i])) {
            SetAdd(&s3, (s1).buffer[i]);
        }
    }

    return s3;
}

Set SetDifference(Set s1, Set s2) {
    Set s3;
    int i;
    SetCreateEmpty(&s3);

    for (i = 0; i < Length(s1); i++) {
        if (!SetIsIn(s2, (s1).buffer[i])) {
            SetAdd(&s3, (s1).buffer[i]);
        }
    }

    return s3;
}

Set SetCopy(Set s) {
    Set copy;
    int i;
    SetCreateEmpty(&copy);

    for (i = 0; i < Length(s); i++) {
        SetAdd(&copy, (s).buffer[i]);
    }

    return copy;
}

boolean SetIsSubset(Set s1, Set s2) {
    return SetIsEmpty(SetDifference(s1, s2));
}

void DisplaySet(Set s) {
    for (int i = 0; i < Length(s)-1; i++) {
        printf("%d. [%d, ",i+1, (s).buffer[i].ID);
        PrintWord((s).buffer[i].Title);
        printf("]\n");
    }
}
