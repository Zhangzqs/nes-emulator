//
// Created by zhiqiang on 2020/12/24.
//

#include "CPU.h"
#include "Bus.h"

/*
 * CPU对总线设备的读写操作
 * */

uint8_t CPU::read(uint16_t addr) {
    return bus->read(addr,false);
}

void CPU::write(uint16_t addr, uint8_t val) {
    bus->write(addr,val);
}

/*-----------------------------以下为寻址模式------------------------------*/
/*
 * 立即数寻址
 * */

uint8_t CPU::IMP() {
    return 0;
}

uint8_t CPU::IMM() {
    return 0;
}

uint8_t CPU::ZP0() {
    return 0;
}

uint8_t CPU::ZPX() {
    return 0;
}

uint8_t CPU::ZPY() {
    return 0;
}

uint8_t CPU::REL() {
    return 0;
}

uint8_t CPU::ABS() {
    return 0;
}

uint8_t CPU::ABX() {
    return 0;
}

uint8_t CPU::ABY() {
    return 0;
}

uint8_t CPU::IND() {
    return 0;
}

uint8_t CPU::IZX() {
    return 0;
}

uint8_t CPU::IZY() {
    return 0;
}

/*
 * 56个指令的实现
 * */

uint8_t CPU::ADC() {
    return 0;
}

uint8_t CPU::AND() {
    return 0;
}

uint8_t CPU::ASL() {
    return 0;
}

uint8_t CPU::BCC() {
    return 0;
}

uint8_t CPU::BCS() {
    return 0;
}

uint8_t CPU::BEQ() {
    return 0;
}

uint8_t CPU::BIT() {
    return 0;
}

uint8_t CPU::BMI() {
    return 0;
}

uint8_t CPU::BNE() {
    return 0;
}

uint8_t CPU::BPL() {
    return 0;
}

uint8_t CPU::BRK() {
    return 0;
}

uint8_t CPU::BVC() {
    return 0;
}

uint8_t CPU::BVS() {
    return 0;
}

uint8_t CPU::CLC() {
    return 0;
}

uint8_t CPU::CLD() {
    return 0;
}

uint8_t CPU::CLI() {
    return 0;
}

uint8_t CPU::CLV() {
    return 0;
}

uint8_t CPU::CMP() {
    return 0;
}

uint8_t CPU::CPX() {
    return 0;
}

uint8_t CPU::CPY() {
    return 0;
}

uint8_t CPU::DEC() {
    return 0;
}

uint8_t CPU::DEX() {
    return 0;
}

uint8_t CPU::DEY() {
    return 0;
}

uint8_t CPU::EOR() {
    return 0;
}

uint8_t CPU::INC() {
    return 0;
}

uint8_t CPU::INX() {
    return 0;
}

uint8_t CPU::INY() {
    return 0;
}

uint8_t CPU::JMP() {
    return 0;
}

uint8_t CPU::JSR() {
    return 0;
}

uint8_t CPU::LDA() {
    return 0;
}

uint8_t CPU::LDX() {
    return 0;
}

uint8_t CPU::LDY() {
    return 0;
}

uint8_t CPU::LSR() {
    return 0;
}

uint8_t CPU::NOP() {
    return 0;
}

uint8_t CPU::ORA() {
    return 0;
}

uint8_t CPU::PHA() {
    return 0;
}

uint8_t CPU::PHP() {
    return 0;
}

uint8_t CPU::PLA() {
    return 0;
}

uint8_t CPU::PLP() {
    return 0;
}

uint8_t CPU::ROL() {
    return 0;
}

uint8_t CPU::ROR() {
    return 0;
}

uint8_t CPU::RTI() {
    return 0;
}

uint8_t CPU::RTS() {
    return 0;
}

uint8_t CPU::SBC() {
    return 0;
}

uint8_t CPU::SEC() {
    return 0;
}

uint8_t CPU::SED() {
    return 0;
}

uint8_t CPU::SEI() {
    return 0;
}

uint8_t CPU::STA() {
    return 0;
}

uint8_t CPU::STX() {
    return 0;
}

uint8_t CPU::STY() {
    return 0;
}

uint8_t CPU::TAX() {
    return 0;
}

uint8_t CPU::TAY() {
    return 0;
}

uint8_t CPU::TSX() {
    return 0;
}

uint8_t CPU::TXA() {
    return 0;
}

uint8_t CPU::TXS() {
    return 0;
}

uint8_t CPU::TYA() {
    return 0;
}

uint8_t CPU::XXX() {
    return 0;
}
