void oneplayerx3(char name[],int difficulty,int continuefn, int file_number)
{
//////////////////////////////initialization//////////////////////////////////////
int sizeOfGrid,noOfBoxes,turns,maxi,maxturns,maxlines,maxj,boxwin,y;
if (difficulty==2)
{
     sizeOfGrid=6;
     noOfBoxes=8;
     maxi=3;
     maxj=7;
     maxturns=24;
     maxlines=12;
}
else if (difficulty==3)
{
     sizeOfGrid=10;
     noOfBoxes=16;
     maxi=7;
     maxj=7;
     maxturns=60;
     maxlines=40;
}
int undo1array[maxturns][2];negative_one(undo1array,maxturns);
int undo2array[maxturns][2];negative_one(undo2array,maxturns);
char A[sizeOfGrid][sizeOfGrid]; initialize_grid(sizeOfGrid,A);
int col=-1,row=-1,winner,turnsOfPlayer1=0,player=2,turnsOfPlayer2=0,NoOfLines=maxlines,undo=0,indexOfUndo1=0,windifference=0,N=0,x=0,redo=1,invalid=0,no_undo=0,no_redo=0;
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
    int playerOne[maxturns][2];negative_one(playerOne,maxturns);
    int computer[maxturns][2];negative_one(computer,maxturns);
    char r[10],c[10],s[10];
    int oldTime=0; int oold[1]={0};time_t timeOfBeginning=time(0); int timer=0;
    //////////////////////////////////to continue previous game///////////////////////////////
    if(continuefn==1)
    {
        FILE *file1=fopen("file1.txt","r");FILE *file2=fopen("file2.txt","r");FILE *file3=fopen("file3.txt","r");
        opening_files(file_number,file1,file2,file3,maxturns,playerOne,computer,indwin,name,s,oold,noOfBoxes,box_index);
        close(file1);close(file2);close(file3);
        oldTime=oold[0];
    }
while(1)

{
///////print invalid message //////////////
if(invalid==1 )
{
    color(YELLOW,"Invalid Numbers");
    invalid=0;
}
if (no_undo==1 )
{
    color(YELLOW,"no possible undo");
    no_undo=0;

}
if(no_redo==1 )
{
    color(YELLOW,"no possible redo");
    no_redo=0;

}
//////////////////////////////////////////initializing all values with zero
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

    /////////////counting turns
   for (int i=0;i<maxturns;i++)
   {
       if ( (playerOne[i][0]%2==1 && playerOne[i][1]%2==0 || playerOne[i][0]%2==0 && playerOne[i][1]%2==1)&& playerOne[i][0]!=-1)
        turnsOfPlayer1++;
       if ( (computer[i][0]%2==1 && computer[i][1]%2==0 || computer[i][0]%2==0 && computer[i][1]%2==1)&& computer[i][0]!=-1)
        turnsOfPlayer2++;

   }
////////////////boxes checking//////////////

   check_boxes(playerOne,computer,noOfBoxes,boxes,maxi,maxj,indwin,maxturns);

//////////////////////////////////////////////////// time /////////////////

   int timehrsMinSec[3]={0,0,0};
   timer=getTime(timeOfBeginning,timehrsMinSec,oldTime);

////////gwtting whose turn/////////////////
     player =whose_turn(maxturns,playerOne,computer,player);



////////getting no of lines/////////////////////////////////////
if (difficulty==2)
    NoOfLines=12;
else
    NoOfLines=40;

for (int i=0;i<maxturns;i++)
{
    if (playerOne[i][0]%2==0 && playerOne[i][1]%2==1 || playerOne[i][0]%2==1 && playerOne[i][1]%2==0)

        NoOfLines--;
    if (computer[i][0]%2==0 && computer[i][1]%2==1 || computer[i][0]%2==1 && computer[i][1]%2==0)
        NoOfLines--;
}
////////////PRINTING THE GRID/////////////////////////////////////
   printing_grid(sizeOfGrid,maxturns ,playerOne,computer,A);
////////////////////////////////////chick if SOMEONE WIN/////////////////////

   if(NoOfLines==0)
   {
       if(indwin[2]>indwin[3])
        {
       color(RED,"\n\n\tFIRST PLAYER WINS!\n");
       color(RESET,"\t\t\t\tSCORE: ");color_int(RED,"",indwin[2]);color_str(RED," for ",name);color(RESET," TO ");color_int(BLUE,"",indwin[3]);color_str(BLUE," for ","computer");
       color(CYAN,"\n\n\tenter 4,4 for main menu");
       winner=1;
       save_scores(indwin[2],name);
       break;
       }
       else if(indwin[2]<indwin[3])
       {
            color(BLUE,"\n\n\tcomputer WINS!\n");
            color(RESET,"\t\t\t\t\tSCORE: ");color_int(BLUE,"",indwin[3]);color_str(BLUE," for ","computer");color(RESET," TO ");color_int(RED,"",indwin[2]);color_str(RED," for ",name);
            color(CYAN,"\n\n\tenter 4,4 for main menu");
            winner=1;
            save_scores(indwin[3],"computer");
            break;

       }
       else if(indwin[2]==indwin[3])
       {
            printf ("\n\n\t tie");
            color(CYAN,"\n\n\tenter 4,4 for main menu");
            winner=0;
            break;
       }
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
///////////////////////computer choose his row and col///////////////////
////////////////choose the best box to choose col and row form/////////////////
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
/////////////////////choose row and col from a choosen box//////////////////////////
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
////////////////////undo////////////////////////////
if (row==1 && col==1)
{   if(NoOfLines==maxlines)
    {
       printf("no possible undo");
       row=-1;
       no_undo=1;
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
                    undo_checkBoxes( maxturns, noOfBoxes,computer, indwin, box1array, box2array, box3array, box4array, box5array, box6array, box7array, box8array, box9array, box10array, box11array, box12array, box13array, box14array, box15array, box16array, box_index);
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
                    undo_checkBoxes( maxturns, noOfBoxes,computer, indwin, box1array, box2array, box3array, box4array, box5array, box6array, box7array, box8array, box9array, box10array, box11array, box12array, box13array, box14array, box15array, box16array, box_index);
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
                    undo_checkBoxes( maxturns, noOfBoxes,computer, indwin, box1array, box2array, box3array, box4array, box5array, box6array, box7array, box8array, box9array, box10array, box11array, box12array, box13array, box14array, box15array, box16array, box_index);
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
                    undo_checkBoxes( maxturns, noOfBoxes,computer, indwin, box1array, box2array, box3array, box4array, box5array, box6array, box7array, box8array, box9array, box10array, box11array, box12array, box13array, box14array, box15array, box16array, box_index);
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
//////////////////////////////////////REDO////////////////////////////////
else if (row==2 && col==2)

   {

       if (undo==0)
       {
       row=-1;
       no_redo=1;
       system("cls");
       continue;

       }
       else{
       indexOfUndo1--;
       redo=1;
       if (indexOfUndo1<0)
                {
                    redo=0;
                    undo=0;
                    indexOfUndo1=indexOfUndo1;

                }
        else
        {
            if (undo1array[indexOfUndo1-1][0]%2==0 && undo1array[indexOfUndo1-1][1]%2==0 && indexOfUndo1>0)
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
            else
            {

                while (undo2array[indexOfUndo1][0]==-1 && undo2array[indexOfUndo1][1]==0 && indexOfUndo1>0)
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
                    playerOne[indwin[0]][0]=undo1array[indexOfUndo1][0];
                    playerOne[indwin[0]][1]=undo1array[indexOfUndo1][1];
                    computer[indwin[0]][0]=undo2array[indexOfUndo1][0];
                    computer[indwin[0]][1]=undo2array[indexOfUndo1][1];
                    undo1array[indexOfUndo1][0]=-1;
                    undo1array[indexOfUndo1][1]=-1;
                    undo2array[indexOfUndo1][0]=-1;
                    undo2array[indexOfUndo1--][1]=-1;
                    indwin[0]++;indwin[1]++;
                    if (indexOfUndo1>0){
                    if(undo2array[indexOfUndo1][0]%2==0 && undo2array[indexOfUndo1][1]%2==0){
                    while (undo2array[indexOfUndo1][0]%2==0 && undo2array[indexOfUndo1][1]%2==0 && indexOfUndo1>0)
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
       row=-1;
       col=-1;
       system("cls");
       indexOfUndo1++;
   }

   }}}}
////////////////////////to save a game//////////////////
else if (row==3 && col==3)
{
    FILE *file1=fopen("file1.txt","w");FILE *file2=fopen("file2.txt","w");FILE *file3=fopen("file3.txt","w");
    y=choose_file();
    if (y==4)
    {
        system("cls");menu();
    }
    else if (y==5)
        return 0 ;
    else if(y==1 || y==2 || x==3)
    {system("cls");
    creating_files(1,difficulty,y,file1,file2,file3,maxturns,playerOne,computer,indwin,name,"computer",timer,noOfBoxes,box_index);
    fclose(file1);fclose(file2);fclose(file3);
    system("cls");
    menu();
    }
    else
    {
        row=-1;
        system("cls");
        invalid=1;
        continue;
    }

}
//////////////////to return to menu/////////////////////
else if (row==4 && col ==4)
{   system("cls");
    menu();
}
//////////////////check the validity of the col and row/////////////////////////
else{
        negative_one(undo1array,maxturns);negative_one(undo2array,maxturns);indexOfUndo1=0;

   if(row%2==0 && col%2==0 || row%2==1 && col%2==1|| row<0 || row>sizeOfGrid-1 ||col<0||col>sizeOfGrid-1 )
   {
       printf("\n\tinvalid numbers \n");
       player--;
       row=-1;
       invalid=1;

   }
////////////////////////check is row and col are choosen before/////////////////////////
   for (int k=0;k<maxturns;k++)
           {
               if ( row==playerOne[k][0]&&col==playerOne[k][1] || row==computer[k][0]&&col==computer[k][1])
               {
                    printf("\n\tinvalid numbers \n");
                    player--;
                    row=-1;
                    invalid=1;
                    break;

               }
           }
   system("cls");
   }
   }
 }
 ///////////////////////end of the game ////////////

while (1)
 {
      color(RESET,"\n\n\tENTER ROW:");
        row=scan_int(r);
        color(RESET,"\tENTER COL:");
        col=scan_int(c);
         if (row==4 && col==4)
        {
            system("cls");
            menu();
        }
        else{
            color(CYAN,"\n\n\tenter 4,4 for main menu");
            continue;
        }
 }
 }
