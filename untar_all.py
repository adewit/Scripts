#!/usr/bin/env python

import fnmatch
import os
import ROOT
import sys
from optparse import OptionParser


parser = OptionParser()


(options, args) = parser.parse_args()


for i in range(1,4001):
  os.system("tar -xf svfit_output_%(i)d.tar"%vars())
