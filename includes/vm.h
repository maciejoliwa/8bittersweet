#include <stdint.h>

#define MEMORY_SIZE 255
#define PROGRAM_SIZE 1024

typedef enum Operations {
    PUSH,
    ADD,
    SUBSTRACT,
    MULTIPLY,
    DIVIDE,
    DRAW,
    EQ,
    LT,
    GT,
    JUMP,
    CLEAR,
} op_t;

typedef struct VirtualMachine {
    uint8_t memory[MEMORY_SIZE];
    uint8_t program[PROGRAM_SIZE];
} vm_t;

vm_t init_vm(uint8_t program[PROGRAM_SIZE]);
void execute_vm_program(vm_t *vm);