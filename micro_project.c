#include <stdio.h>
#include <string.h>

int btod(long long b) {
    int d = 0, base = 1;
    while (b > 0) {
        d += (b % 10) * base;
        base *= 2;
        b /= 10;
    }
    return d;
}

long long btoo(long long b) {
    int d = btod(b);
    long long o = 0, base = 1;
    while (d > 0) {
        o += (d % 8) * base;
        base *= 10;
        d /= 8;
    }
    return o;
}

void btoh(long long b) {
    int d = btod(b);
    char h[32];
    int i = 0;
    while (d > 0) {
        int rem = d % 16;
        h[i++] = (rem < 10) ? rem + '0' : rem - 10 + 'A';
        d /= 16;
    }
    printf("hexadecimal: ");
    for (int j = i - 1; j >= 0; j--)
        printf("%c", h[j]);
    printf("\n");
}

int otod(int o) {
    int d = 0, base = 1;
    while (o > 0) {
        d += (o % 10) * base;
        base *= 8;
        o /= 10;
    }
    return d;
}

long long otob(int o) {
    int d = otod(o);
    long long b = 0, base = 1;
    while (d > 0) {
        b += (d % 2) * base;
        base *= 10;
        d /= 2;
    }
    return b;
}

void otoh(int o) {
    int d = otod(o);
    char h[32];
    int i = 0;
    while (d > 0) {
        int rem = d % 16;
        h[i++] = (rem < 10) ? rem + '0' : rem - 10 + 'A';
        d /= 16;
    }
    printf("hexadecimal: ");
    for (int j = i - 1; j >= 0; j--)
        printf("%c", h[j]);
    printf("\n");
}

int htod(char h[]) {
    int d = 0, base = 1, len = strlen(h);
    for (int i = len - 1; i >= 0; i--) {
        if (h[i] >= '0' && h[i] <= '9')
            d += (h[i] - '0') * base;
        else
            d += (h[i] - 'A' + 10) * base;
        base *= 16;
    }
    return d;
}

long long htob(char h[]) {
    int d = htod(h);
    long long b = 0, base = 1;
    while (d > 0) {
        b += (d % 2) * base;
        base *= 10;
        d /= 2;
    }
    return b;
}

long long htoo(char h[]) {
    int d = htod(h);  // Corrected this line
    long long o = 0, base = 1;
    while (d > 0) {
        o += (d % 8) * base;
        base *= 10;
        d /= 8;
    }
    return o;
}

long long dtob(int d) {
    long long b = 0, base = 1;
    while (d > 0) {
        b += (d % 2) * base;
        base *= 10;
        d /= 2;
    }
    return b;
}

int dtoo(int d) {
    int o = 0, base = 1;
    while (d > 0) {
        o += (d % 8) * base;
        base *= 10;
        d /= 8;
    }
    return o;
}

void dtoh(int d) {
    char h[32];
    int i = 0;
    while (d > 0) {
        int rem = d % 16;
        h[i++] = (rem < 10) ? rem + '0' : rem - 10 + 'A';
        d /= 16;
    }
    printf("hexadecimal: ");
    for (int j = i - 1; j >= 0; j--)
        printf("%c", h[j]);
    printf("\n");
}

int main() {
    int c, d, o, cont = 1;
    long long b;
    char h[32];

    printf("welcome to the number system converter!\n");

    while (cont) {
        printf("\nmenu \n");
        printf("1. binary to decimal\n");
        printf("2. binary to octal\n");
        printf("3. binary to hexadecimal\n");
        printf("4. octal to decimal\n");
        printf("5. octal to binary\n");
        printf("6. octal to hexadecimal\n");
        printf("7. hexadecimal to decimal\n");
        printf("8. hexadecimal to binary\n");
        printf("9. hexadecimal to octal\n");
        printf("10. decimal to binary\n");
        printf("11. decimal to octal\n");
        printf("12. decimal to hexadecimal\n");
        printf("13. exit\n");
        printf("enter your choice: ");
        scanf("%d", &c);

        if (c == 13) {
            printf("exiting the program. goodbye!\n");
            break;
        }

        switch (c) {
            case 1:
                printf("enter binary number: ");
                scanf("%lld", &b);
                printf("decimal: %d\n", btod(b));
                break;
            case 2:
                printf("enter binary number: ");
                scanf("%lld", &b);
                printf("octal: %lld\n", btoo(b));
                break;
            case 3:
                printf("enter binary number: ");
                scanf("%lld", &b);
                btoh(b);
                break;
            case 4:
                printf("enter octal number: ");
                scanf("%d", &o);
                printf("decimal: %d\n", otod(o));
                break;
            case 5:
                printf("enter octal number: ");
                scanf("%d", &o);
                printf("binary: %lld\n", otob(o));
                break;
            case 6:
                printf("enter octal number: ");
                scanf("%d", &o);
                otoh(o);
                break;
            case 7:
                printf("enter hexadecimal number: ");
                scanf("%s", h);
                printf("decimal: %d\n", htod(h));
                break;
            case 8:
                printf("enter hexadecimal number: ");
                scanf("%s", h);
                printf("binary: %lld\n", htob(h));
                break;
            case 9:
                printf("Enter hexadecimal number: ");
                scanf("%s", h);
                printf("octal: %lld\n", htoo(h));
                break;
            case 10:
                printf("enter decimal number: ");
                scanf("%d", &d);
                printf("binary: %lld\n", dtob(d));
                break;
            case 11:
                printf("enter decimal number: ");
                scanf("%d", &d);
                printf("octal: %d\n", dtoo(d));
                break;
            case 12:
                printf("enter decimal number: ");
                scanf("%d", &d);
                dtoh(d);
                break;
            default:
                printf("invalid choice! try again.\n");
        }

        printf("\nenter 1 to continue or 0 to exit: ");
        scanf("%d", &cont);
    }

    printf("thank you for using the converter. goodbye!\n");
    return 0;
}