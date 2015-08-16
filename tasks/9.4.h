#ifndef TASK_9_4_H_INCLUDED
#define TASK_9_4_H_INCLUDED
namespace SALES{
    const int QUARTERS = 4;
    struct Sales{
        double sales[QUARTERS];
        double avg;
        double max;
        double min;
        };
        void setSales(Sales&, const double[], int);
        void setSales(Sales&);
        void showSales(const Sales&);
    }


#endif // TASK_9_4_H_INCLUDED
