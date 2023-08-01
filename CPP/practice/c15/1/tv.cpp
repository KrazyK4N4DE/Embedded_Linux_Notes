/*
互为友元类
*/
#include <iostream>
#include "tv.h"

bool Tv::volup()
{
        if (volume < MaxVol)
        {
                volume++;
                return true;
        }
        else
                return false;
}

bool Tv::voldown()
{
        if (volume > MinVol)
        {
                volume--;
                return true;
        }
        else
                return false;
}

void Tv::channelup()
{
        if (channel < MaxChannel)
                channel++;
        else
                channel = MinChannel;
}

void Tv::channeldown()
{
        if (channel > MinChannel)
                channel--;
        else
                channel = MaxChannel;
}

void Tv::show_settings() const
{
        cout << "Tv is: " << ((state == on) ? "on" : "off") << endl;
        if (state == on)
        {
                cout << "Volume: " << volume << endl;
                cout << "Channel: " << channel << endl;
                cout << "Mode: " << ((input == TV) ? "TV" : "DVD") << endl;
        }
}

void Tv::set_remote_mode(Remote &r)
{
        if(state == on)
                r.set_remote_mode();
}