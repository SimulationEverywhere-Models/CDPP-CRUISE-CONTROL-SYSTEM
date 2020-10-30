/*******************************************************************
*
*  DESCRIPTION: Atomic Model CCSController
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
#include "CCSController.h"      // class CCSController
#include "message.h"    // class ExternalMessage, InternalMessage
#include "mainsimu.h"   // MainSimulator::Instance().getParameter( ... )

/** public functions **/

/*******************************************************************
* Function Name: CCSController
* Description: 
********************************************************************/
CCSController::CCSController( const string &name )
: Atomic( name )
, in_TURNEDON( addInputPort( "in_TURNEDON") )
, in_TURNEDOFF( addInputPort( "in_TURNEDOFF") )
, in_DEC( addInputPort( "in_DEC") )
, in_INC( addInputPort( "in_INC") )
, in_SET( addInputPort( "in_SET") )
, in_RESUME( addInputPort( "in_RESUME") )
, in_BREAK( addInputPort( "in_BREAK") )
, in_GAS( addInputPort( "in_GAS") )
, in_SPEED( addInputPort( "in_SPEED") )
, out_INC( addOutputPort( "out_INC") )
, out_DEC( addOutputPort( "out_DEC") )
, out_STOP( addOutputPort( "out_STOP") )
, preparationTime( 0, 0, 0, 15 )
{
	string time( MainSimulator::Instance().getParameter( description(), "preparation" ) ) ;
	if( time != "" )
		preparationTime = time ;
}

/*******************************************************************
* Function Name: initFunction
* Description: Initializes the current function parameters
********************************************************************/
Model &CCSController::initFunction()
{
	flag=0;
 	GlobalState=inactive; //system off
	setSpeed=0;
	currentSpeed=0;
	
return *this ;
	
}

/*******************************************************************
* Function Name: externalFunction
* Description: response to the receptions of external event 
********************************************************************/
Model &CCSController::externalFunction( const ExternalMessage &msg )
{
	if( msg.port() == in_SPEED )
	{ 	
		currentSpeed=(int)msg.value();
		if((GlobalState==standBy)&& (currentSpeed<=setSpeed))
		{
		  GlobalState=CCSActive;	
		}
	}else if ( msg.port() == in_TURNEDON )
	{ 	
		if(GlobalState==inactive)
		{
		 GlobalState=idle;
		}	
	}else if( msg.port() == in_SET )
	{ 	if(GlobalState==idle||GlobalState==onHold||GlobalState==standBy)
		{
		 GlobalState=CCSActive;	
		 setSpeed =currentSpeed;
		}	
	}else if( msg.port() == in_INC )
	{ 	if(GlobalState==CCSActive)
		{ 
		 setSpeed +=1;	
		}
	}else if( msg.port() == in_DEC )
	{ 	
		if(GlobalState==CCSActive)
		{ 
		 setSpeed -=1;	
		}

	}else if( msg.port() == in_RESUME )
	{ 	
		if(GlobalState==onHold)
		{ 
		 GlobalState=CCSActive;	
		}
	}else if( msg.port() == in_BREAK )
	{ 	
		if(GlobalState==CCSActive||GlobalState==standBy)
		{
		 GlobalState=onHold;	
		 }	
	}else if( msg.port() == in_GAS )
	{ 	if(GlobalState==CCSActive)
		{
		 GlobalState=standBy;	
		}	
	}else if( msg.port() == in_TURNEDOFF )
	{ 	GlobalState=inactive;
	}
	holdIn( active, preparationTime );
	return *this;
}

/*******************************************************************
* Function Name: internalFunction
* Description: invoked after the end of external function to do internal transition 
********************************************************************/
Model &CCSController::internalFunction( const InternalMessage & )
{
	passivate();
	return *this ;
}

/*******************************************************************
* Function Name: outputFunction
* Description: performs the output function
********************************************************************/
Model &CCSController::outputFunction( const InternalMessage &msg )
{
	if(GlobalState==CCSActive)
	{
	  if(currentSpeed<setSpeed)	
             sendOutput( msg.time(), out_INC, 1 ) ;	
	  else if(currentSpeed>setSpeed)
             sendOutput( msg.time(), out_DEC, 1 ) ;	
	flag=1;	
	}else if(flag==1) {
	  sendOutput( msg.time(), out_STOP, 1 ) ;	
	flag=0;	
	}

	return *this ;
}
