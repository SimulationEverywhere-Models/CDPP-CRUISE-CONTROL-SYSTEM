/*******************************************************************
*
*  DESCRIPTION: Atomic Model ButtonInputModule
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
#include "ButtonInputModule.h"      // class ButtonInputModule
#include "message.h"    // class ExternalMessage, InternalMessage
#include "mainsimu.h"   // MainSimulator::Instance().getParameter( ... )

/** public functions **/

/*******************************************************************
* Function Name: ButtonInputModule
* Description: 
********************************************************************/
ButtonInputModule::ButtonInputModule( const string &name )
: Atomic( name )
, in_BUTTON( addInputPort( "in_BUTTON") )
, out_ON( addOutputPort( "out_ON") )
, out_OFF( addOutputPort( "out_OFF") )
, out_SET( addOutputPort( "out_SET") )
, out_ACC( addOutputPort( "out_ACC") )
, out_DEC( addOutputPort( "out_DEC") )
, out_RESUME( addOutputPort( "out_RESUME") )
, preparationTime( 0, 0, 0, 15 )
{
	string time( MainSimulator::Instance().getParameter( description(), "preparation" ) ) ;
	outType=0;
	if( time != "" )
		preparationTime = time ;
}

/*******************************************************************
* Function Name: initFunction
* Description: Initializes the current function parameters
********************************************************************/
Model &ButtonInputModule::initFunction()
{
	return *this ;
}

/*******************************************************************
* Function Name: externalFunction
* Description: response to the receptions of external event 
********************************************************************/
Model &ButtonInputModule::externalFunction( const ExternalMessage &msg )
{
	if( msg.port() == in_BUTTON )
	{ 	
		outType=(int)msg.value();
		holdIn( active, preparationTime );
	}
	return *this;
}

/*******************************************************************
* Function Name: internalFunction
* Description: invoked after the end of external function to do internal transition 
********************************************************************/
Model &ButtonInputModule::internalFunction( const InternalMessage & )
{
	passivate();
	return *this ;
}

/*******************************************************************
* Function Name: outputFunction
* Description: performs the output function
********************************************************************/
Model &ButtonInputModule::outputFunction( const InternalMessage &msg )
{
	switch(outType)
	{
		case 1: //take action
		 {
			sendOutput( msg.time(), out_ON, 1 ) ;	
			break;
		 }
		case 2: //take action
		 {
			sendOutput( msg.time(), out_OFF, 1 ) ;	
			break;
		 }
		case 3: //take action
		 {
			sendOutput( msg.time(), out_SET, 1 ) ;	
			break;
		 }
		case 4: //take action
		 {
			sendOutput( msg.time(), out_ACC, 1 ) ;	
			break;
		 }
		case 5: //take action
		 {
			sendOutput( msg.time(), out_DEC, 1 ) ;	
			break;
		 }	
		case 6: //take action
		 {
			sendOutput( msg.time(), out_RESUME, 1 ) ;	
			break;
		 }
		default: //do this
		break;
	}
	return *this ;
}
