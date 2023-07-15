#ifndef MOTOR_CONTROL_DRIVER_H
#define MOTOR_CONTROL_DRIVER_H

#include <common.h>
#include <wiringPi.h>
#include <wiringSerial.h>
#include <stdint.h>


#define SERIAL_PORT "/dev/serial0"
#define BAUDRATE 9600

/**
 * @brief Estrutura para armazenar as informações do motor
 *
 * @param address Endereço do motor (0-255)
 * @param velocity Velocidade do motor (0-100)
 * @param direction Direção do motor:
 *                  'f' -> Direita
 *                  'b' -> Esquerda
 *                  's' -> Parado
 */
typedef struct {
    uint8_t address;    /*< Endereço do motor*/
    uint8_t velocity;   /*< Velocidade do motor*/
    char direction;     /*< Direção do motor */
    int serial_port;
} serial_motor;

/**
 * @brief Inicia a porta serial responsável pelo serialbus
 *
 * @return -1 em caso de falha | 0 em caso de sucesso
 */
int sm_serial_motor_init(int *serial_port);

/**
 * @brief Inicia os parâmetros de um novo motor serial.
 *
 * @param serial_port Serial bus onde o motor está conectado.
 * @param address Endereço do motor.
 * @return A variável serial_motor.
 */
serial_motor sm_set_serial_motor(int *serial_port, uint8_t address);

/**
 * @brief Seta uma velocidade para o motor.
 *
 * @param motor Endereço do motor que será acionado.
 * @param velocity Velocidade do motor (0 - 100);
 * @param direction Direção do motor ('f', 'b', 's').
 * @return 0
 */
int sm_set_velocity(serial_motor *motor, uint8_t velocity, char direction);

/**
 * @brief Para o motor
 *
 * @param motor
 */
void sm_stop_motor(serial_motor *motor);

#endif
