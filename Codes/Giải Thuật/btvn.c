#include <stdio.h>
#include <stdbool.h>

#define MAX 100



//Xuất mảng
void xuatMang(int a[], int soPhanTuMang) {
    for (int i = 0; i < soPhanTuMang; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

//In các số lẽ và chia hết cho 3
void inSoLeVaChiaHetCho3(int a[], int soPhanTuMang) {
    printf("Cac so le va chia het cho 3 la: ");
    int dem = 0;
    for (int i = 0; i < soPhanTuMang; i++){
        if (a[i] % 2 != 0 && a[i] % 3 == 0)
        {
            printf("%d ", a[i]);
            printf(" -  ");
            dem++;
        }
    }
    if (dem == 0)
    {
        printf("Khong co phan tu nao la so le va chia het cho 3.\n");

    }
    
}


int main() {
    int a[MAX];
    int n;
    while (true) {
        printf("Nhap so phan tu cua mang: ");
        if (scanf("%d", &n) == 1) {
            break;
        } else {
            printf("Vui long nhap so nguyen.\n");
            while (getchar() != '\n');
        }
    }
    nhapMang(a, n);
    xuatMang(a,n);
    inSoLeVaChiaHetCho3(a, n);
    return 0;
}
