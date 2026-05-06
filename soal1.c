/** EL2008 Praktikum Pemecahan Masalah dengan Pemrograman 2025/2026
 *   Modul               : 04 - Dynamic Structures
 *   Hari dan Tanggal    : Rabu, 6 Mei 2026
 *   Nama (NIM)          : Abdullah (13224101)
 *   Nama File           : Prak4_1.c
 *   Deskripsi           : Program menerima input jumlah data (N), nama pasien, dan durasi rawat pasien, kemudian memberikan
 *                         output berupa total durasi tunggu dan urutan antrian.
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Pasien{
    char nama[50];
    int durasi;
    struct Pasien *next;
}Pasien;

void tampilkanPasien(int N, Pasien *orang){
    printf("ORDER ");
    for (int i = 0; i < N; i++){
        printf("%s ", orang[i].nama);
    }
    printf("\n");
}

int jumlahkanWaktu(int N, Pasien *orang){
    int hasil = 0;
    for(int i = 0; i<N; i++){
            hasil = hasil + orang[i].durasi;
    }
    return hasil;
}

int tampilkanWaktu(int N, Pasien *orang){
    int totalWaktu = 0;
    for (int i = 0; i < N; i++){
        totalWaktu = totalWaktu + jumlahkanWaktu(i, orang);
    }   
    printf("WAIT %d\n", totalWaktu);
}

int main(){
    struct Pasien *orang = NULL;
    int N;
    scanf("%d ", &N);

    orang = (Pasien *)malloc(N * sizeof(Pasien));

    for (int i = 0; i < N; i++){
        scanf("%s %d", orang[i].nama, &orang[i].durasi);
    }

    tampilkanPasien(N, orang);
    tampilkanWaktu(N, orang);

}
