#!/usr/bin/env python

import fnmatch
import os

from optparse import OptionParser

parser = OptionParser()
parser.add_option("-i","--input_folder", dest="input",
                  help="Scan the specified folder for datacards" % vars())


(options, args) = parser.parse_args()


for root, dirnames, filenames in os.walk(options.input):
  for filename in fnmatch.filter(filenames, 'htt_*.txt'):
    fullfile = os.path.join(root, filename)
    gghoutfile = os.path.join(root, 'htt_ggPhi_mssm.root')
    bbhoutfile = os.path.join(root, 'htt_bbPhi_mssm.root')
    os.system("text2workspace.py -b %(fullfile)s -o %(gghoutfile)s -P CombineHarvester.CombinePdfs.ModelIndependent:floatingMSSMXSHiggs --PO 'modes=ggH' --PO 'ggHRange=0:20'"%vars())
    os.system("text2workspace.py -b %(fullfile)s -o %(bbhoutfile)s -P CombineHarvester.CombinePdfs.ModelIndependent:floatingMSSMXSHiggs --PO 'modes=bbH' --PO 'bbHRange=0:20'"%vars())
