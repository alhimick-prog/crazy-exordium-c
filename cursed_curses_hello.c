/* curses_hello.c */
#include <curses.h>
#include <unistd.h>

const char message[] = "Hell!!!";
enum { delay_duration = 3 };

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
