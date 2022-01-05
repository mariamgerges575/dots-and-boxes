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
long int getTime (int timeOfBeginning,int timehrsMinSec[],long int oldTime)
{
    long int timer;
    time_t timenow=time(0);
    timer= timenow-timeOfBeginning+oldTime;
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
     return timer;

}

void negative_one(int A[][2],int m)
{
    for (int i=0;i<m;i++)
    {
        A[i][0]=-1;
        A[i][1]=-1;
    }
}
void zeros(int m ,int A[m])
{
    for (int i=0;i<m;i++)
    {
        A[i]=0;
    }
}

void oneplayerName(int x)
{
    char name[10];
    GetName(name);
    oneplayerx3(name,x,0,0);
}
void twoplayersNames(int x)
{char name1[10],name2[10];
 GetNames(name1,name2);
 twoplayers(name1,name2,x,0,0);
}
void GetName (char p1[10])
{
    color(RED,"\n\n\n\n\n\n\t ENTER THE NAME OF THE PLAYER:");
    printf(RED);fgets(p1,10,stdin);printf(RESET);
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

void check_boxes(int player1[40][2],int player2[40][2],int noOfboxes,int boxes[noOfboxes],int maxi,int maxj, int indwin[4],int maxturns)
{  int k=0,box=0,colwin=2,rowwin=2,i,j,M,found1=0,found2=0;
    while(k<maxturns && (player1[k][0]!=-1 || player1[k][0]!=-1 || player2[k][0]!=-1 || player2[k][0]!=-1))
    {   rowwin=2; box=0;
        for ( i=0;i<maxi;i+=2)
        {   colwin=2;
            for( j=0;j<maxj;j+=2)
            {
                if(i<player1[k][0] && player1[k][0]<(i+4) && j<player1[k][1] && player1[k][1]<(j+4)  || i<player2[k][0] && player2[k][0]<(i+4) && j<player2[k][1] && player2[k][1]<(j+4) )
                {

                     if( i<player1[k][0] && player1[k][0]<(i+4) && j<player1[k][1] && player1[k][1]<(j+4) && (player1[k][0]%2!=0 || player1[k][1]%2!=0) )
                    {
                        boxes[box]++;
                        if(boxes[box]==4)
                        {   found1=0; M=0;
                            while ( M<maxturns && (player1[k][0]!=-1 || player1[k][0]!=-1) )
                            {
                                if (player1[M][0]==rowwin && player1[M][1]==colwin)
                                {
                                   found1=1;
                                   break;
                                }
                            M++;
                            }
                            if (found1==0)
                            {
                               player1[indwin[0]][0]=rowwin;
                               player1[indwin[0]++][1]=colwin;
                               player2[indwin[1]][0]=-1;
                               player2[indwin[1]++][1]=0;
                            }

                        indwin[2]++;
                        }
                    }
                    else if ( i<player2[k][0] && player2[k][0]<(i+4) && j<player2[k][1] && player2[k][1]<(j+4) && ( player2[k][0]%2!=0 || player2[k][1]%2!=0 ) )
                    {
                        boxes[box]++;
                        if(boxes[box]==4)
                        {   found2=0; M=0;
                            while (M<maxturns && (player2[k][0]!=-1 || player2[k][0]!=-1) )
                            {
                                if (player2[M][0]==rowwin && player2[M][1]==colwin)
                                {
                                    found2=1;
                                    break;
                                }
                            M++;
                            }
                            if (found2==0)
                            {
                                player1[indwin[0]][0]=-1;
                                player1[indwin[0]++][1]=0;
                                player2[indwin[1]][0]=rowwin;
                                player2[indwin[1]++][1]=colwin;
                            }
                        indwin[3]++;
                        }
                    }
                }
            box++;
            colwin+=2;
            }
        rowwin+=2;
        }
     k++;
    }
}
void printing_grid(int sizeOfGrid,int maxturns ,int playerOne[maxturns][2] ,int playerTwo[maxturns][2],char A[sizeOfGrid][sizeOfGrid])
{
    printf("\n\n");
   for (int i=0;i<sizeOfGrid;i++){
        printf("\t\t\t\t\t\t   ");
    for(int j=0;j<sizeOfGrid;j++){
        int variable =0;
        if (i==0 || j==0)
        {
            printf("%c ",A[i][j]);
        }
        else{
        for (int k=0;k<maxturns;k++)
        {
            char shape;
            if (A[i][j]==32 )
                  {

                      if (i%2==1)
                      {
                          shape=205;
                      }
                      else if (i%2==0 && j%2==0)
                      {
                          shape=219;
                      }
                      else if(i%2==0 && j%2==1)
                      {
                          shape=186;
                      }
                  }
            if (i==playerOne[k][0]&&j==playerOne[k][1])
            {

                  color_char(RED,shape);
                  variable=1;
                  break;



            }
            else if (i==playerTwo[k][0]&&j==playerTwo[k][1])
            {
                  color_char(BLUE,shape);
                  variable=1;
                  break;
            }

        }
        if (variable==0)
           {
               printf("%c ",A[i][j]);
           }

    }}
   printf("\n");
   }

}
int whose_turn(int maxturns,int playerOne[maxturns][2],int playerTwo[maxturns][2],int player)
{
       for(int i=0;i<maxturns;i++)
       {
        if (playerOne[i][0]==-1 && playerOne[i][1]==-1)
        {
            if (i-1<0)
            {
                player=1;
                break;
            }
            else
            {
                if (playerOne[i-1][0]==-1 && playerOne[i-1][1]==0)
                {
                    if (playerTwo[i-1][0]%2==0 && playerTwo[i-1][1]%2==0)
                    {
                        player=2;
                        break;
                    }
                    else
                    {
                        player=1;
                        break;
                    }

                }
                else if (playerOne[i-1][0]%2==0 && playerOne[i-1][1]%2==0)
                {
                    player=1;
                    break;
                }
                else
                {
                    player=2;
                    break;
                }

            }
        }
   }
   return player;
}
struct game
{
    char playerOne[40];
    char playerTwo[40];
    int time;
    int difficulty;
    int noOfPLayers;
    int name1;
    int name2;
};
/*void saveClicked (char arrayOfPlayerOne[][],char arrayOfplayerTwo[],int timer,int difficulty,int noOfPLayers,int name_1,int name_2)
{
    printf("choose one of  the following files\n\n1:file1\n2:file2\n3:file3\nyour choice:");
    char r[10];
    int choice;
    choice=scan_int(r);
    if (choice==1)
    {
        struct game file1;
        file1.playerOne=arrayOfPlayerOne;
        file1.playerTwo=arrayOfplayerTwo;
        file1.time=timer;
        file1.difficulty=difficulty;
        file1.noOfPLayers=noOfPLayers;
        file1.name1=name_1;
        file1.name2=name_2;
    }
    if (choice==2)
    {
        struct game file2;
        file2.playerOne=arrayOfPlayerOne;
        file2.playerTwo=arrayOfplayerTwo;
        file2.time=timer;
        file2.difficulty=difficulty;
        file2.noOfPLayers=noOfPLayers
    }
    if (choice==3)
    {
        struct game file3;
        file3.playerOne=arrayOfPlayerOne;
        file3.playerTwo=arrayOfplayerTwo;
        file3.time=timer;
        file3.difficulty=difficulty;
        file3.noOfPLayers=noOfPLayers;
    }
    system(cls);
    menu();
}*/
void undo_checkBoxes (int maxturns,int noOfBoxes,int computer[maxturns][2],int indwin[4],int box1array[4][2],int box2array[4][2],int box3array[4][2],int box4array[4][2],int box5array[4][2],int box6array[4][2],int box7array[4][2],int box8array[4][2],int box9array[4][2],int box10array[4][2],int box11array[4][2],int box12array[4][2],int box13array[4][2],int box14array[4][2],int box15array[4][2],int box16array[4][2],int box_index[noOfBoxes])
{
    for (int i=0;i<4;i++)
                    {
                        if (computer[indwin[0]][0]==box1array[i][0] && computer[indwin[0]][1]==box1array[i][1])
                        {
                            box_index[0]--;
                        }
                        if (computer[indwin[0]][0]==box2array[i][0] && computer[indwin[0]][1]==box2array[i][1])
                        {
                            box_index[1]--;
                        }
                        if (computer[indwin[0]][0]==box3array[i][0] && computer[indwin[0]][1]==box3array[i][1])
                        {
                            box_index[2]--;
                        }
                        if (computer[indwin[0]][0]==box4array[i][0] && computer[indwin[0]][1]==box4array[i][1])
                        {
                            box_index[3]--;
                        }
                        if (computer[indwin[0]][0]==box5array[i][0] && computer[indwin[0]][1]==box5array[i][1])
                        {
                            box_index[4]--;
                        }
                        if (computer[indwin[0]][0]==box6array[i][0] && computer[indwin[0]][1]==box6array[i][1])
                        {
                            box_index[5]--;
                        }
                        if (computer[indwin[0]][0]==box7array[i][0] && computer[indwin[0]][1]==box7array[i][1])
                        {
                            box_index[6]--;
                        }
                        if (computer[indwin[0]][0]==box8array[i][0] && computer[indwin[0]][1]==box8array[i][1])
                        {
                            box_index[7]--;
                        }
                        if (computer[indwin[0]][0]==box9array[i][0] && computer[indwin[0]][1]==box9array[i][1])
                        {
                            box_index[8]--;
                        }
                        if (computer[indwin[0]][0]==box10array[i][0] && computer[indwin[0]][1]==box10array[i][1])
                        {
                            box_index[9]--;
                        }
                        if (computer[indwin[0]][0]==box11array[i][0] && computer[indwin[0]][1]==box11array[i][1])
                        {
                            box_index[10]--;
                        }
                        if (computer[indwin[0]][0]==box12array[i][0] && computer[indwin[0]][1]==box12array[i][1])
                        {
                            box_index[11]--;
                        }
                        if (computer[indwin[0]][0]==box13array[i][0] && computer[indwin[0]][1]==box13array[i][1])
                        {
                            box_index[12]--;
                        }
                        if (computer[indwin[0]][0]==box14array[i][0] && computer[indwin[0]][1]==box14array[i][1])
                        {
                            box_index[13]--;
                        }
                        if (computer[indwin[0]][0]==box15array[i][0] && computer[indwin[0]][1]==box15array[i][1])
                        {
                            box_index[14]--;
                        }
                        if (computer[indwin[0]][0]==box16array[i][0] && computer[indwin[0]][1]==box16array[i][1])
                        {
                            box_index[15]--;
                        }


                    }
}
