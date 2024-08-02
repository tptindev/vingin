#ifndef SETTINGSCENE_H
#define SETTINGSCENE_H

#include <AScene.h>

class SettingScene : public AScene
{
public:
    SettingScene();
    ~SettingScene();

    // AScene interface
public:
    void Initialize() override;
    void HandleEvents() override;
    void Update(float deltaTime) override;
    void Render() override;
    void Cleanup() override;
};

#endif // SETTINGSCENE_H
