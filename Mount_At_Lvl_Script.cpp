class Mount_At_Lvl_Script : public PlayerScript
{
public:
        Mount_At_Lvl_Script() : PlayerScript("Mount_At_Lvl_Script") { }
 
 
public:
        void OnLevelChanged(Player* player, uint8 newLevel)
        {
                // uint32 SpellID; Unused for this.
                switch (player->getLevel())
                {
                case 20: player->learnSpell(33388, true); break;
                case 40: player->learnSpell(33391, true); break;
                case 67: player->learnSpell(54197, true); break; // Cold Weather Flying- Not really important, but whatevz, right?
                case 70: player->learnSpell(34091, true); break;
                }
        }
};
 
void AddSC_Mount_At_Lvl_Script()
{
        new Mount_At_Lvl_Script();
}
