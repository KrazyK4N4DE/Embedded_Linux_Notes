#ifndef __SALES_H__
#define __SALES_H__

#include <iostream>
#include <stdexcept>
#include <string>

using namespace std;

class Sales
{
public:
        enum {MONTHS = 12};
        explicit Sales(int yy = 0);
        Sales(int yy, const double *gr, int n);
        virtual ~Sales() {}
        int Year() const {return year;}
        virtual double operator[](int i) const;
        virtual double &operator[](int i);
        class bad_index : public logic_error
        {
        private:
                int bi;
        public:
                explicit bad_index(int ix, const string &s = "Index error in Sales object\n") : bi(ix), logic_error(s) {}
                int bi_val() const {return bi;}
                virtual ~bad_index() throw() {} // throw() 表示不抛出异常
        };
private:
        int year;
        double gross[MONTHS]; // 12个月的销售额
};

class LabelSales : public Sales
{
private:
        string label;
public:
        explicit LabelSales(const string &lb = "none", int yy = 0) : Sales(yy), label(lb) {}
        LabelSales(const string &lb, int yy, const double *gr, int n) : Sales(yy, gr, n), label(lb) {}
        virtual ~LabelSales() {}
        const string &Label() const {return label;}
        virtual double operator[](int i) const;
        virtual double &operator[](int i);
        class nbad_index : public Sales::bad_index
        {
        private:
                string lbl;
        public:
                explicit nbad_index(const string &lb, int ix, const string &s = "Index error in LabelSales object\n") : Sales::bad_index(ix, s), lbl(lb) {}
                const string &label_val() const {return lbl;}
                virtual ~nbad_index() throw() {}
        };
};

#endif