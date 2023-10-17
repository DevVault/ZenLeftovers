modded class PluginRecipesManagerBase extends PluginBase
{
	override void RegisterRecipies()
	{
		super.RegisterRecipies();

		if (GetLeftoversConfig().CraftJunkHookHP != -1)
		{
			RegisterRecipe(new CraftJunkHookRecipe); // Add junk hook recipe if enabled
		}
	}
}

class CraftJunkHookRecipe extends RecipeBase
{
	override void Init()
	{
		m_Name = "Craft fishing hook";
		m_IsInstaRecipe = false;//should this recipe be performed instantly without animation
		m_AnimationLength = 1.5;//animation length in relative time units
		m_Specialty = -0.02;// value > 0 for roughness, value < 0 for precision

		//conditions
		m_MinDamageIngredient[0] = -1;//-1 = disable check
		m_MaxDamageIngredient[0] = 3;//3 = badly damaged

		m_MinQuantityIngredient[0] = 1;//1 = minimum of 1 item
		m_MaxQuantityIngredient[0] = -1;//-1 = disable check

		m_MinDamageIngredient[1] = -1;//-1 = disable check
		m_MaxDamageIngredient[1] = 3;//3 = badly damaged

		m_MinQuantityIngredient[1] = -1;//-1 = disable check
		m_MaxQuantityIngredient[1] = -1;//-1 = disable check
		//----------------------------------------------------------------------------------------------------------------------

		//INGREDIENTS
		//ingredient 1 (junk)
		InsertIngredientEx(0, "Empty_SodaCan_Pipsi", "openBeanCan");//you can insert multiple ingredients this way
		InsertIngredientEx(0, "Empty_SodaCan_Cola", "openBeanCan");
		InsertIngredientEx(0, "Empty_SodaCan_Spite", "openBeanCan");
		InsertIngredientEx(0, "Empty_SodaCan_Kvass", "openBeanCan");
		InsertIngredientEx(0, "Empty_SodaCan_Fronta", "openBeanCan");
		InsertIngredientEx(0, "Empty_BakedBeansCan_Opened", "openBeanCan");
		InsertIngredientEx(0, "Empty_PeachesCan_Opened", "openBeanCan");
		InsertIngredientEx(0, "Empty_TacticalBaconCan_Opened", "openBeanCan");
		InsertIngredientEx(0, "Empty_SpaghettiCan_Opened", "openBeanCan");
		InsertIngredientEx(0, "Empty_UnknownFoodCan_Opened", "openBeanCan");
		InsertIngredientEx(0, "Empty_SardinesCan_Opened", "openBeanCan");
		InsertIngredientEx(0, "Empty_TunaCan_Opened", "openBeanCan");
		InsertIngredientEx(0, "Empty_DogFoodCan_Opened", "openBeanCan");
		InsertIngredientEx(0, "Empty_CatFoodCan_Opened", "openBeanCan");
		InsertIngredientEx(0, "Empty_PorkCan_Opened", "openBeanCan");
		InsertIngredientEx(0, "Empty_Lunchmeat_Opened", "openBeanCan");

		m_IngredientAddHealth[0] = 0;// 0 = do nothing
		m_IngredientSetHealth[0] = -1; // -1 = do nothing
		m_IngredientAddQuantity[0] = -1;// 0 = do nothing
		m_IngredientDestroy[0] = true;//true = destroy, false = do nothing
		m_IngredientUseSoftSkills[0] = false;// set 'true' to allow modification of the values by softskills on this ingredient

		//ingredient 2 (knives & tools)
		InsertIngredient(1, "Sickle");//you can insert multiple ingredients this way
		InsertIngredient(1, "KukriKnife");
		InsertIngredient(1, "FangeKnife");
		InsertIngredient(1, "Hacksaw");
		InsertIngredient(1, "HandSaw");
		InsertIngredient(1, "Hatchet");
		InsertIngredient(1, "Woodaxe");
		InsertIngredient(1, "FirefighterAxe");
		InsertIngredient(1, "KitchenKnife");
		InsertIngredient(1, "SteakKnife");
		InsertIngredient(1, "HayHook");
		InsertIngredient(1, "StoneKnife");
		InsertIngredient(1, "Cleaver");
		InsertIngredient(1, "CombatKnife");
		InsertIngredient(1, "HuntingKnife");
		InsertIngredient(1, "Machete");
		InsertIngredient(1, "CrudeMachete");
		InsertIngredient(1, "OrientalMachete");
		InsertIngredient(1, "Sword");
		InsertIngredient(1, "AK_Bayonet");
		InsertIngredient(1, "M9A1_Bayonet");
		InsertIngredient(1, "Mosin_Bayonet");
		InsertIngredient(1, "SKS_Bayonet");
		InsertIngredient(1, "BoneKnife");
		InsertIngredient(1, "Pliers");

		m_IngredientAddHealth[1] = -33;// 0 = do nothing
		m_IngredientSetHealth[1] = -1; // -1 = do nothing
		m_IngredientAddQuantity[1] = 0;// 0 = do nothing
		m_IngredientDestroy[1] = false;// false = do nothing
		m_IngredientUseSoftSkills[1] = true;// set 'true' to allow modification of the values by softskills on this ingredient
		//----------------------------------------------------------------------------------------------------------------------

		//result1
		AddResult("Hook");//add results here

		m_ResultSetFullQuantity[0] = false;//true = set full quantity, false = do nothing
		m_ResultSetQuantity[0] = -1;//-1 = do nothing
		m_ResultSetHealth[0] = 1; // Close to ruined
		m_ResultInheritsHealth[0] = -1;// (value) == -1 means do nothing; a (value) >= 0 means this result will inherit health from ingredient number (value);(value) == -2 means this result will inherit health from all ingredients averaged(result_health = combined_health_of_ingredients / number_of_ingredients)
		m_ResultInheritsColor[0] = -1;// (value) == -1 means do nothing; a (value) >= 0 means this result classname will be a composite of the name provided in AddResult method and config value "color" of ingredient (value)
		m_ResultToInventory[0] = -2;//(value) == -2 spawn result on the ground;(value) == -1 place anywhere in the players inventory, (value) >= 0 means switch position with ingredient number(value)
		m_ResultUseSoftSkills[0] = false;// set 'true' to allow modification of the values by softskills on this result
		m_ResultReplacesIngredient[0] = -1;// value == -1 means do nothing; a value >= 0 means this result will transfer item propertiesvariables, attachments etc.. from an ingredient value
	}
}