#include "errorrate.h"

cErrorRate::cErrorRate(QObject *parent) : QObject(parent)
{
    lostFrames = 0;
    frames = 0;
}

void cErrorRate::setItem(int time, int fr, int lFr)
{
    double rate = (lFr - lostFrames)/static_cast<double>(fr - frames);
    statRates[time] = rate;
    lostFrames = lFr;
    frames = fr;
}

double cErrorRate::getER(int curTime, int period)
{
    double result = 0;

    std::map<int, double>::iterator low, high;
    int pos = curTime - period;
    low = statRates.lower_bound(pos);
    high = statRates.upper_bound(pos);

    int timelow = low->first;
    int timehigh = high->first;
    double rate = high->second;

    result = rate;//  / (timehigh - timelow);

    return result;
}
