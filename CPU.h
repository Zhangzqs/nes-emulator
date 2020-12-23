//
// Created by zhiqiang on 2020/12/23.
//

#ifndef NES_EMULATOR_CPU_H
#define NES_EMULATOR_CPU_H
#include <iostream>
#include <string>
/*
 * 类型前置声明，避免头文件的重复包含
 * */
class Bus;

/*6502 CPU的定义*/
class CPU{
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

    enum FLAGS{
        C = (1 << 0),	// Carry Bit 进位标志位
        Z = (1 << 1),	// Zero 零标志位
        I = (1 << 2),	// Disable Interrupts 禁用中断标志位
        D = (1 << 3),	// Decimal Mode (unused in this implementation) 十进制模式标志位
        B = (1 << 4),	// Break BRK中断标志位
        U = (1 << 5),	// Unused 不使用
        V = (1 << 6),	// Overflow 溢出标志位
        N = (1 << 7),	// Negative 负数标志位
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

    void ConnectBus(Bus *bus){this->bus = bus;};

private:
    /*与总线通信*/
    Bus *bus = nullptr;

    /*读取16位地址存放的值*/
    uint8_t read(uint16_t addr);

    /*写入16位地址的值*/
    void write(uint16_t addr,uint8_t val);

private:
    /*访问标志位函数的便捷函数*/
    bool GetFlag(FLAGS flag);
    void SetFlag(FLAGS flag,bool val);

private:

    /*
     * 指令的结构体
     * */
    struct INSTRUCTION{
        std::string name;   //指令名

        uint8_t cycles = 0; //该指令所需的机器周期
    };
};


#endif //NES_EMULATOR_CPU_H
