#include <stdio.h>
#include <stdlib.h>

/*
 * https://c-for-dummies.com/blog/?p=3363
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

    long selectedRecordNum = 0;
    char scannedStr[1];
    char *end;
    while (selectedRecordNum < 1 || selectedRecordNum > 5) {
        printf("\nFetch which record (1 to 5)? ");
        gets(scannedStr);
        selectedRecordNum = strtol(scannedStr, &end, 10);
    }

    fp = fopen(filename, "r");

    /* set the file position indicator to the desired record */
    fseek(fp, (selectedRecordNum - 1) * personStructSize, SEEK_SET);

    fread(&familyMember, personStructSize, 1, fp);
    printf("\nRecord #%d \nName: %s\nAge: %d\nWeight: %.1f\n",
           selectedRecordNum,
           familyMember.name,
           familyMember.age,
           familyMember.weight
    );
    fclose(fp);

    return 0;
}