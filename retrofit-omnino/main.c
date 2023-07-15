#include <stdio.h>
#include <errno.h>
#include <motor_control_driver.h>
#include <common.h>
#include <unistd.h>

int main(){

#if DEBUG_MODE == 1
    printf("[main] The program has started\n");
#endif

    int serial_port;
    sm_serial_motor_init(&serial_port);

    serial_motor motor_a = sm_set_serial_motor(&serial_port, 255);
    serial_motor motor_b = sm_set_serial_motor(&serial_port, 250);
    serial_motor motor_c = sm_set_serial_motor(&serial_port, 245);

    sm_set_velocity(&motor_a, 0, 's');
    sm_set_velocity(&motor_b, 0, 's');
    sm_set_velocity(&motor_c, 0, 's');

    //sleep(1);

#if DEBUG_MODE == 1
    printf("[main] The program has finished\n");
#endif

    return 1;
}
