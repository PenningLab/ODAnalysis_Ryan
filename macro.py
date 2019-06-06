#!/usr/bin/env python

import os
import sys
import shutil
import ROOT
import argparse

ROOT.gInterpreter.Declare('#include "rqlib/rqlibProjectHeaders.h"')
ROOT.gSystem.Load("rqlib/rqlib.so")

#______________________________________
def load_chain(fileList, chain):

	print 'Loading file names from '+fileList+' into '+chain.GetName()

	file = open(fileList, 'r')
	rqFiles = file.read().splitlines()
	for line in rqFiles:
		if line.startswith('#'):
			print 'comment: '+line
		else:
			chain.Add(line)

def load_many(fileList,chain,chain_name):
	with open(fileList) as f:
		rqFiles=f.read().splitlines()
		for line in rqFiles:
			if line.startswith('#'):
				print 'comment: '+line
			else:
				segs = line.split('|')
				if len(segs)<2:
					continue;
				if not (segs[1] in chain_name):
					chain.append(ROOT.TChain('Events'))
					chain_name.append(segs[1])
				for ifile in segs[0].split(','):
					chain[-1].Add(ifile)
	print(chain_name)
#______________________________________
# define script options
parser = argparse.ArgumentParser(description='Wrapper for TSelector-based analysis on LZ RQ files',formatter_class=argparse.ArgumentDefaultsHelpFormatter)
parser.add_argument('macro', type=str, help='TSelector-based analysis macro ( .C file )')
parser.add_argument('fileList', type=str, help='List of RQ files to process')
parser.add_argument('--ff', action='store_true',help='List of RQ files to process')
parser.add_argument('--outfile', default='', type=str, help='Output histogram file name; empty = <fileList>.root')
parser.add_argument('-n', dest='nevents', default=-1, type=int, help='# of events to process; -1 = ALL')
parser.add_argument('--useProof', action='store_true', help='Use PROOF processing')
parser.add_argument('--useGui', action='store_true', help='Show PROOF GUI')
parser.add_argument('-m', dest='nworkers', default=4, type=int, help='# of workers to use for PROOF processing')
args = parser.parse_args()

macro = args.macro
fileList  = args.fileList
outFile = args.outfile
nevents = args.nevents
useProof = args.useProof
nworkers = args.nworkers
useGui = args.useGui

#______________________________________
# decide whether or not to show gui
if useProof and not useGui:
	ROOT.gROOT.SetBatch(True)

#______________________________________
# build the Events and RQMCTruth TChains and friend them
if not args.ff:
	chain = ROOT.TChain('Events')
	load_chain(fileList, chain)

	if nevents == -1:
		nevents = ROOT.TTree.kMaxEntries

		#______________________________________
		# Do the event processing

		# Haven't figured out how to pass output file name through PROOF,
		# so do it "manually" through the TSelector
	if outFile == '':
		outFile = fileList.rstrip('.list')
		outFile += '.root'
	selector=ROOT.TSelector.GetSelector(macro+'+')
	selector.SetOutputName(outFile)
	print 'Saving outputs to '+outFile

	if (args.useProof):

		proof = ROOT.TProof.Open('','workers='+str(nworkers))
		# Load
		# For ROOT < 6.08.02, PROOF is not loading in the pcm files correctly, so load them manually.
		# See https://sft.its.cern.ch/jira/browse/ROOT-8456
		# and https://sft.its.cern.ch/jira/browse/ROOT-8466
		proof.Load(macro+'+,'+macro[:-2]+'_C_ACLiC_dict_rdict.pcm')
		chain.SetProof(1)
		chain.Process(selector, '', nevents)
		chain.SetProof(0)
	else:
		chain.Process(selector, '', nevents)
else:
	chains = []
	chain_names = []
	load_many(fileList,chains,chain_names)
	for irun in range(len(chains)):
		outname = chain_names[irun]+'.root'
		selector=ROOT.TSelector.GetSelector(macro+'+')
		selector.SetOutputName(outname)
		print 'Saving outputs to '+outname
		#selector.SetHistRanges(chains[irun])
		if (args.useProof):
			proof = ROOT.TProof.Open('','workers='+str(nworkers))
			# Load
			# For ROOT < 6.08.02, PROOF is not loading in the pcm files correctly, so load them manually.
			# See https://sft.its.cern.ch/jira/browse/ROOT-8456
			# and https://sft.its.cern.ch/jira/browse/ROOT-8466
			proof.Load(macro+'+,'+macro[:-2]+'_C_ACLiC_dict_rdict.pcm')
			chains[irun].SetProof(1)
			chains[irun].Process(selector, '', nevents)
			chains[irun].SetProof(0)
		else:
			chains[irun].Process(selector, '', nevents)
