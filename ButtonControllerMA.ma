[top]
components : ButtonController
in : testInOn
in : testInOff
in : testInSet
in : testInAcc
in : testInDec
in : testInResume
out : testOutTurnOn
out : testOutTurnOff
out : testOutDec
out : testOutInc
out : testOutSet
out : testOutResume

Link : testInOn inON@ButtonController
Link : testInOff inOFF@ButtonController
Link : testInSet inSET@ButtonController
Link : testInAcc inACC@ButtonController
Link : testInDec inDEC@ButtonController
Link : testInResume inRESUME@ButtonController

Link : outON@ButtonController testOutTurnOn
Link : outOFF@ButtonController testOutTurnOff
Link : outSET@ButtonController testOutSet
Link : outDEC@ButtonController testOutDec
Link : outACC@ButtonController testOutInc
Link : outRESUME@ButtonController testOutResume

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