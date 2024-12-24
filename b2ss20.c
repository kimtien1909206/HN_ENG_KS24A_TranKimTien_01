#include <stdio.h>
#include <string.h>

struct SanPham {
    char maSP[20];
    char tenSP[100];
    float giaNhap;
    float giaBan;
    int soLuong;
};

void nhapThongTinSanPham(struct SanPham *sp) {
    printf("Nhap ma san pham: ");
    scanf("%s", sp->maSP);
    printf("Nhap ten san pham: ");
    getchar(); 
    fgets(sp->tenSP, 100, stdin);
    sp->tenSP[strcspn(sp->tenSP, "\n")] = 0; 
    printf("Nhap gia nhap: ");
    scanf("%f", &sp->giaNhap);
    printf("Nhap gia ban: ");
    scanf("%f", &sp->giaBan);
    printf("Nhap so luong: ");
    scanf("%d", &sp->soLuong);
}

void hienThiThongTinSanPham(struct SanPham *sp) {
    printf("%-20s %-30s %-10.2f %-10.2f %-10d\n", sp->maSP, sp->tenSP, sp->giaNhap, sp->giaBan, sp->soLuong);
}

void nhapSanPham(struct SanPham *sp, int *n, float *doanhThu) {
    for (int i = 0; i < *n; i++) {
        if (strcmp(sp[i].maSP, sp[*n].maSP) == 0) {
            sp[i].soLuong += sp[*n].soLuong;
            *doanhThu -= sp[*n].soLuong * sp[*n].giaNhap; 
            return;
        }
    }
    (*n)++;
    *doanhThu -= sp[*n].soLuong * sp[*n].giaNhap; 
}
void capNhatThongTinSanPham(struct SanPham *sp, int n, char *maSP) {
    for (int i = 0; i < n; i++) {
        if (strcmp(sp[i].maSP, maSP) == 0) {
            printf("Cap nhat thong tin san pham\n");
            nhapThongTinSanPham(&sp[i]);
            return;
        }
    }
    printf("Khong tim thay san pham co ma: %s\n", maSP);
}
void sapXepSanPham(struct SanPham *sp, int n, int chon) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if ((chon == 1 && sp[i].giaBan > sp[j].giaBan) || (chon == 2 && sp[i].giaBan < sp[j].giaBan)) {
                struct SanPham temp = sp[i];
                sp[i] = sp[j];
                sp[j] = temp;
            }
        }
    }
}
void timKiemSanPham(struct SanPham *sp, int n, char *tenSP) {
    int found = 0;
    for (int i = 0; i < n; i++) {
        if (strstr(sp[i].tenSP, tenSP) != NULL) {
            hienThiThongTinSanPham(&sp[i]);
            found = 1;
        }
    }
    if (!found) {
        printf("Khong tim thay san pham co ten: %s\n", tenSP);
    }
}
void banSanPham(struct SanPham *sp, int *n, float *doanhThu, char *maSP, int soLuongBan) {
    for (int i = 0; i < *n; i++) {
        if (strcmp(sp[i].maSP, maSP) == 0) {
            if (sp[i].soLuong == 0) {
                printf("San pham %s da het hang.\n", maSP);
                return;
            }
            if (soLuongBan > sp[i].soLuong) {
                printf("Khong co du so luong san pham %s de ban.\n", maSP);
                return;
            }
            sp[i].soLuong -= soLuongBan; 
            *doanhThu += soLuongBan * sp[i].giaBan; 
            printf("Ban %d san pham %s thanh cong.\n", soLuongBan, maSP);
            return;
        }
    }
    printf("San pham khong ton tai.\n");
}

int main() {
    struct SanPham sp[100];
    int n = 0;
    float doanhThu = 0;
    int luaChon;
    char maSP[20], tenSP[100];
    int soLuongBan;

    do {
        printf("\nMENU\n");
        printf("1. Nhap so luong va thong tin san pham.\n");
        printf("2. Hien thi danh sach san pham.\n");
        printf("3. Nhap san pham.\n");
        printf("4. Cap nhat thong tin san pham.\n");
        printf("5. Sap xep san pham theo gia (tang/giam).\n");
        printf("6. Tim kiem san pham.\n");
        printf("7. Ban san pham.\n");
        printf("8. Doanh thu hien tai.\n");
        printf("9. Thoat.\n");
        printf("Lua chon cua ban: ");
        scanf("%d", &luaChon);

        switch (luaChon) {
            case 1:
                printf("Nhap so luong san pham: ");
                scanf("%d", &n);
                for (int i = 0; i < n; i++) {
                    printf("Nhap thong tin san pham %d:\n", i + 1);
                    nhapThongTinSanPham(&sp[i]);
                    doanhThu -= sp[i].soLuong * sp[i].giaNhap; 
                }
                break;

            case 2:
                printf("\n%-20s %-30s %-10s %-10s %-10s\n", "Ma SP", "Ten SP", "Gia Nhap", "Gia Ban", "So Luong");
                for (int i = 0; i < n; i++) {
                    hienThiThongTinSanPham(&sp[i]);
                }
                break;

            case 3:
                printf("Nhap thong tin san pham: \n");
                nhapThongTinSanPham(&sp[n]);
                doanhThu -= sp[n].soLuong * sp[n].giaNhap; 
                n++;
                break;

            case 4:
                printf("Nhap ma san pham can cap nhat: ");
                scanf("%s", maSP);
                capNhatThongTinSanPham(sp, n, maSP);
                break;

            case 5:
                printf("Chon 1 de sap xep tang gia, 2 de sap xep giam gia: ");
                int chon;
                scanf("%d", &chon);
                sapXepSanPham(sp, n, chon);
                break;

            case 6:
                printf("Nhap ten san pham can tim: ");
                getchar(); 
                fgets(tenSP, 100, stdin);
                tenSP[strcspn(tenSP, "\n")] = 0; 
                timKiemSanPham(sp, n, tenSP);
                break;

            case 7:
                printf("Nhap ma san pham can ban: ");
                scanf("%s", maSP);
                printf("Nhap so luong can ban: ");
                scanf("%d", &soLuongBan);
                banSanPham(sp, &n, &doanhThu, maSP, soLuongBan);
                break;

            case 8:
                printf("Doanh thu hien tai: %.2f\n", doanhThu);
                break;

            case 9:
                printf("Thoat chuong trinh!\n");
                break;

            default:
                printf("Lua chon khong hop le!\n");
        }

    } while (luaChon != 9);

    return 0;
}


