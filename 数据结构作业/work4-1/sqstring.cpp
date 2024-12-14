#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 256 // 假设最大长度为256

typedef struct {
    char *str;
    size_t length;
} SqString;

void init_sqstring(SqString *s, const char *initial) {
    s->length = strlen(initial);
    s->str = (char*)malloc(s->length + 1);
    if (s->str != NULL) {
        strcpy(s->str, initial);
    }
}

void destroy_sqstring(SqString *s) {
    free(s->str);
    s->str = NULL;
    s->length = 0;
}

void print_sqstring(const SqString *s) {
    printf("%s\n", s->str);
}

size_t get_length(const SqString *s) {
    return s->length;
}

void insert_substring(SqString *dest, const SqString *src, size_t pos) {
    if (pos > dest->length || src->length + dest->length >= MAX_LEN) return;

    dest->str = (char*)realloc(dest->str, dest->length + src->length + 1);
    memmove(dest->str + pos + src->length, dest->str + pos, dest->length - pos + 1);
    memcpy(dest->str + pos, src->str, src->length);
    dest->length += src->length;
}

void delete_substring(SqString *s, size_t pos, size_t n) {
    if (pos >= s->length) return;

    n = (n > s->length - pos) ? s->length - pos : n;
    memmove(s->str + pos, s->str + pos + n, s->length - pos - n + 1);
    s->length -= n;
}

void replace_substring(SqString *dest, const SqString *src, size_t pos, size_t n) {
    delete_substring(dest, pos, n);
    insert_substring(dest, src, pos);
}

SqString extract_substring(const SqString *s, size_t start, size_t length) {
    SqString result;
    if (start >= s->length) {
        init_sqstring(&result, "");
        return result;
    }

    length = (length > s->length - start) ? s->length - start : length;
    char *substr = (char*)malloc(length + 1);
    strncpy(substr, s->str + start, length);
    substr[length] = '\0';
    init_sqstring(&result, substr);
    free(substr);
    return result;
}

void concatenate(SqString *dest, const SqString *src) {
    if (dest->length + src->length >= MAX_LEN) return;

    dest->str = (char*)realloc(dest->str, dest->length + src->length + 1);
    strcat(dest->str, src->str);
    dest->length += src->length;
}