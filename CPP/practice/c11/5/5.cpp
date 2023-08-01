#include "5.h"

Stonewt::Stonewt(double lbs)
{
        stone = (int)lbs / Lbs_per_stn;
        pds_left = (int)lbs % Lbs_per_stn + lbs - (int)lbs;
        pounds = lbs;
}

Stonewt::Stonewt(int stn, double lbs)
{
        stone = stn;
        pds_left = lbs;
        pounds = stn * Lbs_per_stn + lbs;
}

Stonewt::Stonewt()
{
        stone = pds_left = pounds = 0;
}

void Stonewt::Set_Type(Type m)
{
        type = m;
}

Stonewt Stonewt::operator+(const Stonewt &s) const
{
        return Stonewt(pounds + s.pounds);
}

Stonewt Stonewt::operator-(const Stonewt &s) const
{
        return Stonewt(pounds - s.pounds);
}

Stonewt Stonewt::operator*(double n) const
{
        return Stonewt(pounds * n);
}

ostream &operator<<(ostream &os, const Stonewt &s)
{
        if(s.type == Stonewt::STONE)
                os << s.stone << " stone, " << s.pds_left << " pounds\n";
        else if(s.type == Stonewt::POUNDS)
                os << int(s.pounds) << " pounds\n";
        else if(s.type == Stonewt::FLOAT_POUNDS)
                os << s.pounds << " pounds\n";
        else
                os << "Error type value\n";
        return os;
}