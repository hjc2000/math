#include "rtw_capi.h"
#ifdef HOST_CAPI_BUILD
#include "s5_1_capi_host.h"
#define sizeof(s) ((size_t)(0xFFFF))
#undef rt_offsetof
#define rt_offsetof(s,el) ((uint16_T)(0xFFFF))
#define TARGET_CONST
#define TARGET_STRING(s) (s)    
#ifndef SS_INT64
#define SS_INT64  15
#endif
#ifndef SS_UINT64
#define SS_UINT64  16
#endif
#else
#include "builtin_typeid_types.h"
#include "s5_1.h"
#include "s5_1_capi.h"
#include "s5_1_private.h"
#ifdef LIGHT_WEIGHT_CAPI
#define TARGET_CONST                  
#define TARGET_STRING(s)               (NULL)                    
#else
#define TARGET_CONST                   const
#define TARGET_STRING(s)               (s)
#endif
#endif
static const rtwCAPI_Signals rtBlockSignals [ ] = { { 0 , 0 , TARGET_STRING (
"s5_1/Pulse Generator" ) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 1 ,
0 , TARGET_STRING ( "s5_1/Gain" ) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 1
} , { 2 , 0 , TARGET_STRING ( "s5_1/Gain2" ) , TARGET_STRING ( "" ) , 0 , 0 ,
0 , 0 , 2 } , { 3 , 0 , TARGET_STRING ( "s5_1/Gain3" ) , TARGET_STRING ( "" )
, 0 , 0 , 0 , 0 , 1 } , { 4 , 0 , TARGET_STRING ( "s5_1/Sum" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 1 } , { 5 , 0 , TARGET_STRING (
"s5_1/Sum1" ) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 1 } , { 6 , 0 ,
TARGET_STRING ( "s5_1/Sum2" ) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 1 } ,
{ 7 , 0 , TARGET_STRING ( "s5_1/Sum3" ) , TARGET_STRING ( "" ) , 0 , 0 , 0 ,
0 , 1 } , { 8 , 0 , TARGET_STRING ( "s5_1/Transfer Fcn" ) , TARGET_STRING (
"" ) , 0 , 0 , 0 , 0 , 1 } , { 9 , 0 , TARGET_STRING ( "s5_1/Transfer Fcn1" )
, TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 1 } , { 10 , 0 , TARGET_STRING (
"s5_1/Transfer Fcn2" ) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 1 } , { 11 ,
0 , TARGET_STRING (
"s5_1/PID Controller/I Gain/Internal Parameters/Integral Gain" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 1 } , { 12 , 0 , TARGET_STRING (
"s5_1/PID Controller/Integrator/Continuous/Integrator" ) , TARGET_STRING ( ""
) , 0 , 0 , 0 , 0 , 1 } , { 13 , 0 , TARGET_STRING (
"s5_1/PID Controller/Parallel P Gain/Internal Parameters/Proportional Gain" )
, TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 1 } , { 14 , 0 , TARGET_STRING (
"s5_1/PID Controller/Sum/Sum_PI/Sum" ) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0
, 1 } , { 15 , 0 , TARGET_STRING (
"s5_1/PID Controller1/I Gain/Internal Parameters/Integral Gain" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 1 } , { 16 , 0 , TARGET_STRING (
"s5_1/PID Controller1/Integrator/Continuous/Integrator" ) , TARGET_STRING (
"" ) , 0 , 0 , 0 , 0 , 1 } , { 17 , 0 , TARGET_STRING (
"s5_1/PID Controller1/Parallel P Gain/Internal Parameters/Proportional Gain"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 1 } , { 18 , 0 , TARGET_STRING (
"s5_1/PID Controller1/Sum/Sum_PI/Sum" ) , TARGET_STRING ( "" ) , 0 , 0 , 0 ,
0 , 1 } , { 0 , 0 , ( NULL ) , ( NULL ) , 0 , 0 , 0 , 0 , 0 } } ; static
const rtwCAPI_BlockParameters rtBlockParameters [ ] = { { 19 , TARGET_STRING
( "s5_1/PID Controller" ) , TARGET_STRING ( "InitialConditionForIntegrator" )
, 0 , 0 , 0 } , { 20 , TARGET_STRING ( "s5_1/PID Controller1" ) ,
TARGET_STRING ( "InitialConditionForIntegrator" ) , 0 , 0 , 0 } , { 21 ,
TARGET_STRING ( "s5_1/Pulse Generator" ) , TARGET_STRING ( "Amplitude" ) , 0
, 0 , 0 } , { 22 , TARGET_STRING ( "s5_1/Pulse Generator" ) , TARGET_STRING (
"Period" ) , 0 , 0 , 0 } , { 23 , TARGET_STRING ( "s5_1/Pulse Generator" ) ,
TARGET_STRING ( "PulseWidth" ) , 0 , 0 , 0 } , { 24 , TARGET_STRING (
"s5_1/Pulse Generator" ) , TARGET_STRING ( "PhaseDelay" ) , 0 , 0 , 0 } , {
25 , TARGET_STRING ( "s5_1/Step" ) , TARGET_STRING ( "Time" ) , 0 , 0 , 0 } ,
{ 26 , TARGET_STRING ( "s5_1/Step" ) , TARGET_STRING ( "Before" ) , 0 , 0 , 0
} , { 27 , TARGET_STRING ( "s5_1/Step" ) , TARGET_STRING ( "After" ) , 0 , 0
, 0 } , { 28 , TARGET_STRING ( "s5_1/Transfer Fcn" ) , TARGET_STRING ( "A" )
, 0 , 0 , 0 } , { 29 , TARGET_STRING ( "s5_1/Transfer Fcn" ) , TARGET_STRING
( "C" ) , 0 , 0 , 0 } , { 30 , TARGET_STRING ( "s5_1/Transfer Fcn1" ) ,
TARGET_STRING ( "A" ) , 0 , 0 , 0 } , { 31 , TARGET_STRING (
"s5_1/Transfer Fcn1" ) , TARGET_STRING ( "C" ) , 0 , 0 , 0 } , { 32 ,
TARGET_STRING ( "s5_1/Transfer Fcn2" ) , TARGET_STRING ( "A" ) , 0 , 0 , 0 }
, { 33 , TARGET_STRING ( "s5_1/Transfer Fcn2" ) , TARGET_STRING ( "C" ) , 0 ,
0 , 0 } , { 0 , ( NULL ) , ( NULL ) , 0 , 0 , 0 } } ; static const
rtwCAPI_Signals rtRootInputs [ ] = { { 0 , 0 , ( NULL ) , ( NULL ) , 0 , 0 ,
0 , 0 , 0 } } ; static const rtwCAPI_Signals rtRootOutputs [ ] = { { 0 , 0 ,
( NULL ) , ( NULL ) , 0 , 0 , 0 , 0 , 0 } } ; static const
rtwCAPI_ModelParameters rtModelParameters [ ] = { { 34 , TARGET_STRING ( "Ce"
) , 0 , 0 , 0 } , { 35 , TARGET_STRING ( "I" ) , 0 , 0 , 0 } , { 36 ,
TARGET_STRING ( "I1" ) , 0 , 0 , 0 } , { 37 , TARGET_STRING ( "P" ) , 0 , 0 ,
0 } , { 38 , TARGET_STRING ( "P1" ) , 0 , 0 , 0 } , { 39 , TARGET_STRING (
"alpha" ) , 0 , 0 , 0 } , { 40 , TARGET_STRING ( "beta" ) , 0 , 0 , 0 } , { 0
, ( NULL ) , 0 , 0 , 0 } } ;
#ifndef HOST_CAPI_BUILD
static void * rtDataAddrMap [ ] = { & rtB . ir4ptz1aok , & rtB . hfxix0e0ps ,
& rtB . byxu0mepvt , & rtB . gjodmbq2og , & rtB . ax0f3h10mi , & rtB .
les1i01nxj , & rtB . f2oypmfbs0 , & rtB . djio3k0vx0 , & rtB . abnvgs1q43 , &
rtB . b4dfqwig51 , & rtB . kvbyazgzvi , & rtB . fiaan55z4q , & rtB .
gx5umhj324 , & rtB . bolufss0zt , & rtB . arjvtt3u0a , & rtB . g3sy3pjhc3 , &
rtB . c52k25pukw , & rtB . hutqefteoc , & rtB . girlacu0ci , & rtP .
PIDController_InitialConditionForIntegrator , & rtP .
PIDController1_InitialConditionForIntegrator , & rtP . PulseGenerator_Amp , &
rtP . PulseGenerator_Period , & rtP . PulseGenerator_Duty , & rtP .
PulseGenerator_PhaseDelay , & rtP . Step_Time , & rtP . Step_Y0 , & rtP .
Step_YFinal , & rtP . TransferFcn_A , & rtP . TransferFcn_C , & rtP .
TransferFcn1_A , & rtP . TransferFcn1_C , & rtP . TransferFcn2_A , & rtP .
TransferFcn2_C , & rtP . Ce , & rtP . I , & rtP . I1 , & rtP . P , & rtP . P1
, & rtP . alpha , & rtP . beta , } ; static int32_T * rtVarDimsAddrMap [ ] =
{ ( NULL ) } ;
#endif
static TARGET_CONST rtwCAPI_DataTypeMap rtDataTypeMap [ ] = { { "double" ,
"real_T" , 0 , 0 , sizeof ( real_T ) , SS_DOUBLE , 0 , 0 , 0 } } ;
#ifdef HOST_CAPI_BUILD
#undef sizeof
#endif
static TARGET_CONST rtwCAPI_ElementMap rtElementMap [ ] = { { ( NULL ) , 0 ,
0 , 0 , 0 } , } ; static const rtwCAPI_DimensionMap rtDimensionMap [ ] = { {
rtwCAPI_SCALAR , 0 , 2 , 0 } } ; static const uint_T rtDimensionArray [ ] = {
1 , 1 } ; static const real_T rtcapiStoredFloats [ ] = { - 2.0 , 0.0 , 1.0 }
; static const rtwCAPI_FixPtMap rtFixPtMap [ ] = { { ( NULL ) , ( NULL ) ,
rtwCAPI_FIX_RESERVED , 0 , 0 , 0 } , } ; static const rtwCAPI_SampleTimeMap
rtSampleTimeMap [ ] = { { ( const void * ) & rtcapiStoredFloats [ 0 ] , (
const void * ) & rtcapiStoredFloats [ 1 ] , 2 , 0 } , { ( const void * ) &
rtcapiStoredFloats [ 1 ] , ( const void * ) & rtcapiStoredFloats [ 1 ] , 0 ,
0 } , { ( const void * ) & rtcapiStoredFloats [ 1 ] , ( const void * ) &
rtcapiStoredFloats [ 2 ] , 1 , 0 } } ; static rtwCAPI_ModelMappingStaticInfo
mmiStatic = { { rtBlockSignals , 19 , rtRootInputs , 0 , rtRootOutputs , 0 }
, { rtBlockParameters , 15 , rtModelParameters , 7 } , { ( NULL ) , 0 } , {
rtDataTypeMap , rtDimensionMap , rtFixPtMap , rtElementMap , rtSampleTimeMap
, rtDimensionArray } , "float" , { 3032452465U , 3638419270U , 1205337322U ,
4248657459U } , ( NULL ) , 0 , 0 } ; const rtwCAPI_ModelMappingStaticInfo *
s5_1_GetCAPIStaticMap ( void ) { return & mmiStatic ; }
#ifndef HOST_CAPI_BUILD
void s5_1_InitializeDataMapInfo ( void ) { rtwCAPI_SetVersion ( ( *
rt_dataMapInfoPtr ) . mmi , 1 ) ; rtwCAPI_SetStaticMap ( ( *
rt_dataMapInfoPtr ) . mmi , & mmiStatic ) ; rtwCAPI_SetLoggingStaticMap ( ( *
rt_dataMapInfoPtr ) . mmi , ( NULL ) ) ; rtwCAPI_SetDataAddressMap ( ( *
rt_dataMapInfoPtr ) . mmi , rtDataAddrMap ) ; rtwCAPI_SetVarDimsAddressMap (
( * rt_dataMapInfoPtr ) . mmi , rtVarDimsAddrMap ) ;
rtwCAPI_SetInstanceLoggingInfo ( ( * rt_dataMapInfoPtr ) . mmi , ( NULL ) ) ;
rtwCAPI_SetChildMMIArray ( ( * rt_dataMapInfoPtr ) . mmi , ( NULL ) ) ;
rtwCAPI_SetChildMMIArrayLen ( ( * rt_dataMapInfoPtr ) . mmi , 0 ) ; }
#else
#ifdef __cplusplus
extern "C" {
#endif
void s5_1_host_InitializeDataMapInfo ( s5_1_host_DataMapInfo_T * dataMap ,
const char * path ) { rtwCAPI_SetVersion ( dataMap -> mmi , 1 ) ;
rtwCAPI_SetStaticMap ( dataMap -> mmi , & mmiStatic ) ;
rtwCAPI_SetDataAddressMap ( dataMap -> mmi , NULL ) ;
rtwCAPI_SetVarDimsAddressMap ( dataMap -> mmi , NULL ) ; rtwCAPI_SetPath (
dataMap -> mmi , path ) ; rtwCAPI_SetFullPath ( dataMap -> mmi , NULL ) ;
rtwCAPI_SetChildMMIArray ( dataMap -> mmi , ( NULL ) ) ;
rtwCAPI_SetChildMMIArrayLen ( dataMap -> mmi , 0 ) ; }
#ifdef __cplusplus
}
#endif
#endif
