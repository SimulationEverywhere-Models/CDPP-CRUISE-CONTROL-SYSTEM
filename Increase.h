/*******************************************************************
*
*  DESCRIPTION: Atomic Model Increase
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
#ifndef __INCREASE_H
#define __INCREASE_H

#include "atomic.h"     // class Atomic

class Increase : public Atomic
{
public:
	Increase( const string &name = "Increase" ); //Default constructor

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

};	// class Increase

// ** inline ** // 
inline
string Increase::className() const
{
	return "Increase" ;
}

#endif   //__INCREASE_H
