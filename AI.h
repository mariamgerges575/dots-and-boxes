void oneplayerx3()
 {
char playerOne[12][2]; negative_one(playerOne,12);
char computer[12][2]; negative_one(computer,12);
char A[6][10]={{32,'1','2','3','4','5'},
                  {'1',254,32,254,32,254},
                  {'2',32,32,32,32,32},
                  {'3',254,32,254,32,254},
                  {'4',32,32,32,32,32},
                  {'5',254,32,254,32,254}};
int col=-1,row=-1,player=2,index1=0,index2=0,bluewins=0,redwins=0,winner;
    char box1[4][2]={{1,2},{2,1},{3,2},{2,3}};
    char box2[4][2]={{1,4},{2,5},{2,3},{3,4}};
    char box3[4][2]={{5,2},{4,1},{3,4},{3,2}};
    char box4[4][2]={{5,4},{4,5},{3,4},{4,3}};
    char boxes[4]={0,0,0,0};
    int box=-1 , i1=0,i2=0,i3=0,i4=0,ohh=0;
char r[10],c[10];

while(1)

  {

    if (player%2==1 && row!=-1)
    {
        playerOne[index1][0]=row;
        playerOne[index1++][1]=col;
    }
    else if (player%2==0 && row!=-1)
    {
        computer[index2][0]=row;
        computer[index2++][1]=col;
    }

   //boxes checking
    if (0<row && row<4 && 0<col && col<4 )
    {
        boxes[0]++;
    }

    if (0<row && row<4 && 2<col && col<6 )
    {
        boxes[1]++;
    }

    if (2<row && row<6 && 0<col && col<4 )
    {
       boxes[2]++;
    }

    if (2<row && row<6 && 2<col && col<6 )
    {
       boxes[3]++;
    }
    if (boxes[0]==4 || boxes[1]==4 || boxes[2]==4 || boxes[3]==4)
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
               computer[index2][0]=2;
               computer[index2++][1]=2;
               bluewins++;
            }
            boxes[0]=-2;
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
               computer[index2][0]=2;
               computer[index2++][1]=4;
               bluewins++;
            }
            boxes[1]=-2;
        }
        if (boxes[2]==4)
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
               computer[index2][0]=4;
               computer[index2++][1]=2;
               bluewins++;
            }
            boxes[2]=-2;
        }
        if (boxes[3]==4)
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
                computer[index2][0]=4;
                computer[index2++][1]=4;
                bluewins++;
            }
            boxes[3]=-2;
        }

        player++;
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
            else if (i==computer[k][0]&&j==computer[k][1])
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
       color_str(RED,"\n\tfirst player's name:","name");  color_str(BLUE,"\t\t\t\t\t   second player's name:","computer");
       color_int(RED,"\n\n\tnumber of moves for first player:",5); color_int(BLUE,"\t\t\t\t   number of moves for second player:",5);
       color_int(RED,"\n\n\tfirst player's score:",5);  color_int(BLUE,"\t\t\t\t\t\t   second player's score:",5);
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
                    ohh=1;
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

    /*while (ohh==1){
        printf("%d",box);
    }*/
    switch(box)
    {
        case 0:
            row=box1[i1][0];
            col=box1[i1++][1];
            box=-1;
            break;
        case 1:
            row=box2[i2][0];
            col=box2[i2++][1];
            box=-1;
            break;
        case 2:
            row=box3[i3][0];
            col=box3[i3++][1];
            box=-1;
            break;
        case 3:
            row=box4[i4][0];
            col=box4[i4++][1];
            box=-1;
            break;

    }

    }




printf("%d",box);

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
   }

 }
 }
