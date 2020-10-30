[top]
components : ProcessingModule
in : testInOn
in : testInOff
in : testInSet
in : testInAcc
in : testInDec
in : testInResume
in : testInBreak
in : testInGas
in : testInSpeed

out : testOutInc
out : testOutDec
out : testOutStop

Link : testInOn inON@ProcessingModule
Link : testInOff inOFF@ProcessingModule
Link : testInSet inSET@ProcessingModule
Link : testInAcc inACC@ProcessingModule
Link : testInDec inDEC@ProcessingModule
Link : testInResume inRESUME@ProcessingModule
Link : testInBreak inBREAK@ProcessingModule
Link : testInGas inGAS@ProcessingModule
Link : testInSpeed inSPEED@ProcessingModule

Link : outINC@ProcessingModule testOutInc
Link : outDEC@ProcessingModule testOutDec
Link : outSTOP@ProcessingModule testOutStop

[ProcessingModule]
components : brc@BreakController ButtonController ccsc@CCSController pc@PedalController
in : inON inOFF inSET inACC inDEC inRESUME inBREAK inGAS inSPEED
out : outINC outDEC outSTOP

Link : inON inON@ButtonController
Link : inOFF inOFF@ButtonController
Link : inSET inSET@ButtonController
Link : inACC inACC@ButtonController
Link : inDEC inDEC@ButtonController
Link : inRESUME inRESUME@ButtonController
Link : inBREAK in@brc
Link : inGAS in@pc
Link : inSPEED in_SPEED@ccsc

Link : out_INC@ccsc outINC
Link : out_DEC@ccsc outDEC
Link : out_STOP@ccsc outSTOP

Link : outON@ButtonController in_TURNEDON@ccsc
Link : outOFF@ButtonController in_TURNEDOFF@ccsc
Link : outSET@ButtonController in_SET@ccsc
Link : outACC@ButtonController in_INC@ccsc
Link : outDEC@ButtonController in_DEC@ccsc
Link : outRESUME@ButtonController in_RESUME@ccsc

Link : out@brc in_BREAK@ccsc
Link : out@pc in_GAS@ccsc

[brc]
preparation : 0:0:0:10

[pc]
preparation : 0:0:0:10

[ccsc]
preparation : 0:0:0:15


[ButtonController]
components : onOff@ONOFFController SpeedController set@Set resume@Resume
in : inON inOFF inSET inACC inDEC inRESUME
out : outON outOFF outSET outDEC outACC outRESUME

Link : inON inON@onOff
Link : inOFF inOFF@onOff
Link : outON@onOff outON
Link : outOFF@onOff outOFF

Link : inACC accIn@SpeedController
Link : inDEC decIn@SpeedController
Link : decOut@SpeedController outDEC
Link : incOut@SpeedController outACC

Link : inSET in@set
Link : out@set outSET

Link : inRESUME in@resume
Link : out@resume outRESUME

[onOff]
preparation : 0:0:0:15

[set]
preparation : 0:0:0:10

[resume]
preparation : 0:0:0:10




[SpeedController]
components : accQ@Queue decQ@Queue inc@Increase dec@Decrease 
out : incOut
out : decOut
in : accIn
in : decIn
Link : accIn in@accQ
Link : out@accQ in@inc
Link : out@inc incOut
Link : out@inc done@accQ

Link : decIn in@decQ
Link : out@decQ in@dec
Link : out@dec decOut
Link : out@dec done@decQ

[accQ]
preparation : 0:0:0:10

[decQ]
preparation : 0:0:0:10

[inc]
preparation : 0:0:0:15

[dec]
preparation : 0:0:0:15