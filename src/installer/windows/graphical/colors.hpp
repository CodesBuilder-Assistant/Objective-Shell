#ifndef SEASON_HPP
#define SEASON_HPP
#include <Windows.h>
class color_scheme
{
    private:
        COLORREF background;
        COLORREF text;
    public:
        color_scheme(void)
        {
        }
        color_scheme(COLORREF background,COLORREF text)
        {
            this->background=background;
            this->text=text;
        }
        void set(COLORREF background,COLORREF text)
        {
            this->background=background;
            this->text=text;
        }
        color_scheme operator =(const COLORREF background_and_text[])
        {
            color_scheme tmp;
            tmp.background=background_and_text[0];
            tmp.text=background_and_text[1];
            return tmp;
        }
        COLORREF background(void)
        {
            return this->background;
        }
        COLORREF text(void)
        {
            return this->text;
        }
};

const color_scheme season_colors[]={{RGB(0,255,127),RGB(0,185,57)},{RGB(50,200,50),RGB(34,139,34)},{RGB(255,215,0),RGB(255,165,0)},{RGB(30,144,255),RGB(70,130,180)}};
const color_scheme standard_color_schemes[]={{RGB(133,114,248),RGB(106,90,205)},{RGB(100,149,237),RGB(65,105,225)}};
#endif