#include "rt_logging_mmi.h"
#include "s5_1_capi.h"
#include <math.h>
#include "s5_1.h"
#include "s5_1_private.h"
#include "s5_1_dt.h"
#include "simstruc.h"
#include "fixedpoint.h"
#include "slsa_sim_engine.h"
extern void * CreateDiagnosticAsVoidPtr_wrapper ( const char * id , int nargs
, ... ) ; RTWExtModeInfo * gblRTWExtModeInfo = NULL ; void
raccelForceExtModeShutdown ( boolean_T extModeStartPktReceived ) { if ( !
extModeStartPktReceived ) { boolean_T stopRequested = false ;
rtExtModeWaitForStartPkt ( gblRTWExtModeInfo , 3 , & stopRequested ) ; }
rtExtModeShutdown ( 3 ) ; }
#include "slsv_diagnostic_codegen_c_api.h"
const int_T gblNumToFiles = 0 ; const int_T gblNumFrFiles = 0 ; const int_T
gblNumFrWksBlocks = 0 ;
#ifdef RSIM_WITH_SOLVER_MULTITASKING
boolean_T gbl_raccel_isMultitasking = 1 ;
#else
boolean_T gbl_raccel_isMultitasking = 0 ;
#endif
boolean_T gbl_raccel_tid01eq = 0 ; int_T gbl_raccel_NumST = 3 ; const char_T
* gbl_raccel_Version = "9.4 (R2020b) 29-Jul-2020" ; void
raccel_setup_MMIStateLog ( SimStruct * S ) {
#ifdef UseMMIDataLogging
rt_FillStateSigInfoFromMMI ( ssGetRTWLogInfo ( S ) , & ssGetErrorStatus ( S )
) ;
#else
UNUSED_PARAMETER ( S ) ;
#endif
} static DataMapInfo rt_dataMapInfo ; DataMapInfo * rt_dataMapInfoPtr = &
rt_dataMapInfo ; rtwCAPI_ModelMappingInfo * rt_modelMapInfoPtr = & (
rt_dataMapInfo . mmi ) ; const int_T gblNumRootInportBlks = 0 ; const int_T
gblNumModelInputs = 0 ; extern const char * gblInportFileName ; extern
rtInportTUtable * gblInportTUtables ; const int_T gblInportDataTypeIdx [ ] =
{ - 1 } ; const int_T gblInportDims [ ] = { - 1 } ; const int_T
gblInportComplex [ ] = { - 1 } ; const int_T gblInportInterpoFlag [ ] = { - 1
} ; const int_T gblInportContinuous [ ] = { - 1 } ; int_T enableFcnCallFlag [
] = { 1 , 1 , 1 } ; const char * raccelLoadInputsAndAperiodicHitTimes (
SimStruct * S , const char * inportFileName , int * matFileFormat ) { return
rt_RAccelReadInportsMatFile ( S , inportFileName , matFileFormat ) ; } B rtB
; X rtX ; DW rtDW ; static SimStruct model_S ; SimStruct * const rtS = &
model_S ; void MdlInitialize ( void ) { rtX . kogpmmnpl4 = 0.0 ; rtX .
hdgo1kk0ck = rtP . PIDController1_InitialConditionForIntegrator ; rtX .
iedzdvg3s4 = 0.0 ; rtX . g0lxrdpmdo = rtP .
PIDController_InitialConditionForIntegrator ; rtX . ha0kyatih1 = 0.0 ; } void
MdlEnable ( void ) { rtDW . nvybx3lnen = 1 ; _ssSetSampleHit ( rtS , 2 , 1 )
; _ssSetTaskTime ( rtS , 2 , ssGetT ( rtS ) ) ; _ssSetVarNextHitTime ( rtS ,
0 , ssGetT ( rtS ) ) ; ; } void MdlStart ( void ) { { bool
externalInputIsInDatasetFormat = false ; void * pISigstreamManager =
rt_GetISigstreamManager ( rtS ) ;
rtwISigstreamManagerGetInputIsInDatasetFormat ( pISigstreamManager , &
externalInputIsInDatasetFormat ) ; if ( externalInputIsInDatasetFormat ) { }
} MdlInitialize ( ) ; MdlEnable ( ) ; } void MdlOutputs ( int_T tid ) {
real_T ratio ; real_T taskTimeV ; uint32_T numCycles ; rtB . abnvgs1q43 = 0.0
; rtB . abnvgs1q43 += rtP . TransferFcn_C * rtX . kogpmmnpl4 ; rtB .
hfxix0e0ps = 1.0 / rtP . Ce * rtB . abnvgs1q43 ; if ( ssIsSampleHit ( rtS , 1
, 0 ) ) { rtDW . dk5h0xwq0l = ( ssGetTaskTime ( rtS , 1 ) >= rtP . Step_Time
) ; if ( rtDW . dk5h0xwq0l == 1 ) { taskTimeV = rtP . Step_YFinal ; } else {
taskTimeV = rtP . Step_Y0 ; } rtB . byxu0mepvt = 1.0 / rtP . alpha *
taskTimeV ; } rtB . f2oypmfbs0 = rtB . byxu0mepvt - rtB . hfxix0e0ps ; rtB .
hutqefteoc = rtP . P1 * rtB . f2oypmfbs0 ; rtB . c52k25pukw = rtX .
hdgo1kk0ck ; rtB . girlacu0ci = rtB . hutqefteoc + rtB . c52k25pukw ; rtB .
gjodmbq2og = 1.0 / rtP . beta * rtB . girlacu0ci ; rtB . b4dfqwig51 = 0.0 ;
rtB . b4dfqwig51 += rtP . TransferFcn1_C * rtX . iedzdvg3s4 ; rtB .
djio3k0vx0 = rtB . gjodmbq2og - rtB . b4dfqwig51 ; rtB . fiaan55z4q = rtP . I
* rtB . djio3k0vx0 ; rtB . gx5umhj324 = rtX . g0lxrdpmdo ; rtB . bolufss0zt =
rtP . P * rtB . djio3k0vx0 ; rtB . arjvtt3u0a = rtB . bolufss0zt + rtB .
gx5umhj324 ; rtB . g3sy3pjhc3 = rtP . I1 * rtB . f2oypmfbs0 ; if (
ssIsSampleHit ( rtS , 2 , 0 ) ) { taskTimeV = ssGetTaskTime ( rtS , 2 ) ; if
( ssGetTNextWasAdjusted ( rtS , 2 ) ) { rtDW . dttnef2i21 =
_ssGetVarNextHitTime ( rtS , 0 ) ; } if ( rtDW . nvybx3lnen != 0 ) { rtDW .
nvybx3lnen = 0 ; if ( taskTimeV >= rtP . PulseGenerator_PhaseDelay ) { ratio
= ( taskTimeV - rtP . PulseGenerator_PhaseDelay ) / rtP .
PulseGenerator_Period ; numCycles = ( uint32_T ) muDoubleScalarFloor ( ratio
) ; if ( muDoubleScalarAbs ( ( real_T ) ( numCycles + 1U ) - ratio ) <
DBL_EPSILON * ratio ) { numCycles ++ ; } rtDW . c44ymysp45 = numCycles ;
ratio = ( ( real_T ) numCycles * rtP . PulseGenerator_Period + rtP .
PulseGenerator_PhaseDelay ) + rtP . PulseGenerator_Duty * rtP .
PulseGenerator_Period / 100.0 ; if ( taskTimeV < ratio ) { rtDW . oaqaq41rot
= 1 ; rtDW . dttnef2i21 = ratio ; } else { rtDW . oaqaq41rot = 0 ; rtDW .
dttnef2i21 = ( real_T ) ( numCycles + 1U ) * rtP . PulseGenerator_Period +
rtP . PulseGenerator_PhaseDelay ; } } else { rtDW . c44ymysp45 = rtP .
PulseGenerator_PhaseDelay != 0.0 ? - 1 : 0 ; rtDW . oaqaq41rot = 0 ; rtDW .
dttnef2i21 = rtP . PulseGenerator_PhaseDelay ; } } else { if ( rtDW .
dttnef2i21 <= taskTimeV ) { if ( rtDW . oaqaq41rot == 1 ) { rtDW . oaqaq41rot
= 0 ; rtDW . dttnef2i21 = ( real_T ) ( rtDW . c44ymysp45 + 1LL ) * rtP .
PulseGenerator_Period + rtP . PulseGenerator_PhaseDelay ; } else { rtDW .
c44ymysp45 ++ ; rtDW . oaqaq41rot = 1 ; rtDW . dttnef2i21 = ( rtP .
PulseGenerator_Duty * rtP . PulseGenerator_Period * 0.01 + ( real_T ) rtDW .
c44ymysp45 * rtP . PulseGenerator_Period ) + rtP . PulseGenerator_PhaseDelay
; } } } _ssSetVarNextHitTime ( rtS , 0 , rtDW . dttnef2i21 ) ; if ( rtDW .
oaqaq41rot == 1 ) { rtB . ir4ptz1aok = rtP . PulseGenerator_Amp ; } else {
rtB . ir4ptz1aok = 0.0 ; } } rtB . ax0f3h10mi = rtB . b4dfqwig51 - rtB .
ir4ptz1aok ; rtB . kvbyazgzvi = 0.0 ; rtB . kvbyazgzvi += rtP .
TransferFcn2_C * rtX . ha0kyatih1 ; rtB . les1i01nxj = rtB . kvbyazgzvi - rtB
. abnvgs1q43 ; UNUSED_PARAMETER ( tid ) ; } void MdlUpdate ( int_T tid ) {
UNUSED_PARAMETER ( tid ) ; } void MdlDerivatives ( void ) { XDot * _rtXdot ;
_rtXdot = ( ( XDot * ) ssGetdX ( rtS ) ) ; _rtXdot -> kogpmmnpl4 = 0.0 ;
_rtXdot -> kogpmmnpl4 += rtP . TransferFcn_A * rtX . kogpmmnpl4 ; _rtXdot ->
kogpmmnpl4 += rtB . ax0f3h10mi ; _rtXdot -> hdgo1kk0ck = rtB . g3sy3pjhc3 ;
_rtXdot -> iedzdvg3s4 = 0.0 ; _rtXdot -> iedzdvg3s4 += rtP . TransferFcn1_A *
rtX . iedzdvg3s4 ; _rtXdot -> iedzdvg3s4 += rtB . les1i01nxj ; _rtXdot ->
g0lxrdpmdo = rtB . fiaan55z4q ; _rtXdot -> ha0kyatih1 = 0.0 ; _rtXdot ->
ha0kyatih1 += rtP . TransferFcn2_A * rtX . ha0kyatih1 ; _rtXdot -> ha0kyatih1
+= rtB . arjvtt3u0a ; } void MdlProjection ( void ) { } void MdlZeroCrossings
( void ) { ZCV * _rtZCSV ; _rtZCSV = ( ( ZCV * ) ssGetSolverZcSignalVector (
rtS ) ) ; _rtZCSV -> jhtyijhbrb = ssGetT ( rtS ) - rtP . Step_Time ; } void
MdlTerminate ( void ) { } void MdlInitializeSizes ( void ) {
ssSetNumContStates ( rtS , 5 ) ; ssSetNumPeriodicContStates ( rtS , 0 ) ;
ssSetNumY ( rtS , 0 ) ; ssSetNumU ( rtS , 0 ) ; ssSetDirectFeedThrough ( rtS
, 0 ) ; ssSetNumSampleTimes ( rtS , 3 ) ; ssSetNumBlocks ( rtS , 21 ) ;
ssSetNumBlockIO ( rtS , 19 ) ; ssSetNumBlockParams ( rtS , 22 ) ; } void
MdlInitializeSampleTimes ( void ) { ssSetSampleTime ( rtS , 0 , 0.0 ) ;
ssSetSampleTime ( rtS , 1 , 0.0 ) ; ssSetSampleTime ( rtS , 2 , - 2.0 ) ;
ssSetOffsetTime ( rtS , 0 , 0.0 ) ; ssSetOffsetTime ( rtS , 1 , 1.0 ) ;
ssSetOffsetTime ( rtS , 2 , 0.0 ) ; } void raccel_set_checksum ( ) {
ssSetChecksumVal ( rtS , 0 , 3032452465U ) ; ssSetChecksumVal ( rtS , 1 ,
3638419270U ) ; ssSetChecksumVal ( rtS , 2 , 1205337322U ) ; ssSetChecksumVal
( rtS , 3 , 4248657459U ) ; }
#if defined(_MSC_VER)
#pragma optimize( "", off )
#endif
SimStruct * raccel_register_model ( ssExecutionInfo * executionInfo ) {
static struct _ssMdlInfo mdlInfo ; ( void ) memset ( ( char * ) rtS , 0 ,
sizeof ( SimStruct ) ) ; ( void ) memset ( ( char * ) & mdlInfo , 0 , sizeof
( struct _ssMdlInfo ) ) ; ssSetMdlInfoPtr ( rtS , & mdlInfo ) ;
ssSetExecutionInfo ( rtS , executionInfo ) ; { static time_T mdlPeriod [
NSAMPLE_TIMES ] ; static time_T mdlOffset [ NSAMPLE_TIMES ] ; static time_T
mdlTaskTimes [ NSAMPLE_TIMES ] ; static int_T mdlTsMap [ NSAMPLE_TIMES ] ;
static int_T mdlSampleHits [ NSAMPLE_TIMES ] ; static boolean_T
mdlTNextWasAdjustedPtr [ NSAMPLE_TIMES ] ; static int_T mdlPerTaskSampleHits
[ NSAMPLE_TIMES * NSAMPLE_TIMES ] ; static time_T mdlTimeOfNextSampleHit [
NSAMPLE_TIMES ] ; { int_T i ; for ( i = 0 ; i < NSAMPLE_TIMES ; i ++ ) {
mdlPeriod [ i ] = 0.0 ; mdlOffset [ i ] = 0.0 ; mdlTaskTimes [ i ] = 0.0 ;
mdlTsMap [ i ] = i ; mdlSampleHits [ i ] = 1 ; } } ssSetSampleTimePtr ( rtS ,
& mdlPeriod [ 0 ] ) ; ssSetOffsetTimePtr ( rtS , & mdlOffset [ 0 ] ) ;
ssSetSampleTimeTaskIDPtr ( rtS , & mdlTsMap [ 0 ] ) ; ssSetTPtr ( rtS , &
mdlTaskTimes [ 0 ] ) ; ssSetSampleHitPtr ( rtS , & mdlSampleHits [ 0 ] ) ;
ssSetTNextWasAdjustedPtr ( rtS , & mdlTNextWasAdjustedPtr [ 0 ] ) ;
ssSetPerTaskSampleHitsPtr ( rtS , & mdlPerTaskSampleHits [ 0 ] ) ;
ssSetTimeOfNextSampleHitPtr ( rtS , & mdlTimeOfNextSampleHit [ 0 ] ) ; }
ssSetSolverMode ( rtS , SOLVER_MODE_SINGLETASKING ) ; { ssSetBlockIO ( rtS ,
( ( void * ) & rtB ) ) ; ssSetWorkSizeInBytes ( rtS , sizeof ( rtB ) ,
"BlockIO" ) ; ( void ) memset ( ( ( void * ) & rtB ) , 0 , sizeof ( B ) ) ; }
{ real_T * x = ( real_T * ) & rtX ; ssSetContStates ( rtS , x ) ; ( void )
memset ( ( void * ) x , 0 , sizeof ( X ) ) ; } { void * dwork = ( void * ) &
rtDW ; ssSetRootDWork ( rtS , dwork ) ; ssSetWorkSizeInBytes ( rtS , sizeof (
rtDW ) , "DWork" ) ; ( void ) memset ( dwork , 0 , sizeof ( DW ) ) ; } {
static DataTypeTransInfo dtInfo ; ( void ) memset ( ( char_T * ) & dtInfo , 0
, sizeof ( dtInfo ) ) ; ssSetModelMappingInfo ( rtS , & dtInfo ) ; dtInfo .
numDataTypes = 17 ; dtInfo . dataTypeSizes = & rtDataTypeSizes [ 0 ] ; dtInfo
. dataTypeNames = & rtDataTypeNames [ 0 ] ; dtInfo . BTransTable = &
rtBTransTable ; dtInfo . PTransTable = & rtPTransTable ; dtInfo .
dataTypeInfoTable = rtDataTypeInfoTable ; } s5_1_InitializeDataMapInfo ( ) ;
ssSetIsRapidAcceleratorActive ( rtS , true ) ; ssSetRootSS ( rtS , rtS ) ;
ssSetVersion ( rtS , SIMSTRUCT_VERSION_LEVEL2 ) ; ssSetModelName ( rtS ,
"s5_1" ) ; ssSetPath ( rtS , "s5_1" ) ; ssSetTStart ( rtS , 0.0 ) ;
ssSetTFinal ( rtS , 20.0 ) ; { static RTWLogInfo rt_DataLoggingInfo ;
rt_DataLoggingInfo . loggingInterval = NULL ; ssSetRTWLogInfo ( rtS , &
rt_DataLoggingInfo ) ; } { { static int_T rt_LoggedStateWidths [ ] = { 1 , 1
, 1 , 1 , 1 } ; static int_T rt_LoggedStateNumDimensions [ ] = { 1 , 1 , 1 ,
1 , 1 } ; static int_T rt_LoggedStateDimensions [ ] = { 1 , 1 , 1 , 1 , 1 } ;
static boolean_T rt_LoggedStateIsVarDims [ ] = { 0 , 0 , 0 , 0 , 0 } ; static
BuiltInDTypeId rt_LoggedStateDataTypeIds [ ] = { SS_DOUBLE , SS_DOUBLE ,
SS_DOUBLE , SS_DOUBLE , SS_DOUBLE } ; static int_T
rt_LoggedStateComplexSignals [ ] = { 0 , 0 , 0 , 0 , 0 } ; static
RTWPreprocessingFcnPtr rt_LoggingStatePreprocessingFcnPtrs [ ] = { ( NULL ) ,
( NULL ) , ( NULL ) , ( NULL ) , ( NULL ) } ; static const char_T *
rt_LoggedStateLabels [ ] = { "CSTATE" , "CSTATE" , "CSTATE" , "CSTATE" ,
"CSTATE" } ; static const char_T * rt_LoggedStateBlockNames [ ] = {
"s5_1/Transfer Fcn" , "s5_1/PID Controller1/Integrator/Continuous/Integrator"
, "s5_1/Transfer Fcn1" ,
"s5_1/PID Controller/Integrator/Continuous/Integrator" , "s5_1/Transfer Fcn2"
} ; static const char_T * rt_LoggedStateNames [ ] = { "" , "" , "" , "" , ""
} ; static boolean_T rt_LoggedStateCrossMdlRef [ ] = { 0 , 0 , 0 , 0 , 0 } ;
static RTWLogDataTypeConvert rt_RTWLogDataTypeConvert [ ] = { { 0 , SS_DOUBLE
, SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } , { 0 , SS_DOUBLE , SS_DOUBLE , 0 ,
0 , 0 , 1.0 , 0 , 0.0 } , { 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 ,
0.0 } , { 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } , { 0 ,
SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } } ; static
RTWLogSignalInfo rt_LoggedStateSignalInfo = { 5 , rt_LoggedStateWidths ,
rt_LoggedStateNumDimensions , rt_LoggedStateDimensions ,
rt_LoggedStateIsVarDims , ( NULL ) , ( NULL ) , rt_LoggedStateDataTypeIds ,
rt_LoggedStateComplexSignals , ( NULL ) , rt_LoggingStatePreprocessingFcnPtrs
, { rt_LoggedStateLabels } , ( NULL ) , ( NULL ) , ( NULL ) , {
rt_LoggedStateBlockNames } , { rt_LoggedStateNames } ,
rt_LoggedStateCrossMdlRef , rt_RTWLogDataTypeConvert } ; static void *
rt_LoggedStateSignalPtrs [ 5 ] ; rtliSetLogXSignalPtrs ( ssGetRTWLogInfo (
rtS ) , ( LogSignalPtrsType ) rt_LoggedStateSignalPtrs ) ;
rtliSetLogXSignalInfo ( ssGetRTWLogInfo ( rtS ) , & rt_LoggedStateSignalInfo
) ; rt_LoggedStateSignalPtrs [ 0 ] = ( void * ) & rtX . kogpmmnpl4 ;
rt_LoggedStateSignalPtrs [ 1 ] = ( void * ) & rtX . hdgo1kk0ck ;
rt_LoggedStateSignalPtrs [ 2 ] = ( void * ) & rtX . iedzdvg3s4 ;
rt_LoggedStateSignalPtrs [ 3 ] = ( void * ) & rtX . g0lxrdpmdo ;
rt_LoggedStateSignalPtrs [ 4 ] = ( void * ) & rtX . ha0kyatih1 ; }
rtliSetLogT ( ssGetRTWLogInfo ( rtS ) , "tout" ) ; rtliSetLogX (
ssGetRTWLogInfo ( rtS ) , "" ) ; rtliSetLogXFinal ( ssGetRTWLogInfo ( rtS ) ,
"" ) ; rtliSetLogVarNameModifier ( ssGetRTWLogInfo ( rtS ) , "none" ) ;
rtliSetLogFormat ( ssGetRTWLogInfo ( rtS ) , 4 ) ; rtliSetLogMaxRows (
ssGetRTWLogInfo ( rtS ) , 0 ) ; rtliSetLogDecimation ( ssGetRTWLogInfo ( rtS
) , 1 ) ; rtliSetLogY ( ssGetRTWLogInfo ( rtS ) , "" ) ;
rtliSetLogYSignalInfo ( ssGetRTWLogInfo ( rtS ) , ( NULL ) ) ;
rtliSetLogYSignalPtrs ( ssGetRTWLogInfo ( rtS ) , ( NULL ) ) ; } { static
struct _ssStatesInfo2 statesInfo2 ; ssSetStatesInfo2 ( rtS , & statesInfo2 )
; } { static ssPeriodicStatesInfo periodicStatesInfo ;
ssSetPeriodicStatesInfo ( rtS , & periodicStatesInfo ) ; } { static
ssJacobianPerturbationBounds jacobianPerturbationBounds ;
ssSetJacobianPerturbationBounds ( rtS , & jacobianPerturbationBounds ) ; } {
static ssSolverInfo slvrInfo ; static boolean_T contStatesDisabled [ 5 ] ;
static real_T absTol [ 5 ] = { 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 } ;
static uint8_T absTolControl [ 5 ] = { 0U , 0U , 0U , 0U , 0U } ; static
real_T contStateJacPerturbBoundMinVec [ 5 ] ; static real_T
contStateJacPerturbBoundMaxVec [ 5 ] ; static uint8_T zcAttributes [ 1 ] = {
( ZC_EVENT_ALL_UP ) } ; static ssNonContDerivSigInfo nonContDerivSigInfo [ 2
] = { { 1 * sizeof ( real_T ) , ( char * ) ( & rtB . ir4ptz1aok ) , ( NULL )
} , { 1 * sizeof ( real_T ) , ( char * ) ( & rtB . byxu0mepvt ) , ( NULL ) }
} ; { int i ; for ( i = 0 ; i < 5 ; ++ i ) { contStateJacPerturbBoundMinVec [
i ] = 0 ; contStateJacPerturbBoundMaxVec [ i ] = rtGetInf ( ) ; } }
ssSetSolverRelTol ( rtS , 0.001 ) ; ssSetStepSize ( rtS , 0.0 ) ;
ssSetMinStepSize ( rtS , 0.0 ) ; ssSetMaxNumMinSteps ( rtS , - 1 ) ;
ssSetMinStepViolatedError ( rtS , 0 ) ; ssSetMaxStepSize ( rtS , 0.4 ) ;
ssSetSolverMaxOrder ( rtS , - 1 ) ; ssSetSolverRefineFactor ( rtS , 1 ) ;
ssSetOutputTimes ( rtS , ( NULL ) ) ; ssSetNumOutputTimes ( rtS , 0 ) ;
ssSetOutputTimesOnly ( rtS , 0 ) ; ssSetOutputTimesIndex ( rtS , 0 ) ;
ssSetZCCacheNeedsReset ( rtS , 0 ) ; ssSetDerivCacheNeedsReset ( rtS , 0 ) ;
ssSetNumNonContDerivSigInfos ( rtS , 2 ) ; ssSetNonContDerivSigInfos ( rtS ,
nonContDerivSigInfo ) ; ssSetSolverInfo ( rtS , & slvrInfo ) ;
ssSetSolverName ( rtS , "VariableStepAuto" ) ; ssSetVariableStepSolver ( rtS
, 1 ) ; ssSetSolverConsistencyChecking ( rtS , 0 ) ;
ssSetSolverAdaptiveZcDetection ( rtS , 0 ) ; ssSetSolverRobustResetMethod (
rtS , 0 ) ; ssSetAbsTolVector ( rtS , absTol ) ; ssSetAbsTolControlVector (
rtS , absTolControl ) ; ssSetSolverAbsTol_Obsolete ( rtS , absTol ) ;
ssSetSolverAbsTolControl_Obsolete ( rtS , absTolControl ) ;
ssSetJacobianPerturbationBoundsMinVec ( rtS , contStateJacPerturbBoundMinVec
) ; ssSetJacobianPerturbationBoundsMaxVec ( rtS ,
contStateJacPerturbBoundMaxVec ) ; ssSetSolverStateProjection ( rtS , 0 ) ;
ssSetSolverMassMatrixType ( rtS , ( ssMatrixType ) 0 ) ;
ssSetSolverMassMatrixNzMax ( rtS , 0 ) ; ssSetModelOutputs ( rtS , MdlOutputs
) ; ssSetModelLogData ( rtS , rt_UpdateTXYLogVars ) ;
ssSetModelLogDataIfInInterval ( rtS , rt_UpdateTXXFYLogVars ) ;
ssSetModelUpdate ( rtS , MdlUpdate ) ; ssSetModelDerivatives ( rtS ,
MdlDerivatives ) ; ssSetSolverZcSignalAttrib ( rtS , zcAttributes ) ;
ssSetSolverNumZcSignals ( rtS , 1 ) ; ssSetModelZeroCrossings ( rtS ,
MdlZeroCrossings ) ; ssSetSolverConsecutiveZCsStepRelTol ( rtS ,
2.8421709430404007E-13 ) ; ssSetSolverMaxConsecutiveZCs ( rtS , 1000 ) ;
ssSetSolverConsecutiveZCsError ( rtS , 2 ) ; ssSetSolverMaskedZcDiagnostic (
rtS , 1 ) ; ssSetSolverIgnoredZcDiagnostic ( rtS , 1 ) ;
ssSetSolverMaxConsecutiveMinStep ( rtS , 1 ) ;
ssSetSolverShapePreserveControl ( rtS , 2 ) ; ssSetTNextTid ( rtS , INT_MIN )
; ssSetTNext ( rtS , rtMinusInf ) ; ssSetSolverNeedsReset ( rtS ) ;
ssSetNumNonsampledZCs ( rtS , 1 ) ; ssSetContStateDisabled ( rtS ,
contStatesDisabled ) ; ssSetSolverMaxConsecutiveMinStep ( rtS , 1 ) ; }
ssSetChecksumVal ( rtS , 0 , 3032452465U ) ; ssSetChecksumVal ( rtS , 1 ,
3638419270U ) ; ssSetChecksumVal ( rtS , 2 , 1205337322U ) ; ssSetChecksumVal
( rtS , 3 , 4248657459U ) ; { static const sysRanDType rtAlwaysEnabled =
SUBSYS_RAN_BC_ENABLE ; static RTWExtModeInfo rt_ExtModeInfo ; static const
sysRanDType * systemRan [ 1 ] ; gblRTWExtModeInfo = & rt_ExtModeInfo ;
ssSetRTWExtModeInfo ( rtS , & rt_ExtModeInfo ) ;
rteiSetSubSystemActiveVectorAddresses ( & rt_ExtModeInfo , systemRan ) ;
systemRan [ 0 ] = & rtAlwaysEnabled ; rteiSetModelMappingInfoPtr (
ssGetRTWExtModeInfo ( rtS ) , & ssGetModelMappingInfo ( rtS ) ) ;
rteiSetChecksumsPtr ( ssGetRTWExtModeInfo ( rtS ) , ssGetChecksums ( rtS ) )
; rteiSetTPtr ( ssGetRTWExtModeInfo ( rtS ) , ssGetTPtr ( rtS ) ) ; } return
rtS ; }
#if defined(_MSC_VER)
#pragma optimize( "", on )
#endif
const int_T gblParameterTuningTid = - 1 ; void MdlOutputsParameterSampleTime
( int_T tid ) { UNUSED_PARAMETER ( tid ) ; }
