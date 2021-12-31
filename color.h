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

void GetNames (char p1[10],char p2[10])
{

    color(RED,"\n\n\n\n\n\n\t ENTER THE NAME OF THE FIRST PLAYER:");
    printf(RED);gets(p1);printf(RESET);
    color(BLUE,"\n\n\t ENTER THE NAME OF THE SECOND PLAYER:");
    printf(BLUE);gets(p2);printf(RESET);
    system("cls");

}
void getTime (int timeOfBeginning,int timehrsMinSec[])
{
    int timer;
    time_t timenow=time(0);
    timer= timenow-timeOfBeginning;
    int hours=0,minutes=0,seconds=0;
    minutes=timer/60;
    seconds=timer-60*minutes;
    if (minutes>59)
    {
        hours=minutes/60;
        minutes=minutes-60*hours;
    }

     timehrsMinSec[0]=hours;
     timehrsMinSec[1]=minutes;
     timehrsMinSec[2]=seconds;

}
void twoplayersNames(int x)
{char name1[10],name2[10];
 GetNames(name1,name2);
 twoplayers(name1,name2,x);
  /* switch(x)
   {
    case(2):
        twoplayersx3(name1,name2);
    case(3):
        twoplayersx5(name1,name2);
    }*/
}

int negative_one(char A[][2],int m)
{
    for (int i=0;i<m;i++)
    {
        A[i][0]=-1;
        A[i][1]=-1;
    }
}

void oneplayerName()
{
    char name[10];
    GetName(name);
    oneplayerx3(name);
}
void GetName (char p1[10])
{
    color(RED,"\n\n\n\n\n\n\t ENTER THE NAME OF THE PLAYER:");
    printf(RED);gets(p1);printf(RESET);
    system("cls");
}

/*void initialize_grid (int n,int m,char A[ ][n])
{
        A[0]={32,'1','2','3','4','5','6','7','8','9'};
        A[1]={'1',254,32,254,32,254,32,254,32,254};
        A[2]={'2',32,32,32,32,32,32,32,32,32};
        A[3]={'3',254,32,254,32,254,32,254,32,254};
        A[4]={'4',32,32,32,32,32,32,32,32,32};
        A[5]={'5',254,32,254,32,254,32,254,32,254};
        A[6]={'6',32,32,32,32,32,32,32,32,32};
        A[7]={'7',254,32,254,32,254,32,254,32,254};
        A[8]={'8',32,32,32,32,32,32,32,32,32};
        A[9]{'9',254,32,254,32,254,32,254,32,254};
    return 0;

}*/

