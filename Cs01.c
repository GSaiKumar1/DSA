// C program to check the valididy of an email address
//2115051

#include <stdio.h>
#include <stdbool.h>
#include<string.h>

int check1(char *email){
    int i=0,count1=0,pos1,length=0;
//Calculating the frequency of @ and the length of the email 
    while(email[i]!='\0'){
        if(email[i]=='@'){
            count1++;
            pos1=i;
        }
        length++;
         i++;
    }
//If @ occurs 0 or more the 1 times the the email is invalid
    if(count1!=1){
        return 0;
    }
    i=0;
    int count2=0,pos2,arr[2];
    while(email[i]!='\0'){
        if(email[i]=='"'){
            count2++;
           arr[count2-1]=i;
        }
         i++;
    }
//If the email does not starts or ends with alphabets then it is invalid
    if(email[0]<'a' && email[0]>'z' || email[0]<'A' && email[0]>'Z' && email[0]=='@'){
        return 0;
    }
//If special characters are given outside quotes the the email is in valid
    if(count2==0){
        if(email[0]=='.' || email[length-1]=='.')
        {
            return 0;
        }
        for(int i=1;i<length;i++){
            if(email[i]==email[i-1] && email[i]=='.'){
                return 0;
            }
        }
    }
//If special characters are given outside quotes the the email is in valid
    if(count2==2){
    for(int i=0;i<arr[0];i++){
        if(email[i]<'a' && email[i]>'z' || email[i]<'A' && email[i]>'Z' || email[i]<'0' && email[i]>'9' 
        || email[i]=='@' || email[i]!='+'){
            return 0;
        }
    }
    for(int i=arr[1];i<length;i++){
        if(email[i]<'a' && email[i]>'z' || email[i]<'A' && email[i]>'Z' || email[i]<'0' && email[i]>'9' 
        || email[i]=='@' || email[i]!='+'){
            return 0;
        }
    }
    }
//Checking the local part of the email
   //i=0;
   for(int i=0;i<pos1;i++){
         if(email[i]<'a' && email[i]>'z' || email[i]<'A' && email[i]>'Z' || email[i]<'0' && email[i]>'9' || email[i]=='-'){
            return 0;
        }
    }
 
//Checking the domain part of the email
   for(int i=pos1;i<length;i++){
        if(email[i]<'a' && email[i]>'z' || email[i]<'A' && email[i]>'Z' || email[i]<'0' && email[i]>'9' && email[i]!='-'){
            return 0;
        }
    }
    int count_dot=0;
    for(int i=pos1;i<length;i++){
        if(email[i]=='.'){
            count_dot++;
        }
    }
    if(count_dot<1){
        return 0;
    }
    return 1;
}
int main()
{
	char email[254];
    scanf("%s",email);
    if(check1(email)==1){
        printf("Valid");
    }
    else{
        printf("Invalid");
    }
	return 0;
}
