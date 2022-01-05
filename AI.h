void oneplayerx3(char name[],int difficulty,int continuefn)
{
int sizeOfGrid,noOfBoxes,turns,maxi,maxturns,maxlines,maxj,boxwin;
if (difficulty==2)
{
     sizeOfGrid=6;
     noOfBoxes=8;
     maxi=3;
     maxj=7;
     maxturns=24;
     maxlines=12;
     boxwin=2;

}
else if (difficulty==3)
{
     sizeOfGrid=10;
     noOfBoxes=16;
     maxi=7;
     maxj=7;
     maxturns=60;
     maxlines=40;
     boxwin=8;
}
int undo1array[maxturns][2];negative_one(undo1array,maxturns);
int undo2array[maxturns][2];negative_one(undo2array,maxturns);
char A[sizeOfGrid][sizeOfGrid]; initialize_grid(sizeOfGrid,A);
int col=-1,row=-1,winner,turnsOfPlayer1=0,player=2,turnsOfPlayer2=0,NoOfLines=maxlines,undo=0,indexOfUndo1=0,windifference=0,N=0,x=0,redo=1,timer=0;
    int box1array[4][2]={{1,2},{2,1},{2,3},{3,2}};
    int box2array[4][2]={{1,4},{2,5},{2,3},{3,4}};
    int box3array[4][2]={{1,6},{2,5},{2,7},{3,6}};
    int box4array[4][2]={{1,8},{2,9},{2,7},{3,8}};
    int box5array[4][2]={{4,1},{5,2},{3,2},{4,3}};
    int box6array[4][2]={{5,4},{4,5},{3,4},{4,3}};
    int box7array[4][2]={{5,6},{4,5},{4,7},{3,6}};
    int box8array[4][2]={{4,9},{4,7},{3,8},{5,8}};
    int box9array[4][2]={{6,1},{6,3},{5,2},{7,2}};
    int box10array[4][2]={{5,4},{6,3},{6,5},{7,4}};
    int box11array[4][2]={{6,5},{5,6},{6,7},{7,6}};
    int box12array[4][2]={{6,9},{5,8},{7,8},{6,7}};
    int box13array[4][2]={{8,1},{9,2},{7,2},{8,3}};
    int box14array[4][2]={{9,4},{8,3},{7,4},{8,5}};
    int box15array[4][2]={{9,6},{8,5},{8,7},{7,6}};
    int box16array[4][2]={{9,8},{8,9},{8,7},{7,8}};
    int boxes[noOfBoxes]; zeros(noOfBoxes,boxes);
    int box_index[noOfBoxes]; zeros(noOfBoxes,box_index); int indwin[4]; zeros(4,indwin);
    int box=-1 ;
    int playerOne[maxturns][2];int computer[maxturns][2];
   /* if(continuefn==1)
    {
        FILE *file=open("file.txt","r");
        continue_fn(file,maxturns,playerOne,computer);
        close(file);
    }
    else{*/
        negative_one(playerOne,maxturns);
        negative_one(computer,maxturns);

    time_t timeOfBeginning=time(0);
    char r[10],c[10];
while(1)

  {

////////initializing all values with zero
  indwin[3]=0;indwin[2]=0,turnsOfPlayer1=0;turnsOfPlayer2=0;windifference=0;
  int boxes[noOfBoxes]; zeros(noOfBoxes,boxes);
  if (difficulty==2)
  {
      boxes[2]=-6 ; boxes[3]=-6; boxes[6]=-6 ;boxes[7]=-6;
  }
    if (player%2==1 && row!=-1 && row!=0 && col!=0)
    {
        playerOne[indwin[0]][0]=row;
        playerOne[indwin[0]++][1]=col;
        computer[indwin[1]][0]=-1;
        computer[indwin[1]++][1]=0;
        NoOfLines--;

    }
    else if (player%2==0 && row!=-1 && row!=0 && col!=0)
    {
        computer[indwin[1]][0]=row;
        computer[indwin[1]++][1]=col;
        playerOne[indwin[0]][0]=-1;
        playerOne[indwin[0]++][1]=0;
        NoOfLines--;
    }
    //counting turns
   for (int i=0;i<maxturns;i++)
   {
       if ( (playerOne[i][0]%2==1 && playerOne[i][1]%2==0 || playerOne[i][0]%2==0 && playerOne[i][1]%2==1)&& playerOne[i][0]!=-1)
        turnsOfPlayer1++;
       if ( (computer[i][0]%2==1 && computer[i][1]%2==0 || computer[i][0]%2==0 && computer[i][1]%2==1)&& computer[i][0]!=-1)
        turnsOfPlayer2++;

   };
////////////////boxes checking//////////////

   check_boxes(playerOne,computer,noOfBoxes,boxes,maxi,maxj,indwin,maxturns);
for(int i=0;i<noOfBoxes;i++)
{
    printf("%d\t%d\n",boxes[i],box_index[i]);
}
////////////////////////////////////////////////////timeeee

   int timehrsMinSec[3]={0,0,0};
   getTime(timeOfBeginning,timehrsMinSec);

////////gwtting whose turn/////////////////
     player =whose_turn(maxturns,playerOne,computer,player);

//////////getting windifference
///////GETTING WINDIFFERENCE
    for (int i=0;i<maxturns;i++)
    {
        if (playerOne[i][0]==-1 && playerOne[i][1]==-1)
        {
            if (playerOne[i-1][0]%2==0 && playerOne[i-1][1]%2==0 && computer[i-1][0]==-1 && computer[i-1][1]%2==0)
            {
                windifference++;
                if (playerOne[i-2][0]%2==0 && playerOne[i-2][1]%2==0 && computer[i-2][0]==-1 && computer[i-2][1]%2==0)
                {
                    windifference++;
                }
            }
        }
        if (computer[i][0]==-1 && computer[i][1]==-1)
        {
            if (computer[i-1][0]%2==0 && computer[i-1][1]%2==0 && computer[i-1][0]==-1 && computer[i-1][1]%2==0)
            {
                windifference++;
                if (computer[i-2][0]%2==0 && computer[i-2][1]%2==0 && playerOne[i-2][0]==-1 && playerOne[i-2][1]%2==0)
                {
                    windifference++;
                }
            }
        }
    }

////////////PRINTING THE GRID
   printing_grid(sizeOfGrid,maxturns ,playerOne,computer,A);
///////////////////////////////////////////
   if (indwin[2]>boxwin)
   {
       color(RED,"\n\n\tFIRST PLAYER WINS!");
       color(CYAN,"\n\n\tenter 4,4 for main menu");
       winner=1;

       break;

   }
   else if(indwin[3]>boxwin)
   {
       color(BLUE,"\n\n\tcomputer WINS!");
       color(CYAN,"\n\n\tenter 4,4 for main menu");
       winner=2;

       break;
   }
   else if (indwin[2]==boxwin && indwin[3]==boxwin)
   {
       printf ("\n\n\t tie");
       color(CYAN,"\n\n\tenter 3,3 for main menu");
       winner=0;

       break;
   }
   else
   {
       color_str(RED,"\n\tfirst player's name:",name);  color_str(BLUE,"\t\t\t\t\t   second player's name:","computer");
       color_int(RED,"\n\n\tnumber of moves for first player:",turnsOfPlayer1); color_int(BLUE,"\t\t\t\t   number of moves for second player:",turnsOfPlayer2);
       color_int(RED,"\n\n\tfirst player's score:",indwin[2]);  color_int(BLUE,"\t\t\t\t\t\t   second player's score:",indwin[3]);
       color_int(YELLOW,"\n\n\tnumber of remaining lines:",NoOfLines);color_int(YELLOW,"\t\t\t\t\t   TIME: ",timehrsMinSec[0]);color_int(YELLOW,":",timehrsMinSec[1]);color_int(YELLOW,":",timehrsMinSec[2]);
       color(CYAN,"\n\n\tenter 1,1 for undo\t2,2 for redo\t3,3 for save\t4,4 for main menu");

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

        for (int i=0 ; i<noOfBoxes ;i++)
            {
                if (boxes[i]==3)
                {
                    box=i;
                    break;
                }
            }

        if (box==-1)
        {
        for (int i=0 ; i<noOfBoxes ;i++)
        {
            if (boxes[i]==0)
            {
                box=i;
                break;
            }
        }
        }

        if(box==-1)
        {
        for (int i=0 ; i<noOfBoxes ;i++)
        {
            if (boxes[i]==1)
            {
                box=i;
                break;
            }
        }
        }


        if(box==-1)
        {for (int i=0 ; i<noOfBoxes ;i++)
        {
            if (boxes[i]==2)
            {
            box=i;
            break;
            }
        }
        }

    switch(box)
    {
        case 0:
            row=box1array[box_index[0]][0];
            col=box1array[box_index[0]++][1];
            box=-1;
            break;
        case 1:
            row=box2array[box_index[1]][0];
            col=box2array[box_index[1]++][1];
            box=-1;
            break;
        case 2:
                row=box3array[box_index[2]][0];
                col=box3array[box_index[2]++][1];
            box=-1;
            break;
        case 3:
                row=box4array[box_index[3]][0];
                col=box4array[box_index[3]++][1];
            box=-1;
            break;
        case 4:
               row=box5array[box_index[4]][0];
               col=box5array[box_index[4]++][1];
            box=-1;
            break;
        case 5:
               row=box6array[box_index[5]][0];
               col=box6array[box_index[5]++][1];
            box=-1;
            break;
        case 6:
            row=box7array[box_index[6]][0];
            col=box7array[box_index[6]++][1];
            box=-1;
            break;
        case 7:
            row=box8array[box_index[7]][0];
            col=box8array[box_index[7]++][1];
            box=-1;
            break;
        case 8:
            row=box9array[box_index[8]][0];
            col=box9array[box_index[8]++][1];
            box=-1;
            break;
        case 9:
            row=box10array[box_index[9]][0];
            col=box10array[box_index[9]++][1];
            box=-1;
            break;
        case 10:
            row=box11array[box_index[10]][0];
            col=box11array[box_index[10]++][1];
            box=-1;
            break;
        case 11:
            row=box12array[box_index[11]][0];
            col=box12array[box_index[11]++][1];
            box=-1;
            break;
        case 12:
            row=box13array[box_index[12]][0];
            col=box13array[box_index[12]++][1];
            box=-1;
            break;
        case 13:
            row=box14array[box_index[13]][0];
            col=box14array[box_index[13]++][1];
            box=-1;
            break;
        case 14:
            row=box15array[box_index[14]][0];
            col=box15array[box_index[14]++][1];
            box=-1;
            break;
        case 15:
            row=box16array[box_index[15]][0];
            col=box16array[box_index[15]++][1];
            box=-1;
            break;

    }

    }
////////////////////
if (row==1 && col==1)
{   if(NoOfLines==maxlines)
    {
       printf("no possible undo");
       row=-1;
       system("cls");
    }
    else{
        NoOfLines+=2;
        indwin[0]--;indwin[1]--;
        int na2esWa7da=0;

        if (playerOne[indwin[0]][0]%2==0 && playerOne[indwin[0]][1]%2==0)
        {
            while (playerOne[indwin[0]][0]%2==0 && playerOne[indwin[0]][1]%2==0)
            {
                if (indwin[0]<0)
                {

                    na2esWa7da=0;
                    break;
                }
                else
                {
                    undo1array[indexOfUndo1][0]=playerOne[indwin[0]][0];
                    undo1array[indexOfUndo1][1]=playerOne[indwin[0]][1];
                    undo2array[indexOfUndo1][0]=computer[indwin[0]][0];
                    undo2array[indexOfUndo1++][1]=computer[indwin[0]][1];
                    na2esWa7da=1;
                    playerOne[indwin[0]][0]=-1;
                    playerOne[indwin[0]][1]=-1;
                    computer[indwin[0]][0]=-1;
                    computer[indwin[0]][1]=-1;
                    indwin[0]--;indwin[1]--;
                }
            }
            if (na2esWa7da==1)
            {
                if (indwin[0]<0)
                {
                    indwin[0]=indwin[0];
                }
                else
                {
                    undo1array[indexOfUndo1][0]=playerOne[indwin[0]][0];
                    undo1array[indexOfUndo1][1]=playerOne[indwin[0]][1];
                    undo2array[indexOfUndo1][0]=computer[indwin[0]][0];
                    undo2array[indexOfUndo1++][1]=computer[indwin[0]][1];
                    playerOne[indwin[0]][0]=-1;
                    playerOne[indwin[0]][1]=-1;
                    computer[indwin[0]][0]=-1;
                    computer[indwin[0]][1]=-1;
                    indwin[0]--;indwin[1]--;

                }
            }

      }
      else{
            while (playerOne[indwin[0]][0]==-1 && playerOne[indwin[0]][1]==0)
            {
                if (indwin[0]<0)
                {

                    na2esWa7da=0;
                    break;
                }
                else
                {
                    undo1array[indexOfUndo1][0]=playerOne[indwin[0]][0];
                    undo1array[indexOfUndo1][1]=playerOne[indwin[0]][1];
                    undo2array[indexOfUndo1][0]=computer[indwin[0]][0];
                    undo2array[indexOfUndo1++][1]=computer[indwin[0]][1];
                    playerOne[indwin[0]][0]=-1;
                    playerOne[indwin[0]][1]=-1;
                    computer[indwin[0]][0]=-1;
                    computer[indwin[0]][1]=-1;
                    indwin[0]--;indwin[1]--;
                    na2esWa7da=1;

                }

            }
            if (na2esWa7da==1)
            {
                if (indwin[0]<0)
                {
                    indwin[0]=indwin[0];
                }
                else
                {
                    undo1array[indexOfUndo1][0]=playerOne[indwin[0]][0];
                    undo1array[indexOfUndo1][1]=playerOne[indwin[0]][1];
                    undo2array[indexOfUndo1][0]=computer[indwin[0]][0];
                    undo2array[indexOfUndo1++][1]=computer[indwin[0]][1];
                    playerOne[indwin[0]][0]=-1;
                    playerOne[indwin[0]][1]=-1;
                    computer[indwin[0]][0]=-1;
                    computer[indwin[0]][1]=-1;
                    indwin[0]--;indwin[1]--;

                }
          }
    }
    row=-1;
    col=-1;
    undo=1;
    system("cls");
    indwin[0]++;indwin[1]++;


    }

}
///////REDO//////////
else if (row==2 && col==2)

   {

       if (undo==0)
       {
       system("cls");

       row=-1;
       continue;

       }
       else{
       NoOfLines-=2;
       int na2esWa7da=0;
       indexOfUndo1--;
       redo=1;
       if (undo1array[indexOfUndo1][0]%2==0 && undo1array[indexOfUndo1][1]%2==0)
       {
           while (undo1array[indexOfUndo1][0]%2==0 && undo1array[indexOfUndo1][1]%2==0)
           {
               if (indexOfUndo1<0)
                {
                    redo=0;
                    undo=0;
                    na2esWa7da=0;
                    indexOfUndo1=indexOfUndo1;
                    break;
                }
                else
                {

                playerOne[indwin[0]][0]=undo1array[indexOfUndo1][0];
                playerOne[indwin[0]][1]=undo1array[indexOfUndo1][1];
                computer[indwin[0]][0]=undo2array[indexOfUndo1][0];
                computer[indwin[0]][1]=undo2array[indexOfUndo1][1];
                undo1array[indexOfUndo1][0]=-1;
                undo1array[indexOfUndo1][1]=-1;
                undo2array[indexOfUndo1][0]=-1;
                undo2array[indexOfUndo1--][1]=-1;
                indwin[0]++;indwin[1]++;
                na2esWa7da=1;
                }
           }}

        if (indexOfUndo1<0)
           {
            indexOfUndo1=indexOfUndo1;
           }
           else
           {
               playerOne[indwin[0]][0]=undo1array[indexOfUndo1][0];
                playerOne[indwin[0]][1]=undo1array[indexOfUndo1][1];
                computer[indwin[0]][0]=undo2array[indexOfUndo1][0];
                computer[indwin[0]][1]=undo2array[indexOfUndo1][1];
                undo1array[indexOfUndo1][0]=-1;
                undo1array[indexOfUndo1][1]=-1;
                undo2array[indexOfUndo1][0]=-1;
                undo2array[indexOfUndo1--][1]=-1;
                indwin[0]++;indwin[1]++;
                 if (undo1array[indexOfUndo1][0]%2==0 && undo1array[indexOfUndo1][1]%2==0)
       {
           while (undo1array[indexOfUndo1][0]%2==0 && undo1array[indexOfUndo1][1]%2==0)
           {
               if (indexOfUndo1<0)
                {
                    redo=0;
                    undo=0;
                    na2esWa7da=0;
                    indexOfUndo1=indexOfUndo1;
                    break;
                }
                else
                {playerOne[indwin[0]][0]=undo1array[indexOfUndo1][0];
                playerOne[indwin[0]][1]=undo1array[indexOfUndo1][1];
                computer[indwin[0]][0]=undo2array[indexOfUndo1][0];
                computer[indwin[0]][1]=undo2array[indexOfUndo1][1];
                undo1array[indexOfUndo1][0]=-1;
                undo1array[indexOfUndo1][1]=-1;
                undo2array[indexOfUndo1][0]=-1;
                undo2array[indexOfUndo1--][1]=-1;
                indwin[0]++;indwin[1]++;
                na2esWa7da=1;
                }
           }
           if (indexOfUndo1<0)
           {
               indexOfUndo1=indexOfUndo1;
           }
           else
           {
               playerOne[indwin[0]][0]=undo1array[indexOfUndo1][0];
                playerOne[indwin[0]][1]=undo1array[indexOfUndo1][1];
                computer[indwin[0]][0]=undo2array[indexOfUndo1][0];
                computer[indwin[0]][1]=undo2array[indexOfUndo1][1];
                undo1array[indexOfUndo1][0]=-1;
                undo1array[indexOfUndo1][1]=-1;
                undo2array[indexOfUndo1][0]=-1;
                undo2array[indexOfUndo1--][1]=-1;
                indwin[0]++;indwin[1]++;}
           }
       while (undo1array[indexOfUndo1][0]==-1 && undo1array[indexOfUndo1][1]==0)
       {
           if (indexOfUndo1<0)
           {
               indexOfUndo1=indexOfUndo1;
           }
           else
            {
                playerOne[indwin[0]][0]=undo1array[indexOfUndo1][0];
                playerOne[indwin[0]][1]=undo1array[indexOfUndo1][1];
                computer[indwin[0]][0]=undo2array[indexOfUndo1][0];
                computer[indwin[0]][1]=undo2array[indexOfUndo1][1];
                undo1array[indexOfUndo1][0]=-1;
                undo1array[indexOfUndo1][1]=-1;
                undo2array[indexOfUndo1][0]=-1;
                undo2array[indexOfUndo1--][1]=-1;
                indwin[0]++;indwin[1]++;
            }
       }

    }

    row=-1;
       col=-1;
       system("cls");
       indexOfUndo1++;
   }

   }
else if (row==3 && col==3)
{
    //FILE *file;
    //save(file,maxturns,playerOne,computer);
    //system("cls");
    menu();

}
else if (row==4 && col ==4)
{   system("cls");
    menu();
}
else{
printf("%d",box);

   if(row%2==0 && col%2==0 || row%2==1 && col%2==1|| row<0 || row>sizeOfGrid-1 ||col<0||col>sizeOfGrid-1 )
   {
       //elmafrod hena 3yzen nclear akher talat sotor lesa mesh 3arfa ezay
       printf("\n\tinvalid numbers \n");
       player--;
       row=-1;
   }
   for (int k=0;k<maxturns;k++)
           {
               if ( row==playerOne[k][0]&&col==playerOne[k][1] || row==computer[k][0]&&col==computer[k][1])
               {
                    printf("\n\tinvalid numbers \n");
                    player--;
                    row=-1;
                    break;
               }
           }
   system("cls");
   }}
 }
            printf("\n\n\t>>>>first player\'s turn:\n");
            color(RED,"\n\n\tENTER ROW:");
            printf(RED); row=scan_int(r); printf(RESET);
            color(RED,"\tENTER COL:");
            printf(RED); col=scan_int(c); printf(RESET);
            if (row==4 && col ==4)
            {   system("cls");
                menu();
            }
 }
