#ifndef VIOLET_RENDERER_HPP
#define VIOLET_RENDERER_HPP
class Drawable {
    virtual void draw() = 0;
};

class IRenderer{
    virtual ~IRenderer() {}
    virtual void beginRender() = 0;
    virtual void endRender() = 0;
    virtual void draw() = 0;
    virtual void submit(Drawable* in) = 0;
    virtual void remove(Drawable* in) = 0;
};

#endif
