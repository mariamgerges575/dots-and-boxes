#include<stdio.h>
#include<stdlib.h>
#define RED "\033[1;31m"
#define BLACK "\033[1;30m"
#define YELLOW "\033[1;33m"
#define GREEN "\033[1;32m"
#define BLUE "\033[1;34m"
#define PURPLE "\033[1;35m"
#define CYAN "\033[1;36m"
#define RESET "\033[1;0m"
void color(char c[7], char text[10]){
   system("");
   printf("%s%s%s",c,text,RESET);
}
void color_int(char c[7], char text[10],int x){
   system("");
   printf("%s%s%d%s",c,text,x,RESET);
}
void color_str(char c[7], char text[10],char x[10]){
   system("");
   printf("%s%s%s%s",c,text,x,RESET);
}
void color_char(char c[7], char text){
   system("");
   printf("%s%c %s",c,text,RESET);
}
int scan_int(char s[])
{  int a;int len;
        gets(s);
        len=strlen(s);
        if(len==1 && isdigit(s[0]))
           {
              a=s[0]-48;
           }
        else
         {
             a=0;
         }
return a;
}



