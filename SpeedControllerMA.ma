[top]
components : SpeedController
out : testIncOut
out : testDecOut
in : testAccIn
in : testDecIn
Link : testAccIn accIn@SpeedController
Link : testDecIn decIn@SpeedController
Link : incOut@SpeedController testIncOut
Link : decOut@SpeedController testDecOut 

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