#include <stdio.h>
#include <time.h>

int sleep_ns(long ns)
{
    struct timespec time, time2;
    time.tv_sec = 0;
    time.tv_nsec = ns;
    return nanosleep(&time, &time2) == 0;
}

int main()
{
    // turn off stdout buffering. this means that all chars written
    // to stdout by putc will be written *immediately*
    setbuf(stdout, NULL);

    char *msgs = "{ \"msg\": \"hello!\" }\n"
                 "{ \"msg\": \"goodbye :(\" }";
    while ((*msgs) != '\0') {
        putc(*msgs, stdout);
        sleep_ns(100000000); // 10ms
        msgs++;
    }
}
