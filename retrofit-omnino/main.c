#include <stdio.h>
#include <errno.h>
#include <motor_control_driver.h>
#include <common.h>
#include <unistd.h>

serial_motor motor_a;
serial_motor motor_b;
serial_motor motor_c;

int main() {

#if DEBUG_MODE == 1
    printf("[main] The program has started\n");
#endif

    int serial_port;
    sm_serial_motor_init(&serial_port);

    motor_a = sm_set_serial_motor(&serial_port, 255);
    motor_b = sm_set_serial_motor(&serial_port, 250);
    motor_c = sm_set_serial_motor(&serial_port, 245);

    sm_stop_motor(&motor_a);
    sm_stop_motor(&motor_b);
    sm_stop_motor(&motor_c);

    while (1) {
        printf("Comandos: \n");
        printf("1 - Setar a velocidade dos 3 motores ao mesmo tempo.\n");
        printf("2 - Setar individualmente a velocidade do motor.");
        printf("3 - Parar todos os motores.\n");
        printf("4 - Parar um motor individualmente.\n");

        int choice;

        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("vel vel vel\n");
                int vel;


        }
    }

#if DEBUG_MODE == 1
    printf("[main] The program has finished\n");
#endif

    return 1;
}
