#include <iostream>
#include "tv.h"

int main()
{
        Tv Panda;

        cout << "Initial settings for Panda TV:\n";
        Panda.show_settings();

        Panda.onoff();
        Panda.show_settings();
        cout << "-----------------------\n";

        Panda.volup();
        Panda.channelup();
        Panda.show_settings();
        cout << "-----------------------\n";

        Remote rt;
        rt.set_channel(Panda, 57);
        rt.volup(Panda);
        rt.volup(Panda);
        Panda.show_settings();

        return 0;
}