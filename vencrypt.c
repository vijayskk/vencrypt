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
        result = ans - count ;
    }
    return result;
}

int sizeOfPass(char *pass)
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

int main(int argc, char const *argv[])
{
    

    char pass[MAXPASSLEN] = {[0 ... MAXPASSLEN - 1] = 0};

    char choice = argv[1][0];
    
    if (argv[1] == NULL || argv[2] == NULL || argv[3] == NULL)
    {
        printf("\nMissing arguments\nExiting...\n");
        exit(0);
    }
    


    FILE *file1 = fopen(argv[2], "r");
    FILE *file2;

    if (file1 == NULL)
    {
        printf("\nNo file called %s\nExiting...\n",argv[2]);
        exit(0);
    }else{
        file2 = fopen(argv[3], "w");
    }
    

    if (choice == 'E')
    {
        printf("\nCreate the password: ");
        scanf("%s", pass);
        printf("\nEncrypting...\n");
        char ch = fgetc(file1);
        
        int index = 0;
        while (ch != EOF)
        {
            //printf("%d,%c ->", ch, ch);

            fputc(upShift((int)ch, 255, pass[index % sizeOfPass(pass)]), file2);

            //printf(" %d,%c\n", upShift((int)ch, 255, pass[index % sizeOfPass(pass)]), upShift((int)ch, 255, pass[index % sizeOfPass(pass)]));

            ch = fgetc(file1);
            index++;
        }
    }else if(choice == 'D'){
        printf("\nEnter the password: ");
        scanf("%s", pass);
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

    }else{
        printf("\nInvalied option %c",choice);
        exit(0);
    }
    printf("\nFile saved as %s\n",argv[3]);
    fclose(file1);
    fclose(file2);

    //printf("\n%s,%d", pass, sizeOfPass(pass));
    return 0;
}
