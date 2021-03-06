##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=interface
ConfigurationName      :=Debug
WorkspacePath          :=/Users/Kaendan/Documents/Code/GameDev/pji_full_metal_planete
ProjectPath            :=/Users/Kaendan/Documents/Code/GameDev/pji_full_metal_planete/interface
IntermediateDirectory  :=./Debug
OutDir                 := $(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=Tristan Camus
Date                   :=26/11/2016
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
IncludePath            :=  $(IncludeSwitch). $(IncludeSwitch). $(IncludeSwitch)../api $(IncludeSwitch)/usr/local/include 
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
CodeLiteDir:=/Applications/codelite.app/Contents/SharedSupport/
Objects0=$(IntermediateDirectory)/assetmanager.cpp$(ObjectSuffix) $(IntermediateDirectory)/grid.cpp$(ObjectSuffix) $(IntermediateDirectory)/hexagon.cpp$(ObjectSuffix) $(IntermediateDirectory)/pawn.cpp$(ObjectSuffix) $(IntermediateDirectory)/animator.cpp$(ObjectSuffix) $(IntermediateDirectory)/pawns.cpp$(ObjectSuffix) $(IntermediateDirectory)/userinterface.cpp$(ObjectSuffix) 



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
	@$(MakeDirCommand) "/Users/Kaendan/Documents/Code/GameDev/pji_full_metal_planete/.build-debug"
	@echo rebuilt > "/Users/Kaendan/Documents/Code/GameDev/pji_full_metal_planete/.build-debug/interface"

MakeIntermediateDirs:
	@test -d ./Debug || $(MakeDirCommand) ./Debug


./Debug:
	@test -d ./Debug || $(MakeDirCommand) ./Debug

PreBuild:


##
## Objects
##
$(IntermediateDirectory)/assetmanager.cpp$(ObjectSuffix): assetmanager.cpp $(IntermediateDirectory)/assetmanager.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/Users/Kaendan/Documents/Code/GameDev/pji_full_metal_planete/interface/assetmanager.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/assetmanager.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/assetmanager.cpp$(DependSuffix): assetmanager.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/assetmanager.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/assetmanager.cpp$(DependSuffix) -MM assetmanager.cpp

$(IntermediateDirectory)/assetmanager.cpp$(PreprocessSuffix): assetmanager.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/assetmanager.cpp$(PreprocessSuffix)assetmanager.cpp

$(IntermediateDirectory)/grid.cpp$(ObjectSuffix): grid.cpp $(IntermediateDirectory)/grid.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/Users/Kaendan/Documents/Code/GameDev/pji_full_metal_planete/interface/grid.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/grid.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/grid.cpp$(DependSuffix): grid.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/grid.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/grid.cpp$(DependSuffix) -MM grid.cpp

$(IntermediateDirectory)/grid.cpp$(PreprocessSuffix): grid.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/grid.cpp$(PreprocessSuffix)grid.cpp

$(IntermediateDirectory)/hexagon.cpp$(ObjectSuffix): hexagon.cpp $(IntermediateDirectory)/hexagon.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/Users/Kaendan/Documents/Code/GameDev/pji_full_metal_planete/interface/hexagon.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/hexagon.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/hexagon.cpp$(DependSuffix): hexagon.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/hexagon.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/hexagon.cpp$(DependSuffix) -MM hexagon.cpp

$(IntermediateDirectory)/hexagon.cpp$(PreprocessSuffix): hexagon.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/hexagon.cpp$(PreprocessSuffix)hexagon.cpp

$(IntermediateDirectory)/pawn.cpp$(ObjectSuffix): pawn.cpp $(IntermediateDirectory)/pawn.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/Users/Kaendan/Documents/Code/GameDev/pji_full_metal_planete/interface/pawn.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/pawn.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/pawn.cpp$(DependSuffix): pawn.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/pawn.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/pawn.cpp$(DependSuffix) -MM pawn.cpp

$(IntermediateDirectory)/pawn.cpp$(PreprocessSuffix): pawn.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/pawn.cpp$(PreprocessSuffix)pawn.cpp

$(IntermediateDirectory)/animator.cpp$(ObjectSuffix): animator.cpp $(IntermediateDirectory)/animator.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/Users/Kaendan/Documents/Code/GameDev/pji_full_metal_planete/interface/animator.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/animator.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/animator.cpp$(DependSuffix): animator.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/animator.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/animator.cpp$(DependSuffix) -MM animator.cpp

$(IntermediateDirectory)/animator.cpp$(PreprocessSuffix): animator.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/animator.cpp$(PreprocessSuffix)animator.cpp

$(IntermediateDirectory)/pawns.cpp$(ObjectSuffix): pawns.cpp $(IntermediateDirectory)/pawns.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/Users/Kaendan/Documents/Code/GameDev/pji_full_metal_planete/interface/pawns.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/pawns.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/pawns.cpp$(DependSuffix): pawns.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/pawns.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/pawns.cpp$(DependSuffix) -MM pawns.cpp

$(IntermediateDirectory)/pawns.cpp$(PreprocessSuffix): pawns.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/pawns.cpp$(PreprocessSuffix)pawns.cpp

$(IntermediateDirectory)/userinterface.cpp$(ObjectSuffix): userinterface.cpp $(IntermediateDirectory)/userinterface.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/Users/Kaendan/Documents/Code/GameDev/pji_full_metal_planete/interface/userinterface.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/userinterface.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/userinterface.cpp$(DependSuffix): userinterface.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/userinterface.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/userinterface.cpp$(DependSuffix) -MM userinterface.cpp

$(IntermediateDirectory)/userinterface.cpp$(PreprocessSuffix): userinterface.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/userinterface.cpp$(PreprocessSuffix)userinterface.cpp


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r ./Debug/


