#include "controller.h"
#include <QCanBus>
#include <QCanBusFrame>
#include <QTransform>
#include <QDebug>

namespace CanBusGauges{

Controller::Controller(QObject *parent): QObject{parent}
{
    initConnection();
}

quint8 Controller::getSpeedGauge() const
{
    return SpeedGauge;
}

void Controller::setSpeedGauge(const quint8 &speed)
{
    if (this -> SpeedGauge != speed) {
        this -> SpeedGauge = speed;
        emit SpeedGaugeChanged();
    }
}

bool Controller::getCheckEngine() const
{
    return CheckEngine;
}

void Controller::setCheckEngine(const bool &engine)
{
    if (this -> CheckEngine != engine) {
        this -> CheckEngine = engine;
        emit CheckEngineChanged();
    }
}

bool Controller::getCharging() const
{
    return Charging;
}

void Controller::setCharging(const bool &charge)
{
    if (this -> Charging != charge) {
        this -> Charging = charge;
        emit ChargingChanged();
    }
}

quint8 Controller::getEngineTemp() const
{
    return EngineTemp;
}

void Controller::setEngineTemp(const quint8 &temp)
{
    if (this -> EngineTemp != temp) {
        this -> EngineTemp = temp;
        emit EngineTempChanged();
    }
}

quint8 Controller::getRPM() const
{
    return RPM;
}

void Controller::setRPM(const quint8 &rpm)
{
    if (this -> RPM != rpm) {
        this -> RPM = rpm;
        emit RPMChanged();
    }
}


quint8 Controller::getFuelLevel() const
{
    return FuelLevel;
}

void Controller::setFuelLevel(const quint8 &levelFuel) {
    if (this->FuelLevel != levelFuel) {
        this->FuelLevel = levelFuel;
        emit FuelLevelChanged();
    }
}

QString Controller::getSpeedText() const
{
    return SpeedText;
}

void Controller::setSpeedText(const QString &speedText)
{
    if (this->SpeedText != speedText) {
        this->SpeedText = speedText;
        emit SpeedTextChanged();
    }
}


void Controller::initConnection()
{
    if (QCanBus::instance()->plugins().contains(QStringLiteral("peakcan"))) {
        QString errorString;
        { qDebug() << "CanInit: "; }
        canDevice.reset(QCanBus::instance()->createDevice("peakcan","usb0",&errorString));
        connect(canDevice.get(), &QCanBusDevice::framesReceived, this, &Controller::processReceivedFrames);
        canDevice->setConfigurationParameter(QCanBusDevice::ConfigurationKey::BitRateKey,500000); // set bautrate
        canDevice->setConfigurationParameter(QCanBusDevice::ConfigurationKey::CanFdKey,false);  // set no CanFd - i think is not neeeded
        if (!canDevice->connectDevice()) {
            // Error handling goes here
            canDevice.reset();
        }
    }
}
void Controller::processReceivedFrames()
{
    if (!canDevice)
        return;
    // Receive all can frame - counter only for check
    while (canDevice->framesAvailable()) {
         m_numberFramesReceived++;
        QCanBusFrame frame = canDevice->readFrame();
        if(frame.frameId()==0x420){
            const QByteArray data1 = frame.payload();
            if (data1[4]==0x40)
                { Controller::setCheckEngine(true);}
            else
                { Controller::setCheckEngine(false);}
            if (data1[5]==0x8)
                { Controller::setCharging(true);}
            else
                { Controller::setCharging(false);}

            if (data1[0] < 0x50)  { Controller::setEngineTemp(0);}
            if (data1[0] < 0x5F && data1[0] > 0x50)  { Controller::setEngineTemp(1);}
            if (data1[0] < 0x6F && data1[0] > 0x5F) { Controller::setEngineTemp(2);}
            if (data1[0] < 0x7D && data1[0] > 0x6F) { Controller::setEngineTemp(3);}
             qDebug() << "temp: "<< data1[0];
         //   if (data1[0] < 0x8C) { Controller::setEngineTemp(4);}
         //   if (data1[0] < 0x9B) { Controller::setEngineTemp(5);}
         //   if (data1[0] < 0xAA) { Controller::setEngineTemp(6);}

        }
        if(frame.frameId()==0x201){
            const QByteArray data = frame.payload();
            Controller::setSpeedGauge(data[4]);
            Controller::setFuelLevel(data[7]);
            //Controller::setEngineTemp(data[2]);
            Controller::setRPM(data[0]);
            Controller::setSpeedText(QString::number(data[4],10));

           // qDebug() << "speed: "<< QString::number(data[0],10);
        }
        else
        {
          //  Controller::setSpeedGauge(0);
         //   Controller::setFuelLevel(0);
         //   Controller::setEngineTemp(0);
        //    Controller::setRPM(0);
         //   Controller::setSpeedText("ERR");
        }
    }
}


}
