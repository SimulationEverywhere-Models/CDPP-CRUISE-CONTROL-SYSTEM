/*******************************************************************
*
*  DESCRIPTION: Simulator::registerNewAtomics()
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

#include "modeladm.h" 
#include "mainsimu.h"
#include "queue.h"      // class Queue

#include "BreakController.h"
#include "PedalController.h" 
#include "OutputModule.h"
#include "ButtonInputModule.h"
#include "CCSController.h"
#include "ONOFFController.h"
#include "Set.h"
#include "Resume.h"
#include "Increase.h"
#include "Decrease.h"

void MainSimulator::registerNewAtomics()
{
	SingleModelAdm::Instance().registerAtomic( NewAtomicFunction<Increase>() ,"Increase" ) ;
	SingleModelAdm::Instance().registerAtomic( NewAtomicFunction<Decrease>() ,"Decrease" ) ;
	SingleModelAdm::Instance().registerAtomic( NewAtomicFunction<Resume>() ,"Resume" ) ;
	SingleModelAdm::Instance().registerAtomic( NewAtomicFunction<Set>() ,"Set" ) ;
	SingleModelAdm::Instance().registerAtomic( NewAtomicFunction<CCSController>() ,"CCSController" ) ;
	SingleModelAdm::Instance().registerAtomic( NewAtomicFunction<ONOFFController>() , "ONOFFController" ) ;
	SingleModelAdm::Instance().registerAtomic( NewAtomicFunction<ButtonInputModule>() , "ButtonInputModule" ) ;
	SingleModelAdm::Instance().registerAtomic( NewAtomicFunction<OutputModule>() , "OutputModule" ) ;
	SingleModelAdm::Instance().registerAtomic( NewAtomicFunction<BreakController>() , "BreakController" ) ;
	SingleModelAdm::Instance().registerAtomic( NewAtomicFunction<PedalController>() , "PedalController" ) ;
	SingleModelAdm::Instance().registerAtomic( NewAtomicFunction<Queue>() , "Queue" ) ;
}
