/*******************************************************************
*
*  DESCRIPTION: Atomic Model Resume
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

#ifndef __RESUME_H
#define __RESUME_H

#include "atomic.h"     // class Atomic

class Resume : public Atomic
{
public:
	Resume( const string &name = "Resume" ); //Default constructor

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

};	// class Resume

// ** inline ** // 
inline
string Resume::className() const
{
	return "Resume" ;
}

#endif   //__RESUME_H
