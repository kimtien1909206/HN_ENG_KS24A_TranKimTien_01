#include <stdio.h>
int main() {
    FILE *f;
    int soDong;
    char dong[100];
    printf("Nhap so dong: ");
    scanf("%d", &soDong);
    getchar();
    f = fopen("bt05.txt", "w");
    if (f == NULL) {
        printf("Khong the mo file\n");
        return 1;
    }
    for (int i = 0; i < soDong; i++) {
        printf("Nhap noi dung cho dong %d: ", i + 1);
        fgets(dong, sizeof(dong), stdin); 
        fputs(dong, f);
    }
    fclose(f); 
    f = fopen("bt05.txt", "r");
    if (f == NULL) {
        printf("Khong the mo file\n");
        return 1;
    }
    printf("\nNoi dung cua file bt05.txt:\n");
    while (fgets(dong, sizeof(dong), f) != NULL) {
        printf("%s", dong); 
    }
    fclose(f); 
    return 0;
}

