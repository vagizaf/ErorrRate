#include "errorrate.h"

cErrorRate::cErrorRate(QObject *parent) : QObject(parent)
{
    lostFrames = 0;
    frames = 0;
}


void cErrorRate::clear()
{
    statRates.clear();
}

/*
 * Добавление данных о текущем количестве переданных
 *  и потерянных кадров с указанием
 * текущего времени в секундах
 *
 * * Ожидается, что время и количество фрэймов с каждым вызовом функции
 *  только увеличиватеся
 */
void cErrorRate::setItem(int time, int fr, int lFr)
{
    //расчёт rate в текущей отметке времени (метка)
    double rate = (lFr - lostFrames)/static_cast<double>(fr - frames);

    //запись метки в контейнер
    statRates[time] = rate;

    //запомнить для расчёта следующей метки
    lostFrames = lFr;
    frames = fr;
}

/*
 *   Текущее значение error rate для текущего времени в секундах с указанием
 *    продолжительности временного окна в секундах
 */
double cErrorRate::getER(int curTime, int period)
{
    double result = 0;

    std::map<int, double>::iterator begin, end;
    int start = curTime - period;

    // поиск первой отметки времени в периоде
    begin = statRates.upper_bound(start);

    //поиск последней отметки времени в заданном периоде
    end = statRates.upper_bound(curTime);
    --end;

    //расчёт вклада в ER от "неполной" метки
    result += begin->second * (begin->first - start);

    //время прошлой метки
    int lastTime = begin->first;

    //суммирование всех последующих rates с учётом интервала времени
    for(auto it = ++begin; it != statRates.end(); lastTime = it->first, ++it)
    {
        result += (it->second * (it->first - lastTime));
    }

    //вычисление ER (усреднение) - деление на суммарное время по меткам
    return result/(end->first - start);
}
