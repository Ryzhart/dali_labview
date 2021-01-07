///
/// 
///\brief DALI command definition file.
///		   
///\version 2.5.5
///\date    29.11.2008
///
/// File history:
///	[29.11.2008]	added "doxygen style" documentation
///			cleaned up from unused or obsolete constants
///	[18.07.2008]	added DALI V1 (IEC 62386-102) commands
/// 

#ifndef  __DALICOMMANDS_H_
  #define  __DALICOMMANDS_H_




// DALI defined device types 
#define  DALIDEVTYPE_BALLAST                               0
#define  DALIDEVTYPE_EMERGENCY                             1
#define  DALIDEVTYPE_HID                                   2
#define  DALIDEVTYPE_HALOGEN                               3 
#define  DALIDEVTYPE_INCANDECENT                           4
#define  DALIDEVTYPE_CONVERTER                             5
#define  DALIDEVTYPE_LED                                   6

#define  DALIDEVTYPE_MULTISENSOR                         254
#define  DALIDEVTYPE_UNKNOWN                             255 


// --------------------------------------------------------------------
// --------------------------------------------------------------------
// DALI commands for SendBusData() as defined in the DALI draft:  -----
// (see also: command description in the DALI draft)
// -----------------------------------------------------------------  
#define  CMD_OFF                                           0
#define  CMD_UP                                            1
#define  CMD_DOWN                                          2
#define  CMD_STEP_UP                                       3
#define  CMD_STEP_DOWN                                     4
#define  CMD_RECALL_MAX                                    5
#define  CMD_RECALL_MIN                                    6
#define  CMD_STEPDOWN_AND_OFF                              7
#define  CMD_ON_AND_STEPUP                                 8
#define  CMD_ENABLE_DAPC_SEQUENCE						   9
//                                                  reserved
#define  CMD_GOTO_SCENE0                                  16
#define  CMD_GOTO_SCENE1                                  17
#define  CMD_GOTO_SCENE2                                  18
#define  CMD_GOTO_SCENE3                                  19
#define  CMD_GOTO_SCENE4                                  20
#define  CMD_GOTO_SCENE5                                  21
#define  CMD_GOTO_SCENE6                                  22
#define  CMD_GOTO_SCENE7                                  23
#define  CMD_GOTO_SCENE8                                  24
#define  CMD_GOTO_SCENE9                                  25
#define  CMD_GOTO_SCENE10                                 26
#define  CMD_GOTO_SCENE11                                 27
#define  CMD_GOTO_SCENE12                                 28
#define  CMD_GOTO_SCENE13                                 29
#define  CMD_GOTO_SCENE14                                 30
#define  CMD_GOTO_SCENE15                                 31
#define  CMD_RESET                                        32
#define  CMD_STORE_ACTUALLEVEL_TO_DTR                     33
//                                                  reserved
#define  CMD_STORE_MAX_LEVEL                              42
#define  CMD_STORE_MIN_LEVEL                              43
#define  CMD_STORE_SYSFAIL_LEVEL                          44
#define  CMD_STORE_PWRON_LEVEL                            45
#define  CMD_STORE_FADETIME                               46
#define  CMD_STORE_FADERATE                               47
//                                                  reserved
#define  CMD_STORE_SCENE0                                 64
#define  CMD_STORE_SCENE1                                 65
#define  CMD_STORE_SCENE2                                 66
#define  CMD_STORE_SCENE3                                 67
#define  CMD_STORE_SCENE4                                 68
#define  CMD_STORE_SCENE5                                 69
#define  CMD_STORE_SCENE6                                 70
#define  CMD_STORE_SCENE7                                 71
#define  CMD_STORE_SCENE8                                 72
#define  CMD_STORE_SCENE9                                 73
#define  CMD_STORE_SCENE10                                74
#define  CMD_STORE_SCENE11                                75
#define  CMD_STORE_SCENE12                                76
#define  CMD_STORE_SCENE13                                77
#define  CMD_STORE_SCENE14                                78
#define  CMD_STORE_SCENE15                                79
#define  CMD_REMOVE_FROM_SCENE0                           80
#define  CMD_REMOVE_FROM_SCENE1                           81
#define  CMD_REMOVE_FROM_SCENE2                           82
#define  CMD_REMOVE_FROM_SCENE3                           83
#define  CMD_REMOVE_FROM_SCENE4                           84
#define  CMD_REMOVE_FROM_SCENE5                           85
#define  CMD_REMOVE_FROM_SCENE6                           86
#define  CMD_REMOVE_FROM_SCENE7                           87
#define  CMD_REMOVE_FROM_SCENE8                           88
#define  CMD_REMOVE_FROM_SCENE9                           89
#define  CMD_REMOVE_FROM_SCENE10                          90
#define  CMD_REMOVE_FROM_SCENE11                          91
#define  CMD_REMOVE_FROM_SCENE12                          92
#define  CMD_REMOVE_FROM_SCENE13                          93
#define  CMD_REMOVE_FROM_SCENE14                          94
#define  CMD_REMOVE_FROM_SCENE15                          95
#define  CMD_ADD_TO_GROUP0                                96
#define  CMD_ADD_TO_GROUP1                                97
#define  CMD_ADD_TO_GROUP2                                98
#define  CMD_ADD_TO_GROUP3                                99
#define  CMD_ADD_TO_GROUP4                               100
#define  CMD_ADD_TO_GROUP5                               101
#define  CMD_ADD_TO_GROUP6                               102
#define  CMD_ADD_TO_GROUP7                               103
#define  CMD_ADD_TO_GROUP8                               104
#define  CMD_ADD_TO_GROUP9                               105
#define  CMD_ADD_TO_GROUP10                              106
#define  CMD_ADD_TO_GROUP11                              107
#define  CMD_ADD_TO_GROUP12                              108
#define  CMD_ADD_TO_GROUP13                              109
#define  CMD_ADD_TO_GROUP14                              110
#define  CMD_ADD_TO_GROUP15                              111
#define  CMD_REMOVE_FROM_GROUP0                          112
#define  CMD_REMOVE_FROM_GROUP1                          113
#define  CMD_REMOVE_FROM_GROUP2                          114
#define  CMD_REMOVE_FROM_GROUP3                          115
#define  CMD_REMOVE_FROM_GROUP4                          116
#define  CMD_REMOVE_FROM_GROUP5                          117
#define  CMD_REMOVE_FROM_GROUP6                          118
#define  CMD_REMOVE_FROM_GROUP7                          119
#define  CMD_REMOVE_FROM_GROUP8                          120
#define  CMD_REMOVE_FROM_GROUP9                          121
#define  CMD_REMOVE_FROM_GROUP10                         122
#define  CMD_REMOVE_FROM_GROUP11                         123
#define  CMD_REMOVE_FROM_GROUP12                         124
#define  CMD_REMOVE_FROM_GROUP13                         125
#define  CMD_REMOVE_FROM_GROUP14                         126
#define  CMD_REMOVE_FROM_GROUP15                         127
#define  CMD_STORE_SHORT_ADDR                            128
#define  CMD_ENABLE_WRITE_MEMORY						 129
//                                                  reserved
#define  CMD_QUERY_STATUS                                144
#define  CMD_QUERY_BALLAST                               145
// in DALI V1 QUERY_BALLAST has been renamed:
#define  CMD_QUERY_CONTROL_GEAR                          145
#define  CMD_QUERY_LAMPFAILURE                           146
#define  CMD_QUERY_LAMP_POWERON                          147
#define  CMD_QUERY_LIMIT_ERROR                           148
#define  CMD_QUERY_RESET_STATE                           149
#define  CMD_QUERY_MISSING_SHORTADDR                     150
#define  CMD_QUERY_VERSIONNUMBER                         151
#define  CMD_QUERY_CONTENT_DTR                           152
#define  CMD_QUERY_DEVICETYPE                            153
#define  CMD_QUERY_PHYSICAL_MINIMUMLEVEL                 154
#define  CMD_QUERY_POWER_FAILURE                         155
#define  CMD_QUERY_CONTENT_DTR1                          156
#define  CMD_QUERY_CONTENT_DTR2                          157
//                                                  reserved     
#define  CMD_QUERY_ACTUAL_LEVEL                          160  
#define  CMD_QUERY_MAX_LEVEL                             161
#define  CMD_QUERY_MIN_LEVEL                             162
#define  CMD_QUERY_POWERON_LEVEL                         163  
#define  CMD_QUERY_SYSFAILLEVEL                          164
#define  CMD_QUERY_FADETIME_FADERATE                     165
//                                                  reserved
#define  CMD_QUERY_SCENELEVEL0                           176
#define  CMD_QUERY_SCENELEVEL1                           177
#define  CMD_QUERY_SCENELEVEL2                           178
#define  CMD_QUERY_SCENELEVEL3                           179
#define  CMD_QUERY_SCENELEVEL4                           180
#define  CMD_QUERY_SCENELEVEL5                           181
#define  CMD_QUERY_SCENELEVEL6                           182
#define  CMD_QUERY_SCENELEVEL7                           183
#define  CMD_QUERY_SCENELEVEL8                           184
#define  CMD_QUERY_SCENELEVEL9                           185
#define  CMD_QUERY_SCENELEVEL10                          186
#define  CMD_QUERY_SCENELEVEL11                          187
#define  CMD_QUERY_SCENELEVEL12                          188
#define  CMD_QUERY_SCENELEVEL13                          189
#define  CMD_QUERY_SCENELEVEL14                          190
#define  CMD_QUERY_SCENELEVEL15                          191
#define  CMD_QUERY_GROUPS0_7                             192
#define  CMD_QUERY_GROUPS8_15                            193
#define  CMD_QUERY_RANDOMADDRESS_H                       194
#define  CMD_QUERY_RANDOMADDRESS_M                       195
#define  CMD_QUERY_RANDOMADDRESS_L                       196
#define  CMD_READ_MEMORY_LOCATION                        197
//                                                  reserved
//  224..255  Application extended commands
//  -> see below
#define  CMD_QUERY_EXTENDED_VERSIONNUMBER				 255
#define  CMD_TERMINATE                                   256
#define  CMD_DTR                                         257
#define  CMD_INITIALISE                                  258
#define  CMD_RANDOMISE                                   259
#define  CMD_COMPARE                                     260
#define  CMD_WITHDRAW                                    261
//                                                  reserved
#define  CMD_SEARCHADDRH                                 264 
#define  CMD_SEARCHADDRM                                 265 
#define  CMD_SEARCHADDRL                                 266
#define  CMD_PROGRAMSHORTADDR                            267
#define  CMD_VERIFYSHORTADDR                             268
#define  CMD_QUERYSHORTADDR                              269
#define  CMD_PHYSICALSELECTION                           270
//                                                  reserved
#define  CMD_ENABLEDEVICETYPEX                           272
#define  CMD_DTR1                                        273
#define  CMD_DTR2                                        274
#define  CMD_WRITE_MEMORY_LOCATION                       275
//                                                  reserved 
#define  CMD_SPECIAL_RESERVED287                         287
// -----------------------------------------------------------------  
// -----------------------------------------------------------------  

#define  CMD_UNDEFINED                                   900
// additional Commands for SendBusCommand() ------------------------
// (only supported if a DALI SCI [V1.1 or higher] is connected)
//
#define  CMD_SEND_DALI8bit                               950
 // send 8 bit DALI frame (pass 8bit data in dwBusData)
#define  CMD_SEND_DALI16bit                              951
 // send arbitrary 16bit DALI frame (pass 16bit data in dwBusData)
#define  CMD_SEND_eDALI                                  952
 // send arbitrary 25bit eDALI frame (pass 24bit data in dwBusData)
#define  CMD_SEND_DALI24bit                              953
 // send arbitrary 24bit USA- DALI frame (pass 24bit data in dwBusData)
 // this is only supportd by the SCI3 or DALI USB >=V1.5
#define  CMD_SEND_DALI17bit                              954
 // send arbitrary 17bit Helvar- DALI frame (pass 16bit data in dwBusData LOWWORD,
 //                                          and the 17th bit as bit16 of dwBusData (HIWORD bit0)
 // this is only supportd by the DALI USB >= V1.6
#define  CMD_SEND_PLC                              		 955
 // send arbitrary PLC command on specialized DALI USB Hardware
 // this is only supportd by the DALI USB >= V1.6


#define  CMD_DSI                                         990 
#define  CMD_EXTENDED_DSI                               1000 
 // a DSI will be sent on the DALI bus in the following form:
 // 10ms bus LOW -> DSI command -> 10ms bus low -> bus high 

#define  CMD_DIRECT_LIGHT_CONTROL                        999

// arc power in percent: the % value is passed in dwBusData as Value * 100
#define  CMD_DIRECT_LIGHT_CONTROL_PERCENT                998  


// Higher level Commands --------------------------------------------
//
// Addressing [2010.04.13]
// par 0 ... system Extension (search unaddressed devices)
// par 1 ... complete new installation (current device list will be discarded)
#define CMD_START_ADDRESSING                            2000

// for UI-Interface [2010.04.13]
#define CMD_UI_GROUP_ON                                 2010 
#define CMD_UI_GROUP_OFF                                2011 
#define CMD_UI_GROUP_DIM                                2012 



// -----------------------------------------------------------------  
// -----------------------------------------------------------------  
// application extended commands for device type 1 (emergency ballast)
// -----------------------------------------------------------------  
#define  CMD_REST                                        224
#define  CMD_INHIBIT                                     225
#define  CMD_RELIGHT_RESETINHIBIT                        226
#define  CMD_START_FUNCTIONTEST                          227
#define  CMD_START_DURATIONTEST                          228
#define  CMD_STOP_TEST                                   229
#define  CMD_RESET_FUNCTIONTESTDONE                      230
#define  CMD_RESET_DURATIONTESTDONE                      231
#define  CMD_RESET_LAMPTIME                              232
#define  CMD_STORE_EMERGENCYLEVEL                        233
#define  CMD_STORE_TESTDELAYTIMINGHIGH                   234
#define  CMD_STORE_TESTDELAYTIMINGLOW                    235
#define  CMD_STORE_FUNCTIONTESTINTERVAL                  236
#define  CMD_STORE_DURATIONTESTINTERVAL                  237
#define  CMD_STORE_TESTEXECUTIONTIMEOUT                  238
#define  CMD_STORE_PROLONGTIME                           239
#define  CMD_START_IDENTIFICATION                        240
#define  CMD_QUERY_BATTERYCHARGE                         241
#define  CMD_QUERY_TESTTIMING                            242
#define  CMD_QUERY_DURATIONTESTRESULT                    243
#define  CMD_QUERY_LAMPEMERGENCYTIME                     244
#define  CMD_QUERY_LAMPTOTALOPERATIONTIME                245
#define  CMD_QUERY_EMERGENCYLEVEL                        246
#define  CMD_QUERY_EMERGENCYMINLEVEL                     247
#define  CMD_QUERY_EMERGENCYMAXLEVEL                     248
#define  CMD_QUERY_RATEDDURATION                         249
#define  CMD_QUERY_EMERGENCYMODE                         250
#define  CMD_QUERY_FEATURES                              251
#define  CMD_QUERY_FAILURESTATUS                         252
#define  CMD_QUERY_EMERGENCYSTATUS                       253
// -----------------------------------------------------------------  
// -----------------------------------------------------------------  

  
// -----------------------------------------------------------------  
// -----------------------------------------------------------------  
// application extended commands for device type 3 (halogene converters)
// -----------------------------------------------------------------  
#define  CMD_REFERENCE_SYSTEMPOWER                       224
#define  CMD_QUERY_REFERENCE_RUNNING                     249
// -----------------------------------------------------------------  
// -----------------------------------------------------------------  
  


// -----------------------------------------------------------------  
// -----------------------------------------------------------------  
// extended DSI- commands: -----------------------------------------
// -----------------------------------------------------------------  
#define  CMD_EXTDSI_SAVE_MIN                            0x17
#define  CMD_EXTDSI_SAVE_MAX                            0x15
#define  CMD_EXTDSI_SAVE_DC                             0x1A

#define  CMD_EXTDSI_RELAY_LEVEL                         0x21
#define  CMD_EXTDSI_RELAY_HYSTERESIS                    0x22

#define  CMD_EXTDSI_VERIFY_CUSTOM_CODE                  0x40
#define  CMD_SETLIGHTLEVEL_NP                           0x80
#define  CMD_STAYAT_TURNOFF                             0x82
#define  CMD_SET_EEPROM_DEFAULT_VALUES                  0x84

// -----------------------------------------------------------------  
// -----------------------------------------------------------------  




#endif   // __DALICOMMANDS_H_