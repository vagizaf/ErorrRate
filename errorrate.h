#ifndef CERRORRATE_H
#define CERRORRATE_H

#include <QObject>
#include <map>

class cErrorRate : public QObject
{
    Q_OBJECT

    int frames;
    int lostFrames;
    std::map<int,double> statRates;

public:
    explicit cErrorRate(QObject *parent = nullptr);
    void clear();
    void setItem(int time, int frames, int lostFrames);
    double getER(int curTime, int period);

signals:

public slots:
};

#endif // CERRORRATE_H
