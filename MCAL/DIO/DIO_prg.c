/*
 * DIO_prg.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: DELL
 */
/*library inclusion*/
#include "../../LIB/BIT_Math.h"
#include "../../LIB/STD_Types.h"
#include "DIO_int.h"

#include "DIO_pri.h"

/*function definetion*/

void DIO_SetPinDirection(u8 u8PortIdCopy,u8 u8PinIdCopy,u8 u8PinDirCopy)
{
	if((u8PortIdCopy <= PORTD) &&(u8PinIdCopy <= PIN7))
	{
		if (u8PinDirCopy == OUTPUT)
		{
			/*check on the reguired PORT number*/
			switch(u8PortIdCopy)
			{

			case PORTA : SET_BIT(DDRA_register,u8PinIdCopy);break;
			case PORTB : SET_BIT(DDRB_register,u8PinIdCopy);break;
			case PORTC : SET_BIT(DDRC_register,u8PinIdCopy);break;
			case PORTD : SET_BIT(DDRD_register,u8PinIdCopy);break;

			}
		}
		else if (u8PinDirCopy ==INPUT)
		{
			switch(u8PortIdCopy)
						{

						case PORTA : CLR_BIT(DDRA_register,u8PinIdCopy);break;
						case PORTB : CLR_BIT(DDRB_register,u8PinIdCopy);break;
						case PORTC : CLR_BIT(DDRC_register,u8PinIdCopy);break;
						case PORTD : CLR_BIT(DDRD_register,u8PinIdCopy);break;

						}
		}
		else
		{
			/*do nothing wrong value to set!*/
		}
	}else
	{
		/*do nothing error!*/
	}

}

void DIO_SetPinValue (u8 u8PortIdCopy,u8 u8PinIdCopy,u8 u8PinValCopy)
{
	if((u8PortIdCopy <= PORTD) &&(u8PinIdCopy <= PIN7))
		{
			if (u8PinValCopy == HIGH)
			{
				/*check on the reguired PORT number*/
				switch(u8PortIdCopy)
				{

				case PORTA : SET_BIT(PORTA_register,u8PinIdCopy);break;
				case PORTB : SET_BIT(PORTB_register,u8PinIdCopy);break;
				case PORTC : SET_BIT(PORTC_register,u8PinIdCopy);break;
				case PORTD : SET_BIT(PORTD_register,u8PinIdCopy);break;

				}
			}
			else if (u8PinValCopy ==LOW)
			{
				switch(u8PortIdCopy)
							{

							case PORTA : CLR_BIT(PORTA_register,u8PinIdCopy);break;
							case PORTB : CLR_BIT(PORTB_register,u8PinIdCopy);break;
							case PORTC : CLR_BIT(PORTC_register,u8PinIdCopy);break;
							case PORTD : CLR_BIT(PORTD_register,u8PinIdCopy);break;

							}
			}
			else
			{
				/*do nothing wrong value to set!*/
			}
		}else
		{
			/*do nothing error in the pin id or port id*/
		}
}
u8 DIO_GetPinValue (u8 u8PortIdCopy,u8 u8PinIdCopy)
{
	u8 u8ResultLocal;
	if((u8PortIdCopy <= PORTD) &&(u8PinIdCopy <= PIN7))
	{
		switch(u8PortIdCopy)
	    {
		            case PORTA :u8ResultLocal= GET_BIT(PORTA_register,u8PinIdCopy);break;
					case PORTB :u8ResultLocal= GET_BIT(PORTB_register,u8PinIdCopy);break;
					case PORTC :u8ResultLocal= GET_BIT(PORTC_register,u8PinIdCopy);break;
					case PORTD :u8ResultLocal= GET_BIT(PORTD_register,u8PinIdCopy);break;
	    }
	}
	else
	{
		u8ResultLocal=0xFF;

	}
	return u8ResultLocal;
}

void DIO_SetPORTDirection (u8 u8PortIdCopy,u8 u8PinDirCopy)
{
	u8 i=0;
	for(i=0;i<8;i++)
	{
		DIO_SetPinDirection ( u8PortIdCopy,i,u8PinDirCopy);
	}

}
void  DIO_SetPort_Value (u8 u8PortIdCopy,u8 u8PinValCopy)
{

		/* Check on the Required PORT Number */
		switch (u8PortIdCopy)
		{
			case     PORTA:PORTA_register =  u8PinValCopy; break;
			case     PORTB: PORTB_register =  u8PinValCopy; break;
			case     PORTC: PORTC_register = u8PinValCopy; break;
			case     PORTD: PORTD_register =  u8PinValCopy; break;
			default: /* Wrong Port ID */        break;
		}
}
void DIO_set_Fhalf_Port_dir(u8 u8PortIdCopy,u8 u8PinDirCopy)
{
	u8 i=0;
		for(i=0;i<4;i++)
		{
			DIO_SetPinDirection ( u8PortIdCopy,i,u8PinDirCopy);
		}

}

void DIO_set_Fhalf_Port_Val(u8 u8PortIdCopy,u8 u8PinValCopy)
{
	u8 i=0;
		for(i=0;i<4;i++)
		{
			DIO_SetPinValue ( u8PortIdCopy,i,u8PinValCopy);
		}
}
