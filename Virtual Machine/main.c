//
//  main.c
//  Virtual Machine
//
//  Created by Nathan Thurber on 17/9/24.
//

#include <stdio.h>
#include <stdbool.h>

#define sp (registers[SP])
#define ip (registers[IP])

typedef enum {
    PSH,
    ADD,
    POP,
    SET,
    MOV,
    HLT
} InstructionSet;

typedef enum {
    A, B, C, D, E, F, IP, SP, //program counter, stack counter
    NUM_OF_REGISTERS
} Registers;

const int program[] = {
    PSH, 5,
    PSH, 6,
    ADD,
    POP,
    //MOV,
    //SET,
    HLT
};

int registers[NUM_OF_REGISTERS];

int stack[256];

bool running = 1;

void eval(int instr) 
{
    switch (instr) 
    {
        case HLT:
        {
            running = false;
            break;
        }
        case PSH:
        {
            sp++;
            stack[sp] = program[++ip];
            break;
        }
        case POP:
        {
            int val_popped = stack[sp--];
            printf("popped %d\n", val_popped);
            break;
        }
        case ADD: 
        {
            int a = stack[sp--];
            int b = stack[sp--];
            int result = b + a;
            
            sp++;
            stack[sp] = result;
            break;
        }
        case SET:
        {
            
        }
    }
}

int main(int argc, const char * argv[])
{
    sp = -1;
    ip = 0;
    
    while (running)
    {
        eval(program[ip]);
        ip++;
    }
    
    return 0;
}
