So uh, I kinda made a libfttester. It is quite complete, with its own limitations.
Some perks of using this one :
- The code is easy to understand, everything is just in one program. Just compile it along your libft.a (or run gcc -Wall -Werror -Wextra *.c && ./a.out) and you're good to go.
- When an unexpected result is encountered, the program will show directly what the expected result was compareed to the obtained one. This might not always work properly with e.g. empty strings.
- Playing with the tests is easy, you just need to be in the right section of the program.

Limitations :
- Idk how to use file descriptors nor how to check the size of a malloc.
- If a test provokes a bus error or a segfault, you will have to search for it by yourself by fiddling with the tester (and no, ft_memmove should not bus error when src and dst point to the same place).
