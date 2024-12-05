#include <stdio.h>
int main() {
	int i, j;
    int n, choice;
    int arr[100];
    do {
        printf("\n*****### MENU ###*****\n");
        printf("1, nhap so phan tu va gia tri cho mang\n");
        printf("2, in ra cac gia tri phan tu trong mang theo dang (arr[0]=1,arr[1]=5,.....)\n");
        printf("3, tim gia tri nho nhat va gia tri lon nhat trong mang\n");
        printf("4, in ra tong tat ca ca phan tu\n");
        printf("5, them mot phan tu vao cuoi mang, phan tu moi them vao phai do nguoi dung nhap vao\n");
        printf("6, xoa mot phan tu tai mot vi tri cu the (nguoi dung nhap vi tri )\n");
        printf("7, sap xep mang theo thu tu tang dan (bubble sort)\n");
        printf("8, cho nguoi dung nhap vao mot phan tu tim kiem xem phan tu do co ton tai trong mang hay khong (linear search)\n");
        printf("9, in ra toan bo so nguyen trong mang\n");
        printf("10, sap xep mang theo thu tu tang dan (selection sort)\n");
        printf("11,Nhap lua chon (0 de thoat): ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: { 
                printf("Nhap so phan tu trong mang: ");
                scanf("%d", &n);

                for (i = 0; i < n; i++) {
                    printf("Nhap gia tri phan tu %d: ", i);
                    scanf("%d", &arr[i]);
                }
                break;
            }
            case 2: { 
                printf("Cac phan tu trong mang: ");
                for ( i = 0; i < n; i++) {
                   printf("arr[%d] = %d\n", i, arr[i]);
                }
                printf("\n");
                break;
            }
            case 3: {
                int small = arr[0], big = arr[0];
                for (i = 1; i < n; i++) {
                    if (arr[i] < small) small = arr[i];
                    if (arr[i] > big) big = arr[i];
                }
                printf("Gia tri nho nhat: %d\n", small);
                printf("Gia tri lon nhat: %d\n", big);
                break;
            }
            case 4: { 
                int sum = 0;
                for ( i = 0; i < n; i++) {
                    sum += arr[i];
                }
                printf("Tong cac phan tu: %d\n", sum);
                break;
            }
            case 5: { 
                int new_value;
                printf("Nhap gia tri moi: ");
                scanf("%d", &new_value);
                arr[n] = new_value;
                n++; 
                break;
            }
            case 6: { 
                int indexdelete;
                printf("Nhap chi so phan tu can xoa: ");
                scanf("%d", &indexdelete);

                if (indexdelete >= 0 && indexdelete < n) {
                    for (i = indexdelete; i < n - 1; i++) {
                        arr[i] = arr[i + 1];
                    }
                    n--; 
                } else {
                    printf("Chi so khong hop le.\n");
                }
                break;
            }
            case 7: { 
                for ( i = 0; i < n - 1; i++) {
                    for ( j = 0; j < n - i - 1; j++) {
                        if (arr[j] > arr[j + 1]) {
                            int temp = arr[j];
                            arr[j] = arr[j + 1];
                            arr[j + 1] = temp;
                        }
                    }
                }
                printf("Mang da duoc sap xep (Bubble Sort).\n");
                break;
            }
            case 8: { 
                int value, found = 0;
                printf("Nhap gia tri can tim: ");
                scanf("%d", &value);
                for (i = 0; i < n; i++) {
                    if (arr[i] == value) {
                        found = 1;
                        printf("Phan tu %d tim thay tai chi so %d.\n", value, i);
                        break;
                    }
                }
                if (!found) {
                    printf("Phan tu khong ton tai trong mang.\n");
                }
                break;
            }
            case 9: 
                break;
            case 10: { 
                for ( i = 0; i < n - 1; i++) {
                    int minindex = i;
                    for ( j = i + 1; j < n; j++) {
                        if (arr[j] < arr[minindex]) {
                            minindex = j;
                        }
                    }
                    if (minindex != i) {
                        int temp = arr[i];
                        arr[i] = arr[minindex];
                        arr[minindex] = temp;
                    }
                }
                printf("Mang da duoc sap xep (Selection Sort).\n");
                break;
            }
            default:
                if (choice != 0) {
                    printf("Lua chon khong hop le.\n");
                }
        }
    } while (choice != 0);

    return 0;
}

