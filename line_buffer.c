#include <stdio.h>
#include <stdlib.h>

#ifdef DO_DEBUG
#define DEBUG(...) fprintf(stderr, __VA_ARGS__);
#else
#define DEBUG(...)
#endif // DO_DEBUG

#define INITIAL_CAP 1024

int main()
{
    size_t cap = INITIAL_CAP;
    char *buf = malloc(sizeof(char) * cap);
    size_t n = 0;

    while (1) {
        DEBUG("new loop\n");
        if (n == cap) {
            DEBUG("reallocating");
            cap *= 2;
            char *buf_new = realloc(buf, sizeof(char) * cap);
            if (buf_new == NULL) {
                DEBUG("could not reallocate\n");
                exit(1);
            }
            buf = buf_new;
        }

        char c = fgetc(stdin);
        if (feof(stdin)) {
            break;
        }

        buf[n++] = c;
        if (c == '\n') {
            DEBUG("saw a newline\n");
            fwrite(buf, sizeof(char), n, stdout);
            fflush(stdout);

            for (size_t i = 0; i < n; i++) {
                buf[i] = 0;
            }
            n = 0;
        } else {
            DEBUG("saw char %c\n", c);
        }
    }

    if (n > 0) {
        // there are re
        buf[n++] = '\n';
        fwrite(buf, sizeof(char), n, stdout);
        fflush(stdout);
    }

    return 0;
}
