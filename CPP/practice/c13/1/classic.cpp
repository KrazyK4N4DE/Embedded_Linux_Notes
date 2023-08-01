#include "classic.h"
#include <cstring>

Cd::Cd(char *per, char *l, int n, double t)
{
        strcpy(performers, per);
        strcpy(label, l);
        selections = n;
        playtime = t;
}

Cd::Cd(const Cd &d)
{
        strcpy(performers, d.performers);
        strcpy(label, d.label);
        selections = d.selections;
        playtime = d.playtime;
}

Cd::Cd()
{
        strcpy(performers, "none");
        strcpy(label, "none");
        selections = 0;
        playtime = 0;
}

void Cd::Report() const
{
        cout << "performers: " << performers << endl;
        cout << "label: " << label << endl;
        cout << "selections: " << selections << endl;
        cout << "playtime: " << playtime << endl;
}

Cd &Cd::operator=(const Cd &d)
{
        if (this == &d)
                return *this;
        strcpy(performers, d.performers);
        strcpy(label, d.label);
        selections = d.selections;
        playtime = d.playtime;
        return *this;
}

Classic::Classic(char *per, char *l, char *mw, int n, double t) : Cd(per, l, n, t)
{
        strcpy(mainwork, mw);
}

Classic::Classic() : Cd()
{
        strcpy(mainwork, "none");
}

Classic::Classic(const Classic &c) : Cd(c)
{
        strcpy(mainwork, c.mainwork);
}

void Classic::Report() const
{
        Cd::Report();
        cout << "mainwork: " << mainwork << endl;
}

Classic &Classic::operator=(const Classic &c)
{
        if(this == &c)
                return *this;
        Cd::operator=(c);
        strcpy(mainwork, c.mainwork);
        return *this;
}