#ifndef IRENDERER_H
#define IRENDERER_H

class IWindowWrapper;
class ATexture;
class IRenderer
{
public:
    ~IRenderer() = default;
    virtual bool Initialize(IWindowWrapper* window) = 0;
    virtual void SetDrawColor() = 0;
    virtual void Clear() = 0;
    virtual void Present() = 0;
    virtual void Destroy() = 0;
    virtual void RenderTexture(ATexture* texture) {};

};

#endif // IRENDERER_H
