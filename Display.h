
void menu(){
   printf("\n\n\t\t\t\t\t\t  DOTS AND BOXES");
   color(PURPLE,"\n\n\n\t\t0:NEW GAME\n\n");
   color(PURPLE,"\t\t1:Top Ten\n\n");
   color(PURPLE,"\t\t2:Continue\n\n");
   color(PURPLE,"\t\t3:EXIT\n\n\n\n");
   printf("\t\t4:enter your choice:");
   int x;
   scanf("%d",&x);
   system("cls");
    switch(x)
    {
     case 0:
        players_mode_ui();
        break;
    case 1:
        break;
    case 2:
        break;
    case 3:
        break;
    }


}

void players_mode_ui()
{
    color(YELLOW,"\n\n\n\t\t\t\t\t\t select mode \n\n\n\n\n");
    color(PURPLE,"\t\t 0:return to main menu\n\n");
    color(PURPLE,"\t\t 1:one player\n\n");
    color(PURPLE,"\t\t 2:two player\n\n");
    color(PURPLE,"\t\t 3:to EXIT\n\n\t\t ");
    color(RESET,"enter your choice:");
    int x;
    scanf("%d",&x);
    system("cls");
    switch(x)
    {
     case 0:
        menu();
        break;
    case 1:
        difficulty_mode_ui(x);
        break;
    case 2:
        difficulty_mode_ui(x);
        break;
    case 3:
        break;
    }

}

void difficulty_mode_ui(int p)
{
    color(YELLOW,"\n\n\n\t\t\t\t\t\t select difficulty \n\n\n\n\n");
    color(PURPLE,"\t\t 0:return to main menu\n\n");
    color(PURPLE,"\t\t 1:easy\n\n");
    color(PURPLE,"\t\t 2:hard\n\n");
    color(PURPLE,"\t\t 3:to EXIT\n\n\t\t ");
    printf("enter your choice:");
    int x;
    scanf("%d",&x);
    system("cls");
        switch(x)
    {
     case 0:
        menu();
        break;
    case 1:
        if (p == 2)
            twoplayersx3();
        else if(p == 1)
             break;
        break;
    case 2:

        break;
    case 3:
        break;
    }
}

void twoplayersx3()
 {
char playerOne[12][2]={{-1,-1},{-1,-1},{-1,-1},{-1,-1},{-1,-1},{-1,-1},{-1,-1},{-1,-1},{-1,-1},{-1,-1},{-1,-1},{-1,-1}};
char playerTwo[12][2]={{-1,-1},{-1,-1},{-1,-1},{-1,-1},{-1,-1},{-1,-1},{-1,-1},{-1,-1},{-1,-1},{-1,-1},{-1,-1},{-1,-1}};
char A[6][10]={{32,'1','2','3','4','5'},
                  {'1',254,32,254,32,254},
                  {'2',32,32,32,32,32},
                  {'3',254,32,254,32,254},
                  {'4',32,32,32,32,32},
                  {'5',254,32,254,32,254}};
int col=-1,row=-1,player=2;
int index1=0;
int index2=0;
while(1)

  {
    if (player%2==1 && row!=-1)
    {
        playerOne[index1][0]=row;
        playerOne[index1++][1]=col;
    }
    else if (player%2==0 && row!=-1)
    {
        playerTwo[index2][0]=row;
        playerTwo[index2++][1]=col;
    }

   for (int i=0;i<12;i++){
    for (int j=0;j<2;j++){
        printf("%d ",playerOne[i][j]);
    }
    printf("\n");
   }
   for (int i=0;i<12;i++){
    for (int j=0;j<2;j++){
        printf("%d ",playerTwo[i][j]);
    }
    printf("\n");
   }
   char shape;
   player++;
   if (row%2==1 && row!=-1)
   {
        shape=205;
        A[row][col]=shape;
   }
   else if (row%2==0 && row!=-1)
   {
        shape=186;
        A[row][col]=shape;
   }
   printf("\n\n");
   for (int i=0;i<6;i++){
        printf("\t\t\t\t\t\t   ");
    for(int j=0;j<6;j++){
        int variable =0;
        for (int k=0;k<12;k++)
        {
            if (i==playerOne[k][0]&&j==playerOne[k][1])
            {
                if (A[i][j]== 205)
                {
                    color_char(RED,A[i][j]);
                    color_char(RED,A[i][j]);
                    color_char(RED,A[i][j]);
                    variable=1;
                    break;
                }
                else
                {
                    color_char(RED,A[i][j]);
                    variable=1;
                    break;
                }



            }
            else if (i==playerTwo[k][0]&&j==playerTwo[k][1])
            {
                color_char(BLUE,A[i][j]);
                variable=1;
                break;
            }

        }
        if (variable==0)
           {
               printf("%c ",A[i][j]);
           }


   }printf("\n");}

   color_str(RED,"\n\tfirst player's name:","name");  color_str(BLUE,"\t\t\t\t\t   second player's name:","name");
   color_int(RED,"\n\n\tnumber of moves for first player:",5); color_int(BLUE,"\t\t\t\t   number of moves for second player:",5);
   color_int(RED,"\n\n\tfirst player's score:",5);  color_int(BLUE,"\t\t\t\t\t\t   second player's score:",5);
   color_int(YELLOW,"\n\n\tnumber of remaining lines:",3);
   color(CYAN,"\n\n\tenter 0,0 for undo\t1,1 for redo\t2,2 for save\t3,3 for main menu");

   if (player%2==1)
   {

            printf("\n\n\t>>>>first player\'s turn:\n");
            color(RED,"\n\n\tENTER ROW:");
            printf(RED); scanf("%d",&row); printf(RESET);
            color(RED,"\tENTER COL:");
            printf(RED); scanf("%d",&col); printf(RESET);

   }

   else if (player%2==0)
   {

            printf("\n\n\t>>>>second player\'s turn:\n");
            color(BLUE,"\n\n\tENTER ROW:");
            printf(BLUE); scanf("%d",&row); printf(RESET);
            color(BLUE,"\tENTER COL:");
            printf(BLUE); scanf("%d",&col); printf(RESET);
   }




   if(row%2==0 && col%2==0 || row%2==1 && col%2==1|| row<0 || row>5||col<0||col>5)
   {
       //elmafrod hena 3yzen nclear akher talat sotor lesa mesh 3arfa ezay
       printf("\33[2K\r");
       printf("\n\tinvalid numbers \n");
       player--;
       row=-1;


   }
   for (int k=0;k<12;k++)
           {
               if ( row==playerOne[k][0]&&col==playerOne[k][1] || row==playerTwo[k][0]&&col==playerTwo[k][1])
               {
                    printf("\33[2K\r");
                    printf("\n\tinvalid numbers \n");
                    player--;
                    row=-1;
                    break;
               }

           }



   system("cls");
 }
}
