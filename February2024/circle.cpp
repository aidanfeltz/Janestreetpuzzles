#include <iostream>
#include <random>

// Function to check if the circle is out of bounds
bool circleOut(double x1, double y1, double x2, double y2) {
    double XC = (x1 + x2) / 2.0;
    double YC = (y1 + y2) / 2.0;
    double r = std::sqrt(std::pow(x1 - x2, 2) + std::pow(y1 - y2, 2)) / 2.0;
    if ((XC + r) >= 1 || (XC - r) <= 0 || (YC + r) >= 1 || (YC - r) <= 0) {
        return true;
    }
    return false;
}

// Simulation function
double simulation(int z) {
    int timesOut = 0;
    int timesIn = 0;
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(0.000000001, 0.999999999);

    for (int i = 0; i < z; ++i) {
        double a = dis(gen);
        double b = dis(gen);
        double c = dis(gen);
        double d = dis(gen);
        if (circleOut(a, b, c, d)) {
            timesOut++;
        } else {
            timesIn++;
        }
    }

    int timesTried = timesOut + timesIn;
    std::cout << "Times Tried: " << timesOut << std::endl;
    std::cout << "Times in: " << timesIn << std::endl;
    std::cout << "Total Times tried: " << timesTried << std::endl;
    std::cout << "Percent of the time it was out: " << static_cast<double>(timesOut) / timesTried * 100 << std::endl;

    return static_cast<double>(timesOut) / timesTried;
}

int main() {
    double k = 0;
    for (int i = 0; i < 50000; ++i) {
        k += simulation(10000);
    }
    std::cout << k / 50000 << std::endl;
    return 0;
}
