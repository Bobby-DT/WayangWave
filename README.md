# WayangWave
Tugas Besar Algoritma dan Struktur Data

*Anggota Kelompok*
Bobby Dhammawan TANG 		    - 18220037
Jihan Aurelia 				      - 18222001
Benedicta Eryka Santosa 		- 18222031
Firsa Athaya Raissa Alifah 	- 18222051
Muhammad Faiz Atharrahman 	- 18222063

## Deskripsi Program
WayangWave adalah sebuah aplikasi yang bisa mensimulasikan service  pemutaran musik. Aplikasi ini memiliki fitur utama, yaitu memutar lagu, menampilkan daftar lagu, membuat dan menghapus playlist, mengatur urutan dimainkannya lagu, dan menampilkan status dari aplikasi.

## Cara Kompilasi

### Di Terminal Windows
1. Ketik `cd bin` di terminal untuk membuka folder bin
2. Copy paste kode yang ada pada bagian `make.bat` ke terminal
3. Ketika `./WayangWave.exe` di terminal
4. Program berhasil dijalankan

## Data Structures

### Custom Structures

- Song
  ```
  {
    int PenyanyiID,
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
    Key: Word "Nama Penyanyi 1",
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
    Key: Word "Nama Penyanyi 2",
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
        int PenyanyiID,
        int AlbumID,
        int LaguID,
        int PlaylistID
    },
    address Next (adress Lagu_Ke-2_Playlist)  
  }
  ```