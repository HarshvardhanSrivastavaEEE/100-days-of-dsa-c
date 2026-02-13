#include <stdio.h>

int main()
{
 char word[100];
 scanf("%s",word);
 int i = 0;
 int len = 0;
 while(word[i] != '\0')
 {
    len++;
    i++;
 }

 int low = 0;
 int high = len - 1;
 while(low < high)
 {
    int temp = word[low];
    word[low] = word[high];
    word[high] = temp;
    low++;
    high--;
 }
 printf("%s",word);
}
