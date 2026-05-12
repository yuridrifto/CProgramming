/* Terminal UI ( ncruses )
 Reel Feed Controller
 HTTP/API Layer (libcurl)
 JSON Parse (cJson/jansson)
 Video Playback (mpv/ffmpeg)
Terminal opens
↓
Fetch Instagram Reel
↓
Download or stream video
↓
Render/play inside terminal
↓
User presses keys to navigate
↓
Next reel play*/

#include <stdio.h>
#include <ncurses.h>

void testNcurses()
{
    initscr();
    printw("Hello World !");
    refresh();
    getch();
    endwin();
}       

int main ()
{
    testNcurses();
    return 0;
}
