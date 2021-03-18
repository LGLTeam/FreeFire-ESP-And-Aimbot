#ifndef ANDROID_MOD_MENU_GLOBAL_H
#define ANDROID_MOD_MENU_GLOBAL_H

struct {

    uintptr_t MainCameraTransform = 0x54;   
    uintptr_t HeadTF = 0x1A0;  
    uintptr_t HipTF = 0x1A4;     
    uintptr_t HandTF = 0x19C;   
    uintptr_t EyeTF = 0x1A8;   
    uintptr_t IsClientBot = 0xC4;   
    uintptr_t U3DStr = 0x2003AE4;  
    uintptr_t U3DStrConcat = 0x2002284;  
    uintptr_t Component_GetTransform = 0x2689594;  
    uintptr_t GetCameraTrackableEntityTransfrom = 0xA5C7CC;  
    uintptr_t Transform_INTERNAL_GetPosition = 0x2C9523C;  
    uintptr_t Transform_INTERNAL_SetPosition = 0x2C952FC;  
    uintptr_t GetForward = 0x2C95920;  
    uintptr_t get_isAlive = 0xA5C7D4;  
    uintptr_t GetPhysXPose = 0xA20504;  
    uintptr_t IsFiring = 0xA32650;  
    uintptr_t IsCrouching = 0xA20538;  
    uintptr_t get_IsSighting = 0xA68864;  
    uintptr_t get_IsCrouching = 0xA20538;  
	uintptr_t get_isLocalPlayer = 0xA18CDC;      
    uintptr_t get_isLocalTeam = 0xA1EC58; 
    uintptr_t get_isVisible = 0xA182F0;  
    uintptr_t set_aim = 0xA162E0;  
    uintptr_t Camera_main_fov = 0x2682544;  
    uintptr_t get_imo = 0xA1B034;  
    uintptr_t set_esp = 0xBDF540;  
    uintptr_t GetAttackableCenterWS = 0xA14E3C;  
    uintptr_t GetCharacterControllerTopPosition = 0xA54880;  
    uintptr_t get_NickName = 0xA15364;  
    uintptr_t WorldToScreenPoint = 0x2684310;  
    uintptr_t get_height = 0x29E2974;      
    uintptr_t get_width = 0x29E28E4;  
    uintptr_t get_deltaTime = 0x2C93CE4;  
    uintptr_t CurrentUIScene = 0x24DF694;  
    uintptr_t Curent_Match = 0x24E00E8;  
    uintptr_t Current_Local_Player = 0x24E043C;  
    uintptr_t GetLocalPlayerOrObServer = 0x24E0AFC;  
    uintptr_t CurrentLocalSpectator = 0x24E08BC;      
    uintptr_t Player_Index = 0x1A061EC; 
    uintptr_t AddTeammateHud = 0x12340C8;  
    uintptr_t get_tele = 0xBF6AE4;  
    uintptr_t spof_uid = 0xA15274;  
    uintptr_t spof_nick = 0xA1536C;    
    uintptr_t ShowDynamicPopupMessage = 0x12222A4;  
    uintptr_t ShowPopupMessage = 0x122242C;  
    uintptr_t GetLocalPlayer = 0x1FBCF6C;  
    uintptr_t GetCharacterHeight = 0xA272E8;  
    uintptr_t set_height = 0x2687EA0;  
    uintptr_t get_CharacterController = 0xA15710;  
    uintptr_t IsUserControlChanged = 0xA20414;  
    uintptr_t set_invitee_nickname = 0x2BC7240;  
    uintptr_t Raycast = 0x298C28C;  
    uintptr_t get_MyFollowCamera = 0xA15C3C;  
    uintptr_t IsSameTeam = 0x24E1894;  
    uintptr_t AttackableEntity_GetIsDead = 0x23A4B4C;  
    uintptr_t AttackableEntity_IsVisible = 0x23A6ADC;  
    uintptr_t Camera_WorldToScreenPoint =  0x2684310;  
    uintptr_t Camera_main = 0x2684900;  
    uintptr_t wallPedra = 0xEF2890;   
    uintptr_t nightMode = 0x1A2280;  
    uintptr_t medKit1 = 0xA91ACC;  
    uintptr_t medKit2 = 0x2160BA0;   
    uintptr_t medKit3 = 0xA3CC6C;  
    uintptr_t ghostHack = 0xBF6AE4; 
    uintptr_t hdGraphic = 0x29DDB78; 
	uintptr_t rainbullets = 0xBD2278;  

} Global;

#endif