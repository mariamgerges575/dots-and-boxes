
void menu(){
   printf("\n\n\t\t\t\t\t\t  DOTS AND BOXES");
   color(PURPLE,"\n\n\n\t\t0:NEW GAME\n\n");
   color(PURPLE,"\t\t1:Top Ten\n\n");
   color(PURPLE,"\t\t2:Continue\n\n");
   color(PURPLE,"\t\t3:EXIT\n\n\n\n");
   printf("\t\t4:enter your choice\n\n\n\n");
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

void twoplayersx3(){
 while(1){
   char A[6][10]={{' ','1',' ','2',' ','3',' ','4',' ','5'},{'1',254,' ',' ',' ',254,' ',' ',' ',254}
   ,{'2',186,' ',' ',' ',' ',' ',' ',' ',' '},{'3',254,' ',' ',' ',254,' ',' ',' ',254}
   ,{'4',' ',' ',' ',' ',' ',' ',' ',' ',' '},{'5',254,' ',' ',' ',254,' ',' ',' ',254}};
   printf("\n\n");
   for (int i=0;i<6;i++){
        printf("\t\t\t\t\t\t   ");
    for(int j=0;j<10;j++){
        if(i==2 && j==1){
        color_char(RED,186);
        }
        else{
        printf("%c",A[i][j]);
        }
    }
    printf("\n");
   }

   color_str(RED,"\n\tfirst player's name:","name");  color_str(BLUE,"\t\t\t\t\t   second player's name:","name");
   color_int(RED,"\n\n\tnumber of moves for first player:",5); color_int(BLUE,"\t\t\t\t   number of moves for second player:",5);
   color_int(RED,"\n\n\tfirst player's score:",5);  color_int(BLUE,"\t\t\t\t\t\t   second player's score:",5);
   color_int(YELLOW,"\n\n\tnumber of remaining lines:",3);
   color(CYAN,"\n\n\tenter 0,0 for undo\t1,1 for redo\t2,2 for save\t3,3 for main menu");
   int col,row;
   color(RED,"\n\n\tENTER ROW:");
   printf(RED); scanf("%d",&col); printf(RESET);
   color(RED,"\tENTER COL:");
   printf(RED); scanf("%d",&row); printf(RESET);
   system("cls");
 }
}
