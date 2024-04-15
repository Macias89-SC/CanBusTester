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
    Q_PROPERTY(uint SpeedGauge READ getSpeedGauge WRITE setSpeedGauge NOTIFY SpeedGaugeChanged FINAL)
    Q_PROPERTY(int FuelLevel READ getFuelLevel WRITE setFuelLevel NOTIFY FuelLevelChanged FINAL)
        Q_PROPERTY(int EngineTemp READ getEngineTemp WRITE setEngineTemp NOTIFY EngineTempChanged FINAL)
        Q_PROPERTY(int RPM READ getRPM WRITE setRPM NOTIFY RPMChanged FINAL)
public:
    explicit Controller(QObject *parent = nullptr );

    int getSpeedGauge() const;
    void setSpeedGauge(const uint &speed);

    int getFuelLevel() const;
    void setFuelLevel(const int &levelFuel);

    int getEngineTemp() const;
    void setEngineTemp(const int &temp);

    int getRPM() const;
    void setRPM(const int &rpm);


signals:
    void  enableACChanged();
    void  SpeedGaugeChanged();
    void  FogLightChanged();
    void  FuelLevelChanged();
    void  EngineTempChanged();
    void  RPMChanged();

private:
    bool enableAC{};
    uint SpeedGauge;
    int FuelLevel;
    int EngineTemp;
    int RPM;
    void processReceivedFrames();
    void initConnection();
    std::unique_ptr<QCanBusDevice>canDevice;
    double m_numberFramesReceived;

};
}
#endif // CONTROLLER_H
