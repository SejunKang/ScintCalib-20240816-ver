#include "G4SystemOfUnits.hh"
#include "G4ParticleGun.hh"
#include "G4Gamma.hh"
#include "G4Electron.hh"
#include "G4Geantino.hh"
#include "PrimaryGeneratorAction.hh"
#include "G4RandomTools.hh"
#include "G4IonTable.hh"
PrimaryGeneratorAction::PrimaryGeneratorAction()
    : G4VUserPrimaryGeneratorAction()
{
    fPrimary = new G4ParticleGun();
    
}

PrimaryGeneratorAction::~PrimaryGeneratorAction()
{
    delete fPrimary;
}
void PrimaryGeneratorAction::GeneratePrimaries(G4Event *anEvent)
{
   // G4ParticleTable *particletable = G4ParticleTable::GetParticleTable();
  //  G4ParticleDefinition *particle = particletable -> FindParticle("geantino");

  /* if(particle == G4Geantino::Geantino())
    {
    G4ParticleDefinition* ion =  G4IonTable::GetIonTable()->GetIon(48, 109, 0.); */
    fPrimary->SetParticleDefinition(G4Gamma::Definition());
    fPrimary->SetParticleEnergy(22.*keV);
    fPrimary->SetParticleCharge(0. *eplus);
    fPrimary->SetParticlePosition(G4ThreeVector(0., 65*cm, -2.5 *cm));
    //momentum distribution ===============================
    fPrimary->SetParticleMomentumDirection(G4RandomDirection(0.7));
    fPrimary->GeneratePrimaryVertex(anEvent);
//}
}
