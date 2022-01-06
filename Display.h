void menu(){
//    Read_scores();
   printing_top11_file();
   printf("\n\n\t\t\t\t\t\t  DOTS AND BOXES");
   color(PURPLE,"\n\n\n\t\t1:NEW GAME\n\n");
   color(PURPLE,"\t\t2:Top Ten\n\n");
   color(PURPLE,"\t\t3:Continue\n\n");
   color(PURPLE,"\t\t4:EXIT\n\n\n\n");
   printf("\t\t5:enter your choice:");
   char s [10];int x;
   x=scan_int(s);
   system("cls");
    switch(x)
    {
     case 1:
        players_mode_ui();
        break;
    case 2:
        show_top10();
        break;
    case 3:
        pre_continue();
        break;
    case 4:
        break;
    default:
        menu();
    }
}

void players_mode_ui()
{
    color(YELLOW,"\n\n\n\t\t\t\t\t\t select mode \n\n\n\n\n");
    color(PURPLE,"\t\t 1:return to main menu\n\n");
    color(PURPLE,"\t\t 2:one player\n\n");
    color(PURPLE,"\t\t 3:two player\n\n");
    color(PURPLE,"\t\t 4:to EXIT\n\n\t\t ");
    color(RESET,"enter your choice:");
    int x; char s[10];
    x=scan_int(s);
    system("cls");
    switch(x)
    {
     case 1:
        menu();
        break;
    case 2:
        difficulty_mode_ui(x);
        break;
    case 3:
        difficulty_mode_ui(x);
        break;
    case 4:
        break;
    default:
        players_mode_ui();
    }

}

void difficulty_mode_ui(int p)
{
    color(YELLOW,"\n\n\n\t\t\t\t\t\t select difficulty \n\n\n\n\n");
    color(PURPLE,"\t\t 1:return to main menu\n\n");
    color(PURPLE,"\t\t 2:easy\n\n");
    color(PURPLE,"\t\t 3:hard\n\n");
    color(PURPLE,"\t\t 4:to EXIT\n\n\t\t ");
    printf("enter your choice:");
    int x; char s[10];
    x=scan_int(s);
    system("cls");
        switch(x)
    {
     case 1:
        menu();
        break;
    case 2:
        if (p == 3)
            twoplayersNames(2);
        else if(p == 2)
            oneplayerName(2);
        break;
    case 3:
         if (p == 3)
            twoplayersNames(3);
        else if(p == 2)
             oneplayerName(3);
        break;
    case 4:
        break;
    default:
        difficulty_mode_ui(p);
    }
}


void twoplayers(char name1[],char name2[],int difficulty,int continuefn,int file_number)
{
     int sizeOfGrid,noOfBoxes,maxi,maxj,maxturns,maxlines,y;
if (difficulty==2)
{
     sizeOfGrid=6;
     noOfBoxes=4;
     maxi=3;
     maxturns=24; maxlines=12;
}
else if (difficulty==3)
{
     sizeOfGrid=10;
     noOfBoxes=16;
     maxi=7;
     maxturns=60; maxlines=40;
}
maxj=maxi;
int bluewinsarray[12],redwinsarray[12],box1array[12],box2array[12],box3array[12],box4array[12];
zeros(12,bluewinsarray);zeros(12,redwinsarray);zeros(12,box1array);zeros(12,box2array);zeros(12,box3array);zeros(12,box4array);

int undo1array[maxturns][2];negative_one(undo1array,maxturns);
int undo2array[maxturns][2];negative_one(undo2array,maxturns);
int playerOne[maxturns][2];negative_one(playerOne,maxturns);
int playerTwo[maxturns][2];negative_one(playerTwo,maxturns);
char A[sizeOfGrid][sizeOfGrid]; initialize_grid(sizeOfGrid,A);
int undo=0,indexOfUndo1=0,noOfWinsPerTurn=0,windifference=0,indexOfUndo2=0,N=0,x=0,redo=1,col=-1,row=-1,player=2,previousbluewins=0,previousredwins=0,winner,turnsOfPlayer1=0,turnsOfPlayer2=0,noOflines=maxlines;
char r[10],c[10]; int boxes[noOfBoxes]; zeros(noOfBoxes,boxes); long int timer;
time_t timeOfBeginning=time(0);
int indwin[4]; zeros(4,indwin); //[0]=index1,[1]=index2,[2]=redwins,[3]=bluewins;
long int oldTime=0;
if(continuefn==1)
{
    FILE *file1=fopen("file1.txt","r");FILE *file2=fopen("file2.txt","r");FILE *file3=fopen("file3.txt","r");
    opening_files(file_number,file1,file2,file3,maxturns,playerOne,playerTwo,indwin,name1,name2,oldTime);
    close(file1);close(file2);close(file3);
}
while(1)

  {
    /////////////////////////////////////////////////////////INITIALIZING ALL VALUES WITH ZERO/////////////////////////////////////////////////
    indwin[3]=0;indwin[2]=0;noOfWinsPerTurn=0;turnsOfPlayer1=0;turnsOfPlayer2=0;windifference=0;
    zeros(noOfBoxes,boxes);

    ////////////////////////////////////////////////////////ADDING THE TWO NEW POINTS////////////////////////////////////////////////////////////
    if (player%2==1 && row!=-1)
    {
        playerOne[indwin[0]][0]=row;
        playerOne[indwin[0]++][1]=col;
        playerTwo[indwin[1]][0]=-1;
        playerTwo[indwin[1]++][1]=0;
    }
    else if (player%2==0 && row!=-1)
    {
        playerTwo[indwin[1]][0]=row;
        playerTwo[indwin[1]++][1]=col;
        playerOne[indwin[0]][0]=-1;
        playerOne[indwin[0]++][1]=0;
    }


   //////////////////////////////////////////////////////////////counting turns//////////////////////////////////////////////////////////////////
   for (int i=0;i<maxturns;i++)
   {
       if ( (playerOne[i][0]%2==1 && playerOne[i][1]%2==0 || playerOne[i][0]%2==0 && playerOne[i][1]%2==1)&& playerOne[i][0]!=-1)
        turnsOfPlayer1++;
       if ( (playerTwo[i][0]%2==1 && playerTwo[i][1]%2==0 || playerTwo[i][0]%2==0 && playerTwo[i][1]%2==1)&& playerTwo[i][0]!=-1)
        turnsOfPlayer2++;
   }

//////////////////////////////////////////////////////////////GETTING THE VALUES OF BOXES AFTER EACH TURN///////////////////////////////////////////
check_boxes(playerOne,playerTwo,noOfBoxes,boxes,maxi,maxj,indwin,maxturns);

////////////////////////////////////////////////////TIME/////////////////////////////////////////////////////////////////////////////////
   int timehrsMinSec[3]={0,0,0};
   timer=getTime(timeOfBeginning,timehrsMinSec,oldTime);


////////////////////////////////////////////////////////////GETTING WHOSE TURN IT IS/////////////////////////////////////////////////////////////
   player =whose_turn(maxturns,playerOne,playerTwo,player);

////////////////////////////////////////////////////////////////GETTING WINDIFFERENCE/////////////////////////////////////////////////////////
    for (int i=0;i<maxturns;i++)
    {
        if (playerOne[i][0]==-1 && playerOne[i][1]==-1)
        {
            if (playerOne[i-1][0]%2==0 && playerOne[i-1][1]%2==0 && playerTwo[i-1][0]==-1 && playerTwo[i-1][1]%2==0)
            {
                windifference++;
                if (playerOne[i-2][0]%2==0 && playerOne[i-2][1]%2==0 && playerTwo[i-2][0]==-1 && playerTwo[i-2][1]%2==0)
                {
                    windifference++;
                }
            }
        }
        if (playerTwo[i][0]==-1 && playerTwo[i][1]==-1)
        {
            if (playerTwo[i-1][0]%2==0 && playerTwo[i-1][1]%2==0 && playerOne[i-1][0]==-1 && playerOne[i-1][1]%2==0)
            {
                windifference++;
                if (playerTwo[i-2][0]%2==0 && playerTwo[i-2][1]%2==0 && playerOne[i-2][0]==-1 && playerOne[i-2][1]%2==0)
                {
                    windifference++;
                }
            }
        }
    }

//////////////////////////////////////////////////////////getting no of lines////////////////////////////////////////////////////////////////
if (difficulty==2)
    noOflines=12;
else
    noOflines=40;

for (int i=0;i<maxturns;i++)
{
    if (playerOne[i][0]%2==0 && playerOne[i][1]%2==1 || playerOne[i][0]%2==1 && playerOne[i][1]%2==0)

        noOflines--;
    if (playerTwo[i][0]%2==0 && playerTwo[i][1]%2==1 || playerTwo[i][0]%2==1 && playerTwo[i][1]%2==0)
        noOflines--;
}

/////////////////////////////////////////////////////////////////PRINTING THE GRID////////////////////////////////////////////////////////////
printing_grid(sizeOfGrid,maxturns ,playerOne,playerTwo,A);


//////////////////////////////////////////////DID SOMEONE WIN////////////////////////////////////////////////////////////////////////////
   /*if (indwin[2]>noOfBoxes/2)
   {
       color_str(RED,"\n\n\t\t\t\t\t",name1);color(RED,"  WINS!");
       color(CYAN,"\n\n\tenter 0,0 for undo\t1,1 for redo\t2,2 for save\t3,3 for main menu");
       winner=1;

       break;

   }
   else if(indwin[3]>noOfBoxes/2)
   {
       color_str(BLUE,"\n\n\t\t\t\t\t",name2);color(BLUE,"  WINS!");
       color(CYAN,"\n\n\tenter 4,4 for main menu");
       winner=2;

       break;
   }
   else if (indwin[2]==noOfBoxes/2 && indwin[3]==noOfBoxes/2)
   {
       printf ("\n\n\t tie");
       color(CYAN,"\n\n\tenter 4,4 for main menu");
       winner=0;

       break;
   }*/
   if(noOflines==0)
   {
       if(indwin[2]>indwin[3])
        {
       color(RED,"\n\n\tFIRST PLAYER WINS!\n");
       color(RESET,"\t\t\t\tSCORE: ");color_int(RED,"",indwin[2]);color_str(RED," for ",name1);color(RESET," TO ");color_int(BLUE,"",indwin[3]);color_str(BLUE," for ",name2);
       color(CYAN,"\n\n\tenter 4,4 for main menu");
       winner=1;
       printf("%d %s",indwin[2],name1);
       save_scores(indwin[2],name1);
       break;
       }
       else if(indwin[2]<indwin[3])
       {
            color(BLUE,"\n\n\tSECOND PLAYER WINS!\n");
            color(RESET,"\t\t\t\t\tSCORE: ");color_int(BLUE,"",indwin[3]);color_str(BLUE," for ",name2);color(RESET," TO ");color_int(RED,"",indwin[2]);color_str(RED," for ",name1);
            color(CYAN,"\n\n\tenter 4,4 for main menu");
            winner=1;
            save_scores(indwin[3],name2);
            break;

       }
       else if(indwin[2]==indwin[3])
       {
            printf ("\n\n\t tie");
            color(CYAN,"\n\n\tenter 3,3 for main menu");
            winner=0;
            break;
       }
   }
   else
   {
       color_str(RED,"\n\n\n\n\t",name1);  color_str(BLUE,"\t\t\t\t\t\t    ",name2);

       color_int(RED,"\n\n\tnumber of moves for first player: ",turnsOfPlayer1); color_int(BLUE,"\t\t   number of moves for second player: ",turnsOfPlayer2);
       color_int(RED,"\n\n\tfirst player's score:",indwin[2]);  color_int(BLUE,"\t\t\t\t   second player's score:",indwin[3]);
       color_int(YELLOW,"\n\n\tnumber of remaining lines:",noOflines);color_int(YELLOW,"\t\t\t   TIME: ",timehrsMinSec[0]);color_int(YELLOW,":",timehrsMinSec[1]);color_int(YELLOW,":",timehrsMinSec[2]);
       color(CYAN,"\n\n\tenter 1,1 for undo\t 2,2 for redo\t3,3 for save\t4,4 for main menu\t1,1 for clear");

/////////////////////////////////////////////////////choose row and col/////////////////////////////////////////////////////////////////////////////
   if (player%2==1)
   {

            printf("\n\n\t>>>>first player\'s turn:\n");
            color(RED,"\n\n\tENTER ROW:");
            printf(RED); row=scan_int(r); printf(RESET);
            color(RED,"\tENTER COL:");
            printf(RED); col=scan_int(c); printf(RESET);

   }

   else if (player%2==0)
   {

            printf("\n\n\t>>>>second player\'s turn:\n");
            color(BLUE,"\n\n\tENTER ROW:");
            printf(BLUE);row=scan_int(r); printf(RESET);
            color(BLUE,"\tENTER COL:");
            printf(BLUE); col=scan_int(c); printf(RESET);
   }



//////////////////////////////////////////////////////////////////////////////UNDO//////////////////////////////////////////////////
   if (row==1 && col==1)
   {
       if(noOflines==maxlines)
       {
           printf("no possible undo");
           row=-1;
       }
       else{


       if (windifference==0)
       {
           x=1;
       }
       else if (windifference==1)
       {
           x=2;
       }
       else if (windifference==2)
       {
           x=3;

       }
       for (int i=0;i<x;i++)
       {


               indwin[0]--;indwin[1]--;
               if (indwin[0]<0)
                 {indwin[0]++;
                  indwin[1]++;
                break;}
               undo1array[indexOfUndo1][0]=playerOne[indwin[0]][0];
               undo1array[indexOfUndo1][1]=playerOne[indwin[0]][1];
               undo2array[indexOfUndo1][0]=playerTwo[indwin[0]][0];
               undo2array[indexOfUndo1++][1]=playerTwo[indwin[0]][1];
               playerOne[indwin[0]][0]=-1;
               playerOne[indwin[0]][1]=-1;
               playerTwo[indwin[0]][0]=-1;
               playerTwo[indwin[0]][1]=-1;


       }
       row=-1;
       col=-1;
       undo=1;
       system("cls");


   }
   }
////////////////////////////////////////////////////////////////REDO//////////////////////////////////////////////////////////////////
  else if (row==2 && col==2)
   {
       row=-1;
       if (undo==0)
       {
           redo=0;
           player--;
           system("cls");
       }
       else if (undo==1)
       {
           for (int i=0;i<x;i++)
           {
                indexOfUndo1--;
                if (indexOfUndo1<0)
                {
                    redo=0;
                    undo=0;
                    break;
                }
                else
                {
                playerOne[indwin[0]][0]=undo1array[indexOfUndo1][0];
                playerOne[indwin[0]][1]=undo1array[indexOfUndo1][1];
                playerTwo[indwin[0]][0]=undo2array[indexOfUndo1][0];
                playerTwo[indwin[0]][1]=undo2array[indexOfUndo1][1];
                undo1array[indexOfUndo1][0]=-1;
                undo1array[indexOfUndo1][1]=-1;
                undo2array[indexOfUndo1][0]=-1;
                undo2array[indexOfUndo1][1]=-1;
                indwin[0]++;indwin[1]++;
                }

           }

            system("cls");
       }
   }
   else if (row==3 && col==3)
   {
    FILE *file1=fopen("file1.txt","w");FILE *file2=fopen("file2.txt","w");FILE *file3=fopen("file3.txt","w");
    y=choose_file();
    creating_files(2,difficulty,y,file1,file2,file3,maxturns,playerOne,playerTwo,indwin,name1,name2,timer);
    fclose(file1);fclose(file2);fclose(file3);
    system("cls");
    menu();

    }
    else if (row==4 && col==4)
    {
        system("cls");
        menu();
    }
   else
   {
        undo=0;x=0;redo=1;
        negative_one(undo1array,20);
        negative_one(undo2array,20);

       if(row%2==0 && col%2==0 || row%2==1 && col%2==1|| row<1 || row>sizeOfGrid-1||col<1||col>sizeOfGrid-1)
   {
       row=-1;

   }
   else{
   for (int k=0;k<maxturns;k++)
           {
               if ( row==playerOne[k][0]&&col==playerOne[k][1] || row==playerTwo[k][0]&&col==playerTwo[k][1])
               {
                    player--;
                    row=-1;
                    break;
               }

           }}

   system("cls");
   }

   }
 }
        color(RESET,"\n\n\tENTER ROW:");
        row=scan_int(r);
        color(RESET,"\tENTER COL:");
        col=scan_int(c);
         if (row==4 && col==4)
        {
            system("cls");
            menu();
        }
 }


