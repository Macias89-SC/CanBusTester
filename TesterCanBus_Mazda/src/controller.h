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
    Q_PROPERTY(quint8 SpeedGauge READ getSpeedGauge WRITE setSpeedGauge NOTIFY SpeedGaugeChanged FINAL)
    Q_PROPERTY(quint8 FuelLevel READ getFuelLevel WRITE setFuelLevel NOTIFY FuelLevelChanged FINAL)
    Q_PROPERTY(quint8 EngineTemp READ getEngineTemp WRITE setEngineTemp NOTIFY EngineTempChanged FINAL)
    Q_PROPERTY(quint8 RPM READ getRPM WRITE setRPM NOTIFY RPMChanged FINAL)
    Q_PROPERTY(QString SpeedText READ getSpeedText WRITE setSpeedText NOTIFY SpeedTextChanged FINAL)
    Q_PROPERTY(bool  Charging READ getCharging WRITE setCharging NOTIFY ChargingChanged FINAL)
    Q_PROPERTY(bool CheckEngine READ getCheckEngine WRITE setCheckEngine NOTIFY CheckEngineChanged FINAL);
public:
    explicit Controller(QObject *parent = nullptr );

    bool getCheckEngine() const;
    void setCheckEngine(const bool &engine);

    bool getCharging() const;
    void setCharging(const bool &charge);

    quint8 getSpeedGauge() const;
    void setSpeedGauge(const quint8 &speed);

    quint8 getFuelLevel() const;
    void setFuelLevel(const quint8 &levelFuel);

    quint8 getEngineTemp() const;
    void setEngineTemp(const quint8 &temp);

    quint8 getRPM() const;
    void setRPM(const quint8 &rpm);

    QString getSpeedText() const;
    void setSpeedText(const QString &speedText);


signals:
    void  CheckEngineChanged();
    void  ChargingChanged();
    void  SpeedGaugeChanged();
    void  FogLightChanged();
    void  FuelLevelChanged();
    void  EngineTempChanged();
    void  RPMChanged();
    void  SpeedTextChanged();

private:
    bool  CheckEngine = false;
    bool  Charging = false;
    quint8 SpeedGauge=0;
    quint8 FuelLevel=0;
    quint8 EngineTemp=0;
    quint8 RPM=0;
    QString SpeedText="0";
    void processReceivedFrames();
    void initConnection();
    std::unique_ptr<QCanBusDevice>canDevice;
    double m_numberFramesReceived;

};
}
#endif // CONTROLLER_H
