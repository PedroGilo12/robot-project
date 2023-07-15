#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <motor_control_driver.h>
#include <common.h>

int main ()
{

#if DEBUG_MODE == 1
    printf("[main] The program has started\n");
#endif

    int serial_port;
    sm_serial_motor_init(&serial_port);
    serial_motor motor_a = sm_set_serial_motor(&serial_port, 255);
    sm_set_velocity(&motor_a, 100, 'f');

    return 0;
}
