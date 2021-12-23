
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
    return ;
}

void difficulty_mode_ui()
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
    return;
}

void threex3(){
 while(1){
   char A[6][10]={{' ',49,' ',50,' ',51,' ',52,' ',53},{49,254,'=','=','=',254,' ',' ',' ',254}
   ,{50,186,' ',' ',' ',' ',' ',' ',' ',' '},{51,254,' ',' ',' ',254,' ',' ',' ',254}
   ,{52,' ',' ',' ',' ',' ',' ',' ',' ',' '},{53,254,' ',' ',' ',254,' ',' ',' ',254}};
   printf("\n\n");
   for (int i=0;i<6;i++){
        printf("\t\t\t\t\t\t   ");
    for(int j=0;j<10;j++){
        //if(i==2 && j==1){
        //color_char(RED,186);
        //}
        //else{
        printf("%c",A[i][j]);
        //}
    }
    printf("\n");
   }

   color_str(RED,"\n\tfirst player's name:","name");  color_str(BLUE,"\t\t\t\t\t   second player's name:","name");
   color_int(RED,"\n\n\tnumber of moves for first player:",5); color_int(BLUE,"\t\t\t\t   number of moves for second player:",5);
   color_int(RED,"\n\n\tfirst player's score:",5);  color_int(BLUE,"\t\t\t\t\t   secound player's score:",5);
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
