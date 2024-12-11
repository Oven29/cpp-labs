#include "utils/Random.h"

#include <random>

namespace Random {

double RandDouble(double begin, double end) {
    std::random_device r{};
    std::default_random_engine randomEngine(r());
    std::uniform_real_distribution<double> distribution(begin, end);

    return distribution(randomEngine);
}

}  // namespace Random
