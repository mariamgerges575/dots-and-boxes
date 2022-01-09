void menu(){
//    Read_scores();
   printing_top11_file();
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
        show_top10();
        break;
    case 3:
        pre_continue();
        break;
    case 4:
        return 0;
        break;
    default:
        menu();
        break;
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
            oneplayerName(2);
        break;
    case 3:
         if (p == 3)
            twoplayersNames(3);
        else if(p == 2)
             oneplayerName(3);
        break;
    case 4:
        return 0;
        break;
    default:
        difficulty_mode_ui(p);
    }
}

int choose_file()
{
    char s[10]; int x;
    color(PURPLE,"\n 1 for file 1 \n 2 for file 2 \n 3 for file 3");
    color(BLUE,"\n\t\t\t\t\tenter 4 for main Menu  or  5 for Exit");
    printf("\n\nenter the number");x=scan_int(s);

}
void GetNames (char p1[10],char p2[10])
{
    color(RED,"\n\n\n\n\n\n\t ENTER THE NAME OF THE FIRST PLAYER:");
    printf(RED);gets(p1);printf(RESET);
    color(BLUE,"\n\n\t ENTER THE NAME OF THE SECOND PLAYER:");
    printf(BLUE);gets(p2);printf(RESET);
    system("cls");

}
void GetName (char p1[10])
{
    color(RED,"\n\n\n\n\n\n\t ENTER THE NAME OF THE PLAYER:");
    printf(RED);gets(p1);printf(RESET);
    system("cls");
}
void oneplayerName(int x)
{
    char name[10];
    GetName(name);
    oneplayerx3(name,x,0,0);
}
void twoplayersNames(int x)
{char name1[10],name2[10];
 GetNames(name1,name2);
 twoplayers(name1,name2,x,0,0);
}
