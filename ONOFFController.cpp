/*******************************************************************
*
*  DESCRIPTION: Atomic Model ONOFFController
*
*  AUTHOR: Christy Gnanapragasam  Vijay Mahendran Sivaharan Thurairasa 
*
*  EMAIL: christy@sce.carleton.ca
*         vijay@sce.carleton.ca
*	  sthurair@sce.carleton.ca
*
*  DATE: 19/10/2003
*
*******************************************************************/

/** include files **/
#include "ONOFFController.h"      // class ONOFFController
#include "message.h"    // class ExternalMessage, InternalMessage
#include "mainsimu.h"   // MainSimulator::Instance().getParameter( ... )

/** public functions **/

/*******************************************************************
* Function Name: ONOFFController
* Description: 
********************************************************************/
ONOFFController::ONOFFController( const string &name )
: Atomic( name )
, inON( addInputPort( "inON" ) )
, inOFF( addInputPort( "inOFF" ) )
, outON( addInputPort( "outON" ) )
, outOFF( addOutputPort( "outOFF" ) )
, preparationTime( 0, 0, 0, 010 )
{
	string time( MainSimulator::Instance().getParameter( description(), "preparation" ) ) ;

	if( time != "" )
		preparationTime = time ;

}

/*******************************************************************
* Function Name: initFunction
* Description: Initializes the current function parameters
********************************************************************/
Model &ONOFFController::initFunction()
{
	localState = OFF;
	flag = 0; // no need for output
	return *this ;
}

/*******************************************************************
* Function Name: externalFunction
* Description: response to the receptions of external event 
********************************************************************/
Model &ONOFFController::externalFunction( const ExternalMessage &msg )
{
	if (state() == passive) {
	if( msg.port() == inON )
	{		
		if(localState == OFF)
		{
			localState = ON;
			flag = 1;
			holdIn( active, preparationTime );
		}
	}
	if( msg.port() == inOFF )
	{
		if(localState == ON)
		{
			localState = OFF;
			flag = 1;
			holdIn( active, preparationTime );
		}
	}
	}
	return *this;
}

/*******************************************************************
* Function Name: internalFunction
* Description: invoked after the end of external function to do internal transition 
********************************************************************/
Model &ONOFFController::internalFunction( const InternalMessage & )
{
	passivate();
	return *this ;
}

/*******************************************************************
* Function Name: outputFunction
* Description: performs the output function
********************************************************************/
Model &ONOFFController::outputFunction( const InternalMessage &msg )
{
	if (flag == 1) {
		if (localState == OFF)
			sendOutput( msg.time(), outOFF, 1 ) ;
		else
			sendOutput( msg.time(), outON, 1 ) ;			
		flag = 0;
	}

return *this ;
}
