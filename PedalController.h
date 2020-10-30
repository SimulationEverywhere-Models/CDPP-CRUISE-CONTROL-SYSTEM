/*******************************************************************
*
*  DESCRIPTION: Atomic Model PedalController
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

#ifndef __PEDALCONTROLLER_H
#define __PEDALCONTROLLER_H

#include "atomic.h"     // class Atomic

class PedalController : public Atomic
{
public:
	PedalController( const string &name = "PedalController" ); //Default constructor

	virtual string className() const ;
protected:
	Model &initFunction();
	Model &externalFunction( const ExternalMessage & );
	Model &internalFunction( const InternalMessage & );
	Model &outputFunction( const InternalMessage & );

private:
	const Port &in;
	Port &out;
	Time preparationTime;

};	// class PedalController

// ** inline ** // 
inline
string PedalController::className() const
{
	return "PedalController" ;
}

#endif   //__PEDALCONTROLLER_H
