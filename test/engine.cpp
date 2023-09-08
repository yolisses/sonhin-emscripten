#include <stdio.h>
#include <emscripten/bind.h>

using namespace emscripten;

const int CHUNK_SIZE = 4410;
const int SAMPLE_RATE = 44100;

class Engine
{
public:
    int index;
    float chunk[CHUNK_SIZE];
};

EMSCRIPTEN_BINDINGS(engine_something)
{
    class_<Engine>("MyClass")
        .constructor<>();
}

int main()
{
    Engine engine;
    printf("here\n");
    printf("%d\n", engine.index);
    return 0;
}