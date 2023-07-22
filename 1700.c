#include <stdio.h>

int* rearrangeStack (int* array, int sizeArray);
int countStudents(int* students, int studentsSize, int* sandwiches, int sandwichesSize);

int main () {
    int students[6] = {1,1,1,0,0,1}, sandwiches[6] = {1,0,0,0,1,1};

    countStudents (students, sizeof(students) / sizeof(int), sandwiches, sizeof(sandwiches) / sizeof(int));
}

int countStudents(int* students, int studentsSize, int* sandwiches, int sandwichesSize) {
    int sizeA = studentsSize;
    int end = 0;
    int noOneEatingCount = 0;
    int notEatCount = 0;

    while (end == 0) {
        printf("%d == %d ? ", students[0], sandwiches[0]);
        if (sandwiches[0] != 2) {
            if (students[0] == sandwiches[0] && students[0] != 2 && sandwiches[0] != 2) {
                printf("true ");
                noOneEatingCount = 0;
                students[0] = 2;
                sandwiches[0] = 2;
                rearrangeStack(students, sizeA);
                rearrangeStack(sandwiches, sizeA);
            } else {
                printf("false ");
                noOneEatingCount++;
                rearrangeStack(students, sizeA);
            }
        } else {
            end = 1;
        }

        if (noOneEatingCount == sizeA) {
            end = 1;
        }
        printf("\n");
    }

    for (int i = 0; i < sizeA; i++) {
        if (students[i] != 2) {
            notEatCount++;
        }
    }
        
    printf("%d", notEatCount);
    return notEatCount;
}

int* rearrangeStack (int* array, int sizeArray) {
    int temp = array[0];
    for (int i = 0; i < sizeArray - 1; i++) {
        array[i] = array[i + 1];
    }
    array[sizeArray - 1] = temp;

    return array;
}