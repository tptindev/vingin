#ifndef SETTINGBUTTON_H
#define SETTINGBUTTON_H

#include <AEntity.h>

class SettingButton : public AEntity
{
public:
    SettingButton();
    ~SettingButton();

    // AEntity interface
public:
    void Update() override;
    void Render() override;
};

#endif // SETTINGBUTTON_H
