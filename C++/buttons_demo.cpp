// fltk/buttons_demo.cpp
#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Button.H>

enum {
    spacing = 5,
    button_h = 40,
    button_w = 200,
    font_size_button = 20,
    heading_h = 80,
    heading_w = 400,
    font_size_heading = 30
};

static const char *msg[] = {
    "Say hello", "Say goodbye", "Quit"
};

static const char *heading_message[] = {
"Please, push the button\nand read input in terminal"
};

static void say_callback(Fl_Widget *, void *user)
{
    printf("%s\n", (const char*)user);
}

static void exit_callback(Fl_Widget *w, void *)
{
    Fl_Widget *p;
    do {
        p = w->parent();
        if(p)
            w = p;
        } while(p);
        w->hide();
};

int main(int argc, char **argv)
{
    int win_w = heading_w;
    int win_h = heading_h + button_h * 3 + spacing * 4;
    Fl_Window *win = new Fl_Window(win_w, win_h, "buttons demo");
    Fl_Box *a = new Fl_Box(0, 0, heading_w, heading_h, heading_message[0]);
    a->labelsize(font_size_heading);
    Fl_Button *b[3];
    int i;
    for(i = 0; i < 3; i++) {
        int w = (heading_w - button_w) / 2;
        int h = heading_h + spacing + button_h * i + spacing * i;
        b[i] = new Fl_Button(w, h, button_w, button_h, msg[i]);
        b[i]->labelsize(font_size_button);
    }
    win->end();
    b[0]->callback(say_callback, (void*)"Hello, world!");
    b[1]->callback(say_callback, (void*)"Goodbye, world!");
    b[2]->callback(exit_callback, 0);
    win->show();
    return Fl::run();
}
