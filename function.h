#include <bits/stdc++.h>
using namespace std;
#include <graphics.h>

//for the button and field
#include "ui.h"
#include "tree.h"

//Below are the functions that will run in the application
//function age pore likhsi bole age theke ekhane define kore disi

//easy() and easy2() are the games
//void drawwwwwwww();

void get_ans();
void ar_input();//arithmetic expression
void regex_input();

void Easy();
void Easy2();
//void loading();
void about_us();//it is the about us page
void exit();
void menu();
void info_start();
void move_start();
void Header();
void Footer();
void move_ahead();



void frame()
{
    //cleardevice() is a function of graphics which clears the screen
    cleardevice();
    //Frame Start
    setfillstyle(SOLID_FILL, DARKGRAY);
    bar(0, 0, 15, 505);//For Left Side
    bar(785, 0, 800, 505);//For Right Side
    bar(15, 0, 800, 15);//For Top Side
    bar(0, 505, 800, 520);//For Bottom Side
    setfillstyle(SOLID_FILL, LIGHTGRAY);
    bar(16, 16, 784, 504);//For Middle rectangle
    //Frame End
}

char name[200] = "";
char cpyname[200]="";
char exp1[200] = "";


vector<string> readDataFromFile(char* fileName)
{
    vector<string>words;
    FILE *file = fopen(fileName, "r");
    char c;
    string word;
    while((c = fgetc(file)) != EOF)
    {
        if(c == ' ' || c == '\n')
        {
            words.push_back(word);
            word = "";
        }
        else word.push_back(c);
    }
    fclose(file);
    return words;
}


void type_till_go(){}
//This is the game
// void type_till_go()
// {
//     cleardevice();
//     frame();
//     //for generating random time; time(0) - passing 0 for generating the current time
//     srand(time(0));

//     clock_t begin = clock();
//     double time_spent = 0.0;
//     settextstyle(4, 0, 3);//void settextstyle(int font, int direction, int font_size);


//     setcolor(WHITE);
//     rectangle(17, 150, 783, 150);//To remove bottom line of rectangular area
//     setcolor(BLACK);
//     rectangle(200, 150, 600, 150);//To print a line

//     Button back_button(15, 350, 250, 460, MAGENTA, "BACK");
//     Button re_start(501, 350, 783, 460, CYAN, "RE-START");
//     //Button next(501, 350, 783, 460, MAGENTA, "NEXT LEVEL");


//     char typed_word[50] = "";
//     int ccnt = 0, wcnt = 0;
//     bool timeOverWarning = false;
//     bool isStore = false;
//     int mx = 0;

//     Footer();

//     while(true)
//     {
//         re_start.hover(GREEN);
//         back_button.hover(GREEN);
//         //next.hover(GREEN);
//         //GetAsyncKeyState checks if the left mouse button is pressed using the GetAsyncKeyState
//         //GetAsyncKeyState is for seeing where the mouse is moving
//         //it will check whether a key is pressed or not.
//         if(GetAsyncKeyState(VK_LBUTTON) & (0x8000 != 0))
//         {
//             if(re_start.cursor())
//             {
//                 type_till_go();
//                 return;
//             }

//             else if(back_button.cursor())
//             {
//                 move_ahead();
//                 return;
//             }

//         }
//         char ch;
//         if(ch == 9)
//         {

//             outtextxy(210,210, "NOT Valid");

//             strcpy(typed_word, "");
//             settextstyle(4, 0, 3);
//             rand_word  = words[rand() % length];
//             strcpy(crand_word, rand_word.c_str());

//             new Field(16, 80, 783, 150,WHITE,BLACK,crand_word); //To print random word
//             new Field(16, 150, 783, 200,WHITE,BLACK,"");

//             setcolor(WHITE);
//             rectangle(16, 150, 783, 150);

//             setcolor(BLACK);
//             rectangle(200, 150, 600, 150);
//         }

//     }
// }


void Header()
{
    // Header Section
    setcolor(BLACK);
    //set background color
    setbkcolor(LIGHTCYAN);
    //font style
    settextstyle(GOTHIC_FONT, HORIZ_DIR, 4);
    //void outtextxy(int x, int y, char *string); displaying text at a specific position
    outtextxy(400 - textwidth("Typing Master") / 2, 58 - textheight("A") / 2, "Typing GAME");
    setlinestyle(1, 0, 1);
    //for drawing line in header
    line(16, 84.5 + textheight("A")/ 4, 784,84.5 + textheight("A")/ 4);
    setlinestyle(0, 0, 1);
    settextstyle(GOTHIC_FONT, HORIZ_DIR, 3);
}
void Footer()
{
    //Footer Section

    //void setfillstyle(int pattern, int color)
    setfillstyle(SOLID_FILL, CYAN);
    //void bar(int left, int top, int right, int bottom); drawing the bar
    bar(16, 465, 783, 504);
    settextstyle(GOTHIC_FONT, HORIZ_DIR, 1);
    setbkcolor(CYAN);
    setcolor(BLACK);
    outtextxy(400 - textwidth("Developed By Spartan")/2, 485 - textheight("A") / 2, "Developed By Spartan");
    settextstyle(GOTHIC_FONT, HORIZ_DIR, 3);
}

void info_start() {
    cleardevice();
    frame();
    Footer();

    // Creating parameterized Button objects from ui.h
    Button back(15, 425, 130, 465, BLUE, "BACK");

    // Displaying content
    settextstyle(DEFAULT_FONT, HORIZ_DIR, 2);
    setcolor(WHITE);

    outtextxy(50, 50, "Our Project Takes Arithmetic Expression and Analyzes.");
    settextstyle(DEFAULT_FONT, HORIZ_DIR, 2);

    outtextxy(50, 120, "Tokens include:");
    outtextxy(100, 150, "- Numbers (e.g., 42, 3.14)");
    outtextxy(100, 180, "- Operators (+, -, *)");
    outtextxy(100, 210, "- Parentheses (, )");
    outtextxy(100, 240, "- Identifiers (e.g., x, sum)");

    outtextxy(50, 300, "These tokens simplify expression analysis.");

    while (true) {
        back.hover(GREEN); // Highlight the "BACK" button on hover

        if (GetAsyncKeyState(VK_LBUTTON) & (0x8000 != 0)) { // Left mouse button clicked
            if (back.cursor()) {
                menu(); // Go back to the main menu
                break;
            }
        }
    }
}



void Easy()
{
    cleardevice();
    frame();

    Footer();
    new Field(0, 0, 800, 50, MAGENTA,WHITE, "Easy Labels");
    Button char_one_mnt(200, 130, 600, 230, CYAN, "Type Characters");
    //Button char_two_mnt(200, 230, 600, 330, MAGENTA, "Label 2");
    //Button char_five_mnt(200, 330, 600, 430, CYAN, "Label 3");
    Button back(15, 425, 130, 465, BLUE, "BACK");
    while(true)
    {
        char_one_mnt.hover(RED);
        //char_two_mnt.hover(BLUE);
        //char_five_mnt.hover(RED);
        back.hover(GREEN);

        if(GetAsyncKeyState(VK_LBUTTON) & (0x8000 != 0))
        {
            if(char_one_mnt.cursor())  type_till_go();
            else if(back.cursor())info_start();
        }
        if(kbhit()) getch();
    }
}
void about_us()
{
    setbkcolor(DARKGRAY);
    cleardevice();
    frame();
    Footer();
    settextstyle(6, 0, 4);
    new Field(0, 0, 800, 70, GREEN,BLACK,"About Us");
    settextstyle(8, 0, 1);
    new Field(15, 200, 785, 230, CYAN,WHITE ,"Team Members");
    new Field(15, 230, 785, 260, CYAN,WHITE ,"Team Leader: Ahanaf");
    new Field(15, 260, 785, 290, CYAN,WHITE ,"Member 1: Irtisum");
    settextstyle(8, 0, 2);
    Button back(15, 425, 130, 465, BLUE, "BACK");
    while(true)
    {
        back.hover(GREEN);

        if(GetAsyncKeyState(VK_LBUTTON) & (0x8000 != 0))
        {
            if(back.cursor())menu();
        }
        if(kbhit()) getch();
    }
}



//#######################################################################################
//#######################################################################################
//For game 2
void Easy2()
{
    //loading();
    cleardevice();
    frame();
    Footer();
    new Field(0, 0, 800, 50, MAGENTA,WHITE, "Hard Lavels");


    Button word_one_mnt(200, 130, 600, 230, CYAN, "Type Word by Word");
    //Button word_two_mnt(200, 230, 600, 330, MAGENTA, "Label 2");
    //Button word_five_mnt(200, 330, 600, 430, CYAN, "Label 3");
    Button back(15, 425, 130, 465, BLUE, "BACK");

    while(true)
    {
        word_one_mnt.hover(GREEN);
        //word_two_mnt.hover(GREEN);
        //word_five_mnt.hover(GREEN);
        back.hover(GREEN);



        if(GetAsyncKeyState(VK_LBUTTON) & (0x8000 != 0))
        {
            if(word_one_mnt.cursor())  type_till_go();
            else if(back.cursor())move_ahead();
        }
        if(kbhit()) getch();//kbhit determines if a key has been pressed or not
    }
}


void move_ahead()
{
    cleardevice();
     frame();
     Header();
     Footer();
    //creating the parameterized object from ui.h
    Button easy(200, 130, 600, 230, MAGENTA, "Check Sample: 55* ");
    //Button hard(200, 250, 600, 350, MAGENTA, "  HARD");
    Button back(15, 425, 130, 465, BLUE, "BACK");
    while(true)
    {
        easy.hover(GREEN);
        //hard.hover(GREEN);
        back.hover(GREEN);
        if(GetAsyncKeyState(VK_LBUTTON) & (0x8000 != 0))
        {
            if(easy.cursor()) Easy2();
            //else if(hard.cursor())Hard();
            else if(back.cursor())menu();
        }
    }
}

void exit()
{
    setbkcolor(BLACK);
    cleardevice();
    frame();
    Footer();
    new Field(0, 0, 800, 40, MAGENTA,WHITE, "WHAT YOU WANT TO DO");
    Button back(15, 425, 130, 465, BLUE, "BACK");
    Button exit(650, 425, 785, 465, BLUE, "EXIT");
    while(true)
    {
        back.hover(GREEN);

        if(GetAsyncKeyState(VK_LBUTTON) & (0x8000 != 0))
        {
            if(back.cursor())menu();
            else if(exit.cursor())closegraph();
        }
        if(kbhit()) getch();
    }

}
void menu()
{

    setbkcolor(CYAN);
    cleardevice();
    settextstyle(6, 0, 4);
    new Field(0, 0, 800, 70, GREEN,BLACK, "MAIN MENU");

    Footer();

    ////left,top,right,bottom

     // First row buttons for games
    //Button info(50, 90, 300, 140, MAGENTA, "Game 1");
    Button info(125, 90, 395, 150, MAGENTA, "Info + Rules");
    Button move(405, 90, 675, 150, BLUE, "Move Ahead?");
    Button game3(125, 160, 395, 220, MAGENTA, "Lexer");
    Button reginput(405, 160, 675, 220, BLUE, "Regex box");

    // sescond row buttons
    Button astatment(125, 230, 395, 290, MAGENTA, "Statement?");
    Button ptree(405, 230, 675, 290, BLUE, "Parse Tree");
    Button aboutMe(125, 300, 675, 360, MAGENTA, "About Us");

    Button ext(125, 370, 675, 430, RED, "Exit");

    while(true)
    {
        //hovering over menu
        info.hover(GREEN);
        move.hover(GREEN);
        game3.hover(GREEN);
        reginput.hover(GREEN);
        astatment.hover(GREEN);
        aboutMe.hover(GREEN);
        ptree.hover(GREEN);
        //newsfeed.hover(GREEN);
        ext.hover(GREEN);

        //pressing the windows
        if(GetAsyncKeyState(VK_LBUTTON) & (0x8000 != 0))
        {
            if(info.cursor()) info_start();
            else if(move.cursor())move_ahead();
            else if(reginput.cursor()) regex_input();
            else if(astatment.cursor()) ar_input();
            else if(ptree.cursor()) {drawwwwwwww();}
            else if(aboutMe.cursor()) about_us();
           else if(ext.cursor()) exit();
        }
    }
}


void login()
{

    setbkcolor(LIGHTCYAN);
    cleardevice();

    settextstyle(6, 0, 4);
    new Field(0,0,800,80,BLACK,WHITE,"WELCOME TO Lexer ");//left,top,right,bottom
    settextstyle(8, 0, 2);//void settextstyle(int font, int direction, int font_size);
    new Field(100, 350, 350, 400, GREEN,WHITE, "ENTER YOUR NAME");//left,top,right,bottom
    Input userName;//creating input object from the ui.h
    userName.Name(350, 350,700, 400);//left,top,right,bottom
    Button submit(370,430,450,480, BLUE, "OK");

    while(true)
    {
        int tr=0;
        submit.hover(GREEN);
        if(GetAsyncKeyState(VK_LBUTTON) & (0x8000 != 0))
        {
            if(userName.cursor()){ userName.getName(name); tr=1; }
            else if(submit.cursor())
            {
                if(strlen(name)>0){
                    //name[0]
                    menu();
                }
            }

        }
    }

}


//---------------------------------------------------------------------------------------------------------------------------
//---------------------------------------------------------------------------------------------------------------------------
//---------------------------------------------------------------------------------------------------------------------------
//addition

//#############################################################################################
//Arithmetic input
bool isOperator(char ch) {
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/');
}


void ar_input() {
    setbkcolor(DARKGRAY);
   // setbkcolor(LIGHTCYAN);
    cleardevice();
    //Footer();
    settextstyle(8, 0, 2);
    new Field(100, 350, 350, 400, GREEN,WHITE, "ENTER Expression");
    //Button back(15, 525, 130, 565, BLUE, "Exit");
    Input exp;
    exp.Name(350, 350,700, 400);
    Button submit(370,430,450,480, BLUE, "OK");
    Button back(15, 425, 130, 480, BLUE, "BACK");

    while(true) {
        submit.hover(GREEN);
        if(GetAsyncKeyState(VK_LBUTTON) & (0x8000 != 0)) {
            if(exp.cursor()){ exp.getName(exp1); }
            else if(submit.cursor()) {
                // evaluate exprresion
                bool ok = 0;
                int nn = strlen(exp1);
                if( nn == 1) ok = 1;
                for(int i=1;i<nn;i++){
                    if(i&1 && !isOperator(exp1[i])){
                        ok = 1;
                        break;
                    }
                    if(!(i&1) && isOperator(exp1[i])){
                        ok = 1;
                        break;
                    }
                }
                // ok = 1 = invalid ,
                if(ok) outtextxy(100, 200, "Invalid Expression");
                else outtextxy(100, 200, "   Valid Expression  ");

            }
            else if(back.cursor()) {
                menu();
            }
        }
    }
}







///////regex box 




//#############################################################################################
//Regex input

void regex_input() {
    setbkcolor(DARKGRAY);
   // setbkcolor(LIGHTCYAN);
    cleardevice();
    //Footer();
    settextstyle(8, 0, 2);
    outtextxy(100,100, "The Follow Up expression: 55*");

    new Field(100, 350, 350, 400, GREEN,WHITE, "ENTER Numbers");
    //Button back(15, 525, 130, 565, BLUE, "Exit");
    Input exp;
    exp.Name(350, 350,700, 400);
    Button submit(370,430,450,480, BLUE, "OK");
    Button back(15, 425, 130, 480, BLUE, "BACK");

    while(true) {
        submit.hover(GREEN);
        if(GetAsyncKeyState(VK_LBUTTON) & (0x8000 != 0)) {
            if(exp.cursor()){ exp.getName(exp1); }
            else if(submit.cursor()) {
                // evaluate exprresion
                bool ok = 0;
                int nn = strlen(exp1);
                if( nn == 1) ok = 1;
                for(int i=1;i<nn;i++){
                    if(exp1[i]!='5'){
                        ok = 1;
                        break;
                    }
                }
                // ok = 1 = invalid ,
                if(ok) outtextxy(100, 200, "Invalid Expression");
                else outtextxy(100, 200, "   Valid Expression  ");
            }
            else if(back.cursor()) {
                menu();
            }
        }
    }
}






////sample
// void leaderboard()
// {
//     setbkcolor(DARKGRAY);
//     cleardevice();
//     //frame();
//     Footer();
//     // settextstyle(6, 0, 4);
//     // new Field(0, 0, 800, 70, GREEN,BLACK,"Leaderboard");
//     // settextstyle(8, 0, 1);


//     // settextstyle(8, 0, 2);
//     Button back(15, 425, 130, 465, BLUE, "BACK");
//     while(true)
//     {
//         back.hover(GREEN);

//         if(GetAsyncKeyState(VK_LBUTTON) & (0x8000 != 0))
//         {
//             if(back.cursor())menu();
//         }
//         if(kbhit()) getch();
//     }
// }
