#!/usr/bin/env python

import os
import sys
import shutil
import ROOT
import argparse
import collections

#array of line colors
ROOT.gROOT.SetBatch(True)

parser = argparse.ArgumentParser(description='Overlay Plots')
parser.add_argument('fileList', type=str, help='Comma seperated list of files to plot')
#parser.add_argument('--force', action='store_true', help='Force rqlib generation')
parser.add_argument('--plotNames',type=str, help='Comma seperated list of legend names. (must have same number of entries as fileList)')
parser.add_argument('--outFile',default='plots',type=str,help="Output file name")
args = parser.parse_args()

fileList = (args.fileList).split(',')
plotNames = []
infiles = []
if args.plotNames:
	plotNames = (args.plotNames).split(',')
genplotlist = False
if len(fileList) != len(plotNames):
	plotNames = []
	genplotlist = True
	print("Using fileList to generate legend\n")
for ent in fileList:
	if not os.path.isfile(ent):
		print('{} :: File not found, removing from list'.format(ent))
		if not genplotlist:
			del plotNames[fileList.index(ent)]
		fileList.remove(ent)
		continue
	if genplotlist:
		plotNames.append(ent.rstrip(".root"))
	print("file {} is good".format(ent))
stacks1D = {}
stacks2D = {}
leg1 = ROOT.TLegend(.7,.7,.9,.88)
leg1.SetBorderSize(1)
leg1.SetFillColor(0)
leg1.SetFillStyle(0)
leg1.SetTextFont(42)
leg1.SetTextSize(0.035)

#leg.AddEntry(g1,"2X_{n}","L")
#need array of line colours at least as large as fileList
cols = [1,2,3,4,7,1,2,3,4,7]
markers = [7,7,7,7,7,25,25,25,25,25]
printname = args.outFile + ".pdf"
canvas = ROOT.TCanvas("ca1","ca1",100,10,6000,2000)
#canvas.Print('{}.pdf['.format(args.outFile))
canvas.Divide(5,2,0.0001)
canvas.cd()
ROOT.gStyle.SetOptStat(0);
for i in range(len(fileList)):
	ifile = ROOT.TFile(fileList[i])
	icol = i%len(cols)
	keylist = ifile.GetListOfKeys()
	print("processing file {}".format(fileList[i]))
	infiles.append(ifile)
	#keylist.Sort()
	currentpad = 0
	for ikey in keylist:
		tclass = ROOT.gROOT.GetClass(ikey.GetClassName())
		#print("processing object {}".format(ikey.GetName()))
		if tclass.InheritsFrom("TH2"):
			h = ikey.ReadObj()
			h.SetMarkerColor(cols[icol])
			h.SetMarkerStyle(markers[icol])
			if h.GetName() not in stacks2D.keys():
				stacks2D[h.GetName()] = ROOT.THStack('{}_stack'.format(h.GetName()),'{}'.format(h.GetTitle()))
				stacks2D[h.GetName()].Add(h)
				if len(fileList)==2:
					stacks2D['{}_sub'.format(h.GetName())] = h.Clone('{}_sub'.format(h.GetName()))
			else:
				stacks2D[h.GetName()].Add(h)
				if len(fileList)==2:
					stacks2D['{}_sub'.format(h.GetName())].Divide(h)

			if stacks2D[h.GetName()].GetNhists()==len(fileList):
				currentpad += 1
				canvas.cd(currentpad)
				stacks2D[h.GetName()].Draw("nostack")
				stacks2D[h.GetName()].GetXaxis().SetTitle(h.GetXaxis().GetTitle())
				stacks2D[h.GetName()].GetYaxis().SetTitle(h.GetYaxis().GetTitle())
				canvas.Update()
				if len(fileList)==2:
					stacks2D['{}_sub'.format(h.GetName())].GetXaxis().SetTitle(h.GetXaxis().GetTitle())
					stacks2D['{}_sub'.format(h.GetName())].GetYaxis().SetTitle(h.GetYaxis().GetTitle())
					stacks2D['{}_sub'.format(h.GetName())].SetTitle('{}/{}'.format(plotNames[0],plotNames[1]))
					currentpad += 1
					canvas.cd(currentpad)
					ROOT.gPad.SetLogz()
					stacks2D['{}_sub'.format(h.GetName())].Draw("contz")
					canvas.Update()
				#canvas.Print(printname,"pdf")
		elif tclass.InheritsFrom("TH1"):
			h = ikey.ReadObj()
			h.SetLineColor(cols[icol])
			h.SetMarkerColor(cols[icol])
			h.SetMarkerStyle(markers[icol])
			if leg1.GetListOfPrimitives().GetEntries()<(i+1):
				leg1.AddEntry(h,plotNames[i],"L")
			if h.GetName() not in stacks1D.keys():
				stacks1D[h.GetName()] = ROOT.THStack('{}_stack'.format(h.GetName()),'{}'.format(h.GetTitle()))
				stacks1D[h.GetName()].Add(h)
			else:
				stacks1D[h.GetName()].Add(h)
			if "area" in h.GetName()  or "coincidence" in h.GetName() or "peakamp" in h.GetName() or "phdperpulse" in h.GetName():
				continue
			if stacks1D[h.GetName()].GetNhists()==len(fileList):
				currentpad += 1
				canvas.cd(currentpad)
				stacks1D[h.GetName()].Draw("nostack")
				stacks1D[h.GetName()].GetXaxis().SetTitle(h.GetXaxis().GetTitle())
				canvas.Update()
				#canvas.Print(printname,"pdf")

		if i==len(fileList)-1 and currentpad%9==0 and (ikey.GetName() in stacks1D.keys() or ikey.GetName() in stacks2D.keys()):
			curhistname = ikey.GetName().lstrip("h_")
			curhistname = (curhistname.split("_")[0]).split("V")[0]
			canvas.cd(1)
			leg1.Draw()
			canvas.Print('{}_{}.png'.format(args.outFile,curhistname),"png")
			currentpad = 0

canvas2 = ROOT.TCanvas("ca2","ca2",100,10,1200,1000)
canvas2.cd()
#canvas2.Divide(3,1,0.0001)
if "h_area" in stacks1D.keys():
	stacks1D['h_area'].Draw("nostack")
	canvas2.Update()
	leg1.Draw()
	canvas2.Print('{}_PulseArea.png'.format(args.outFile),"png")
if "h_coincidence" in stacks1D.keys():
	stacks1D['h_coincidence'].Draw("nostack")
	canvas2.Update()
	leg1.Draw()
	canvas2.Print('{}_Coincidence.png'.format(args.outFile),"png")
if "h_peakamp" in stacks1D.keys():
	stacks1D['h_peakamp'].Draw("nostack")
	canvas2.Update()
	leg1.Draw()
	canvas2.Print('{}_PulsePeakAmp.png'.format(args.outFile),"png")
if "h_phdperpulse" in stacks1D.keys():
	stacks1D['h_phdperpulse'].Draw("nostack")
	canvas2.Update()
	leg1.Draw()
	canvas2.Print('{}_Eventphdperpulse.png'.format(args.outFile),"png")
	#ifile.Close()
#Difference Plots

#canvas.Print('{}.pdf]'.format(args.outFile))
"""
printname = args.outFile + ".pdf"
totalplots = len(stacks1D)+len(stacks2D)
counter = 0
canvas = ROOT.TCanvas("ca1","ca1",200,10,2900,2100)
canvas.Print('{}.pdf['.format(args.outFile))
canvas.cd()
#print("Drawing Canvases")
for ent in sorted(stacks1D):
	print("Drawing 1d canvas {}".format(stacks1D[ent].GetName()))
	counter += 1
	stacks1D[ent].Draw("nostack")
	canvas.Update()
	print("Printing {}".format(printname))
	canvas.Print(printname,"pdf")

for ent in sorted(stacks2D):
	print("Drawing 2d canvas {}".format(stacks2D[ent].GetName()))
	counter += 1
	stacks2D[ent].Draw("nostack")
	canvas.Update()
	#leg2.Draw()
	print("Printing {}".format(printname))
	canvas.Print(printname,"pdf")
canvas.Print('{}.pdf]'.format(args.outFile))
"""
"""
for ent in stacks1D:
	print("Hists in 1D {} = {}".format(stacks1D[ent].GetName(),stacks1D[ent].GetNhists()))

for ent in stacks2D:
	print("Hists in 2D {} = {}".format(stacks2D[ent].GetName(),stacks2D[ent].GetNhists()))
"""
sys.exit()
