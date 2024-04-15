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
int Controller::getSpeedGauge() const
{
    return SpeedGauge;
}

void Controller::setSpeedGauge(const uint &speed)
{
    if (this -> SpeedGauge != speed) {
        this -> SpeedGauge = speed;
        emit SpeedGaugeChanged();
    }
}

int Controller::getEngineTemp() const
{
    return EngineTemp;
}

void Controller::setEngineTemp(const int &temp)
{
    if (this -> EngineTemp != temp) {
        this -> EngineTemp = temp;
        emit EngineTempChanged();
    }
}

int Controller::getRPM() const
{
    return RPM;
}

void Controller::setRPM(const int &rpm)
{
    if (this -> RPM != rpm) {
        this -> RPM = rpm;
        emit RPMChanged();
    }
}


int Controller::getFuelLevel() const
{
    return FuelLevel;
}

void Controller::setFuelLevel(const int &levelFuel) {
    if (this->FuelLevel != levelFuel) {
        this->FuelLevel = levelFuel;
        emit FuelLevelChanged();
    }
}


void Controller::initConnection()
{
    if (QCanBus::instance()->plugins().contains(QStringLiteral("peakcan"))) {
        QString errorString;
        { qDebug() << "CanInit: "; }
        canDevice.reset(QCanBus::instance()->createDevice("peakcan","usb0",&errorString));
        connect(canDevice.get(), &QCanBusDevice::framesReceived, this, &Controller::processReceivedFrames);
        canDevice->setConfigurationParameter(QCanBusDevice::ConfigurationKey::BitRateKey,125000); // set bautrate
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
        if(frame.frameId()==0x200){

        }
        if(frame.frameId()==0x100){
            const QByteArray data = frame.payload();
            char speed=data.at(0);
            char fuel= data.at(7);
            char rpm = data.at(5);
            char engine = data.at(2);
            Controller::setSpeedGauge(static_cast<uint>(speed));
            Controller::setFuelLevel(static_cast<int>(fuel));
            Controller::setEngineTemp(static_cast<int>(engine));
            Controller::setRPM(static_cast<int>(rpm));

           // qDebug() << "engine: "<<static_cast<int>(engine);
        }

    }
}


}
