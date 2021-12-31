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


void twoplayers(char name1[],char name2[],int difficulty)
{
     int sizeOfGrid,noOfBoxes;
if (difficulty==3)
{
     sizeOfGrid=6;
     noOfBoxes=4;
}
else if (difficulty==5)
{
     sizeOfGrid=10;
     noOfBoxes=16;
}
char bluewinsarray[12]={0,0,0,0,0,0,0,0,0,0,0,0},redwinsarray[12]={0,0,0,0,0,0,0,0,0,0,0,0},box1array[12]={0,0,0,0,0,0,0,0,0,0,0,0},box2array[12]={0,0,0,0,0,0,0,0,0,0,0,0},box3array[12]={0,0,0,0,0,0,0,0,0,0,0,0},box4array[12]={0,0,0,0,0,0,0,0,0,0,0,0};


char undo1array[40][2];negative_one(undo1array,40);
char undo2array[40][2];negative_one(undo2array,40);
char playerOne[40][2];negative_one(playerOne,40);
char playerTwo[40][2];negative_one(playerTwo,40);
char A[10][10]; initialize_grid(10,A);
int undo=0,indexOfUndo1=0,noOfWinsPerTurn=0,windifference=0,indexOfUndo2=0,N=0,x=0,redo=1,col=-1,row=-1,player=2,index1=0,index2=0,bluewins=0,redwins=0,previousbluewins=0,previousredwins=0,winner,turnsOfPlayer1=0,turnsOfPlayer2=0,NoOfLines=12,timer=0,box1,box2,box3,box4,box5,box6,box7,box8,box9,box10,box11,box12,box13,box14,box15,box16;
char r[10],c[10];
time_t timeOfBeginning=time(0);

while(1)

  {
      printf ("\n undo1\n");
      for (int i=0;i<20;i++){
    for (int j=0;j<2;j++){
        printf("%d ",undo1array[i][j]);
    }
    printf("\n");

   }
   printf ("\n undo2\n");
   printf("\n");
   for (int i=0;i<40;i++){
    for (int j=0;j<2;j++){
        printf("%d ",undo2array[i][j]);
    }
    printf("\n");
   }
    //////////////INITIALIZING ALL VALUES WITH ZERO
    bluewins=0;redwins=0;noOfWinsPerTurn=0;turnsOfPlayer1=0;turnsOfPlayer2=0;windifference=0;
    printf("\ni=%d\n",N);
    printf("player = %d",player);
    ////////////ADDING THE TWO NEW POINTS
    if (player%2==1 && row!=-1)
    {
        playerOne[index1][0]=row;
        playerOne[index1++][1]=col;
        playerTwo[index2][0]=-1;
        playerTwo[index2++][1]=0;

        NoOfLines--;
    }
    else if (player%2==0 && row!=-1)
    {
        playerTwo[index2][0]=row;
        playerTwo[index2++][1]=col;
        playerOne[index1][0]=-1;
        playerOne[index1++][1]=0;

        NoOfLines--;
    }


   //counting turns
   for (int i=0;i<40;i++)
   {
       if ( (playerOne[i][0]%2==1 && playerOne[i][1]%2==0 || playerOne[i][0]%2==0 && playerOne[i][1]%2==1)&& playerOne[i][0]!=-1)
        turnsOfPlayer1++;
       if ( (playerTwo[i][0]%2==1 && playerTwo[i][1]%2==0 || playerTwo[i][0]%2==0 && playerTwo[i][1]%2==1)&& playerTwo[i][0]!=-1)
        turnsOfPlayer2++;

   }
   box5=0;box1=0;box2=0;box3=0;box4=0;box5=0;box6=0;box7=0;box8=0;box9=0;box10=0;box11=0;box12=0;box13=0;box14=0;box15=0;box16=0;
   //////GETTING THE VALUES OF BOXES AFTER EACH TURN
   for (int i=0;i<40;i++)
   {
        if ( playerOne[i][0]%2==0 && playerOne[i][1]%2==0 && playerOne[i][0]!=-1 && playerOne[i][1]!=0 && playerTwo[i][0]%2==0 && playerTwo[i][1]%2==0 && playerTwo[i][0]!=-1 && playerTwo[i][1]!=0)
        {
            box1=box1;
        }
        else
        {
            if (0<playerOne[i][0] && playerOne[i][0]<4 && 0<playerOne[i][1] && playerOne[i][1]<4  )
            {
                box1++;

                if (box1==4)
                {
                    int found=0;
                    for (int i=0;i<40;i++)
                    {
                        if (playerOne[i][0]==2 &&playerOne[i][1]==2)

                        {
                            found=1;
                            break;
                        }

                    }
                    if (found==0)
                        {
                            playerOne[index1][0]=2;
                            playerOne[index1++][1]=2;
                            playerTwo[index2][0]=-1;
                            playerTwo[index2++][1]=0;

                        }
                    redwins++;
                }
            }
            if (0<playerOne[i][0] && playerOne[i][0]<4 && 2<playerOne[i][1] && playerOne[i][1]<6 )
            {
                box2++;
                if (box2==4)
                {
                    int found=0;
                    for (int i=0;i<40;i++)
                    {
                        if(playerOne[i][0]==2 &&playerOne[i][1]==4)
                        {
                            found=1;
                            break;
                        }

                    }

                 if (found==0)
                        {
                            playerOne[index1][0]=2;
                            playerOne[index1++][1]=4;
                            playerTwo[index2][0]=-1;
                            playerTwo[index2++][1]=0;
                        }
                 redwins++;
                }
            }
                if (2<playerOne[i][0] && playerOne[i][0]<6 && 0<playerOne[i][1] && playerOne[i][1]<4 )
            {
                box3++;
                if (box3==4)
                {
                    int found=0;
                    for (int i=0;i<40;i++)
                    {
                        if(playerOne[i][0]==4 &&playerOne[i][1]==2)
                        {
                            found=1;
                            break;

                        }

                    }
                    if (found==0)
                        {
                               playerOne[index1][0]=4;
                               playerOne[index1++][1]=2;
                               playerTwo[index2][0]=-1;
                               playerTwo[index2++][1]=0;

                        }

                    redwins++;
                }


            }
            if (2<playerOne[i][0] && playerOne[i][0]<6 && 2<playerOne[i][1] && playerOne[i][1]<6 )
            {
                box4++;
                if (box4==4)
                {
                    int found=0;
                    for (int i=0;i<40;i++)
                    {
                            if(playerOne[i][0]==4 &&playerOne[i][1]==4)
                            {
                                found=1;
                                break;
                            }

                    }
                    if (found==0)
                            {
                                 playerOne[index1][0]=4;
                                 playerOne[index1++][1]=4;
                                 playerTwo[index2][0]=-1;
                                 playerTwo[index2++][1]=0;

                            }


                    redwins++;

                }


            }
            if (0<playerOne[i][0] && playerOne[i][0]<4 && 4<playerOne[i][1] && playerOne[i][1]<8 )
            {
                box5++;
                printf ("\n7asaalleet f playerone\n");
                if (box5==4)
                {
                    int found=0;
                    for (int i=0;i<40;i++)
                    {
                            if(playerOne[i][0]==2 &&playerOne[i][1]==6)
                            {
                                found=1;
                                break;
                            }

                    }
                    if (found==0)
                            {
                                 playerOne[index1][0]=2;
                                 playerOne[index1++][1]=6;
                                 playerTwo[index2][0]=-1;
                                 playerTwo[index2++][1]=0;

                            }


                    redwins++;

                }


            }
            if (0<playerOne[i][0] && playerOne[i][0]<4 && 6<playerOne[i][1] && playerOne[i][1]<10 )
            {
                box6++;
                if (box6==4)
                {
                    int found=0;
                    for (int i=0;i<40;i++)
                    {
                            if(playerOne[i][0]==2 &&playerOne[i][1]==8)
                            {
                                found=1;
                                break;
                            }

                    }
                    if (found==0)
                            {
                                 playerOne[index1][0]=2;
                                 playerOne[index1++][1]=8;
                                 playerTwo[index2][0]=-1;
                                 playerTwo[index2++][1]=0;

                            }


                    redwins++;

                }


            }
            if (2<playerOne[i][0] && playerOne[i][0]<6 && 4<playerOne[i][1] && playerOne[i][1]<8 )
            {
                box7++;
                if (box7==4)
                {
                    int found=0;
                    for (int i=0;i<40;i++)
                    {
                            if(playerOne[i][0]==4 &&playerOne[i][1]==6)
                            {
                                found=1;
                                break;
                            }

                    }
                    if (found==0)
                            {
                                 playerOne[index1][0]=4;
                                 playerOne[index1++][1]=6;
                                 playerTwo[index2][0]=-1;
                                 playerTwo[index2++][1]=0;

                            }
                    redwins++;
                }
            }
            if (2<playerOne[i][0] && playerOne[i][0]<6 && 6<playerOne[i][1] && playerOne[i][1]<10 )
            {
                box8++;
                if (box8==4)
                {
                    int found=0;
                    for (int i=0;i<40;i++)
                    {
                            if(playerOne[i][0]==4 &&playerOne[i][1]==8)
                            {
                                found=1;
                                break;
                            }

                    }
                    if (found==0)
                            {
                                 playerOne[index1][0]=4;
                                 playerOne[index1++][1]=8;
                                 playerTwo[index2][0]=-1;
                                 playerTwo[index2++][1]=0;
                            }
                    redwins++;
                }
            }
            if (4<playerOne[i][0] && playerOne[i][0]<8 && 2<playerOne[i][1] && playerOne[i][1]<6 )
            {
                box10++;
                if (box10==4)
                {
                    int found=0;
                    for (int i=0;i<40;i++)
                    {
                            if(playerOne[i][0]==6 &&playerOne[i][1]==4)
                            {
                                found=1;
                                break;
                            }

                    }
                    if (found==0)
                            {
                                 playerOne[index1][0]=6;
                                 playerOne[index1++][1]=4;
                                 playerTwo[index2][0]=-1;
                                 playerTwo[index2++][1]=0;
                            }
                    redwins++;
                }
            }
            if (4<playerOne[i][0] && playerOne[i][0]<8 && 0<playerOne[i][1] && playerOne[i][1]<4 )
            {
                box9++;
                if (box9==4)
                {
                    int found=0;
                    for (int i=0;i<40;i++)
                    {
                            if(playerOne[i][0]==6 &&playerOne[i][1]==2)
                            {
                                found=1;
                                break;
                            }

                    }
                    if (found==0)
                            {
                                 playerOne[index1][0]=6;
                                 playerOne[index1++][1]=2;
                                 playerTwo[index2][0]=-1;
                                 playerTwo[index2++][1]=0;
                            }
                    redwins++;
                }
            }
            if (6<playerOne[i][0] && playerOne[i][0]<10 && 0<playerOne[i][1] && playerOne[i][1]<4 )
            {
                box11++;
                if (box11==4)
                {
                    int found=0;
                    for (int i=0;i<40;i++)
                    {
                            if(playerOne[i][0]==8 &&playerOne[i][1]==2)
                            {
                                found=1;
                                break;
                            }
                    }
                    if (found==0)
                            {
                                 playerOne[index1][0]=8;
                                 playerOne[index1++][1]=2;
                                 playerTwo[index2][0]=-1;
                                 playerTwo[index2++][1]=0;
                            }
                    redwins++;
                }
            }
            if (6<playerOne[i][0] && playerOne[i][0]<10 && 2<playerOne[i][1] && playerOne[i][1]<6 )
            {
                box12++;
                if (box12==4)
                {
                    int found=0;
                    for (int i=0;i<40;i++)
                    {
                            if(playerOne[i][0]==8 &&playerOne[i][1]==4)
                            {
                                found=1;
                                break;
                            }
                    }
                    if (found==0)
                            {
                                 playerOne[index1][0]=8;
                                 playerOne[index1++][1]=4;
                                 playerTwo[index2][0]=-1;
                                 playerTwo[index2++][1]=0;

                            }
                    redwins++;
                }
            }
            if (4<playerOne[i][0] && playerOne[i][0]<8 && 4<playerOne[i][1] && playerOne[i][1]<8 )
            {
                box13++;
                if (box13==4)
                {
                    int found=0;
                    for (int i=0;i<40;i++)
                    {
                            if(playerOne[i][0]==6 &&playerOne[i][1]==6)
                            {
                                found=1;
                                break;
                            }

                    }
                    if (found==0)
                            {
                                 playerOne[index1][0]=6;
                                 playerOne[index1++][1]=6;
                                 playerTwo[index2][0]=-1;
                                 playerTwo[index2++][1]=0;
                            }
                    redwins++;
                }
            }
            if (4<playerOne[i][0] && playerOne[i][0]<8 && 6<playerOne[i][1] && playerOne[i][1]<10 )
            {
                box14++;
                if (box14==4)
                {
                    int found=0;
                    for (int i=0;i<40;i++)
                    {
                            if(playerOne[i][0]==6 &&playerOne[i][1]==8)
                            {
                                found=1;
                                break;
                            }

                    }
                    if (found==0)
                            {
                                 playerOne[index1][0]=6;
                                 playerOne[index1++][1]=8;
                                 playerTwo[index2][0]=-1;
                                 playerTwo[index2++][1]=0;

                            }
                    redwins++;
                }
            }
            if (6<playerOne[i][0] && playerOne[i][0]<10 && 4<playerOne[i][1] && playerOne[i][1]<8)
            {
                box15++;
                if (box15==4)
                {
                    int found=0;
                    for (int i=0;i<40;i++)
                    {
                            if(playerOne[i][0]==8 &&playerOne[i][1]==6)
                            {
                                found=1;
                                break;
                            }

                    }
                    if (found==0)
                            {
                                 playerOne[index1][0]=8;
                                 playerOne[index1++][1]=6;
                                 playerTwo[index2][0]=-1;
                                 playerTwo[index2++][1]=0;
                            }
                    redwins++;
                }
            }
            if (6<playerOne[i][0] && playerOne[i][0]<10 && 6<playerOne[i][1] && playerOne[i][1]<10 )
            {
                box16++;
                if (box16==4)
                {
                    int found=0;
                    for (int i=0;i<40;i++)
                    {
                            if(playerOne[i][0]==8 &&playerOne[i][1]==8)
                            {
                                found=1;
                                break;
                            }

                    }
                    if (found==0)
                            {
                                 playerOne[index1][0]=8;
                                 playerOne[index1++][1]=8;
                                 playerTwo[index2][0]=-1;
                                 playerTwo[index2++][1]=0;

                            }


                    redwins++;

                }

            }
        }


       if ( playerTwo[i][0]%2==0 && playerTwo[i][1]%2==0)
        {
            box1=box1;

        }
        else
        {
            if (0<playerTwo[i][0] && playerTwo[i][0]<4 && 0<playerTwo[i][1] && playerTwo[i][1]<4 )
            {
                    box1++;
                    if (box1==4)
                    {
                        int found=0;
                        for (int i=0;i<40;i++)
                        {
                            if (playerTwo[i][0]==2 &&playerTwo[i][1]==2)
                            {
                                found=1;
                                break;
                            }


                        }
                        if (found==0)
                            {
                                playerTwo[index2][0]=2;
                                playerTwo[index2++][1]=2;
                                playerOne[index1][0]=-1;
                                playerOne[index1++][1]=0;
                            }
                         bluewins++;

                    }

            }
            if (0<playerTwo[i][0] && playerTwo[i][0]<4 && 2<playerTwo[i][1] && playerTwo[i][1]<6 )
            {
                box2++;
                if (box2==4)

                {
                    int found=0;
                    for (int i=0;i<40;i++)
                    {
                        if (playerTwo[i][0]==2 &&playerTwo[i][1]==4)
                        {
                            found=1;
                            break;
                        }

                    }
                    if (found==0)
                        {
                            playerTwo[index2][0]=2;
                            playerTwo[index2++][1]=4;
                            playerOne[index1][0]=-1;
                            playerOne[index1++][1]=0;

                        }
                    bluewins++;

                }


            }
            if (2<playerTwo[i][0] && playerTwo[i][0]<6 && 0<playerTwo[i][1] && playerTwo[i][1]<4 )
            {
                box3++;
                if (box3==4)

                {
                    int found=0;
                    for (int i=0;i<40;i++)
                    {
                        if (playerTwo[i][0]==4 &&playerTwo[i][1]==2)
                        {
                            found=1;
                            break;
                        }

                    }
                    if (found==0)
                        {
                            playerTwo[index2][0]=4;
                            playerTwo[index2++][1]=2;
                            playerOne[index1][0]=-1;
                            playerOne[index1++][1]=0;

                        }

                    bluewins++;
                }


            }
            if (2<playerTwo[i][0] && playerTwo[i][0]<6 && 2<playerTwo[i][1] && playerTwo[i][1]<6 )
            {
            box4++;
            if (box4==4)

            {
                int found=0;
                for (int i=0;i<40;i++)
                {
                    if(playerTwo[i][0]==4 &&playerTwo[i][1]==4)
                    {
                        found=1;
                        break;
                    }

                }
                if (found==0)
                {
                    playerTwo[index2][0]=4;
                    playerTwo[index2++][1]=4;
                }

                bluewins++;
            }


            }
            if (0<playerTwo[i][0] && playerTwo[i][0]<4 && 4<playerTwo[i][1] && playerTwo[i][1]<8 )
            {
                box5++;
                printf ("\n7asaalleet f playertwo\n");
                if (box5==4)
                {
                    int found=0;
                    for (int i=0;i<40;i++)
                    {
                            if(playerTwo[i][0]==2 &&playerTwo[i][1]==6)
                            {
                                found=1;
                                break;
                            }

                    }
                    if (found==0)
                            {
                                 playerTwo[index1][0]=2;
                                 playerTwo[index1++][1]=6;
                                 playerOne[index2][0]=-1;
                                 playerOne[index2++][1]=0;

                            }


                    bluewins++;

                }


            }
            if (0<playerTwo[i][0] && playerTwo[i][0]<4 && 6<playerTwo[i][1] && playerTwo[i][1]<10 )
            {
                box6++;
                if (box6==4)
                {
                    int found=0;
                    for (int i=0;i<40;i++)
                    {
                            if(playerTwo[i][0]==2 &&playerTwo[i][1]==8)
                            {
                                found=1;
                                break;
                            }

                    }
                    if (found==0)
                            {
                                 playerTwo[index1][0]=2;
                                 playerTwo[index1++][1]=8;
                                 playerOne[index2][0]=-1;
                                 playerOne[index2++][1]=0;

                            }


                    redwins++;

                }


            }
            if (2<playerTwo[i][0] && playerTwo[i][0]<6 && 4<playerTwo[i][1] && playerTwo[i][1]<8 )
            {
                box7++;
                if (box7==4)
                {
                    int found=0;
                    for (int i=0;i<40;i++)
                    {
                            if(playerTwo[i][0]==4 &&playerTwo[i][1]==6)
                            {
                                found=1;
                                break;
                            }

                    }
                    if (found==0)
                            {
                                 playerTwo[index1][0]=4;
                                 playerTwo[index1++][1]=6;
                                 playerOne[index2][0]=-1;
                                 playerOne[index2++][1]=0;

                            }
                    redwins++;
                }
            }
            if (2<playerTwo[i][0] && playerTwo[i][0]<6 && 6<playerTwo[i][1] && playerTwo[i][1]<10 )
            {
                box8++;
                if (box8==4)
                {
                    int found=0;
                    for (int i=0;i<40;i++)
                    {
                            if(playerTwo[i][0]==4 &&playerTwo[i][1]==8)
                            {
                                found=1;
                                break;
                            }

                    }
                    if (found==0)
                            {
                                 playerTwo[index1][0]=4;
                                 playerTwo[index1++][1]=8;
                                 playerOne[index2][0]=-1;
                                 playerOne[index2++][1]=0;
                            }
                    redwins++;
                }
            }
            if (4<playerTwo[i][0] && playerTwo[i][0]<8 && 2<playerTwo[i][1] && playerTwo[i][1]<6 )
            {
                box10++;
                if (box10==4)
                {
                    int found=0;
                    for (int i=0;i<40;i++)
                    {
                            if(playerTwo[i][0]==6 &&playerTwo[i][1]==4)
                            {
                                found=1;
                                break;
                            }

                    }
                    if (found==0)
                            {
                                 playerTwo[index1][0]=6;
                                 playerTwo[index1++][1]=4;
                                 playerOne[index2][0]=-1;
                                 playerOne[index2++][1]=0;
                            }
                    redwins++;
                }
            }
            if (4<playerTwo[i][0] && playerTwo[i][0]<8 && 0<playerTwo[i][1] && playerTwo[i][1]<4 )
            {
                box9++;
                if (box9==4)
                {
                    int found=0;
                    for (int i=0;i<40;i++)
                    {
                            if(playerTwo[i][0]==6 &&playerTwo[i][1]==2)
                            {
                                found=1;
                                break;
                            }

                    }
                    if (found==0)
                            {
                                 playerTwo[index1][0]=6;
                                 playerTwo[index1++][1]=2;
                                 playerOne[index2][0]=-1;
                                 playerOne[index2++][1]=0;
                            }
                    redwins++;
                }
            }
            if (6<playerTwo[i][0] && playerTwo[i][0]<10 && 0<playerTwo[i][1] && playerTwo[i][1]<4 )
            {
                box11++;
                if (box11==4)
                {
                    int found=0;
                    for (int i=0;i<40;i++)
                    {
                            if(playerTwo[i][0]==8 &&playerTwo[i][1]==2)
                            {
                                found=1;
                                break;
                            }
                    }
                    if (found==0)
                            {
                                 playerTwo[index1][0]=8;
                                 playerTwo[index1++][1]=2;
                                 playerOne[index2][0]=-1;
                                 playerOne[index2++][1]=0;
                            }
                    redwins++;
                }
            }
            if (6<playerTwo[i][0] && playerTwo[i][0]<10 && 2<playerTwo[i][1] && playerTwo[i][1]<6 )
            {
                box12++;
                if (box12==4)
                {
                    int found=0;
                    for (int i=0;i<40;i++)
                    {
                            if(playerTwo[i][0]==8 &&playerTwo[i][1]==4)
                            {
                                found=1;
                                break;
                            }
                    }
                    if (found==0)
                            {
                                 playerTwo[index1][0]=8;
                                 playerTwo[index1++][1]=4;
                                 playerOne[index2][0]=-1;
                                 playerOne[index2++][1]=0;

                            }
                    redwins++;
                }
            }
            if (4<playerTwo[i][0] && playerTwo[i][0]<8 && 4<playerTwo[i][1] && playerTwo[i][1]<8 )
            {
                box13++;
                if (box13==4)
                {
                    int found=0;
                    for (int i=0;i<40;i++)
                    {
                            if(playerTwo[i][0]==6 &&playerTwo[i][1]==6)
                            {
                                found=1;
                                break;
                            }

                    }
                    if (found==0)
                            {
                                 playerTwo[index1][0]=6;
                                 playerTwo[index1++][1]=6;
                                 playerOne[index2][0]=-1;
                                 playerOne[index2++][1]=0;
                            }
                    redwins++;
                }
            }
            if (4<playerTwo[i][0] && playerTwo[i][0]<8 && 6<playerTwo[i][1] && playerTwo[i][1]<10 )
            {
                box14++;
                if (box14==4)
                {
                    int found=0;
                    for (int i=0;i<40;i++)
                    {
                            if(playerTwo[i][0]==6 &&playerTwo[i][1]==8)
                            {
                                found=1;
                                break;
                            }

                    }
                    if (found==0)
                            {
                                 playerTwo[index1][0]=6;
                                 playerTwo[index1++][1]=8;
                                 playerOne[index2][0]=-1;
                                 playerOne[index2++][1]=0;

                            }
                    redwins++;
                }
            }
            if (6<playerTwo[i][0] && playerTwo[i][0]<10 && 4<playerTwo[i][1] && playerTwo[i][1]<8)
            {
                box15++;
                if (box15==4)
                {
                    int found=0;
                    for (int i=0;i<40;i++)
                    {
                            if(playerTwo[i][0]==8 &&playerTwo[i][1]==6)
                            {
                                found=1;
                                break;
                            }

                    }
                    if (found==0)
                            {
                                 playerTwo[index1][0]=8;
                                 playerTwo[index1++][1]=6;
                                 playerOne[index2][0]=-1;
                                 playerOne[index2++][1]=0;
                            }
                    redwins++;
                }
            }
            if (6<playerTwo[i][0] && playerTwo[i][0]<10 && 6<playerTwo[i][1] && playerTwo[i][1]<10 )
            {
                box16++;
                if (box16==4)
                {
                    int found=0;
                    for (int i=0;i<40;i++)
                    {
                            if(playerTwo[i][0]==8 &&playerTwo[i][1]==8)
                            {
                                found=1;
                                break;
                            }

                    }
                    if (found==0)
                            {
                                 playerTwo[index1][0]=8;
                                 playerTwo[index1++][1]=8;
                                 playerOne[index2][0]=-1;
                                 playerOne[index2++][1]=0;

                            }


                    redwins++;

                }
            }
        }
   }


    printf("\nthe box1 are equal to %d",box1);


    printf("\nthe blue wins are equal to %d",bluewins);
    printf("\nthe red wins are equal to %d\n",redwins);
    printf("\nthe previous bluewins are equal to %d\n",previousbluewins);
    printf("\nthe  previous red wins are equal to %d\n",previousredwins);
    printf ("index1 %d index2 %d\n",index1,index2);
    printf(" bluewins %d redwins %d\n",bluewins,redwins);
    printf(" previousbluewins %d previousredwins %d\n i= %d\n",previousbluewins,previousredwins,N);
    for (int i=0;i<40;i++){
    for (int j=0;j<2;j++){
        printf("%d ",playerOne[i][j]);
    }
    printf("\n");
   }
   printf("\n");
   for (int i=0;i<40;i++){
    for (int j=0;j<2;j++){
        printf("%d ",playerTwo[i][j]);
    }
    printf("\n");
   }
   printf("%d   %d   %d   %d  %d   %d  %d  %d   %d   %d   %d  %d  %d   %d   %d   %d   ",box1,box2,box3,box4,box5,box6,box7,box8,box9,box10,box11,box12,box13,box14,box15 ,box16);
   //char shape;
   player++;

 ////////////////////////////////////////////////////timeeee

   int timehrsMinSec[3]={0,0,0};
   getTime(timeOfBeginning,timehrsMinSec);

////////GETTING WHOSE TURN IT IS

   for(int i=0;i<40;i++)
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
///////GETTING WINDIFFERENCE
    for (int i=0;i<40;i++)
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
    printf("\n\n windifference %d\n\n",windifference);
//////////////////////////////////printing of the grid
    printf("\n\n");
/////////PRINTING THE GRID
   for (int i=0;i<sizeOfGrid;i++){
        printf("\t\t\t\t\t\t   ");
    for(int j=0;j<sizeOfGrid;j++){
        int variable =0;
        if (i==0 || j==0)
        {
            printf("%c ",A[i][j]);
        }
        else{
        for (int k=0;k<40;k++)
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

   if (redwins>noOfBoxes/2)
   {
       color_str(RED,"\n\n\t\t\t\t\t",name1);color(RED,"  WINS!");
       color(CYAN,"\n\n\tenter 0,0 for undo\t1,1 for redo\t2,2 for save\t3,3 for main menu");
       winner=1;

       break;

   }
   else if(bluewins>noOfBoxes/2)
   {
       color_str(BLUE,"\n\n\t\t\t\t\t",name2);color(BLUE,"  WINS!");
       color(CYAN,"\n\n\tenter 0,0 for undo\t1,1 for redo\t2,2 for save\t3,3 for main menu");
       winner=2;

       break;
   }
   else if (redwins==noOfBoxes/2 && bluewins==noOfBoxes/2)
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
       color(CYAN,"\n\n\tenter 0,0 for undo\t 2,2 for redo\t2,2 for save\t3,3 for main menu\t1,1 for clear");
       if (redo==0)
       {
           printf("\n\n\n\n\t NO POINTS TO REDO\nenter another two points\n\n");
       }

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




   if (row==0 && col==0)
   {

       NoOfLines--;

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

               printf("\nindexxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx1 %d\n",index1);
               index1--;index2--;
               if (index1<0)
                 {index1++;
                  index2++;
                break;}
               undo1array[indexOfUndo1][0]=playerOne[index1][0];
               undo1array[indexOfUndo1][1]=playerOne[index1][1];
               undo2array[indexOfUndo1][0]=playerTwo[index1][0];
               undo2array[indexOfUndo1++][1]=playerTwo[index1][1];
               playerOne[index1][0]=-1;
               playerOne[index1][1]=-1;
               playerTwo[index1][0]=-1;
               playerTwo[index1][1]=-1;


       }
       row=-1;
       col=-1;
       undo=1;
       system("cls");



   }

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
                playerOne[index1][0]=undo1array[indexOfUndo1][0];
                playerOne[index1][1]=undo1array[indexOfUndo1][1];
                playerTwo[index1][0]=undo2array[indexOfUndo1][0];
                playerTwo[index1][1]=undo2array[indexOfUndo1][1];
                undo1array[indexOfUndo1][0]=-1;
                undo1array[indexOfUndo1][1]=-1;
                undo2array[indexOfUndo1][0]=-1;
                undo2array[indexOfUndo1][1]=-1;
                NoOfLines++;
                index1++;index2++;
                }

           }

            system("cls");
       }
   }
   else
   {
        undo=0;x=0;redo=1;
        negative_one(undo1array,20);
        negative_one(undo2array,20);

       if(row%2==0 && col%2==0 || row%2==1 && col%2==1|| row<1 || row>sizeOfGrid-1||col<1||col>sizeOfGrid-1)
   {

      // player--;
       row=-1;


   }
   else{
   for (int k=0;k<40;k++)
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
 }



