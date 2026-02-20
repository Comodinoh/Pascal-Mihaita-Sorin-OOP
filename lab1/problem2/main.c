#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <stdint.h>
#include <assert.h>
#include <string.h>

size_t min(size_t a, size_t b) {
    return a < b ? a : b;
}

void *memndup(const void *buf, size_t n) {
    void *res = malloc(n);

    if(!res) return NULL;

    memcpy(res, buf, n);
    return res;
}

void nstrncpy(char *a, const char *b, size_t n) {
    for(int i = 0; i < n; i++) {
        a[i] = b[i];
    }
    a[n] = '\0';   
}

char *nstrndup(const char *str, size_t n) {
    char *buf = malloc(sizeof(char)*(n+1));
    strncpy(buf, str, n);
    return buf;
}


size_t nstrlen(const char *a) {
    size_t l = 0;

    assert(a != NULL);
    while(a[l] != '\0') l++;

    return l;
}

void nmemset(void *buf, int val, size_t size) {
    uint8_t *cbuf = buf;
    size_t i = 0;
    
    while(i < size) {
        cbuf[i++] = val;
    }
}


void nstrcpy(char *a, const char *b) {
    size_t len = nstrlen(b);

    for(int i = 0; i < len; i++) {
        a[i] = b[i];
    }
    a[len] = '\0';
}

void swapt(char *a, char *b, char *temp, size_t temp_size, size_t a_size, size_t b_size) {
    nmemset(temp, 0, temp_size+1);
    nstrcpy(temp, a);

    nmemset(a, 0, a_size+1);
    nstrcpy(a, b);

    nmemset(b, 0, b_size+1);
    nstrcpy(b, temp);
}


int betterstrcmp(char *one, char *two) {
    if(one == two) return 0;

    size_t l1 = nstrlen(one);
    size_t l2 = nstrlen(two);

    size_t l = min(l1, l2);

    for(size_t i = 0; i < l; i++) {
        char c1 = one[i];
        char c2 = two[i];
        i++;
        
        if(c1 == c2) continue;

        return c1-c2;
    }

    return l1-l2;
}

int main(void)
{
    char buf[512];

    scanf("%[^\n]", buf);
    printf("Entered Text: %s\n", buf);

    size_t arrcap = 32;
    char** array = malloc(sizeof(char*)*arrcap);
    char temp[512];
    
    size_t i = 0;
    size_t j = 0;
    size_t len = nstrlen(buf);
    int n = 0;

    while(i <= len) {
        if(i == len || buf[i] == ' ') {
            if(n != 0) {
                if(j >= arrcap) {
                    arrcap *= 2;
                    array = realloc(array, sizeof(char)*arrcap);
                }
                
                array[j++] = nstrndup(temp, sizeof(char)*n);
                n = 0;
            }

            if(i == len) break;
            
            while(i < len && buf[i] == ' ') i++;
        } else {
            temp[n++] = buf[i++];
        }
    }


    for(size_t j2 = 0; j2 < j; j2++) {
        for(size_t j3 = 0; j3 < j-j2-1; j3++) {
            char *first = array[j3];
            size_t first_len = nstrlen(first);
            char *second = array[j3+1];
            size_t second_len  = nstrlen(second);
            //printf("Iteration %ld,%ld First: %ld - \"%s\" Second: %ld - \"%s\"\n", j2, j3, first_len, first, second_len, second);

            if(first_len > second_len) {
                second = realloc(second, sizeof(char)*(first_len+1));
                swapt(first, second, temp, 512, first_len, second_len);
              //  printf("Swapped %s and %s\n", second, first);
            } else if(first_len == second_len) {
                if(strcmp(first, second) < 0) {
                    swapt(first, second, temp, 512, first_len, second_len);
                //    printf("Swapped %s and %s\n", second, first);
                }
            }
        }
        printf("%s\n", array[j-j2-1]);
    }
    
    return 0;
}
