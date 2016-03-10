##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=interface
ConfigurationName      :=Debug
WorkspacePath          := "/Users/Kaendan/Documents/Code/Master/S2/PJI/FMP"
ProjectPath            := "/Users/Kaendan/Documents/Code/Master/S2/PJI/FMP/interface"
IntermediateDirectory  :=./Debug
OutDir                 := $(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=Tristan Camus
Date                   :=08/03/2016
CodeLitePath           :="/Users/Kaendan/Library/Application Support/codelite"
LinkerName             :=g++
SharedObjectLinkerName :=g++ -dynamiclib -fPIC
ObjectSuffix           :=.o
DependSuffix           :=.o.d
PreprocessSuffix       :=.o.i
DebugSwitch            :=-gstab
IncludeSwitch          :=-I
LibrarySwitch          :=-l
OutputSwitch           :=-o 
LibraryPathSwitch      :=-L
PreprocessorSwitch     :=-D
SourceSwitch           :=-c 
OutputFile             :=$(IntermediateDirectory)/lib$(ProjectName).a
Preprocessors          :=
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=-E 
ObjectsFileList        :="interface.txt"
PCHCompileFlags        :=
MakeDirCommand         :=mkdir -p
LinkOptions            :=  
IncludePath            :=  $(IncludeSwitch). $(IncludeSwitch). $(IncludeSwitch)../api 
IncludePCH             := 
RcIncludePath          := 
Libs                   := 
ArLibs                 :=  
LibPath                := $(LibraryPathSwitch). 

##
## Common variables
## AR, CXX, CC, AS, CXXFLAGS and CFLAGS can be overriden using an environment variables
##
AR       := ar rcus
CXX      := g++
CC       := gcc
CXXFLAGS :=  -g -std=c++11 $(Preprocessors)
CFLAGS   :=  -g $(Preprocessors)
ASFLAGS  := 
AS       := as


##
## User defined environment variables
##
CodeLiteDir:=/Users/Kaendan/Downloads/codelite.app/Contents/SharedSupport/
Objects0=$(IntermediateDirectory)/assetmanager.cpp$(ObjectSuffix) $(IntermediateDirectory)/grid.cpp$(ObjectSuffix) $(IntermediateDirectory)/hexagon.cpp$(ObjectSuffix) $(IntermediateDirectory)/pawn.cpp$(ObjectSuffix) 



Objects=$(Objects0) 

##
## Main Build Targets 
##
.PHONY: all clean PreBuild PrePreBuild PostBuild MakeIntermediateDirs
all: $(IntermediateDirectory) $(OutputFile)

$(OutputFile): $(Objects)
	@$(MakeDirCommand) $(@D)
	@echo "" > $(IntermediateDirectory)/.d
	@echo $(Objects0)  > $(ObjectsFileList)
	$(AR) $(ArchiveOutputSwitch)$(OutputFile) $(Objects) $(ArLibs)
	@$(MakeDirCommand) "/Users/Kaendan/Documents/Code/Master/S2/PJI/FMP/.build-debug"
	@echo rebuilt > "/Users/Kaendan/Documents/Code/Master/S2/PJI/FMP/.build-debug/interface"

MakeIntermediateDirs:
	@test -d ./Debug || $(MakeDirCommand) ./Debug


./Debug:
	@test -d ./Debug || $(MakeDirCommand) ./Debug

PreBuild:


##
## Objects
##
$(IntermediateDirectory)/assetmanager.cpp$(ObjectSuffix): assetmanager.cpp $(IntermediateDirectory)/assetmanager.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/Users/Kaendan/Documents/Code/Master/S2/PJI/FMP/interface/assetmanager.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/assetmanager.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/assetmanager.cpp$(DependSuffix): assetmanager.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/assetmanager.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/assetmanager.cpp$(DependSuffix) -MM "assetmanager.cpp"

$(IntermediateDirectory)/assetmanager.cpp$(PreprocessSuffix): assetmanager.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/assetmanager.cpp$(PreprocessSuffix) "assetmanager.cpp"

$(IntermediateDirectory)/grid.cpp$(ObjectSuffix): grid.cpp $(IntermediateDirectory)/grid.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/Users/Kaendan/Documents/Code/Master/S2/PJI/FMP/interface/grid.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/grid.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/grid.cpp$(DependSuffix): grid.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/grid.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/grid.cpp$(DependSuffix) -MM "grid.cpp"

$(IntermediateDirectory)/grid.cpp$(PreprocessSuffix): grid.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/grid.cpp$(PreprocessSuffix) "grid.cpp"

$(IntermediateDirectory)/hexagon.cpp$(ObjectSuffix): hexagon.cpp $(IntermediateDirectory)/hexagon.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/Users/Kaendan/Documents/Code/Master/S2/PJI/FMP/interface/hexagon.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/hexagon.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/hexagon.cpp$(DependSuffix): hexagon.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/hexagon.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/hexagon.cpp$(DependSuffix) -MM "hexagon.cpp"

$(IntermediateDirectory)/hexagon.cpp$(PreprocessSuffix): hexagon.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/hexagon.cpp$(PreprocessSuffix) "hexagon.cpp"

$(IntermediateDirectory)/pawn.cpp$(ObjectSuffix): pawn.cpp $(IntermediateDirectory)/pawn.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/Users/Kaendan/Documents/Code/Master/S2/PJI/FMP/interface/pawn.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/pawn.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/pawn.cpp$(DependSuffix): pawn.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/pawn.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/pawn.cpp$(DependSuffix) -MM "pawn.cpp"

$(IntermediateDirectory)/pawn.cpp$(PreprocessSuffix): pawn.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/pawn.cpp$(PreprocessSuffix) "pawn.cpp"


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r ./Debug/

