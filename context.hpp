#include <allegro5/allegro.h>

#include "iso.hpp"

#include <map>
#include <vector>
#include <cstdint>
using namespace std;

typedef int tileID;

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600


class Context {
public:
    void RenderFrame();
    bool shouldExit();

    void RegisterTriangle(Triangle* t);

    Context();
    ~Context();
private:
    ALLEGRO_DISPLAY* display;
    ALLEGRO_EVENT_QUEUE* event_queue;

    vector<Triangle*> triangles;
};