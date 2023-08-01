#ifndef __TV_H__
#define __TV_H__

using namespace std;

class Tv
{
private:
        enum {off, on}; // 电视开关状态
        enum {MinVol = 0, MaxVol = 20}; // 音量范围
        enum {MinChannel = 1, MaxChannel = 100}; // 频道范围
        enum {TV, DVD}; // 模式

        int state; // 电视开关状态
        int volume; // 音量
        int channel; // 频道
        int input;
public:
        Tv(int s = off) : state(s), volume(5), channel(2), input(TV) {}
        void onoff() {state = (state == on) ? off : on;}
        bool volup();
        bool voldown();
        void channelup();
        void channeldown();
        void set_input() {input = (input == TV) ? DVD : TV;}
        void show_settings() const;

        friend class Remote;
};

class Remote
{
private:
        int mode;
public:
        Remote(int m = Tv::TV) : mode(m) {}
        void onoff(Tv &t) {t.onoff();}
        bool volup(Tv &t) {return t.volup();}
        bool voldown(Tv &t) {return t.voldown();}
        void channelup(Tv &t) {t.channelup();}
        void channeldown(Tv &t) {t.channeldown();}
        void set_channel(Tv &t, int c) {t.channel = c;}
        void set_input(Tv &t) {t.set_input();}
};

#endif