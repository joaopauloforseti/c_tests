#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
   char input[50];
   int i;

   fgets(input, 50, stdin);

   for(i = 0; i < 50; i++) {
      if(input[i] == '\n') break;
      printf("%c\n", input[i]);
   }
}
