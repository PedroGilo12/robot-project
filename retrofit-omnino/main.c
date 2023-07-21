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
        printf("1 - Setar a velocidade de um motor\n");
        printf("2 - Enviar velocidades");
        printf("3 - Parar todos os motores.\n");
        int choice;

        scanf("%d", &choice);

        switch (choice) {
            case 1:
                int address, velocity;
                char direction;

                printf("Digite em ordem: Motor Velocidade Direção\n");
                scanf("%d %d %c", &address, &velocity, &direction);

                printf("Motor: %d\nVelocidade: %d\nDirection: %c", address, velocity, direction);
                if(address == 1) {
                    sm_set_velocity(&motor_a, velocity, direction);
                }
                if(address == 2) {
                    sm_set_velocity(&motor_b, velocity, direction);
                }
                if(address == 3) {
                    sm_set_velocity(&motor_c, velocity, direction);
                }

                break;
            case 2:
                sm_stop_motor(&motor_a);
                sm_stop_motor(&motor_b);
                sm_stop_motor(&motor_c);

        }
    }

#if DEBUG_MODE == 1
    printf("[main] The program has finished\n");
#endif

    return 1;
}
