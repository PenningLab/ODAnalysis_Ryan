#!/usr/bin/env python

import os
import sys
import shutil
import ROOT
import argparse

parser = argparse.ArgumentParser(description='Configure rqlib')
parser.add_argument('file', type=str, help='Sample LZap file to generate rqlib')
parser.add_argument('--force', action='store_true', help='Force rqlib generation')
parser.add_argument('--tree',type=str, help='Name of Tree in LZap file to generate template script')
parser.add_argument('-n','--AnaName',type=str,help='Name of analysis class')
parser.add_argument('-o','--options',type=str,help="MakeSelector options default is topmost branches as a whole")
args = parser.parse_args()

filename = args.file

if not os.path.isdir('rqlib'):
    file = ROOT.TFile(filename)
    file.MakeProject("rqlib","*","update+");
    file.Close()
elif args.force:
    shutil.rmtree('rqlib')
    file = ROOT.TFile(filename)
    file.MakeProject("rqlib","*","update+");
    file.Close()
else:
    print "rqlib already exists. doing nothing."
if args.tree:
	ROOT.gInterpreter.Declare('#include "rqlib/rqlibProjectHeaders.h"')
	ROOT.gSystem.Load("rqlib/rqlib.so")
	
	classname = "Analysis"
	if args.AnaName:
		classname = args.AnaName
	selectoptions = "@"
	if args.options:
		selectoptions = args.options
	file = ROOT.TFile(filename)
	newtree = file.Get(args.tree)
	newtree.MakeSelector(classname,selectoptions)
	file.Close()

sys.exit()
