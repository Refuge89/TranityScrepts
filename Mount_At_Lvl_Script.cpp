class Mount_At_Lvl_Script : public PlayerScript
{
public:
	Mount_At_Lvl_Script() : PlayerScript("Mount_At_Lvl_Script") { }

	void OnLevelChanged(Player* player, uint8 newLevel)
	{
		uint32 SpellID;
		switch (player->getLevel())
		{
		case 20: SpellID = 33388; break;
		case 40: SpellID = 33391; break;
		case 67: SpellID = 54197; break; // Cold Weather Flying- Not really important, but whatevz, right?
		case 70: SpellID = 34091; break;
		default: return;
		}
		player->learnSpell(SpellID, true);
	}
};

void AddSC_Mount_At_Lvl_Script()
{
	new Mount_At_Lvl_Script();
}
