#include <stdio.h>
int main() {
    FILE *f;
    char kyTu;
    f = fopen("bt01.txt", "r");
    if (f == NULL) {
        printf("Khong the mo file\n");
        return 1;
    }
    kyTu = fgetc(f);
    if (kyTu != EOF) {
        printf("Ky tu dau tien trong file: %c\n", kyTu);
    } else {
        printf("File rong\n");
    }
    fclose(f);
    return 0;
}


