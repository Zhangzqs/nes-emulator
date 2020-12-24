//
// Created by zhiqiang on 2020/12/24.
//

#ifndef NES_EMULATOR_BUS_H
#define NES_EMULATOR_BUS_H

#include <cstdint>
#include "CPU.h"
#include <array>
#include <vector>
class Bus{
public:
    explicit Bus();
    virtual ~Bus();

public:
    //总线上的所有设备
    CPU cpu;

    //逻辑上的RAM
    std::array<uint8_t,64*1024> ram;

public:
    //总线上的读写操作
    void write(uint16_t addr,uint8_t data);
    uint8_t read(uint16_t addr,bool bReadOnly = false);
};


#endif //NES_EMULATOR_BUS_H
