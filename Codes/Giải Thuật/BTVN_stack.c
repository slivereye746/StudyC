#include <stdio.h>
#include <string.h>

#define MAX 100

//Cấu trúc lưu trữ thông tin dự án
typedef struct {
    int maDuAn;
    char tenDuAn[200];
    char diaDiem[300];
    float kinhPhi;
} DuAn;

//Cấu trúc ngăn xếp
typedef struct {
    DuAn arr[MAX];
    int top;
} QuanLyDuAn;

//Khởi tạo ngăn xếp rỗng
void createQuanLyDuAn(QuanLyDuAn *s) {
    s->top = -1;
}

//Kiểm tra rỗng
int isEmpty(QuanLyDuAn *s) {
    return (s->top == -1);
}

//Kiểm tra đầy
int isFull(QuanLyDuAn *s) {
    return (s->top == MAX - 1);
}

//Thêm một phần tử vào ngăn xếp (push)
void push(QuanLyDuAn *s, DuAn p) {
    if (isFull(s)) {
        printf("So luong du an da full!\n");
        return;
    }
    s->arr[++s->top] = p;
}

//Bỏ một phần tử khỏi ngăn xếp (pop)
DuAn pop(QuanLyDuAn *s) {
    DuAn temp;  //Tạo biến tạm để trả về
    if (isEmpty(s)) {
        printf("Khong co du an nao!\n");
        //Có thể xử lý trả về giá trị mặc định hoặc báo lỗi
        return temp;
    }
    temp = s->arr[s->top--];
    return temp;
}

//Hiển thị thông tin một dự án
void printDuAn(DuAn p) {
    printf("Ma du an : %d\n", p.maDuAn);
    printf("Ten du an: %s\n", p.tenDuAn);
    printf("Dia diem : %s\n", p.diaDiem);
    printf("Kinh phi : %.2f\n", p.kinhPhi);
    printf("-----------------------------\n");
}

//Hiển thị các dự án có địa điểm "Thuan Thanh"
void showThuanThanh(QuanLyDuAn *s) {
    int found = 0;
    printf("\n=== Danh sach du an co dia diem 'Thuan Thanh' ===\n");
    for (int i = 0; i <= s->top; i++) {
        if (strcmp(s->arr[i].diaDiem, "Thuan Thanh") == 0) {
            printDuAn(s->arr[i]);
            found = 1;
        }
    }
    if (!found) {
        printf("Khong co du an nao co dia diem 'Thuan Thanh'!\n");
    }
}

//Hiển thị toàn bộ dự án trong ngăn xếp
void showDuAn(QuanLyDuAn *s) {
    if (isEmpty(s)) {
        printf("Ngăn xếp rỗng, không có dự án nào!\n");
        return;
    }
    printf("\nDanh sach tat ca du an\n");
    for (int i = s->top; i >= 0; i--) {
        printDuAn(s->arr[i]);
    }
}

int main() {
    QuanLyDuAn s;
    createQuanLyDuAn(&s);

    int n;
    printf("Nhap so luong du an muon them vao ngan xep: ");
    scanf("%d", &n);
    getchar(); //Đọc ký tự '\n' còn sót lại trong bộ đệm

    for (int i = 0; i < n; i++) {
        DuAn p;
        printf("\nNhap thong tin du an thu %d\n", i + 1);

        printf("Ma du an: ");
        scanf("%d", &p.maDuAn);
        getchar();

        printf("Ten du an: ");
        fgets(p.tenDuAn, sizeof(p.tenDuAn), stdin);// Nhập chuỗi từ bàn phím
        // Xoa ky tu xuong dong neu co
        p.tenDuAn[strcspn(p.tenDuAn, "\n")] = '\0';

        printf("Dia diem: ");
        fgets(p.diaDiem, sizeof(p.diaDiem), stdin);
        p.diaDiem[strcspn(p.diaDiem, "\n")] = '\0';

        printf("Kinh phi: ");
        scanf("%f", &p.kinhPhi);
        getchar();

        push(&s, p);
    }
    showDuAn(&s);
    showThuanThanh(&s);

    return 0;
}
