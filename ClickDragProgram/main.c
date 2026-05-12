#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ncurses.h>

#define MIN 0
#define MAXMILLI 20000

int millisecond = MIN;

void SpawnScreen()
{
    initscr();

    if(has_colors()==FALSE)
    {
        endwin();
        printf("Your terminal does not support color\n");
        exit(1);
            
    }
    start_color();
    init_pair(1,COLOR_RED,COLOR_BLACK);

    attron(COLOR_PAIR(1));
    int length=0,width=0 , x=0 ,y =100;
    float temp;

    getyx(stdscr,y,x);
    char string[] = "Click to start...0";

    length = strlen(string);
    temp = (width-length)/2;
    x = x + temp;
    mvwprintw(stdscr,y,x,"%s",string);

    refresh();
    attroff(COLOR_PAIR(1));
    
    getch();
    endwin();
}


int main()
{
    /*
     * Todo :
     * 1) Click reaction player
     *2) DragClick simulator 
     * 
     * 1) using ncurses , spawn a screen
     * 2) screen click to start
     * 3) screen will turn white in random screen
     * 4) capture start time when white screen appears 
     * 5) player click the screen and turn back to black
     * 6) show reaction ms 
     * 7) store data into excel / text file 
     * 8) repeat until exit 
     *
     */
    SpawnScreen();
    
    
   return 0;
}
