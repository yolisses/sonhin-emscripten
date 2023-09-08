#include "print_array.h"
#include <stdio.h>
#include <array>
#include <emscripten/bind.h>
using namespace emscripten;

const int CHUNK_SIZE = 10;
const int SAMPLE_RATE = 100;

class Engine
{
public:
    int index;
    std::array<float, CHUNK_SIZE> chunk = {};

    emscripten::val getBuffer()
    {
        return emscripten::val(
            emscripten::typed_memory_view(
                this->chunk.size(),
                this->chunk.data()));
    }
};

int main()
{
    Engine engine;
    printf("here\n");
    print_array(engine.chunk);
    return 0;
}

EMSCRIPTEN_BINDINGS(engine)
{
    class_<Engine>("Engine")
        .constructor()
        .property("index", &Engine::index)
        .property("chunk", &Engine::chunk)
        .function("getBuffer", &Engine::getBuffer);
}
