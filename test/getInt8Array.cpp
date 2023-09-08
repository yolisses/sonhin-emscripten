#include <emscripten/bind.h>
#include <emscripten/val.h>
#include <emscripten/bind.h>

using namespace emscripten;

std::array<int, 10> buffer = {1, 2, 3};

emscripten::val getInt8Array()
{
    return emscripten::val(
        emscripten::typed_memory_view(
            buffer.size(),
            buffer.data()));
}

EMSCRIPTEN_BINDINGS()
{
    function("getInt8Array", &getInt8Array);
}