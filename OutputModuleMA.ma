[top]
components : OM@OutputModule
out : testThrottle
in : testInc testDec testStp
Link : testInc inc@OM
Link : testDec dec@OM
Link : testStp stp@OM
Link : out@OM testThrottle

[OM]
incTime : 00:00:00:010
decTime : 00:00:00:015
stpTime : 00:00:00:020
