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

#ifndef __OUTPUTMODULE_H
#define __OUTPUTMODULE_H

#include "atomic.h"     // class Atomic

class OutputModule : public Atomic
{
public:
	OutputModule( const string &name = "OutputModule" ); //Default constructor

	virtual string className() const ;
protected:
	Model &initFunction();
	Model &externalFunction( const ExternalMessage & );
	Model &internalFunction( const InternalMessage & );
	Model &outputFunction( const InternalMessage & );

private:
	const Port &inc;
	const Port &dec;
	const Port &stp;
	Port &out;
	Time incTime;
	Time decTime;
	Time stpTime;
	int outType;

};	// class OutputModule

// ** inline ** // 
inline
string OutputModule::className() const
{
	return "OutputModule" ;
}

#endif   //__OUTPUTMODULE_H
