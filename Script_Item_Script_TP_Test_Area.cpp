#include "ScriptMgr.h"
#include "Player.h"


class Script_Item_Script_TP_Test_Area : public ItemScript
{
public:
	Script_Item_Script_TP_Test_Area() : ItemScript("Script_Item_Script_TP_Test_Area"){ }
		bool OnUse(Player* player, /*player*/ Item* /*item*/, SpellCastTargets const& /*targets*/) override
	{
		player->TeleportTo(0, -11119.131836f, -2010.953003f, 47.082821f, 0.715869f);
		return true;
	}
};

void AddSC_Script_TP_Item()
{
	new Script_Item_Script_TP_Test_Area();
}
