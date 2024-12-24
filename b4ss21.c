#include <stdio.h>
int main() {
    FILE *f;
    char dong[100];
    f = fopen("bt01.txt", "r");
    if (f == NULL) {
        printf("Khong the mo file\n");
        return 1;
    }
    if (fgets(dong, sizeof(dong), f) != NULL) {
        printf("Dong dau tien trong file: %s", dong);
    } else {
        printf("File rong hoac loi khi doc file.\n");
    }
    fclose(f);
    return 0;
}


