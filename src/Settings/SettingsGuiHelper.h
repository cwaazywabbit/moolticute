#ifndef SETTINGSGUIHELPER_H
#define SETTINGSGUIHELPER_H

#include <QObject>
#include <QJsonObject>
#include "DeviceSettings.h"
#include "WSClient.h"

namespace Ui {
class MainWindow;
}
class MainWindow;

class SettingsGuiHelper : public QObject
{
    Q_OBJECT
public:
    explicit SettingsGuiHelper(WSClient* parent = nullptr);
    void setMainWindow(MainWindow *mw);
    void createSettingUIMapping();
    bool checkSettingsChanged();
    void resetSettings();
    void getChangedSettings(QJsonObject& o);
    void updateParameters(const QJsonObject &data);

private slots:
    void sendParams(bool value, int param);
    void sendParams(int value, int param);

private:
    WSClient* m_wsClient = nullptr;
    DeviceSettings* m_settings = nullptr;
    MainWindow* m_mw = nullptr;
    Ui::MainWindow* ui = nullptr;

    Common::MPHwVersion m_deviceType = Common::MP_Unknown;
    QMap<MPParams::Param, QWidget*> m_widgetMapping;
};

#endif // SETTINGSGUIHELPER_H
