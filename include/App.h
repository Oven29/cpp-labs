#pragma once

namespace App {

using TPF = double (*)(double);

struct IntegralPrint {
    const char* FnName = {};
    double integralSum = 0;
    double actualIntegralSum = 0;
    int n = 0;
};

void Run();

}  // namespace App
