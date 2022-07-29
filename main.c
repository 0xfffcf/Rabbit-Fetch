#include <stdio.h>
#include <stdlib.h>

#define BLUE "\e[33m"
#define RESET "\e[0m"

int main(void)
{
    FILE *fpipe;
    char kernel[10];
    char shell[12];
    char terminal[25];
    char separator[15];

    if ((fpipe = popen("uname -r", "r")) == 0)
    {
        return -1;
    }

    fgets(kernel, sizeof(kernel), fpipe);

    if ((fpipe = popen("echo $SHELL", "r")) == 0)
    {
        return -1;
    }

    fgets(shell, sizeof(terminal), fpipe);

    if ((fpipe = popen("echo $TERM", "r")) == 0)
    {
        return -1;
    }

    fgets(terminal, sizeof(terminal), fpipe);
    pclose(fpipe);

    system("clear");
    sprintf(separator, "%s~%s", BLUE, RESET);
    printf("(\\ /)     kern %s %s( . .)    shell %s %sc(%s\"%s)(%s\"%s)   term %s %s",
           separator, kernel, separator, shell, BLUE, RESET, BLUE, RESET, separator, terminal);

    return 0;
}