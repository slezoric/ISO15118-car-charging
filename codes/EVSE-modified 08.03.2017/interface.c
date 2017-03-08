/*
 * interface.c
 *
 *  Created on: 30.10.2015
 *      Author: melanie
 */

# include "interface.h"


#define MODEMDEVICE "/dev/ttyAPP2"

int open_serial(void)
  {
  /* Oeffnet seriellen Port
   * Gibt das Filehandle zurueck oder -1 bei Fehler
   * RS232-Parameter:
   * 19200 bps, 8 Datenbits, 1 Stoppbit, no parity, no handshake
   */

   int fd;                    /* Filedeskriptor */
   struct termios options;    /* Schnittstellenoptionen */

   /* Port oeffnen - read/write, kein "controlling tty", Status von DCD ignorieren */
   fd = open(MODEMDEVICE, O_RDWR | O_NOCTTY | O_NDELAY);
   if (fd >= 0)
     {
     /* get the current options */
     fcntl(fd, F_SETFL, 0);
     if (tcgetattr(fd, &options) != 0) return(-1);
     /* Baudrate setzen */
     cfsetispeed(&options, B57600);
     cfsetospeed(&options, B57600);

     /* setze Optionen */
     options.c_cflag &= ~PARENB;         /* kein Paritybit */
     options.c_cflag &= ~CSTOPB;         /* 1 Stoppbit */
     options.c_cflag &= ~CSIZE;          /* 8 Datenbits */
     options.c_cflag |= CS8;

     /* 57600 bps, 8 Datenbits, CD-Signal ignorieren, Lesen erlauben */
     options.c_cflag |= (CLOCAL | CREAD);

     /* Kein Echo, keine Steuerzeichen, keine Interrupts */
     options.c_lflag &= ~(ICANON | ECHO | ECHOE | ISIG);
     options.c_iflag = IGNPAR;           /* Parity-Fehler ignorieren */
     options.c_oflag &= ~OPOST;          /* setze "raw" Input */
     options.c_cc[VMIN]  = 0;            /* warten auf min. 0 Zeichen */
     options.c_cc[VTIME] = 10;           /* Timeout 1 Sekunde */
     tcflush(fd,TCIOFLUSH);              /* Puffer leeren */
     if (tcsetattr(fd, TCSAFLUSH, &options) != 0) return(-1);

     }
  return(fd);
  }

int uart_send_data(int fd, char* data,int length)
{
	int sent;  /* return-Wert */
  /*  Daten senden */
  sent = write(fd, data, length);
  if (sent < 0)
    {
    perror("sendbytes failed - error!");
    return -1;
    }
  if (sent < length)
    {
    perror("sendbytes failed - truncated!");
    }

  return sent;
}

unsigned char build_checksum(char* data, int length)
{
	unsigned char result=0;
	int i;
	for(i=0;i<length;i++)
	{
		result = result^data[i];
	}
	return result;
}
void STX_Error(int fd, char* result)
{
	int read_old[2];
	while((read_old[0] != result[0]) || (read_old[0] != read_old[1])||(read_old[0] == 0))
	{
		read_old[1] = read_old[0];
		read_old[0] = result[0];
		read(fd,result,1);
	}
}


