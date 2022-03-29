<!--

	STRING.md

	By: xbeheydt <xavier.beheydt@gmail.com>

	Created: 2022/04/28

-->
# 42 Cursus - libft - String helpers and handlers

## Helpers

- [`int ft_isascii(int c)`](../src/ft_isascii.c) : checks whether `c` is a 7-bit `unsigned char` value that fits into the ASCII character set.
- [`int ft_isprint(int c)`](../src/ft_isprint.c) : checks for any printable character including space.
- [`int ft_islower(int c)`](../src/ft_islower.c) : checks for a lowercase character.
- [`int ft_isupper(int c)`](../src/ft_isupper.c) : checks for a uppercase character.
- [`int ft_isalpha(int c)`](../src/ft_isalpha.c) : checks for an alphabetic character, it is equivalent to `(ft_isupper(c) || ft_islower(c))`.
- [`int ft_isdigit(int c)`](../src/ft_isdigit.c) : checks for a digit (0 through 9).
- [`int ft_isalnum(int c)`](../src/ft_isalnum.c) : checks for an alphanumeric character, it is equivalent to `(isalpha(c) || isdigit(c))`.

> Several others could be implemented, such as `ft_isctrl`, `ft_isblack` and etc...

## Handlers

- [`int ft_tolower(int c)`](../src/ft_tolower.c) : if `c` is a uppercase letters, returns its lowercase equivalent.
- [`int ft_toupper(int c)`](../src/ft_toupper.c) : if `c` is a lowercase letters, returns its uppercase equivalent.
- [`char *ft_strchr(const char *s, int c)`](../src/ft_strchr.c) : returns a pointer to the first occurence of the character `c` in the string `s`.
- [`char *ft_strrchr(const char *s, int c)`](../src/ft_strrchr.c) : returns a pointer to the last occurence of the character `c` in the string `s`. 
- [`char *ft_strnstr(const char *haystack, const char *needle, size_t len)`](../src/ft_strnstr.c) : locates the first occurence ot the null-terminated string `needle` in the string `haystack`, where not more than `len` characters are searched.
- [`char *ft_strdup(const char *s1).c`](../src/ft_strdup.c) : returns a pointers to a new string which is a duplicate of the string `s1`. Memory for the new string is obtained with `malloc`, and can be freed with `free`.
- [`size_t ft_strlcat(char *dst, const char *src, size_t dstsize)`](../src/ft_strlcat.c) : appends the NULL-terminated string `src` to the end of `dst`. It will append at most `size - ft_strlen(src) - 1` bytes, NUL-terminating the result.
- [`size_t ft_strlcpy(char *dst, const char *src, size_t dstsize)`](../src/ft_strlcpy.c) : copies up to `dstsize - 1` characters from NUL-terminated string `src` to `dst`. NUL-terminating the result.
- [`size_t ft_strlen(const char *s)`](../src/ft_strlen.c) : calculates the length of the string pointed by `s`, excluding the terminating null byte (`\0`)
<!-- [`int ft_strcmp(const char *s1, const char *s2)`](../src/ft_strcmp.c) : compares the two string `s1` and `s2`. -->
- [`int ft_strncmp(const char *s1, const char *s2, size_t len)`](../src/ft_strncmp.c) : compares the two string `s1` and `s2` but only the first (at most) `len` bytes of `s1` and `s2`.
- [`char *ft_substr(char const *s, unsigned int start, size_t len)`](../src/ft_substr.c) : returns a pointer from the `start` index and the length `len` of the string `s`. Memory for the new string is obtained with `malloc` and can be freed with `free`.
- [`char **ft_split(char const *s, char c)`](../src/ft_split.c) : return a pointer of pointer of the string `s` splited by the character `c`. Memory for the new string array is obtained with `malloc` and can be freed with `free`.
- [`char *ft_strtrim(char const *s1, char const *set)`](../src/ft_strtrim.c) : returns a pointer trimed at start and end by the string `set` of the string `s1`. Memory for the new string is obtained with `malloc`, and can be freed with `free`.
- [`char *ft_strjoin(char const *s1, char const *s2)`](../src/ft_strjoin.c) : returns a pointer joined of the string `s1` and the string `s2`. Memory for the new string is obtained with `malloc`, and can be freed with `free`.
- [`char *ft_strmapi(char const *s, char (*f)(unsigned int, char)`](../src/ft_strmapi.c) : returns a pointer modified of the string `s` by function `f`. Memory for the new string is obtained with `malloc`, and can be freed with `free`.
- [`char *ft_striter(char const *s, char (*f)(unsigned int, char)`](../src/ft_striteri.c) : modifies of the string `s` with function `f`.
