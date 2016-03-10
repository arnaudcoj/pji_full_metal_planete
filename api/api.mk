##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=api
ConfigurationName      :=Debug
WorkspacePath          := "/Users/Kaendan/Documents/Code/Master/S2/PJI/FMP"
ProjectPath            := "/Users/Kaendan/Documents/Code/Master/S2/PJI/FMP/api"
IntermediateDirectory  :=./Debug
OutDir                 := $(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=Tristan Camus
Date                   :=11/03/2016
CodeLitePath           :="/Users/Kaendan/Library/Application Support/codelite"
LinkerName             :=/usr/bin/g++
SharedObjectLinkerName :=/usr/bin/g++ -dynamiclib -fPIC
ObjectSuffix           :=.o
DependSuffix           :=.o.d
PreprocessSuffix       :=.i
DebugSwitch            :=-g 
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
ObjectsFileList        :="api.txt"
PCHCompileFlags        :=
MakeDirCommand         :=mkdir -p
LinkOptions            :=  
IncludePath            :=  $(IncludeSwitch). $(IncludeSwitch). 
IncludePCH             := 
RcIncludePath          := 
Libs                   := 
ArLibs                 :=  
LibPath                := $(LibraryPathSwitch). 

##
## Common variables
## AR, CXX, CC, AS, CXXFLAGS and CFLAGS can be overriden using an environment variables
##
AR       := /usr/bin/ar rcu
CXX      := /usr/bin/g++
CC       := /usr/bin/gcc
CXXFLAGS :=  -g -std=c++11 $(Preprocessors)
CFLAGS   :=  -g $(Preprocessors)
ASFLAGS  := 
AS       := /usr/bin/as


##
## User defined environment variables
##
CodeLiteDir:=/Users/Kaendan/Downloads/codelite.app/Contents/SharedSupport/
Objects0=$(IntermediateDirectory)/cell.cpp$(ObjectSuffix) $(IntermediateDirectory)/game.cpp$(ObjectSuffix) $(IntermediateDirectory)/gamestate.cpp$(ObjectSuffix) $(IntermediateDirectory)/hexagrid.cpp$(ObjectSuffix) $(IntermediateDirectory)/mountaincell.cpp$(ObjectSuffix) $(IntermediateDirectory)/piece.cpp$(ObjectSuffix) $(IntermediateDirectory)/piecestock.cpp$(ObjectSuffix) $(IntermediateDirectory)/plaincell.cpp$(ObjectSuffix) $(IntermediateDirectory)/player.cpp$(ObjectSuffix) $(IntermediateDirectory)/reefcell.cpp$(ObjectSuffix) \
	$(IntermediateDirectory)/seacell.cpp$(ObjectSuffix) $(IntermediateDirectory)/swampcell.cpp$(ObjectSuffix) 



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
	@echo rebuilt > "/Users/Kaendan/Documents/Code/Master/S2/PJI/FMP/.build-debug/api"

MakeIntermediateDirs:
	@test -d ./Debug || $(MakeDirCommand) ./Debug


./Debug:
	@test -d ./Debug || $(MakeDirCommand) ./Debug

PreBuild:


##
## Objects
##
$(IntermediateDirectory)/cell.cpp$(ObjectSuffix): cell.cpp $(IntermediateDirectory)/cell.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/Users/Kaendan/Documents/Code/Master/S2/PJI/FMP/api/cell.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/cell.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/cell.cpp$(DependSuffix): cell.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/cell.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/cell.cpp$(DependSuffix) -MM "cell.cpp"

$(IntermediateDirectory)/cell.cpp$(PreprocessSuffix): cell.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/cell.cpp$(PreprocessSuffix) "cell.cpp"

$(IntermediateDirectory)/game.cpp$(ObjectSuffix): game.cpp $(IntermediateDirectory)/game.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/Users/Kaendan/Documents/Code/Master/S2/PJI/FMP/api/game.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/game.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/game.cpp$(DependSuffix): game.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/game.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/game.cpp$(DependSuffix) -MM "game.cpp"

$(IntermediateDirectory)/game.cpp$(PreprocessSuffix): game.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/game.cpp$(PreprocessSuffix) "game.cpp"

$(IntermediateDirectory)/gamestate.cpp$(ObjectSuffix): gamestate.cpp $(IntermediateDirectory)/gamestate.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/Users/Kaendan/Documents/Code/Master/S2/PJI/FMP/api/gamestate.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/gamestate.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/gamestate.cpp$(DependSuffix): gamestate.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/gamestate.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/gamestate.cpp$(DependSuffix) -MM "gamestate.cpp"

$(IntermediateDirectory)/gamestate.cpp$(PreprocessSuffix): gamestate.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/gamestate.cpp$(PreprocessSuffix) "gamestate.cpp"

$(IntermediateDirectory)/hexagrid.cpp$(ObjectSuffix): hexagrid.cpp $(IntermediateDirectory)/hexagrid.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/Users/Kaendan/Documents/Code/Master/S2/PJI/FMP/api/hexagrid.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/hexagrid.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/hexagrid.cpp$(DependSuffix): hexagrid.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/hexagrid.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/hexagrid.cpp$(DependSuffix) -MM "hexagrid.cpp"

$(IntermediateDirectory)/hexagrid.cpp$(PreprocessSuffix): hexagrid.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/hexagrid.cpp$(PreprocessSuffix) "hexagrid.cpp"

$(IntermediateDirectory)/mountaincell.cpp$(ObjectSuffix): mountaincell.cpp $(IntermediateDirectory)/mountaincell.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/Users/Kaendan/Documents/Code/Master/S2/PJI/FMP/api/mountaincell.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/mountaincell.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/mountaincell.cpp$(DependSuffix): mountaincell.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/mountaincell.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/mountaincell.cpp$(DependSuffix) -MM "mountaincell.cpp"

$(IntermediateDirectory)/mountaincell.cpp$(PreprocessSuffix): mountaincell.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/mountaincell.cpp$(PreprocessSuffix) "mountaincell.cpp"

$(IntermediateDirectory)/piece.cpp$(ObjectSuffix): piece.cpp $(IntermediateDirectory)/piece.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/Users/Kaendan/Documents/Code/Master/S2/PJI/FMP/api/piece.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/piece.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/piece.cpp$(DependSuffix): piece.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/piece.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/piece.cpp$(DependSuffix) -MM "piece.cpp"

$(IntermediateDirectory)/piece.cpp$(PreprocessSuffix): piece.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/piece.cpp$(PreprocessSuffix) "piece.cpp"

$(IntermediateDirectory)/piecestock.cpp$(ObjectSuffix): piecestock.cpp $(IntermediateDirectory)/piecestock.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/Users/Kaendan/Documents/Code/Master/S2/PJI/FMP/api/piecestock.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/piecestock.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/piecestock.cpp$(DependSuffix): piecestock.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/piecestock.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/piecestock.cpp$(DependSuffix) -MM "piecestock.cpp"

$(IntermediateDirectory)/piecestock.cpp$(PreprocessSuffix): piecestock.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/piecestock.cpp$(PreprocessSuffix) "piecestock.cpp"

$(IntermediateDirectory)/plaincell.cpp$(ObjectSuffix): plaincell.cpp $(IntermediateDirectory)/plaincell.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/Users/Kaendan/Documents/Code/Master/S2/PJI/FMP/api/plaincell.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/plaincell.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/plaincell.cpp$(DependSuffix): plaincell.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/plaincell.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/plaincell.cpp$(DependSuffix) -MM "plaincell.cpp"

$(IntermediateDirectory)/plaincell.cpp$(PreprocessSuffix): plaincell.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/plaincell.cpp$(PreprocessSuffix) "plaincell.cpp"

$(IntermediateDirectory)/player.cpp$(ObjectSuffix): player.cpp $(IntermediateDirectory)/player.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/Users/Kaendan/Documents/Code/Master/S2/PJI/FMP/api/player.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/player.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/player.cpp$(DependSuffix): player.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/player.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/player.cpp$(DependSuffix) -MM "player.cpp"

$(IntermediateDirectory)/player.cpp$(PreprocessSuffix): player.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/player.cpp$(PreprocessSuffix) "player.cpp"

$(IntermediateDirectory)/reefcell.cpp$(ObjectSuffix): reefcell.cpp $(IntermediateDirectory)/reefcell.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/Users/Kaendan/Documents/Code/Master/S2/PJI/FMP/api/reefcell.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/reefcell.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/reefcell.cpp$(DependSuffix): reefcell.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/reefcell.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/reefcell.cpp$(DependSuffix) -MM "reefcell.cpp"

$(IntermediateDirectory)/reefcell.cpp$(PreprocessSuffix): reefcell.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/reefcell.cpp$(PreprocessSuffix) "reefcell.cpp"

$(IntermediateDirectory)/seacell.cpp$(ObjectSuffix): seacell.cpp $(IntermediateDirectory)/seacell.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/Users/Kaendan/Documents/Code/Master/S2/PJI/FMP/api/seacell.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/seacell.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/seacell.cpp$(DependSuffix): seacell.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/seacell.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/seacell.cpp$(DependSuffix) -MM "seacell.cpp"

$(IntermediateDirectory)/seacell.cpp$(PreprocessSuffix): seacell.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/seacell.cpp$(PreprocessSuffix) "seacell.cpp"

$(IntermediateDirectory)/swampcell.cpp$(ObjectSuffix): swampcell.cpp $(IntermediateDirectory)/swampcell.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/Users/Kaendan/Documents/Code/Master/S2/PJI/FMP/api/swampcell.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/swampcell.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/swampcell.cpp$(DependSuffix): swampcell.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/swampcell.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/swampcell.cpp$(DependSuffix) -MM "swampcell.cpp"

$(IntermediateDirectory)/swampcell.cpp$(PreprocessSuffix): swampcell.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/swampcell.cpp$(PreprocessSuffix) "swampcell.cpp"


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r ./Debug/


