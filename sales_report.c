#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    FILE *in_file = fopen("sales_data.txt", "r");

    if (in_file != NULL) {
        int line = 0;
        char data[12][256];
        
        while (!feof(in_file) && !ferror(in_file)) {
            if (fgets(data[line], 256, in_file) != NULL ) {
                line++;
            }
        }

        fclose(in_file);

        for (int i=0; i<12; i++) {
            printf("%s", data[i]);
        }
    }

    else {
        printf("Error opening file");
        return 1;
    }
    return 0;
}