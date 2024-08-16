/*
#ifndef RUNACTION_HH
#define RUNACTION_HH
*/

#ifndef RUNACT_h
#define RUNACT_h 1

#include "G4UserRunAction.hh"



class G4Run;

class RunAction : public G4UserRunAction
{
public:
    RunAction();
    virtual ~RunAction() override;

    virtual void BeginOfRunAction(const G4Run *) override;
    virtual void EndOfRunAction(const G4Run *) override;
};

#endif
