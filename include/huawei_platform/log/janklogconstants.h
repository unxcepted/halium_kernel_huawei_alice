/* DTS2015111704698 tuhailong/00278867 20151118 begin */
#define JL_POWERKEY_PRESS                                  "JLOG0"
#define JL_USBCHARGING_START                               "JLOG1"
#define JL_USBCHARGING_END                                 "JLOG2"
#define JL_NEWRINGING_CONNECTION                           "JLOG3"
#define JL_INCOMINGCALL_RINGING                            "JLOG4"
#define JL_PMS_WAKEFULNESS_ASLEEP                          "JLOG5"
#define JL_PMS_WAKEFULNESS_DREAMING                        "JLOG6"
#define JL_PMS_WAKEFULNESS_NAPPING                         "JLOG7"
#define JL_PMS_WAKEUP_FINISHED                             "JLOG8"
#define JL_POWERKEY_RELEASE                                "JLOG9"
#define JL_KERNEL_LCD_OPEN                                 "JLOG10"
#define JL_KERNEL_LCD_SUSPEND                              "JLOG11"
#define JL_KERNEL_LCD_POWER_ON                             "JLOG12"
#define JL_KERNEL_LCD_POWER_OFF                            "JLOG13"
#define JL_KERNEL_PM_SUSPEND_WAKEUP                        "JLOG14"
#define JL_GO_TO_SLEEP_REASON_USER                         "JLOG15"
#define JL_KERNEL_PM_SUSPEND_SLEEP                         "JLOG16"
#define JL_KERNEL_PM_DEEPSLEEP_WAKEUP                      "JLOG17"
#define JL_KERNEL_LCD_BACKLIGHT_ON                         "JLOG18"
#define JL_SYSPROC_INIT_POWERON_START                      "JLOG19"
#define JL_SYSPROC_INIT_POWERON_END                        "JLOG20"
#define JL_SERVICEMANAGER_POWERON_START                    "JLOG21"
#define JL_SERVICEMANAGER_STARTUP                          "JLOG22"
#define JL_START_SYSTEMSERVER                              "JLOG23"
#define JL_LAUNCHER_STARTUP                                "JLOG24"
#define JL_ZYGOTE_START                                    "JLOG25"
#define JL_FIRST_BOOT                                      "JLOG26"
#define JL_BOOT_PROGRESS_START                             "JLOG27"
#define JL_BOOT_PROGRESS_PRELOAD_START                     "JLOG28"
#define JL_BOOT_PROGRESS_PRELOAD_END                       "JLOG29"
#define JL_BOOT_PROGRESS_SYSTEM_RUN                        "JLOG30"
#define JL_BOOT_PROGRESS_PMS_START                         "JLOG31"
#define JL_BOOT_PROGRESS_PMS_READY                         "JLOG32"
#define JL_BOOT_PROGRESS_AMS_READY                         "JLOG33"
#define JL_BOOT_PROGRESS_ENABLE_SCREEN                     "JLOG34"
#define JL_PROXIMITY_SENSOR_FAR                            "JLOG35"
#define JL_PROXIMITY_SENSOR_NEAR                           "JLOG36"
#define JL_JANK_FRAME_SKIP                                 "JLOG37"
#define JL_JANK_FRAME_INFLATE_TIME                         "JLOG38"
#define JL_JANK_FRAME_OBTAIN_TIME                          "JLOG39"
#define JL_JANK_FRAME_SETUP_TIME                           "JLOG40"
#define JL_JANK_FRAME_COMPOSE_TIME                         "JLOG41"
#define JL_SLIDE_TO_CLICK                                  "JLOG42"
#define JL_APP_LAUNCHING_BEGIN                             "JLOG43"
#define JL_APP_LAUNCHING_END                               "JLOG44"
#define JL_COVER_SENSOR_OPEN                               "JLOG45"
#define JL_BOOT_PROGRESS_INITZYGOTE_START                  "JLOG46"
#define JL_RIL_RESPONSE_NEW_SMS                            "JLOG47"
#define JL_DISPATCH_NORMAL_SMS                             "JLOG48"
#define JL_SEND_BROADCAST_SMS                              "JLOG49"
#define JL_DISPATCH_SMS_FAILED                             "JLOG50"
#define JL_WAP_DISPATCH_PDU                                "JLOG51"
#define JL_TP_GESTURE_KEY                                  "JLOG52"
#define JL_WAKEUP_DBCLICK                                  "JLOG53"
#define JL_INPUTDISPATCH_FINGERPRINT                       "JLOG54"
#define JL_FINGER_INDENTIFY_OK                             "JLOG55"
#define JL_FINGER_INDENTIFY_FAILED                         "JLOG56"
#define JL_ROTATION_CHANGED                                "JLOG57"
#define JL_START_ROTATION_ANIM                             "JLOG58"
#define JL_END_ROTATION_ANIM                               "JLOG59"
#define JL_MONKEY_CTS_START                                "JLOG60"
#define JL_MONKEY_CTS_END                                  "JLOG61"
#define JL_SQLITE_INSERT_ET                                "JLOG62"
#define JL_SQLITE_UPDATE_ET                                "JLOG63"
#define JL_SQLITE_QUERY_ET                                 "JLOG64"
#define JL_SQLITE_DELETE_ET                                "JLOG65"
#define JL_SQLITE_EXECSQL_ET                               "JLOG66"
#define JL_JANK_FRAME_HANDLER_TIME                         "JLOG67"
#define JL_JANK_FRAME_TIMEOUT                              "JLOG68"
#define JL_SLIDE_TO_CLICK_TIMEOUT                          "JLOG69"
#define JL_BINDER_TRANSACT_TIMEOUT                         "JLOG70"
#define JL_KEYGUARD_DELEGATE_SCTURNON                      "JLOG71"
#define JL_KEYGUARD_MEDIA_SCTURNON                         "JLOG72"
#define JL_KEYGUARD_MEDIA_NTSCON                           "JLOG73"
#define JL_KEYGUARD_MEDIA_HDLSCON                          "JLOG74"
#define JL_KEYGUARD_MANAG_SCTURNON                         "JLOG75"
#define JL_KEYGUARD_DELEGATE_SHOWN                         "JLOG76"
#define JL_KERNEL_LCD_BACKLIGHT_OFF                        "JLOG77"
#define JL_GO_TO_SLEEP_REASON_PROX                         "JLOG78"
#define JL_GO_TO_SLEEP_REASON_OTHERS                       "JLOG79"
#define JL_STRICT_MODE                                     "JLOG80"
#define JL_JANK_FRAME_ENABLE                               "JLOG81"
#define JL_JANK_FRAME_DISABLE                              "JLOG82"
#define JL_COVER_OPEN                                      "JLOG83"
#define JL_COVER_REMOVE_SCREEN_BEGIN                       "JLOG84"
#define JL_COVER_REMOVE_SCREEN_END                         "JLOG85"
#define JL_COVER_OPEN_BROADCAST                            "JLOG86"
#define JL_CAMERA_LAUNCH_BEGIN                             "JLOG87"
#define JL_CAMERA_LAUNCH_END                               "JLOG88"
#define JL_CAMERA_AF_BEGIN                                 "JLOG89"
#define JL_CAMERA_AF_END                                   "JLOG90"
#define JL_CAMERA_SHUTTERLAG_ZSL_BEGIN                     "JLOG91"
#define JL_CAMERA_SHUTTERLAG_ZSL_END                       "JLOG92"
#define JL_CAMERA_SHUTTERLAG_NOZSL_BEGIN                   "JLOG93"
#define JL_CAMERA_SHUTTERLAG_NOZSL_END                     "JLOG94"
#define JL_CAMERA_SHOT_TO_SEE_BEGIN                        "JLOG95"
#define JL_CAMERA_SHOT_TO_SEE_END                          "JLOG96"
#define JL_CAMERA_SEE_TO_REVIEW_BEGIN                      "JLOG97"
#define JL_CAMERA_SEE_TO_REVIEW_END                        "JLOG98"
#define JL_CAMERA_QUICK_SNAPSHOT_BEGIN                     "JLOG99"
#define JL_CAMERA_QUICK_SNAPSHOT_END                       "JLOG100"
#define JL_CAMERA_START_RECORDING_BEGIN                    "JLOG101"
#define JL_CAMERA_START_RECORDING_END                      "JLOG102"
#define JL_ART_GC_TOTALTIME                                "JLOG103"
#define JL_ART_GC_PAUSETIME                                "JLOG104"
#define JL_KERNEL_HUNG_TASK                                "JLOG105"
#define JL_PMS_OPEN_ABC                                    "JLOG106"
#define JL_ABC_OPEN_ALS                                    "JLOG107"
#define JL_ABC_GET_FIRST_ALS_VALUE                         "JLOG108"
#define JL_ABC_GET_SECOND_ALS_VALUE                        "JLOG109"
#define JL_ABC_SET_BRIGHTNESS_BEGIN                        "JLOG110"
#define JL_ABC_SET_BRIGHTNESS_END                          "JLOG111"
#define JL_PEOPLE_ACTIVITY_ONCREATE                        "JLOG112"
#define JL_CONTACT_DETAIL_LIST_BIND_VIEW                   "JLOG113"
#define JL_CALLLOG_LIST_BIND_VIEW                          "JLOG114"
#define JL_CONTACT_DETAIL_BIND_VIEW                        "JLOG115"
#define JL_CONTACT_BIND_EDITOR_FOR_NEW                     "JLOG116"
#define JL_DIALPAD_AFTER_TEXT_CHANGE                       "JLOG117"
#define JL_CONTACT_MULTISELECT_ACTIVITY_ONCREATE           "JLOG118"
#define JL_CONTACT_MULTISELECT_BIND_VIEW                   "JLOG119"
#define JL_DIALPAD_ONTOUCH_NOT_FIRST_DOWN                  "JLOG120"
#define JL_DIALPAD_ADAPTER_GET_VIEW                        "JLOG121"
#define JL_DEF_CONTACT_ITEM_CLICK                          "JLOG122"
#define JL_NEW_CONTACT_CLICK                               "JLOG123"
#define JL_NEW_CONTACT_SAVE_CLICK                          "JLOG124"
#define JL_EDIT_CONTACT_CLICK                              "JLOG125"
#define JL_NEW_CONTACT_SELECT_ACCOUNT                      "JLOG126"
#define JL_PEOPLE_ACTIVITY_ONNEWINTENT                     "JLOG127"
#define JL_PHONE_INCALLUI_LAUNCH_START                     "JLOG128"
#define JL_PHONE_INCALLUI_LAUNCH_END                       "JLOG129"
#define JL_PHONE_INCALLUI_CLOSE_START                      "JLOG130"
#define JL_PHONE_INCALLUI_CLOSE_END                        "JLOG131"
#define JL_EDIT_CONTACT_END                                "JLOG132"
#define JL_SYSTEMUI_DROPDOWN_RESPONSE                      "JLOG133"
#define JL_SYSTEMUI_TAB_SWITCH                             "JLOG134"
#define JL_SYSTEMUI_START_RECENT                           "JLOG135"
#define JL_SYSTEMUI_REMOVEALL_RECENT                       "JLOG136"
#define JL_MMS_CONVERSATIONS_DELETE                        "JLOG137"
#define JL_MMS_MESSAGES_DELETE                             "JLOG138"
#define JL_MMS_MESSAGE_SEARCH                              "JLOG139"
#define JL_MMS_RECENT_CONTACTS_QUERY                       "JLOG140"
#define JL_MMS_MATCHED_CONTACTS_SEARCH                     "JLOG141"
#define JL_APP_RUN_FRONT                                   "JLOG142"
#define JL_RESOURCE_MANAGER                                "JLOG143"
#define JL_SETTINGS_BLUETOOTH_LAUNCH                       "JLOG144"
#define JL_SETTINGS_WIFI_LAUNCH                            "JLOG145"
#define JL_CAMERA_ONCREATE                                 "JLOG146"
#define JL_CAMERA_ONRESUME                                 "JLOG147"
#define JL_CAMERA_OPENCAMERA_BEGIN                         "JLOG148"
#define JL_CAMERA_OPENCAMERA_END                           "JLOG149"
#define JL_CAMERA_STARTPREVIEW_BEGIN                       "JLOG150"
#define JL_CAMERA_STARTPREVIEW_END                         "JLOG151"
#define JL_CAMERA_COLD_START_END                           "JLOG152"
#define JL_CAMERA_HOT_START_END                            "JLOG153"
#define JL_CAMERA_HOT_START_BEGIN                          "JLOG154"
#define JL_CAMERA3_DEVICEPOWERUP_BEGIN                     "JLOG155"
#define JL_CAMERA3_DEVICEPOWERUP_END                       "JLOG156"
#define JL_CAMERA3_ISPPOWERUP_BEGIN                        "JLOG157"
#define JL_CAMERA3_ISPPOWERUP_END                          "JLOG158"
#define JL_CAMERA3_SENSORPOWERUP_BEGIN                     "JLOG159"
#define JL_CAMERA3_SENSORPOWERUP_END                       "JLOG160"
#define JL_CAMERA3_D2POWERUP_BEGIN                         "JLOG161"
#define JL_CAMERA3_D2POWERUP_END                           "JLOG162"
#define JL_CAMERA3_LASERPOWERUP_BEGIN                      "JLOG163"
#define JL_CAMERA3_LASERPOWERUP_END                        "JLOG164"
#define JL_CAMERA3_ACQUIRE_LASER_BEGIN                     "JLOG165"
#define JL_CAMERA3_ACQUIRE_LASER_END                       "JLOG166"
#define JL_CAMERA3_ACQUIRE_CAMERA_BEGIN                    "JLOG167"
#define JL_CAMERA3_ACQUIRE_CAMERA_END                      "JLOG168"
#define JL_CAMERA3_PIPELINE_START_BEGIN                    "JLOG169"
#define JL_CAMERA3_PIPELINE_START_END                      "JLOG170"
#define JL_CAMERA3_STARTSTREAMING_BEGIN                    "JLOG171"
#define JL_CAMERA3_STARTSTREAMING_END                      "JLOG172"

#define JLID_POWERKEY_PRESS                                   0
#define JLID_USBCHARGING_START                                1
#define JLID_USBCHARGING_END                                  2
#define JLID_NEWRINGING_CONNECTION                            3
#define JLID_INCOMINGCALL_RINGING                             4
#define JLID_PMS_WAKEFULNESS_ASLEEP                           5
#define JLID_PMS_WAKEFULNESS_DREAMING                         6
#define JLID_PMS_WAKEFULNESS_NAPPING                          7
#define JLID_PMS_WAKEUP_FINISHED                              8
#define JLID_POWERKEY_RELEASE                                 9
#define JLID_KERNEL_LCD_OPEN                                  10
#define JLID_KERNEL_LCD_SUSPEND                               11
#define JLID_KERNEL_LCD_POWER_ON                              12
#define JLID_KERNEL_LCD_POWER_OFF                             13
#define JLID_KERNEL_PM_SUSPEND_WAKEUP                         14
#define JLID_GO_TO_SLEEP_REASON_USER                          15
#define JLID_KERNEL_PM_SUSPEND_SLEEP                          16
#define JLID_KERNEL_PM_DEEPSLEEP_WAKEUP                       17
#define JLID_KERNEL_LCD_BACKLIGHT_ON                          18
#define JLID_SYSPROC_INIT_POWERON_START                       19
#define JLID_SYSPROC_INIT_POWERON_END                         20
#define JLID_SERVICEMANAGER_POWERON_START                     21
#define JLID_SERVICEMANAGER_STARTUP                           22
#define JLID_START_SYSTEMSERVER                               23
#define JLID_LAUNCHER_STARTUP                                 24
#define JLID_ZYGOTE_START                                     25
#define JLID_FIRST_BOOT                                       26
#define JLID_BOOT_PROGRESS_START                              27
#define JLID_BOOT_PROGRESS_PRELOAD_START                      28
#define JLID_BOOT_PROGRESS_PRELOAD_END                        29
#define JLID_BOOT_PROGRESS_SYSTEM_RUN                         30
#define JLID_BOOT_PROGRESS_PMS_START                          31
#define JLID_BOOT_PROGRESS_PMS_READY                          32
#define JLID_BOOT_PROGRESS_AMS_READY                          33
#define JLID_BOOT_PROGRESS_ENABLE_SCREEN                      34
#define JLID_PROXIMITY_SENSOR_FAR                             35
#define JLID_PROXIMITY_SENSOR_NEAR                            36
#define JLID_JANK_FRAME_SKIP                                  37
#define JLID_JANK_FRAME_INFLATE_TIME                          38
#define JLID_JANK_FRAME_OBTAIN_TIME                           39
#define JLID_JANK_FRAME_SETUP_TIME                            40
#define JLID_JANK_FRAME_COMPOSE_TIME                          41
#define JLID_SLIDE_TO_CLICK                                   42
#define JLID_APP_LAUNCHING_BEGIN                              43
#define JLID_APP_LAUNCHING_END                                44
#define JLID_COVER_SENSOR_OPEN                                45
#define JLID_BOOT_PROGRESS_INITZYGOTE_START                   46
#define JLID_RIL_RESPONSE_NEW_SMS                             47
#define JLID_DISPATCH_NORMAL_SMS                              48
#define JLID_SEND_BROADCAST_SMS                               49
#define JLID_DISPATCH_SMS_FAILED                              50
#define JLID_WAP_DISPATCH_PDU                                 51
#define JLID_TP_GESTURE_KEY                                   52
#define JLID_WAKEUP_DBCLICK                                   53
#define JLID_INPUTDISPATCH_FINGERPRINT                        54
#define JLID_FINGER_INDENTIFY_OK                              55
#define JLID_FINGER_INDENTIFY_FAILED                          56
#define JLID_ROTATION_CHANGED                                 57
#define JLID_START_ROTATION_ANIM                              58
#define JLID_END_ROTATION_ANIM                                59
#define JLID_MONKEY_CTS_START                                 60
#define JLID_MONKEY_CTS_END                                   61
#define JLID_SQLITE_INSERT_ET                                 62
#define JLID_SQLITE_UPDATE_ET                                 63
#define JLID_SQLITE_QUERY_ET                                  64
#define JLID_SQLITE_DELETE_ET                                 65
#define JLID_SQLITE_EXECSQL_ET                                66
#define JLID_JANK_FRAME_HANDLER_TIME                          67
#define JLID_JANK_FRAME_TIMEOUT                               68
#define JLID_SLIDE_TO_CLICK_TIMEOUT                           69
#define JLID_BINDER_TRANSACT_TIMEOUT                          70
#define JLID_KEYGUARD_DELEGATE_SCTURNON                       71
#define JLID_KEYGUARD_MEDIA_SCTURNON                          72
#define JLID_KEYGUARD_MEDIA_NTSCON                            73
#define JLID_KEYGUARD_MEDIA_HDLSCON                           74
#define JLID_KEYGUARD_MANAG_SCTURNON                          75
#define JLID_KEYGUARD_DELEGATE_SHOWN                          76
#define JLID_KERNEL_LCD_BACKLIGHT_OFF                         77
#define JLID_GO_TO_SLEEP_REASON_PROX                          78
#define JLID_GO_TO_SLEEP_REASON_OTHERS                        79
#define JLID_STRICT_MODE                                      80
#define JLID_JANK_FRAME_ENABLE                                81
#define JLID_JANK_FRAME_DISABLE                               82
#define JLID_COVER_OPEN                                       83
#define JLID_COVER_REMOVE_SCREEN_BEGIN                        84
#define JLID_COVER_REMOVE_SCREEN_END                          85
#define JLID_COVER_OPEN_BROADCAST                             86
#define JLID_CAMERA_LAUNCH_BEGIN                              87
#define JLID_CAMERA_LAUNCH_END                                88
#define JLID_CAMERA_AF_BEGIN                                  89
#define JLID_CAMERA_AF_END                                    90
#define JLID_CAMERA_SHUTTERLAG_ZSL_BEGIN                      91
#define JLID_CAMERA_SHUTTERLAG_ZSL_END                        92
#define JLID_CAMERA_SHUTTERLAG_NOZSL_BEGIN                    93
#define JLID_CAMERA_SHUTTERLAG_NOZSL_END                      94
#define JLID_CAMERA_SHOT_TO_SEE_BEGIN                         95
#define JLID_CAMERA_SHOT_TO_SEE_END                           96
#define JLID_CAMERA_SEE_TO_REVIEW_BEGIN                       97
#define JLID_CAMERA_SEE_TO_REVIEW_END                         98
#define JLID_CAMERA_QUICK_SNAPSHOT_BEGIN                      99
#define JLID_CAMERA_QUICK_SNAPSHOT_END                        100
#define JLID_CAMERA_START_RECORDING_BEGIN                     101
#define JLID_CAMERA_START_RECORDING_END                       102
#define JLID_ART_GC_TOTALTIME                                 103
#define JLID_ART_GC_PAUSETIME                                 104
#define JLID_KERNEL_HUNG_TASK                                 105
#define JLID_PMS_OPEN_ABC                                     106
#define JLID_ABC_OPEN_ALS                                     107
#define JLID_ABC_GET_FIRST_ALS_VALUE                          108
#define JLID_ABC_GET_SECOND_ALS_VALUE                         109
#define JLID_ABC_SET_BRIGHTNESS_BEGIN                         110
#define JLID_ABC_SET_BRIGHTNESS_END                           111
#define JLID_PEOPLE_ACTIVITY_ONCREATE                         112
#define JLID_CONTACT_DETAIL_LIST_BIND_VIEW                    113
#define JLID_CALLLOG_LIST_BIND_VIEW                           114
#define JLID_CONTACT_DETAIL_BIND_VIEW                         115
#define JLID_CONTACT_BIND_EDITOR_FOR_NEW                      116
#define JLID_DIALPAD_AFTER_TEXT_CHANGE                        117
#define JLID_CONTACT_MULTISELECT_ACTIVITY_ONCREATE            118
#define JLID_CONTACT_MULTISELECT_BIND_VIEW                    119
#define JLID_DIALPAD_ONTOUCH_NOT_FIRST_DOWN                   120
#define JLID_DIALPAD_ADAPTER_GET_VIEW                         121
#define JLID_DEF_CONTACT_ITEM_CLICK                           122
#define JLID_NEW_CONTACT_CLICK                                123
#define JLID_NEW_CONTACT_SAVE_CLICK                           124
#define JLID_EDIT_CONTACT_CLICK                               125
#define JLID_NEW_CONTACT_SELECT_ACCOUNT                       126
#define JLID_PEOPLE_ACTIVITY_ONNEWINTENT                      127
#define JLID_PHONE_INCALLUI_LAUNCH_START                      128
#define JLID_PHONE_INCALLUI_LAUNCH_END                        129
#define JLID_PHONE_INCALLUI_CLOSE_START                       130
#define JLID_PHONE_INCALLUI_CLOSE_END                         131
#define JLID_EDIT_CONTACT_END                                 132
#define JLID_SYSTEMUI_DROPDOWN_RESPONSE                       133
#define JLID_SYSTEMUI_TAB_SWITCH                              134
#define JLID_SYSTEMUI_START_RECENT                            135
#define JLID_SYSTEMUI_REMOVEALL_RECENT                        136
#define JLID_MMS_CONVERSATIONS_DELETE                         137
#define JLID_MMS_MESSAGES_DELETE                              138
#define JLID_MMS_MESSAGE_SEARCH                               139
#define JLID_MMS_RECENT_CONTACTS_QUERY                        140
#define JLID_MMS_MATCHED_CONTACTS_SEARCH                      141
#define JLID_APP_RUN_FRONT                                    142
#define JLID_RESOURCE_MANAGER                                 143
#define JLID_SETTINGS_BLUETOOTH_LAUNCH                        144
#define JLID_SETTINGS_WIFI_LAUNCH                             145
#define JLID_CAMERA_ONCREATE                                  146
#define JLID_CAMERA_ONRESUME                                  147
#define JLID_CAMERA_OPENCAMERA_BEGIN                          148
#define JLID_CAMERA_OPENCAMERA_END                            149
#define JLID_CAMERA_STARTPREVIEW_BEGIN                        150
#define JLID_CAMERA_STARTPREVIEW_END                          151
#define JLID_CAMERA_COLD_START_END                            152
#define JLID_CAMERA_HOT_START_END                             153
#define JLID_CAMERA_HOT_START_BEGIN                           154
#define JLID_CAMERA3_DEVICEPOWERUP_BEGIN                      155
#define JLID_CAMERA3_DEVICEPOWERUP_END                        156
#define JLID_CAMERA3_ISPPOWERUP_BEGIN                         157
#define JLID_CAMERA3_ISPPOWERUP_END                           158
#define JLID_CAMERA3_SENSORPOWERUP_BEGIN                      159
#define JLID_CAMERA3_SENSORPOWERUP_END                        160
#define JLID_CAMERA3_D2POWERUP_BEGIN                          161
#define JLID_CAMERA3_D2POWERUP_END                            162
#define JLID_CAMERA3_LASERPOWERUP_BEGIN                       163
#define JLID_CAMERA3_LASERPOWERUP_END                         164
#define JLID_CAMERA3_ACQUIRE_LASER_BEGIN                      165
#define JLID_CAMERA3_ACQUIRE_LASER_END                        166
#define JLID_CAMERA3_ACQUIRE_CAMERA_BEGIN                     167
#define JLID_CAMERA3_ACQUIRE_CAMERA_END                       168
#define JLID_CAMERA3_PIPELINE_START_BEGIN                     169
#define JLID_CAMERA3_PIPELINE_START_END                       170
#define JLID_CAMERA3_STARTSTREAMING_BEGIN                     171
#define JLID_CAMERA3_STARTSTREAMING_END                       172
/* DTS2015111704698 tuhailong/00278867 20151118 end */