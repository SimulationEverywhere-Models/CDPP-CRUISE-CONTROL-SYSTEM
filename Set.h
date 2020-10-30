/*******************************************************************
*
*  DESCRIPTION: Atomic Model Set
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

#ifndef __SET_H
#define __SET_H

#include "atomic.h"     // class Atomic

class Set : public Atomic
{
	public:
		Set( const string &name = "Set" ); //Default constructor

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

};	// class Set

// ** inline ** // 
inline
string Set::className() const
{
	return "Set" ;
}

#endif   //__SET_H
