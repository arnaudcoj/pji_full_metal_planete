##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=tests
ConfigurationName      :=Debug
WorkspacePath          := "/Users/Kaendan/Documents/Code/Master/S2/PJI/FMP"
ProjectPath            := "/Users/Kaendan/Documents/Code/Master/S2/PJI/FMP/tests"
IntermediateDirectory  :=./Debug
OutDir                 := $(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=Tristan Camus
Date                   :=10/03/2016
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
OutputFile             :=$(IntermediateDirectory)/$(ProjectName)
Preprocessors          :=
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=-E
ObjectsFileList        :="tests.txt"
PCHCompileFlags        :=
MakeDirCommand         :=mkdir -p
LinkOptions            :=  
IncludePath            :=  $(IncludeSwitch). $(IncludeSwitch). $(IncludeSwitch)../api 
IncludePCH             := 
RcIncludePath          := 
Libs                   := $(LibrarySwitch)api $(LibrarySwitch)yaml-cpp 
ArLibs                 :=  "api" "yaml-cpp" 
LibPath                := $(LibraryPathSwitch). $(LibraryPathSwitch)../api/Debug $(LibraryPathSwitch)/usr/local/lib 

##
## Common variables
## AR, CXX, CC, AS, CXXFLAGS and CFLAGS can be overriden using an environment variables
##
AR       := /usr/bin/ar rcu
CXX      := /usr/bin/g++
CC       := /usr/bin/gcc
CXXFLAGS :=  -g -O0 -std=c++11 $(Preprocessors)
CFLAGS   :=  -g -O0 -Wall $(Preprocessors)
ASFLAGS  := 
AS       := /usr/bin/as


##
## User defined environment variables
##
CodeLiteDir:=/Users/Kaendan/Downloads/codelite.app/Contents/SharedSupport/
Objects0=$(IntermediateDirectory)/main.cpp$(ObjectSuffix) $(IntermediateDirectory)/testCell.cpp$(ObjectSuffix) $(IntermediateDirectory)/testgame.cpp$(ObjectSuffix) $(IntermediateDirectory)/testgamestate.cpp$(ObjectSuffix) $(IntermediateDirectory)/testHexagrid.cpp$(ObjectSuffix) $(IntermediateDirectory)/testpiece.cpp$(ObjectSuffix) $(IntermediateDirectory)/testpiecestock.cpp$(ObjectSuffix) $(IntermediateDirectory)/testplayer.cpp$(ObjectSuffix) 



Objects=$(Objects0) 

##
## Main Build Targets 
##
.PHONY: all clean PreBuild PrePreBuild PostBuild MakeIntermediateDirs
all: $(OutputFile)

$(OutputFile): $(IntermediateDirectory)/.d $(Objects) 
	@$(MakeDirCommand) $(@D)
	@echo "" > $(IntermediateDirectory)/.d
	@echo $(Objects0)  > $(ObjectsFileList)
	$(LinkerName) $(OutputSwitch)$(OutputFile) $(Objects) $(LibPath) $(Libs) $(LinkOptions)

MakeIntermediateDirs:
	@test -d ./Debug || $(MakeDirCommand) ./Debug


$(IntermediateDirectory)/.d:
	@test -d ./Debug || $(MakeDirCommand) ./Debug

PreBuild:


##
## Objects
##
$(IntermediateDirectory)/main.cpp$(ObjectSuffix): main.cpp $(IntermediateDirectory)/main.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/Users/Kaendan/Documents/Code/Master/S2/PJI/FMP/tests/main.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/main.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/main.cpp$(DependSuffix): main.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/main.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/main.cpp$(DependSuffix) -MM "main.cpp"

$(IntermediateDirectory)/main.cpp$(PreprocessSuffix): main.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/main.cpp$(PreprocessSuffix) "main.cpp"

$(IntermediateDirectory)/testCell.cpp$(ObjectSuffix): testCell.cpp $(IntermediateDirectory)/testCell.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/Users/Kaendan/Documents/Code/Master/S2/PJI/FMP/tests/testCell.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/testCell.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/testCell.cpp$(DependSuffix): testCell.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/testCell.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/testCell.cpp$(DependSuffix) -MM "testCell.cpp"

$(IntermediateDirectory)/testCell.cpp$(PreprocessSuffix): testCell.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/testCell.cpp$(PreprocessSuffix) "testCell.cpp"

$(IntermediateDirectory)/testgame.cpp$(ObjectSuffix): testgame.cpp $(IntermediateDirectory)/testgame.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/Users/Kaendan/Documents/Code/Master/S2/PJI/FMP/tests/testgame.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/testgame.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/testgame.cpp$(DependSuffix): testgame.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/testgame.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/testgame.cpp$(DependSuffix) -MM "testgame.cpp"

$(IntermediateDirectory)/testgame.cpp$(PreprocessSuffix): testgame.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/testgame.cpp$(PreprocessSuffix) "testgame.cpp"

$(IntermediateDirectory)/testgamestate.cpp$(ObjectSuffix): testgamestate.cpp $(IntermediateDirectory)/testgamestate.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/Users/Kaendan/Documents/Code/Master/S2/PJI/FMP/tests/testgamestate.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/testgamestate.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/testgamestate.cpp$(DependSuffix): testgamestate.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/testgamestate.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/testgamestate.cpp$(DependSuffix) -MM "testgamestate.cpp"

$(IntermediateDirectory)/testgamestate.cpp$(PreprocessSuffix): testgamestate.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/testgamestate.cpp$(PreprocessSuffix) "testgamestate.cpp"

$(IntermediateDirectory)/testHexagrid.cpp$(ObjectSuffix): testHexagrid.cpp $(IntermediateDirectory)/testHexagrid.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/Users/Kaendan/Documents/Code/Master/S2/PJI/FMP/tests/testHexagrid.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/testHexagrid.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/testHexagrid.cpp$(DependSuffix): testHexagrid.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/testHexagrid.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/testHexagrid.cpp$(DependSuffix) -MM "testHexagrid.cpp"

$(IntermediateDirectory)/testHexagrid.cpp$(PreprocessSuffix): testHexagrid.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/testHexagrid.cpp$(PreprocessSuffix) "testHexagrid.cpp"

$(IntermediateDirectory)/testpiece.cpp$(ObjectSuffix): testpiece.cpp $(IntermediateDirectory)/testpiece.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/Users/Kaendan/Documents/Code/Master/S2/PJI/FMP/tests/testpiece.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/testpiece.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/testpiece.cpp$(DependSuffix): testpiece.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/testpiece.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/testpiece.cpp$(DependSuffix) -MM "testpiece.cpp"

$(IntermediateDirectory)/testpiece.cpp$(PreprocessSuffix): testpiece.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/testpiece.cpp$(PreprocessSuffix) "testpiece.cpp"

$(IntermediateDirectory)/testpiecestock.cpp$(ObjectSuffix): testpiecestock.cpp $(IntermediateDirectory)/testpiecestock.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/Users/Kaendan/Documents/Code/Master/S2/PJI/FMP/tests/testpiecestock.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/testpiecestock.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/testpiecestock.cpp$(DependSuffix): testpiecestock.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/testpiecestock.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/testpiecestock.cpp$(DependSuffix) -MM "testpiecestock.cpp"

$(IntermediateDirectory)/testpiecestock.cpp$(PreprocessSuffix): testpiecestock.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/testpiecestock.cpp$(PreprocessSuffix) "testpiecestock.cpp"

$(IntermediateDirectory)/testplayer.cpp$(ObjectSuffix): testplayer.cpp $(IntermediateDirectory)/testplayer.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/Users/Kaendan/Documents/Code/Master/S2/PJI/FMP/tests/testplayer.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/testplayer.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/testplayer.cpp$(DependSuffix): testplayer.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/testplayer.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/testplayer.cpp$(DependSuffix) -MM "testplayer.cpp"

$(IntermediateDirectory)/testplayer.cpp$(PreprocessSuffix): testplayer.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/testplayer.cpp$(PreprocessSuffix) "testplayer.cpp"


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r ./Debug/


