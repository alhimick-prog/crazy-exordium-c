// fltk/calculator.cpp
#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Light_Button.H>
#include <FL/Fl_Group.H>
#include <FL/Fl_Input.H>
#include <FL/Fl_Output.H>

struct scelet {
    Fl_Output *outp;
    Fl_Input *inp;
    Fl_Button *clear;
    Fl_Button *allclear;
    Fl_Button *del;
    Fl_Button *extract_root;
    Fl_Button *numb[18];
    Fl_Button *evaluation;
};

static const char *const buttsymb[] =
{ "^", "(", ")", "+", "7", "8", "9", "-",
"4", "5", "6", "*", "1", "2", "3", "/", "0", "." };

static const char *const additsymb[] = { "C", "AC", "<-", "Root", "=" };

enum {
    spacing = 3,
    butt_h = 40,
    butt_w = 60,
    double_butt_w = 120,
    field_w = 240,
    quant_butt_in_str = 4
};

static void key_press(Fl_Widget *w, void *user)
{
    scelet *press = (scelet*)user;
    for (int i = 0; i < 18; i++) {
        if(press->numb[i] == w) {
            press->inp->insert(buttsymb[i]);
        }
    press->inp->take_focus();
    }
}

static void press_clear(Fl_Widget *w, void *user)
{
    scelet *press = (scelet*)user;
    press->inp->value("");
    press->inp->take_focus();
}

static void press_allclear(Fl_Widget *w, void *user)
{
    scelet *press = (scelet*)user;
    press->inp->value("");
    press->outp->value("");
    press->inp->take_focus();
}

static void press_delete(Fl_Widget *w, void *user)
{
    scelet *press = (scelet*)user;
    press->inp->cut(-1);
    press->inp->take_focus();
}

static void press_evaluation(Fl_Widget *w, void *user)
{
    scelet *press = (scelet*)user;
    const char *const input_string = press->inp->value();
    press->outp->value(input_string);
    press->inp->take_focus();
}

int main()
{
    int win_w = butt_w * 4 + spacing * 2;
    int win_h = butt_h * 8 + spacing * 4;
    Fl_Window *win = new Fl_Window(win_w, win_h, "Calculator_scelet");

    scelet *gov = new scelet;

    gov->outp = new Fl_Output(spacing, spacing, field_w, butt_h);
    gov->inp = new Fl_Input(spacing, spacing * 2 + butt_h, field_w, butt_h);

    int butt_y = spacing * 3 + butt_h * 2;
    gov->clear = new Fl_Button(spacing,
                               butt_y,
                               butt_w,
                               butt_h,
                               additsymb[0]);
    gov->clear->callback(press_clear, (void*)gov);
    gov->allclear = new Fl_Button(spacing + butt_w,
                                  butt_y,
                                  butt_w,
                                  butt_h,
                                  additsymb[1]);
    gov->allclear->callback(press_allclear, (void*)gov);
    gov->del = new Fl_Button(spacing + double_butt_w,
                             butt_y,
                             butt_w,
                             butt_h,
                             additsymb[2]);
    gov->del->callback(press_delete, (void*)gov);
    gov->extract_root = new Fl_Button(spacing + butt_w * 3,
                                      butt_y,
                                      butt_w,
                                      butt_h,
                                      additsymb[3]);
    
    for (int i = 0; i < 18; i++) {
        int butt_x = spacing;
        int butt_y = spacing * 3 + butt_h * 3;
        int x_pos = i % 4;
        int y_pos = i / 4;
        gov->numb[i] = new Fl_Button(butt_x + x_pos * butt_w,
                                     butt_y + y_pos * butt_h,
                                     butt_w,
                                     butt_h,
                                     buttsymb[i]);
        gov->numb[i]->callback(key_press, (void*)gov);
    };

    gov->evaluation = new Fl_Button(spacing + butt_w * 2,
                                    spacing * 3 + butt_h * 7,
                                    double_butt_w,
                                    butt_h,
                                    additsymb[4]);
    gov->evaluation->callback(press_evaluation, (void*)gov);

    gov->inp->take_focus();
    win->end();
    win->show();
    return Fl::run();
}