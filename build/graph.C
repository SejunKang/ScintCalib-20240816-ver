void graph()
{
double x[14] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100, 110, 120, 130, 140};
double y1[14] = {7.23589,6.05177,5.45521,5.158,4.41827,4.17495,3.80551,3.37198,3.17235,3.02736,2.78481,2.55303,2.44797,2.25571};
double y2[14] = {31,26,23,22,19,18,16,14,13,13,12,11,10,9};

TGraph *gr1 = new TGraph(14, x, y1);
gr1->SetMarkerStyle(8);
gr1->SetMarkerColor(kBlue);
gr1->SetLineColor(kBlue);
gr1->SetLineWidth(2);

TGraph *gr2 = new TGraph(14, x, y2);
gr2->SetMarkerStyle(22);
gr2->SetMarkerSize(2);
gr2->SetMarkerColor(kRed);
gr2->SetLineColor(kRed);
gr2->SetLineWidth(2);


TCanvas *c1 = new TCanvas();
c1->SetFillColor(21);

TMultiGraph *mg = new TMultiGraph();
mg->Add(gr1);
mg->Add(gr2);
mg->Draw("ALPS");
mg->SetTitle("Photon Number vs Distance (X-ray only);Distance from PMT (cm);Photon Number");

auto legend = new TLegend(0.6,0.4,0.9,0.6);
legend->AddEntry(gr1, "Photon number with QE", "lp");
legend->AddEntry(gr2, "Photon number without QE", "lp");
legend->SetFillColor(21);
legend->Draw();

TLatex *lat = new TLatex(20, 60000, "(/run/beamOn 1000)");
lat->Draw();

}
