void photoncounting()
{
//Processing QE Graph ------------------------------------------------

double x[72] = {5, 5, 4.76 , 4.71 , 4.66 , 4.6 , 4.55 , 4.51 , 4.46 , 4.41 , 4.37 , 4.3 , 4.23 , 4.17 , 4.05 , 3.92 , 3.76 , 3.62 , 3.47 , 3.34 , 3.24 , 3.13 , 3.03 , 2.92 , 2.83 , 2.74 , 2.67 , 2.6 , 2.53 , 2.47 , 2.41 , 2.37 , 2.34 , 2.31 , 2.29 , 2.27 , 2.23 , 2.21 , 2.18 , 2.14 , 2.11 , 2.08 , 2.06 , 2.04 , 2.02 , 2.01 , 1.99 , 1.98 , 1.97 , 1.96 , 1.95 , 1.94 , 1.93 , 1.92 , 1.9 , 1.9 , 1.88 , 1.87 , 1.87 , 1.86 , 1.85 , 1.84 , 1.83 , 1.83 , 1.82 , 1.81 , 1.8 , 1.79 , 1.79 , 1.78 , 1.77, 1.77
};
double y[72] = {0, 0, 2.08 , 2.48 , 2.95 , 3.51 , 4.25 , 5.15 , 6.35 , 7.7 , 9.33 , 11.1 , 13.22 , 15.47 , 18.1 , 20.45 , 22.7 , 24.34 , 25.65 , 26.1 , 26.1 , 25.65 , 25.21 , 24.34 , 23.51 , 21.92 , 19.74 , 18.1 , 16.58 , 15.47 , 13.69 , 12.33 , 10.72 , 9.33 , 8.25 , 6.93 , 6.03 , 5.34 , 4.56 , 3.97 , 3.39 , 2.9 , 2.52 , 2.19 , 1.84 , 1.57 , 1.35 , 1.15 , 0.98 , 0.87 , 0.77 , 0.67 , 0.59 , 0.51 , 0.43 , 0.36 , 0.31 , 0.26 , 0.22 , 0.18 , 0.15 , 0.13 , 0.11 , 0.09 , 0.07 , 0.06 , 0.05 , 0.04 , 0.04 , 0.03 , 0, 0
};

TGraph *gr = new TGraph(72, x, y);

gr->SetTitle("Energy vs QE;Energy (eV);QE (%)");
gr->SetMarkerStyle(8);
gr->SetMarkerSize(1);
gr->SetMarkerColor(kBlack);

TCanvas *c1 = new TCanvas();
c1->SetFillColor(21);
gr->Draw("AP");

TLatex *lat = new TLatex(2.6, 5, "Average QE = 7.53514%");
lat->Draw();

//Splining ---------------------------------------------------------

auto smooth = new TGraphSmooth("normal");
TGraph *sm = smooth->SmoothKern(gr, "normal");

//Quintic spline after graph smoothing gives the best result.

auto spline = new TSpline5("spline", gr);
spline -> SetLineColor(kRed);
spline -> SetLineWidth(2);
spline -> Draw("same");

auto legend = new TLegend(0.7,0.8,0.9,0.9);
legend->AddEntry(gr, "QE", "lp");
legend->AddEntry(spline, "Spline Curve", "lp");
legend->SetFillColor(21);
legend->Draw();

//Reading Geant4 Results --------------------------------------------

std::vector<double> x_ms;
std::vector<double> y_ms;

fstream file;
file.open("numbers_nt_num.csv", ios::in);
double value;
while(1)
{
std::string line;
while (std::getline(file, line)){
std::stringstream sts(line);
if (sts >> value){
x_ms.push_back(value);}
}
if(file.eof()) break;
}

//Calculating Photon Number -----------------------------------------

for (double x_m : x_ms)
{double y_m = spline -> Eval(x_m);
if (0 <= y_m && y_m <= 26.1){
y_ms.push_back(y_m);
}
else y_ms.push_back(0.0);
}
auto sum = std::accumulate(std::begin(y_ms), std::end(y_ms), 0.0);
auto per = sum / x_ms.size();
std::cout << "photon number with QE = " << (sum / 100) / 1000 << std::endl;
std::cout << "photon number without QE = " << x_ms.size() / 1000 << std::endl;
std::cout << "ratio = " << per << "%" << std::endl;
}
