



void compilevertex1 (TString myopt="fast"){
TString opt;
if (myopt.Contains("force")){opt="kfg";} else {opt ="kg"; }
gSystem->CompileMacro ("vertex.cpp", opt.Data());
gSystem->CompileMacro ("track1.cpp", opt.Data());
gSystem->CompileMacro ("vertexsimul1.c", opt.Data()); }
