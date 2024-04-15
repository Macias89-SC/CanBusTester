#include "controller.h"
#include <QCanBus>
#include <QCanBusFrame>
#include <QTransform>
#include <QDebug>

namespace CanBusGauges{

Controller::Controller(QObject *parent): QObject{parent}
{
    QObject::connect(this, &Controller::enableACChanged, [](bool state) { qDebug() << "enableACChanged: " << state; });
    initConnection();
}

int Controller::getFuelLevel() {return this->FuelLevel;}
void Controller::setFuelLevel(int levelFuel)
{
    this->FuelLevel = levelFuel;
    emit setFuelLevel(levelFuel);
}

int Controller::getSpeedGauge() { return this->SpeedGauge;}
void Controller::setSpeedGauge(int speed)
{
    this->SpeedGauge = speed;
    emit setSpeedGauge(speed);
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
            qDebug() << "Can send signal: "<<m_numberFramesReceived;
        }
        if(frame.frameId()==0x100){
            const QByteArray data = frame.payload();
            setFuelLevel(data[2]);

            //  ui->checkBox->setChecked(data[0]); // pod to podstawić dane do szybkościomierza
        }

    }
}


}
