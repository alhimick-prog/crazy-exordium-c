// fltk/radiobuttons.cpp
#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Light_Button.H>
#include <FL/Fl_Round_Button.H>
#include <FL/Fl_Radio_Round_Button.H>
#include <FL/Fl_Check_Button.H>
#include <FL/Fl_Group.H>

struct controls {
    Fl_Radio_Round_Button *rb_background[5];
    Fl_Check_Button *cb;
    Fl_Radio_Round_Button *rb_letter[5];
    Fl_Box *box;
};

static const int colors[] = { FL_RED, FL_GREEN, FL_BLUE, FL_WHITE,
    FL_BLACK };
static const char *const colnames[] = { "red", "green", "blue", "white",
    "black" };

static void set_callback(Fl_Widget *w, void *user)
{
    controls *c = (controls*)user;
    int i;
    for(i = 0; i < 5; i++) {
        if(c->rb_background[i]->value()) {
            c->box->color(colors[i]);
            break;
        }
    }
    for(i = 0; i < 5; i++) {
        if(c->rb_letter[i]->value()) {
            c->box->labelcolor(colors[i]);
            break;
        }
    }
    c->box->label(c->cb->value() ? "F" : "");
};

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

enum {
    spacing = 2,
    button_w = 150,
    button_h = 40,
    option_w = 120,
    string_h = 20,
    option_background_h = 132 ,
    option_letter_h = 156,
    letter_size = 90
};

int main()
{
    int win_w = button_w * 2 + spacing * 3;
    int win_h = option_background_h + option_letter_h + button_h
                + spacing * 10;
    Fl_Window *win = new Fl_Window(win_w, win_h, "radiobuttons");
    controls *ctrl = new controls;
    Fl_Group *back = new Fl_Group(0, 0, option_w,
                     option_background_h, "");
    new Fl_Box(spacing, spacing, option_w, button_h,
              "Background color:");
    int i;
    for(i = 0; i < 5; i++) {
        int high_value = string_h + spacing * 2 + spacing * i;
        ctrl->rb_background[i] = new Fl_Radio_Round_Button(spacing,
                        high_value, option_w, string_h, colnames[i]);
    }
    back->end();
    int letter_high = option_background_h + spacing;
    Fl_Group *letter = new Fl_Group(0, letter_high, option_w,
                       option_letter_h, "");
    new Fl_Box(spacing, spacing, option_w, option_letter_h,
               "Letter color:");
    for(i = 0; i < 5; i++) {
        int high_value = string_h + spacing * 2 * spacing * i;
        ctrl->rb_letter[i] = new Fl_Radio_Round_Button(spacing,
                        high_value, option_w, string_h, colnames[i]);
    }
    letter->end();
    int box_x = option_w + spacing * 2;
    int box_w = button_w * 2 - option_w;
    int box_h = option_background_h + option_letter_h;
    ctrl->box = new Fl_Box(box_x, spacing, box_w, box_h);
    ctrl->box->labelsize(letter_size);
    ctrl->box->box(FL_FLAT_BOX);
    int buttons_y = option_background_h + option_letter_h + spacing;
    Fl_Button *set_b = new Fl_Button(spacing, buttons_y, button_w,
                                button_h, "Set!");
    set_b->callback(set_callback, (void*)ctrl);

    Fl_Button *close_b = new Fl_Button(spacing * 2 + button_w, buttons_y,
                                button_w, button_h, "Quit");
    close_b->callback(exit_callback, 0);
    win->end();
    win->show();
    return Fl::run();
};
