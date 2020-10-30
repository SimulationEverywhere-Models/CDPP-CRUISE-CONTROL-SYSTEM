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

#ifndef __CCSCONTROLLER_H
#define __CCSCONTROLLER_H

#include "atomic.h"     // class Atomic

class CCSController : public Atomic
{
public:
	CCSController( const string &name = "CCSController" ); //Default constructor

	virtual string className() const ;
protected:
	Model &initFunction();
	Model &externalFunction( const ExternalMessage & );
	Model &internalFunction( const InternalMessage & );
	Model &outputFunction( const InternalMessage & );
	
private:
	const Port &in_TURNEDON,&in_TURNEDOFF,&in_DEC,&in_INC,&in_SET,&in_RESUME,&in_BREAK,	&in_GAS,&in_SPEED;
	Port &out_INC, &out_DEC, &out_STOP;
	Time preparationTime;

	int flag; 
	int GlobalState;
	int currentSpeed;
	int setSpeed;
	enum CCSState
	{
		inactive,  // system is off
		idle, 	   // system wait for set input	
		CCSActive,	   // system is active	
		standBy,   // system wait for previous speed and once it met go back to active
		onHold // system is OnHold (Break is pressed), and once resume pressed go to active
		
	} ;



};	// class CCSController

// ** inline ** // 
inline
string CCSController::className() const
{
	return "CCSController" ;
}

#endif   //__CCSCONTROLLER_H
