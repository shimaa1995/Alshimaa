/*
 * DIO_PROGRAM.C
 *
 *  Created on: Jan 21, 2019
 *      Author: Alshimaa
 */
#include "STD_TYPES.h"
#include "MATH_BITS.h"
#include "AVR_DIO_REG.h"
#include "DIO_Interface.h"


/*******************************************************************
 * SET PIN DIRECTION
 * INPUT : PORT NUMBER & PIN NUMBER &VALUE TO SET PIN DDIRECTION
 * OUTPUT : ERROT STATE
 ******************************************************************/
u8 DIO_SetPinDirection
(
		DIO_tenuPORTID COPY_enuPortID ,//Port NB
		DIO_tenuPINID COPY_enuPinID ,//PIN NB
		DIO_tenuPinDirection COPY_enuPinDirection//Set pin Direction (input / output)
)
{
	/*Error variable to indicate if error occurs or not */
	u8 LOC_u8Err = 0 ;

	/*Check if user entered pin number higher than 7 or less than 0*/
	if(COPY_enuPinID > u8MAX_PIN_NB || COPY_enuPinID <0)
	{
		/*if (7<pin number<0) set error variable*/
		LOC_u8Err = 1;
	}
	else
	{
		/*if pin numper in Range(0,7) check port NB*/
		switch(COPY_enuPortID)
		{
		/*if user enterd PortA check value want to set*/
		case DIO_enuPORTA :
			/*if value is equal to Input clr the selected pin*/
			if(COPY_enuPinDirection == DIO_enuINPUT)
			{
				CLR_BIT(DDRA,COPY_enuPinID);
			}
			/*if value is equal to output set the selected pin*/
			else if(COPY_enuPinDirection == DIO_enuOUTPUT)
			{
				SET_BIT(DDRA,COPY_enuPinID);
			}
			/*if value is not equal to input or output set error variable*/
			else
			{
				LOC_u8Err = 1;
			}
			break ;
			/*if user enterd PortB check value want to set*/
		case DIO_enuPORTB :
			/*if value is equal to Input clr the selected pin*/
			if(COPY_enuPinDirection == DIO_enuINPUT)
			{
				CLR_BIT(DDRB,COPY_enuPinID);
			}
			/*if value is equal to output set the selected pin*/
			else if(COPY_enuPinDirection == DIO_enuOUTPUT)
			{
				SET_BIT(DDRB,COPY_enuPinID);
			}
			/*if value is not equal to input or output set error variable*/
			else
			{
				LOC_u8Err = 1;
			}
			break ;
			/*if user enterd PortC check value want to set*/
		case DIO_enuPORTC :
			/*if value is equal to Input clr the selected pin*/
			if(COPY_enuPinDirection == DIO_enuINPUT)
			{
				CLR_BIT(DDRC,COPY_enuPinID);
			}
			/*if value is equal to output set the selected pin*/
			else if(COPY_enuPinDirection == DIO_enuOUTPUT)
			{
				SET_BIT(DDRC,COPY_enuPinID);
			}
			/*if value is not equal to input or output set error variable*/
			else
			{
				LOC_u8Err = 1;
			}
			break ;
			/*if user enterd PortD check value want to set*/
		case DIO_enuPORTD :
			/*if value is equal to Input clr the selected pin*/
			if(COPY_enuPinDirection == DIO_enuINPUT)
			{
				CLR_BIT(DDRD,COPY_enuPinID);
			}
			/*if value is equal to output set the selected pin*/
			else if(COPY_enuPinDirection == DIO_enuOUTPUT)
			{
				SET_BIT(DDRD,COPY_enuPinID);
			}
			/*if value is not equal to input or output set error variable*/
			else
			{
				LOC_u8Err = 1;
			}
			break ;
		/*if user entered Port NB else set error variable*/
		default :
			LOC_u8Err = 1;
		}
	}
	/*Return error value*/
	return LOC_u8Err ;
}

/****************************************************************
 * SET PIN VALUE
 * INPUT : PORT NUMBER & PIN NUMBER & VALUE TO SET PIN VALUE
 * OUTPUT : ERROT STATE
 ***************************************************************/
u8 DIO_u8SetPinValue
(
		DIO_tenuPORTID COPY_enuPortID ,//Port NB
		DIO_tenuPINID COPY_enuPinID ,//PIN NB
		DIO_tenuPinValue COPY_enuPinValue//Set pin with High or Low Value
)
{
	/*Error variable to indicate if error occurs or not */
	u8 LOC_u8Err = 0 ;

	/*Check if user entered pin number higher than 7 or less than 0*/
	if(COPY_enuPinID > u8MAX_PIN_NB || COPY_enuPinID <0)
	{
		/*if (7<pin number<0) set error variable*/
		LOC_u8Err = 1;
	}
	/*if pin numper in Range(0,7) check port NB*/
	else
	{
		switch(COPY_enuPortID)
		{
		/*if user enterd PortA check value want to set*/
		case DIO_enuPORTA :
			/*if value is equal to zero clr the selected pin*/
			if (COPY_enuPinValue == DIO_enuLOW)
			{
				CLR_BIT(PORTA , COPY_enuPinID);
			}
			/*if value is equal to one set the selected pin*/
			else if (COPY_enuPinValue == DIO_enuHIGH)
			{
				SET_BIT(PORTA , COPY_enuPinID);
			}
			/*if value is not equal to one or zero set error variable*/
			else
			{
				LOC_u8Err = 1;
			}
			break ;
		/*if user enterd PortB check value want to set*/
		case DIO_enuPORTB :
			/*if value is equal to zero clr the selected pin*/
			if (COPY_enuPinValue == DIO_enuLOW)
			{
				CLR_BIT(PORTB , COPY_enuPinID);
			}
			/*if value is equal to one set the selected pin*/
			else if (COPY_enuPinValue == DIO_enuHIGH)
			{
				SET_BIT(PORTB , COPY_enuPinID);
			}
			/*if value is not equal to one or zero set error variable*/
			else
			{
				LOC_u8Err = 1;
			}

			break ;
		/*if user enterd PortC check value want to set*/
		case DIO_enuPORTC :
			/*if value is equal to zero clr the selected pin*/
			if (COPY_enuPinValue == DIO_enuLOW)
			{
				CLR_BIT(PORTC , COPY_enuPinID);
			}
			/*if value is equal to one set the selected pin*/
			else if (COPY_enuPinValue == DIO_enuHIGH)
			{
				SET_BIT(PORTC , COPY_enuPinID);
			}
			/*if value is not equal to one or zero set error variable*/
			else
			{
				LOC_u8Err = 1;
			}
			break ;
		/*if user enterd PortD check value want to set*/
		case DIO_enuPORTD :
			/*if value is equal to zero clr the selected pin*/
			if (COPY_enuPinValue == DIO_enuLOW)
			{
				CLR_BIT(PORTD , COPY_enuPinID);
			}
			/*if value is equal to one set the selected pin*/
			else if (COPY_enuPinValue == DIO_enuHIGH)
			{
				SET_BIT(PORTD , COPY_enuPinID);
			}
			/*if value is not equal to one or zero set error variable*/
			else
			{
				LOC_u8Err = 1;
			}
			break ;
			/*if user entered Port NB else set .error variable*/
		default :
			LOC_u8Err = 1;
		}
	}
	/*Return error value*/
	return LOC_u8Err ;
}

/****************************************************************
 * GET PIN VALUE
 * INPUT : PORT NUMBER & PIN NUMBER &  POINTER TO THE VALUE
 * OUTPUT : ERROT STATE
 ***************************************************************/
u8 DIO_u8GetPinValue
(
		DIO_tenuPORTID COPY_enuPortID ,//Port NB
		DIO_tenuPINID COPY_enuPinID ,//PIN NB
		u8 *COPY_pValue)//Pointer to Save pin value
{
	/*Error variable to indicate if error occurs or not */
	u8 LOC_u8Err = 0;

	/*Check if user entered pin number higher than 7 or less than 0*/
	/*check if pointer is equal NULL*/
	if((COPY_pValue == Null) || ((COPY_enuPinID >u8MAX_PIN_NB) || (COPY_enuPinID <0)))
	{
		/*if (7<pin number<0) set error variable*/
		/*if pointer is equal to NULL set error variable*/
		LOC_u8Err = 1;
	}
	/*if pin numper in Range(0,7) & pointer is available value check port NB*/
	else
	{
		switch(COPY_enuPortID)
		{
		/*if user enterd PortA check value want to set*/
		case  DIO_enuPORTA :
			/*hold pin value*/
			*COPY_pValue = GET_BIT(PINA , COPY_enuPinID);
			break ;
			/*if user enterd PortB check value want to set*/
		case  DIO_enuPORTB :
			*COPY_pValue = GET_BIT(PINB , COPY_enuPinID);
			break ;
			/*if user enterd PortC check value want to set*/
		case  DIO_enuPORTC :
			*COPY_pValue = GET_BIT(PINC , COPY_enuPinID);
			break ;
			/*if user enterd PortAD check value want to set*/
		case  DIO_enuPORTD :
			*COPY_pValue = GET_BIT(PIND , COPY_enuPinID);
			break ;
			/*if user entered Port NB else. set error variable*/
		default :
			LOC_u8Err = 1;
		}
	}
	/*Return error value*/
	return LOC_u8Err ;
}

/*******************************************************************
 * SET Port DIRECTION
 * INPUT : PORT NUMBER & VALUE TO SET Potr DDIRECTION
 * OUTPUT : ERROT STATE
 ******************************************************************/
u8 DIO_u8SetPortDirection
(
		DIO_tenuPORTID COPY_enuPortID ,//Port NB
		u8 COPY_u8PortDirection////Set port Direction (input / output)
)
{
	/*Error variable to indicate if error occurs or not */
	u8 LOC_u8Err = 0;

	switch (COPY_enuPortID)
	{
	/*if user enterd PortA check value want to set*/
	case DIO_enuPORTA :
		DDRA = COPY_u8PortDirection ;
		break ;
		/*if user enterd PortB check value want to set*/
	case DIO_enuPORTB :
		DDRB = COPY_u8PortDirection ;
		break ;
		/*if user enterd PortC check value want to set*/
	case DIO_enuPORTC :
		DDRC = COPY_u8PortDirection ;
		break ;
		/*if user enterd PortD check value want to set*/
	case DIO_enuPORTD :
		DDRD = COPY_u8PortDirection ;
		break ;
		/*if user entered Port NB else. set error variable*/
	default :
		LOC_u8Err = 1 ;
	}
	/*Return error value*/
	return LOC_u8Err ;
}

/****************************************************************
 * SET PORT VALUE
 * INPUT : PORT NUMBER & VALUE TO SET PIN VALUE
 * OUTPUT : ERROT STATE
 ***************************************************************/
u8 DIO_u8SetPortValue
(
		DIO_tenuPORTID COPY_enuPortID ,//Port NB
		u8 COPY_u8PortValue//Set Port with High or Low Value
)
{
	/*Error variable to indicate if error occurs or not */
	u8 LOC_u8Err = 0;


	switch (COPY_enuPortID)
	{
		/*if user enterd PortA check value want to set*/
	case DIO_enuPORTA :

		PORTA = COPY_u8PortValue ;
		break ;
		/*if user enterd PortB check value want to set*/
	case DIO_enuPORTB :
		PORTB = COPY_u8PortValue ;
		break ;
		/*if user enterd PortC check value want to set*/
	case DIO_enuPORTC :
		PORTC = COPY_u8PortValue ;
		break ;
		/*if user enterd PortD check value want to set*/
	case DIO_enuPORTD :
		PORTD = COPY_u8PortValue ;
		break ;
		/*if user entered Port NB else. set error variable*/
	default :
		LOC_u8Err = 1 ;
	}
	/*Return error value*/
	return LOC_u8Err ;
}

/**************************************************
 * GET PORT VALUE
 * INPUT : PORT NUMBER & POINTER TO THE VALUE
 * OUTPUT : ERROT STATE
 ************************************************/
u8 DIO_u8GetPortValue
(
		DIO_tenuPORTID COPY_enuPORTID ,//Port NB
		u8* COPY_pu8PortValue//Pointer to save Port value
)
{
	/*Error variable to indicate if error occurs or not */
	u8 LOC_u8Err = 0;

	/*check if pointer equal NULL*/
	if(COPY_pu8PortValue == Null)
	{
		/*if pointer is equal to NULL set error variable*/
		LOC_u8Err = 1;
	}
	/*if pointer is available value check port NB*/
	else
	{
		switch(COPY_enuPORTID)
		{
			/*if user enterd PortA check value want to set*/
		case DIO_enuPORTA :
			/*Hold Port Value*/
			*COPY_pu8PortValue = PINA ;
			break ;
			/*if user enterd PortB check value want to set*/
		case DIO_enuPORTB :
			/*Hold Port Value*/
			*COPY_pu8PortValue = PINB ;
			break ;
			/*if user enterd PortC check value want to set*/
		case DIO_enuPORTC :
			/*Hold Port Value*/
			*COPY_pu8PortValue = PINC ;
			break ;
			/*if user enterd PortD check value want to set*/
		case DIO_enuPORTD :
			/*Hold Port Value*/
			*COPY_pu8PortValue = PIND ;
			break ;
			/*if user entered Port NB else. set error variable*/
		default :
			LOC_u8Err = 1;
		}
	}
	/*Return error value*/
	return LOC_u8Err ;
}
