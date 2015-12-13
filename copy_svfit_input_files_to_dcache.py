#!/usr/bin/env python

import fnmatch
import os
import ROOT
import sys
from optparse import OptionParser


parser = OptionParser()
parser.add_option("-i","--input_folder", dest="input",
                  help="Scan the specified folder recursively looking for svfit input files." % vars())


(options, args) = parser.parse_args()

dcache_path = ""

for root, dirnames, filenames in os.walk(options.input):
  for filename in fnmatch.filter(filenames, '*svfit_*_input.root'):
    fullfile = os.path.join(root, filename)
    os.system('lcg-cp %(fullfile)s %(dcache_path)s/%(filename)s'%vars())

