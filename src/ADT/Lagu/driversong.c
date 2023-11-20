#include <stdio.h>
#include "../../boolean.h"
#include "../Mesin/mesinkata.h"
#include "song.h"

int main() {
    printf("Testing Song structure . . .\n\n");
    printf("Declaring Song . . .\nSong newSong;\n\n");
    Song newSong;
    printf("Creating Empty Song . . .\nCreateEmptyLagu(&newSong);\n\n");
    CreateEmptyLagu(&newSong);
    printf("newSong = CreateLagu(1, 2, 3, -1);\n\n");
    newSong = CreateLagu(1, 2, 3, -1);
    printf("newSong.PenyanyiID: %d\n", newSong.PenyanyiID);
    printf("newSong.AlbumID: %d\n", newSong.AlbumID);
    printf("newSong.LaguID: %d\n", newSong.LaguID);
    printf("newSong.PlaylistID: %d\n\n", newSong.PlaylistID);

    printf("Declaring 2nd Song . . .\nSong newSong2;\n\n");
    Song newSong2;
    printf("Creating 2nd Empty Song . . .\nCreateEmptyLagu(&newSong2);\n\n");
    CreateEmptyLagu(&newSong2);
    printf("SongIsEqual(newSong, newSong2): %d\n\n", SongIsEqual(newSong, newSong2));
    printf("newSong2 = CreateLagu(1, 2, 3, -1);\n\n");
    newSong2 = CreateLagu(1, 2, 3, -1);
    printf("newSong2.PenyanyiID: %d\n", newSong2.PenyanyiID);
    printf("newSong2.AlbumID: %d\n", newSong2.AlbumID);
    printf("newSong2.LaguID: %d\n", newSong2.LaguID);
    printf("newSong2.PlaylistID: %d\n\n", newSong2.PlaylistID);

    printf("SongIsEqual(newSong, newSong2): %d\n\n", SongIsEqual(newSong, newSong2));

    printf("Testing Object structure . . .\n\n");
    printf("Declaring Object . . .\nObject newObject;\n\n");
    Object newObject;
    printf("Creating Object . . .\nnewObject = CreateObject(1, toKata('Title'));\n\n");
    newObject = CreateObject(1, toKata("Title"));
    printf("newObject.ID: %d\n", newObject.ID);
    printf("newObject.Title: ");
    PrintWord(newObject.Title);
    printf("\n\n");
    printf("Declaring 2nd Object . . .\nObject newObject2;\n\n");
    Object newObject2;
    printf("ObjectIsEqual(newObject, newObject2): %d\n\n", ObjectIsEqual(newObject, newObject2));
    printf("Creating 2nd Object . . .\nnewObject2 = CreateObject(1, toKata('Title'));\n\n");
    newObject2 = CreateObject(1, toKata("Title"));
    printf("newObject2.ID: %d\n", newObject2.ID);
    printf("newObject2.Title: ");
    PrintWord(newObject2.Title);
    printf("\n\n");

    printf("ObjectIsEqual(newObject, newObject2): %d\n", ObjectIsEqual(newObject, newObject2));
    return 0;
}