#include <stdio.h>
struct SinhVien {
    int id;
    char name[50];
    int age;
};
int main() {
    FILE *f;
    struct SinhVien sv;
    int soLuong;
    printf("Nhap so luong sinh vien: ");
    scanf("%d", &soLuong);
    getchar(); 
    f = fopen("students.txt", "w");
    if (f == NULL) {
        printf("Khong the mo file\n");
        return 1;
    }
    for (int i = 0; i < soLuong; i++) {
        printf("Nhap thong tin sinh vien %d:\n", i + 1);
        printf("ID: ");
        scanf("%d", &sv.id);
        getchar(); 
        printf("Ten: ");
        fgets(sv.name, sizeof(sv.name), stdin);
        printf("Tuoi: ");
        scanf("%d", &sv.age);
        getchar();

        fprintf(f, "%d %s %d\n", sv.id, sv.name, sv.age);
    }
    fclose(f);
    printf("Thong tin sinh vien da duoc luu vao file students.txt\n");
    return 0;
}


