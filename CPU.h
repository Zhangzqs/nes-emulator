//
// Created by zhiqiang on 2020/12/23.
//

#ifndef NES_EMULATOR_CPU_H
#define NES_EMULATOR_CPU_H

//提供了uint*_t各种类型
#include <cstdint>
#include <string>

/*
 * 类型前置声明，避免头文件的重复包含
 * */
class Bus;

/*6502 CPU的定义*/
class CPU {
public:
    explicit CPU();

    virtual ~CPU();

public:
    //6502 CPU的寄存器,这里声明为public是为了便于更方便地访问
    uint8_t a;  //累加寄存器
    uint8_t x;  //x变址寄存器
    uint8_t y;  //y变址寄存器
    uint8_t sp; //堆栈指针寄存器
    uint8_t pc; //PC程序计数器
    uint8_t status; //标志位寄存器

public:
    /*各个标志位的枚举值*/
    enum FLAGS {
        C = (1 << 0),    // Carry Bit 进位标志位
        Z = (1 << 1),    // Zero 零标志位
        I = (1 << 2),    // Disable Interrupts 禁用中断标志位
        D = (1 << 3),    // Decimal Mode (unused in this implementation) 十进制模式标志位
        B = (1 << 4),    // Break BRK中断标志位
        U = (1 << 5),    // Unused 不使用
        V = (1 << 6),    // Overflow 溢出标志位
        N = (1 << 7),    // Negative 负数标志位
    };


public:


/*
 * 6502由3个中断IRQ/NMI/RESET，每个中断都有一个16位向量，即指针,
 * 用来存放该中断发生时中断服务函数的地址
 * 一些外部事件，硬件层上这些事件是由外部引脚而触发的，
 * 模拟器中这些事件是由外部调用而实现
 * */

    /*复位中断，强制让CPU达到一个已知的状态,优先级最高*/
    void reset();


    /*
     * interrupt request 中断请求，在特定位置执行一个指令,又称作BRK中断
     * IRQ/BRK中断有两种情况，一种可由软件使用BRK指令产生，一种是硬件通过IRQ引脚产生
     */
    void irq();

    /*Non-Maskable Interrupt Request 不可屏蔽中断请求*/
    void nmi();

    /*执行一个时钟周期的更新*/
    void clock();

    /*查询当前指令是否已经执行完毕*/
    bool complete();

    void ConnectBus(Bus *bus) { this->bus = bus; };

private:
    /*与总线通信*/
    Bus *bus = nullptr;

    /*读取16位地址存放的值*/
    uint8_t read(uint16_t addr);

    /*写入16位地址的值*/
    void write(uint16_t addr, uint8_t val);

private:
    /*访问标志位函数的便捷函数*/
    bool GetFlag(FLAGS flag);

    void SetFlag(FLAGS flag, bool val);

private:

    /*
     * 指令的结构体
     * */
    struct INSTRUCTION {
        std::string name;   //指令名

        uint8_t cycles = 0; //该指令所需的机器周期
    };

private:
    /*
     * 各种寻址模式
     * 6502有多种寻址模式去访问内存数据，一些是直接寻址，一些是像指针那样的间接寻址。
     * 每个操作符都包含了寻址模式的信息,可以用来简化某些操作。这与它在哪里读/写它使用的数据有关。
     * 寻址模式会改变字节数该组成完整的指令，所以我们应该在实现执行指令之前，实现寻址模式，
     * 以此来确保程序计数器指向正确的位置，指令用它所需要的地址进行装填，
     * 并且指令需要的机器周期数也会被计算出来。
     * 这些函数可以根据访问内存的位置和方式调整所需的周期数，因此它们返回所需的调整结果。
     * */

    uint8_t IMP();

    uint8_t IMM();

    uint8_t ZP0();

    uint8_t ZPX();

    uint8_t ZPY();

    uint8_t REL();

    uint8_t ABS();

    uint8_t ABX();

    uint8_t ABY();

    uint8_t IND();

    uint8_t IZX();

    uint8_t IZY();

private:

    /*
     * 56个指令
     * */

    uint8_t ADC();

    uint8_t AND();

    uint8_t ASL();

    uint8_t BCC();

    uint8_t BCS();

    uint8_t BEQ();

    uint8_t BIT();

    uint8_t BMI();

    uint8_t BNE();

    uint8_t BPL();

    uint8_t BRK();

    uint8_t BVC();

    uint8_t BVS();

    uint8_t CLC();

    uint8_t CLD();

    uint8_t CLI();

    uint8_t CLV();

    uint8_t CMP();

    uint8_t CPX();

    uint8_t CPY();

    uint8_t DEC();

    uint8_t DEX();

    uint8_t DEY();

    uint8_t EOR();

    uint8_t INC();

    uint8_t INX();

    uint8_t INY();

    uint8_t JMP();

    uint8_t JSR();

    uint8_t LDA();

    uint8_t LDX();

    uint8_t LDY();

    uint8_t LSR();

    uint8_t NOP();

    uint8_t ORA();

    uint8_t PHA();

    uint8_t PHP();

    uint8_t PLA();

    uint8_t PLP();

    uint8_t ROL();

    uint8_t ROR();

    uint8_t RTI();

    uint8_t RTS();

    uint8_t SBC();

    uint8_t SEC();

    uint8_t SED();

    uint8_t SEI();

    uint8_t STA();

    uint8_t STX();

    uint8_t STY();

    uint8_t TAX();

    uint8_t TAY();

    uint8_t TSX();

    uint8_t TXA();

    uint8_t TXS();

    uint8_t TYA();

    uint8_t XXX();

};


#endif //NES_EMULATOR_CPU_H
