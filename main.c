#include <stdio.h>
#include <dirent.h>
#include <stdint.h>
#include <sys/time.h>
#include <stdint.h>
#include <inttypes.h>

int64_t currentTimeMillis();


int main(void) {
    int64_t start=currentTimeMillis();
    DIR *dr;
    struct dirent *en;
    char dir[] = "/Users/edore/CLionProjects/BigramsTrigrams/Gutenberg/txt";
    dr = opendir(dir);
    char path[200];
    int countBigrams['z' - 'a' + 1]['z' - 'a' + 1] = {{0}};
    int countTrigrams['z' - 'a' + 1]['z' - 'a' + 1]['z' - 'a' + 1] = {{0}};
    int c0 = EOF, c1;
    int t0 = EOF, t1, t2;
    if (dr) {
        int i = 0;
        while ((en = readdir(dr)) != NULL) {
            if (i > 1) {
                snprintf(path, sizeof(path), "/Users/edore/CLionProjects/BigramsTrigrams/Gutenberg/txt/%s", en->d_name);
                FILE *plain = fopen(path, "r");
                if (plain != NULL) {
                    while ((c1 = getc(plain)) != EOF) {
                        if (c1 >= 'a' && c1 <= 'z' && c0 >= 'a' && c0 <= 'z') {
                            countBigrams[c0 - 'a'][c1 - 'a']++;
                        }
                        c0 = c1;
                    }
                    fclose(plain);
                }
                FILE *file = fopen(path, "r");
                if (file != NULL) {
                    while ((t2 = getc(file)) != EOF) {
                        if (t2 >= 'a' && t2 <= 'z' && t1 >= 'a' && t1 <= 'z' && t0 >= 'a' && t0 <= 'z') {
                            countTrigrams[t0 - 'a'][t1 - 'a'][t2 - 'a']++;
                        }
                        t0 = t1;
                        t1 = t2;
                    }
                    fclose(file);
                }
            }
            i++;
        }
    }
    closedir(dr);
    int64_t time=currentTimeMillis()-start;
    for (c0 = 'a'; c0 <= 'z'; c0++) {
        for (c1 = 'a'; c1 <= 'z'; c1++) {
            int n = countBigrams[c0 - 'a'][c1 - 'a'];
            if (n) {
                printf("%c%c: %d\n", c0, c1, n);
            }
        }
    }
    for (t0 = 'a'; t0 <= 'z'; t0++) {
        for (t1 = 'a'; t1 <= 'z'; t1++) {
            for (t2 = 'a'; t2 <= 'z'; t2++) {
                int n = countTrigrams[t0 - 'a'][t1 - 'a'][t2 - 'a'];
                if (n) {
                    printf("%c%c%c: %d\n", t0, t1, t2, n);
                }
            }
        }
    }
    printf("Tempo totale di esecuzione: ms ""%"PRId64"\n", time);
    return 0;
}

int64_t currentTimeMillis() {
    struct timeval time;
    gettimeofday(&time, NULL);
    int64_t s1 = (int64_t) (time.tv_sec) * 1000;
    int64_t s2 = (time.tv_usec / 1000);
    return s1 + s2;
}