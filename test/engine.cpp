#include <stdio.h>
#include <emscripten/bind.h>

using namespace emscripten;

const int CHUNK_SIZE = 4410;
const int SAMPLE_RATE = 44100;

class Engine
{
public:
    Engine(){};
    int index;
    float chunk[CHUNK_SIZE];
};

int main()
{
    Engine engine;
    printf("here\n");
    return 0;
}

EMSCRIPTEN_BINDINGS(engine)
{
    class_<Engine>("Engine")
        .constructor()
        .property("index", &Engine::index);
}
