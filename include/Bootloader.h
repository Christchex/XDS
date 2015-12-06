// Shamelessly stolen from ctrtool.
typedef struct {
    u8 signature[0x100];
    u8 magic[4];
    u8 contentsize[4];
    u8 partitionid[8];
    u8 makercode[2];
    u8 version[2];
    u8 reserved0[4];
    u8 programid[8];
    u8 tempflag;
    u8 reserved1[0x2f];
    u8 productcode[0x10];
    u8 extendedheaderhash[0x20];
    u8 extendedheadersize[4];
    u8 reserved2[4];
    u8 flags[8];
    u8 plainregionoffset[4];
    u8 plainregionsize[4];
    u8 reserved3[8];
    u8 exefsoffset[4];
    u8 exefssize[4];
    u8 exefshashregionsize[4];
    u8 reserved4[4];
    u8 romfsoffset[4];
    u8 romfssize[4];
    u8 romfshashregionsize[4];
    u8 reserved5[4];
    u8 exefssuperblockhash[0x20];
    u8 romfssuperblockhash[0x20];
} ctr_ncchheader;

// Exheader
typedef struct {
    u8 reserved[5];
    u8 flag;
    u8 remasterversion[2];
} exheader_systeminfoflags;

typedef struct {
    u8 address[4];
    u8 nummaxpages[4];
    u8 codesize[4];
} exheader_codesegmentinfo;

typedef struct {
    u8 name[8];
    exheader_systeminfoflags flags;
    exheader_codesegmentinfo text;
    u8 stacksize[4];
    exheader_codesegmentinfo ro;
    u8 reserved[4];
    exheader_codesegmentinfo data;
    u8 bsssize[4];
} exheader_codesetinfo;

typedef struct {
    u8 programid[0x30][8];
} exheader_dependencylist;

typedef struct {
    u8 savedatasize[4];
    u8 reserved[4];
    u8 jumpid[8];
    u8 reserved2[0x30];
} exheader_systeminfo;

typedef struct {
    u8 extsavedataid[8];
    u8 systemsavedataid[8];
    u8 reserved[8];
    u8 accessinfo[7];
    u8 otherattributes;
} exheader_storageinfo;

typedef struct {
    u8 programid[8];
    u8 flags[8];
    u8 resourcelimitdescriptor[0x10][2];
    exheader_storageinfo storageinfo;
    u8 serviceaccesscontrol[0x20][8];
    u8 reserved[0x1f];
    u8 resourcelimitcategory;
} exheader_arm11systemlocalcaps;

typedef struct {
    u8 descriptors[28][4];
    u8 reserved[0x10];
} exheader_arm11kernelcapabilities;

typedef struct {
    u8 descriptors[15];
    u8 descversion;
} exheader_arm9accesscontrol;

typedef struct {
    // systemcontrol info {
    //   coreinfo {
    exheader_codesetinfo codesetinfo;
    exheader_dependencylist deplist;
    //   }
    exheader_systeminfo systeminfo;
    // }
    // accesscontrolinfo {
    exheader_arm11systemlocalcaps arm11systemlocalcaps;
    exheader_arm11kernelcapabilities arm11kernelcaps;
    exheader_arm9accesscontrol arm9accesscontrol;
    // }
    struct {
        u8 signature[0x100];
        u8 ncchpubkeymodulus[0x100];
        exheader_arm11systemlocalcaps arm11systemlocalcaps;
        exheader_arm11kernelcapabilities arm11kernelcaps;
        exheader_arm9accesscontrol arm9accesscontrol;
    } accessdesc;
} exheader_header;

// ExeFS
typedef struct {
    u8 name[8];
    u8 offset[4];
    u8 size[4];
} exefs_sectionheader;

typedef struct {
    exefs_sectionheader section[8];
    u8 reserved[0x80];
    u8 hashes[8][0x20];
} exefs_header;

int Boot(KKernel* kernel);
