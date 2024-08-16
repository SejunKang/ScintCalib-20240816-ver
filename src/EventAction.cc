
#include <ctime>
#include "EventAction.hh"
#include "G4Event.hh"
#include "G4SystemOfUnits.hh"
#include "Randomize.hh"
#include "G4CsvAnalysisManager.hh"
#include "G4ParticleDefinition.hh"
EventAction::EventAction()
{
// Initialize
	m_NScint = 0;
	m_NCeren = 0;
    m_NOp    = 0;
    m_DeltaE = 0;

    m_PName  = "";
    m_KEi    = 0;
    m_PFound = false;
}

EventAction::~EventAction()
{
}

void EventAction::BeginOfEventAction(const G4Event *)
{
// Initialize
	m_NScint = 0;
	m_NCeren = 0;
    m_NOp    = 0;
    m_DeltaE = 0;

    m_PName  = "";
    m_KEi    = 0;
    m_PFound = false;
}

void EventAction::EndOfEventAction(const G4Event *anEvent)
{
    auto AM = G4CsvAnalysisManager::Instance();
    AM -> FillNtupleIColumn(1, 0, anEvent -> GetEventID());
    AM -> FillNtupleSColumn(1, 1, m_PName);
    AM -> FillNtupleDColumn(1, 2, m_KEi);
    AM -> FillNtupleDColumn(1, 3, m_DeltaE);
    AM -> FillNtupleIColumn(1, 4, m_NOp);
    AM -> AddNtupleRow(1);
}


void EventAction::AddScint()
{
	m_NScint++;
}

void EventAction::AddCeren()
{
	m_NCeren++;
}


void EventAction::SetPrimaryName(G4String pname)
{
	m_PName = pname;
}

void EventAction::SetPrimaryEnergy(G4double kei)
{
	m_KEi = kei;
}

void EventAction::SetPrimaryFound()
{
	m_PFound = true;
}

G4bool EventAction::GetPrimaryFound()
{
    return m_PFound;
}


void EventAction::AddOp()
{
	m_NOp++;
}

void EventAction::AddDeltaE(G4double dE)
{
	m_DeltaE += dE;
}



