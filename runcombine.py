#!/usr/bin/env python

import fnmatch
import os

from optparse import OptionParser

parser = OptionParser()
parser.add_option("-i","--input_folder", dest="input",
                  help="Scan the specified folder for datacards" % vars())


(options, args) = parser.parse_args()


for root, dirnames, filenames in os.walk(options.input):
  for filename in fnmatch.filter(filenames, 'htt_ggPhi*'):
    gghfullfile = os.path.join(root, filename)
    gghoutfile = os.path.join(root, 'mssm_ggh.json')
    os.system("python CombineHarvester/CombineTools/scripts/combineTool.py -m 90:140:10,160:200:20,250:500:50,600:1000:100 -M Asymptotic --boundlist CombineHarvester/CombinePdfs/scripts/mssm_ggh_boundaries.json %(gghfullfile)s --manual_model_params --setPhysicsModelParameters r_bbH=0,r_ggH=0 -t -1 --freezeNuisances MH"%vars())
    os.system("python CombineHarvester/CombineTools/scripts/combineTool.py -M CollectLimits -i higgsCombine.Test.Asymptotic* -o %(gghoutfile)s"%vars())
  for filename in fnmatch.filter(filenames, 'htt_bbPhi*'):
    bbhfullfile = os.path.join(root, filename)
    bbhoutfile = os.path.join(root, 'mssm_bbh.json')
    os.system("python CombineHarvester/CombineTools/scripts/combineTool.py -m 90:140:10,160:200:20,250:500:50,600:1000:100 -M Asymptotic --boundlist CombineHarvester/CombinePdfs/scripts/mssm_bbh_boundaries.json %(bbhfullfile)s --manual_model_params --setPhysicsModelParameters r_bbH=0,r_ggH=0 -t -1 --freezeNuisances MH"%vars())
    os.system("python CombineHarvester/CombineTools/scripts/combineTool.py -M CollectLimits -i higgsCombine.Test.Asymptotic* -o %(bbhoutfile)s"%vars())
 
