#include <stdio.h>
#include "vencrypt.h"

int main(int argc, char const *argv[])
{
    if (argv[1][0] == 'E')
    {
        encrypt(argv[2],argv[3],argv[4]);
    }else if(argv[1][0] == 'D'){
        decrypt(argv[2],argv[3],argv[4]);
    }
    return 0;
}
