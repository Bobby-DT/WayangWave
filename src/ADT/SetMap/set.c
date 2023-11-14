#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "../../boolean.h"
#include "set.h"


void CreateSet(Set *s) {
    Length(*s) = 0;
}

boolean isEmpty(Set s)
{
    return Length(s) == 0;
}

int length(Set s)
{
    return Length(s);
}

void add(Set *s, char Elmt[])
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

void removeElmt(Set *s, char Elmt[])
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

boolean isIn(Set s, char Elmt[]) {
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

boolean isEqual(Set s1, Set s2) {
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

Set unionSet(Set s1, Set s2) {
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

Set intersectionSet(Set s1, Set s2) {
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

Set setDifference(Set s1, Set s2) {
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

Set copySet(Set s) {
    Set copy;
    int i;
    CreateSet(&copy);

    for (i = 0; i < length(s); i++) {
        add(&copy, (s).buffer[i]);
    }

    return copy;
}

boolean isSubset(Set s1, Set s2) {
    return isEmpty(setDifference(s1, s2));
}

void displaySet(Set s) {
    printf("{");
    for (int i = 0; i < length(s)-1; i++) {
        printf("%s,", (s).buffer[i]);
    }
    printf("%s", (s).buffer[length(s)-1]);
    printf("}\n");
}
