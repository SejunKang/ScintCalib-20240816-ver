/*
#ifndef ACTIONINITIALIZATION_HH
#define ACTIONINITIALIZATION_HH
*/
#ifndef ACTINI_h
#define ACTINI_h 1

#include "G4VUserActionInitialization.hh"
#include "RunAction.hh"
#include "G4String.hh"

class ActionInitialization : public G4VUserActionInitialization
{
public:
    ActionInitialization();
    virtual ~ActionInitialization() override;

    virtual void BuildForMaster() const override;
    virtual void Build() const override;
};

#endif
