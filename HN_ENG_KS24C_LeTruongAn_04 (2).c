#include <stdio.h>

int main() {
    int arr[100], n = 0, choice, value, pos, temp, i, j;

    do {
        printf("\n--- MENU ---\n");
        printf("1. Nhap so phan tu va gia tri cho mang\n");
        printf("2. In ra gia tri cac phan tu trong mang\n");
        printf("3. Them mot phan tu vao vi tri ngau nhien\n");
        printf("4. Xoa phan tu tai mot vi tri cu the\n");
        printf("5. Sap xep mang theo thu tu tang dan\n");
        printf("6. Sap xep chan truoc, le sau\n");
        printf("7. Dao nguoc mang\n");
        printf("8. Thoat\n");
        printf("Lua chon cua ban: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Nhap so phan tu: ");
                scanf("%d", &n);
                for (i = 0; i < n; i++) {
                    printf("Nhap arr[%d]: ", i);
                    scanf("%d", &arr[i]);
                }
                break;

            case 2:
                for (i = 0; i < n; i++) {
                    printf("arr[%d] = %d\n", i, arr[i]);
                }
                break;

            case 3:
                printf("Nhap gia tri can them: ");
                scanf("%d", &value);
                printf("Nhap vi tri can them: ");
                scanf("%d", &pos);
                if (pos < 0 || pos > n) {
                    printf("Vi tri khong hop le!\n");
                } else {
                    for (i = n; i > pos; i--) {
                        arr[i] = arr[i - 1];
                    }
                    arr[pos] = value;
                    n++;
                }
                break;

            case 4:
                printf("Nhap vi tri can xoa: ");
                scanf("%d", &pos);
                if (pos < 0 || pos >= n) {
                    printf("Vi tri khong hop le!\n");
                } else {
                    for (i = pos; i < n - 1; i++) {
                        arr[i] = arr[i + 1];
                    }
                    n--;
                }
                break;

            case 5:
                for (i = 1; i < n; i++) {
                    temp = arr[i];
                    j = i - 1;
                    while (j >= 0 && arr[j] > temp) {
                        arr[j + 1] = arr[j];
                        j--;
                    }
                    arr[j + 1] = temp;
                }
                printf("Mang sau khi sap xep tang dan:\n");
                for (i = 0; i < n; i++) {
                    printf("%d ", arr[i]);
                }
                printf("\n");
                break;

            case 6:
                {
                    int tempArr[100], index = 0;
                    for (i = 0; i < n; i++) {
                        if (arr[i] % 2 == 0) {
                            tempArr[index++] = arr[i];
                        }
                    }
                    for (i = 0; i < n; i++) {
                        if (arr[i] % 2 != 0) {
                            tempArr[index++] = arr[i];
                        }
                    }
                    for (i = 0; i < n; i++) {
                        arr[i] = tempArr[i];
                    }
                    printf("Mang sau khi sap xep chan truoc, le sau:\n");
                    for (i = 0; i < n; i++) {
                        printf("%d ", arr[i]);
                    }
                    printf("\n");
                }
                break;

            case 7:
                for (i = 0; i < n / 2; i++) {
                    temp = arr[i];
                    arr[i] = arr[n - i - 1];
                    arr[n - i - 1] = temp;
                }
                printf("Mang sau khi dao nguoc:\n");
                for (i = 0; i < n; i++) {
                    printf("%d ", arr[i]);
                }
                printf("\n");
                break;

            case 8:
                printf("Thoat chuong trinh.\n");
                break;

            default:
                printf("Lua chon khong hop le!\n");
                break;
        }
    } while (choice != 8);

    return 0;
}
