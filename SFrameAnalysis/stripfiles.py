from ROOT import TFile
from sys import argv
for filename in argv[1:]:
  if ('QCD' in filename) or ('_2' in filename):
    continue
  f=TFile('/scratch/hh/dust/naf/cms/user/usai/Semileptonicselection/'+filename,'READ')
  #a=f.Get('btageffhists/pt_bJet')
  #print '/scratch/hh/dust/naf/cms/user/usai/Semileptonicselection/'+filename
  histohash=f.Get('btageffhists').GetListOfKeys()
  f2=TFile('/scratch/hh/dust/naf/cms/user/usai/Semileptonicselection/'+filename[:-5]+'_2.root','RECREATE')
  directory=f2.mkdir('btageffhists')
  directory.cd()
  histokeyiter=histohash.MakeIterator()
  key=histokeyiter()
  while key:
    obj=key.ReadObj()
    obj.Write()
    key=histokeyiter()
  f.Close()
  f2.Close()