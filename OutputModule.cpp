/*******************************************************************
*
*  DESCRIPTION: Atomic Model OutputModule
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
#include "OutputModule.h"      // class OutputModule
#include "message.h"    // class ExternalMessage, InternalMessage
#include "mainsimu.h"   // MainSimulator::Instance().getParameter( ... )

/** public functions **/

/*******************************************************************
* Function Name: OutputModule
* Description: 
********************************************************************/
OutputModule::OutputModule( const string &name )
: Atomic( name )
, inc( addInputPort( "inc" ) )
, dec( addInputPort( "dec" ) )
, stp( addInputPort( "stp" ) )
, out( addOutputPort( "out" ) )
, incTime( 0, 0, 0, 10 )
, decTime( 0, 0, 0, 15 )
, stpTime( 0, 0, 0, 20 )
{
	string time( MainSimulator::Instance().getParameter( description(), "incTime" ) ) ;
	if( time != "" )
		incTime = time ;
	string time1( MainSimulator::Instance().getParameter( description(), "decTime" ) ) ;
	if( time1 != "" )
		decTime = time1 ;
	string time2( MainSimulator::Instance().getParameter( description(), "stpTime" ) ) ;
	if( time2 != "" )
		stpTime = time2;

}

/*******************************************************************
* Function Name: initFunction
* Description: Initializes the current function parameters
********************************************************************/
Model &OutputModule::initFunction()
{
	outType = -2;	
	return *this ;
}

/*******************************************************************
* Function Name: externalFunction
* Description: response to the receptions of external event 
********************************************************************/
Model &OutputModule::externalFunction( const ExternalMessage &msg )
{
	if( msg.port() == inc )
	{		
		holdIn( active, incTime );
		outType = 1;
	}
	if( msg.port() == dec )
	{
		holdIn( active, decTime );
		outType = -1;
	}
	if( msg.port() == stp )
	{
		holdIn( active, stpTime );
		outType = 0;
	}
	return *this;
}

/*******************************************************************
* Function Name: internalFunction
* Description: invoked after the end of external function to do internal transition 
********************************************************************/
Model &OutputModule::internalFunction( const InternalMessage & )
{
	passivate();
	return *this ;
}

/*******************************************************************
* Function Name: outputFunction
* Description: performs the output function
********************************************************************/
Model &OutputModule::outputFunction( const InternalMessage &msg )
{
	sendOutput( msg.time(), out, outType) ;
	return *this ;
}
