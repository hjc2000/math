#ifndef RTW_HEADER_s5_1_h_
#define RTW_HEADER_s5_1_h_
#include <stddef.h>
#include <float.h>
#include <string.h>
#include "rtw_modelmap.h"
#ifndef s5_1_COMMON_INCLUDES_
#define s5_1_COMMON_INCLUDES_
#include <stdlib.h>
#include "rtwtypes.h"
#include "sigstream_rtw.h"
#include "simtarget/slSimTgtSigstreamRTW.h"
#include "simtarget/slSimTgtSlioCoreRTW.h"
#include "simtarget/slSimTgtSlioClientsRTW.h"
#include "simtarget/slSimTgtSlioSdiRTW.h"
#include "simstruc.h"
#include "fixedpoint.h"
#include "raccel.h"
#include "slsv_diagnostic_codegen_c_api.h"
#include "rt_logging.h"
#include "dt_info.h"
#include "ext_work.h"
#endif
#include "s5_1_types.h"
#include "multiword_types.h"
#include "mwmathutil.h"
#include "rt_defines.h"
#include "rtGetInf.h"
#include "rt_nonfinite.h"
#define MODEL_NAME s5_1
#define NSAMPLE_TIMES (3) 
#define NINPUTS (0)       
#define NOUTPUTS (0)     
#define NBLOCKIO (19) 
#define NUM_ZC_EVENTS (0) 
#ifndef NCSTATES
#define NCSTATES (5)   
#elif NCSTATES != 5
#error Invalid specification of NCSTATES defined in compiler command
#endif
#ifndef rtmGetDataMapInfo
#define rtmGetDataMapInfo(rtm) (*rt_dataMapInfoPtr)
#endif
#ifndef rtmSetDataMapInfo
#define rtmSetDataMapInfo(rtm, val) (rt_dataMapInfoPtr = &val)
#endif
#ifndef IN_RACCEL_MAIN
#endif
typedef struct { real_T abnvgs1q43 ; real_T hfxix0e0ps ; real_T byxu0mepvt ;
real_T f2oypmfbs0 ; real_T hutqefteoc ; real_T c52k25pukw ; real_T girlacu0ci
; real_T gjodmbq2og ; real_T b4dfqwig51 ; real_T djio3k0vx0 ; real_T
fiaan55z4q ; real_T gx5umhj324 ; real_T bolufss0zt ; real_T arjvtt3u0a ;
real_T g3sy3pjhc3 ; real_T ir4ptz1aok ; real_T ax0f3h10mi ; real_T kvbyazgzvi
; real_T les1i01nxj ; } B ; typedef struct { real_T dttnef2i21 ; int64_T
c44ymysp45 ; struct { void * LoggedData ; } dr1oipabeo ; int32_T nvybx3lnen ;
int32_T oaqaq41rot ; int_T dk5h0xwq0l ; } DW ; typedef struct { real_T
kogpmmnpl4 ; real_T hdgo1kk0ck ; real_T iedzdvg3s4 ; real_T g0lxrdpmdo ;
real_T ha0kyatih1 ; } X ; typedef struct { real_T kogpmmnpl4 ; real_T
hdgo1kk0ck ; real_T iedzdvg3s4 ; real_T g0lxrdpmdo ; real_T ha0kyatih1 ; }
XDot ; typedef struct { boolean_T kogpmmnpl4 ; boolean_T hdgo1kk0ck ;
boolean_T iedzdvg3s4 ; boolean_T g0lxrdpmdo ; boolean_T ha0kyatih1 ; } XDis ;
typedef struct { real_T kogpmmnpl4 ; real_T hdgo1kk0ck ; real_T iedzdvg3s4 ;
real_T g0lxrdpmdo ; real_T ha0kyatih1 ; } CStateAbsTol ; typedef struct {
real_T kogpmmnpl4 ; real_T hdgo1kk0ck ; real_T iedzdvg3s4 ; real_T g0lxrdpmdo
; real_T ha0kyatih1 ; } CXPtMin ; typedef struct { real_T kogpmmnpl4 ; real_T
hdgo1kk0ck ; real_T iedzdvg3s4 ; real_T g0lxrdpmdo ; real_T ha0kyatih1 ; }
CXPtMax ; typedef struct { real_T jhtyijhbrb ; } ZCV ; typedef struct {
rtwCAPI_ModelMappingInfo mmi ; } DataMapInfo ; struct P_ { real_T Ce ; real_T
I ; real_T I1 ; real_T P ; real_T P1 ; real_T alpha ; real_T beta ; real_T
PIDController1_InitialConditionForIntegrator ; real_T
PIDController_InitialConditionForIntegrator ; real_T TransferFcn_A ; real_T
TransferFcn_C ; real_T Step_Time ; real_T Step_Y0 ; real_T Step_YFinal ;
real_T TransferFcn1_A ; real_T TransferFcn1_C ; real_T PulseGenerator_Amp ;
real_T PulseGenerator_Period ; real_T PulseGenerator_Duty ; real_T
PulseGenerator_PhaseDelay ; real_T TransferFcn2_A ; real_T TransferFcn2_C ; }
; extern const char * RT_MEMORY_ALLOCATION_ERROR ; extern B rtB ; extern X
rtX ; extern DW rtDW ; extern P rtP ; extern const
rtwCAPI_ModelMappingStaticInfo * s5_1_GetCAPIStaticMap ( void ) ; extern
SimStruct * const rtS ; extern const int_T gblNumToFiles ; extern const int_T
gblNumFrFiles ; extern const int_T gblNumFrWksBlocks ; extern rtInportTUtable
* gblInportTUtables ; extern const char * gblInportFileName ; extern const
int_T gblNumRootInportBlks ; extern const int_T gblNumModelInputs ; extern
const int_T gblInportDataTypeIdx [ ] ; extern const int_T gblInportDims [ ] ;
extern const int_T gblInportComplex [ ] ; extern const int_T
gblInportInterpoFlag [ ] ; extern const int_T gblInportContinuous [ ] ;
extern const int_T gblParameterTuningTid ; extern DataMapInfo *
rt_dataMapInfoPtr ; extern rtwCAPI_ModelMappingInfo * rt_modelMapInfoPtr ;
void MdlOutputs ( int_T tid ) ; void MdlOutputsParameterSampleTime ( int_T
tid ) ; void MdlUpdate ( int_T tid ) ; void MdlTerminate ( void ) ; void
MdlInitializeSizes ( void ) ; void MdlInitializeSampleTimes ( void ) ;
SimStruct * raccel_register_model ( ssExecutionInfo * executionInfo ) ;
#endif
