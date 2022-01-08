
void creating_files(int oneOrtwo,int difficulty,int x,FILE *file1,FILE *file2,FILE *file3,int maxturns,int player1[maxturns][2],int player2[maxturns][2],int indwin[4],char name1[10],char name2[10],long int oldTime,int noOfboxes,int box_index[noOfboxes])
{
    switch(x)
    {
       case 1:
           save(oneOrtwo,difficulty,file1,maxturns,player1,player2,indwin,name1,name2,oldTime,noOfboxes,box_index);
           break;
       case 2:
           save(oneOrtwo,difficulty,file2,maxturns,player1,player2,indwin,name1,name2,oldTime,noOfboxes,box_index);
           break;
        case 3:
           save(oneOrtwo,difficulty,file3,maxturns,player1,player2,indwin,name1,name2,oldTime,noOfboxes,box_index);
           break;
    }
}
void save (int oneOrtwo,int difficulty,FILE *file,int maxturns,int player1[maxturns][2],int player2[maxturns][2],int indwin[4],char name1[10],char name2[10],long int oldTime,int noOfboxes,int box_index[noOfboxes])
{
    fprintf(file ,"%d ",oneOrtwo);
    fprintf(file ,"%d ",difficulty);
    for(int i=0;i<maxturns;i++)
    {
        fprintf(file ,"%d %d ",player1[i][0],player1[i][1]);
    }
    for(int i=0;i<maxturns;i++)
    {
        fprintf(file ,"%d %d ",player2[i][0],player2[i][1]);
    }
    for(int i=0;i<4;i++)
    {
         fprintf(file ,"%d ",indwin[i]);
    }
    for(int i=0 ;i<noOfboxes;i++)
    {
        fprintf(file ,"%d ",box_index[i]);
    }
    fprintf(file ,"%ld ",oldTime);
    fprintf(file ,"%s ",name1);
    fprintf(file ,"%s ",name2);

}

void opening_files(int x,FILE *file1,FILE *file2,FILE *file3,int maxturns,int player1[maxturns][2],int player2[maxturns][2],int indwin[4],char name1[10],char name2[10],long int oldTime[1],int noOfboxes,int box_index[noOfboxes])
{
    switch(x)
    {
       case 1:
           continue_fn(file1,maxturns,player1,player2,indwin,name1,name2,oldTime,noOfboxes,box_index);
           break;
       case 2:
           continue_fn(file2,maxturns,player1,player2,indwin,name1,name2,oldTime,noOfboxes,box_index);
           break;
        case 3:
           continue_fn(file3,maxturns,player1,player2,indwin,name1,name2,oldTime,noOfboxes,box_index);
           break;
    }
}
void continue_fn(FILE *file,int maxturns,int player1[maxturns][2],int player2[maxturns][2],int indwin[4],char name1[10],char name2[10],long int oldTime[1],int noOfboxes,int box_index[noOfboxes])
{   int x,y;
    fscanf(file ,"%d ",&x);
    fscanf(file ,"%d ",&y);
    for(int i=0;i<maxturns;i++)
    {
        fscanf(file ,"%d %d ",&player1[i][0],&player1[i][1]);
    }
    for(int i=0;i<maxturns;i++)
    {
        fscanf(file ,"%d %d ",&player2[i][0],&player2[i][1]);
    }
    for(int i=0;i<4;i++)
    {
         fscanf(file ,"%d ",&indwin[i]);
    }
    for(int i=0 ;i<noOfboxes;i++)
    {
        fscanf (file ,"%d ",&box_index[i]);
    }
    fscanf(file ,"%ld ",&oldTime[0]);
    fscanf(file ,"%s ",name1);
    fscanf(file ,"%s ",name2);
}
void pre_continue()
{   char name[10],name1[10],name2[10];

    int y=choose_file(); int oneOrtwo ,difficulty;
    FILE *file1=fopen("file1.txt","r");FILE *file2=fopen("file2.txt","r");FILE *file3=fopen("file3.txt","r");
    switch (y)
    {
      case 1 :
        fscanf(file1,"%d %d ",&oneOrtwo,&difficulty);
        break;
      case 2 :
        fscanf(file2,"%d %d ",&oneOrtwo,&difficulty);
        break;
      case 3 :
        fscanf(file3,"%d %d ",&oneOrtwo,&difficulty);
        break;
      case 4:
          system("cls");menu();
      case 5:
        return 0;
      default:
        pre_continue();

    }
    fclose(file1);fclose(file2);fclose(file3);
    if (oneOrtwo==1 && difficulty==2)
    {
        oneplayerx3(name,2,1,y);
    }
    else if(oneOrtwo==1 && difficulty==3)
    {
        oneplayerx3(name,3,1,y);
    }
    else if(oneOrtwo==2 && difficulty==2)
    {
        twoplayers(name1,name2,2,1,y);
    }
     else if(oneOrtwo==2 && difficulty==3)
    {
        twoplayers(name1,name2,3,1,y);
    }
}


struct leaderboard
{
    char name[6];
    int score;

}ranks[11];

void save_scores(int score,char name[6])
{
    for (int i=0;i<10;i++)
    {
        if (score>ranks[i].score)
        {

            for (int j=10;j>i;j--)
            {

                ranks[j] = ranks[j-1];



            }
            ranks[i].score=score;
            for (int k=0;k<6;k++)
                {
                    ranks[i].name[k]=name[k];
                }
            break;

        }
    }
   /* for (int i=0;i<10;i++)
    {
        printf("\n rank[%d].score %d",i,ranks[i].score);
        printf("\n rank[%d].name %s",i,ranks[i].name);
    }*/

    printing_top11_file();

}
void printing_top11_file()
{
    FILE *scorespreadsheet=fopen("scorespreadsheet.txt","w");
    for (int i=0;i<11;i++)
    {
        fprintf(scorespreadsheet,"%d ",ranks[i].score);
        fprintf(scorespreadsheet,"%s ",ranks[i].name);
    }
    fclose(scorespreadsheet);
}
void reading_structs_at_beginning ()
{
    FILE *scorespreadsheet=fopen("scorespreadsheet.txt","r");
    for (int i=0;i<10;i++)
    {
        fscanf(scorespreadsheet,"%d ",&ranks[i].score);
        fscanf(scorespreadsheet,"%s ",ranks[i].name);
    }
}
void show_top10()
{
    printf("\n\t\t\t\t\t TOP TEN");
    for (int i=0;i<10;i++)
    {
        printf("\n\tname: %s\t\t score:%d",ranks[i].name,ranks[i].score);
    }
    color(PURPLE,"\n\n\n\t\t enter any no to return to main menu\n\n");
    char s [10];int x;
    x=scan_int(s);
   system("cls");
    switch(x)
    {
     case 1:
        menu();
        break;
     default:
        menu();}

}
