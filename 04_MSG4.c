#include <stdio.h>

/*
 * Группа The Co-ordination Group for Meteorological Satellites - CGMS, разработала спецификацию:
 * https://www.cgms-info.org/wp-content/uploads/2021/10/cgms-lrit-hrit-global-specification-(v2-8-of-30-oct-2013).pdf
 * Нас интересует Table 4-1 Primary Header Record, страница 14.
 */
int main() {
    FILE *fp;
    const char filename[] = "..\\files\\H-000-MSG4__-MSG4________-VIS006___-000008___-201802281500-__";

    fp = fopen(filename, "r");
    unsigned char primaryHdr[16];
    fread(&primaryHdr, 16, 1, fp);
    fclose(fp);

    // 1 байт
    const unsigned char hdr_type = primaryHdr[0];

    // следующие 2 байта
    const unsigned short hdr_rec_len = (primaryHdr[1] << 8) + primaryHdr[2];

    // следующий 1 байт
    const unsigned char file_type = primaryHdr[3];

    // следующие 4 байта
    const unsigned int total_hdr_len = (primaryHdr[4] << 24) + (primaryHdr[5] << 16) + (primaryHdr[6] << 8) + primaryHdr[7];

    return 0;
}