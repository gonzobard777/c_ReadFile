#include <stdio.h>

/*
 * https://c-for-dummies.com/blog/?p=3357
 */
int main() {
    FILE *fp;
    const char filename[] = "..\\files\\family.data";

    struct person {
        char name[32];
        int age;
        float weight;
    } familyMember;
    const char personStructSize = sizeof(struct person);

//region Запись
    fp = fopen(filename, "w");

    struct person family_in[] = {
            {"Dad",    42, 460.1}, // 1
            {"Mom",    40, 120.0}, // 2
            {"Junior", 15, 150.6}, // 3
            {"Missy",  12, 80.2},  // 4
            {"Baby",   1,  33.9}   // 5
    };
    for (int i = 0; i < 5; i++) {
        fwrite(&family_in[i], sizeof(struct person), 1, fp);
    }
    fclose(fp);
//endregion Запись


//region Чтение
    fp = fopen(filename, "r");

//    struct person family_out[5];
//    for (int i = 0; i < 5; i++) {
//        fread(&family_out[i], sizeof(struct person), 1, fp);
//        printf("%s is %d and weights %.1f\n",
//               family_out[i].name,
//               family_out[i].age,
//               family_out[i].weight
//        );
//    }

    for (int i = 0; i < 5; i++) {
        fread(&familyMember, personStructSize, 1, fp);
        printf("%s is %d and weights %.30f\n",
               familyMember.name,
               familyMember.age,
               familyMember.weight
        );
    }
    fclose(fp);
//endregion Чтение

    return 0;
}