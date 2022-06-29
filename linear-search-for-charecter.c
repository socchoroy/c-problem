#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define size 100
int available(char *word, char ch);
int main()
{

  char ch, thing[size];

  int have;
  printf("Please Enter a string : ");
  gets(thing);
  printf("Please Enter which charecter you want to search : ");
  scanf("%c", &ch);
  have = available(thing, ch);
  if (have == 1)
  {
    printf("we found the charetcer!");
  }
  else
  {
    printf("we didn't found it!");
  }
}
int available(char *word, char ch)
{
  int present = 0, count = 0, space = 0;
  while (*word != NULL)
  {
    count++;
    if (ch == *word)
    {
      present = 1;
      break;
    }
    word++;
  }
  printf("\nfound in %d position\n", count);
  return present;
}