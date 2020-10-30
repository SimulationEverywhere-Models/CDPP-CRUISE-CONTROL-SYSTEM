/*******************************************************************
*
*  DESCRIPTION: Atomic Model BreakController
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
#include "BreakController.h"      // class BreakController
#include "message.h"    // class ExternalMessage, InternalMessage
#include "mainsimu.h"   // MainSimulator::Instance().getParameter( ... )

/** public functions **/

/*******************************************************************
* Function Name: BreakController
* Description: 
********************************************************************/
BreakController::BreakController( const string &name )
: Atomic( name )
, in( addInputPort( "in" ) )
, out( addOutputPort( "out" ) )
, preparationTime( 0, 0, 0, 10 )
{
	string time( MainSimulator::Instance().getParameter( description(), "preparation" ) ) ;

	if( time != "" )
		preparationTime = time ;
}

/*******************************************************************
* Function Name: initFunction
* Description: Initializes the current function parameters
********************************************************************/
Model &BreakController::initFunction()
{
	return *this ;
}

/*******************************************************************
* Function Name: externalFunction
* Description: response to the receptions of external event 
********************************************************************/
Model &BreakController::externalFunction( const ExternalMessage &msg )
{
	if( msg.port() == in )
	{
		holdIn( active, preparationTime );
	}
	return *this;
}

/*******************************************************************
* Function Name: internalFunction
* Description: invoked after the end of external function to do internal transition 
********************************************************************/
Model &BreakController::internalFunction( const InternalMessage & )
{
	passivate();
	return *this ;
}

/*******************************************************************
* Function Name: outputFunction
* Description: performs the output function
********************************************************************/
Model &BreakController::outputFunction( const InternalMessage &msg )
{
	sendOutput( msg.time(), out, 1 ) ;
	return *this ;
}
