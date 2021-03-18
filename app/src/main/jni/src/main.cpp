
#include <pthread.h>
#include <jni.h>
#include <src/Includes/Utils.h>
#include "Hook.h"
#include "Função.h"



#if defined(__aarch64__) //Compile for arm64 lib only
#include <src/And64InlineHook/And64InlineHook.hpp>
#else //Compile for armv7 lib only. Do not worry about greyed out highlighting code, it still works
#include <src/Substrate/SubstrateHook.h>
#endif

#include "KittyMemory/MemoryPatch.h"
#include "Includes/Logger.h"
#include "struc.h"

#define HOOK(offset, ptr, orig) MSHookFunction((void *)getRealOffset(offset), (void *)ptr, (void **)&orig)



    switch (feature) {
        // The category was 0 so "case 0" is not needed
        case 0:
       MT.hs100 = !MT.hs100;
        byFOV = !byFOV;
        break;
      
		
        break;
        
        
        
            case 1:
        MT.aimFire= !MT.aimFire;
        break;
        

    case 2:
        MT.aimScope= !MT.aimScope;
        break;
        

        
        
        
        case 3:
        MT.aimAgachado = !MT.aimAgachado;
		
        break;
        
           case 4:
     if (Value > 0) {
            MT.Fov_Aim = 1.0f - (0.0099f * (float)Value);
        }
        break;
        
                   case 5:
        if (Value > 0) {
            MT.aimBotFov = 1.0f - (0.0099f * (float)Value);
        }
        break;
        
         case 6:

            if (Value == 0) {
                Patches.SensiNormal.Restore();
                Patches.SensiMedia.Restore();
                Patches.SensiAlta.Restore();
            } else if (Value == 1) {
                Patches.SensiNormal.Modify();
            } else if (Value == 2) {
                Patches.SensiMedia.Modify();
            } else if (Value == 3) {
                Patches.SensiAlta.Modify();
            }
            break;
           
        case 7:
        MT.espFire = !MT.espFire;
        break;
    default:
        break;
        
       case 8:
        MT.espNames = !MT.espNames;
        break;
       
       
     case 9:
        MT.fakeName = !MT.fakeName;
        break;
   
            
        case 10:

            if (Value == 0) {
                Patches.CorpoHack1.Restore();
                Patches.CorpoHack2.Restore();
                Patches.CorpoHack3.Restore();
                Patches.CorpoHack4.Restore();
                Patches.CorpoHack5.Restore();
            } else if (Value == 1) {
                Patches.CorpoHack1.Modify();
            } else if (Value == 2) {
                Patches.CorpoHack2.Modify();
            } else if (Value == 3) {
                Patches.CorpoHack3.Modify();
            } else if (Value == 4) {
                Patches.CorpoHack4.Modify();
            } else if (Value == 5) {
                Patches.CorpoHack5.Modify();
            }
            break;
            

        
           case 11:
                MT.teleKill = !MT.teleKill;
                    break;
        
 
        
                case 12:
                    MT.ghost = !MT.ghost;
                break;
            
                     case 13:
            KMHack123 = !KMHack123;
            if (KMHack123) {
                Patches.Socofast.Modify();
            } else {
                Patches.Socofast.Restore();
            }
            break;
            
          case 14:
            KMHack5 = !KMHack5;
            if (KMHack5) {
                Patches.WhiteBody.Modify();
                Patches.WhiteBody2.Modify();
            } else {
                Patches.WhiteBody.Restore();
                Patches.WhiteBody2.Restore();
            }
            break;         
            
             case 15:
            KMHack4 = !KMHack4;
            if (KMHack4) {
                Patches.MedKitRunning.Modify();
                Patches.MedKitRunning2.Modify();
            } else {
                Patches.MedKitRunning.Restore();
                Patches.MedKitRunning2.Restore();
            }
            break;
            
            
                 case 16:
            KMHack33 = !KMHack33;
            if (KMHack33) {
                Patches.modcorHd.Modify();
            } else {
                Patches.modcorHd.Restore();
            }
            break;
            
        
            case 17:
            KMHack3 = !KMHack3;
            if (KMHack3) {
                
                Patches.NightMod.Modify();
            } else {
                Patches.NightMod.Restore();
                
            }
            break;
            
      case 18:
            KMHack15 = !KMHack15;
            if (KMHack15) {
                Patches.WallPedra.Modify();
            } else {
                Patches.WallPedra.Restore();
            }
            break;
            

            
 
            
    
    
	}
	}
	
	
	}


	void (*LateUpdate)(void *componentPlayer);
void AimBot(void *local_player, void *enemy_player) {

    int pose = GetPhysXPose(enemy_player);
    bool alive = get_isAlive(enemy_player);
    bool visible = get_isVisible(enemy_player);
    bool visi = get_AttackableEntity_IsVisible(enemy_player);
    bool visir = get_AttackableEntity_GetIsDead(enemy_player);

    bool sameteam = get_isLocalTeam(enemy_player);
    void *HeadTF = *(void **)((uintptr_t)enemy_player + Global.HeadTF);
    void *HipTF = *(void **)((uintptr_t)enemy_player + Global.HipTF);
    void *Main_Camera = *(void **)((uintptr_t)local_player + Global.MainCameraTransform);

    if (!get_IsSkyDashing(local_player) && !get_IsParachuting(local_player) && !get_IsSkyDiving(local_player) && !get_IsDieing(local_player) && alive && pose != 8  && !sameteam && HeadTF != NULL && Main_Camera != NULL && HipTF != NULL) {
        Vector3 EnemyLocation = Transform_INTERNAL_GetPosition(HeadTF);
        Vector3 CenterWS = GetAttackableCenterWS(local_player);
        bool scope = get_IsSighting(local_player);
        bool agachado = get_IsCrouching(local_player);
        float distance = Vector3::Distance(CenterWS, EnemyLocation);

        Vector3 PlayerLocation = Transform_INTERNAL_GetPosition(Main_Camera);
        Quaternion PlayerLook = GetRotationToLocation(EnemyLocation, 0.1f, PlayerLocation);
        Quaternion PlayerLook2 = GetRotationToLocation(Transform_INTERNAL_GetPosition(HipTF), 0.1f, PlayerLocation);
                Vector3 fwd = Transform_get_forward(Main_Camera);
                
        Vector3 nrml = Vector3::Normalized(EnemyLocation - PlayerLocation);
        float PlayerDot = Vector3::Dot(fwd, nrml);
		



        if (MT.espFire) {
            void *imo = get_imo(local_player);
            if (imo != NULL && distance > 1.0f) {
                set_esp(imo, CenterWS, EnemyLocation);
            }
        }
        
          if (MT.AlertWorld) {
            monoString *alert = FormatCount(MT.enemyCountWorld, MT.botCountWorld);
            if (alert != NULL) {
                ShowDynamicPopupMessage(alert);
            }
        }

        
        
            if (MT.fakeName) {
            spofNick(local_player);
        }

           if (MT.espNames) {
            void *ui = CurrentUIScene();
            if (ui != NULL) {
                monoString *nick = get_NickName(enemy_player);
                monoString *distances = U3DStrFormat(distance);
                AddTeammateHud(ui, nick, distances);
            }
        }
            if (MT.Paraquedas ) {
            void *_MountTF = Component_GetTransform(enemy_player);
            if (_MountTF != NULL) {
                Vector3 MountTF =
Patches.Teletransport.Modify(); Patches.Teletransport.Restore();                       Transform_INTERNAL_GetPosition(_MountTF) - (GetForward(_MountTF) * 1.6f);
                Transform_INTERNAL_SetPosition(Component_GetTransform(local_player), Vvector3(MountTF.X, MountTF.Y, MountTF.Z));
            }
        }
        

if (MT.teleKill) {
                       set_aim(local_player, PlayerLook);
            void *_MountTF = Component_GetTransform(enemy_player);
            if (_MountTF != NULL) {
                Vector3 MountTF =
                        Transform_INTERNAL_GetPosition(_MountTF) - (GetForward(_MountTF) * 1.6f);
                Transform_INTERNAL_SetPosition(Component_GetTransform(local_player), Vvector3(MountTF.X, MountTF.Y, MountTF.Z));
            }
        }
	   

        if ((agachado && MT.aimAgachado) && ((PlayerDot > 0.998f && !MT.aimBotFov) || (PlayerDot > MT.Fov_Aim && MT.aimBotFov))) {
        	            
            set_aim(local_player, PlayerLook);
        }
        

        if ((scope && MT.aimScope) && ((PlayerDot > 0.998f && !MT.aimBotFov) || (PlayerDot > MT.Fov_Aim && MT.aimBotFov))) {
            set_aim(local_player, PlayerLook);

        }
        

                bool firing = IsFiring(local_player);
        if ((firing && MT.aimFire) && ((PlayerDot > 0.998f && !MT.aimBotFov) || (PlayerDot > MT.Fov_Aim && MT.aimBotFov))) {
        	            

            if (MT.aimBody) {
                set_aim(local_player, PlayerLook2);
            }
            if (MT.hs100) {
                set_aim(local_player, PlayerLook);
            }
            if (MT.hs70) {
                if (MT.aimbotauto)
                {
                    set_aim(local_player, PlayerLook);
                    ++MT.semihs;
                } else {
                    set_aim(local_player, PlayerLook2);
                    --MT.semihs;
                }

                if (MT.semihs == 6)
                {
                    MT.aimbotauto = false;
                } else if (MT.semihs == 0) {
                    MT.aimbotauto = true;
                }
                if (MT.semihs > 6 || MT.semihs < 0)
                {
                    MT.semihs = 3;
                    MT.aimbotauto = true;
                }
            }
        }
		}
		}
    


bool isEspReady = false;

void *fakeEnemy;
void _LateUpdate(void *player){
    if (player != NULL) {
        void *local_player = Current_Local_Player();
        if (local_player == NULL){
            local_player = GetLocalPlayerOrObServer();
        }
        if (local_player != NULL){
            void *current_match = Curent_Match();
            if (current_match != NULL) {
                void *fakeCamPlayer = get_MyFollowCamera(local_player);
                void *fakeCamEnemy = get_MyFollowCamera(player);
                if (fakeCamPlayer != NULL && fakeCamEnemy != NULL){
                    void *fakeCamPlayerTF = Component_GetTransform(fakeCamPlayer);
                    void *fakeCamEnemyTF = Component_GetTransform(player);
                    if (fakeCamPlayerTF != NULL && fakeCamEnemyTF != NULL){
                        Vector3 fakeCamPlayerPos = Transform_INTERNAL_GetPosition(fakeCamPlayerTF);
                        Vector3 fakeCamEnemyPos = Transform_INTERNAL_GetPosition(fakeCamEnemyTF);
                        float distance = Vector3::Distance(fakeCamPlayerPos, fakeCamEnemyPos);
                        if (player != local_player){
                            if (distance > 1.6f) {
                                bool sameteams = get_isLocalTeam(player);
                                int pose = GetPhysXPose(player);
                                bool alive = get_isAlive(player);
                                bool visible = get_isVisible(player);
                                bool visir = get_AttackableEntity_GetIsDead(player);
                                       
                                if (!sameteams && pose != 8 && alive && !get_IsSkyDashing(player) && !get_IsSkyDiving(player) && !get_IsDieing(player) && IsVisible(player) && get_CurHP(player) > 0) {
                                    AimBot(local_player, player);
                                }
                            } else {
                                fakeEnemy = player;
                            }
                        }
                    }
					    
                }
            }
        }
    }
    LateUpdate(player);
    }
 
Vector3 GetHeadPosition(void* player){
    return Transform_INTERNAL_GetPosition(*(void**) ((uint64_t) player + 0x1A0));



}
Vector3 GetHipPosition(void* player){
    return Transform_INTERNAL_GetPosition(*(void**) ((uint64_t) player + 0x1A4));
}

void* GetClosestEnemy(void* _this, bool byFOV) {
    if(_this == NULL) {
        return NULL;
    }
    float shortestDistance = 99999999.0;
    float maxAngle = 30.0;
    void* closestEnemy = NULL;
    void* LocalPlayer = GetLocalPlayer(_this);
    if(LocalPlayer != NULL && !get_IsSkyDashing(LocalPlayer) && !get_IsParachuting(LocalPlayer) && !get_IsSkyDiving(LocalPlayer) && !get_IsDieing(LocalPlayer));
        for (int u = 0; u <= 50; u++) {
            void *Player = getPlayerByIndex(_this, (uint8_t) u);
            {
				
            if (Player != NULL && !IsSameTeam(LocalPlayer, Player) && !get_IsDieing(Player) && !get_IsSkyDashing(Player) && !get_IsParachuting(Player) && !get_IsSkyDiving(Player) && IsVisible(Player) && get_CurHP(Player) > 0)
            {
				
                Vector3 PlayerPos = GetHipPosition(Player);
                Vector3 LocalPlayerPos = GetHipPosition(LocalPlayer);Transform_INTERNAL_GetPosition(Component_get_transform(get_main()));
                float distanceToMe = Vector3::Distance(LocalPlayerPos, PlayerPos);
                if(byFOV) {
                    Vector3 targetDir = PlayerPos - LocalPlayerPos;
					
                    float angle = Vector3::Angle(targetDir, Transform_get_forward(Component_get_transform(get_main()))) * 100.0;
                    
                    if(angle <= maxAngle) {
                        if(distanceToMe < shortestDistance) {
                            shortestDistance = distanceToMe;
                            closestEnemy = Player;
                        }
                    }
                } else {
                    if(distanceToMe < shortestDistance) {
                        shortestDistance = distanceToMe;
                        closestEnemy = Player;
                    }
                }
            }
        }
    }
    return closestEnemy;
}

bool (*orig_ghost)(void* _this, int value);
bool _ghost(void* _this, int value){
    if (_this != NULL){
        if (MT.ghost || MT.teleKill){
            return false;
        }
    }
    return orig_ghost(_this, value);
}
	
	    void *hack_thread(void *) {
    ProcMap il2cppMap;
    do {
        il2cppMap = KittyMemory::getLibraryMap(libName);
        sleep(1);
    } while (!il2cppMap.isValid());

Patches.Bypass.Modify();

    Patches.Teletransport = MemoryPatch("libil2cpp.so", ghost, "\x00\x00\xA0\xE3\x1E\xFF\x2F\xE1", 8);
        Patches.Teletransport2 = MemoryPatch("libil2cpp.so", ghost, "\x00\x00\xA0\xE3\x1E\xFF\x2F\xE1", 8);
        Patches.Speed1 = MemoryPatch("libil2cpp.so", speed, "\x82\x0F\x43\xE3\x1E\xFF\x2F\xE1", 8);
            Patches.Speed2 = MemoryPatch("libil2cpp.so", speed, "\x84\x0F\x43\xE3\x1E\xFF\x2F\xE1", 8);
    Patches.NoParacaidas = MemoryPatch("libil2cpp.so", paraquedas, "\x00\x00\xA0\xE3\x1E\xFF\x2F\xE1", 8);
    Patches.Viewcamera1 = MemoryPatch("libil2cpp.so", speed, "\x32\x00\x44\xE3\x1E\xFF\x2F\xE1", 8);
    Patches.Viewcamera2 = MemoryPatch("libil2cpp.so", speed, "\x64\x00\x44\xE3\x1E\xFF\x2F\xE1", 8);
    Patches.Viewcamera3 = MemoryPatch("libil2cpp.so", speed, "\x7F\x00\x44\xE3\x1E\xFF\x2F\xE1", 8);
    Patches.MedKitRunning = MemoryPatch("libil2cpp.so", medkit1, "\x00\x00\xA0\xE3\x1E\xFF\x2F\xE1", 8);
    Patches.MedKitRunning2 = MemoryPatch("libil2cpp.so", medkit2, "\x00\x00\xA0\xE3\x1E\xFF\x2F\xE1", 8);
    Patches.MedKitRunning3 = MemoryPatch("libil2cpp.so", medkit3, "\x00\x00\xA0\xE3\x1E\xFF\x2F\xE1", 8);
    Patches.WhiteBody = MemoryPatch("libil2cpp.so", branco1, "\x01\x00\xA0\xE3\x1E\xFF\x2F\xE1", 8);
    Patches.WhiteBody2 = MemoryPatch("libil2cpp.so", branco2, "\x00\x00\xA0\xE3\x1E\xFF\x2F\xE1", 8);
    Patches.modcorHd = MemoryPatch("libil2cpp.so", modohd, "\x00\x00\xA0\xE3\x1E\xFF\x2F\xE1", 8);
    Patches.SemDano = MemoryPatch("libil2cpp.so", semdano, "\x00\x00\xD0\xC1", 4);
    Patches.NoScope = MemoryPatch("libil2cpp.so", removermira, "\x00\x00\xA0\xE3\x1E\xFF\x2F\xE1", 8);
    Patches.AimbotSemi = MemoryPatch("libil2cpp.so", semi, "\x5C\x04\x44\xE3\x1E\xFF\x2F\xE1", 8);
    Patches.Socofast = MemoryPatch("libil2cpp.so", soco, "\x8A\x00\xA0\xE3\x1E\xFF\x2F\xE1", 8);
    Patches.MiraLockUpd = MemoryPatch("libil2cpp.so", miraLockUpd, "\x00\x00\xA0\xE3\x1E\xFF\x2F\xE1", 8);
    Patches.MiraLock = MemoryPatch("libil2cpp.so", aimlock, "\x01\x00\xA0\xE3\x1E\xFF\x2F\xE1", 8);
    Patches.RecargaFast = MemoryPatch("libil2cpp.so", recargarapida, "\x12\x03\xA0\xE3\x1E\xFF\x2F\xE1", 8);
    Patches.SemDelay = MemoryPatch("libil2cpp.so", semdelay1, "\x00\x00\x00\x00", 4);
    Patches.SemDelay2 = MemoryPatch("libil2cpp.so", semdelay2, "\x00\x00\x00\x00", 4);
    Patches.TiroMovimento = MemoryPatch("libil2cpp.so", tiroEmMovimento, "\x01\x00\xA0\xE3\x1E\xFF\x2F\xE1", 8);
    Patches.SensiNormal = MemoryPatch("libil2cpp.so", sensibilidade, "\x00\x00\x7A\x43", 4);
    Patches.SensiMedia = MemoryPatch("libil2cpp.so", sensibilidade, "\x00\x00\x48\x43", 4);
    Patches.SensiAlta = MemoryPatch("libil2cpp.so", sensibilidade, "\x00\x00\x16\x43", 4);
    Patches.ChuvaBug = MemoryPatch("libil2cpp.so", chuvaBug, "\x12\x00\xA0\xE3\x1E\xFF\x2F\xE1", 8);
    Patches.ChuvaBala1 = MemoryPatch("libil2cpp.so", chuvaBalas, "\x02\x00\xA0\xE3\x1E\xFF\x2F\xE1", 8);
    Patches.ChuvaBala2 = MemoryPatch("libil2cpp.so", chuvaBalas, "\x03\x00\xA0\xE3\x1E\xFF\x2F\xE1", 8);
    Patches.ChuvaBala3 = MemoryPatch("libil2cpp.so", chuvaBalas, "\x04\x00\xA0\xE3\x1E\xFF\x2F\xE1", 8);
    Patches.ChuvaBala4 = MemoryPatch("libil2cpp.so", chuvaBalas, "\x05\x00\xA0\xE3\x1E\xFF\x2F\xE1", 8);
    Patches.ChuvaBala5 = MemoryPatch("libil2cpp.so", chuvaBalas, "\x06\x00\xA0\xE3\x1E\xFF\x2F\xE1", 8);
    Patches.ChuvaBala6 = MemoryPatch("libil2cpp.so", chuvaBalas, "\x07\x00\xA0\xE3\x1E\xFF\x2F\xE1", 8);
    Patches.ChuvaBala7 = MemoryPatch("libil2cpp.so", chuvaBalas, "\x08\x00\xA0\xE3\x1E\xFF\x2F\xE1", 8);
    Patches.ChuvaBala8 = MemoryPatch("libil2cpp.so", chuvaBalas, "\x09\x00\xA0\xE3\x1E\xFF\x2F\xE1", 8);
    Patches.ChuvaBala9 = MemoryPatch("libil2cpp.so", chuvaBalas, "\x0A\x00\xA0\xE3\x1E\xFF\x2F\xE1", 8);
    Patches.ChuvaBala10 = MemoryPatch("libil2cpp.so", chuvaBalas, "\x0B\x00\xA0\xE3\x1E\xFF\x2F\xE1", 8);
    Patches.ChuvaBala11 = MemoryPatch("libil2cpp.so", chuvaBalas, "\x0C\x00\xA0\xE3\x1E\xFF\x2F\xE1", 8);
    Patches.ChuvaBala12 = MemoryPatch("libil2cpp.so", chuvaBalas, "\x0D\x00\xA0\xE3\x1E\xFF\x2F\xE1", 8);
    Patches.ChuvaBala13 = MemoryPatch("libil2cpp.so", chuvaBalas, "\x0E\x00\xA0\xE3\x1E\xFF\x2F\xE1", 8);
    Patches.ChuvaBala14 = MemoryPatch("libil2cpp.so", chuvaBalas, "\x0F\x00\xA0\xE3\x1E\xFF\x2F\xE1", 8);
    Patches.ChuvaBala15 = MemoryPatch("libil2cpp.so", chuvaBalas, "\x10\x00\xA0\xE3\x1E\xFF\x2F\xE1", 8);
    Patches.WallCarroUpd = MemoryPatch("libil2cpp.so", wallCarroUpd, "\x00\x00\xA0\xE3\x1E\xFF\x2F\xE1", 8);
    Patches.WallCarro = MemoryPatch("libil2cpp.so", wallCarro, "\x00\x00\xA0\xE3\x1E\xFF\x2F\xE1", 8);
    Patches.NightMod = MemoryPatch("libunity.so", modonoite, "\x00\x00\x80\xBF", 4);
    Patches.AntenaPro = MemoryPatch("libunity.so", antenaCorpo, "\x10\x40\x1C\x46", 4);
    Patches.CorpoHack1 = MemoryPatch("libil2cpp.so", corpoGrande, "\x81\x0F\x43\xE3\x1E\xFF\x2F\xE1", 8);
    Patches.CorpoHack2 = MemoryPatch("libil2cpp.so", corpoGrande, "\x82\x0F\x43\xE3\x1E\xFF\x2F\xE1", 8);
    Patches.CorpoHack3 = MemoryPatch("libil2cpp.so", corpoGrande, "\x83\x0F\x43\xE3\x1E\xFF\x2F\xE1", 8);
    Patches.CorpoHack4 = MemoryPatch("libil2cpp.so", corpoGrande, "\x84\x0F\x43\xE3\x1E\xFF\x2F\xE1", 8);
    Patches.CorpoHack5 = MemoryPatch("libil2cpp.so", corpoGrande, "\x85\x0F\x43\xE3\x1E\xFF\x2F\xE1", 8);
        Patches.SuperSpeed = MemoryPatch("libunity.so", antenaCorpo, "\x10\x40\x1C\x46", 4);
                Patches.Bypass = MemoryPatch("libtersafe.so", 0x1DEFF8, "\x00\x20\x70\x47", 4);
    Patches.WallPedra = MemoryPatch("libunity.so", zePedrinha, "\xC9\x3C\x8E\xBF\xC9\x3C\x8E\xBF\xC9\x3C\x8E\xBF\xC9\x3C\x8E\xBF", 16);
    
       HOOK(0xA3D2E4, _LateUpdate, LateUpdate);
       
       HOOK(0xBF408C, _ghost, orig_ghost);
       
    return NULL;
}




    // loop until our target library is found


JNIEXPORT jint JNICALL
JNI_OnLoad(JavaVM *vm, void *reserved) {
    JNIEnv *globalEnv;
    vm->GetEnv((void **) &globalEnv, JNI_VERSION_1_6);

    // Create a new thread so it does not block the main thread, means the game would not freeze
    pthread_t ptid;
    pthread_create(&ptid, NULL, hack_thread, NULL);

    return JNI_VERSION_1_6;
}

JNIEXPORT void JNICALL
JNI_OnUnload(JavaVM *vm, void *reserved) {}
