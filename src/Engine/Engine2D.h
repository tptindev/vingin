#ifndef ENGINE2D_H
#define ENGINE2D_H

#include "IEngine.h"
class SDLWindowWrapper;
class Renderer2D;
class SceneManager;
class Engine2D: public IEngine
{
public:
    Engine2D(const Engine2D &) = delete;
    Engine2D(Engine2D &&) = delete;
    Engine2D &operator=(const Engine2D &) = delete;
    Engine2D &operator=(Engine2D &&) = delete;
    static Engine2D *Instance();
    static void ResetInstance();
    static bool &Running();
    ~Engine2D();

    // IEngine interface
public:
    bool Initialize(const char *title) override;
    void Loop() override;
    void Quit() override;
    void Connections() override;

    // IEngine interface
private:
    void Update(float deltaTime) override;
    void Render() override;

private:
    static Engine2D *s_instance;
    Engine2D();
    void GetDesktopResolution(int& width, int& height);
    void OnWindowTitleChanged(const char*title);

private:
    const char* m_title;
    static bool s_running;
    SDLWindowWrapper* m_winWrapper{nullptr};
    Renderer2D* m_renderer2d{nullptr};
    SceneManager* m_sceneManager{nullptr};


};

#endif // !ENGINE2D_H
