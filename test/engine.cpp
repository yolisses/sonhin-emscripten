#include <stdio.h>
#include <array>
#include <iostream>
#include <emscripten/bind.h>
using namespace emscripten;

const int CHUNK_SIZE = 10;
const int SAMPLE_RATE = 100;

template <typename T, size_t N>
void printArray(const std::array<T, N> &arr)
{
    std::cout << "[";
    for (size_t i = 0; i < N; i++)
    {
        std::cout << arr[i];
        if (i < N - 1)
        {
            std::cout << ", ";
        }
    }
    std::cout << "]" << std::endl;
}

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
    printArray(engine.chunk);
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
