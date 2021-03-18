struct  {

    MemoryPatch nightMode;
    MemoryPatch Teletransport;
    MemoryPatch Teletransport2;
    MemoryPatch Speed1;
    MemoryPatch Speed2;    
    MemoryPatch NoParacaidas;
    MemoryPatch NightMod;
    MemoryPatch Viewcamera1;
    MemoryPatch Viewcamera2;
    MemoryPatch Viewcamera3;
    MemoryPatch MedKitRunning;
    MemoryPatch MedKitRunning2;
    MemoryPatch MedKitRunning3;
    MemoryPatch WhiteBody;
    MemoryPatch WhiteBody2;
    MemoryPatch modcorHd;
    MemoryPatch AntenaPro;
    MemoryPatch SemDano;
    MemoryPatch CorpoHack1;
    MemoryPatch CorpoHack2;
    MemoryPatch CorpoHack3;
    MemoryPatch CorpoHack4;
    MemoryPatch CorpoHack5;
    MemoryPatch NoScope;
    MemoryPatch SuperSpeed;
    MemoryPatch AimbotSemi;
    MemoryPatch Socofast;
    MemoryPatch MiraLockUpd;
    MemoryPatch MiraLock;
    MemoryPatch RecargaFast;
    MemoryPatch SemDelay;
    MemoryPatch SemDelay2;
    MemoryPatch TiroMovimento;
    MemoryPatch SensiNormal;
    MemoryPatch SensiMedia;
    MemoryPatch SensiAlta;
    MemoryPatch ChuvaBug;
    MemoryPatch ChuvaBala1;
    MemoryPatch ChuvaBala2;
    MemoryPatch ChuvaBala3;
    MemoryPatch ChuvaBala4;
    MemoryPatch ChuvaBala5;
    MemoryPatch ChuvaBala6;
    MemoryPatch ChuvaBala7;
    MemoryPatch ChuvaBala8;
    MemoryPatch ChuvaBala9;
    MemoryPatch ChuvaBala10;
    MemoryPatch ChuvaBala11;
    MemoryPatch ChuvaBala12;
    MemoryPatch ChuvaBala13;
    MemoryPatch ChuvaBala14;
    MemoryPatch ChuvaBala15;
    MemoryPatch WallPedra;
    MemoryPatch WallCarroUpd;
    MemoryPatch WallCarro;
    MemoryPatch wallPedra;
    MemoryPatch medKit1;
    MemoryPatch medKit2;
    MemoryPatch medKit3;
    MemoryPatch ghostHack;
    MemoryPatch Bypass;
	MemoryPatch rain1;
	MemoryPatch rain2;
	MemoryPatch rain3;
	MemoryPatch rain4;
	MemoryPatch rain5;
	MemoryPatch rain6;
	MemoryPatch rain7;
	MemoryPatch rain8;
	MemoryPatch rain9;
	MemoryPatch rain10;
	MemoryPatch rain11;
	MemoryPatch rain12;

} Patches;;
bool byFOV;
bool KMHack1 = false, KMHack2 = false, KMHack3 = false, KMHack4 = false, KMHack5 = false, KMHack6 = false, KMHack7 = false, KMHack8 = false, KMHack9 = false, KMHack10 = false, KMHack11 = false, KMHack12 = false, KMHack13 = false, KMHack14 = false, KMHack15 = false, KMHack16 = false,
KMHack17 = false, KMHack18 = false,
KMHack33 = false, KMHack34 = false,
KMHack87 = false, KMHack88 = false,
KMHack01 = false, KMHack0 = false,
KMHack123 = false, KMHack886 = false;

int Desativer = 0;

int semi = 0xBCF174;
int ghost = 0xBF6AE4;
int ghost2 = 0xBF6AE4;
int speed = 0xA41BD0;
int paraquedas = 0xA1DC2C;
int viewcamera = 0x1B2471C;
int medkit1 = 0x2160BA0;
int medkit2 = 0xA3CC6C;
int medkit3 = 0xA3A3D4;
int branco1 = 0xA1FD7C;
int branco2 = 0x1859F48;
int modohd = 0x29DDB78;
int semdano = 0x290CE18;
int removermira = 0xBA0F08;
int soco = 0xBD1FBC;
int miraLockUpd = 0xB98834;
int aimlock = 0x126F250;
int recargarapida = 0x125C5A0;
int semdelay1 = 0x2222D14;
int semdelay2 = 0x1B436A0;
int tiroEmMovimento = 0xA41358;
int sensibilidade = 0xA42F44;
int chuvaBug = 0xBDC994;
int chuvaBalas = 0xBCF820;
int wallCarroUpd = 0x2A6C9B4;
int wallCarro = 0x21D19E4;
int modonoite = 0x1A2280;
int antenaCorpo = 0x2A3454;
int corpoGrande = 0xA41BD0;
int zePedrinha = 0xEF2890;


struct {

    float Fov_Aim = 0.998f;
    int semihs = 0;
    bool aimBotFov = false;
    bool aimScope = false;
    bool aimTiro = false;
    bool hs100 = false;
    bool ghost = false;
    bool hs70 = false;
    bool aimAgachado = false;
    bool aimBody = false;
    bool aimbotauto = true;
    bool teleKill = false;
    bool Paraquedas = false;
    bool aimVisibilidade = false;

    bool AlertWorld = false;
    bool AlertAround = false;
    bool Angle = false;
    bool espDistance = false;
    
    bool espName = false;
    bool espNames = false;
    bool aimFire = false;
    bool espSkeleton = false;
    bool espCircle = false;
    bool espNear = false;
    bool isEspReady = false;

    bool closestEnemy = false;
    bool espFire = false;

    bool fakeName = false;
    
    bool sameteams = false;
    bool byFOV = false;
    bool aimTeste = false;
    bool aimTeste1 = false;
    bool aimTeste3 = false;
    bool medKit = false;
    

    int enemyCountAround = 0;
    int botCountAround = 0;
    int enemyCountWorld = 0;
    int botCountWorld = 0;

} MT;

bool active = true;
bool launched = false;

JNIEXPORT void JNICALL
Java_com_mt_team_FloatingModMenuService_Joeliton(
        JNIEnv *env,
        jobject activityObject,
        jint feature,
        jint Value) {

    __android_log_print(ANDROID_LOG_VERBOSE, "Mod Menu", "Feature: = %d", feature);
    __android_log_print(ANDROID_LOG_VERBOSE, "Mod Menu", "Value: = %d", Value);

    // You must count your features from 0, not 1
