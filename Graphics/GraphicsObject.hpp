#ifndef GRAPHICSOBJECT_H_
#define GRAPHICSOBJECT_H_

class GraphicsObject {

private:
    static GraphicsObject *_instance;

protected:
    GraphicsObject();

    GraphicsObject(const GraphicsObject &);

    GraphicsObject &operator=(const GraphicsObject &);

public:
    static GraphicsObject *Instance();

    ~GraphicsObject();

    bool Init3DGraphics();
};

#endif
