#include <stdio.h>
#include <stdlib.h>
/* ***************************************************
         DINAMIK BELLEK ILE MATRIS CARPIM UYGULAMASI
******************************************************/


// Matris için dinamik bellek ayirma
int** matrisOlustur(int satir, int sutun) {
    int** matris = (int**)malloc(satir * sizeof(int*));
    for (int i = 0; i < satir; i++) {
        matris[i] = (int*)malloc(sutun * sizeof(int));
    }
    return matris;
}

// Matrisi temizleme 
void matrisSil(int** matris, int satir) {
    for (int i = 0; i < satir; i++) {
        free(matris[i]);
    }
    free(matris);
}

// Matris degerlerini kullanicidan alma
void matrisDegerAl(int** matris, int satir, int sutun, char isim) {
    printf("\n%c matrisinin elemanlarini girin:\n", isim);
    for (int i = 0; i < satir; i++) {
        for (int j = 0; j < sutun; j++) {
            printf("%c[%d][%d]: ", isim, i, j);
            scanf("%d", &matris[i][j]);
        }
    }
}

// Matrisi yazdirma
void matrisYazdir(int** matris, int satir, int sutun) {
    for (int i = 0; i < satir; i++) {
        for (int j = 0; j < sutun; j++) {
            printf("%4d ", matris[i][j]);
        }
        printf("\n");
    }
}

// Matris çarpimi
// MANTIK: Birinci matrisin SATIR elemanlari ile Ikinci matrisin SUTUN elemanlari
// sirasiyla carpilir ve toplanir.
// Formul: C[i][j] = Toplam(A[i][k] * B[k][j])
int** matrisCarp(int** A, int** B, int satir1, int sutun1, int sutun2) {
    int** C = matrisOlustur(satir1, sutun2);
    
    for (int i = 0; i < satir1; i++) {
        for (int j = 0; j < sutun2; j++) {
            C[i][j] = 0;
            for (int k = 0; k < sutun1; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    
    return C;
}

int main() {
    int satir1, sutun1, satir2, sutun2;
    
    printf("=== MATRIS CARPIMI PROGRAMI ===\n\n");
    
    // Ilk matris boyutlari
    printf("Birinci matrisin satir sayisi: ");
    scanf("%d", &satir1);
    printf("Birinci matrisin sutun sayisi: ");
    scanf("%d", &sutun1);
    
    // Ikinci matris boyutlari
    printf("Ikinci matrisin satir sayisi: ");
    scanf("%d", &satir2);
    printf("Ikinci matrisin sutun sayisi: ");
    scanf("%d", &sutun2);
    
    // Çarpim kontrolü
    if (sutun1 != satir2) {
        printf("\nHATA: Matris carpimi yapilamaz!\n");
        printf("Birinci matrisin sutun sayisi (%d), ikinci matrisin satir sayisina (%d) esit olmali.\n", 
               sutun1, satir2);
        return 1;
    }
    
    // Matrisleri olustur
    int** A = matrisOlustur(satir1, sutun1);
    int** B = matrisOlustur(satir2, sutun2);
    
    // Degerleri al
    matrisDegerAl(A, satir1, sutun1, 'A');
    matrisDegerAl(B, satir2, sutun2, 'B');
    
    // Matrisleri göster
    printf("\nA Matrisi (%dx%d):\n", satir1, sutun1);
    matrisYazdir(A, satir1, sutun1);
    
    printf("\nB Matrisi (%dx%d):\n", satir2, sutun2);
    matrisYazdir(B, satir2, sutun2);
    
    // Çarpim islemi
    int** C = matrisCarp(A, B, satir1, sutun1, sutun2);
    
    printf("\nSonuc Matrisi C = A x B (%dx%d):\n", satir1, sutun2);
    matrisYazdir(C, satir1, sutun2);
    
    // Bellegi temizle 
    matrisSil(A, satir1);
    matrisSil(B, satir2);
    matrisSil(C, satir1);
    
    printf("\nProgram basariyla tamamlandi.\n");
    
    return 0;
}
