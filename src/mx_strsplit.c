#include "../inc/libmx.h"

char **mx_strsplit(const char *s, char c) {
    if (s == NULL) return NULL;
    
    int num_of_words = mx_count_words(s, c);
    char **arr = (char**)malloc(num_of_words);
    int j = 0;
    
    for (int i = 0; i < num_of_words; i++) {
        int length_of_word = 0;
        int start = 0;
        
        while (s[j] != '\0') {
            if (s[j] != c) {
                length_of_word++;
                if (start == 0) start = j;
            }
            else
                if (s[j] == c && length_of_word) break;
            j++;
        }
        char *word = mx_strnew(length_of_word);
        int n = 0;
        
        for (int m = start; m < j; m++)
            word[n++] = s[m];
        arr[i] = word;
    }
    arr[num_of_words] = 0;
    return arr;
}

