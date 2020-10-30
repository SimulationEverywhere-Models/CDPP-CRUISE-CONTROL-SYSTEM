[top]
components : ONOFF@ONOFFController
out : testONOut testOFFOut
in : testONIn testOFFIn                                               
Link : testONIn inON@ONOFF
Link : testOFFIn inOFF@ONOFF
Link : outON@ONOFF testONOut
Link : outOFF@ONOFF testOFFOut

[ONOFF]
preparation : 00:00:00:010