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

#ifndef __DECREASE_H
#define __DECREASE_H

#include "atomic.h"     // class Atomic

class Decrease : public Atomic
{
public:
	Decrease( const string &name = "Decrease" ); //Default constructor

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

};	// class Decrease

// ** inline ** // 
inline
string Decrease::className() const
{
	return "Decrease" ;
}

#endif   //__DECREASE_H
