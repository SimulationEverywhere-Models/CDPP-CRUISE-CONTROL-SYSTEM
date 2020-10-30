[top]
components : CCSC@CCSController
out : testOut_INC
out : testOut_DEC
out : testOut_STOP
in : testIn_TURNEDON
in : testIn_TURNEDOFF
in : testIn_INC
in : testIn_DEC
in : testIn_SET
in : testIn_RESUME
in : testIn_BREAK
in : testIn_GAS
in : testIn_SPEED
Link : testIn_TURNEDON in_TURNEDON@CCSC
Link : testIn_TURNEDOFF in_TURNEDOFF@CCSC
Link : testIn_INC in_INC@CCSC
Link : testIn_DEC in_DEC@CCSC
Link : testIn_SET in_SET@CCSC
Link : testIn_RESUME in_RESUME@CCSC
Link : testIn_BREAK in_BREAK@CCSC
Link : testIn_GAS in_GAS@CCSC
Link : testIn_SPEED in_SPEED@CCSC

Link : out_INC@CCSC testOut_INC
Link : out_DEC@CCSC testOut_DEC
Link : out_STOP@CCSC testOut_STOP

[CCSC]
preparation : 00:00:00:010
