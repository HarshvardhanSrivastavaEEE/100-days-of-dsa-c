#include <stdio.h>

int main()
{
  int arr[10] = {44,2,3,32,66,77,26,99,101,37};
  int cnt = 0;
  int k = 99;
  int found_index = -1;
  for(int i = 0; i < 10; i++)
  {
    if(arr[i] == k)
    {
      found_index = i;
      cnt++;
      break;
    }
    cnt++;
  }
  printf("Found at index: %d",found_index);
  printf("Number of comparisons took: %d",cnt);
}