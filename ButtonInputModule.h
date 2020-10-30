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

#ifndef __BUTTONINPUTMODULE_H
#define __BUTTONINPUTMODULE_H

#include "atomic.h"     // class Atomic

class ButtonInputModule : public Atomic
{
public:
	ButtonInputModule( const string &name = "ButtonInputModule" ); //Default constructor

	virtual string className() const ;
protected:
	Model &initFunction();
	Model &externalFunction( const ExternalMessage & );
	Model &internalFunction( const InternalMessage & );
	Model &outputFunction( const InternalMessage & );

private:
	const Port &in_BUTTON;
	Port &out_ON, &out_OFF, &out_SET, &out_ACC, &out_DEC, &out_RESUME;
	Time preparationTime;

	int outType;
};	// class ButtonInputModule

// ** inline ** // 
inline
string ButtonInputModule::className() const
{
	return "ButtonInputModule" ;
}

#endif   //__BUTTONINPUTMODULE_H
