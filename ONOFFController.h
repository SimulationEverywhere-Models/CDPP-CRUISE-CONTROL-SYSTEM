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

#ifndef __ONOFFCONTROLLER_H
#define __ONOFFCONTROLLER_H

#include "atomic.h"     // class Atomic

class ONOFFController : public Atomic
{
public:
	ONOFFController( const string &name = "ONOFFController" ); //Default constructor

	virtual string className() const ;
protected:
	Model &initFunction();
	Model &externalFunction( const ExternalMessage & );
	Model &internalFunction( const InternalMessage & );
	Model &outputFunction( const InternalMessage & );

private:
	const Port &inON;
	const Port &inOFF;
	Port &outON;
	Port &outOFF;

	Time preparationTime;
	int localState;
        enum ONOFFState{ON, OFF};
	int flag;

};	// class ONOFFController

// ** inline ** // 
inline
string ONOFFController::className() const
{
	return "ONOFFController" ;
}

#endif   //__ONOFFCONTROLLER_H
