#include <stdio.h>
#include "malloc.h"

typedef struct Pupil pupil;
struct Pupil {
    int cleaning;
    int study;
    char letter;
};

void sort(pupil *list, int len, int type) // 1- cleaning  2- study  3- letter
{
    if (type = 1) {
        int flags = 1;
        while (flags) {
            flags = 1;
            for (int i = 0; i < len - 1; i++) {
                if (list[i].cleaning > list[i + 1].cleaning) {
                    list[i].cleaning ^= list[i + 1].cleaning ^= list[i].cleaning ^= list[i + 1].cleaning;
                    flags++;
                }
            }
            flags--;
        }
    }
    if (type = 2) {
        int flags = 1;
        while (flags) {
            flags = 1;
            for (int i = 0; i < len - 1; i++) {
                if (list[i].study > list[i + 1].study) {
                    list[i].study ^= list[i + 1].study ^= list[i].study ^= list[i + 1].study;
                    flags++;
                }
            }
            flags--;
        }
    }
    if (type = 3) {
        int flags = 1;
        while (flags) {
            flags = 1;
            for (int i = 0; i < len - 1; i++) {
                if (list[i].letter > list[i + 1].letter) {
                    list[i].letter ^= list[i + 1].letter ^= list[i].letter ^= list[i + 1].letter;
                    flags++;
                }
            }
            flags--;
        }
    }
}

int main() {
    int n;
    scanf("%d\n", &n);
    pupil *array = (pupil *) malloc((sizeof(pupil)) * n);
    for (int i = 0; i < n; i++) {
        scanf("%c\n", &array[i].letter);
        scanf("%d\n", &array[i].study);
        scanf("%d\n", &array[i].cleaning);
    }
    int type;
    scanf("%d", &type);// тип сортировки
    sort(array, n, type);
    for (int i =0;i<n;i++) {
        printf("%c-%d-%d\n",array[i].letter,array[i].study,array[i].cleaning);
    }
    return 0;
}
