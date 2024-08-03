#include "Engine3D.h"
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <functional>
#include <SceneManager.h>
#include <Renderer3D.h>
#include <GLWindowWrapper.h>

Engine3D *Engine3D::s_instance = nullptr;
Engine3D *Engine3D::Instance()
{
    if (Engine3D::s_instance == nullptr)
    {
        Engine3D::s_instance = new Engine3D();
    }
    return Engine3D::s_instance;
}

Engine3D::Engine3D()
{
    std::cout << __FUNCTION__ << std::endl;
}

Engine3D::~Engine3D()
{
    if (this->m_renderer3d != nullptr)
    {
        delete this->m_renderer3d;
        this->m_renderer3d = nullptr;
    }

    if (this->m_winWrapper != nullptr)
    {
        delete this->m_winWrapper;
        this->m_winWrapper = nullptr;
    }
    std::cout << __FUNCTION__ << std::endl;
}

void Engine3D::Connections()
{
    this->m_sceneManager->NotifyWindowTitleChanged().Connect(
        SceneManager::NOTIFY_SCENE_CHANGED,
        std::bind(&Engine3D::OnWindowTitleChanged, this, std::placeholders::_1)
        );
}

void Engine3D::Update(float deltaTime)
{
    this->m_sceneManager->UpdateScenes(deltaTime);
}

void Engine3D::Render()
{
    this->m_renderer3d->SetDrawColor();
    this->m_renderer3d->Clear();
    this->m_sceneManager->RenderScenes(this->m_renderer3d);
    this->m_renderer3d->Present();
}

void Engine3D::ResetInstance()
{
    if (Engine3D::s_instance != nullptr)
    {
        delete Engine3D::s_instance;
        Engine3D::s_instance = nullptr;
    }
    return;
}

bool Engine3D::Initialize(const char* title)
{
    this->m_title = title;
    glfwSetErrorCallback([](int error, const char* description)
                         {
                             fprintf(stderr, "Error: %s\n", description);
                         });

    if (!glfwInit())
    {
        return false;
    }

    this->m_winWrapper = new GLWindowWrapper();
    if (!this->m_winWrapper->CreateWindow(640, 480, this->m_title))
    {
        return false;
    }

    this->m_renderer3d = Renderer3D::Instance();
    if (!this->m_renderer3d->Initialize(this->m_winWrapper))
    {
        return false;
    }

    if (glewInit() != GLEW_OK)
    {
        return false;
    }

    this->m_sceneManager = SceneManager::Instance();
    if (this->m_sceneManager == nullptr)
    {
        return false;
    }

    this->Connections();

    return true;
}

void Engine3D::Loop()
{
    while (!glfwWindowShouldClose(this->m_winWrapper->window()))
    {
        /* Poll for and process events */
        glfwPollEvents();
        this->Update(0.0f);
        this->Render();
    }
}

void Engine3D::Quit()
{
    SceneManager::ResetInstance();
    this->m_renderer3d->Destroy();
    this->m_winWrapper->DestroyWindow();
    Renderer3D::ResetInstance();
}

void Engine3D::GetDesktopResolution(int &width, int &height)
{
}

void Engine3D::OnWindowTitleChanged(const char *title)
{
    char buffer[255];
    sprintf(&buffer[0], this->m_title, title);
    glfwSetWindowTitle(this->m_winWrapper->window(), buffer);
}
