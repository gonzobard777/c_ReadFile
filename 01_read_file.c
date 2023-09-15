#include <stdio.h>

int main() {
    FILE *filePtr;
    filePtr = fopen("..\\files\\check.txt", "r");

    char bufLen = 30;
    char buf[bufLen];
    for (int i = 0; i < bufLen; i++) {
        buf[i] = '#';
    }
    size_t count = fread(buf, 2, 2, filePtr);

    printf("%zu\n", count);
    printf("%s", buf);

    fclose(filePtr);

    return 0;
}
