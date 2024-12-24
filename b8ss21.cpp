#include <stdio.h>
struct SinhVien {
    int id;
    char name[50];
    int age;
};
int main() {
    FILE *f;
    struct SinhVien sv[100];
    int i = 0;
    f = fopen("students.txt", "r");
    if (f == NULL) {
        printf("Khong the mo file students.txt\n");
        return 1;
    }
    while (fscanf(f, "%d %49[^\n] %d", &sv[i].id, sv[i].name, &sv[i].age) == 3) {
        i++;
        if (i >= 100) break;  // N?u m?ng d?y thì d?ng l?i
    }
    fclose(f);
    printf("Danh sach sinh vien:\n");
    for (int j = 0; j < i; j++) {
        printf("ID: %d, Ten: %s, Tuoi: %d\n", sv[j].id, sv[j].name, sv[j].age);
    }
    return 0;
}

