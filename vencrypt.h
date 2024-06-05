#define MAXPASSLEN 30

#include <stdio.h>
#include <stdlib.h>

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

extern void encrypt(const char *file1name,const char *file2name,const char *pass)
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
    else
    {
        file2 = fopen(file2name, "w");
    }
    //---
    printf("\nEncrypting...\n");
    char ch = fgetc(file1);

    int index = 0;
    while (ch != EOF)
    {
        // printf("%d,%c ->", ch, ch);

        fputc(upShift((int)ch, 255, pass[index % sizeOfPass(pass)]), file2);

        // printf(" %d,%c\n", upShift((int)ch, 255, pass[index % sizeOfPass(pass)]), upShift((int)ch, 255, pass[index % sizeOfPass(pass)]));

        ch = fgetc(file1);
        index++;
    }
    // printf("\nEnter the password: ");
    // scanf("%s", pass);
    // printf("\nDecrypting...\n");
    // char ch = fgetc(file1);

    // int index = 0;
    // while (ch != EOF)
    // {
    //     //printf("%d,%c ->", ch, ch);

    //     fputc(downShift((int)ch, 255, pass[index % sizeOfPass(pass)]), file2);

    //     //printf(" %d,%c\n", downShift((int)ch, 255, pass[index % sizeOfPass(pass)] ), downShift((int)ch, 255, pass[index % sizeOfPass(pass)] ));

    //     ch = fgetc(file1);
    //     index++;
    // }

    printf("\nFile saved as %s\n", file2name);
    fclose(file1);
    fclose(file2);

    // printf("\n%s,%d", pass, sizeOfPass(pass));
}


extern void decrypt(const char *file1name,const char *file2name,const char *pass)
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
        //printf("%d,%c ->", ch, ch);

        fputc(downShift((int)ch, 255, pass[index % sizeOfPass(pass)]), file2);

        //printf(" %d,%c\n", downShift((int)ch, 255, pass[index % sizeOfPass(pass)] ), downShift((int)ch, 255, pass[index % sizeOfPass(pass)] ));

        ch = fgetc(file1);
        index++;
    }

    printf("\nFile saved as %s\n", file2name);
    fclose(file1);
    fclose(file2);

    // printf("\n%s,%d", pass, sizeOfPass(pass));
}