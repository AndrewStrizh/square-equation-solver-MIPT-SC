#include <errno.h>
#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include "ses.h"


int main(int argc, char *argv[])
{
    printf("Square equation solver\n"
           "# (c) STA, 2023\n\n");

    if(argc>1 && !strcmp(argv[1], "tests"))
        all_tests();
    else
    {
        struct st_params params = {0, 0, 0};
        struct st_roots roots = {0, 0};

        init_params(&params);
        solver(params, &roots);
    };
}
