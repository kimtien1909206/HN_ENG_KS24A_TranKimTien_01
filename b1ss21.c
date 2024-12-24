#include <stdio.h>
int main() {
    char chuoi[100];
    FILE *f;
    printf("Nhap chuoi: ");
    fgets(chuoi, sizeof(chuoi), stdin);
    f = fopen("bt01.txt", "w");
    if (f == NULL) {
        printf("Khong the mo file\n");
        return 1;
    }
    fputs(chuoi, f);
    fclose(f);
    printf("Chuoi da duoc ghi vao file bt01.txt\n");
    return 0;
}


