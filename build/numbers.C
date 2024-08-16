void numbers()
{
fstream file;
file.open("numbers_nt_event.csv", ios::in);
std::vector<double> m_y;
double y;

std::string line;
while (std::getline(file, line)){
std::stringstream sts(line);

std::string a, b, c, d, e;
if (std::getline(sts, a, ',') && std::getline(sts, b, ',') && std::getline(sts, c, ',') && std::getline(sts, d, ',') && std::getline(sts, e, ','))
{
y = std::stod(e);
m_y.push_back(y);
}
if(file.eof()) break;
}
file.close();

TH1F *hs = new TH1F("hist","Photon Number Distribution (X-ray only)",100, 0, 200);

for (double y : m_y){
hs -> Fill(y);
}
TCanvas *c1 = new TCanvas();
hs-> GetXaxis() -> SetTitle("Photon Number");
hs-> GetYaxis() -> SetTitle("Number of Entries");
hs->SetFillColor(42);
hs->Draw();
}
