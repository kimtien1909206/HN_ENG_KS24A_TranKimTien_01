#include <stdio.h>
#include <string.h>

struct Sach {
    char maSach[20];
    char tenSach[100];
    char tacGia[50];
    float giaTien;
    char theLoai[50];
};

void nhapThongTinSach(struct Sach *sach) {
    printf("Nhap ma sach: ");
    scanf("%s", sach->maSach);
    printf("Nhap ten sach: ");
    getchar(); 
    fgets(sach->tenSach, 100, stdin);
    sach->tenSach[strcspn(sach->tenSach, "\n")] = 0; 
    printf("Nhap tac gia: ");
    fgets(sach->tacGia, 50, stdin);
    sach->tacGia[strcspn(sach->tacGia, "\n")] = 0; 
    printf("Nhap gia tien: ");
    scanf("%f", &sach->giaTien);
    printf("Nhap the loai: ");
    getchar();
    fgets(sach->theLoai, 50, stdin);
    sach->theLoai[strcspn(sach->theLoai, "\n")] = 0; 
}

void hienThiThongTinSach(struct Sach *sach) {
    printf("%-20s %-30s %-30s %-10.2f %-20s\n", sach->maSach, sach->tenSach, sach->tacGia, sach->giaTien, sach->theLoai);
}

void themSach(struct Sach *sach, int *n, int viTri) {
    for (int i = *n; i > viTri; i--) {
        sach[i] = sach[i - 1];
    }
    nhapThongTinSach(&sach[viTri]);
    (*n)++;
}

void xoaSach(struct Sach *sach, int *n, char *maSach) {
    for (int i = 0; i < *n; i++) {
        if (strcmp(sach[i].maSach, maSach) == 0) {
            for (int j = i; j < *n - 1; j++) {
                sach[j] = sach[j + 1];
            }
            (*n)--;
            return;
        }
    }
    printf("Khong tim thay ma sach!\n");
}

void capNhatSach(struct Sach *sach, int n, char *maSach) {
    for (int i = 0; i < n; i++) {
        if (strcmp(sach[i].maSach, maSach) == 0) {
            printf("Cap nhat thong tin sach\n");
            nhapThongTinSach(&sach[i]);
            return;
        }
    }
    printf("Khong tim thay ma sach!\n");
}

void sapXepTheoGia(struct Sach *sach, int n, int chon) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if ((chon == 1 && sach[i].giaTien > sach[j].giaTien) || (chon == 2 && sach[i].giaTien < sach[j].giaTien)) {
                struct Sach temp = sach[i];
                sach[i] = sach[j];
                sach[j] = temp;
            }
        }
    }
}

void timKiemSach(struct Sach *sach, int n, char *tenSach) {
    int found = 0;
    for (int i = 0; i < n; i++) {
        if (strstr(sach[i].tenSach, tenSach) != NULL) {
            hienThiThongTinSach(&sach[i]);
            found = 1;
        }
    }
    if (!found) {
        printf("Khong tim thay sach co ten: %s\n", tenSach);
    }
}

int main() {
    struct Sach sach[100];
    int n = 0;
    int luaChon;
    char maSach[20], tenSach[100];
    int viTri;

    do {
        printf("\nMENU\n");
        printf("1. Nhap so luong va thong tin sach.\n");
        printf("2. Hien thi thong tin sach.\n");
        printf("3. Them sach vao vi tri.\n");
        printf("4. Xoa sach theo ma sach.\n");
        printf("5. Cap nhat thong tin sach theo ma sach.\n");
        printf("6. Sap xep sach theo gia (tang/giam).\n");
        printf("7. Tim kiem sach theo ten sach.\n");
        printf("8. Thoat.\n");
        printf("Lua chon cua ban: ");
        scanf("%d", &luaChon);

        switch (luaChon) {
            case 1:
                printf("Nhap so luong sach: ");
                scanf("%d", &n);
                for (int i = 0; i < n; i++) {
                    printf("Nhap thong tin sach %d:\n", i + 1);
                    nhapThongTinSach(&sach[i]);
                }
                break;

            case 2:
                printf("\n%-20s %-30s %-30s %-10s %-20s\n", "Ma Sach", "Ten Sach", "Tac Gia", "Gia Tien", "The Loai");
                for (int i = 0; i < n; i++) {
                    hienThiThongTinSach(&sach[i]);
                }
                break;

            case 3:
                printf("Nhap vi tri can them sach: ");
                scanf("%d", &viTri);
                if (viTri < 0 || viTri > n) {
                    printf("Vi tri khong hop le!\n");
                } else {
                    themSach(sach, &n, viTri);
                }
                break;

            case 4:
                printf("Nhap ma sach can xoa: ");
                scanf("%s", maSach);
                xoaSach(sach, &n, maSach);
                break;

            case 5:
                printf("Nhap ma sach can cap nhat: ");
                scanf("%s", maSach);
                capNhatSach(sach, n, maSach);
                break;

            case 6:
                printf("Chon 1 de sap xep tang gia, 2 de sap xep giam gia: ");
                int chon;
                scanf("%d", &chon);
                sapXepTheoGia(sach, n, chon);
                break;

            case 7:
                printf("Nhap ten sach can tim: ");
                getchar();
                fgets(tenSach, 100, stdin);
                tenSach[strcspn(tenSach, "\n")] = 0;
                timKiemSach(sach, n, tenSach);
                break;

            case 8:
                printf("Thoat chuong trinh!\n");
                break;

            default:
                printf("Lua chon khong hop le!\n");
        }

    } while (luaChon != 8);

    return 0;
}


