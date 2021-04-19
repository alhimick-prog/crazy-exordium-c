// fltk/radiobuttons_v2.cpp
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
    spacing = 3,
    butt_w = 150,
    butt_h = 40,
    opt_w = 120,
    str_h = 20,
    letter_size = 90,
    opt_b_h = 140,
    opt_l_h = 160,

};

int main()
{
    int win_w = butt_w * 2 + spacing * 3;
    int win_h = opt_b_h + opt_l_h + butt_h + spacing * 4;
    Fl_Window *win = new Fl_Window(win_w, win_h, "radiobuttons_v2");
    controls *ctrl = new controls;
    int c_x_opt_b = spacing;
    int c_y_opt_b = spacing;
    Fl_Group *back = new Fl_Group(c_x_opt_b, c_y_opt_b, opt_w, opt_b_h, "");
    new Fl_Box(c_x_opt_b, c_y_opt_b, opt_w, str_h, "Background color:");
    int i;
    for(i = 0; i < 5; i++) {
        int high_value = c_y_opt_b + str_h * (i + 1) + spacing * (i + 1);
        ctrl->rb_background[i] = new Fl_Radio_Round_Button(
            c_x_opt_b, high_value, opt_w, str_h, colnames[i]);
    }
    back->end();
    int c_x_opt_l = spacing;
    int c_y_opt_l = spacing * 2 + opt_b_h;
    Fl_Group *lett = new Fl_Group(c_x_opt_l, c_y_opt_l, opt_w, opt_l_h, "");
    new Fl_Box(c_x_opt_l, c_y_opt_l, opt_w, str_h, "Letter settings:");
    for(i = 0; i < 5; i++) {
        int high_value = c_y_opt_l + str_h * (i + 1) + spacing * (i + 1);
        ctrl->rb_letter[i] = new Fl_Radio_Round_Button(
            c_x_opt_l, high_value, opt_w, str_h, colnames[i]);
    }
    int cb_c_x = c_x_opt_l;
    int cb_c_y = c_y_opt_l + str_h * 6 + spacing * 6;
    ctrl->cb = new Fl_Check_Button(cb_c_x, cb_c_y, opt_w, str_h,
                                    "show letter");
    lett->end();


    win->end();
    win->show();
    return Fl::run();
};
