#include <stdio.h>
#include <ncurses.h>

int main(){
    initscr();
    
    clear();
    move(10, 20);
    addstr("Hello, world");
    move(LINES - 1, 0);
    standout();
    refresh();
    getch();
    endwin();
    return 0;
}
