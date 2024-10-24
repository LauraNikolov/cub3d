# LIBFT

## 42 Project

Replica of these libc functions: 

- • isalpha
- • isdigit
- • isalnum
- • isascii
- • isprint
- • strlen
- • memset
- • bzero
- • memcpy
- • memmove
- • strlcpy
- • strlcat
- • toupper
- • tolower
- • strchr
- • strrchr
- • strncmp
- • memchr
- • memcmp
- • strnstr
- • atoi 
- • calloc
- • strdup

and some supplementary functions :

| Function name | ft_substr |
| :------------ | :-------- |
| Prototype | ```char *ft_substr(char const *s, unsigned int start, unsigned int len)``` | 
| Parameters | s: The string from which to extract the new string. start: The start index of the new string in the string 's'. len: The maximum size of the new string | 
| Return value | The new string. NULL is allocation failed. |
| Description | Allocate (with malloc) and return a string from the 's' string. This new string starts at the 'start' index and has for maximal size 'len'. | 

| Function name | ft_strjoin |
| :------------ | :-------- |
| Prototype | ```char *ft_strjoin(char const *s1, char const *s2```
| Parameters |  | s1: The prefix string. s2: The suffix string. | 
| Return value | The new string. NULL if allocation failed. |
| Description | Allocate (with malloc) and return a new string, the result of concatenation of s1 and s2. | 

| Function name | ft_strtrim |
| :------------ | :-------- |
| Prototype | ```char *ft_strtrim(char const *s1, char const *set```
| Parameters |  | The string to trim. set: The character reference set to be trimmed. | 
| Return value | The trimmed string. NULL is allocation failed. |
| Description | Allocate (with malloc) and return a copy of the s1 string, without the caracters specified in 'set, at the beginning and at the end of the string. | 

| Function name | ft_split |
| :------------ | :-------- |
| Prototype | ```char **ft_split(char const *s, char c)```
| Parameters |  | s: The string to cut. c: The delimitating caracter. | 
| Return value | The array of new strings, the result from the slicing. NULL is allocation failed. |
| Description |Alloue (with malloc(3)) and returns an array of strings obtained by separating 's' with the character 'c', used as a delimiter. The array must be terminated by NULL | 


(TO COMPLETE)


