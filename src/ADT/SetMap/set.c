#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "../../boolean.h"
#include "set.h"


void SetCreateEmpty(Set *s) {
    Length(*s) = 0;
}

boolean SetIsEmpty(Set s)
{
    return Length(s) == 0;
}

int SetLength(Set s)
{
    return Length(s);
}

void SetAdd(Set *s, Word)
{
    if (!isIn(*s, Elmt)) {
        int i = 0;
        while (Elmt[i] != '\0') {
            s->buffer[length(*s)][i] = Elmt[i];
            i++;
        }
        s->length = s->length + 1;
    }
}

void SetRemoveElmt(Set *s, Word)
{
    int i = 0, j, it;
    boolean found = false;
    while (!found && i < Length(*s)) {
        if (s->buffer[i] == Elmt) {
            for (j = i; j < (Length(*s) - 1); j++) {
                it = 0;
                while (s->buffer[j+1][it] != '\0') {
                    s->buffer[j][it] = s->buffer[j+1][it];
                    it++;
                }
            }
            s->length = s->length - 1;
            found = true;
        }
        i++;
    }
}

boolean SetIsIn(Set s, Word) {
    int i = 0;
    size_t j;
    boolean equal= false;
    while (!equal && i < length(s)) {
        j = 0;
        equal = true;
        while ((s).buffer[i][j] != '\0' && equal) {
            if ((s).buffer[i][j] != Elmt[j])
                equal = false;
            j++;
        }
        i++;
    }

    return equal;
}

boolean SetsIsEqual(Set s1, Set s2) {
    boolean equal = true;
    int i = 0;
    if (length(s1) == length(s2)) {
        while (equal && i < length(s1)) {
            if ((s1).buffer[i] != (s2).buffer[i]) {
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
        add(&s3, (s1).buffer[i]);
    }

    i = 0;
    while (i < length(s2) && length(s3) < (CAPACITY-1)) {
        if (!isIn(s3, (s2).buffer[i])) {
            add(&s3, (s2).buffer[i]);
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
            add(&s3, (s1).buffer[i]);
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
            add(&s3, (s1).buffer[i]);
        }
    }

    return s3;
}

Set SetCopy(Set s) {
    Set copy;
    int i;
    CreateSet(&copy);

    for (i = 0; i < length(s); i++) {
        add(&copy, (s).buffer[i]);
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
