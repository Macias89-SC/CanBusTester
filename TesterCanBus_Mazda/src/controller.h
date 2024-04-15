#pragma once
#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QObject>
#include <QQmlEngine>
#include <QCanBusDevice>

namespace CanBusGauges{

class Controller: public QObject
{
    Q_OBJECT
    Q_PROPERTY(bool enableAC MEMBER enableAC NOTIFY enableACChanged FINAL)
    Q_PROPERTY(int SpeedGauge READ getSpeedGauge WRITE setSpeedGauge NOTIFY SpeedGaugeChanged FINAL)
    Q_PROPERTY(int FuelLevel READ getFuelLevel WRITE setFuelLevel NOTIFY FuelLevelChanged FINAL)
public:
    explicit Controller(QObject *parent = nullptr );

    int getSpeedGauge();
    void setSpeedGauge(int speed);

    int getFuelLevel();
    void setFuelLevel(int levelFuel);


signals:
    void enableACChanged(bool state);
    void  SpeedGaugeChanged(int speed);
    void  FogLightChanged(bool state);
    void  FuelLevelChanged(int levelFuel);

private:
    bool enableAC{};
    int SpeedGauge = 20;
    int FuelLevel=2;
    void processReceivedFrames();
    void initConnection();
    std::unique_ptr<QCanBusDevice>canDevice;
    double m_numberFramesReceived;

};
}
#endif // CONTROLLER_H
