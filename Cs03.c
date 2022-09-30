//C program to check validity of IP address

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define N 100
int validate_number(char *str) {
//Checking if the character is a number
   while (*str) {
      if(!isdigit(*str)){
         return 0;
      }
      str++;
   }
   return 1;
}
//Checking validity
int validate_ip(char *ip) {
   int i, num, dots = 0;
   char *ptr;
   if (ip == NULL)
      return 0;
      ptr = strtok(ip, ".");
      if (ptr == NULL)
         return 0;
   while (ptr) {
   //Checking the data type of substring
      if (!validate_number(ptr))
         return 0;
         num = atoi(ptr);
         if (num >= 0 && num <= 255) {
            ptr = strtok(NULL, ".");
            if (ptr != NULL)
               dots++;
         } else
            return 0;
    }
//If the number of dots are not 3 the the IP address is invalid
    if (dots != 3)
       return 0;
      return 1;
}
//Main Function
int main() {
   char ip1[N];
  printf("Enter the IP Address\n");
  scanf("%s",&ip1);
   char ip2[N];
   printf("Enter the IP Address\n");
  scanf("%s",&ip2);
   validate_ip(ip1)? printf("Valid\n"): printf("Not valid\n");
   validate_ip(ip2)? printf("Valid\n"): printf("Not valid\n");
return 0;
}
