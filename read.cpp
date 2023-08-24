#include <errno.h>
#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include "read.h"


int read_double(double *value, const char *prompt, const char param)
{
    size_t length = 0;
    char *end = NULL;
    char buf[BUFFER_SIZE] = "";

    assert(value);
    assert(prompt);
    assert(isfinite (*value));
    assert(!isnan (*value));


    printf("%s%c: ", prompt, param);

    if (!fgets(buf, sizeof(buf), stdin))
        return 1;

    length = strlen(buf);

    if (buf[length - 1] == '\n')
    {
        buf[--length] = '\0';
        errno = 0;
        *value = strtod(buf, &end);

        if (length == 0)
        {
            fprintf(stderr,TEXT_COLOR(YELLOW_TEXT, "Error: An empty string was entered.\n"));
            return 1;
        }
        if (errno != 0 || *end != '\0')
        {
            fprintf(stderr, TEXT_COLOR(YELLOW_TEXT, "Error: Invalid character.\n"));
            fprintf(stderr, TEXT_COLOR(YELLOW_TEXT, "\t%s\n"), buf);
            fprintf(stderr, TEXT_COLOR(YELLOW_TEXT, "\t%*c\n"), (int)(end - buf) + 1, '^');
            return 1;
        }
    }
    else
    {
        scanf("%*[^\n]");
        scanf("%*c");
        fprintf(stderr, TEXT_COLOR(YELLOW_TEXT, "Error: do not enter more than %d character(s).\n"), BUFFER_SIZE - 2);
        /// BUFFER_SIZE - 2 because the buffer also stores the newline character and the null byte
        return 1;
    }
    return 0;
}


int do_read_double(double *value, const char param)
{
    assert(value);
    assert(isfinite (*value));
    assert(!isnan (*value));

    int status = 0;
    do
    {
        status = read_double(value, "Enter the parameter ", param);
        if (status != 0)
        {
            printf(TEXT_COLOR(YELLOW_TEXT, "Please try again.\n"));
        }
    } while (status != 0);
    return 0;
}


int init_params(struct st_params *params)
{

    /// TODO assert for structure fields

    do_read_double(&(params->a), 'a');
    do_read_double(&(params->b), 'b');
    do_read_double(&(params->c), 'c');
    printf("--> You have entered: a = %lf; b = %lf; c = %lf\n", params->a, params->b, params->c);
    return 0;
}
