#ifndef PRESSURE_H_
#define PRESSURE_H_

#define SCALE_FACTOR 240

#include "I2C.h"

class Pressure {
public:
    Pressure();
    virtual ~Pressure() { };
    int getPressure();

private:
    struct I2C_config i2c_config;
    I2C i2c;
    int convertPressure(int pressure);
    // TODO: altitude private member
};

#endif /* PRESSURE_H_ */
