int choose_file()
{
    char s[10]; int x;
    color(PURPLE,"\n 1 for file 1 \n 2 for file 2 \n 3 for file 3");    printf("\nenter the number");x=scan_int(s);
    return x;

}
void creating_files(int oneOrtwo,int difficulty,int x,FILE *file1,FILE *file2,FILE *file3,int maxturns,int player1[maxturns][2],int player2[maxturns][2],int indwin[4],char name1[10],char name2[10],long int oldTime)
{
    switch(x)
    {
       case 1:
           save(oneOrtwo,difficulty,file1,maxturns,player1,player2,indwin,name1,name2,oldTime);
           break;
       case 2:
           save(oneOrtwo,difficulty,file2,maxturns,player1,player2,indwin,name1,name2,oldTime);
           break;
        case 3:
           save(oneOrtwo,difficulty,file3,maxturns,player1,player2,indwin,name1,name2,oldTime);
           break;
    }
}
void save (int oneOrtwo,int difficulty,FILE *file,int maxturns,int player1[maxturns][2],int player2[maxturns][2],int indwin[4],char name1[10],char name2[10],long int oldTime)
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
    fprintf(file ,"%s ",name1);
    fprintf(file ,"%s ",name2);
    fprintf(file ,"%ld ",oldTime);
}

void opening_files(int x,FILE *file1,FILE *file2,FILE *file3,int maxturns,int player1[maxturns][2],int player2[maxturns][2],int indwin[4],char name1[10],char name2[10],long int oldTime)
{
    switch(x)
    {
       case 1:
           continue_fn(file1,maxturns,player1,player2,indwin,name1,name2,oldTime);
           break;
       case 2:
           continue_fn(file2,maxturns,player1,player2,indwin,name1,name2,oldTime);
           break;
        case 3:
           continue_fn(file3,maxturns,player1,player2,indwin,name1,name2,oldTime);
           break;
    }
}
void continue_fn(FILE *file,int maxturns,int player1[maxturns][2],int player2[maxturns][2],int indwin[4],char name1[10],char name2[10],long int oldTime)
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
    fscanf(file ,"%s ",name1);
    fscanf(file ,"%s ",name2);
    fscanf(file ,"%ld ",&oldTime);

}
void pre_continue()
{
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
    }
    fclose(file1);fclose(file2);fclose(file3);
    if (oneOrtwo==1 && difficulty==2)
    {
        oneplayerx3(" ",2,1,y);
    }
    else if(oneOrtwo==1 && difficulty==3)
    {
        oneplayerx3(" ",3,1,y);
    }
    else if(oneOrtwo==2 && difficulty==2)
    {
        twoplayers(" "," ",2,1,y);
    }
     else if(oneOrtwo==2 && difficulty==3)
    {
        twoplayers(" "," ",3,1,y);
    }
}
struct leaderboard
{
    char name[10];
    int score;

}ranks[11]={{" ",0},{" ",0},{" ",0},{" ",0},{" ",0},{" ",0},{" ",0},{" ",0},{" ",0},{" ",0},{" ",0}};
/*void initializing_structs()
{
    for(int i=0;i<11;i++)
    {
        ranks[i].name=" ";
        ranks[i].score=0;
    }
}*/

void save_scores(int score,char name[10])
{
    for (int i=0;i<10;i++)
    {
        if (score>ranks[0].score)
        {
            for (int j=10;j>i;j--)
            {
                ranks[j]=ranks[j-1];

            }

        }
    }
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
    /*scorespreadsheet=fopen("scorespreadsheet.txt","r");
    fscanf(scorespreadsheet,"%d ",&ranks[1].score);
    fscanf(scorespreadsheet,"%s ",ranks[1].name);
    printf("\n %d",ranks[1].score);
    printf("\n %s",ranks[1].name);*/
}
void reading_structs_at_beginning ()
{
    scorespreadsheet=fopen("scorespreadsheet.txt","r");
    for (int i=0;i<10;i++)
    {
        fscanf(scorespreadsheet,"%d ",&ranks[1].score);
        fscanf(scorespreadsheet,"%s ",ranks[1].name);
    }
}
/*void save_scores (int score,char name[10])
{
    s++;
    FILE *scorespreadsheet=fopen("scorespreadsheet.txt","a");
    fprintf(scorespreadsheet,"%d ",score);
    fprintf(scorespreadsheet,"%s ",name);
    fclose(scorespreadsheet);
}*/
/*void Read_scores()
{
    for (int i=0;i<s;i++)
    {
        FILE *scorespreadsheet=fopen("scorespreadsheet.txt","a");
        fscanf(scorespreadsheet,"%d ",&ranks[i].score);
        fscanf(scorespreadsheet,"%s ",ranks[i].name);

    }
}*/

