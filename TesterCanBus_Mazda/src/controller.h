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

    int getSpeedGauge() const;
    void setSpeedGauge(const int &speed);

    int getFuelLevel() const;
    void setFuelLevel(const int &levelFuel);


signals:
    void  enableACChanged();
    void  SpeedGaugeChanged();
    void  FogLightChanged();
    void  FuelLevelChanged();

private:
    bool enableAC{};
    int SpeedGauge;
    int FuelLevel;
    void processReceivedFrames();
    void initConnection();
    std::unique_ptr<QCanBusDevice>canDevice;
    double m_numberFramesReceived;

};
}
#endif // CONTROLLER_H
