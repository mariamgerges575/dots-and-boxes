
void menu(){
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
        break;
    case 3:
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
            oneplayerName();
        break;
    case 3:
         if (p == 3)
            twoplayersNames(3);
        else if(p == 2)
             oneplayerName();
        break;
    case 4:
        break;
    default:
        difficulty_mode_ui(p);
    }
}

void twoplayersx3(char name1[],char name2[])
 {



char playerOne[12][2];negative_one(playerOne,12);
char playerTwo[12][2];negative_one(playerTwo,12);
char A[6][10]={{32,'1','2','3','4','5'},
                  {'1',254,32,254,32,254},
                  {'2',32,32,32,32,32},
                  {'3',254,32,254,32,254},
                  {'4',32,32,32,32,32},
                  {'5',254,32,254,32,254}};
int col=-1,row=-1,player=2,index1=0,index2=0,box1=0,box2=0,box3=0,box4=0,bluewins=0,redwins=0,previousbluewins=0,previousredwins=0,winner,turnsOfPlayer1=0,turnsOfPlayer2=0,NoOfLines=12,timer=0;
char r[10],c[10];
time_t timeOfBeginning=time(0);



while(1)

  {

    if (player%2==1 && row!=-1)
    {
        playerOne[index1][0]=row;
        playerOne[index1++][1]=col;
        turnsOfPlayer1++;
        NoOfLines--;
    }
    else if (player%2==0 && row!=-1)
    {
        playerTwo[index2][0]=row;
        playerTwo[index2++][1]=col;
        turnsOfPlayer2++;
        NoOfLines--;
    }

   //boxes checking
    if (0<row && row<4 && 0<col && col<4 )
    {
        box1++;
    }

    if (0<row && row<4 && 2<col && col<6 )
    {
        box2++;
    }

    if (2<row && row<6 && 0<col && col<4 )
    {
       box3++;
    }

    if (2<row && row<6 && 2<col && col<6 )
    {
       box4++;
    }
    if (box1==4 || box2==4 || box3==4 || box4==4)
    {
        if (box1==4)
        {
            //A[2][2]=219;
            if (player%2==1)
            {
                playerOne[index1][0]=2;
                playerOne[index1++][1]=2;
                redwins++;
            }
            else
            {
               playerTwo[index2][0]=2;
               playerTwo[index2++][1]=2;
               bluewins++;
            }
            box1=0;
        }
        if (box2==4)
        {
            //A[2][4]=219;
            if (player%2==1)
            {
                playerOne[index1][0]=2;
                playerOne[index1++][1]=4;
                redwins++;
            }
            else
            {
               playerTwo[index2][0]=2;
               playerTwo[index2++][1]=4;
               bluewins++;
            }
            box2=0;
        }
        if (box3==4)
        {
            //A[4][2]=219;
            if (player%2==1)
            {
                playerOne[index1][0]=4;
                playerOne[index1++][1]=2;
                redwins++;
            }
            else
            {
               playerTwo[index2][0]=4;
               playerTwo[index2++][1]=2;
               bluewins++;
            }
            box3=0;
        }
        if (box4==4)
        {
            //A[4][4]=219;
            if (player%2==1)
            {
                playerOne[index1][0]=4;
                playerOne[index1++][1]=4;
                redwins++;
            }
            else
            {
                playerTwo[index2][0]=4;
                playerTwo[index2++][1]=4;
                bluewins++;
            }
            box4=0;
        }

        player++;
    }


   printf("%d\n%d\n%d\n%d\n%d\n%d\n",row,col,box1,box2,box3,box4);


   printf ("index1 %d index2 %d\n",index1,index2);
   printf(" bluewins %d redwins %d\n",bluewins,redwins);
   printf(" previousbluewins %d previousredwins %d\n",previousbluewins,previousredwins);
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
   printf("%d   %d   %d   %d",box1,box2,box3,box4);
   //char shape;
   player++;
  /* if (row%2==1 && row!=-1)
   {
        shape=205;
        A[row][col]=shape;
   }
   else if (row%2==0 && row!=-1)
   {
        shape=186;
        A[row][col]=shape;
   }*/

   //timeeee

   int timehrsMinSec[3]={0,0,0};
   getTime(timeOfBeginning,timehrsMinSec);





   printf("\n\n");
   for (int i=0;i<6;i++){
        printf("\t\t\t\t\t\t   ");
    for(int j=0;j<6;j++){
        int variable =0;
        for (int k=0;k<12;k++)
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

    }
   printf("\n");
   }

   if (redwins>2)
   {
       color_str(RED,"\n\n\t\t\t\t\t",name1);color(RED,"  WINS!");
       color(CYAN,"\n\n\tenter 0,0 for undo\t1,1 for redo\t2,2 for save\t3,3 for main menu");
       winner=1;

       break;

   }
   else if(bluewins>2)
   {
       color_str(BLUE,"\n\n\t\t\t\t\t",name2);color(BLUE,"  WINS!");
       color(CYAN,"\n\n\tenter 0,0 for undo\t1,1 for redo\t2,2 for save\t3,3 for main menu");
       winner=2;

       break;
   }
   else if (redwins==2 && bluewins==2)
   {
       printf ("\n\n\t tie");
       color(CYAN,"\n\n\tenter 0,0 for undo\t1,1 for redo\t2,2 for save\t3,3 for main menu");
       winner=0;

       break;
   }
   else
   {
       color_str(RED,"\n\n\n\n\t",name1);  color_str(BLUE,"\t\t\t\t\t\t    ",name2);

       color_int(RED,"\n\n\tnumber of moves for first player: ",turnsOfPlayer1); color_int(BLUE,"\t\t   number of moves for second player: ",turnsOfPlayer2);
       color_int(RED,"\n\n\tfirst player's score:",redwins);  color_int(BLUE,"\t\t\t\t   second player's score:",bluewins);
       color_int(YELLOW,"\n\n\tnumber of remaining lines:",NoOfLines);color_int(YELLOW,"\t\t\t TIME: ",timehrsMinSec[0]);color_int(YELLOW,":",timehrsMinSec[1]);color_int(YELLOW,":",timehrsMinSec[2]);
       color(CYAN,"\n\n\tenter 0,0 for undo\t1,1 for redo\t2,2 for save\t3,3 for main menu");

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




   if (row==1&&col==1)
   {
       if (turnsOfPlayer1==0 && turnsOfPlayer2==0)
       {
           system("cls");
           twoplayersNames(2);

       }
       else
       {
           system("cls");
           twoplayersx3(name1,name2);
       }



   }
   if (row==0 && col==0)
   {
       if (player%2==0)
       {
           if ((bluewins-previousbluewins)==1)
           {
               bluewins--;
               index2--;
               playerTwo[index2][0]=-1;
               playerTwo[index2][1]=-1;
               index2--;
                if (0<playerTwo[index2][0] && playerTwo[index2][0]<4 && 0<playerTwo[index2][1] && playerTwo[index2][1]<4 )
                {
                    if (box1==0)
                    {
                        box1=3;
                    }
                    else
                    {
                        box1--;
                    }
                }

                if (0<playerTwo[index2][0] && playerTwo[index2][0]<4 && 2<playerTwo[index2][1] && playerTwo[index2][1]<6 )
                {
                    if (box2==0)
                    {
                        box2=3;
                    }
                    else
                    {
                        box2--;
                    }
                }

                if (2<playerTwo[index2][0] && playerTwo[index2][0]<6 && 0<playerTwo[index2][1] && playerTwo[index2][1]<4 )
                {
                    if (box3==0)
                    {
                        box3=3;
                    }
                    else
                    {
                        box3--;
                    }
                }

                if (2<playerTwo[index2][0] && playerTwo[index2][0]<6 && 2<playerTwo[index2][1] && playerTwo[index2][1]<6 )
                {
                    if (box4==0)
                    {
                        box4=3;
                    }
                    else
                    {
                        box4--;
                    }
                }

                playerTwo[index2][0]=-1;
                playerTwo[index2][1]=-1;
                row=-1;
                player++;
                system("cls");

            }
           else if ((bluewins-previousbluewins)==2)
           {
                bluewins--;
                index2--;
                playerTwo[index2][0]=-1;
                playerTwo[index2][1]=-1;
                bluewins--;
                index2--;
                playerTwo[index2][0]=-1;
                playerTwo[index2][1]=-1;
                index2--;
                if (0<playerTwo[index2][0] && playerTwo[index2][0]<4 && 0<playerTwo[index2][1] && playerTwo[index2][1]<4 )
                {
                    box1=3;
                }

                if (0<playerTwo[index2][0] && playerTwo[index2][0]<4 && 2<playerTwo[index2][1] && playerTwo[index2][1]<6 )
                {
                    box2=3;
                }

                if (2<playerTwo[index2][0] && playerTwo[index2][0]<6 && 0<playerTwo[index2][1] && playerTwo[index2][1]<4 )
                {
                    box3=3;

                }
                if (2<playerTwo[index2][0] && playerTwo[index2][0]<6 && 2<playerTwo[index2][1] && playerTwo[index2][1]<6 )
                {
                    box4=3;

                }

                playerTwo[index2][0]=-1;
                playerTwo[index2][1]=-1;
                row=-1;
                player++;
                system("cls");



           }
           else if (bluewins-previousbluewins==0)
           {
                index1--;
                if (0<playerOne[index1][0] && playerOne[index1][0]<4 && 0<playerOne[index1][1] && playerOne[index1][1]<4 )
                {
                    box1--;
                }

                if (0<playerOne[index1][0] && playerOne[index1][0]<4 && 2<playerOne[index1][1] && playerOne[index1][1]<6 )
                {
                    box2--;
                }

                if (2<playerOne[index1][0] && playerOne[index1][0]<6 && 0<playerOne[index1][1] && playerOne[index1][1]<4 )
                {
                    box3--;
                }

                if (2<playerOne[index1][0] && playerOne[index1][0]<6 && 2<playerOne[index1][1] && playerOne[index1][1]<6 )
                {
                    box4--;
                }
                playerOne[index1][0]=-1;
                playerOne[index1][1]=-1;
                row=-1;
                system("cls");

           }


       }
       else
       {
           if ((redwins-previousredwins)==1)
           {
                redwins--;
                index1--;
                playerOne[index1][0]=-1;
                playerOne[index1][1]=-1;
                index1--;
                if (0<playerOne[index1][0] && playerOne[index1][0]<4 && 0<playerOne[index1][1] && playerOne[index1][1]<4 )
                {
                    printf(" \nbox1 %d\n",box1);
                    if (box1==0)
                    {
                        box1=3;
                        printf(" \nbox1 fel 3 %d\n",box1);

                    }
                    else
                    {
                        box1--;
                        printf(" \nbox1 fel -1 %d\n",box1);
                    }
                }

                if (0<playerOne[index1][0] && playerOne[index1][0]<4 && 2<playerOne[index1][1] && playerOne[index1][1]<6 )
                {
                    if (box2==0)
                    {
                        box2=3;
                    }
                    else
                    {
                        box2--;
                    }
            }

                if (2<playerOne[index1][0] && playerOne[index1][0]<6 && 0<playerOne[index1][1] && playerOne[index1][1]<4 )
                {
                    if (box3==0)
                    {
                        box3=3;
                    }
                    else
                    {
                        box3--;
                    }
                }

                if (2<playerOne[index1][0] && playerOne[index1][0]<6 && 2<playerOne[index1][1] && playerOne[index1][1]<6 )
                {
                    if (box4==0)
                    {
                        box4=3;
                    }
                    else
                    {
                        box4--;
                    }
                }
                playerOne[index1][0]=-1;
                playerOne[index1][1]=-1;
                row=-1;
                player++;
                system("cls");


           }
           else if ((redwins-previousredwins)==2)
           {
               redwins--;
               index1--;
               playerOne[index1][0]=-1;
               playerOne[index1][1]=-1;
               redwins--;
               index1--;
               playerOne[index1][0]=-1;
               playerOne[index1][1]=-1;
               index1--;
               if (0<playerOne[index1][0] && playerOne[index1][0]<4 && 0<playerOne[index1][1] && playerOne[index1][1]<4 )
                {
                    box1=3;
                }

                if (0<playerOne[index1][0] && playerOne[index1][0]<4 && 2<playerOne[index1][1] && playerOne[index1][1]<6 )
                {
                    box2=3;
                }

                if (2<playerOne[index1][0] && playerOne[index1][0]<6 && 0<playerOne[index1][1] && playerOne[index1][1]<4 )
                {
                    box3=3;
                }

                if (2<playerOne[index1][0] && playerOne[index1][0]<6 && 2<playerOne[index1][1] && playerOne[index1][1]<6 )
                {
                    box4=3;
                }
                playerOne[index1][0]=-1;
                playerOne[index1][1]=-1;
                row=-1;
                player++;
                system("cls");
            }
           else
           {
                index2--;
                if (0<playerTwo[index2][0] && playerTwo[index2][0]<4 && 0<playerTwo[index2][1] && playerTwo[index2][1]<4 )
                {
                    if (box1==0)
                    {
                        box1=3;
                }
                else
                {
                    box1--;
                }
            }

            if (0<playerTwo[index2][0] && playerTwo[index2][0]<4 && 2<playerTwo[index2][1] && playerTwo[index2][1]<6 )
            {
                if (box2==0)
                {
                    box2=3;
                }
                else
                {
                    box2--;
                }
            }

            if (2<playerTwo[index2][0] && playerTwo[index2][0]<6 && 0<playerTwo[index2][1] && playerTwo[index2][1]<4 )
            {
                if (box3==0)
                {
                    box3=3;
                }
                else
                {
                    box3--;
                }
            }

            if (2<playerTwo[index2][0] && playerTwo[index2][0]<6 && 2<playerTwo[index2][1] && playerTwo[index2][1]<6 )
            {
                if (box4==0)
                {
                    box4=3;
                }
                else
                {
                    box4--;
                }
            }

            playerTwo[index2][0]=-1;
            playerTwo[index2][1]=-1;
            row=-1;
            system("cls");
           }


       }
   }

   else
   {
        previousredwins=redwins;
        previousbluewins=bluewins;
       if(row%2==0 && col%2==0 || row%2==1 && col%2==1|| row<1 || row>5||col<1||col>5)
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
                    printf("\n\tinvalid numbers \n");
                    player--;
                    row=-1;
                    break;
               }

           }

   system("cls");
   }

   }


 }
}

void twoplayersx5(char name1[],char name2[])
 {
char playerOne[40][2]; negative_one(playerOne,40);
char playerTwo[40][2]; negative_one(playerTwo,40);

char A[10][10]= {{32,'1','2','3','4','5','6','7','8','9'},
                  {'1',254,32,254,32,254,32,254,32,254},
                  {'2',32,32,32,32,32,32,32,32,32},
                  {'3',254,32,254,32,254,32,254,32,254},
                  {'4',32,32,32,32,32,32,32,32,32},
                  {'5',254,32,254,32,254,32,254,32,254},
                  {'6',32,32,32,32,32,32,32,32,32},
                  {'7',254,32,254,32,254,32,254,32,254},
                  {'8',32,32,32,32,32,32,32,32,32},
                  {'9',254,32,254,32,254,32,254,32,254}};
int col=-1,row=-1,player=2,index1=0,index2=0,bluewins=0,redwins=0,winner,turnsOfPlayer1=0,turnsOfPlayer2=0,NoOfLines=40,timer=0;
int boxes[16]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
char r[10],c[10];
time_t timeOfBeginning=time(0);



while(1)

  {

    if (player%2==1 && row!=-1)
    {
        playerOne[index1][0]=row;
        playerOne[index1++][1]=col;
        turnsOfPlayer1++;
        NoOfLines--;
    }
    else if (player%2==0 && row!=-1)
    {
        playerTwo[index2][0]=row;
        playerTwo[index2++][1]=col;
        turnsOfPlayer2++;
        NoOfLines--;
    }

   //boxes checking
    if (0<row && row<4 && 0<col && col<4 )
        boxes[0]++;

    if (0<row && row<4 && 2<col && col<6 )
        boxes[1]++;

    if (2<row && row<6 && 4<col && col<8 )
       boxes[2]++;

    if (2<row && row<6 && 6<col && col<10 )
       boxes[3]++;

    if (2<row && row<6 && 0<col && col<4 )
        boxes[4]++;

    if (2<row && row<6 && 2<col && col<6 )
        boxes[5]++;

    if (2<row && row<6 &&  4<col && col<8)
       boxes[6]++;

    if (2<row && row<6 && 6<col && col<10 )
       boxes[7]++;

    if (4<row && row<8 && 0<col && col<4 )
        boxes[8]++;

    if (4<row && row<8 && 2<col && col<6 )
        boxes[9]++;

    if (4<row && row<8 && 4<col && col<8 )
       boxes[10]++;

    if (4<row && row<8 && 6<col && col<10 )
       boxes[11]++;

    if (6<row && row<10 && 0<col && col<4 )
        boxes[12]++;

    if (6<row && row<10 && 2<col && col<6 )
        boxes[13]++;

    if (6<row && row<10 &&  4<col && col<8)
       boxes[14]++;

    if (6<row && row<10 && 6<col && col<10 )
       boxes[15]++;


    if (boxes[0]==4 || boxes[1]==4 || boxes[2]==4 || boxes[3]==4 || boxes[4]==4 || boxes[5]==4 || boxes[6]==4 || boxes[7]==4
        || boxes[8]==4 || boxes[9]==4 || boxes[10]==4 || boxes[11]==4 || boxes[12]==4 || boxes[13]==4 || boxes[14]==4 || boxes[15]==4)
    {
        if (boxes[0]==4)
        {
            A[2][2]=219;
            if (player%2==1)
            {
                playerOne[index1][0]=2;
                playerOne[index1++][1]=2;
                redwins++;
            }
            else
            {
               playerTwo[index2][0]=2;
               playerTwo[index2++][1]=2;
               bluewins++;
            }
            boxes[0]=0;
        }
        if (boxes[1]==4)
        {
            A[2][4]=219;
            if (player%2==1)
            {
                playerOne[index1][0]=2;
                playerOne[index1++][1]=4;
                redwins++;
            }
            else
            {
               playerTwo[index2][0]=2;
               playerTwo[index2++][1]=4;
               bluewins++;
            }
            boxes[1]=0;
        }
        if (boxes[2]==4)
        {
            A[2][6]=219;
            if (player%2==1)
            {
                playerOne[index1][0]=2;
                playerOne[index1++][1]=6;
                redwins++;
            }
            else
            {
               playerTwo[index2][0]=2;
               playerTwo[index2++][1]=6;
               bluewins++;
            }
            boxes[2]=0;
        }
        if (boxes[3]==4)
        {
            A[2][8]=219;
            if (player%2==1)
            {
                playerOne[index1][0]=2;
                playerOne[index1++][1]=8;
                redwins++;
            }
            else
            {
                playerTwo[index2][0]=2;
                playerTwo[index2++][1]=8;
                bluewins++;
            }
            boxes[3]=0;
        }
        if (boxes[4]==4)
        {
            A[4][2]=219;
            if (player%2==1)
            {
                playerOne[index1][0]=4;
                playerOne[index1++][1]=2;
                redwins++;
            }
            else
            {
               playerTwo[index2][0]=4;
               playerTwo[index2++][1]=2;
               bluewins++;
            }
            boxes[4]=0;
        }
        if (boxes[5]==4)
        {
            A[4][4]=219;
            if (player%2==1)
            {
                playerOne[index1][0]=4;
                playerOne[index1++][1]=4;
                redwins++;
            }
            else
            {
               playerTwo[index2][0]=4;
               playerTwo[index2++][1]=4;
               bluewins++;
            }
            boxes[5]=0;
        }
        if (boxes[6]==4)
        {
            A[4][6]=219;
            if (player%2==1)
            {
                playerOne[index1][0]=4;
                playerOne[index1++][1]=6;
                redwins++;
            }
            else
            {
               playerTwo[index2][0]=4;
               playerTwo[index2++][1]=6;
               bluewins++;
            }
            boxes[6]=0;
        }
        if (boxes[7]==4)
        {
            A[4][8]=219;
            if (player%2==1)
            {
                playerOne[index1][0]=4;
                playerOne[index1++][1]=8;
                redwins++;
            }
            else
            {
                playerTwo[index2][0]=4;
                playerTwo[index2++][1]=8;
                bluewins++;
            }
            boxes[7]=0;
        }
        if (boxes[8]==4)
        {
            A[6][2]=219;
            if (player%2==1)
            {
                playerOne[index1][0]=6;
                playerOne[index1++][1]=2;
                redwins++;
            }
            else
            {
               playerTwo[index2][0]=6;
               playerTwo[index2++][1]=2;
               bluewins++;
            }
            boxes[8]=0;
        }
        if (boxes[9]==4)
        {
            A[6][4]=219;
            if (player%2==1)
            {
                playerOne[index1][0]=6;
                playerOne[index1++][1]=4;
                redwins++;
            }
            else
            {
               playerTwo[index2][0]=6;
               playerTwo[index2++][1]=4;
               bluewins++;
            }
            boxes[9]=0;
        }
        if (boxes[10]==4)
        {
            A[6][6]=219;
            if (player%2==1)
            {
                playerOne[index1][0]=6;
                playerOne[index1++][1]=6;
                redwins++;
            }
            else
            {
               playerTwo[index2][0]=6;
               playerTwo[index2++][1]=6;
               bluewins++;
            }
            boxes[10]=0;
        }
        if (boxes[11]==4)
        {
            A[6][8]=219;
            if (player%2==1)
            {
                playerOne[index1][0]=6;
                playerOne[index1++][1]=8;
                redwins++;
            }
            else
            {
                playerTwo[index2][0]=6;
                playerTwo[index2++][1]=8;
                bluewins++;
            }
            boxes[11]=0;
        }
        if (boxes[12]==4)
        {
            A[8][2]=219;
            if (player%2==1)
            {
                playerOne[index1][0]=8;
                playerOne[index1++][1]=2;
                redwins++;
            }
            else
            {
               playerTwo[index2][0]=8;
               playerTwo[index2++][1]=2;
               bluewins++;
            }
            boxes[12]=0;
        }
        if (boxes[13]==4)
        {
            A[8][4]=219;
            if (player%2==1)
            {
                playerOne[index1][0]=8;
                playerOne[index1++][1]=4;
                redwins++;
            }
            else
            {
               playerTwo[index2][0]=8;
               playerTwo[index2++][1]=4;
               bluewins++;
            }
            boxes[13]=0;
        }
        if (boxes[14]==4)
        {
            A[8][6]=219;
            if (player%2==1)
            {
                playerOne[index1][0]=8;
                playerOne[index1++][1]=6;
                redwins++;
            }
            else
            {
               playerTwo[index2][0]=8;
               playerTwo[index2++][1]=6;
               bluewins++;
            }
            boxes[14]=0;
        }
        if (boxes[15]==4)
        {
            A[8][8]=219;
            if (player%2==1)
            {
                playerOne[index1][0]=8;
                playerOne[index1++][1]=8;
                redwins++;
            }
            else
            {
                playerTwo[index2][0]=8;
                playerTwo[index2++][1]=8;
                bluewins++;
            }
            boxes[15]=0;
        }


        player++;
    }





   /*for (int i=0;i<12;i++){
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
   }*/
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

   //timeeee

   int timehrsMinSec[3]={0,0,0};
   getTime(timeOfBeginning,timehrsMinSec);





   printf("\n\n");
   for (int i=0;i<10;i++){
        printf("\t\t\t\t\t\t   ");
    for(int j=0;j<10;j++){
        int variable =0;
        for (int k=0;k<40;k++)
        {
            if (i==playerOne[k][0]&&j==playerOne[k][1])
            {
                  color_char(RED,A[i][j]);
                  variable=1;
                  break;



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


   if (redwins>8)
   {
       color_str(RED,"\n\n\t\t\t\t\t",name1);color(RED,"  WINS!");
       color(CYAN,"\n\n\tenter 0,0 for undo\t1,1 for redo\t2,2 for save\t3,3 for main menu");
       winner=1;

       break;

   }
   else if(bluewins>8)
   {
       color_str(BLUE,"\n\n\t\t\t\t\t",name2);color(BLUE,"  WINS!");
       color(CYAN,"\n\n\tenter 0,0 for undo\t1,1 for redo\t2,2 for save\t3,3 for main menu");
       winner=2;

       break;
   }
   else if (redwins==8 && bluewins==8)
   {
       printf ("\n\n\t tie");
       color(CYAN,"\n\n\tenter 0,0 for undo\t1,1 for redo\t2,2 for save\t3,3 for main menu");
       winner=0;

       break;
   }
   else
   {
       color_str(RED,"\n\n\n\n\t",name1);  color_str(BLUE,"\t\t\t\t\t\t    ",name2);

       color_int(RED,"\n\n\tnumber of moves for first player: ",turnsOfPlayer1); color_int(BLUE,"\t\t   number of moves for second player: ",turnsOfPlayer2);
       color_int(RED,"\n\n\tfirst player's score:",redwins);  color_int(BLUE,"\t\t\t\t   second player's score:",bluewins);
       color_int(YELLOW,"\n\n\tnumber of remaining lines:",NoOfLines);color_int(YELLOW,"\t\t\t TIME: ",timehrsMinSec[0]);color_int(YELLOW,":",timehrsMinSec[1]);color_int(YELLOW,":",timehrsMinSec[2]);
       color(CYAN,"\n\n\tenter 0,0 for undo\t1,1 for redo\t2,2 for save\t3,3 for main menu");

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

   if (row==1&&col==1)
   {
       if (turnsOfPlayer1==0 && turnsOfPlayer2==0)
       {
           system("cls");
           twoplayersNames(3);

       }
       else
       {
           system("cls");
           twoplayersx5(name1,name2);
       }
   }
    if (row==3&&col==3)
   {
       system("cls");
       menu();
   }
   if(row%2==0 && col%2==0 || row%2==1 && col%2==1|| row<0 || row>9||col<0||col>9)
   {
       //elmafrod hena 3yzen nclear akher talat sotor lesa mesh 3arfa ezay
       player--;
       row=-1;


   }
   for (int k=0;k<40;k++)
           {
               if ( row==playerOne[k][0]&&col==playerOne[k][1] || row==playerTwo[k][0]&&col==playerTwo[k][1])
               {
                    player--;
                    row=-1;
                    break;
               }

           }

   system("cls");
   }

 }
}
