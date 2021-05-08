#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* Args[])
{
    int wordcount = 0;
    if (argc != 3) {
        exit(0);
    }

    FILE* fp;
    if (!(fp = fopen(Args[2], "r+"))) {
        exit(0);
    }
    
    char letter = NULL, temp;

    if (Args[1][1] == 'c') {
        while (!feof(fp)) {
            letter = fgetc(fp);
            if (letter >= 32 && letter <= 127) {
                wordcount++;
            }
        }

        printf("×Ö·ûÊý:%d\n", wordcount);
        fclose(fp);
    }
    else if (Args[1][1] == 'w') {
        while (!feof(fp)) {
            temp = fgetc(fp);

            if (temp == ' ' || temp == '\n' || temp == '\t' || temp == NULL) {
                if (letter != ' ' && letter != '\n' && letter != '\t' && letter >= 32 && letter <= 127) {
                    wordcount++;
                }
            }
            letter = temp;
        }

        printf("µ¥´ÊÊý:%d\n", wordcount + 1);
        fclose(fp);
    }
    else {
        exit(0);
    }
}