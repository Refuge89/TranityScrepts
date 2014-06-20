#include "ScriptPCH.h"
class Level_up_Mob : public CreatureScript
{
public:
	Level_up_Mob() : CreatureScript("Level_up_Mob"){ }
	bool OnGossipHello(Player * player, Creature * creature){
		player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, "Level me up, Scotty!", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 1);
		player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, "Nevermind.", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 2);
		player->PlayerTalkClass->SendGossipMenu(1, creature->GetGUID());
		return true;
	}
	bool OnGossipSelect(Player * player, Creature * creature, uint32 sender, uint32 action){
		player->PlayerTalkClass->ClearMenus();
		if (sender != GOSSIP_SENDER_MAIN)
			return false;
		switch (action){
		case GOSSIP_ACTION_INFO_DEF + 1:
			player->GiveXP(3630600, player);
			player->SetFlag(PLAYER_FLAGS, PLAYER_FLAGS_NO_XP_GAIN);
			//player->GetSession()->KickPlayer();
			player->PlayerTalkClass->SendCloseGossip();
			break;
		case GOSSIP_ACTION_INFO_DEF + 2:
			//chathandler->SendSysMessage("You don't want to be level 60? I'm sorry to hear.");
			player->PlayerTalkClass->SendCloseGossip();
			break;
		}
		return true;
	}
};
void AddSC_Level_up_Mob()
{
	new Level_up_Mob();
}
