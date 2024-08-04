#ifndef BACKGROUNDLAYER_H
#define BACKGROUNDLAYER_H

#include <memory>
#include <ALayer.h>
class SDLImage;
class SDLText;
class BackgroundLayer : public ALayer
{
public:
    BackgroundLayer();
    ~BackgroundLayer();

    // ALayer interface
public:
    void Initialize() override;
    void Update(float deltaTime) override;
    void Render(IRenderer *renderer) override;
    void Cleanup() override;

private:
    std::shared_ptr<SDLImage> m_bg{nullptr};
    std::shared_ptr<SDLText> m_hello{nullptr};
};

#endif // BACKGROUNDLAYER_H
