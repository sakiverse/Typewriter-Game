#include <stdio.h>

char a[] = "Hello,World";
char memory[128]="";
int i = 0;

int strlen(char *s)
{
    int len = 0;
    while (s[len] != '\0')
    {
        len++;
    }
    return len;
}

void update()
{
    if (i < 0)
    {
        printf("Game over! you failed!\n");
        fputs(a, stdout);
        printf("\n");
        i = 0;
        memory[0] = '\0';
        update();
        return;
    }

    if (a[i] == '\0')
    {
        printf("\nyou win!\n");
        return;
    }
    printf(memory);
    char input[127];
    fgets(input, sizeof(input), stdin);

    int found = 0;
    if (input[0] == a[i])
    {
        found = 1;
    }

    if (found)
    {
        printf("PERFECT \n");
        memory[i] = a[i];
        i++;
    }
    else
    {
        printf("MISS \n");
        memory[i] = '\0';
        i--;
    }

    update();
}

int main()
{
    int len = strlen(a);
    for (int j = 0; j < len; j++)
    {
        if (a[j] == '\n')
            printf("\\n");
        else
            printf("%c", a[j]);
    }
    printf("\n");

    update();
    return 0;
}
