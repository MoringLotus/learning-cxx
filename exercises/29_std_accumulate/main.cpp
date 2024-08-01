#include "../exercise.h"
#include <numeric>

// READ: `std::accumulate` <https://zh.cppreference.com/w/cpp/algorithm/accumulate>

int main(int argc, char **argv) {
    using DataType = float;
    int shape[]{1, 3, 224, 224};
    // TODO: 调用 `std::accumulate` 计算：
    //       - 数据类型为 float；
    //       - 形状为 shape；
    //       - 连续存储；
    //       的张量占用的字节数
    auto total_elements = std::accumulate(shape, shape + sizeof(shape) / sizeof(shape[0]), 1, std::multiplies<>());

    // 计算张量占用的字节数
    size_t bytes_per_element = sizeof(DataType);
    size_t total_bytes = total_elements * bytes_per_element;
    int size = total_bytes;
    ASSERT(size == 602112, "4x1x3x224x224 = 602112");
    return 0;
}
