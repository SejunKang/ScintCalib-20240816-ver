#include <ctime>
#include "G4RunManager.hh"
#include "G4Run.hh"
#include "RunAction.hh"
#include "G4CsvAnalysisManager.hh"
RunAction::RunAction()
    : G4UserRunAction()
{
/*auto analysisManager = G4AnalysisManager::Instance();
analysisManager->OpenFile("g4_minimal.csv");
analysisManager->CreateNtuple("EDep", "Enaergy Deposition");
analysisManager->CreateNtupleDColumn("EDep");
analysisManager->FinishNtuple();*/
}

RunAction::~RunAction()
{
}

void RunAction::BeginOfRunAction(const G4Run*)
{
auto AM = G4CsvAnalysisManager::Instance();
	AM -> SetVerboseLevel(0);

    AM -> CreateNtuple("num", "num");
    AM -> CreateNtupleDColumn(0, "num");
    AM -> FinishNtuple(0);
    AM -> OpenFile("numbers.csv");

    AM -> CreateNtuple("event", "Event-based MC truth info");
    AM -> CreateNtupleIColumn("eid"); // Event ID
    AM -> CreateNtupleSColumn("pname"); // Initial condition: what primary particle is
    AM -> CreateNtupleDColumn("Ei" ); // Initial condition: Initial kinetic of the primary
    AM -> CreateNtupleDColumn("dE" ); // Result: Energy deposit in scint
    AM -> CreateNtupleIColumn("N"  ); // Result: Number of optical photons generated
    AM -> FinishNtuple(1);
    AM -> OpenFile("event.csv");
}


void RunAction::EndOfRunAction(const G4Run*)
{
    auto AM = G4CsvAnalysisManager::Instance();
    AM -> Write();
    AM -> CloseFile();
}


