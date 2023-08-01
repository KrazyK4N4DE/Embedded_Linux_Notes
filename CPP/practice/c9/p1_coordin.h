/*
一般在写头文件都会写#ifndef _XXX_H_ #define _XXX_H_ #endif
如果没有写这些，可能会出现重复定义的错误，因为头文件会被包含多次
*/
#ifndef __P1_COORDIN_H__ // __P1_COORDIN_H__这个可以随便写，一般用文件名大写
#define __P1_COORDIN_H__

struct polar
{
        double distance;
        double angle;
};
struct rect
{
        double x;
        double y;
};

polar rect_to_polar(rect o);
void show_polar(polar o);

#endif //要放在最后