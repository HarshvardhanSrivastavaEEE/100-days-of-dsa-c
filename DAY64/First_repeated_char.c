#include <stdio.h>
#include <string.h>

int main()
{
    char s[1000];
    scanf("%s", s);

    int freq[26] = {0};

    // count frequency
    for(int i = 0; s[i] != '\0'; i++)
    {
        freq[s[i] - 'a']++;
    }

    // find first repeated (smallest second occurrence)
    for(int i = 0; s[i] != '\0'; i++)
    {
        if(freq[s[i] - 'a'] > 1)
        {
            printf("%c\n", s[i]);
            return 0;
        }
    }

    printf("-1\n");
    return 0;
}