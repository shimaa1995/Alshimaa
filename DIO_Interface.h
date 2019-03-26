/*
 * DIO_Interface.h
 *
 *  Created on: Jan 21, 2019
 *      Author: Alshimaa
 */

#ifndef DIO_INTERFACE_H_
#define DIO_INTERFACE_H_
#define Null             0
#define u8MAX_PIN_NB     7//MAX NB OF PINS

/* PORTS*/
typedef enum
{
	DIO_enuPORTA = 0 ,
	DIO_enuPORTB ,
	DIO_enuPORTC ,
	DIO_enuPORTD
}DIO_tenuPORTID;

/*PINS*/
typedef enum
{
	DIO_enuPIN0 =0 ,
	DIO_enuPIN1 ,
	DIO_enuPIN2 ,
	DIO_enuPIN3 ,
	DIO_enuPIN4 ,
	DIO_enuPIN5 ,
	DIO_enuPIN6 ,
	DIO_enuPIN7 ,
}DIO_tenuPINID;

/*PINS DIRECTION*/
typedef enum
{
	DIO_enuINPUT = 0 ,
	DIO_enuOUTPUT
}DIO_tenuPinDirection;

/*PINS VALUE*/
typedef enum
{
	DIO_enuLOW = 0 ,
	DIO_enuHIGH
}DIO_tenuPinValue;

/* PIN FUNCTIONS PROTOTYPES*/

/*******************************************************************
 * SET PIN DIRECTION
 * INPUT : PORT NUMBER & PIN NUMBER &VALUE TO SET PIN DDIRECTION
 * OUTPUT : ERROT STATE
 ******************************************************************/
u8 DIO_SetPinDirection (
						 DIO_tenuPORTID COPY_enuPORTID ,//
						 DIO_tenuPINID COPY_enuPINID ,//
						 DIO_tenuPinDirection COPY_enuPinDirection//
						);

/****************************************************************
 * SET PIN VALUE
 * INPUT : PORT NUMBER & PIN NUMBER & VALUE TO SET PIN VALUE
 * OUTPUT : ERROT STATE
 ***************************************************************/
u8 DIO_u8SetPinValue(
						DIO_tenuPORTID COPY_enuPORTID ,
						DIO_tenuPINID COPY_enuPINID ,
						DIO_tenuPinValue COPY_enuPinValue
					);

/****************************************************************
 * GET PIN VALUE
 * INPUT : PORT NUMBER & PIN NUMBER &  POINTER TO THE VALUE
 * OUTPUT : ERROT STATE
 ***************************************************************/
u8 DIO_u8GetPinValue (
						DIO_tenuPORTID COPY_enuPortID ,
						DIO_tenuPINID COPY_enuPinID ,
						u8* COPY_pu8PinValue
					 );

/*PORTS FUNCTIONS PROTOTYPES */

/*******************************************************************
 * SET Port DIRECTION
 * INPUT : PORT NUMBER & VALUE TO SET Potr DDIRECTION
 * OUTPUT : ERROT STATE
 ******************************************************************/
u8 DIO_u8SetPortDirection (
							DIO_tenuPORTID COPY_enuPORTID ,
							u8 COPY_u8PortDirection
						  );

/****************************************************************
 * SET PORT VALUE
 * INPUT : PORT NUMBER & VALUE TO SET PIN VALUE
 * OUTPUT : ERROT STATE
 ***************************************************************/
u8 DIO_u8SetPortValue (
						  DIO_tenuPORTID COPY_enuPORTID ,
						  u8 COPY_u8PortValue
					  );

/**************************************************
 * GET PORT VALUE
 * INPUT : PORT NUMBER & POINTER TO THE VALUE
 * OUTPUT : ERROT STATE
 ************************************************/
u8 DIO_u8GetPortValue (
						  DIO_tenuPORTID COPY_enuPORTID ,
						  u8* COPY_pu8PortValue
					  );

#endif /* DIO_INTERFACE_H_ */
