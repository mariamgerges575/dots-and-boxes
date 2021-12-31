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

void initialize_grid(int m,char A[m][m])
{   int i,j; char k=49;
    A[0][0]=32;
    for (i=1;i<m;i++)
    {
        A[0][i]=k;
        A[i][0]=k++;
    }

    for(i=1;i<m;i++)
    {
        for(j=1;j<m;j++)
        {
             if(i%2==0)
            {
               A[i][j]=32;
            }
            else if(i%2==1)
            {
                if(j%2==0)
                    A[i][j]=32;
                else
                    A[i][j]=254;
            }
        }
    }
    return;
}

int choose_file()
{   char s[10]; int x;
    color(PURPLE,"\n 1 for file 1 \n 2 for file 2 \n 3 for file 3");
    printf("\nenter the number");x=scan_int(s);
    return x;
}


void continue_fn(FILE *file,int m,char player1[m][2],char player2[m][2])
{   fopen(file,"r");
    for(int i=10;i<m;i++)
    {
        fscanf(file ,"%c %c ",&player1[i][0],&player1[i][1]);
    }
    for(int i=10;i<m;i++)
    {
        fscanf(file ,"%c %c ",player2[i][0],player2[i][1]);
    }
    fclose(file);
}
void save (FILE *file,int m,char player1[m][2],char player2[m][2])
{   fopen(file,"r");
    for(int i=10;i<m;i++)
    {
        fprintf(file ,"%c %c ",player1[i][0],player1[i][1]);
    }

    for(int i=10;i<m;i++)
    {
        fprintf(file ,"%c %c ",player2[i][0],player2[i][1]);
    }
    fclose(file);
}

