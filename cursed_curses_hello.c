/* cursed_curses_hello.c */
/* Displayed 5 lables in terminal with delay = delay_duration */
/* Library is used for compilation: -lncurses */
#include <curses.h>
#include <unistd.h>

const char message[] = "Hello!";
enum { delay_duration = 2 };

int main()
{
    int row, col;
    initscr();
    getmaxyx(stdscr, row, col);
    move(row / 4, ( (col / 2) - (sizeof(message) - 1) ) / 2);
    addstr(message);
    curs_set(0);
    refresh();
    sleep(delay_duration);
    move(row / 4, ( (col / 2) - (sizeof(message) - 1) ) / 2 + (col/2));
    addstr(message);
    curs_set(0);
    refresh();
    sleep(delay_duration);
    move(row / 2, (col - (sizeof(message) - 1) ) / 2);
    addstr(message);
    curs_set(0);
    refresh();
    sleep(delay_duration);
    move(row * 3 / 4, ( (col / 2) - (sizeof(message) - 1) ) / 2);
    addstr(message);
    curs_set(0);
    refresh();
    sleep(delay_duration);
    move(row * 3 / 4, ( (col / 2) - (sizeof(message) - 1) ) / 2 + (col/2));
    addstr(message);
    curs_set(0);
    refresh();
    sleep(delay_duration);
    endwin();
    return 0;
}
