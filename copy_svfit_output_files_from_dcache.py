#!/usr/bin/env python

import fnmatch
import os
import ROOT
import sys
from optparse import OptionParser


parser = OptionParser()


(options, args) = parser.parse_args()

dcache_path = ""
local_svfit_folder = "svfit-output-dec01-fewerits"

for i in range(1,1001):
  os.system('lcg-cp %(dcache_path)s/0000/svfit_output_%(i)d.tar %(local_svfit_folder)s/svfit_output_%(i)d.tar'%vars())

for i in range(1000,2001):
  os.system('lcg-cp %(dcache_path)s/0001/svfit_output_%(i)d.tar %(local_svfit_folder)s/svfit_output_%(i)d.tar'%vars())

for i in range(2000,3001):
  os.system('lcg-cp %(dcache_path)s/0002/svfit_output_%(i)d.tar %(local_svfit_folder)s/svfit_output_%(i)d.tar'%vars())

for i in range(3000,4001):
  os.system('lcg-cp %(dcache_path)s/0003/svfit_output_%(i)d.tar %(local_svfit_folder)s/svfit_output_%(i)d.tar'%vars())

