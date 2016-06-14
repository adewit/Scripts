import ROOT
import math

ROOT.gROOT.SetBatch(ROOT.kTRUE)

def calcChi2(filename, subdirname):
 tdir = filename.Get(subdirname)
 ztt_hist = tdir.Get("ZTT") 
 vv_hist = tdir.Get("VV") 
 zll_hist = tdir.Get("ZLL")
 tt_hist = tdir.Get("TT")
 w_hist = tdir.Get("W")
 qcd_hist = tdir.Get("QCD")
 data_hist = tdir.Get("data_obs")
 ztt_hist.Add(vv_hist)
 ztt_hist.Add(zll_hist)
 ztt_hist.Add(tt_hist)
 ztt_hist.Add(w_hist)
 ztt_hist.Add(qcd_hist)
 
 tot_chi2 = 0
 nbins = ztt_hist.GetNbinsX()
 for x in range(nbins):
   tot_chi2 += (math.pow(ztt_hist.GetBinContent(x+1)-data_hist.GetBinContent(x+1),2))/data_hist.GetBinContent(x+1)

 return tot_chi2


etr1dd = ROOT.TFile("./WJets2503/datacard_mt_1_inclusive_et_2015_Wrun1DD.root")
etr2dd = ROOT.TFile("./WJets2503/datacard_mt_1_inclusive_et_2015_Wrun2DD.root")
etmc = ROOT.TFile("./WJets2503/datacard_mt_1_inclusive_et_2015_WMC.root")

mtr1dd = ROOT.TFile("./WJets2503/datacard_mt_1_inclusive_mt_2015_Wrun1DD.root")
mtr2dd = ROOT.TFile("./WJets2503/datacard_mt_1_inclusive_mt_2015_Wrun2DD.root")
mtmc = ROOT.TFile("./WJets2503/datacard_mt_1_inclusive_mt_2015_WMC.root")

print 'mt, w from mc'
print calcChi2(mtmc,"mt_inclusive")

print 'mt, w using run 1 DD'
print calcChi2(mtr1dd,"mt_inclusive")

print 'mt, w using run 2 DD'
print calcChi2(mtr2dd,"mt_inclusive")


print 'et, w from mc'
print calcChi2(etmc,"et_inclusive")

print 'et, w using run 1 DD'
print calcChi2(etr1dd,"et_inclusive")

print 'et, w using run 2 DD'
print calcChi2(etr2dd,"et_inclusive")
