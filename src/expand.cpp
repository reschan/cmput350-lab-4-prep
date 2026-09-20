#include <cassert>  // assert
#include <cstddef>  // size_t
#include <cstdint>  // uint64_t, uint32_t
#include <iostream>
#include <bitset>

// Expands the binary representation of input by a factor of scale.
// e.g., expand(0b1111ull, 3) == 0b001001001001
uint64_t expand(uint64_t input, uint32_t scale) {
    assert(scale >= 1);
    uint64_t res = 0;
    for (int i = 0; i < 64; i++) {
        if (i * scale > 64) {
            return res;
        }
        // get original bit
        uint64_t mask = 1;
        uint64_t bit = (input & (mask << i)) >> i;
        res = res | (bit << (i * (scale)));
        std::cout << "shifted\n";
    }
    return res;
}

int main() {
    uint64_t res = expand(0b1, 0);
    std::bitset<64> x(res);
    std::cout << x << '\n';
    return 0;
}
