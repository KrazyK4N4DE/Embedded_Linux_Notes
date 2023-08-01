#include "classic.h"
#include <cstring>

Cd::Cd(char *per, char *l, int n, double t)
{
        performers = new char[strlen(per) + 1];
        strcpy(performers, per);
        label = new char[strlen(l) + 1];
        strcpy(label, l);
        selections = n;
        playtime = t;
}

Cd::Cd(const Cd &d)
{
        performers = new char[strlen(d.performers) + 1];
        strcpy(performers, d.performers);
        label = new char[strlen(d.label) + 1];
        strcpy(label, d.label);
        selections = d.selections;
        playtime = d.playtime;
}

Cd::Cd()
{
        performers = NULL;
        label = NULL;
        selections = 0;
        playtime = 0;
}

Cd::~Cd()
{
        delete [] performers;
        delete [] label;
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
        delete [] performers;
        performers = new char[strlen(d.performers) + 1];
        strcpy(performers, d.performers);
        delete [] label;
        label = new char[strlen(d.label) + 1];
        strcpy(label, d.label);
        selections = d.selections;
        playtime = d.playtime;
        return *this;
}

Classic::Classic(char *per, char *l, char *mw, int n, double t) : Cd(per, l, n, t)
{
        mainwork = new char[strlen(mw) + 1];
        strcpy(mainwork, mw);
}

Classic::Classic() : Cd()
{
        mainwork = NULL;
}

Classic::Classic(const Classic &c) : Cd(c)
{
        mainwork = new char[strlen(c.mainwork) + 1];
        strcpy(mainwork, c.mainwork);
}

Classic::~Classic()
{
        delete [] mainwork;
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
        delete [] mainwork;
        mainwork = new char[strlen(c.mainwork) + 1];
        strcpy(mainwork, c.mainwork);
        return *this;
}