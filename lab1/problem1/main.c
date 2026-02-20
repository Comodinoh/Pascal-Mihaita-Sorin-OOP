#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

int worseatoi(char* str, size_t len) {
    int i = 0;
    int nr = 0;
    int neg = 0;
    if(str[0] == '-')
    {
        neg = 1;
        str++;
        len--;
    }

    assert(len != 0);

    while(i < len) {
        char c = str[i];

        int digit = c - '0';
        nr = nr*10 + digit;

        i++;
    }
    if(neg) nr *= -1;

    return nr;
}

int main()
{
    FILE* file = fopen("in.txt", "r");

    size_t bufcap = 64;
    char* buf = malloc(sizeof(char)*bufcap);
    char c;
    int sum = 0;
    int i = 0;
    
    while((c = fgetc(file)) != EOF) {
        if(c == '\n') {
            if(i == 0) continue;

            int nr = worseatoi(buf, i);
            printf("Number: %d\n", nr);
            sum += nr;

            memset(buf, 0, sizeof(char)*bufcap);
            i = 0;
        }else {
            if(i >= bufcap) {
                bufcap *= 2;
                buf = realloc(buf, sizeof(char)*bufcap);
            }

            buf[i] = c;

            i++;
        }
    }

    printf("Sum: %d\n", sum);
    
    return 0;
}
