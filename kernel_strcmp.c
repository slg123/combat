#include <stdio.h>

void compare_them(const char *s1, const char *s2);

int main() 
{
    const unsigned char *s1 = "Test";
    const unsigned char *s2 = "Test";
    const unsigned char *s3 = "Scott";

    compare_them(s1, s2);
    compare_them(s1, s3);

    return 0;
}

// kernel strcmp() from linux-2.6/arch/x86/boot
int strcmp(const char *str1, const char *str2)
{
    const unsigned char *s1 = (const unsigned char *)str1;
    const unsigned char *s2 = (const unsigned char *)str2;
    int delta = 0;

    while (*s1 || *s2) {
        delta = *s2 - *s1;
        if (delta)
            return delta;
        s1++;
        s2++;
    }
    return 0;
}

void compare_them(const char *s1, const char *s2)
{
    if (strcmp(s1, s2))
        printf("%s != %s\n", s1, s2);
    else
        printf("%s == %s\n", s1, s2); 
}

