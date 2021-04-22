// fltk/calculator.cpp
#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Light_Button.H>
#include <FL/Fl_Group.H>
#include <FL/Fl_Input.H>
#include <FL/Fl_Output.H>

struct buttons {
    Fl_Button *numb[18];
};

static const char *const buttsymb[] =
{ "^", "(", ")", "+", "7", "8", "9", "-",
"4", "5", "6", "*", "1", "2", "3", "/", "0", "." };

enum {
    spacing = 3,
    buttsize = 40,
    doublebuttsize = 80,
    field_w = 160,
    quant_butt_in_str = 4
};

int main()
{
    int win_w = buttsize * 4 + spacing * 2;
    int win_h = buttsize * 8 + spacing * 4;
    Fl_Window *win = new Fl_Window(win_w, win_h, "Calculator_scelet");

    Fl_Output *res = new Fl_Output(spacing, spacing, field_w, buttsize);
    Fl_Input *inp = new Fl_Input(spacing,
                                 spacing * 2 + buttsize,
                                 field_w,
                                 buttsize);

    int butt_y = spacing * 3 + buttsize * 2;
    Fl_Button *clear = new Fl_Button(spacing,
                                     butt_y,
                                     doublebuttsize,
                                     buttsize,
                                     "C");
    Fl_Button *del = new Fl_Button(spacing + doublebuttsize,
                                   butt_y,
                                   buttsize,
                                   buttsize,
                                   "<-");
    Fl_Button *extract_root = new Fl_Button(spacing + buttsize * 3,
                                        butt_y,
                                        buttsize,
                                        buttsize,
                                        "Root");
    
    buttons *butt = new buttons;
    for (int i = 0; i < 18; i++) {
        int butt_x = spacing;
        int butt_y = spacing * 3 + buttsize * 3;
        int x_pos = i % 4;
        int y_pos = i / 4;
        butt->numb[i] = new Fl_Button(butt_x + x_pos * buttsize,
                                         butt_y + y_pos * buttsize,
                                         buttsize,
                                         buttsize,
                                         buttsymb[i]);
    };

    Fl_Button *evaluation = new Fl_Button(spacing + buttsize * 2,
                                          spacing * 3 + buttsize * 7,
                                          doublebuttsize,
                                          buttsize,
                                          "=");

    win->end();
    win->show();
    return Fl::run();
}