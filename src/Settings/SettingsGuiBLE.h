#ifndef SETTINGSGUIBLE_H
#define SETTINGSGUIBLE_H

#include <QObject>
#include "ISettingsGui.h"
#include "DeviceSettingsBLE.h"

class MainWindow;

class SettingsGuiBLE : public DeviceSettingsBLE, public ISettingsGui
{
    Q_OBJECT
public:
    explicit SettingsGuiBLE(QObject* parent, MainWindow* mw);
    void loadParameters() override;
    void updateParam(MPParams::Param param, int val) override;
    void updateUI() override;
};

#endif // SETTINGSGUIBLE_H
