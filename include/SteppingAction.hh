/*
#ifndef STEPPINGACTION_h
#define STEPPINGACTION_h 1
*/

#ifndef STEACT_h
#define STEACT_h 1

#include "G4UserSteppingAction.hh"

#include "EventAction.hh"

class EventAction;

class SteppingAction: public G4UserSteppingAction
{
  public:
	SteppingAction(EventAction* EA);
	virtual ~SteppingAction();

	virtual void UserSteppingAction(const G4Step*);

  private:
	EventAction* m_EA;
};

#endif
