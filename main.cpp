#include <errno.h>
#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include "main.h"


int main(void)
{
    printf("Square equation solver\n"
           "# (c) STA, 2023\n\n");

    struct st_params params = {0, 0, 0};
    struct st_roots roots = {0, 0};

    init_params(&params);
    solver(params, &roots);

    all_tests();
}
