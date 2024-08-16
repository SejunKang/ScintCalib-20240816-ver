/*
#ifndef EVENTACTION_HH
#define EVENTACTION_HH
*/

#ifndef EVEACT_h
#define EVEACT_h 1

#include "G4UserEventAction.hh"
#include "G4Types.hh"
#include "globals.hh"
class EventAction : public G4UserEventAction
{
public:
    EventAction();
    virtual ~EventAction();

    virtual void BeginOfEventAction(const G4Event *) override;
    virtual void EndOfEventAction(const G4Event *) override;

    void AddScint();
	void AddCeren();

    // Figure out who the primary is
    void SetPrimaryName(G4String pname);
    void SetPrimaryEnergy(G4double kei);
    void SetPrimaryFound();
    G4bool GetPrimaryFound();

    // Collect dEdx
    void AddOp();
    void AddDeltaE(G4double dE);

  private:
	G4int m_NScint;
	G4int m_NCeren;

    G4String m_PName;
    G4double m_KEi;
    G4bool m_PFound;

    G4int m_NOp;
    G4double m_DeltaE;

G4int fHCID;
};

#endif // EVENTACTION_HH
