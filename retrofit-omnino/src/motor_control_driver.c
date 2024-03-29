#include <stdio.h>
#include <stdlib.h>
#include <motor_control_driver.h>

int sm_serial_motor_init(int *serial_port) {

    /* Iniciando porta serial */
    *serial_port = serialOpen(SERIAL_PORT, BAUDRATE);

    if (serial_port < 0) {
#if DEBUG_MODE == 1
        printf("[sm_init] The serial port cannot be started\n");
#endif
        return 1;
    }

    /* Iniciando WiringPi*/
    if (wiringPiSetup() == -1) {
#if DEBUG_MODE == 1
        printf("[sm_init] WiringPi cannot be started\n");
#endif
        return 1;
    }

#if DEBUG_MODE == 1
        printf("[sm_init] Serial port and WiringPi has be started\n");
#endif

    return 0;
}

serial_motor sm_set_serial_motor(int *serial_port, uint8_t address) {
    serial_motor motor = {
            .address = address,
            .velocity = 0,
            .direction = 's',
            .serial_port = *serial_port
    };

    return motor;
}

/**
 * @brief Atualiza os valores do motor
 * @param motor
 * @return
 */
int sm_update_motor(serial_motor * motor) {
    serialPutchar(motor->serial_port, motor->address);
    serialPutchar(motor->serial_port, motor->velocity);
    serialPutchar(motor->serial_port, motor->direction);
}

int sm_set_velocity(serial_motor *motor, uint8_t velocity, char direction) {

#if DEBUG_MODE == 1
        printf("[sm_set_velocity] Setting velocity...\n");
#endif

    motor->velocity = velocity;
    motor->direction = direction;

    sm_update_motor(motor);

    if (serialDataAvail(motor->serial_port)) {
        char dat = serialGetchar(motor->serial_port);
#if DEBUG_MODE == 1
        printf("[sm_set_velocity] Received response: %d\n", dat);
#endif
    }

    return 0;
}

void sm_stop_motor(serial_motor *motor) {

    motor->velocity = 0;
    motor->direction = 's';

    sm_update_motor(motor);

    return;
}

