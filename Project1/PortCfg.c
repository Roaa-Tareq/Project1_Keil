#include "IntCtrl.h"
#include "Dio.h"
#include "Port.h"
#include "SysTick.h"

#define ACTIVATED_PORT_NUM				3	

/* User-defined configuration structs */
static Port_CfgType portCfg[]= {
																		{DIO_PF1, PORT_DIO, DIO_LOW, PORT_OUTPUT, PORT_DEFAULT_IA, PORT_DR2R},			/*RED LED*/
																		{DIO_PF4, PORT_DIO, DIO_LOW, PORT_INPUT, PORT_PUR, PORT_DR2R},							/*SW1*/
																		{DIO_PF0, PORT_DIO, DIO_LOW, PORT_INPUT, PORT_PUR, PORT_DR2R}								/*SW2*/
																};

																
int main(void)
{
	Port_Init(portCfg,ACTIVATED_PORT_NUM);
	while(1)
	{
		if(Dio_ReadChannel(portCfg[1].pin) == 0x00)
		{
			/*SW1 is pressed*/
			Dio_WriteChannel(portCfg[0].pin,portCfg[0].levelValue);
		}

	}
}