void compilevertex (TString myopt="fast"){
TString opt;
if (myopt.Contains("force")){opt="kfg";} else {opt ="kg"; }
gSystem->CompileMacro ("vertex.cpp", opt.Data());
gSystem->CompileMacro ("track.cpp", opt.Data());
gSystem->CompileMacro ("vertexsimul.C", opt.Data()); }
