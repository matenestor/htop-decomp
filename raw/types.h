typedef unsigned char   undefined;

typedef unsigned char    bool;
typedef unsigned char    byte;
typedef unsigned char    dwfenc;
typedef unsigned int    dword;
typedef long long    int16;
typedef long long    longlong;
typedef unsigned long    qword;
typedef int    sdword;
typedef long    sqword;
typedef unsigned char    uchar;
typedef unsigned int    uint;
typedef unsigned long long    uint16;
typedef unsigned long    ulong;
typedef unsigned long long    ulonglong;
typedef unsigned char    undefined1;
typedef unsigned int    undefined4;
typedef unsigned long    undefined6;
typedef unsigned long    undefined8;
typedef unsigned short    ushort;
typedef int    wchar_t;
typedef unsigned short    word;
typedef struct NoteGnuPropertyElement_4 NoteGnuPropertyElement_4, *PNoteGnuPropertyElement_4;

struct NoteGnuPropertyElement_4 {
    dword prType;
    dword prDatasz;
    byte data[4];
};

typedef struct eh_frame_hdr eh_frame_hdr, *Peh_frame_hdr;

struct eh_frame_hdr {
    byte eh_frame_hdr_version; /* Exception Handler Frame Header Version */
    dwfenc eh_frame_pointer_encoding; /* Exception Handler Frame Pointer Encoding */
    dwfenc eh_frame_desc_entry_count_encoding; /* Encoding of # of Exception Handler FDEs */
    dwfenc eh_frame_table_encoding; /* Exception Handler Table Encoding */
};

typedef struct fde_table_entry fde_table_entry, *Pfde_table_entry;

struct fde_table_entry {
    dword initial_loc; /* Initial Location */
    dword data_loc; /* Data location */
};

typedef struct _IO_marker _IO_marker, *P_IO_marker;

typedef struct _IO_FILE_2 _IO_FILE_2, *P_IO_FILE_2;

typedef long __off_t;

typedef void _IO_lock_t;

typedef long __off64_t_2;

typedef ulong size_t;

struct _IO_FILE_2 {
    int _flags;
    byte field_0x4;
    byte field_0x5;
    byte field_0x6;
    byte field_0x7;
    char *_IO_read_ptr;
    char *_IO_read_end;
    char *_IO_read_base;
    char *_IO_write_base;
    char *_IO_write_ptr;
    char *_IO_write_end;
    char *_IO_buf_base;
    char *_IO_buf_end;
    char *_IO_save_base;
    char *_IO_backup_base;
    char *_IO_save_end;
    struct _IO_marker *_markers;
    struct _IO_FILE_2 *_chain;
    int _fileno;
    int _flags2;
    __off_t _old_offset;
    ushort _cur_column;
    char _vtable_offset;
    char _shortbuf[1];
    byte field_0x84;
    byte field_0x85;
    byte field_0x86;
    byte field_0x87;
    _IO_lock_t *_lock;
    __off64_t_2 _offset;
    void *__pad1;
    void *__pad2;
    void *__pad3;
    void *__pad4;
    size_t __pad5;
    int _mode;
    char _unused2[20];
};

struct _IO_marker {
    struct _IO_marker *_next;
    struct _IO_FILE_2 *_sbuf;
    int _pos;
    byte field_0x14;
    byte field_0x15;
    byte field_0x16;
    byte field_0x17;
};

typedef struct stat_2 stat_2, *Pstat_2;

typedef ulong __dev_t;

typedef ulong __ino_t;

typedef ulong __nlink_t;

typedef uint __mode_t;

typedef uint __uid_t;

typedef uint __gid_t;

typedef long __blksize_t;

typedef long __blkcnt_t;

typedef struct timespec_2 timespec_2, *Ptimespec_2;

typedef long __time_t;

struct timespec_2 {
    __time_t tv_sec;
    long tv_nsec;
};

struct stat_2 {
    __dev_t st_dev;
    __ino_t st_ino;
    __nlink_t st_nlink;
    __mode_t st_mode;
    __uid_t st_uid;
    __gid_t st_gid;
    int __pad0;
    __dev_t st_rdev;
    __off_t st_size;
    __blksize_t st_blksize;
    __blkcnt_t st_blocks;
    struct timespec_2 st_atim;
    struct timespec_2 st_mtim;
    struct timespec_2 st_ctim;
    long __unused[3];
};

typedef struct statfs_2 statfs_2, *Pstatfs_2;

typedef ulong __fsblkcnt_t;

typedef ulong __fsfilcnt_t;

typedef struct __fsid_t_2 __fsid_t_2, *P__fsid_t_2;

struct __fsid_t_2 {
    int __val[2];
};

struct statfs_2 {
    long f_type;
    long f_bsize;
    __fsblkcnt_t f_blocks;
    __fsblkcnt_t f_bfree;
    __fsblkcnt_t f_bavail;
    __fsfilcnt_t f_files;
    __fsfilcnt_t f_ffree;
    struct __fsid_t_2 f_fsid;
    long f_namelen;
    long f_frsize;
    long f_flags;
    long f_spare[4];
};

typedef struct statvfs_2 statvfs_2, *Pstatvfs_2;

struct statvfs_2 {
    ulong f_bsize;
    ulong f_frsize;
    __fsblkcnt_t f_blocks;
    __fsblkcnt_t f_bfree;
    __fsblkcnt_t f_bavail;
    __fsfilcnt_t f_files;
    __fsfilcnt_t f_ffree;
    __fsfilcnt_t f_favail;
    ulong f_fsid;
    ulong f_flag;
    ulong f_namemax;
    int __f_spare[6];
};

typedef struct _IO_FILE_2 FILE_2;

typedef struct evp_pkey_ctx_st evp_pkey_ctx_st, *Pevp_pkey_ctx_st;

struct evp_pkey_ctx_st {
};

typedef struct evp_pkey_ctx_st EVP_PKEY_CTX;

typedef struct __dirstream __dirstream, *P__dirstream;

typedef struct __dirstream DIR_2;

struct __dirstream {
};

typedef union sigval_2 sigval_2, *Psigval_2;

typedef union sigval_2 sigval_t;

union sigval_2 {
    int sival_int;
    void *sival_ptr;
};

typedef union _union_1441 _union_1441, *P_union_1441;

typedef struct _struct_1442 _struct_1442, *P_struct_1442;

typedef struct _struct_1443 _struct_1443, *P_struct_1443;

typedef struct _struct_1444 _struct_1444, *P_struct_1444;

typedef struct _struct_1445 _struct_1445, *P_struct_1445;

typedef struct _struct_1446 _struct_1446, *P_struct_1446;

typedef struct _struct_1447 _struct_1447, *P_struct_1447;

typedef int __pid_t;

typedef long __clock_t;

struct _struct_1445 {
    __pid_t si_pid;
    __uid_t si_uid;
    int si_status;
    byte field_0xc;
    byte field_0xd;
    byte field_0xe;
    byte field_0xf;
    __clock_t si_utime;
    __clock_t si_stime;
};

struct _struct_1444 {
    __pid_t si_pid;
    __uid_t si_uid;
    sigval_t si_sigval;
};

struct _struct_1443 {
    int si_tid;
    int si_overrun;
    sigval_t si_sigval;
};

struct _struct_1446 {
    void *si_addr;
};

struct _struct_1442 {
    __pid_t si_pid;
    __uid_t si_uid;
};

struct _struct_1447 {
    long si_band;
    int si_fd;
    byte field_0xc;
    byte field_0xd;
    byte field_0xe;
    byte field_0xf;
};

union _union_1441 {
    int _pad[28];
    struct _struct_1442 _kill;
    struct _struct_1443 _timer;
    struct _struct_1444 _rt;
    struct _struct_1445 _sigchld;
    struct _struct_1446 _sigfault;
    struct _struct_1447 _sigpoll;
};

typedef struct siginfo siginfo, *Psiginfo;

typedef struct siginfo siginfo_t_2;

struct siginfo {
    int si_signo;
    int si_errno;
    int si_code;
    byte field_0xc;
    byte field_0xd;
    byte field_0xe;
    byte field_0xf;
    union _union_1441 _sifields;
};

typedef uint wint_t;

typedef long __syscall_slong_t;

typedef ulong __cpu_mask;

typedef int __clockid_t;

typedef uint mmask_t;

typedef uchar __u8;

typedef long __ssize_t;

typedef int IOPriority;

typedef word __u16;

typedef long __fd_mask;

typedef uchar __uint8_t;

typedef long __suseconds_t;

typedef sdword __int32_t;

typedef ulong memory_t;

typedef bool _Bool;

typedef int16 __int128;

typedef uint __id_t;

typedef word __uint16_t;

typedef uint ht_key_t;

typedef uint chtype;

typedef long __fsword_t;

typedef qword __uint64_t;

typedef int openat_arg_t;

typedef sqword __off64_t;

typedef int nl_item;

typedef dword __u32;

typedef sqword __int64_t;

typedef dword __uint32_t;

typedef qword __u64;

typedef struct Machine_ Machine_, *PMachine_;

typedef struct Settings__2 Settings__2, *PSettings__2;

typedef struct timeval timeval, *Ptimeval;

typedef __uint64_t uint64_t;

typedef __int64_t int64_t;

typedef struct UsersTable_ UsersTable_, *PUsersTable_;

typedef struct UsersTable_ UsersTable;

typedef __uid_t uid_t;

typedef struct Table_ Table_, *PTable_;

typedef struct Table_ Table;

typedef enum HeaderLayout_ {
    HF_INVALID=-1,
    HF_TWO_50_50=0,
    HF_TWO_33_67=1,
    HF_TWO_67_33=2,
    HF_THREE_33_34_33=3,
    HF_THREE_25_25_50=4,
    HF_THREE_25_50_25=5,
    HF_THREE_50_25_25=6,
    HF_THREE_40_30_30=7,
    HF_THREE_30_40_30=8,
    HF_THREE_30_30_40=9,
    HF_THREE_40_20_40=10,
    HF_FOUR_25_25_25_25=11,
    LAST_HEADER_LAYOUT=12
} HeaderLayout_;

typedef enum HeaderLayout_ HeaderLayout;

typedef struct MeterColumnSetting MeterColumnSetting, *PMeterColumnSetting;

typedef struct Hashtable_ Hashtable_, *PHashtable_;

typedef struct Hashtable_ Hashtable_2;

typedef struct ScreenSettings__2 ScreenSettings__2, *PScreenSettings__2;

typedef struct ScreenSettings__2 ScreenSettings_2;

typedef struct Object_ Object_, *PObject_;

typedef struct Object_ Object;

typedef struct Vector_ Vector_, *PVector_;

typedef struct Vector_ Vector;

typedef struct Panel_ Panel_, *PPanel_;

typedef struct HashtableItem_ HashtableItem_, *PHashtableItem_;

typedef struct HashtableItem_ HashtableItem;

typedef __int32_t int32_t;

typedef int32_t RowField;

typedef __uint32_t uint32_t;

typedef struct ObjectClass_ ObjectClass_, *PObjectClass_;

typedef struct ObjectClass_ ObjectClass;

typedef struct FunctionBar_ FunctionBar_, *PFunctionBar_;

typedef struct FunctionBar_ FunctionBar;

typedef struct RichString_ RichString_, *PRichString_;

typedef struct RichString_ RichString;

typedef enum ColorElements_ {
    RESET_COLOR=0,
    DEFAULT_COLOR=1,
    FUNCTION_BAR=2,
    FUNCTION_KEY=3,
    FAILED_SEARCH=4,
    FAILED_READ=5,
    PAUSED=6,
    PANEL_HEADER_FOCUS=7,
    PANEL_HEADER_UNFOCUS=8,
    PANEL_SELECTION_FOCUS=9,
    PANEL_SELECTION_FOLLOW=10,
    PANEL_SELECTION_UNFOCUS=11,
    LARGE_NUMBER=12,
    METER_SHADOW=13,
    METER_TEXT=14,
    METER_VALUE=15,
    METER_VALUE_ERROR=16,
    METER_VALUE_IOREAD=17,
    METER_VALUE_IOWRITE=18,
    METER_VALUE_NOTICE=19,
    METER_VALUE_OK=20,
    METER_VALUE_WARN=21,
    LED_COLOR=22,
    UPTIME=23,
    BATTERY=24,
    TASKS_RUNNING=25,
    SWAP=26,
    SWAP_CACHE=27,
    SWAP_FRONTSWAP=28,
    PROCESS=29,
    PROCESS_SHADOW=30,
    PROCESS_TAG=31,
    PROCESS_MEGABYTES=32,
    PROCESS_GIGABYTES=33,
    PROCESS_TREE=34,
    PROCESS_RUN_STATE=35,
    PROCESS_D_STATE=36,
    PROCESS_BASENAME=37,
    PROCESS_HIGH_PRIORITY=38,
    PROCESS_LOW_PRIORITY=39,
    PROCESS_NEW=40,
    PROCESS_TOMB=41,
    PROCESS_THREAD=42,
    PROCESS_THREAD_BASENAME=43,
    PROCESS_COMM=44,
    PROCESS_THREAD_COMM=45,
    PROCESS_PRIV=46,
    BAR_BORDER=47,
    BAR_SHADOW=48,
    GRAPH_1=49,
    GRAPH_2=50,
    MEMORY_USED=51,
    MEMORY_BUFFERS=52,
    MEMORY_BUFFERS_TEXT=53,
    MEMORY_CACHE=54,
    MEMORY_SHARED=55,
    MEMORY_COMPRESSED=56,
    HUGEPAGE_1=57,
    HUGEPAGE_2=58,
    HUGEPAGE_3=59,
    HUGEPAGE_4=60,
    LOAD=61,
    LOAD_AVERAGE_FIFTEEN=62,
    LOAD_AVERAGE_FIVE=63,
    LOAD_AVERAGE_ONE=64,
    CHECK_BOX=65,
    CHECK_MARK=66,
    CHECK_TEXT=67,
    CLOCK=68,
    DATE=69,
    DATETIME=70,
    HELP_BOLD=71,
    HELP_SHADOW=72,
    HOSTNAME=73,
    CPU_NICE=74,
    CPU_NICE_TEXT=75,
    CPU_NORMAL=76,
    CPU_SYSTEM=77,
    CPU_IOWAIT=78,
    CPU_IRQ=79,
    CPU_SOFTIRQ=80,
    CPU_STEAL=81,
    CPU_GUEST=82,
    PANEL_EDIT=83,
    SCREENS_OTH_BORDER=84,
    SCREENS_OTH_TEXT=85,
    SCREENS_CUR_BORDER=86,
    SCREENS_CUR_TEXT=87,
    PRESSURE_STALL_TEN=88,
    PRESSURE_STALL_SIXTY=89,
    PRESSURE_STALL_THREEHUNDRED=90,
    FILE_DESCRIPTOR_USED=91,
    FILE_DESCRIPTOR_MAX=92,
    ZFS_MFU=93,
    ZFS_MRU=94,
    ZFS_ANON=95,
    ZFS_HEADER=96,
    ZFS_OTHER=97,
    ZFS_COMPRESSED=98,
    ZFS_RATIO=99,
    ZRAM_COMPRESSED=100,
    ZRAM_UNCOMPRESSED=101,
    DYNAMIC_GRAY=102,
    DYNAMIC_DARKGRAY=103,
    DYNAMIC_RED=104,
    DYNAMIC_GREEN=105,
    DYNAMIC_BLUE=106,
    DYNAMIC_CYAN=107,
    DYNAMIC_MAGENTA=108,
    DYNAMIC_YELLOW=109,
    DYNAMIC_WHITE=110,
    LAST_COLORELEMENT=111
} ColorElements_;

typedef enum ColorElements_ ColorElements;

typedef void (*Object_Display)(Object *, RichString *);

typedef void (*Object_Delete)(Object *);

typedef wchar_t (*Object_Compare)(void *, void *);

typedef union anon_union_8_2_1989b71c_for_keys anon_union_8_2_1989b71c_for_keys, *Panon_union_8_2_1989b71c_for_keys;

typedef struct cchar_t cchar_t, *Pcchar_t;

typedef chtype attr_t;

struct Settings__2 {
    char *filename;
    wchar_t config_version;
    HeaderLayout hLayout;
    struct MeterColumnSetting *hColumns;
    Hashtable_2 *dynamicColumns;
    Hashtable_2 *dynamicMeters;
    Hashtable_2 *dynamicScreens;
    ScreenSettings_2 **screens;
    uint nScreens;
    uint ssIndex;
    ScreenSettings_2 *ss;
    wchar_t colorScheme;
    wchar_t delay;
    _Bool countCPUsFromOne;
    _Bool detailedCPUTime;
    _Bool showCPUUsage;
    _Bool showCPUFrequency;
    _Bool showCPUTemperature;
    _Bool degreeFahrenheit;
    _Bool showProgramPath;
    _Bool shadowOtherUsers;
    _Bool showThreadNames;
    _Bool hideKernelThreads;
    _Bool hideRunningInContainer;
    _Bool hideUserlandThreads;
    _Bool highlightBaseName;
    _Bool highlightDeletedExe;
    _Bool shadowDistPathPrefix;
    _Bool highlightMegabytes;
    _Bool highlightThreads;
    _Bool highlightChanges;
    byte field_0x62;
    byte field_0x63;
    wchar_t highlightDelaySecs;
    _Bool findCommInCmdline;
    _Bool stripExeFromCmdline;
    _Bool showMergedCommand;
    _Bool updateProcessNames;
    _Bool accountGuestInCPUMeter;
    _Bool headerMargin;
    _Bool screenTabs;
    _Bool enableMouse;
    wchar_t hideFunctionBar;
    _Bool changed;
    byte field_0x75;
    byte field_0x76;
    byte field_0x77;
    uint64_t lastUpdate;
};

struct UsersTable_ {
    Hashtable_2 *users;
};

union anon_union_8_2_1989b71c_for_keys {
    char **keys;
    char **constKeys;
};

struct Hashtable_ {
    size_t size;
    HashtableItem *buckets;
    size_t items;
    _Bool owner;
    byte field_0x19;
    byte field_0x1a;
    byte field_0x1b;
    byte field_0x1c;
    byte field_0x1d;
    byte field_0x1e;
    byte field_0x1f;
};

struct ScreenSettings__2 {
    char *heading;
    char *dynamic;
    struct Table_ *table;
    RowField *fields;
    uint32_t flags;
    wchar_t direction;
    wchar_t treeDirection;
    RowField sortKey;
    RowField treeSortKey;
    _Bool treeView;
    _Bool treeViewAlwaysByPID;
    _Bool allBranchesCollapsed;
    byte field_0x37;
};

struct ObjectClass_ {
    void *extends;
    Object_Display display;
    Object_Delete delete;
    Object_Compare compare;
};

struct Vector_ {
    Object **array;
    ObjectClass *type;
    wchar_t arraySize;
    wchar_t growthRate;
    wchar_t items;
    wchar_t dirty_index;
    wchar_t dirty_count;
    _Bool owner;
    byte field_0x25;
    byte field_0x26;
    byte field_0x27;
};

struct FunctionBar_ {
    wchar_t size;
    byte field_0x4;
    byte field_0x5;
    byte field_0x6;
    byte field_0x7;
    char **functions;
    union anon_union_8_2_1989b71c_for_keys keys;
    wchar_t *events;
    _Bool staticData;
    byte field_0x21;
    byte field_0x22;
    byte field_0x23;
    byte field_0x24;
    byte field_0x25;
    byte field_0x26;
    byte field_0x27;
};

struct timeval {
    __time_t tv_sec;
    __suseconds_t tv_usec;
};

struct Machine_ {
    struct Settings__2 *settings;
    struct timeval realtime;
    uint64_t realtimeMs;
    uint64_t monotonicMs;
    int64_t iterationsRemaining;
    memory_t totalMem;
    memory_t usedMem;
    memory_t buffersMem;
    memory_t cachedMem;
    memory_t sharedMem;
    memory_t availableMem;
    memory_t totalSwap;
    memory_t usedSwap;
    memory_t cachedSwap;
    uint activeCPUs;
    uint existingCPUs;
    UsersTable *usersTable;
    uid_t htopUserId;
    uid_t maxUserId;
    uid_t userId;
    byte field_0x94;
    byte field_0x95;
    byte field_0x96;
    byte field_0x97;
    size_t tableCount;
    Table **tables;
    Table *activeTable;
    Table *processTable;
};

struct Object_ {
    ObjectClass *klass;
};

struct Table_ {
    Object super;
    Vector *rows;
    Vector *displayList;
    Hashtable_2 *table;
    struct Machine_ *host;
    char *incFilter;
    _Bool needsSort;
    byte field_0x31;
    byte field_0x32;
    byte field_0x33;
    wchar_t following;
    struct Panel_ *panel;
};

struct cchar_t {
    attr_t attr;
    wchar_t chars[5];
    wchar_t ext_color;
};

struct RichString_ {
    wchar_t chlen;
    byte field_0x4;
    byte field_0x5;
    byte field_0x6;
    byte field_0x7;
    struct cchar_t *chptr;
    struct cchar_t chstr[351];
    wchar_t highlightAttr;
};

struct Panel_ {
    Object super;
    wchar_t x;
    wchar_t y;
    wchar_t w;
    wchar_t h;
    wchar_t cursorX;
    wchar_t cursorY;
    Vector *items;
    wchar_t selected;
    wchar_t oldSelected;
    wchar_t selectedLen;
    byte field_0x34;
    byte field_0x35;
    byte field_0x36;
    byte field_0x37;
    void *eventHandlerState;
    wchar_t scrollV;
    wchar_t scrollH;
    _Bool needsRedraw;
    _Bool cursorOn;
    _Bool wasFocus;
    byte field_0x4b;
    byte field_0x4c;
    byte field_0x4d;
    byte field_0x4e;
    byte field_0x4f;
    FunctionBar *currentBar;
    FunctionBar *defaultBar;
    RichString header;
    ColorElements selectionColorId;
    byte field_0x26dc;
    byte field_0x26dd;
    byte field_0x26de;
    byte field_0x26df;
};

struct HashtableItem_ {
    ht_key_t key;
    byte field_0x4;
    byte field_0x5;
    byte field_0x6;
    byte field_0x7;
    size_t probe;
    void *value;
};

struct MeterColumnSetting {
    size_t len;
    char **names;
    wchar_t *modes;
};

typedef struct Machine_ Machine;

typedef struct Machine__2 Machine__2, *PMachine__2;

typedef struct Machine__2 Machine_2;

typedef struct Settings__3 Settings__3, *PSettings__3;

typedef struct Table__2 Table__2, *PTable__2;

typedef struct Table__2 Table_2;

typedef struct ScreenSettings__3 ScreenSettings__3, *PScreenSettings__3;

typedef struct ScreenSettings__3 ScreenSettings_3;

struct Machine__2 {
    struct Settings__3 *settings;
    struct timeval realtime;
    uint64_t realtimeMs;
    uint64_t monotonicMs;
    int64_t iterationsRemaining;
    memory_t totalMem;
    memory_t usedMem;
    memory_t buffersMem;
    memory_t cachedMem;
    memory_t sharedMem;
    memory_t availableMem;
    memory_t totalSwap;
    memory_t usedSwap;
    memory_t cachedSwap;
    uint activeCPUs;
    uint existingCPUs;
    UsersTable *usersTable;
    uid_t htopUserId;
    uid_t maxUserId;
    uid_t userId;
    byte field_0x94;
    byte field_0x95;
    byte field_0x96;
    byte field_0x97;
    size_t tableCount;
    Table_2 **tables;
    Table_2 *activeTable;
    Table_2 *processTable;
};

struct ScreenSettings__3 {
    char *heading;
    char *dynamic;
    struct Table__2 *table;
    RowField *fields;
    uint32_t flags;
    wchar_t direction;
    wchar_t treeDirection;
    RowField sortKey;
    RowField treeSortKey;
    _Bool treeView;
    _Bool treeViewAlwaysByPID;
    _Bool allBranchesCollapsed;
    byte field_0x37;
};

struct Settings__3 {
    char *filename;
    wchar_t config_version;
    HeaderLayout hLayout;
    struct MeterColumnSetting *hColumns;
    Hashtable_2 *dynamicColumns;
    Hashtable_2 *dynamicMeters;
    Hashtable_2 *dynamicScreens;
    ScreenSettings_3 **screens;
    uint nScreens;
    uint ssIndex;
    ScreenSettings_3 *ss;
    wchar_t colorScheme;
    wchar_t delay;
    _Bool countCPUsFromOne;
    _Bool detailedCPUTime;
    _Bool showCPUUsage;
    _Bool showCPUFrequency;
    _Bool showCPUTemperature;
    _Bool degreeFahrenheit;
    _Bool showProgramPath;
    _Bool shadowOtherUsers;
    _Bool showThreadNames;
    _Bool hideKernelThreads;
    _Bool hideRunningInContainer;
    _Bool hideUserlandThreads;
    _Bool highlightBaseName;
    _Bool highlightDeletedExe;
    _Bool shadowDistPathPrefix;
    _Bool highlightMegabytes;
    _Bool highlightThreads;
    _Bool highlightChanges;
    byte field_0x62;
    byte field_0x63;
    wchar_t highlightDelaySecs;
    _Bool findCommInCmdline;
    _Bool stripExeFromCmdline;
    _Bool showMergedCommand;
    _Bool updateProcessNames;
    _Bool accountGuestInCPUMeter;
    _Bool headerMargin;
    _Bool screenTabs;
    _Bool enableMouse;
    wchar_t hideFunctionBar;
    _Bool changed;
    byte field_0x75;
    byte field_0x76;
    byte field_0x77;
    uint64_t lastUpdate;
};

struct Table__2 {
    Object super;
    Vector *rows;
    Vector *displayList;
    Hashtable_2 *table;
    struct Machine__2 *host;
    char *incFilter;
    _Bool needsSort;
    byte field_0x31;
    byte field_0x32;
    byte field_0x33;
    wchar_t following;
    struct Panel_ *panel;
};

typedef struct Machine__4 Machine__4, *PMachine__4;

typedef struct Machine__4 Machine_3;

typedef struct Settings__5 Settings__5, *PSettings__5;

typedef struct Table__5 Table__5, *PTable__5;

typedef struct Table__5 Table_4;

typedef struct ScreenSettings__6 ScreenSettings__6, *PScreenSettings__6;

typedef struct ScreenSettings__6 ScreenSettings_6;

struct ScreenSettings__6 {
    char *heading;
    char *dynamic;
    struct Table__5 *table;
    RowField *fields;
    uint32_t flags;
    wchar_t direction;
    wchar_t treeDirection;
    RowField sortKey;
    RowField treeSortKey;
    _Bool treeView;
    _Bool treeViewAlwaysByPID;
    _Bool allBranchesCollapsed;
    byte field_0x37;
};

struct Machine__4 {
    struct Settings__5 *settings;
    struct timeval realtime;
    uint64_t realtimeMs;
    uint64_t monotonicMs;
    int64_t iterationsRemaining;
    memory_t totalMem;
    memory_t usedMem;
    memory_t buffersMem;
    memory_t cachedMem;
    memory_t sharedMem;
    memory_t availableMem;
    memory_t totalSwap;
    memory_t usedSwap;
    memory_t cachedSwap;
    uint activeCPUs;
    uint existingCPUs;
    UsersTable *usersTable;
    uid_t htopUserId;
    uid_t maxUserId;
    uid_t userId;
    byte field_0x94;
    byte field_0x95;
    byte field_0x96;
    byte field_0x97;
    size_t tableCount;
    Table_4 **tables;
    Table_4 *activeTable;
    Table_4 *processTable;
};

struct Settings__5 {
    char *filename;
    wchar_t config_version;
    HeaderLayout hLayout;
    struct MeterColumnSetting *hColumns;
    Hashtable_2 *dynamicColumns;
    Hashtable_2 *dynamicMeters;
    Hashtable_2 *dynamicScreens;
    ScreenSettings_6 **screens;
    uint nScreens;
    uint ssIndex;
    ScreenSettings_6 *ss;
    wchar_t colorScheme;
    wchar_t delay;
    _Bool countCPUsFromOne;
    _Bool detailedCPUTime;
    _Bool showCPUUsage;
    _Bool showCPUFrequency;
    _Bool showCPUTemperature;
    _Bool degreeFahrenheit;
    _Bool showProgramPath;
    _Bool shadowOtherUsers;
    _Bool showThreadNames;
    _Bool hideKernelThreads;
    _Bool hideRunningInContainer;
    _Bool hideUserlandThreads;
    _Bool highlightBaseName;
    _Bool highlightDeletedExe;
    _Bool shadowDistPathPrefix;
    _Bool highlightMegabytes;
    _Bool highlightThreads;
    _Bool highlightChanges;
    byte field_0x62;
    byte field_0x63;
    wchar_t highlightDelaySecs;
    _Bool findCommInCmdline;
    _Bool stripExeFromCmdline;
    _Bool showMergedCommand;
    _Bool updateProcessNames;
    _Bool accountGuestInCPUMeter;
    _Bool headerMargin;
    _Bool screenTabs;
    _Bool enableMouse;
    wchar_t hideFunctionBar;
    _Bool changed;
    byte field_0x75;
    byte field_0x76;
    byte field_0x77;
    uint64_t lastUpdate;
};

struct Table__5 {
    Object super;
    Vector *rows;
    Vector *displayList;
    Hashtable_2 *table;
    struct Machine__4 *host;
    char *incFilter;
    _Bool needsSort;
    byte field_0x31;
    byte field_0x32;
    byte field_0x33;
    wchar_t following;
    struct Panel_ *panel;
};

typedef struct Machine__3 Machine__3, *PMachine__3;

typedef struct Machine__3 Machine_4;

typedef struct Settings__4 Settings__4, *PSettings__4;

typedef struct Table__3 Table__3, *PTable__3;

typedef struct Table__3 Table_3;

typedef struct ScreenSettings__4 ScreenSettings__4, *PScreenSettings__4;

typedef struct ScreenSettings__4 ScreenSettings_4;

struct ScreenSettings__4 {
    char *heading;
    char *dynamic;
    struct Table__3 *table;
    RowField *fields;
    uint32_t flags;
    wchar_t direction;
    wchar_t treeDirection;
    RowField sortKey;
    RowField treeSortKey;
    _Bool treeView;
    _Bool treeViewAlwaysByPID;
    _Bool allBranchesCollapsed;
    byte field_0x37;
};

struct Machine__3 {
    struct Settings__4 *settings;
    struct timeval realtime;
    uint64_t realtimeMs;
    uint64_t monotonicMs;
    int64_t iterationsRemaining;
    memory_t totalMem;
    memory_t usedMem;
    memory_t buffersMem;
    memory_t cachedMem;
    memory_t sharedMem;
    memory_t availableMem;
    memory_t totalSwap;
    memory_t usedSwap;
    memory_t cachedSwap;
    uint activeCPUs;
    uint existingCPUs;
    UsersTable *usersTable;
    uid_t htopUserId;
    uid_t maxUserId;
    uid_t userId;
    byte field_0x94;
    byte field_0x95;
    byte field_0x96;
    byte field_0x97;
    size_t tableCount;
    Table_3 **tables;
    Table_3 *activeTable;
    Table_3 *processTable;
};

struct Table__3 {
    Object super;
    Vector *rows;
    Vector *displayList;
    Hashtable_2 *table;
    struct Machine__3 *host;
    char *incFilter;
    _Bool needsSort;
    byte field_0x31;
    byte field_0x32;
    byte field_0x33;
    wchar_t following;
    struct Panel_ *panel;
};

struct Settings__4 {
    char *filename;
    wchar_t config_version;
    HeaderLayout hLayout;
    struct MeterColumnSetting *hColumns;
    Hashtable_2 *dynamicColumns;
    Hashtable_2 *dynamicMeters;
    Hashtable_2 *dynamicScreens;
    ScreenSettings_4 **screens;
    uint nScreens;
    uint ssIndex;
    ScreenSettings_4 *ss;
    wchar_t colorScheme;
    wchar_t delay;
    _Bool countCPUsFromOne;
    _Bool detailedCPUTime;
    _Bool showCPUUsage;
    _Bool showCPUFrequency;
    _Bool showCPUTemperature;
    _Bool degreeFahrenheit;
    _Bool showProgramPath;
    _Bool shadowOtherUsers;
    _Bool showThreadNames;
    _Bool hideKernelThreads;
    _Bool hideRunningInContainer;
    _Bool hideUserlandThreads;
    _Bool highlightBaseName;
    _Bool highlightDeletedExe;
    _Bool shadowDistPathPrefix;
    _Bool highlightMegabytes;
    _Bool highlightThreads;
    _Bool highlightChanges;
    byte field_0x62;
    byte field_0x63;
    wchar_t highlightDelaySecs;
    _Bool findCommInCmdline;
    _Bool stripExeFromCmdline;
    _Bool showMergedCommand;
    _Bool updateProcessNames;
    _Bool accountGuestInCPUMeter;
    _Bool headerMargin;
    _Bool screenTabs;
    _Bool enableMouse;
    wchar_t hideFunctionBar;
    _Bool changed;
    byte field_0x75;
    byte field_0x76;
    byte field_0x77;
    uint64_t lastUpdate;
};

typedef struct MetersPanel_ MetersPanel_, *PMetersPanel_;

typedef struct MetersPanel_ MetersPanel;

typedef struct Panel_ Panel;

typedef struct Settings__4 Settings_3;

typedef struct ScreenManager__2 ScreenManager__2, *PScreenManager__2;

typedef struct ScreenManager__2 ScreenManager_2;

typedef struct Header__3 Header__3, *PHeader__3;

typedef struct Header__3 Header_3;

typedef struct State__3 State__3, *PState__3;

typedef struct State__3 State_3;

typedef struct MainPanel_ MainPanel_, *PMainPanel_;

typedef struct State_ State_, *PState_;

typedef struct State_ State;

typedef struct IncSet__2 IncSet__2, *PIncSet__2;

typedef struct IncSet__2 IncSet_2;

typedef enum Htop_Reaction {
    HTOP_OK=0,
    HTOP_REFRESH=1,
    HTOP_RECALCULATE=3,
    HTOP_SAVE_SETTINGS=4,
    HTOP_KEEP_FOLLOWING=8,
    HTOP_QUIT=16,
    HTOP_REDRAW_BAR=32,
    HTOP_UPDATE_PANELHDR=65,
    HTOP_RESIZE=225
} Htop_Reaction;

typedef Htop_Reaction (*Htop_Action)(State *);

typedef struct Header__4 Header__4, *PHeader__4;

typedef struct Header__4 Header_4;

typedef struct IncMode_ IncMode_, *PIncMode_;

typedef struct IncMode_ IncMode;

struct MainPanel_ {
    Panel super;
    State *state;
    IncSet_2 *inc;
    Htop_Action *keys;
    FunctionBar *processBar;
    FunctionBar *readonlyBar;
    uint idSearch;
    byte field_0x270c;
    byte field_0x270d;
    byte field_0x270e;
    byte field_0x270f;
};

struct ScreenManager__2 {
    wchar_t x1;
    wchar_t y1;
    wchar_t x2;
    wchar_t y2;
    Vector *panels;
    char *name;
    wchar_t panelCount;
    byte field_0x24;
    byte field_0x25;
    byte field_0x26;
    byte field_0x27;
    Header_3 *header;
    Machine_4 *host;
    State_3 *state;
    _Bool allowFocusChange;
    byte field_0x41;
    byte field_0x42;
    byte field_0x43;
    byte field_0x44;
    byte field_0x45;
    byte field_0x46;
    byte field_0x47;
};

struct State__3 {
    Machine_4 *host;
    struct MainPanel_ *mainPanel;
    Header_3 *header;
    _Bool pauseUpdate;
    _Bool hideSelection;
    _Bool hideMeters;
    byte field_0x1b;
    byte field_0x1c;
    byte field_0x1d;
    byte field_0x1e;
    byte field_0x1f;
};

struct MetersPanel_ {
    Panel super;
    Settings_3 *settings;
    Vector *meters;
    ScreenManager_2 *scr;
    MetersPanel *leftNeighbor;
    MetersPanel *rightNeighbor;
    _Bool moving;
    byte field_0x2709;
    byte field_0x270a;
    byte field_0x270b;
    byte field_0x270c;
    byte field_0x270d;
    byte field_0x270e;
    byte field_0x270f;
};

struct IncMode_ {
    char buffer[129];
    byte field_0x81;
    byte field_0x82;
    byte field_0x83;
    wchar_t index;
    FunctionBar *bar;
    _Bool isFilter;
    byte field_0x91;
    byte field_0x92;
    byte field_0x93;
    byte field_0x94;
    byte field_0x95;
    byte field_0x96;
    byte field_0x97;
};

struct IncSet__2 {
    IncMode modes[2];
    IncMode *active;
    Panel *panel;
    FunctionBar *defaultBar;
    _Bool filtering;
    _Bool found;
    byte field_0x14a;
    byte field_0x14b;
    byte field_0x14c;
    byte field_0x14d;
    byte field_0x14e;
    byte field_0x14f;
};

struct State_ {
    Machine_2 *host;
    struct MainPanel_ *mainPanel;
    Header_4 *header;
    _Bool pauseUpdate;
    _Bool hideSelection;
    _Bool hideMeters;
    byte field_0x1b;
    byte field_0x1c;
    byte field_0x1d;
    byte field_0x1e;
    byte field_0x1f;
};

struct Header__4 {
    Vector **columns;
    Machine_2 *host;
    HeaderLayout headerLayout;
    wchar_t pad;
    wchar_t height;
    byte field_0x1c;
    byte field_0x1d;
    byte field_0x1e;
    byte field_0x1f;
};

struct Header__3 {
    Vector **columns;
    Machine_4 *host;
    HeaderLayout headerLayout;
    wchar_t pad;
    wchar_t height;
    byte field_0x1c;
    byte field_0x1d;
    byte field_0x1e;
    byte field_0x1f;
};

typedef struct MetersPanel__2 MetersPanel__2, *PMetersPanel__2;

typedef struct MetersPanel__2 MetersPanel_2;

typedef struct Settings__3 Settings_4;

typedef struct ScreenManager__3 ScreenManager__3, *PScreenManager__3;

typedef struct ScreenManager__3 ScreenManager_3;

struct ScreenManager__3 {
    wchar_t x1;
    wchar_t y1;
    wchar_t x2;
    wchar_t y2;
    Vector *panels;
    char *name;
    wchar_t panelCount;
    byte field_0x24;
    byte field_0x25;
    byte field_0x26;
    byte field_0x27;
    Header_4 *header;
    Machine_2 *host;
    State *state;
    _Bool allowFocusChange;
    byte field_0x41;
    byte field_0x42;
    byte field_0x43;
    byte field_0x44;
    byte field_0x45;
    byte field_0x46;
    byte field_0x47;
};

struct MetersPanel__2 {
    Panel super;
    Settings_4 *settings;
    Vector *meters;
    ScreenManager_3 *scr;
    MetersPanel_2 *leftNeighbor;
    MetersPanel_2 *rightNeighbor;
    _Bool moving;
    byte field_0x2709;
    byte field_0x270a;
    byte field_0x270b;
    byte field_0x270c;
    byte field_0x270d;
    byte field_0x270e;
    byte field_0x270f;
};

typedef struct anon_struct_16_2_f5102bc2 anon_struct_16_2_f5102bc2, *Panon_struct_16_2_f5102bc2;

struct anon_struct_16_2_f5102bc2 {
    wchar_t klass;
    byte field_0x4;
    byte field_0x5;
    byte field_0x6;
    byte field_0x7;
    char *name;
};

typedef struct Header_ Header_, *PHeader_;

struct Header_ {
    Vector **columns;
    Machine_3 *host;
    HeaderLayout headerLayout;
    wchar_t pad;
    wchar_t height;
    byte field_0x1c;
    byte field_0x1d;
    byte field_0x1e;
    byte field_0x1f;
};

typedef struct Header_ Header;

typedef struct Header__2 Header__2, *PHeader__2;

typedef struct Header__2 Header_2;

struct Header__2 {
    Vector **columns;
    Machine *host;
    HeaderLayout headerLayout;
    wchar_t pad;
    wchar_t height;
    byte field_0x1c;
    byte field_0x1d;
    byte field_0x1e;
    byte field_0x1f;
};

typedef struct Meter_ Meter_, *PMeter_;

typedef struct Meter_ Meter;

typedef void (*Meter_Done)(Meter *);

typedef void (*Meter_Draw)(Meter *, wchar_t, wchar_t, wchar_t);

typedef struct GraphData_ GraphData_, *PGraphData_;

typedef struct GraphData_ GraphData;

typedef __uint8_t uint8_t;

struct GraphData_ {
    struct timeval time;
    size_t nValues;
    double *values;
};

struct Meter_ {
    Object super;
    Meter_Draw draw;
    Machine *host;
    char *caption;
    wchar_t mode;
    uint param;
    GraphData drawData;
    wchar_t h;
    wchar_t columnWidthCount;
    uint8_t curItems;
    byte field_0x51;
    byte field_0x52;
    byte field_0x53;
    byte field_0x54;
    byte field_0x55;
    byte field_0x56;
    byte field_0x57;
    wchar_t *curAttributes;
    char txtBuffer[256];
    double *values;
    double total;
    void *meterData;
};

typedef void (*Meter_UpdateValues)(Meter *);

typedef void (*Meter_UpdateMode)(Meter *, wchar_t);

typedef struct MeterClass_ MeterClass_, *PMeterClass_;

typedef void (*Meter_Init)(Meter *);

typedef char * (*Meter_GetCaption)(Meter *);

typedef void (*Meter_GetUiName)(Meter *, char *, size_t);

struct MeterClass_ {
    ObjectClass super;
    Meter_Init init;
    Meter_Done done;
    Meter_UpdateMode updateMode;
    Meter_UpdateValues updateValues;
    Meter_Draw draw;
    Meter_GetCaption getCaption;
    Meter_GetUiName getUiName;
    wchar_t defaultMode;
    byte field_0x5c;
    byte field_0x5d;
    byte field_0x5e;
    byte field_0x5f;
    double total;
    wchar_t *attributes;
    char *name;
    char *uiName;
    char *caption;
    char *description;
    uint8_t maxItems;
    _Bool isMultiColumn;
    byte field_0x92;
    byte field_0x93;
    byte field_0x94;
    byte field_0x95;
    byte field_0x96;
    byte field_0x97;
};

typedef struct MeterClass_ MeterClass;

typedef enum MeterModeId {
    CUSTOM_METERMODE=0,
    BAR_METERMODE=1,
    TEXT_METERMODE=2,
    GRAPH_METERMODE=3,
    LED_METERMODE=4,
    LAST_METERMODE=5
} MeterModeId;

typedef struct MeterMode_ MeterMode_, *PMeterMode_;

typedef struct MeterMode_ MeterMode;

typedef void (*Meter_Draw_3)(Meter *, wchar_t, wchar_t, wchar_t);

struct MeterMode_ {
    Meter_Draw_3 draw;
    char *uiName;
    wchar_t h;
    byte field_0x14;
    byte field_0x15;
    byte field_0x16;
    byte field_0x17;
};

typedef char * (*Meter_GetCaption_2)(Meter *);

typedef void (*Meter_GetUiName_2)(Meter *, char *, size_t);

typedef void (*Meter_Draw_2)(Meter *, wchar_t, wchar_t, wchar_t);

typedef void (*Meter_UpdateValues_2)(Meter *);

typedef struct MeterClass__2 MeterClass__2, *PMeterClass__2;

typedef struct MeterClass__2 MeterClass_2;

typedef void (*Meter_Init_2)(Meter *);

typedef void (*Meter_Done_2)(Meter *);

typedef void (*Meter_UpdateMode_2)(Meter *, wchar_t);

struct MeterClass__2 {
    ObjectClass super;
    Meter_Init_2 init;
    Meter_Done_2 done;
    Meter_UpdateMode_2 updateMode;
    Meter_UpdateValues_2 updateValues;
    Meter_Draw_2 draw;
    Meter_GetCaption_2 getCaption;
    Meter_GetUiName_2 getUiName;
    wchar_t defaultMode;
    byte field_0x5c;
    byte field_0x5d;
    byte field_0x5e;
    byte field_0x5f;
    double total;
    wchar_t *attributes;
    char *name;
    char *uiName;
    char *caption;
    char *description;
    uint8_t maxItems;
    _Bool isMultiColumn;
    byte field_0x92;
    byte field_0x93;
    byte field_0x94;
    byte field_0x95;
    byte field_0x96;
    byte field_0x97;
};

typedef struct Meter__2 Meter__2, *PMeter__2;

typedef struct Meter__2 Meter_2;

struct Meter__2 {
    Object super;
    Meter_Draw_2 draw;
    Machine_4 *host;
    char *caption;
    wchar_t mode;
    uint param;
    GraphData drawData;
    wchar_t h;
    wchar_t columnWidthCount;
    uint8_t curItems;
    byte field_0x51;
    byte field_0x52;
    byte field_0x53;
    byte field_0x54;
    byte field_0x55;
    byte field_0x56;
    byte field_0x57;
    wchar_t *curAttributes;
    char txtBuffer[256];
    double *values;
    double total;
    void *meterData;
};

typedef struct Meter__3 Meter__3, *PMeter__3;

typedef struct Meter__3 Meter_3;

struct Meter__3 {
    Object super;
    Meter_Draw_3 draw;
    Machine_2 *host;
    char *caption;
    wchar_t mode;
    uint param;
    GraphData drawData;
    wchar_t h;
    wchar_t columnWidthCount;
    uint8_t curItems;
    byte field_0x51;
    byte field_0x52;
    byte field_0x53;
    byte field_0x54;
    byte field_0x55;
    byte field_0x56;
    byte field_0x57;
    wchar_t *curAttributes;
    char txtBuffer[256];
    double *values;
    double total;
    void *meterData;
};

typedef struct MeterClass__3 MeterClass__3, *PMeterClass__3;

typedef struct MeterClass__3 MeterClass_3;

typedef void (*Meter_Init_3)(Meter *);

typedef void (*Meter_Done_3)(Meter *);

typedef void (*Meter_UpdateMode_3)(Meter *, wchar_t);

typedef void (*Meter_UpdateValues_3)(Meter *);

typedef char * (*Meter_GetCaption_3)(Meter *);

typedef void (*Meter_GetUiName_3)(Meter *, char *, size_t);

struct MeterClass__3 {
    ObjectClass super;
    Meter_Init_3 init;
    Meter_Done_3 done;
    Meter_UpdateMode_3 updateMode;
    Meter_UpdateValues_3 updateValues;
    Meter_Draw_3 draw;
    Meter_GetCaption_3 getCaption;
    Meter_GetUiName_3 getUiName;
    wchar_t defaultMode;
    byte field_0x5c;
    byte field_0x5d;
    byte field_0x5e;
    byte field_0x5f;
    double total;
    wchar_t *attributes;
    char *name;
    char *uiName;
    char *caption;
    char *description;
    uint8_t maxItems;
    _Bool isMultiColumn;
    byte field_0x92;
    byte field_0x93;
    byte field_0x94;
    byte field_0x95;
    byte field_0x96;
    byte field_0x97;
};

typedef enum MeterRateStatus {
    RATESTATUS_DATA=0,
    RATESTATUS_INIT=1,
    RATESTATUS_NODATA=2,
    RATESTATUS_STALE=3
} MeterRateStatus;

typedef union sigval sigval, *Psigval;

union sigval {
    wchar_t sival_int;
    void *sival_ptr;
};

typedef union sigval __sigval_t;

typedef struct SystemdMeterContext SystemdMeterContext, *PSystemdMeterContext;

typedef struct SystemdMeterContext SystemdMeterContext_t;

typedef void sd_bus;

struct SystemdMeterContext {
    sd_bus *bus;
    char *systemState;
    uint nFailedUnits;
    uint nInstalledJobs;
    uint nNames;
    uint nJobs;
};

typedef void sd_bus_error;

typedef enum anon_enum_32 {
    CPU_METER_NICE=0,
    CPU_METER_NORMAL=1,
    CPU_METER_KERNEL=2,
    CPU_METER_IRQ=3,
    CPU_METER_SOFTIRQ=4,
    CPU_METER_STEAL=5,
    CPU_METER_GUEST=6,
    CPU_METER_IOWAIT=7,
    CPU_METER_FREQUENCY=8,
    CPU_METER_TEMPERATURE=9,
    CPU_METER_ITEMCOUNT=10
} anon_enum_32;

typedef __id_t id_t;

typedef struct __fsid_t __fsid_t, *P__fsid_t;

struct __fsid_t {
    wchar_t __val[2];
};

typedef __dev_t dev_t;

typedef __ssize_t ssize_t;

typedef struct __dirstream DIR;

typedef struct dirent dirent, *Pdirent;

struct dirent {
    __ino_t d_ino;
    __off_t d_off;
    ushort d_reclen;
    uchar d_type;
    char d_name[256];
    byte field_0x113;
    byte field_0x114;
    byte field_0x115;
    byte field_0x116;
    byte field_0x117;
};

typedef struct CategoriesPanel_ CategoriesPanel_, *PCategoriesPanel_;

typedef struct CategoriesPanel_ CategoriesPanel;

typedef struct ScreenManager_ ScreenManager_, *PScreenManager_;

typedef struct ScreenManager_ ScreenManager;

typedef struct State__2 State__2, *PState__2;

typedef struct State__2 State_2;

typedef struct MainPanel__2 MainPanel__2, *PMainPanel__2;

typedef struct IncSet_ IncSet_, *PIncSet_;

typedef struct IncSet_ IncSet;

typedef Htop_Reaction (*Htop_Action_2)(State *);

struct ScreenManager_ {
    wchar_t x1;
    wchar_t y1;
    wchar_t x2;
    wchar_t y2;
    Vector *panels;
    char *name;
    wchar_t panelCount;
    byte field_0x24;
    byte field_0x25;
    byte field_0x26;
    byte field_0x27;
    Header_2 *header;
    Machine *host;
    State_2 *state;
    _Bool allowFocusChange;
    byte field_0x41;
    byte field_0x42;
    byte field_0x43;
    byte field_0x44;
    byte field_0x45;
    byte field_0x46;
    byte field_0x47;
};

struct MainPanel__2 {
    Panel super;
    State_2 *state;
    IncSet *inc;
    Htop_Action_2 *keys;
    FunctionBar *processBar;
    FunctionBar *readonlyBar;
    uint idSearch;
    byte field_0x270c;
    byte field_0x270d;
    byte field_0x270e;
    byte field_0x270f;
};

struct CategoriesPanel_ {
    Panel super;
    ScreenManager *scr;
    Machine *host;
    Header_2 *header;
};

struct State__2 {
    Machine *host;
    struct MainPanel__2 *mainPanel;
    Header_2 *header;
    _Bool pauseUpdate;
    _Bool hideSelection;
    _Bool hideMeters;
    byte field_0x1b;
    byte field_0x1c;
    byte field_0x1d;
    byte field_0x1e;
    byte field_0x1f;
};

struct IncSet_ {
    IncMode modes[2];
    IncMode *active;
    Panel *panel;
    FunctionBar *defaultBar;
    _Bool filtering;
    _Bool found;
    byte field_0x14a;
    byte field_0x14b;
    byte field_0x14c;
    byte field_0x14d;
    byte field_0x14e;
    byte field_0x14f;
};

typedef struct CPUMeterData_ CPUMeterData_, *PCPUMeterData_;

typedef struct CPUMeterData_ CPUMeterData;

struct CPUMeterData_ {
    uint cpus;
    byte field_0x4;
    byte field_0x5;
    byte field_0x6;
    byte field_0x7;
    Meter_3 **meters;
};

typedef struct AffinityPanel_ AffinityPanel_, *PAffinityPanel_;

struct AffinityPanel_ {
    Panel super;
    Machine_2 *host;
    _Bool topoView;
    byte field_0x26e9;
    byte field_0x26ea;
    byte field_0x26eb;
    byte field_0x26ec;
    byte field_0x26ed;
    byte field_0x26ee;
    byte field_0x26ef;
    Vector *cpuids;
    uint width;
    byte field_0x26fc;
    byte field_0x26fd;
    byte field_0x26fe;
    byte field_0x26ff;
};

typedef struct MaskItem_ MaskItem_, *PMaskItem_;

typedef struct MaskItem_ MaskItem;

struct MaskItem_ {
    Object super;
    char *text;
    char *indent;
    wchar_t value;
    wchar_t sub_tree;
    Vector *children;
    wchar_t cpu;
    byte field_0x2c;
    byte field_0x2d;
    byte field_0x2e;
    byte field_0x2f;
};

typedef struct AffinityPanel_ AffinityPanel;

typedef struct CategoriesPanelPage_ CategoriesPanelPage_, *PCategoriesPanelPage_;

typedef void (*CategoriesPanel_makePageFunc)(CategoriesPanel *);

struct CategoriesPanelPage_ {
    char *name;
    CategoriesPanel_makePageFunc ctor;
};

typedef struct CategoriesPanelPage_ CategoriesPanelPage;

typedef struct __va_list_tag __va_list_tag, *P__va_list_tag;

struct __va_list_tag {
    uint gp_offset;
    uint fp_offset;
    void *overflow_arg_area;
    void *reg_save_area;
};

typedef struct __va_list_tag __builtin_va_list[1];

typedef __builtin_va_list __gnuc_va_list;

typedef struct SignalItem_ SignalItem_, *PSignalItem_;

typedef struct SignalItem_ SignalItem;

struct SignalItem_ {
    char *name;
    wchar_t number;
    byte field_0xc;
    byte field_0xd;
    byte field_0xe;
    byte field_0xf;
};

typedef struct siginfo_t siginfo_t, *Psiginfo_t;

typedef union anon_union_112_8_26c2b70a_for__sifields anon_union_112_8_26c2b70a_for__sifields, *Panon_union_112_8_26c2b70a_for__sifields;

typedef struct anon_struct_8_2_0a3d7222_for__kill anon_struct_8_2_0a3d7222_for__kill, *Panon_struct_8_2_0a3d7222_for__kill;

typedef struct anon_struct_16_3_5124685d_for__timer anon_struct_16_3_5124685d_for__timer, *Panon_struct_16_3_5124685d_for__timer;

typedef struct anon_struct_16_3_9bedbd60_for__rt anon_struct_16_3_9bedbd60_for__rt, *Panon_struct_16_3_9bedbd60_for__rt;

typedef struct anon_struct_32_5_7a6ff138_for__sigchld anon_struct_32_5_7a6ff138_for__sigchld, *Panon_struct_32_5_7a6ff138_for__sigchld;

typedef struct anon_struct_32_3_f01937af_for__sigfault anon_struct_32_3_f01937af_for__sigfault, *Panon_struct_32_3_f01937af_for__sigfault;

typedef struct anon_struct_16_2_3c0246b2_for__sigpoll anon_struct_16_2_3c0246b2_for__sigpoll, *Panon_struct_16_2_3c0246b2_for__sigpoll;

typedef struct anon_struct_16_3_349d2ff7_for__sigsys anon_struct_16_3_349d2ff7_for__sigsys, *Panon_struct_16_3_349d2ff7_for__sigsys;

typedef union anon_union_16_2_200698a6_for__bounds anon_union_16_2_200698a6_for__bounds, *Panon_union_16_2_200698a6_for__bounds;

typedef struct anon_struct_16_2_6c587c7a_for__addr_bnd anon_struct_16_2_6c587c7a_for__addr_bnd, *Panon_struct_16_2_6c587c7a_for__addr_bnd;

struct anon_struct_16_2_6c587c7a_for__addr_bnd {
    void *_lower;
    void *_upper;
};

union anon_union_16_2_200698a6_for__bounds {
    struct anon_struct_16_2_6c587c7a_for__addr_bnd _addr_bnd;
    __uint32_t _pkey;
};

struct anon_struct_32_5_7a6ff138_for__sigchld {
    __pid_t si_pid;
    __uid_t si_uid;
    wchar_t si_status;
    byte field_0xc;
    byte field_0xd;
    byte field_0xe;
    byte field_0xf;
    __clock_t si_utime;
    __clock_t si_stime;
};

struct anon_struct_8_2_0a3d7222_for__kill {
    __pid_t si_pid;
    __uid_t si_uid;
};

struct anon_struct_16_3_349d2ff7_for__sigsys {
    void *_call_addr;
    wchar_t _syscall;
    uint _arch;
};

struct anon_struct_16_3_5124685d_for__timer {
    wchar_t si_tid;
    wchar_t si_overrun;
    __sigval_t si_sigval;
};

struct anon_struct_32_3_f01937af_for__sigfault {
    void *si_addr;
    short si_addr_lsb;
    byte field_0xa;
    byte field_0xb;
    byte field_0xc;
    byte field_0xd;
    byte field_0xe;
    byte field_0xf;
    union anon_union_16_2_200698a6_for__bounds _bounds;
};

struct anon_struct_16_3_9bedbd60_for__rt {
    __pid_t si_pid;
    __uid_t si_uid;
    __sigval_t si_sigval;
};

struct anon_struct_16_2_3c0246b2_for__sigpoll {
    long si_band;
    wchar_t si_fd;
    byte field_0xc;
    byte field_0xd;
    byte field_0xe;
    byte field_0xf;
};

union anon_union_112_8_26c2b70a_for__sifields {
    wchar_t _pad[28];
    struct anon_struct_8_2_0a3d7222_for__kill _kill;
    struct anon_struct_16_3_5124685d_for__timer _timer;
    struct anon_struct_16_3_9bedbd60_for__rt _rt;
    struct anon_struct_32_5_7a6ff138_for__sigchld _sigchld;
    struct anon_struct_32_3_f01937af_for__sigfault _sigfault;
    struct anon_struct_16_2_3c0246b2_for__sigpoll _sigpoll;
    struct anon_struct_16_3_349d2ff7_for__sigsys _sigsys;
};

struct siginfo_t {
    wchar_t si_signo;
    wchar_t si_errno;
    wchar_t si_code;
    wchar_t __pad0;
    union anon_union_112_8_26c2b70a_for__sifields _sifields;
};

typedef struct sigaction sigaction, *Psigaction;

typedef union anon_union_8_2_5ad2d23e_for___sigaction_handler anon_union_8_2_5ad2d23e_for___sigaction_handler, *Panon_union_8_2_5ad2d23e_for___sigaction_handler;

typedef struct __sigset_t __sigset_t, *P__sigset_t;

typedef void (*__sighandler_t)(wchar_t);

struct __sigset_t {
    ulong __val[16];
};

union anon_union_8_2_5ad2d23e_for___sigaction_handler {
    __sighandler_t sa_handler;
    void (*sa_sigaction)(wchar_t, struct siginfo_t *, void *);
};

struct sigaction {
    union anon_union_8_2_5ad2d23e_for___sigaction_handler __sigaction_handler;
    struct __sigset_t sa_mask;
    wchar_t sa_flags;
    byte field_0x8c;
    byte field_0x8d;
    byte field_0x8e;
    byte field_0x8f;
    void (*sa_restorer)(void);
};

typedef struct LinuxProcess_ LinuxProcess_, *PLinuxProcess_;

typedef struct LinuxProcess_ LinuxProcess;

typedef struct Process__3 Process__3, *PProcess__3;

typedef struct Process__3 Process_3;

typedef __pid_t pid_t;

typedef struct Row__3 Row__3, *PRow__3;

typedef struct Row__3 Row_3;

typedef __time_t time_t;

typedef enum ProcessState_ {
    UNKNOWN=1,
    RUNNABLE=2,
    RUNNING=3,
    QUEUED=4,
    WAITING=5,
    UNINTERRUPTIBLE_WAIT=6,
    BLOCKED=7,
    PAGING=8,
    STOPPED=9,
    TRACED=10,
    ZOMBIE=11,
    DEFUNCT=12,
    IDLE=13,
    SLEEPING=14
} ProcessState_;

typedef enum ProcessState_ ProcessState;

typedef struct ProcessMergedCommand_ ProcessMergedCommand_, *PProcessMergedCommand_;

typedef struct ProcessMergedCommand_ ProcessMergedCommand;

typedef struct ProcessCmdlineHighlight_ ProcessCmdlineHighlight_, *PProcessCmdlineHighlight_;

typedef struct ProcessCmdlineHighlight_ ProcessCmdlineHighlight;

struct ProcessCmdlineHighlight_ {
    size_t offset;
    size_t length;
    wchar_t attr;
    wchar_t flags;
};

struct Row__3 {
    Object super;
    struct Machine__4 *host;
    wchar_t id;
    wchar_t group;
    wchar_t parent;
    _Bool isRoot;
    _Bool tag;
    _Bool show;
    _Bool wasShown;
    _Bool showChildren;
    _Bool updated;
    byte field_0x22;
    byte field_0x23;
    int32_t indent;
    uint tree_depth;
    byte field_0x2c;
    byte field_0x2d;
    byte field_0x2e;
    byte field_0x2f;
    uint64_t seenStampMs;
    uint64_t tombStampMs;
};

struct ProcessMergedCommand_ {
    uint64_t lastUpdate;
    char *str;
    size_t highlightCount;
    ProcessCmdlineHighlight highlights[8];
};

struct Process__3 {
    Row_3 super;
    wchar_t pgrp;
    wchar_t session;
    wchar_t tpgid;
    _Bool isKernelThread;
    _Bool isUserlandThread;
    _Bool isRunningInContainer;
    byte field_0x4f;
    ulong tty_nr;
    char *tty_name;
    uid_t st_uid;
    byte field_0x64;
    byte field_0x65;
    byte field_0x66;
    byte field_0x67;
    char *user;
    _Bool elevated_priv;
    byte field_0x71;
    byte field_0x72;
    byte field_0x73;
    byte field_0x74;
    byte field_0x75;
    byte field_0x76;
    byte field_0x77;
    ulonglong time;
    char *cmdline;
    wchar_t cmdlineBasenameEnd;
    wchar_t cmdlineBasenameStart;
    char *procComm;
    char *procExe;
    char *procCwd;
    wchar_t procExeBasenameOffset;
    _Bool procExeDeleted;
    _Bool usesDeletedLib;
    byte field_0xae;
    byte field_0xaf;
    wchar_t processor;
    float percent_cpu;
    float percent_mem;
    byte field_0xbc;
    byte field_0xbd;
    byte field_0xbe;
    byte field_0xbf;
    long priority;
    long nice;
    long nlwp;
    time_t starttime_ctime;
    char starttime_show[8];
    long m_virt;
    long m_resident;
    ulong minflt;
    ulong majflt;
    ProcessState state;
    wchar_t scheduling_policy;
    ProcessMergedCommand mergedCommand;
};

struct LinuxProcess_ {
    Process_3 super;
    IOPriority ioPriority;
    byte field_0x1ec;
    byte field_0x1ed;
    byte field_0x1ee;
    byte field_0x1ef;
    ulong cminflt;
    ulong cmajflt;
    ulonglong utime;
    ulonglong stime;
    ulonglong cutime;
    ulonglong cstime;
    long m_share;
    long m_priv;
    long m_pss;
    long m_swap;
    long m_psswp;
    long m_trs;
    long m_drs;
    long m_lrs;
    ulong flags;
    ulonglong io_rchar;
    ulonglong io_wchar;
    ulonglong io_syscr;
    ulonglong io_syscw;
    ulonglong io_read_bytes;
    ulonglong io_write_bytes;
    ulonglong io_cancelled_write_bytes;
    ulonglong io_last_scan_time_ms;
    double io_rate_read_bps;
    double io_rate_write_bps;
    char *ctid;
    pid_t vpid;
    uint vxid;
    char *cgroup;
    char *cgroup_short;
    char *container_short;
    uint oom;
    byte field_0x2e4;
    byte field_0x2e5;
    byte field_0x2e6;
    byte field_0x2e7;
    ulonglong delay_read_time;
    ulonglong cpu_delay_total;
    ulonglong blkio_delay_total;
    ulonglong swapin_delay_total;
    float cpu_delay_percent;
    float blkio_delay_percent;
    float swapin_delay_percent;
    byte field_0x314;
    byte field_0x315;
    byte field_0x316;
    byte field_0x317;
    ulong ctxt_total;
    ulong ctxt_diff;
    char *secattr;
    ulonglong last_mlrs_calctime;
    long autogroup_id;
    wchar_t autogroup_nice;
    byte field_0x344;
    byte field_0x345;
    byte field_0x346;
    byte field_0x347;
};

typedef struct MemorySwapMeterData_ MemorySwapMeterData_, *PMemorySwapMeterData_;

struct MemorySwapMeterData_ {
    Meter_3 *memoryMeter;
    Meter_3 *swapMeter;
};

typedef struct MemorySwapMeterData_ MemorySwapMeterData;

typedef struct HeaderOptionsPanel_ HeaderOptionsPanel_, *PHeaderOptionsPanel_;

typedef struct HeaderOptionsPanel_ HeaderOptionsPanel;

struct HeaderOptionsPanel_ {
    Panel super;
    ScreenManager_3 *scr;
    Settings_4 *settings;
};

typedef enum __priority_which {
    PRIO_PROCESS=0,
    PRIO_PGRP=1,
    PRIO_USER=2
} __priority_which;

typedef enum __priority_which __priority_which_t;

typedef struct statfs statfs, *Pstatfs;

struct statfs {
    __fsword_t f_type;
    __fsword_t f_bsize;
    __fsblkcnt_t f_blocks;
    __fsblkcnt_t f_bfree;
    __fsblkcnt_t f_bavail;
    __fsfilcnt_t f_files;
    __fsfilcnt_t f_ffree;
    struct __fsid_t f_fsid;
    __fsword_t f_namelen;
    __fsword_t f_frsize;
    __fsword_t f_flags;
    __fsword_t f_spare[4];
};

typedef struct LinuxMachine_ LinuxMachine_, *PLinuxMachine_;

typedef struct CPUData_ CPUData_, *PCPUData_;

typedef struct CPUData_ CPUData;

typedef struct ZfsArcStats_ ZfsArcStats_, *PZfsArcStats_;

typedef struct ZfsArcStats_ ZfsArcStats;

typedef struct ZramStats_ ZramStats_, *PZramStats_;

typedef struct ZramStats_ ZramStats;

typedef struct ZswapStats_ ZswapStats_, *PZswapStats_;

typedef struct ZswapStats_ ZswapStats;

struct ZswapStats_ {
    memory_t usedZswapComp;
    memory_t usedZswapOrig;
};

struct ZramStats_ {
    memory_t totalZram;
    memory_t usedZramComp;
    memory_t usedZramOrig;
};

struct ZfsArcStats_ {
    wchar_t enabled;
    wchar_t isCompressed;
    ulonglong min;
    ulonglong max;
    ulonglong size;
    ulonglong MFU;
    ulonglong MRU;
    ulonglong anon;
    ulonglong header;
    ulonglong other;
    ulonglong compressed;
    ulonglong uncompressed;
};

struct LinuxMachine_ {
    Machine_3 super;
    long jiffies;
    wchar_t pageSize;
    wchar_t pageSizeKB;
    uint runningTasks;
    byte field_0xcc;
    byte field_0xcd;
    byte field_0xce;
    byte field_0xcf;
    longlong boottime;
    double period;
    CPUData *cpuData;
    memory_t totalHugePageMem;
    memory_t usedHugePageMem[24];
    memory_t availableMem;
    ZfsArcStats zfs;
    ZramStats zram;
    ZswapStats zswap;
};

struct CPUData_ {
    ulonglong totalTime;
    ulonglong userTime;
    ulonglong systemTime;
    ulonglong systemAllTime;
    ulonglong idleAllTime;
    ulonglong idleTime;
    ulonglong niceTime;
    ulonglong ioWaitTime;
    ulonglong irqTime;
    ulonglong softIrqTime;
    ulonglong stealTime;
    ulonglong guestTime;
    ulonglong totalPeriod;
    ulonglong userPeriod;
    ulonglong systemPeriod;
    ulonglong systemAllPeriod;
    ulonglong idleAllPeriod;
    ulonglong idlePeriod;
    ulonglong nicePeriod;
    ulonglong ioWaitPeriod;
    ulonglong irqPeriod;
    ulonglong softIrqPeriod;
    ulonglong stealPeriod;
    ulonglong guestPeriod;
    double frequency;
    double temperature;
    _Bool online;
    byte field_0xd1;
    byte field_0xd2;
    byte field_0xd3;
    byte field_0xd4;
    byte field_0xd5;
    byte field_0xd6;
    byte field_0xd7;
};

typedef struct LinuxMachine_ LinuxMachine;

typedef struct LinuxMachine__2 LinuxMachine__2, *PLinuxMachine__2;

typedef struct LinuxMachine__2 LinuxMachine_2;

struct LinuxMachine__2 {
    Machine_2 super;
    long jiffies;
    wchar_t pageSize;
    wchar_t pageSizeKB;
    uint runningTasks;
    byte field_0xcc;
    byte field_0xcd;
    byte field_0xce;
    byte field_0xcf;
    longlong boottime;
    double period;
    CPUData *cpuData;
    memory_t totalHugePageMem;
    memory_t usedHugePageMem[24];
    memory_t availableMem;
    ZfsArcStats zfs;
    ZramStats zram;
    ZswapStats zswap;
};

typedef struct DynamicMeter_ DynamicMeter_, *PDynamicMeter_;

struct DynamicMeter_ {
    char name[32];
    char *caption;
    char *description;
    uint type;
    byte field_0x34;
    byte field_0x35;
    byte field_0x36;
    byte field_0x37;
    double maximum;
};

typedef struct DynamicMeter_ DynamicMeter;

typedef __gnuc_va_list va_list;

typedef struct LibraryData_ LibraryData_, *PLibraryData_;

typedef struct LibraryData_ LibraryData;

struct LibraryData_ {
    uint64_t size;
    _Bool exec;
    byte field_0x9;
    byte field_0xa;
    byte field_0xb;
    byte field_0xc;
    byte field_0xd;
    byte field_0xe;
    byte field_0xf;
};

typedef struct ColumnsPanel_ ColumnsPanel_, *PColumnsPanel_;

typedef struct ColumnsPanel_ ColumnsPanel;

struct ColumnsPanel_ {
    Panel super;
    ScreenSettings_3 *ss;
    _Bool *changed;
    _Bool moving;
    byte field_0x26f1;
    byte field_0x26f2;
    byte field_0x26f3;
    byte field_0x26f4;
    byte field_0x26f5;
    byte field_0x26f6;
    byte field_0x26f7;
};

typedef struct EnvScreen_ EnvScreen_, *PEnvScreen_;

typedef struct EnvScreen_ EnvScreen;

typedef struct InfoScreen_ InfoScreen_, *PInfoScreen_;

typedef struct InfoScreen_ InfoScreen;

typedef struct Process_ Process_, *PProcess_;

typedef struct Process_ Process;

typedef struct Row_ Row_, *PRow_;

typedef struct Row_ Row;

struct Row_ {
    Object super;
    struct Machine_ *host;
    wchar_t id;
    wchar_t group;
    wchar_t parent;
    _Bool isRoot;
    _Bool tag;
    _Bool show;
    _Bool wasShown;
    _Bool showChildren;
    _Bool updated;
    byte field_0x22;
    byte field_0x23;
    int32_t indent;
    uint tree_depth;
    byte field_0x2c;
    byte field_0x2d;
    byte field_0x2e;
    byte field_0x2f;
    uint64_t seenStampMs;
    uint64_t tombStampMs;
};

struct Process_ {
    Row super;
    wchar_t pgrp;
    wchar_t session;
    wchar_t tpgid;
    _Bool isKernelThread;
    _Bool isUserlandThread;
    _Bool isRunningInContainer;
    byte field_0x4f;
    ulong tty_nr;
    char *tty_name;
    uid_t st_uid;
    byte field_0x64;
    byte field_0x65;
    byte field_0x66;
    byte field_0x67;
    char *user;
    _Bool elevated_priv;
    byte field_0x71;
    byte field_0x72;
    byte field_0x73;
    byte field_0x74;
    byte field_0x75;
    byte field_0x76;
    byte field_0x77;
    ulonglong time;
    char *cmdline;
    wchar_t cmdlineBasenameEnd;
    wchar_t cmdlineBasenameStart;
    char *procComm;
    char *procExe;
    char *procCwd;
    wchar_t procExeBasenameOffset;
    _Bool procExeDeleted;
    _Bool usesDeletedLib;
    byte field_0xae;
    byte field_0xaf;
    wchar_t processor;
    float percent_cpu;
    float percent_mem;
    byte field_0xbc;
    byte field_0xbd;
    byte field_0xbe;
    byte field_0xbf;
    long priority;
    long nice;
    long nlwp;
    time_t starttime_ctime;
    char starttime_show[8];
    long m_virt;
    long m_resident;
    ulong minflt;
    ulong majflt;
    ProcessState state;
    wchar_t scheduling_policy;
    ProcessMergedCommand mergedCommand;
};

struct InfoScreen_ {
    Object super;
    Process *process;
    Panel *display;
    IncSet *inc;
    Vector *lines;
};

struct EnvScreen_ {
    InfoScreen super;
};

typedef struct ProcessLocksScreen_ ProcessLocksScreen_, *PProcessLocksScreen_;

typedef struct ProcessLocksScreen_ ProcessLocksScreen;

struct ProcessLocksScreen_ {
    InfoScreen super;
    pid_t pid;
    byte field_0x2c;
    byte field_0x2d;
    byte field_0x2e;
    byte field_0x2f;
};

typedef struct FileLocks_ProcessData_ FileLocks_ProcessData_, *PFileLocks_ProcessData_;

typedef struct FileLocks_LockData_ FileLocks_LockData_, *PFileLocks_LockData_;

typedef struct FileLocks_Data_ FileLocks_Data_, *PFileLocks_Data_;

typedef struct FileLocks_Data_ FileLocks_Data;

struct FileLocks_ProcessData_ {
    _Bool error;
    byte field_0x1;
    byte field_0x2;
    byte field_0x3;
    byte field_0x4;
    byte field_0x5;
    byte field_0x6;
    byte field_0x7;
    struct FileLocks_LockData_ *locks;
};

struct FileLocks_Data_ {
    char *locktype;
    char *exclusive;
    char *readwrite;
    char *filename;
    wchar_t fd;
    byte field_0x24;
    byte field_0x25;
    byte field_0x26;
    byte field_0x27;
    dev_t dev;
    uint64_t inode;
    uint64_t start;
    uint64_t end;
};

struct FileLocks_LockData_ {
    FileLocks_Data data;
    struct FileLocks_LockData_ *next;
};

typedef struct FileLocks_LockData_ FileLocks_LockData;

typedef struct FileLocks_ProcessData_ FileLocks_ProcessData;

typedef struct TtyDriver_ TtyDriver_, *PTtyDriver_;

typedef struct TtyDriver_ TtyDriver;

struct TtyDriver_ {
    char *path;
    uint major;
    uint minorFrom;
    uint minorTo;
    byte field_0x14;
    byte field_0x15;
    byte field_0x16;
    byte field_0x17;
};

typedef struct LinuxProcessTable_ LinuxProcessTable_, *PLinuxProcessTable_;

typedef struct ProcessTable__2 ProcessTable__2, *PProcessTable__2;

typedef struct ProcessTable__2 ProcessTable_2;

typedef struct nl_sock nl_sock, *Pnl_sock;

struct nl_sock {
};

struct ProcessTable__2 {
    Table_2 super;
    Hashtable_2 *pidMatchList;
    uint totalTasks;
    uint runningTasks;
    uint userlandThreads;
    uint kernelThreads;
};

struct LinuxProcessTable_ {
    ProcessTable_2 super;
    TtyDriver *ttyDrivers;
    _Bool haveSmapsRollup;
    _Bool haveAutogroup;
    byte field_0x62;
    byte field_0x63;
    byte field_0x64;
    byte field_0x65;
    byte field_0x66;
    byte field_0x67;
    struct nl_sock *netlink_socket;
    wchar_t netlink_family;
    byte field_0x74;
    byte field_0x75;
    byte field_0x76;
    byte field_0x77;
};

typedef struct LinuxProcessTable_ LinuxProcessTable;

typedef struct ProcessTable_ ProcessTable_, *PProcessTable_;

struct ProcessTable_ {
    Table_4 super;
    Hashtable_2 *pidMatchList;
    uint totalTasks;
    uint runningTasks;
    uint userlandThreads;
    uint kernelThreads;
};

typedef struct ProcessTable_ ProcessTable;

typedef struct DiskIOData_ DiskIOData_, *PDiskIOData_;

typedef struct DiskIOData_ DiskIOData;

struct DiskIOData_ {
    uint64_t totalBytesRead;
    uint64_t totalBytesWritten;
    uint64_t totalMsTimeSpend;
};

typedef struct PanelClass_ PanelClass_, *PPanelClass_;

typedef struct PanelClass_ PanelClass;

typedef enum HandlerResult_ {
    HANDLED=1,
    IGNORED=2,
    BREAK_LOOP=4,
    REFRESH=8,
    REDRAW=16,
    RESCAN=32,
    RESIZE=64,
    SYNTH_KEY=128
} HandlerResult_;

typedef enum HandlerResult_ HandlerResult;

typedef HandlerResult (*Panel_EventHandler)(Panel *, wchar_t);

typedef void (*Panel_DrawFunctionBar)(Panel *, _Bool);

typedef void (*Panel_PrintHeader)(Panel *);

struct PanelClass_ {
    ObjectClass super;
    Panel_EventHandler eventHandler;
    Panel_DrawFunctionBar drawFunctionBar;
    Panel_PrintHeader printHeader;
};

typedef void (*Panel_PrintHeader_2)(Panel *);

typedef struct PanelClass__2 PanelClass__2, *PPanelClass__2;

typedef HandlerResult (*Panel_EventHandler_2)(Panel *, wchar_t);

typedef void (*Panel_DrawFunctionBar_2)(Panel *, _Bool);

struct PanelClass__2 {
    ObjectClass super;
    Panel_EventHandler_2 eventHandler;
    Panel_DrawFunctionBar_2 drawFunctionBar;
    Panel_PrintHeader_2 printHeader;
};

typedef struct PanelClass__2 PanelClass_2;

typedef struct PanelClass__3 PanelClass__3, *PPanelClass__3;

typedef HandlerResult (*Panel_EventHandler_3)(Panel *, wchar_t);

typedef void (*Panel_DrawFunctionBar_3)(Panel *, _Bool);

typedef void (*Panel_PrintHeader_3)(Panel *);

struct PanelClass__3 {
    ObjectClass super;
    Panel_EventHandler_3 eventHandler;
    Panel_DrawFunctionBar_3 drawFunctionBar;
    Panel_PrintHeader_3 printHeader;
};

typedef struct PanelClass__3 PanelClass_3;

typedef enum IncType.conflict {
    INC_SEARCH=0,
    INC_FILTER=1
} IncType.conflict;

typedef char * (*IncMode_GetPanelValue)(Panel *, wchar_t);

typedef enum anon_enum_32 IncType;

typedef struct IncSet__3 IncSet__3, *PIncSet__3;

typedef struct IncSet__3 IncSet_3;

struct IncSet__3 {
    IncMode modes[2];
    IncMode *active;
    Panel *panel;
    FunctionBar *defaultBar;
    _Bool filtering;
    _Bool found;
    byte field_0x14a;
    byte field_0x14b;
    byte field_0x14c;
    byte field_0x14d;
    byte field_0x14e;
    byte field_0x14f;
};

typedef char * (*IncMode_GetPanelValue_2)(Panel *, wchar_t);

typedef struct DynamicIterator.conflict DynamicIterator.conflict, *PDynamicIterator.conflict;

typedef struct DynamicColumn__2 DynamicColumn__2, *PDynamicColumn__2;

typedef struct DynamicColumn__2 DynamicColumn_2;

struct DynamicIterator.conflict {
    char *name;
    DynamicColumn_2 *data;
    uint key;
    byte field_0x14;
    byte field_0x15;
    byte field_0x16;
    byte field_0x17;
};

struct DynamicColumn__2 {
    char name[32];
    char *heading;
    char *caption;
    char *description;
    wchar_t width;
    _Bool enabled;
    byte field_0x3d;
    byte field_0x3e;
    byte field_0x3f;
    Table_2 *table;
};

typedef struct _IO_FILE _IO_FILE, *P_IO_FILE;

typedef struct _IO_codecvt _IO_codecvt, *P_IO_codecvt;

typedef struct _IO_wide_data _IO_wide_data, *P_IO_wide_data;

struct _IO_wide_data {
};

struct _IO_FILE {
    wchar_t _flags;
    byte field_0x4;
    byte field_0x5;
    byte field_0x6;
    byte field_0x7;
    char *_IO_read_ptr;
    char *_IO_read_end;
    char *_IO_read_base;
    char *_IO_write_base;
    char *_IO_write_ptr;
    char *_IO_write_end;
    char *_IO_buf_base;
    char *_IO_buf_end;
    char *_IO_save_base;
    char *_IO_backup_base;
    char *_IO_save_end;
    struct _IO_marker *_markers;
    struct _IO_FILE *_chain;
    wchar_t _fileno;
    wchar_t _flags2;
    __off_t _old_offset;
    ushort _cur_column;
    char _vtable_offset;
    char _shortbuf[1];
    byte field_0x84;
    byte field_0x85;
    byte field_0x86;
    byte field_0x87;
    _IO_lock_t *_lock;
    __off64_t _offset;
    struct _IO_codecvt *_codecvt;
    struct _IO_wide_data *_wide_data;
    struct _IO_FILE *_freeres_list;
    void *_freeres_buf;
    size_t __pad5;
    wchar_t _mode;
    char _unused2[20];
};

struct _IO_codecvt {
};

typedef struct DynamicColumn_ DynamicColumn_, *PDynamicColumn_;

struct DynamicColumn_ {
    char name[32];
    char *heading;
    char *caption;
    char *description;
    wchar_t width;
    _Bool enabled;
    byte field_0x3d;
    byte field_0x3e;
    byte field_0x3f;
    Table *table;
};

typedef struct DynamicColumn_ DynamicColumn;

typedef __uint16_t uint16_t;

typedef struct DynamicIterator.conflict1 DynamicIterator.conflict1, *PDynamicIterator.conflict1;

struct DynamicIterator.conflict1 {
    uint key;
    byte field_0x4;
    byte field_0x5;
    byte field_0x6;
    byte field_0x7;
    char *name;
    _Bool found;
    byte field_0x11;
    byte field_0x12;
    byte field_0x13;
    byte field_0x14;
    byte field_0x15;
    byte field_0x16;
    byte field_0x17;
};

typedef struct stat stat, *Pstat;

typedef struct timespec timespec, *Ptimespec;

struct timespec {
    __time_t tv_sec;
    __syscall_slong_t tv_nsec;
};

struct stat {
    __dev_t st_dev;
    __ino_t st_ino;
    __nlink_t st_nlink;
    __mode_t st_mode;
    __uid_t st_uid;
    __gid_t st_gid;
    wchar_t __pad0;
    __dev_t st_rdev;
    __off_t st_size;
    __blksize_t st_blksize;
    __blkcnt_t st_blocks;
    struct timespec st_atim;
    struct timespec st_mtim;
    struct timespec st_ctim;
    __syscall_slong_t __glibc_reserved[3];
};

typedef struct InfoScreen__2 InfoScreen__2, *PInfoScreen__2;

typedef struct InfoScreen__2 InfoScreen_2;

typedef void (*InfoScreen_Scan)(InfoScreen_2 *);

struct InfoScreen__2 {
    Object super;
    Process *process;
    Panel *display;
    IncSet_3 *inc;
    Vector *lines;
};

typedef void (*InfoScreen_Draw)(InfoScreen_2 *);

typedef _Bool (*InfoScreen_OnKey)(InfoScreen_2 *, wchar_t);

typedef struct InfoScreenClass_ InfoScreenClass_, *PInfoScreenClass_;

typedef void (*InfoScreen_OnErr)(InfoScreen_2 *);

struct InfoScreenClass_ {
    ObjectClass super;
    InfoScreen_Scan scan;
    InfoScreen_Draw draw;
    InfoScreen_OnErr onErr;
    InfoScreen_OnKey onKey;
};

typedef struct InfoScreenClass_ InfoScreenClass;

typedef void (*InfoScreen_OnErr_2)(InfoScreen_2 *);

typedef void (*InfoScreen_Scan_2)(InfoScreen_2 *);

typedef struct InfoScreen__3 InfoScreen__3, *PInfoScreen__3;

typedef struct InfoScreen__3 InfoScreen_3;

typedef struct Process__2 Process__2, *PProcess__2;

typedef struct Process__2 Process_2;

typedef struct Row__2 Row__2, *PRow__2;

typedef struct Row__2 Row_2;

struct InfoScreen__3 {
    Object super;
    Process_2 *process;
    Panel *display;
    IncSet_2 *inc;
    Vector *lines;
};

struct Row__2 {
    Object super;
    struct Machine__2 *host;
    wchar_t id;
    wchar_t group;
    wchar_t parent;
    _Bool isRoot;
    _Bool tag;
    _Bool show;
    _Bool wasShown;
    _Bool showChildren;
    _Bool updated;
    byte field_0x22;
    byte field_0x23;
    int32_t indent;
    uint tree_depth;
    byte field_0x2c;
    byte field_0x2d;
    byte field_0x2e;
    byte field_0x2f;
    uint64_t seenStampMs;
    uint64_t tombStampMs;
};

struct Process__2 {
    Row_2 super;
    wchar_t pgrp;
    wchar_t session;
    wchar_t tpgid;
    _Bool isKernelThread;
    _Bool isUserlandThread;
    _Bool isRunningInContainer;
    byte field_0x4f;
    ulong tty_nr;
    char *tty_name;
    uid_t st_uid;
    byte field_0x64;
    byte field_0x65;
    byte field_0x66;
    byte field_0x67;
    char *user;
    _Bool elevated_priv;
    byte field_0x71;
    byte field_0x72;
    byte field_0x73;
    byte field_0x74;
    byte field_0x75;
    byte field_0x76;
    byte field_0x77;
    ulonglong time;
    char *cmdline;
    wchar_t cmdlineBasenameEnd;
    wchar_t cmdlineBasenameStart;
    char *procComm;
    char *procExe;
    char *procCwd;
    wchar_t procExeBasenameOffset;
    _Bool procExeDeleted;
    _Bool usesDeletedLib;
    byte field_0xae;
    byte field_0xaf;
    wchar_t processor;
    float percent_cpu;
    float percent_mem;
    byte field_0xbc;
    byte field_0xbd;
    byte field_0xbe;
    byte field_0xbf;
    long priority;
    long nice;
    long nlwp;
    time_t starttime_ctime;
    char starttime_show[8];
    long m_virt;
    long m_resident;
    ulong minflt;
    ulong majflt;
    ProcessState state;
    wchar_t scheduling_policy;
    ProcessMergedCommand mergedCommand;
};

typedef struct InfoScreenClass__2 InfoScreenClass__2, *PInfoScreenClass__2;

typedef void (*InfoScreen_Draw_2)(InfoScreen_2 *);

typedef _Bool (*InfoScreen_OnKey_2)(InfoScreen_2 *, wchar_t);

struct InfoScreenClass__2 {
    ObjectClass super;
    InfoScreen_Scan_2 scan;
    InfoScreen_Draw_2 draw;
    InfoScreen_OnErr_2 onErr;
    InfoScreen_OnKey_2 onKey;
};

typedef struct InfoScreenClass__2 InfoScreenClass_2;

typedef struct anon_struct_24_4_85c7b288 anon_struct_24_4_85c7b288, *Panon_struct_24_4_85c7b288;

struct anon_struct_24_4_85c7b288 {
    uint8_t columns;
    uint8_t widths[4];
    byte field_0x5;
    byte field_0x6;
    byte field_0x7;
    char *name;
    char *description;
};

typedef struct AvailableMetersPanel_ AvailableMetersPanel_, *PAvailableMetersPanel_;

typedef struct AvailableMetersPanel_ AvailableMetersPanel;

struct AvailableMetersPanel_ {
    Panel super;
    ScreenManager_2 *scr;
    Machine_4 *host;
    Header_3 *header;
    size_t columns;
    MetersPanel **meterPanels;
};

typedef void (*Table_ScanCleanup)(Table_2 *);

typedef void (*Table_ScanPrepare)(Table_2 *);

typedef struct TableClass_ TableClass_, *PTableClass_;

typedef void (*Table_ScanIterate)(Table_2 *);

struct TableClass_ {
    ObjectClass super;
    Table_ScanPrepare prepare;
    Table_ScanIterate iterate;
    Table_ScanCleanup cleanup;
};

typedef struct TableClass_ TableClass;

typedef struct Affinity_ Affinity_, *PAffinity_;

typedef struct Affinity_ Affinity;

struct Affinity_ {
    Machine_2 *host;
    uint size;
    uint used;
    uint *cpus;
};

typedef struct Affinity__2 Affinity__2, *PAffinity__2;

typedef struct Affinity__2 Affinity_2;

struct Affinity__2 {
    Machine *host;
    uint size;
    uint used;
    uint *cpus;
};

typedef struct MEVENT MEVENT, *PMEVENT;

struct MEVENT {
    short id;
    byte field_0x2;
    byte field_0x3;
    wchar_t x;
    wchar_t y;
    wchar_t z;
    mmask_t bstate;
};

typedef struct _win_st _win_st, *P_win_st;

typedef struct _win_st WINDOW;

struct _win_st {
};

typedef struct utsname utsname, *Putsname;

struct utsname {
    char sysname[65];
    char nodename[65];
    char release[65];
    char version[65];
    char machine[65];
    char domainname[65];
};

typedef wchar_t (*Row_CompareByParent)(Row_3 *, Row_3 *);

typedef _Bool (*Row_MatchesFilter)(Row_3 *, struct Table__5 *);

typedef _Bool (*Row_IsVisible)(Row_3 *, struct Table__5 *);

typedef struct RowClass_ RowClass_, *PRowClass_;

typedef struct RowClass_ RowClass;

typedef _Bool (*Row_IsHighlighted)(Row_3 *);

typedef void (*Row_WriteField)(Row_3 *, RichString *, RowField);

typedef char * (*Row_SortKeyString)(Row_3 *);

struct RowClass_ {
    ObjectClass super;
    Row_IsHighlighted isHighlighted;
    Row_IsVisible isVisible;
    Row_WriteField writeField;
    Row_MatchesFilter matchesFilter;
    Row_SortKeyString sortKeyString;
    Row_CompareByParent compareByParent;
};

typedef _Bool (*Row_IsHighlighted_2)(Row_3 *);

typedef _Bool (*Row_IsVisible_2)(Row_3 *, struct Table__5 *);

typedef void (*Row_WriteField_2)(Row_3 *, RichString *, RowField);

typedef wchar_t (*Row_CompareByParent_2)(Row_3 *, Row_3 *);

typedef struct RowClass__2 RowClass__2, *PRowClass__2;

typedef struct RowClass__2 RowClass_2;

typedef _Bool (*Row_MatchesFilter_2)(Row_3 *, struct Table__5 *);

typedef char * (*Row_SortKeyString_2)(Row_3 *);

struct RowClass__2 {
    ObjectClass super;
    Row_IsHighlighted_2 isHighlighted;
    Row_IsVisible_2 isVisible;
    Row_WriteField_2 writeField;
    Row_MatchesFilter_2 matchesFilter;
    Row_SortKeyString_2 sortKeyString;
    Row_CompareByParent_2 compareByParent;
};

typedef struct nlattr nlattr, *Pnlattr;

struct nlattr {
    __u16 nla_len;
    __u16 nla_type;
};

typedef struct nlmsghdr nlmsghdr, *Pnlmsghdr;

struct nlmsghdr {
    __u32 nlmsg_len;
    __u16 nlmsg_type;
    __u16 nlmsg_flags;
    __u32 nlmsg_seq;
    __u32 nlmsg_pid;
};

typedef struct taskstats taskstats, *Ptaskstats;

struct taskstats {
    __u16 version;
    byte field_0x2;
    byte field_0x3;
    __u32 ac_exitcode;
    __u8 ac_flag;
    __u8 ac_nice;
    byte field_0xa;
    byte field_0xb;
    byte field_0xc;
    byte field_0xd;
    byte field_0xe;
    byte field_0xf;
    __u64 cpu_count;
    __u64 cpu_delay_total;
    __u64 blkio_count;
    __u64 blkio_delay_total;
    __u64 swapin_count;
    __u64 swapin_delay_total;
    __u64 cpu_run_real_total;
    __u64 cpu_run_virtual_total;
    char ac_comm[32];
    __u8 ac_sched;
    __u8 ac_pad[3];
    byte field_0x74;
    byte field_0x75;
    byte field_0x76;
    byte field_0x77;
    __u32 ac_uid;
    __u32 ac_gid;
    __u32 ac_pid;
    __u32 ac_ppid;
    __u32 ac_btime;
    byte field_0x8c;
    byte field_0x8d;
    byte field_0x8e;
    byte field_0x8f;
    __u64 ac_etime;
    __u64 ac_utime;
    __u64 ac_stime;
    __u64 ac_minflt;
    __u64 ac_majflt;
    __u64 coremem;
    __u64 virtmem;
    __u64 hiwater_rss;
    __u64 hiwater_vm;
    __u64 read_char;
    __u64 write_char;
    __u64 read_syscalls;
    __u64 write_syscalls;
    __u64 read_bytes;
    __u64 write_bytes;
    __u64 cancelled_write_bytes;
    __u64 nvcsw;
    __u64 nivcsw;
    __u64 ac_utimescaled;
    __u64 ac_stimescaled;
    __u64 cpu_scaled_run_real_total;
    __u64 freepages_count;
    __u64 freepages_delay_total;
    __u64 thrashing_count;
    __u64 thrashing_delay_total;
    __u64 ac_btime64;
    __u64 compact_count;
    __u64 compact_delay_total;
    __u32 ac_tgid;
    byte field_0x174;
    byte field_0x175;
    byte field_0x176;
    byte field_0x177;
    __u64 ac_tgetime;
    __u64 ac_exe_dev;
    __u64 ac_exe_inode;
    __u64 wpcopy_count;
    __u64 wpcopy_delay_total;
    __u64 irq_count;
    __u64 irq_delay_total;
};

typedef struct statvfs statvfs, *Pstatvfs;

struct statvfs {
    ulong f_bsize;
    ulong f_frsize;
    __fsblkcnt_t f_blocks;
    __fsblkcnt_t f_bfree;
    __fsblkcnt_t f_bavail;
    __fsfilcnt_t f_files;
    __fsfilcnt_t f_ffree;
    __fsfilcnt_t f_favail;
    ulong f_fsid;
    ulong f_flag;
    ulong f_namemax;
    uint f_type;
    wchar_t __f_spare[5];
};

typedef struct DynamicIterator DynamicIterator, *PDynamicIterator;

struct DynamicIterator {
    Panel *super;
    uint id;
    uint offset;
};

typedef struct tm tm, *Ptm;

struct tm {
    wchar_t tm_sec;
    wchar_t tm_min;
    wchar_t tm_hour;
    wchar_t tm_mday;
    wchar_t tm_mon;
    wchar_t tm_year;
    wchar_t tm_wday;
    wchar_t tm_yday;
    wchar_t tm_isdst;
    byte field_0x24;
    byte field_0x25;
    byte field_0x26;
    byte field_0x27;
    long tm_gmtoff;
    char *tm_zone;
};

typedef struct Hashtable_ Hashtable;

typedef void (*Hashtable_PairFunction)(ht_key_t, void *, void *);

typedef struct passwd passwd, *Ppasswd;

struct passwd {
    char *pw_name;
    char *pw_passwd;
    __uid_t pw_uid;
    __gid_t pw_gid;
    char *pw_gecos;
    char *pw_dir;
    char *pw_shell;
};

typedef enum ACPresence_ {
    AC_ABSENT=0,
    AC_PRESENT=1,
    AC_ERROR=2
} ACPresence_;

typedef enum ACPresence_ ACPresence;

typedef enum ReservedFields_ {
    NULL_FIELD=0,
    PID=1,
    COMM=2,
    STATE=3,
    PPID=4,
    PGRP=5,
    SESSION=6,
    TTY=7,
    TPGID=8,
    MINFLT=10,
    CMINFLT=11,
    MAJFLT=12,
    CMAJFLT=13,
    UTIME=14,
    STIME=15,
    CUTIME=16,
    CSTIME=17,
    PRIORITY=18,
    NICE=19,
    STARTTIME=21,
    PROCESSOR=38,
    M_VIRT=39,
    M_RESIDENT=40,
    M_SHARE=41,
    M_TRS=42,
    M_DRS=43,
    M_LRS=44,
    ST_UID=46,
    PERCENT_CPU=47,
    PERCENT_MEM=48,
    USER=49,
    TIME=50,
    NLWP=51,
    TGID=52,
    PERCENT_NORM_CPU=53,
    ELAPSED=54,
    SCHEDULERPOLICY=55,
    CTID=100,
    VPID=101,
    VXID=102,
    RCHAR=103,
    WCHAR=104,
    SYSCR=105,
    SYSCW=106,
    RBYTES=107,
    WBYTES=108,
    CNCLWB=109,
    IO_READ_RATE=110,
    IO_WRITE_RATE=111,
    IO_RATE=112,
    CGROUP=113,
    OOM=114,
    IO_PRIORITY=115,
    PERCENT_CPU_DELAY=116,
    PERCENT_IO_DELAY=117,
    PERCENT_SWAP_DELAY=118,
    M_PSS=119,
    M_SWAP=120,
    M_PSSWP=121,
    CTXT=122,
    SECATTR=123,
    PROC_COMM=124,
    PROC_EXE=125,
    CWD=126,
    AUTOGROUP_ID=127,
    AUTOGROUP_NICE=128,
    CCGROUP=129,
    CONTAINER=130,
    M_PRIV=131,
    LAST_RESERVED_FIELD=132
} ReservedFields_;

typedef __clockid_t clockid_t;

typedef struct nl_msg nl_msg, *Pnl_msg;

struct nl_msg {
};

typedef struct sensors_chip_name sensors_chip_name, *Psensors_chip_name;

typedef struct sensors_bus_id sensors_bus_id, *Psensors_bus_id;

struct sensors_bus_id {
    short type;
    short nr;
};

struct sensors_chip_name {
    char *prefix;
    struct sensors_bus_id bus;
    wchar_t addr;
    char *path;
};

typedef struct sensors_feature sensors_feature, *Psensors_feature;

typedef enum sensors_feature_type {
    SENSORS_FEATURE_IN=0,
    SENSORS_FEATURE_FAN=1,
    SENSORS_FEATURE_TEMP=2,
    SENSORS_FEATURE_POWER=3,
    SENSORS_FEATURE_ENERGY=4,
    SENSORS_FEATURE_CURR=5,
    SENSORS_FEATURE_HUMIDITY=6,
    SENSORS_FEATURE_MAX_MAIN=7,
    SENSORS_FEATURE_VID=16,
    SENSORS_FEATURE_INTRUSION=17,
    SENSORS_FEATURE_MAX_OTHER=18,
    SENSORS_FEATURE_BEEP_ENABLE=24,
    SENSORS_FEATURE_MAX=25,
    SENSORS_FEATURE_UNKNOWN=2147483647
} sensors_feature_type;

struct sensors_feature {
    char *name;
    wchar_t number;
    enum sensors_feature_type type;
    wchar_t first_subfeature;
    wchar_t padding1;
};

typedef struct sensors_subfeature sensors_subfeature, *Psensors_subfeature;

typedef enum sensors_subfeature_type {
    SENSORS_SUBFEATURE_IN_INPUT=0,
    SENSORS_SUBFEATURE_IN_MIN=1,
    SENSORS_SUBFEATURE_IN_MAX=2,
    SENSORS_SUBFEATURE_IN_LCRIT=3,
    SENSORS_SUBFEATURE_IN_CRIT=4,
    SENSORS_SUBFEATURE_IN_AVERAGE=5,
    SENSORS_SUBFEATURE_IN_LOWEST=6,
    SENSORS_SUBFEATURE_IN_HIGHEST=7,
    SENSORS_SUBFEATURE_IN_ALARM=128,
    SENSORS_SUBFEATURE_IN_MIN_ALARM=129,
    SENSORS_SUBFEATURE_IN_MAX_ALARM=130,
    SENSORS_SUBFEATURE_IN_BEEP=131,
    SENSORS_SUBFEATURE_IN_LCRIT_ALARM=132,
    SENSORS_SUBFEATURE_IN_CRIT_ALARM=133,
    SENSORS_SUBFEATURE_FAN_INPUT=256,
    SENSORS_SUBFEATURE_FAN_MIN=257,
    SENSORS_SUBFEATURE_FAN_MAX=258,
    SENSORS_SUBFEATURE_FAN_ALARM=384,
    SENSORS_SUBFEATURE_FAN_FAULT=385,
    SENSORS_SUBFEATURE_FAN_DIV=386,
    SENSORS_SUBFEATURE_FAN_BEEP=387,
    SENSORS_SUBFEATURE_FAN_PULSES=388,
    SENSORS_SUBFEATURE_FAN_MIN_ALARM=389,
    SENSORS_SUBFEATURE_FAN_MAX_ALARM=390,
    SENSORS_SUBFEATURE_TEMP_INPUT=512,
    SENSORS_SUBFEATURE_TEMP_MAX=513,
    SENSORS_SUBFEATURE_TEMP_MAX_HYST=514,
    SENSORS_SUBFEATURE_TEMP_MIN=515,
    SENSORS_SUBFEATURE_TEMP_CRIT=516,
    SENSORS_SUBFEATURE_TEMP_CRIT_HYST=517,
    SENSORS_SUBFEATURE_TEMP_LCRIT=518,
    SENSORS_SUBFEATURE_TEMP_EMERGENCY=519,
    SENSORS_SUBFEATURE_TEMP_EMERGENCY_HYST=520,
    SENSORS_SUBFEATURE_TEMP_LOWEST=521,
    SENSORS_SUBFEATURE_TEMP_HIGHEST=522,
    SENSORS_SUBFEATURE_TEMP_MIN_HYST=523,
    SENSORS_SUBFEATURE_TEMP_LCRIT_HYST=524,
    SENSORS_SUBFEATURE_TEMP_ALARM=640,
    SENSORS_SUBFEATURE_TEMP_MAX_ALARM=641,
    SENSORS_SUBFEATURE_TEMP_MIN_ALARM=642,
    SENSORS_SUBFEATURE_TEMP_CRIT_ALARM=643,
    SENSORS_SUBFEATURE_TEMP_FAULT=644,
    SENSORS_SUBFEATURE_TEMP_TYPE=645,
    SENSORS_SUBFEATURE_TEMP_OFFSET=646,
    SENSORS_SUBFEATURE_TEMP_BEEP=647,
    SENSORS_SUBFEATURE_TEMP_EMERGENCY_ALARM=648,
    SENSORS_SUBFEATURE_TEMP_LCRIT_ALARM=649,
    SENSORS_SUBFEATURE_POWER_AVERAGE=768,
    SENSORS_SUBFEATURE_POWER_AVERAGE_HIGHEST=769,
    SENSORS_SUBFEATURE_POWER_AVERAGE_LOWEST=770,
    SENSORS_SUBFEATURE_POWER_INPUT=771,
    SENSORS_SUBFEATURE_POWER_INPUT_HIGHEST=772,
    SENSORS_SUBFEATURE_POWER_INPUT_LOWEST=773,
    SENSORS_SUBFEATURE_POWER_CAP=774,
    SENSORS_SUBFEATURE_POWER_CAP_HYST=775,
    SENSORS_SUBFEATURE_POWER_MAX=776,
    SENSORS_SUBFEATURE_POWER_CRIT=777,
    SENSORS_SUBFEATURE_POWER_MIN=778,
    SENSORS_SUBFEATURE_POWER_LCRIT=779,
    SENSORS_SUBFEATURE_POWER_AVERAGE_INTERVAL=896,
    SENSORS_SUBFEATURE_POWER_ALARM=897,
    SENSORS_SUBFEATURE_POWER_CAP_ALARM=898,
    SENSORS_SUBFEATURE_POWER_MAX_ALARM=899,
    SENSORS_SUBFEATURE_POWER_CRIT_ALARM=900,
    SENSORS_SUBFEATURE_POWER_MIN_ALARM=901,
    SENSORS_SUBFEATURE_POWER_LCRIT_ALARM=902,
    SENSORS_SUBFEATURE_ENERGY_INPUT=1024,
    SENSORS_SUBFEATURE_CURR_INPUT=1280,
    SENSORS_SUBFEATURE_CURR_MIN=1281,
    SENSORS_SUBFEATURE_CURR_MAX=1282,
    SENSORS_SUBFEATURE_CURR_LCRIT=1283,
    SENSORS_SUBFEATURE_CURR_CRIT=1284,
    SENSORS_SUBFEATURE_CURR_AVERAGE=1285,
    SENSORS_SUBFEATURE_CURR_LOWEST=1286,
    SENSORS_SUBFEATURE_CURR_HIGHEST=1287,
    SENSORS_SUBFEATURE_CURR_ALARM=1408,
    SENSORS_SUBFEATURE_CURR_MIN_ALARM=1409,
    SENSORS_SUBFEATURE_CURR_MAX_ALARM=1410,
    SENSORS_SUBFEATURE_CURR_BEEP=1411,
    SENSORS_SUBFEATURE_CURR_LCRIT_ALARM=1412,
    SENSORS_SUBFEATURE_CURR_CRIT_ALARM=1413,
    SENSORS_SUBFEATURE_HUMIDITY_INPUT=1536,
    SENSORS_SUBFEATURE_VID=4096,
    SENSORS_SUBFEATURE_INTRUSION_ALARM=4352,
    SENSORS_SUBFEATURE_INTRUSION_BEEP=4353,
    SENSORS_SUBFEATURE_BEEP_ENABLE=6144,
    SENSORS_SUBFEATURE_UNKNOWN=2147483647
} sensors_subfeature_type;

struct sensors_subfeature {
    char *name;
    wchar_t number;
    enum sensors_subfeature_type type;
    wchar_t mapping;
    uint flags;
};

typedef struct DynamicScreen_ DynamicScreen_, *PDynamicScreen_;

struct DynamicScreen_ {
    char name[32];
    char *heading;
    char *caption;
    char *fields;
    char *sortKey;
    char *columnKeys;
    wchar_t direction;
    byte field_0x4c;
    byte field_0x4d;
    byte field_0x4e;
    byte field_0x4f;
};

typedef struct DynamicScreen_ DynamicScreen;

typedef union Arg Arg, *PArg;

union Arg {
    wchar_t i;
    void *v;
};

typedef enum nl_cb_type {
    NL_CB_VALID=0,
    NL_CB_FINISH=1,
    NL_CB_OVERRUN=2,
    NL_CB_SKIPPED=3,
    NL_CB_ACK=4,
    NL_CB_MSG_IN=5,
    NL_CB_MSG_OUT=6,
    NL_CB_INVALID=7,
    NL_CB_SEQ_CHECK=8,
    NL_CB_SEND_ACK=9,
    NL_CB_DUMP_INTR=10,
    __NL_CB_TYPE_MAX=11
} nl_cb_type;

typedef wchar_t (*nl_recvmsg_msg_cb_t)(struct nl_msg *, void *);

typedef enum nl_cb_action {
    NL_OK=0,
    NL_SKIP=1,
    NL_STOP=2
} nl_cb_action;

typedef enum nl_cb_kind {
    NL_CB_DEFAULT=0,
    NL_CB_VERBOSE=1,
    NL_CB_DEBUG=2,
    NL_CB_CUSTOM=3,
    __NL_CB_KIND_MAX=4
} nl_cb_kind;

typedef enum TreeStr_ {
    TREE_STR_VERT=0,
    TREE_STR_RTEE=1,
    TREE_STR_BEND=2,
    TREE_STR_TEND=3,
    TREE_STR_OPEN=4,
    TREE_STR_SHUT=5,
    TREE_STR_ASC=6,
    TREE_STR_DESC=7,
    LAST_TREE_STR=8
} TreeStr_;

typedef enum ColorScheme_ {
    COLORSCHEME_DEFAULT=0,
    COLORSCHEME_MONOCHROME=1,
    COLORSCHEME_BLACKONWHITE=2,
    COLORSCHEME_LIGHTTERMINAL=3,
    COLORSCHEME_MIDNIGHT=4,
    COLORSCHEME_BLACKNIGHT=5,
    COLORSCHEME_BROKENGRAY=6,
    LAST_COLORSCHEME=7
} ColorScheme_;

typedef enum ColorScheme_ ColorScheme;

typedef struct StrBuf_state StrBuf_state, *PStrBuf_state;

typedef _Bool (*StrBuf_putc_t)(struct StrBuf_state *, char);

struct StrBuf_state {
    char *buf;
    size_t size;
    size_t pos;
};

typedef enum OptionItemType {
    OPTION_ITEM_TEXT=0,
    OPTION_ITEM_CHECK=1,
    OPTION_ITEM_NUMBER=2
} OptionItemType;

typedef struct OptionItemClass_ OptionItemClass_, *POptionItemClass_;

typedef struct OptionItemClass_ OptionItemClass;

struct OptionItemClass_ {
    ObjectClass super;
    enum OptionItemType kind;
    byte field_0x24;
    byte field_0x25;
    byte field_0x26;
    byte field_0x27;
};

typedef struct OptionItem_ OptionItem_, *POptionItem_;

struct OptionItem_ {
    Object super;
    char *text;
};

typedef struct CheckItem_ CheckItem_, *PCheckItem_;

typedef struct OptionItem_ OptionItem;

struct CheckItem_ {
    OptionItem super;
    _Bool *ref;
    _Bool value;
    byte field_0x19;
    byte field_0x1a;
    byte field_0x1b;
    byte field_0x1c;
    byte field_0x1d;
    byte field_0x1e;
    byte field_0x1f;
};

typedef struct CheckItem_ CheckItem;

typedef struct NumberItem_ NumberItem_, *PNumberItem_;

typedef struct NumberItem_ NumberItem;

struct NumberItem_ {
    OptionItem super;
    char *text;
    wchar_t *ref;
    wchar_t value;
    wchar_t scale;
    wchar_t min;
    wchar_t max;
};

typedef struct TextItem_ TextItem_, *PTextItem_;

struct TextItem_ {
    OptionItem super;
    char *text;
};

typedef struct TextItem_ TextItem;

typedef struct CommandLineSettings_ CommandLineSettings_, *PCommandLineSettings_;

typedef struct CommandLineSettings_ CommandLineSettings;

struct CommandLineSettings_ {
    Hashtable_2 *pidMatchList;
    char *commFilter;
    uid_t userId;
    wchar_t sortKey;
    wchar_t delay;
    wchar_t iterationsRemaining;
    _Bool useColors;
    _Bool enableMouse;
    _Bool treeView;
    _Bool allowUnicode;
    _Bool highlightChanges;
    byte field_0x25;
    byte field_0x26;
    byte field_0x27;
    wchar_t highlightDelaySecs;
    _Bool readonly;
    byte field_0x2d;
    byte field_0x2e;
    byte field_0x2f;
};

typedef struct nla_policy nla_policy, *Pnla_policy;

struct nla_policy {
    uint16_t type;
    uint16_t minlen;
    uint16_t maxlen;
};

typedef struct ColorsPanel_ ColorsPanel_, *PColorsPanel_;

typedef struct ColorsPanel_ ColorsPanel;

struct ColorsPanel_ {
    Panel super;
    Settings_4 *settings;
};

typedef struct ProcessClass_ ProcessClass_, *PProcessClass_;

typedef int32_t ProcessField;

typedef wchar_t (*Process_CompareByKey)(Process_2 *, Process_2 *, ProcessField);

struct ProcessClass_ {
    RowClass_2 super;
    Process_CompareByKey compareByKey;
};

typedef struct ProcessClass_ ProcessClass;

typedef Process_2 * (*Process_New)(struct Machine__2 *);

typedef struct ProcessFieldData_ ProcessFieldData_, *PProcessFieldData_;

typedef struct ProcessFieldData_ ProcessFieldData;

struct ProcessFieldData_ {
    char *name;
    char *title;
    char *description;
    uint32_t flags;
    _Bool pidColumn;
    _Bool defaultSortDesc;
    _Bool autoWidth;
    byte field_0x1f;
};

typedef struct ProcessClass__2 ProcessClass__2, *PProcessClass__2;

typedef struct ProcessClass__2 ProcessClass_2;

typedef wchar_t (*Process_CompareByKey_2)(Process_2 *, Process_2 *, ProcessField);

struct ProcessClass__2 {
    RowClass super;
    Process_CompareByKey_2 compareByKey;
};

typedef enum CommandLineStatus {
    STATUS_OK=0,
    STATUS_ERROR_EXIT=1,
    STATUS_OK_EXIT=2
} CommandLineStatus;

typedef wchar_t (*__compar_fn_t)(void *, void *);

typedef struct ScreenListItem_ ScreenListItem_, *PScreenListItem_;

typedef struct ListItem_ ListItem_, *PListItem_;

typedef struct ListItem_ ListItem;

struct ListItem_ {
    Object super;
    char *value;
    wchar_t key;
    _Bool moving;
    byte field_0x15;
    byte field_0x16;
    byte field_0x17;
};

struct ScreenListItem_ {
    ListItem super;
    DynamicScreen *ds;
    ScreenSettings_4 *ss;
};

typedef struct ScreensPanel_ ScreensPanel_, *PScreensPanel_;

typedef struct AvailableColumnsPanel_ AvailableColumnsPanel_, *PAvailableColumnsPanel_;

typedef struct AvailableColumnsPanel_ AvailableColumnsPanel;

struct AvailableColumnsPanel_ {
    Panel super;
    Panel *columns;
};

struct ScreensPanel_ {
    Panel super;
    ScreenManager_3 *scr;
    Settings_4 *settings;
    ColumnsPanel *columns;
    AvailableColumnsPanel *availableColumns;
    char buffer[21];
    byte field_0x2715;
    byte field_0x2716;
    byte field_0x2717;
    char *saved;
    wchar_t cursor;
    _Bool moving;
    byte field_0x2725;
    byte field_0x2726;
    byte field_0x2727;
    ListItem *renamingItem;
};

typedef struct ScreenListItem_ ScreenListItem;

typedef struct ScreensPanel_ ScreensPanel;

typedef struct MainPanel_ MainPanel;

typedef _Bool (*MainPanel_foreachRowFn)(Row_3 *, union Arg);

typedef struct MainPanel__2 MainPanel_2;

typedef _Bool (*MainPanel_foreachRowFn_2)(Row_3 *, union Arg);

typedef struct sched_param sched_param, *Psched_param;

struct sched_param {
    wchar_t sched_priority;
};

typedef struct NetworkIOData_ NetworkIOData_, *PNetworkIOData_;

typedef struct NetworkIOData_ NetworkIOData;

struct NetworkIOData_ {
    uint64_t bytesReceived;
    uint64_t packetsReceived;
    uint64_t bytesTransmitted;
    uint64_t packetsTransmitted;
};

typedef struct term term, *Pterm;

typedef struct term TERMINAL;

typedef struct termtype termtype, *Ptermtype;

typedef struct termtype TERMTYPE;

struct termtype {
    char *term_names;
    char *str_table;
    char *Booleans;
    short *Numbers;
    char **Strings;
    char *ext_str_table;
    char **ext_Names;
    ushort num_Booleans;
    ushort num_Numbers;
    ushort num_Strings;
    ushort ext_Booleans;
    ushort ext_Numbers;
    ushort ext_Strings;
    byte field_0x44;
    byte field_0x45;
    byte field_0x46;
    byte field_0x47;
};

struct term {
    TERMTYPE type;
};

typedef struct ScreenTabListItem_ ScreenTabListItem_, *PScreenTabListItem_;

struct ScreenTabListItem_ {
    ListItem super;
    DynamicScreen *ds;
};

typedef struct ScreenTabsPanel_ ScreenTabsPanel_, *PScreenTabsPanel_;

typedef struct ScreenNamesPanel_ ScreenNamesPanel_, *PScreenNamesPanel_;

typedef struct ScreenNamesPanel_ ScreenNamesPanel;

struct ScreenTabsPanel_ {
    Panel super;
    ScreenManager_2 *scr;
    Settings_3 *settings;
    ScreenNamesPanel *names;
    wchar_t cursor;
    byte field_0x26fc;
    byte field_0x26fd;
    byte field_0x26fe;
    byte field_0x26ff;
};

struct ScreenNamesPanel_ {
    Panel super;
    ScreenManager_2 *scr;
    Settings_3 *settings;
    char buffer[21];
    byte field_0x2705;
    byte field_0x2706;
    byte field_0x2707;
    DynamicScreen *ds;
    char *saved;
    wchar_t cursor;
    byte field_0x271c;
    byte field_0x271d;
    byte field_0x271e;
    byte field_0x271f;
    ListItem *renamingItem;
};

typedef struct ScreenTabsPanel_ ScreenTabsPanel;

typedef struct ScreenNameListItem_ ScreenNameListItem_, *PScreenNameListItem_;

struct ScreenNameListItem_ {
    ListItem super;
    ScreenSettings_4 *ss;
};

typedef struct ScreenTabListItem_ ScreenTabListItem;

typedef struct ScreenNameListItem_ ScreenNameListItem;

typedef struct TraceScreen_ TraceScreen_, *PTraceScreen_;

typedef struct _IO_FILE FILE;

struct TraceScreen_ {
    InfoScreen super;
    _Bool tracing;
    byte field_0x29;
    byte field_0x2a;
    byte field_0x2b;
    pid_t child;
    FILE *strace;
    _Bool contLine;
    _Bool follow;
    byte field_0x3a;
    byte field_0x3b;
    byte field_0x3c;
    byte field_0x3d;
    byte field_0x3e;
    byte field_0x3f;
};

typedef struct TraceScreen_ TraceScreen;

typedef struct option option, *Poption;

struct option {
    char *name;
    wchar_t has_arg;
    byte field_0xc;
    byte field_0xd;
    byte field_0xe;
    byte field_0xf;
    wchar_t *flag;
    wchar_t val;
    byte field_0x1c;
    byte field_0x1d;
    byte field_0x1e;
    byte field_0x1f;
};

typedef struct __sigset_t sigset_t;

typedef struct OpenFiles_FileData_ OpenFiles_FileData_, *POpenFiles_FileData_;

typedef struct OpenFiles_Data_ OpenFiles_Data_, *POpenFiles_Data_;

typedef struct OpenFiles_Data_ OpenFiles_Data;

struct OpenFiles_Data_ {
    char *data[8];
};

struct OpenFiles_FileData_ {
    OpenFiles_Data data;
    struct OpenFiles_FileData_ *next;
};

typedef struct OpenFiles_FileData_ OpenFiles_FileData;

typedef struct OpenFiles_ProcessData_ OpenFiles_ProcessData_, *POpenFiles_ProcessData_;

typedef struct OpenFiles_ProcessData_ OpenFiles_ProcessData;

struct OpenFiles_ProcessData_ {
    OpenFiles_Data data;
    wchar_t error;
    wchar_t cols[8];
    byte field_0x64;
    byte field_0x65;
    byte field_0x66;
    byte field_0x67;
    struct OpenFiles_FileData_ *files;
};

typedef struct TempDriverDefs TempDriverDefs, *PTempDriverDefs;

struct TempDriverDefs {
    char *prefix;
    wchar_t priority;
    byte field_0xc;
    byte field_0xd;
    byte field_0xe;
    byte field_0xf;
};

typedef struct anon_struct_24_3_caff484e anon_struct_24_3_caff484e, *Panon_struct_24_3_caff484e;

struct anon_struct_24_3_caff484e {
    char *key;
    _Bool roInactive;
    byte field_0x9;
    byte field_0xa;
    byte field_0xb;
    byte field_0xc;
    byte field_0xd;
    byte field_0xe;
    byte field_0xf;
    char *info;
};

typedef struct ScreenSettings_ ScreenSettings_, *PScreenSettings_;

typedef struct ScreenSettings_ ScreenSettings;

struct ScreenSettings_ {
    char *heading;
    char *dynamic;
    struct Table_ *table;
    RowField *fields;
    uint32_t flags;
    wchar_t direction;
    wchar_t treeDirection;
    RowField sortKey;
    RowField treeSortKey;
    _Bool treeView;
    _Bool treeViewAlwaysByPID;
    _Bool allBranchesCollapsed;
    byte field_0x37;
};

typedef struct Settings_ Settings_, *PSettings_;

typedef struct ScreenSettings__5 ScreenSettings__5, *PScreenSettings__5;

typedef struct ScreenSettings__5 ScreenSettings_5;

struct ScreenSettings__5 {
    char *heading;
    char *dynamic;
    struct Table_ *table;
    RowField *fields;
    uint32_t flags;
    wchar_t direction;
    wchar_t treeDirection;
    RowField sortKey;
    RowField treeSortKey;
    _Bool treeView;
    _Bool treeViewAlwaysByPID;
    _Bool allBranchesCollapsed;
    byte field_0x37;
};

struct Settings_ {
    char *filename;
    wchar_t config_version;
    HeaderLayout hLayout;
    struct MeterColumnSetting *hColumns;
    Hashtable_2 *dynamicColumns;
    Hashtable_2 *dynamicMeters;
    Hashtable_2 *dynamicScreens;
    ScreenSettings_5 **screens;
    uint nScreens;
    uint ssIndex;
    ScreenSettings_5 *ss;
    wchar_t colorScheme;
    wchar_t delay;
    _Bool countCPUsFromOne;
    _Bool detailedCPUTime;
    _Bool showCPUUsage;
    _Bool showCPUFrequency;
    _Bool showCPUTemperature;
    _Bool degreeFahrenheit;
    _Bool showProgramPath;
    _Bool shadowOtherUsers;
    _Bool showThreadNames;
    _Bool hideKernelThreads;
    _Bool hideRunningInContainer;
    _Bool hideUserlandThreads;
    _Bool highlightBaseName;
    _Bool highlightDeletedExe;
    _Bool shadowDistPathPrefix;
    _Bool highlightMegabytes;
    _Bool highlightThreads;
    _Bool highlightChanges;
    byte field_0x62;
    byte field_0x63;
    wchar_t highlightDelaySecs;
    _Bool findCommInCmdline;
    _Bool stripExeFromCmdline;
    _Bool showMergedCommand;
    _Bool updateProcessNames;
    _Bool accountGuestInCPUMeter;
    _Bool headerMargin;
    _Bool screenTabs;
    _Bool enableMouse;
    wchar_t hideFunctionBar;
    _Bool changed;
    byte field_0x75;
    byte field_0x76;
    byte field_0x77;
    uint64_t lastUpdate;
};

typedef struct Settings_ Settings;

typedef struct Settings__5 Settings_5;

typedef struct ScreenDefaults ScreenDefaults, *PScreenDefaults;

struct ScreenDefaults {
    char *name;
    char *columns;
    char *sortKey;
    char *treeSortKey;
};

typedef struct Settings__2 Settings_2;

typedef struct DisplayOptionsPanel_ DisplayOptionsPanel_, *PDisplayOptionsPanel_;

typedef struct DisplayOptionsPanel_ DisplayOptionsPanel;

struct DisplayOptionsPanel_ {
    Panel super;
    Settings_4 *settings;
    ScreenManager_3 *scr;
};

typedef struct fd_set fd_set, *Pfd_set;

struct fd_set {
    __fd_mask fds_bits[16];
};

typedef struct CommandScreen_ CommandScreen_, *PCommandScreen_;

typedef struct CommandScreen_ CommandScreen;

struct CommandScreen_ {
    InfoScreen super;
};

typedef struct cpu_set_t cpu_set_t, *Pcpu_set_t;

struct cpu_set_t {
    __cpu_mask __bits[16];
};

typedef struct SchedulingPolicy SchedulingPolicy, *PSchedulingPolicy;

struct SchedulingPolicy {
    char *name;
    wchar_t id;
    _Bool prioritySupport;
    byte field_0xd;
    byte field_0xe;
    byte field_0xf;
};

typedef struct SchedulingArg SchedulingArg, *PSchedulingArg;

struct SchedulingArg {
    wchar_t policy;
    wchar_t priority;
};

typedef struct OpenFilesScreen_ OpenFilesScreen_, *POpenFilesScreen_;

typedef struct OpenFilesScreen_ OpenFilesScreen;

struct OpenFilesScreen_ {
    InfoScreen super;
    pid_t pid;
    byte field_0x2c;
    byte field_0x2d;
    byte field_0x2e;
    byte field_0x2f;
};

typedef struct tm_2 tm_2, *Ptm_2;

struct tm_2 {
    int tm_sec;
    int tm_min;
    int tm_hour;
    int tm_mday;
    int tm_mon;
    int tm_year;
    int tm_wday;
    int tm_yday;
    int tm_isdst;
    byte field_0x24;
    byte field_0x25;
    byte field_0x26;
    byte field_0x27;
    long tm_gmtoff;
    char *tm_zone;
};

typedef union _union_1457 _union_1457, *P_union_1457;

typedef void (*__sighandler_t_2)(int);

union _union_1457 {
    __sighandler_t_2 sa_handler;
    void (*sa_sigaction)(int, siginfo_t_2 *, void *);
};

typedef struct sigaction_2 sigaction_2, *Psigaction_2;

struct sigaction_2 {
    union _union_1457 __sigaction_handler;
    struct __sigset_t sa_mask;
    int sa_flags;
    byte field_0x8c;
    byte field_0x8d;
    byte field_0x8e;
    byte field_0x8f;
    void (*sa_restorer)(void);
};

typedef struct sched_param_2 sched_param_2, *Psched_param_2;

struct sched_param_2 {
    int __sched_priority;
};

typedef int (*__compar_fn_t_2)(void *, void *);

typedef enum Elf64_DynTag {
    DT_NULL=0,
    DT_NEEDED=1,
    DT_PLTRELSZ=2,
    DT_PLTGOT=3,
    DT_HASH=4,
    DT_STRTAB=5,
    DT_SYMTAB=6,
    DT_RELA=7,
    DT_RELASZ=8,
    DT_RELAENT=9,
    DT_STRSZ=10,
    DT_SYMENT=11,
    DT_INIT=12,
    DT_FINI=13,
    DT_SONAME=14,
    DT_RPATH=15,
    DT_SYMBOLIC=16,
    DT_REL=17,
    DT_RELSZ=18,
    DT_RELENT=19,
    DT_PLTREL=20,
    DT_DEBUG=21,
    DT_TEXTREL=22,
    DT_JMPREL=23,
    DT_BIND_NOW=24,
    DT_INIT_ARRAY=25,
    DT_FINI_ARRAY=26,
    DT_INIT_ARRAYSZ=27,
    DT_FINI_ARRAYSZ=28,
    DT_RUNPATH=29,
    DT_FLAGS=30,
    DT_PREINIT_ARRAY=32,
    DT_PREINIT_ARRAYSZ=33,
    DT_RELRSZ=35,
    DT_RELR=36,
    DT_RELRENT=37,
    DT_ANDROID_REL=1610612751,
    DT_ANDROID_RELSZ=1610612752,
    DT_ANDROID_RELA=1610612753,
    DT_ANDROID_RELASZ=1610612754,
    DT_ANDROID_RELR=1879040000,
    DT_ANDROID_RELRSZ=1879040001,
    DT_ANDROID_RELRENT=1879040003,
    DT_GNU_PRELINKED=1879047669,
    DT_GNU_CONFLICTSZ=1879047670,
    DT_GNU_LIBLISTSZ=1879047671,
    DT_CHECKSUM=1879047672,
    DT_PLTPADSZ=1879047673,
    DT_MOVEENT=1879047674,
    DT_MOVESZ=1879047675,
    DT_FEATURE_1=1879047676,
    DT_POSFLAG_1=1879047677,
    DT_SYMINSZ=1879047678,
    DT_SYMINENT=1879047679,
    DT_GNU_XHASH=1879047924,
    DT_GNU_HASH=1879047925,
    DT_TLSDESC_PLT=1879047926,
    DT_TLSDESC_GOT=1879047927,
    DT_GNU_CONFLICT=1879047928,
    DT_GNU_LIBLIST=1879047929,
    DT_CONFIG=1879047930,
    DT_DEPAUDIT=1879047931,
    DT_AUDIT=1879047932,
    DT_PLTPAD=1879047933,
    DT_MOVETAB=1879047934,
    DT_SYMINFO=1879047935,
    DT_VERSYM=1879048176,
    DT_RELACOUNT=1879048185,
    DT_RELCOUNT=1879048186,
    DT_FLAGS_1=1879048187,
    DT_VERDEF=1879048188,
    DT_VERDEFNUM=1879048189,
    DT_VERNEED=1879048190,
    DT_VERNEEDNUM=1879048191,
    DT_AUXILIARY=2147483645,
    DT_FILTER=2147483647
} Elf64_DynTag;

typedef enum Elf_ProgramHeaderType {
    PT_NULL=0,
    PT_LOAD=1,
    PT_DYNAMIC=2,
    PT_INTERP=3,
    PT_NOTE=4,
    PT_SHLIB=5,
    PT_PHDR=6,
    PT_TLS=7,
    PT_GNU_EH_FRAME=1685382480,
    PT_GNU_STACK=1685382481,
    PT_GNU_RELRO=1685382482
} Elf_ProgramHeaderType;

typedef struct Elf64_Rela Elf64_Rela, *PElf64_Rela;

struct Elf64_Rela {
    qword r_offset; /* location to apply the relocation action */
    qword r_info; /* the symbol table index and the type of relocation */
    qword r_addend; /* a constant addend used to compute the relocatable field value */
};

typedef struct Elf64_Phdr Elf64_Phdr, *PElf64_Phdr;

struct Elf64_Phdr {
    enum Elf_ProgramHeaderType p_type;
    dword p_flags;
    qword p_offset;
    qword p_vaddr;
    qword p_paddr;
    qword p_filesz;
    qword p_memsz;
    qword p_align;
};

typedef struct Elf64_Shdr Elf64_Shdr, *PElf64_Shdr;

typedef enum Elf_SectionHeaderType {
    SHT_NULL=0,
    SHT_PROGBITS=1,
    SHT_SYMTAB=2,
    SHT_STRTAB=3,
    SHT_RELA=4,
    SHT_HASH=5,
    SHT_DYNAMIC=6,
    SHT_NOTE=7,
    SHT_NOBITS=8,
    SHT_REL=9,
    SHT_SHLIB=10,
    SHT_DYNSYM=11,
    SHT_INIT_ARRAY=14,
    SHT_FINI_ARRAY=15,
    SHT_PREINIT_ARRAY=16,
    SHT_GROUP=17,
    SHT_SYMTAB_SHNDX=18,
    SHT_ANDROID_REL=1610612737,
    SHT_ANDROID_RELA=1610612738,
    SHT_GNU_ATTRIBUTES=1879048181,
    SHT_GNU_HASH=1879048182,
    SHT_GNU_LIBLIST=1879048183,
    SHT_CHECKSUM=1879048184,
    SHT_SUNW_move=1879048186,
    SHT_SUNW_COMDAT=1879048187,
    SHT_SUNW_syminfo=1879048188,
    SHT_GNU_verdef=1879048189,
    SHT_GNU_verneed=1879048190,
    SHT_GNU_versym=1879048191
} Elf_SectionHeaderType;

struct Elf64_Shdr {
    dword sh_name;
    enum Elf_SectionHeaderType sh_type;
    qword sh_flags;
    qword sh_addr;
    qword sh_offset;
    qword sh_size;
    dword sh_link;
    dword sh_info;
    qword sh_addralign;
    qword sh_entsize;
};

typedef struct Elf64_Dyn Elf64_Dyn, *PElf64_Dyn;

struct Elf64_Dyn {
    enum Elf64_DynTag d_tag;
    qword d_val;
};

typedef struct NoteAbiTag NoteAbiTag, *PNoteAbiTag;

struct NoteAbiTag {
    dword namesz; /* Length of name field */
    dword descsz; /* Length of description field */
    dword type; /* Vendor specific type */
    char name[4]; /* Vendor name */
    dword abiType; /* 0 == Linux */
    dword requiredKernelVersion[3]; /* Major.minor.patch */
};

typedef struct GnuDebugLink_48 GnuDebugLink_48, *PGnuDebugLink_48;

struct GnuDebugLink_48 {
    char filename[48];
    dword crc;
};

typedef struct Elf64_Sym Elf64_Sym, *PElf64_Sym;

struct Elf64_Sym {
    dword st_name;
    byte st_info;
    byte st_other;
    word st_shndx;
    qword st_value;
    qword st_size;
};

typedef struct GnuBuildId GnuBuildId, *PGnuBuildId;

struct GnuBuildId {
    dword namesz; /* Length of name field */
    dword descsz; /* Length of description field */
    dword type; /* Vendor specific type */
    char name[4]; /* Vendor name */
    byte hash[20];
};

typedef struct NoteGnuProperty_4 NoteGnuProperty_4, *PNoteGnuProperty_4;

struct NoteGnuProperty_4 {
    dword namesz; /* Length of name field */
    dword descsz; /* Length of description field */
    dword type; /* Vendor specific type */
    char name[4]; /* Vendor name */
};

typedef struct Elf64_Ehdr Elf64_Ehdr, *PElf64_Ehdr;

struct Elf64_Ehdr {
    byte e_ident_magic_num;
    char e_ident_magic_str[3];
    byte e_ident_class;
    byte e_ident_data;
    byte e_ident_version;
    byte e_ident_osabi;
    byte e_ident_abiversion;
    byte e_ident_pad[7];
    word e_type;
    word e_machine;
    dword e_version;
    qword e_entry;
    qword e_phoff;
    qword e_shoff;
    dword e_flags;
    word e_ehsize;
    word e_phentsize;
    word e_phnum;
    word e_shentsize;
    word e_shnum;
    word e_shstrndx;
};

