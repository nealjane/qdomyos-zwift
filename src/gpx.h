#ifndef GPX_H
#define GPX_H

#include <QObject>
#include <QFile>
#include <QTime>
#include <QGeoCoordinate>
#include "sessionline.h"
#include "bluetoothdevice.h"

class gpx_altitude_point_for_treadmill
{
public:
    uint32_t seconds;
    float inclination;
    float speed;
};

class gpx_point
{
public:
    QDateTime time;
    QGeoCoordinate p;
};

class gpx : public QObject
{
    Q_OBJECT
public:
    explicit gpx(QObject *parent = nullptr);
    QList<gpx_altitude_point_for_treadmill> open(QString gpx);
    static void save(QString filename, QList<SessionLine> session, bluetoothdevice::BLUETOOTH_TYPE type);

private:
    QList<gpx_point> points;

signals:

};

#endif // GPX_H
