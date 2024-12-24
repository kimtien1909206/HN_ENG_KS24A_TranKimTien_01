#include <stdio.h>
int main() {
    FILE *f1, *f2;
    char ch;
    f1 = fopen("bt01.txt", "r");
    if (f1 == NULL) {
        printf("Khong the mo file bt01.txt\n");
        return 1;
    }
    f2 = fopen("bt06.txt", "w");
    if (f2 == NULL) {
        printf("Khong the mo file bt06.txt\n");
        fclose(f1);
        return 1;
    }
    while ((ch = fgetc(f1)) != EOF) {
        fputc(ch, f2);
    }
    printf("Sao chep thanh cong tu bt01.txt sang bt06.txt\n");
    fclose(f1);
    fclose(f2);
    return 0;
}

