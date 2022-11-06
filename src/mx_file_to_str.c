#include "../inc/libmx.h"

char *mx_file_to_str(const char *file) {
    if (file == NULL) return NULL;
    
    int fd = open(file, O_RDONLY);

    if (fd < 0) return NULL;

    int len = 0;
    char c;
    
    while (read(fd, &c, 1) != 0) len++;
    close(fd);
    fd = open(file, O_RDONLY);
    char *text = mx_strnew(len);
    
    for (int i = 0; read(fd, &c, 1); i++) {
        text[i] = c;
    }
    close(fd);
    return text;
}

