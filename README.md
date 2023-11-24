# WayangWave
Tugas Besar Algoritma dan Struktur Data STI

## Deskripsi Program
WayangWave adalah sebuah aplikasi yang bisa mensimulasikan service  pemutaran musik. Aplikasi ini memiliki fitur utama, yaitu memutar lagu, menampilkan daftar lagu, membuat dan menghapus playlist, mengatur urutan dimainkannya lagu, dan menampilkan status dari aplikasi.

## Anggota Kelompok

|Nama                      |NIM     |
|--------------------------|--------|
|Bobby Dhammawan TANG      |18220037|
|Jihan Aurelia 			       |18222001|
|Benedicta Eryka Santosa   |18222031|
|Firsa Athaya Raissa Alifah|18222051|
|Muhammad Faiz A 	         |18222063|

## Cara Kompilasi

1. Clone repository
```
git clone https://github.com/Bobby-DT/WayangWave.git
```
2. Pergi ke folder WayangWave/bin
```
cd WayangWave/bin
```
3. Ketik `make`, `./make.sh` atau `make.bat` pada terminal
4. Ketik `./WayangWave` atau `./WayangWave.exe` di terminal
5. Program berhasil dijalankan

## Struktur Data

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

- TabKata Penyanyi
  ```
  [
   Word "Nama Penyanyi 1", 
   Word "Nama Penyanyi 2", 
   . . .
  ],
  int Neff
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
  ],
  int Count
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
  ],
  int Count
  ```

- ArrayDinWord PlaylistTitle
  ```
  Dynamic Array of Word
  [
    Word "Nama Playlist 1",
    Word "Nama Playlist 2",
    . . .
  ],
  int Capacity,
  int Neff
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
  ],
  int Capacity,
  int Neff

  address (Node Struktur Berkait)
  {
    Song Lagu_Ke-1_Playlist {
        int PenyanyiID,
        int AlbumID,
        int LaguID,
        int PlaylistID
    },
    address Next (address Lagu_Ke-2_Playlist)  
  }
  ```

- UserData
  ```
  {
    Word Username,
    Song Playing,
    Queue Antrian,
    Stack Riwayat,
    ArrayDinWord PlaylistTitle,
    ArrayDin PlaylistData
  }
  ```

- UserStorage User
  ```
  [
    {
        Word "Username User 1",
        Song Playing_User_1,
        Queue Antrian_User_1,
        Stack Riwayat_User_1,
        ArrayDinWord PlaylistTitle_User_1,
        ArrayDin PlaylistData_User_1
    },{
        Word "Username User 2",
        Song Playing_User_2,
        Queue Antrian_User_2,
        Stack Riwayat_User_2,
        ArrayDinWord PlaylistTitle_User_2,
        ArrayDin PlaylistData_User_2
    },
    . . .
  ],
  int Count
   ```