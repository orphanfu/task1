#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 20

typedef struct {
    char name[MAX_NAME_LENGTH];
    char surname[MAX_NAME_LENGTH];
    int height;
} Person;

Person* createPersonArray(int N) {
    Person *people = (Person *)malloc(N * sizeof(Person));
    if (people == NULL) {
        printf("n/a");
        return NULL;
    }
    return people;
}

void freePersonArray(Person* people) {
    free(people);
}


int populatePersonArray(Person* people, int N) {
    for (int i = 0; i < N; i++) {
        if (scanf("%20s %20s %d", people[i].name, people[i].surname, &people[i].height) != 3) {
            printf("n/a");
            return 0;
        }
    }
    return 1;
}

void findPeopleByHeight(Person* people, int N, int H) {
    int found = 0;
    for (int i = 0; i < N; i++) {
        if (people[i].height >= H) {
            if (found > 0) {
                printf(", ");
            }
            printf("%s %s", people[i].name, people[i].surname);
            found++;
        }
    }
    if (found == 0) {
        printf("Nothing");
    }
}

int main() {
    int N, H;

    if (scanf("%d", &N) != 1 || N <= 0) {
        printf("n/a");
        return 0;
    }

    Person *people = createPersonArray(N);
    if (people == NULL) {
        return 0;
    }

    if (!populatePersonArray(people, N)) {
        freePersonArray(people);
        return 0;
    }

    if (scanf("%d", &H) != 1 || H <= 0) {
        printf("n/a");
        freePersonArray(people);
        return 0;
    }

    findPeopleByHeight(people, N, H);

    freePersonArray(people);
    return 0;
}