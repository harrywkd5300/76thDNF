#pragma once


enum STATE { DOOR, SKILL, PLAYER, MONSTER, BOSS, EFFECT, BUTTON, NPC, SHOP, UI, ICON, INVEN, ITEM, MOUSE, END };

enum Skillname { Arrow, Fireball, Buster, thunder, night, Shield, Firewall, Explosion, BossSkill1, BossSkill2, End };

enum EffectName {  bomb, spark, Finish };

enum UitName {  shop, inventory, Ui_end };

enum Scene { Logo, Menu, Edit, Stage, stage2, DGSel, DG1, DG2, Boss,  Ending };

enum RenderID { Render_BackGround, Render_Obj, Render_skill, Render_Effect, Render_BASE, Render_UI, Render_UI2, Render_End };

enum ItemState { CLOTH, PANTS, WEAPON, SHOSE, STATE_END };