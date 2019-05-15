#include <stdio.h>

struct Computer {
    float cpu_speed_GHz;
    int ram_size_GB;
    int bits;
};

typedef struct {
    float cpu_speed_GHz;
    int ram_size_GB;
    int bits;
} Notebook_t;

int main()
{
    struct Computer pc;
    pc.cpu_speed_GHz = 2.8;
    pc.ram_size_GB = 16;
    pc.bits = 64;

    Notebook_t lenovo;
    lenovo.cpu_speed_GHz = 3.3;
    lenovo.ram_size_GB = 16;
    lenovo.bits = 64;

    printf("Hi, I have a %d bit Lenovo notebook, it has a %.1f GHz processor and %d GB RAM.\n",lenovo.bits, lenovo.cpu_speed_GHz, lenovo.ram_size_GB);
    printf("Hi, I have a %d bit AMD PC, it has a %.1f GHz processor and %d GB RAM.\n",pc.bits, pc.cpu_speed_GHz, pc.ram_size_GB);

    return 0;
}