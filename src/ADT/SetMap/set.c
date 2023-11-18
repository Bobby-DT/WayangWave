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
    int i = 0;
    boolean found = false;
    while (!found && i < length(s)) {
        if (ObjectIsEqual(s.buffer[i], O)) {
            found = true;
        }
        i++;
    }
    return found;
}

int SearchSet(Set s, Object O) {
    int i = 0;
    boolean found = false;
    while (!found && i < length(s)) {
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
    if (length(s1) == length(s2)) {
        while (equal && i < length(s1)) {
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
    CreateSet(&s3);

    for (i = 0; i < length(s1); i++) {
        SetAdd(&s3, (s1).buffer[i]);
    }

    i = 0;
    while (i < length(s2) && length(s3) < (CAPACITY-1)) {
        if (!isIn(s3, (s2).buffer[i])) {
            SetAdd(&s3, (s2).buffer[i]);
        }
        i++;
    }

    return s3;
}

Set SetIntersection(Set s1, Set s2) {
    Set s3;
    int i;
    CreateSet(&s3);

    for (i = 0; i < length(s1); i++) {
        if (isIn(s2, (s1).buffer[i])) {
            SetAdd(&s3, (s1).buffer[i]);
        }
    }

    return s3;
}

Set SetDifference(Set s1, Set s2) {
    Set s3;
    int i;
    CreateSet(&s3);

    for (i = 0; i < length(s1); i++) {
        if (!isIn(s2, (s1).buffer[i])) {
            SetAdd(&s3, (s1).buffer[i]);
        }
    }

    return s3;
}

Set SetCopy(Set s) {
    Set copy;
    int i;
    CreateSet(&copy);

    for (i = 0; i < length(s); i++) {
        SetAdd(&copy, (s).buffer[i]);
    }

    return copy;
}

boolean SetIsSubset(Set s1, Set s2) {
    return isEmpty(SetDifference(s1, s2));
}

void DisplaySet(Set s) {
    for (int i = 0; i < length(s)-1; i++) {
        printf("%d. %s\n",(i+1), (s).buffer[i]);
    }
}
