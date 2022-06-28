#include <stdio.h>
#include <string.h>
#define size 100
int search(char know[], int start, int highest, char want);
int main()
{
    int len, pos, start = 0;
    char word[size], ch;
    printf("Please Enter a string : ");
    gets(word);
    len = strlen(word);
    printf("Please Enter which charecter you want to search : ");
    scanf("%c", &ch);
    pos = search(word, start, len - 1, ch);
    if (pos == -1)
        printf("sorry! we didn't found it!");
    else
        printf("yes!we found it at %d position", pos + 1);

    return 0;
}

int search(char know[], int start, int highest, char want)
{
    if (know[start] == want)
        return start;
    else if (know[highest] == want)
        return highest;
    else if (start > highest)
        return -1;

    return search(know, start + 1, highest - 1, want);
}