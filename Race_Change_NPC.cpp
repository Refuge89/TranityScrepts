class Race_Change_NPC : public CreatureScript
{
public:
	Race_Change_NPC() : CreatureScript("Race_Change_NPC") {  }
	
	bool OnGossipHello(Player * player, Creature * creature)
	{
		player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, "*Take a whiff of the chloroform*", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 1);
		player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, "I think I'll pass..", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 2);
		player->PlayerTalkClass->SendGossipMenu(1, creature->GetGUID());
		return true;
	}
	bool OnGossipSelect(Player * player, Creature * creature, uint32 sender, uint32 action){
		player->PlayerTalkClass->ClearMenus();
		if (sender != GOSSIP_SENDER_MAIN)
			return false;
		switch (action){
		case GOSSIP_ACTION_INFO_DEF + 1:
			player->SetAtLoginFlag(AT_LOGIN_CHANGE_RACE);
			player->GetSession()->KickPlayer();
			player->PlayerTalkClass->SendCloseGossip();
			break;
		case GOSSIP_ACTION_INFO_DEF +2:
			player->PlayerTalkClass->SendCloseGossip();
			break;
		}
		return true;
	}
};

void AddSC_Race_Change_NPC()
{
	new Race_Change_NPC();
}
