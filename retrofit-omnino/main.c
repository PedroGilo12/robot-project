#include <stdio.h>
#include <string.h>
#include <errno.h>

#include <wiringPi.h>
#include <wiringSerial.h>

int main ()
{
    int serial_port ;
    char dat;

    printf("The program has started\n");

    if ((serial_port = serialOpen("/dev/serial0", 9600)) < 0)	/* open serial port */
    {
        fprintf (stderr, "Unable to open serial device: %s\n", strerror (errno)) ;
        return 1 ;
    }

    if (wiringPiSetup () == -1)					/* initializes wiringPi setup */
    {
        fprintf (stdout, "Unable to start wiringPi: %s\n", strerror (errno)) ;
        return 1 ;
    }

    while(1){

	serialPrintf(serial_port, "oi\n");

        if(serialDataAvail (serial_port) )
        {
            dat = serialGetchar (serial_port);		/* receive character serially*/
            printf ("%c", dat) ;
            fflush (stdout) ;
            serialPutchar(serial_port, dat);		/* transmit character serially on port */
        }
    }

}
