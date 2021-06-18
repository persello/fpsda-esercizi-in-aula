#ifndef LIBSTRING_H
#define LIBSTRING_H

int my_strstr(char *s, char *t);
int my_strncmp(char *s, char *t, int n);
void my_strinsert(char s[], char t[]);
void my_strcat(char s[], char t[]);
void my_strcpy(char s[], char t[]);
int frase_palindroma(char s[]);
int palindroma(char s[]);
int my_strlen(char s[]);

#endif