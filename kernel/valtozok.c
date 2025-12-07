volatile unsigned short* vga = (volatile unsigned short*)0xB8000;
char command[32];
int cmd_len = 0;
// FAT12 SPECIFIKUS KONSTANSOK
#define SECTOR_SIZE 512
#define FAT12_LBA_OFFSET 64  // A BPB kezdete a 65. szektor (LBA 64)
#define ATA_PRIMARY_DATA 0x1F0
#define ATA_PRIMARY_ERROR 0x1F1
#define ATA_PRIMARY_SECTOR_COUNT 0x1F2
#define ATA_PRIMARY_LBA_LOW 0x1F3
#define ATA_PRIMARY_LBA_MID 0x1F4
#define ATA_PRIMARY_LBA_HIGH 0x1F5
#define ATA_PRIMARY_DRIVE_HEAD 0x1F6
#define ATA_PRIMARY_COMMAND 0x1F7
#define ATA_PRIMARY_STATUS 0x1F7
#define ATA_PRIMARY_DCR 0x3F6

// A FAT12 BPB (Boot Parameter Block) minimális struktúrája
typedef struct {
    unsigned char  BS_jmpBoot[3];
    unsigned char  BS_OEMName[8];
    unsigned short BPB_BytesPerSec;     // 0x0B (512)
    unsigned char  BPB_SecPerClus;      // 0x0D (1, 2, 4...)
    unsigned short BPB_RsvdSecCnt;      // 0x0E (1)
    unsigned char  BPB_NumFATs;         // 0x10 (2)
    unsigned short BPB_RootEntCnt;      // 0x11 (224/14)
    unsigned short BPB_TotSec16;        // 0x13 (2880)
    unsigned char  BPB_Media;           // 0x15
    unsigned short BPB_FATSz16;         // 0x16 (9)
    unsigned short BPB_SecPerTrk;       // 0x18
    unsigned short BPB_NumHeads;        // 0x1A
    unsigned int   BPB_HiddenSec;       // 0x1C (A MI ESETÜNKBEN EZ: 64)
    unsigned int   BPB_TotSec32;        // 0x20
    // ... további FAT12/16/32 mezők
    unsigned char  BS_DriveNum;         // 0x24
    unsigned char  BS_Reserved1;        // 0x25
    unsigned char  BS_BootSig;          // 0x26
    unsigned int   BS_VolID;            // 0x27
    unsigned char  BS_VolLab[11];       // 0x2B
    unsigned char  BS_FilSysType[8];    // 0x36 ("FAT12   ")
} __attribute__((packed)) BPB_struct;

// A Gyökérkönyvtár bejegyzés struktúrája
typedef struct {
    unsigned char  DIR_Name[11];        // 0x00
    unsigned char  DIR_Attr;            // 0x0B
    unsigned char  _reserved[10];
    unsigned short DIR_WrtTime;
    unsigned short DIR_WrtDate;
    unsigned short DIR_FstClus;         // 0x1A (Első klaszter száma)
    unsigned int   DIR_FileSize;        // 0x1C
    unsigned short DIR_FstClusLO;
} __attribute__((packed)) DIR_Entry;

// Globális változók a BPB adatok tárolására
BPB_struct g_bpb;
static int shift_active = 1;
int strlen(const char* str);
unsigned char g_fat_table[512 * 9];
#define TARGET_LOAD_ADDR ((void*)0x20000)