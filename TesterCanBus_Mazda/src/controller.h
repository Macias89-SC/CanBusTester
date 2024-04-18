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
    Q_PROPERTY(bool  AbsActive READ getAbsActive WRITE setAbsActive NOTIFY AbsActiveChanged FINAL)
    Q_PROPERTY(bool  CruiseControlActive READ getCruiseControlActive WRITE setCruiseControlActive NOTIFY CruiseControlActiveChanged FINAL)
    Q_PROPERTY(bool  CruiseControlCancel READ getCruiseControlCancel WRITE setCruiseControlCancel NOTIFY CruiseControlCancelChanged FINAL)
    Q_PROPERTY(bool  DoorOpenActive READ getDoorOpenActive WRITE setDoorOpenActive NOTIFY DoorOpenActiveChanged FINAL)
    Q_PROPERTY(bool  EspActive READ getEspActive WRITE setEspActive NOTIFY EspActiveChanged FINAL)
    Q_PROPERTY(bool  ImobilizerActive READ getImobilizerActive WRITE setImobilizerActive NOTIFY ImobilizerActiveChanged FINAL)
    Q_PROPERTY(bool  OilPressureFault READ getOilPressureFault WRITE setOilPressureFault NOTIFY OilPressureFaultChanged FINAL)
    Q_PROPERTY(bool  ParkingBrakeActive READ getParkingBrakeActive WRITE setParkingBrakeActive NOTIFY ParkingBrakeActiveChanged FINAL)
    Q_PROPERTY(bool  SeatBeltActive READ getSeatBeltActive WRITE setSeatBeltActive NOTIFY SeatBeltActiveChanged FINAL)
    Q_PROPERTY(bool  SteeringFaultActive READ getSteeringFaultActive WRITE setSteeringFaultActive NOTIFY SteeringFaultActiveChanged FINAL)

public:
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

    bool getAbsActive() const;
    void setAbsActive(const bool &absActive);

    bool getCruiseControlActive() const;
    void setCruiseControlActive(const bool &cruiseControlActive);

    bool getCruiseControlCancel() const;
    void setCruiseControlCancel(const bool &cruiseControlCancel);

    bool getDoorOpenActive() const;
    void setDoorOpenActive(const bool &doorOpenActive);

    bool getEspActive() const;
    void setEspActive(const bool &espActive);

    bool getImobilizerActive() const;
    void setImobilizerActive(const bool &imobilizerActive);

    bool getOilPressureFault() const;
    void setOilPressureFault(const bool &oilPressureFault);

    bool getParkingBrakeActive() const;
    void setParkingBrakeActive(const bool &parkingBrakeActive);

    bool getSeatBeltActive() const;
    void setSeatBeltActive(const bool &seatBeltActive);

    bool getSteeringFaultActive() const;
    void setSteeringFaultActive(const bool &steeringFaultActive);



signals:
    void  CheckEngineChanged();
    void  ChargingChanged();
    void  SpeedGaugeChanged();
    void  FogLightChanged();
    void  FuelLevelChanged();
    void  EngineTempChanged();
    void  RPMChanged();
    void  SpeedTextChanged();
    void AbsActiveChanged();
    void CruiseControlActiveChanged();
    void CruiseControlCancelChanged();
    void DoorOpenActiveChanged();
    void EspActiveChanged();
    void ImobilizerActiveChanged();
    void OilPressureFaultChanged();
    void ParkingBrakeActiveChanged();
    void SeatBeltActiveChanged();
    void SteeringFaultActiveChanged();

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
    bool AbsActive = false;
    bool CruiseControlActive = false;
    bool CruiseControlCancel = false;
    bool DoorOpenActive = false;
    bool EspActive = false;
    bool ImobilizerActive = false;
    bool OilPressureFault = false;
    bool ParkingBrakeActive = false;
    bool SeatBeltActive = false;
    bool SteeringFaultActive = false;

};
}
#endif // CONTROLLER_H
