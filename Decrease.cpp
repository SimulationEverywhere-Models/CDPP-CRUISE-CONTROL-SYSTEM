/*******************************************************************
*
*  DESCRIPTION: Atomic Model Decrease
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
#include "Decrease.h"      // class Decrease
#include "message.h"    // class ExternalMessage, InternalMessage
#include "mainsimu.h"   // MainSimulator::Instance().getParameter( ... )

/** public functions **/

/*******************************************************************
* Function Name: Decrease
* Description: 
********************************************************************/
Decrease::Decrease( const string &name )
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
Model &Decrease::initFunction()
{
	return *this ;
}

/*******************************************************************
* Function Name: externalFunction
* Description: response to the receptions of external event 
********************************************************************/
Model &Decrease::externalFunction( const ExternalMessage &msg )
{
	if(state()==passive)
	{
		if( msg.port() == in )
		{
			holdIn( active, preparationTime );
		}
	}
	return *this;
}

/*******************************************************************
* Function Name: internalFunction
* Description: invoked after the end of external function to do internal transition 
********************************************************************/
Model &Decrease::internalFunction( const InternalMessage & )
{
	passivate();
	return *this ;
}

/*******************************************************************
* Function Name: outputFunction
* Description: performs the output function
********************************************************************/
Model &Decrease::outputFunction( const InternalMessage &msg )
{
	sendOutput( msg.time(), out, 1 ) ;
	return *this ;
}
