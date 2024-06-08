#define MAXPASSLEN 30
#define MAXFILETYPELEN 10

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int extensionChecker(const char * extension){
    FILE * configfile = fopen("configs/filetypes.info","r");

    int lineLength = 10;
    char line[lineLength]; /* not ISO 90 compatible */


    while(fgets(line, lineLength, configfile)) {
        if (strcmp(line,extension) == 0)
        {
            return 1;
        }
    }
    return 0;
}

extern int checkFile(const char * filename){
    char extension[MAXFILETYPELEN] = "";
    int isExtension = 0;
    int j = 0;
    int i = 0;
    while(filename[i] != '\0')
    {
        if (isExtension == 1)
        {
            extension[j] = filename[i];
            j++;
        }
        if (filename[i] == '.')
        {
            isExtension = 1;
        }
        i++;
    }
    extension[j] = '\n';
    return extensionChecker(extension); 
}



int upShift(int num, int max, int count)
{
    int result = 0;
    if (count > 255)
    {
        return result;
    }
    if (num + count > 255)
    {
        result = (num + count) - 255;
    }
    else
    {
        result = num + count;
    }
    return result;
}

int downShift(int ans, int max, int count)
{
    int result = 0;
    if (count > 255)
    {
        return result;
    }
    if (ans < count)
    {
        result = (ans + max) - count + 1;
    }
    else
    {
        result = ans - count;
    }
    return result;
}

int sizeOfPass(const char *pass)
{
    int size = 0;
    for (int i = 0; i < MAXPASSLEN; i++)
    {
        if (pass[i] != 0)
        {
            size++;
        }
    }
    return size;
}

extern void encrypt(const char *file1name, const char *file2name, const char *pass)
{

    if (file1name == NULL || file2name == NULL || pass == NULL)
    {
        printf("\nMissing arguments\nExiting...\n");
        exit(0);
    }

    FILE *file1 = fopen(file1name, "r");
    FILE *file2;

    if (file1 == NULL)
    {
        printf("\nNo file called %s\nExiting...\n", file1name);
        exit(0);
    }
    if (checkFile(file1name) != 1)
    {
        char tm;
        printf("\nThis filetype is not supported yet.\nWant to continue?:[y,n]:");
        scanf("%c",&tm);
        if (tm != 'y')
        {
            exit(0);
        }
        
    }
    
    else
    {
        file2 = fopen(file2name, "w");
    }
    printf("\nEncrypting...\n");
    char ch = fgetc(file1);

    int index = 0;
    while (ch != EOF)
    {

        fputc(upShift((int)ch, 255, pass[index % sizeOfPass(pass)]), file2);

        ch = fgetc(file1);
        index++;
    }

    printf("\nFile saved as %s\n", file2name);
    fclose(file1);
    fclose(file2);
}

extern void decrypt(const char *file1name, const char *file2name, const char *pass)
{

    if (file1name == NULL || file2name == NULL || pass == NULL)
    {
        printf("\nMissing arguments\nExiting...\n");
        exit(0);
    }

    FILE *file1 = fopen(file1name, "r");
    FILE *file2;

    if (file1 == NULL)
    {
        printf("\nNo file called %s\nExiting...\n", file1name);
        exit(0);
    }
    if (checkFile(file1name) != 1)
    {
        char tm;
        printf("\nThis filetype is not supported yet.\nWant to continue?:[y,n]:");
        scanf("%c",&tm);
        if (tm != 'y')
        {
            exit(0);
        }
        
    }
    else
    {
        file2 = fopen(file2name, "w");
    }
    //---

    printf("\nDecrypting...\n");
    char ch = fgetc(file1);

    int index = 0;
    while (ch != EOF)
    {

        fputc(downShift((int)ch, 255, pass[index % sizeOfPass(pass)]), file2);

        ch = fgetc(file1);
        index++;
    }

    printf("\nFile saved as %s\n", file2name);
    fclose(file1);
    fclose(file2);
}