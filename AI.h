void oneplayerx3(char name[])
 {
char undo1array[40][2];negative_one(undo1array,40);
char undo2array[40][2];negative_one(undo2array,40);
char playerOne[40][2];negative_one(playerOne,40);
char computer[40][2];negative_one(computer,40);
char A[6][6]={{32,'1','2','3','4','5'},
                  {'1',254,32,254,32,254},
                  {'2',32,32,32,32,32},
                  {'3',254,32,254,32,254},
                  {'4',32,32,32,32,32},
                  {'5',254,32,254,32,254}};
int col=-1,row=-1,player=2,index1=0,index2=0,bluewins=0,redwins=0,winner,box1=0,box2=1,box3=2,box4=3,turnsOfPlayer1=0,turnsOfPlayer2=0,NoOfLines=12,undo=0,indexOfUndo1=0,windifference=0,N=0,x=0,redo=1,timer=0;
    char box1array[4][2]={{1,2},{2,1},{2,3},{3,2}};
    char box2array[4][2]={{1,4},{2,5},{2,3},{3,4}};
    char box3array[4][2]={{5,2},{4,1},{3,2},{4,3}};
    char box4array[4][2]={{5,4},{4,5},{3,4},{4,3}};
    char boxes[4]={0,0,0,0};
    int box=-1 , i1=0,i2=0,i3=0,i4=0;
char r[10],c[10];

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
  /////initializing all values with zero
  bluewins=0;redwins=0;turnsOfPlayer1=0;turnsOfPlayer2=0;windifference=0;
  char boxes[4]={0,0,0,0};

    if (player%2==1 && row!=-1 && row!=0 && col!=0)
    {
        playerOne[index1][0]=row;
        playerOne[index1++][1]=col;
        computer[index2][0]=-1;
        computer[index2++][1]=0;

        NoOfLines--;
    }
    else if (player%2==0 && row!=-1 && row!=0 && col!=0)
    {
        computer[index2][0]=row;
        computer[index2++][1]=col;
        playerOne[index1][0]=-1;
        playerOne[index1++][1]=0;

        NoOfLines--;
    }
    //counting turns
   for (int i=0;i<20;i++)
   {
       if ( (playerOne[i][0]%2==1 && playerOne[i][1]%2==0 || playerOne[i][0]%2==0 && playerOne[i][1]%2==1)&& playerOne[i][0]!=-1)
        turnsOfPlayer1++;
       if ( (computer[i][0]%2==1 && computer[i][1]%2==0 || computer[i][0]%2==0 && computer[i][1]%2==1)&& computer[i][0]!=-1)
        turnsOfPlayer2++;

   }
   //boxes checking
   for (int i=0;i<40;i++)
   {
        if ( playerOne[i][0]%2==0 && playerOne[i][1]%2==0 )
        {
            box1=box1;
        }
        else
        {
            if (0<playerOne[i][0] && playerOne[i][0]<4 && 0<playerOne[i][1] && playerOne[i][1]<4  )
            {
                boxes[box1]++;

                if (boxes[box1]==4)
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
                            computer[index2][0]=-1;
                            computer[index2++][1]=0;

                        }
                    redwins++;
                }
            }
            if (0<playerOne[i][0] && playerOne[i][0]<4 && 2<playerOne[i][1] && playerOne[i][1]<6 )
            {
                boxes[box2]++;
                if (boxes[box2]==4)
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
                            computer[index2][0]=-1;
                            computer[index2++][1]=0;
                        }
                 redwins++;
                }
            }
             if (2<playerOne[i][0] && playerOne[i][0]<6 && 0<playerOne[i][1] && playerOne[i][1]<4 )
            {
                boxes[box3]++;
                if (boxes[box3]==4)
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
                               computer[index2][0]=-1;
                               computer[index2++][1]=0;

                        }

                    redwins++;
                }


            }
            if (2<playerOne[i][0] && playerOne[i][0]<6 && 2<playerOne[i][1] && playerOne[i][1]<6 )
            {
                boxes[box4]++;
                if (boxes[box4]==4)
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
                                 computer[index2][0]=-1;
                                 computer[index2++][1]=0;

                            }


                    redwins++;

                }


            }
        }
        if ( computer[i][0]%2==0 && computer[i][1]%2==0)
        {
            box1=box1;

        }
        else
        {
            if (0<computer[i][0] && computer[i][0]<4 && 0<computer[i][1] && computer[i][1]<4 )
            {
                    boxes[box1]++;
                    if (boxes[box1]==4)
                    {
                        int found=0;
                        for (int i=0;i<40;i++)
                        {
                            if (computer[i][0]==2 &&computer[i][1]==2)
                            {
                                found=1;
                                break;
                            }


                        }
                        if (found==0)
                            {
                                computer[index2][0]=2;
                                computer[index2++][1]=2;
                                playerOne[index1][0]=-1;
                                playerOne[index1++][1]=0;
                            }
                         bluewins++;

                    }

            }
            if (0<computer[i][0] && computer[i][0]<4 && 2<computer[i][1] && computer[i][1]<6 )
            {
                boxes[box2]++;
                if (boxes[box2]==4)

                {
                    int found=0;
                    for (int i=0;i<40;i++)
                    {
                        if (computer[i][0]==2 &&computer[i][1]==4)
                        {
                            found=1;
                            break;
                        }

                    }
                    if (found==0)
                        {
                            computer[index2][0]=2;
                            computer[index2++][1]=4;
                            playerOne[index1][0]=-1;
                            playerOne[index1++][1]=0;

                        }
                    bluewins++;

                }


            }
             if (2<computer[i][0] && computer[i][0]<6 && 0<computer[i][1] && computer[i][1]<4 )
            {
                boxes[box3]++;
                if (boxes[box3]==4)

                {
                    int found=0;
                    for (int i=0;i<40;i++)
                    {
                        if (computer[i][0]==4 &&computer[i][1]==2)
                        {
                            found=1;
                            break;
                        }

                    }
                    if (found==0)
                        {
                            computer[index2][0]=4;
                            computer[index2++][1]=2;
                            playerOne[index1][0]=-1;
                            playerOne[index1++][1]=0;

                        }

                    bluewins++;
                }


            }
            if (2<computer[i][0] && computer[i][0]<6 && 2<computer[i][1] && computer[i][1]<6 )
            {
            boxes[box4]++;
            if (boxes[box4]==4)

            {
                int found=0;
                for (int i=0;i<40;i++)
                {
                    if(computer[i][0]==4 &&computer[i][1]==4)
                    {
                        found=1;
                        break;
                    }

                }
                if (found==0)
                {
                    computer[index2][0]=4;
                    computer[index2++][1]=4;
                }

                bluewins++;
            }
            }
        }
   }


   printf("%d\t%d\t%d\t%d\t\n%d\n%d\n%d\n%d\n",i1,i2,i3,i4,boxes[0],boxes[1],boxes[2],boxes[3]);


   /*for (int i=0;i<12;i++){
    for (int j=0;j<2;j++){
        printf("%d ",playerOne[i][j]);
    }
    printf("\n");
   }
   for (int i=0;i<12;i++){
    for (int j=0;j<2;j++){
        printf("%d ",computer[i][j]);
    }
    printf("\n");
   }*/

   for (int i=0;i<40;i++){
    for (int j=0;j<2;j++){
        printf("%d ",playerOne[i][j]);
    }
    printf("\n");
   }
   printf("\n");
   for (int i=0;i<40;i++){
    for (int j=0;j<2;j++){
        printf("%d ",computer[i][j]);
    }
    printf("\n");
   }
   printf("\n\n");

////////gwtting whose turn
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
                    if (computer[i-1][0]%2==0 && computer[i-1][1]%2==0)
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
//////////getting windifference
///////GETTING WINDIFFERENCE
    for (int i=0;i<40;i++)
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
    printf("\n\n windifference %d\n\n",windifference);
    for (int i=0;i<40;i++){
    for (int j=0;j<2;j++){
        printf("%d ",playerOne[i][j]);
    }
    printf("\n");
   }
   printf("\n");
   for (int i=0;i<40;i++){
    for (int j=0;j<2;j++){
        printf("%d ",computer[i][j]);
    }
    printf("\n");
   }
    /////////PRINTING THE GRID
   for (int i=0;i<6;i++){
        printf("\t\t\t\t\t\t   ");
    for(int j=0;j<6;j++){
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
            else if (i==computer[k][0]&&j==computer[k][1])
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
   if (redwins>2)
   {
       color(RED,"\n\n\tFIRST PLAYER WINS!");
       color(CYAN,"\n\n\tenter 0,0 for undo\t1,1 for redo\t2,2 for save\t3,3 for main menu");
       winner=1;

       break;

   }
   else if(bluewins>2)
   {
       color(BLUE,"\n\n\tcomputer WINS!");
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
       color_str(RED,"\n\tfirst player's name:",name);  color_str(BLUE,"\t\t\t\t\t   second player's name:","computer");
       color_int(RED,"\n\n\tnumber of moves for first player:",turnsOfPlayer1); color_int(BLUE,"\t\t\t\t   number of moves for second player:",turnsOfPlayer2);
       color_int(RED,"\n\n\tfirst player's score:",redwins);  color_int(BLUE,"\t\t\t\t\t\t   second player's score:",bluewins);
       color_int(YELLOW,"\n\n\tnumber of remaining lines:",3);
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

        for (int i=0 ; i<4 ;i++)
            {
                if (boxes[i]==3)
                {
                    box=i;
                    break;
                }
            }

        if (box==-1)
        {
        for (int i=0 ; i<4 ;i++)
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
        for (int i=0 ; i<4 ;i++)
        {
            if (boxes[i]==1)
            {
                box=i;
                break;
            }
        }
        }


        if(box==-1)
        {for (int i=0 ; i<4 ;i++)
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
            row=box1array[i1][0];
            col=box1array[i1++][1];
            box=-1;
            break;
        case 1:
            row=box2array[i2][0];
            col=box2array[i2++][1];
            box=-1;
            break;
        case 2:
            row=box3array[i3][0];
            col=box3array[i3++][1];
            printf("\ndakhal f case 2\n");
            box=-1;
            break;
        case 3:
            row=box4array[i4][0];
            col=box4array[i4++][1];
            box=-1;
            break;

    }

    }


if (row==0 && col==0)
{
    index1--;index2--;
    int na2esWa7da=0;
    while (playerOne[index1][0]==-1 && playerOne[index1][1]==0)
    {
        if (index1<0)
        {
            index1++;index2++;
            na2esWa7da=0;
            break;
        }
        else
        {
               undo1array[indexOfUndo1][0]=-1;
               undo1array[indexOfUndo1][1]=0;
               undo2array[indexOfUndo1][0]=computer[index1][0];
               undo2array[indexOfUndo1++][1]=computer[index1][1];
               playerOne[index1][0]=-1;
               playerOne[index1][1]=-1;
               computer[index1][0]=-1;
               computer[index1][1]=-1;
               index1--;index2--;
               na2esWa7da=1;

        }

    }
    if (na2esWa7da==1)
    {
        if (index1<0)
           {
               index1++;index2++;
           }
        else
        {
            undo1array[indexOfUndo1][0]=playerOne[index1][0];
               undo1array[indexOfUndo1][1]=playerOne[index1][1];
               undo2array[indexOfUndo1][0]=computer[index1][0];
               undo2array[indexOfUndo1++][1]=computer[index1][1];
               playerOne[index1][0]=-1;
               playerOne[index1][1]=-1;
               computer[index1][0]=-1;
               computer[index1][1]=-1;

        }
    }
    row=-1;
    col=-1;
    undo=1;
    system("cls");


}
else if (row==2 && col==2)

   {
       if (undo==0)
       {
           redo=0;
          // player--;
           system("cls");
       }
       else{
       int na2esWa7da=0;
       indexOfUndo1--;
       while (undo2array[indexOfUndo1][0]==-1 && undo2array[indexOfUndo1][1]==0)
       {

                if (indexOfUndo1<0)
                {
                    redo=0;
                    undo=0;
                    na2esWa7da=0;
                    indexOfUndo1++;
                    break;
                }
                else
                {

                playerOne[index1][0]=undo1array[indexOfUndo1][0];
                playerOne[index1][1]=undo1array[indexOfUndo1][1];
                computer[index1][0]=undo2array[indexOfUndo1][0];
                computer[index1][1]=undo2array[indexOfUndo1][1];
                undo1array[indexOfUndo1][0]=-1;
                undo1array[indexOfUndo1][1]=-1;
                undo2array[indexOfUndo1][0]=-1;
                undo2array[indexOfUndo1--][1]=-1;
                NoOfLines++;
                index1++;index2++;
                na2esWa7da=1;
                }
       }
       if (na2esWa7da==1)
    {
        if (indexOfUndo1<0)
           {
               indexOfUndo1++;
           }
           else
           {
               playerOne[index1][0]=undo1array[indexOfUndo1][0];
                playerOne[index1][1]=undo1array[indexOfUndo1][1];
                computer[index1][0]=undo2array[indexOfUndo1][0];
                computer[index1][1]=undo2array[indexOfUndo1][1];
                undo1array[indexOfUndo1][0]=-1;
                undo1array[indexOfUndo1][1]=-1;
                undo2array[indexOfUndo1][0]=-1;
                undo2array[indexOfUndo1][1]=-1;
                NoOfLines++;
                index1++;index2++;
           }}

       row=-1;
       col=-1;
       system("cls");
    }


   }
else{

printf("%d",box);

   if(row%2==0 && col%2==0 || row%2==1 && col%2==1|| row<0 || row>5||col<0||col>5)
   {
       //elmafrod hena 3yzen nclear akher talat sotor lesa mesh 3arfa ezay
       printf("\33[2K\r");
       printf("\n\tinvalid numbers \n");
       player--;
       row=-1;


   }
   for (int k=0;k<40;k++)
           {
               if ( row==playerOne[k][0]&&col==playerOne[k][1] || row==computer[k][0]&&col==computer[k][1])
               {
                    printf("\33[2K\r");
                    printf("\n\tinvalid numbers \n");
                    player--;
                    row=-1;
                    break;
               }

           }



   system("cls");
   }}

 }
 }
