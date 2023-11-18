# WayangWave
Tugas Besar Algoritma dan Struktur Data

## Data Structures

### Custom Structures

- Song
  ```
  {
    int PenyayiID,
    int AlbumID,
    int LaguID,
    int PlaylistID
  }
  ```

- Object
  ```
  {
    int ID,
    Word Title
  }
  ```

### ADT

- TabKata Penyanyi
  ```
  [
   Word "Nama Penyanyi 1", 
   Word "Nama Penyanyi 2", 
   . . .
  ]
  ```

- Map Album
  ```
  [
    {
    Key: Word "Nama Penyayi 1",
    Value" Set [
        Object Album_1 {
            int ID_Album_1,
            Word "Nama Album 1"
        },
        Object Album_2 {
            int ID_Album_2,
            Word "Nama Album 2"
        }
    ]
    },{
    Key: Word "Nama Penyayi 2",
    Value" Set [
        Object Album_1 {
            int ID_Album_1,
            Word "Nama Album 1"
        },
        Object Album_2 {
            int ID_Album_2,
            Word "Nama Album 2"
        }
    ]
    }
    . . .
  ]
  ```

- Map Lagu
  ```
  [
    {
    Key: Word "Nama Album 1",
    Value" Set [
        Object Lagu_1 {
            int ID_Lagu_1,
            Word "Nama Lagu 1"
        },
        Object Lagu_2 {
            int ID_Lagu_2,
            Word "Nama Lagu 2"
        }
    ]
    },{
    Key: Word "Nama Album 2",
    Value" Set [
        Object Lagu_1 {
            int ID_Lagu_1,
            Word "Nama Lagu 1"
        },
        Object Lagu_2 {
            int ID_Lagu_2,
            Word "Nama Lagu 2"
        }
    ]
    }
    . . .
  ]
  ```

- ArrayDinWord PlaylistTitle
  ```
  Dynamic Array of Word
  [
    Word "Nama Playlist 1",
    Word "Nama Playlist 2",
    . . .
  ]
  ```

- ArrayDin PlaylistData
  ```
  Dynamic Array of Struktur Berkait
  [
    ListLinier Playlist_1 {
        address First (address pertama Playlist 1)
    },
    ListLinier Playlist_2 {
        address First (address pertama Playlist 2)
    },
    . . .
  ]

  address (Node Struktur Berkait)
  {
    Song Lagu_Ke-1_Playlist {
        int PenyayiID,
        int AlbumID,
        int LaguID,
        int PlaylistID
    },
    address Next (adress Lagu_Ke-2_Playlist)  
  }
  ```