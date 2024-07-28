#ifndef ENGINE3D_H
#define ENGINE3D_H

#include <memory>
#include "IEngine.h"
struct GLFWwindow;
class SceneManager;
class Engine3D: public IEngine
{
    friend SceneManager;
public:
    Engine3D(const Engine3D &) = delete;
    Engine3D(Engine3D &&) = delete;
    Engine3D(const char *title, GLFWwindow *window, SceneManager *sceneManager, const IEngine &);
    Engine3D &operator=(const Engine3D &) = delete;
    Engine3D &operator=(Engine3D &&) = delete;
    static Engine3D *Instance();
    static void ResetInstance();
    ~Engine3D();

    // IEngine interface
public:
    bool Initialize(const char* title) override;
    void Loop() override;
    void Quit() override;
    void Connections() override;

private:
    static Engine3D *s_instance;
    Engine3D();
    void GetDesktopResolution(int& width, int& height);
    void OnWindowTitleChanged(const char*title);


private:
    const char* m_title;
    GLFWwindow* m_window;
    SceneManager* m_sceneManager;
};

#endif // ENGINE3D_H