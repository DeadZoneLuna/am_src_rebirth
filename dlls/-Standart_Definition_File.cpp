

//	x	  x
//	X	  X		   XXXXXXX						X
//	  X   X			X	XXXXXXX	XXXXXXX	XXXXXXX	XXXXXXX 
// 	    X		XXXX		X  	X  X		X	X	X	X	X  X	
// 	  X   X			X	XX		X	X	X	X	XX	
//	X	 x			x	x		x		x		x
//	X	  X			X	XXXXXXX	X	X	XXXXXXX	XXXXXXX
//	
// Arrange Mode game definition file (.fgd) 
// Version 1.0.9 by X-TENDER
// Coding by SysOp
// For Worldcraft - Valve Hammer Editor 3.3 or above
// Last update: 29/03/07
//
// Updated by Xtender
// xtender@arrangemode.com.ar
//
// Arrange Mod contact:
// Web:
// http://www.arrangemode.com.ar
// http://www.arrangemode.com.tk 
//
//
// 0427 - version 3.40
//

//
// worldspawn
//


/*
@SolidClass = worldspawn : "World entity"
[
	message(string) : "Map Description / Title"
	skyname(string) : "environment map (cl_skyname)"
	sounds(integer) : "CD track to play" : 1
	light(integer) : "Default light level"
	WaveHeight(string) : "Default Wave Height"
	MaxRange(string) : "Max viewable distance" : "99999"//hack
	chaptertitle(string) : "Chapter Title Message"
	startdark(choices) : "Level Fade In" : 0 =
	[	
		0 : "No"
		1 : "Yes"
	]
	gametitle(choices) : "Display game title" : 0 = 
	[	
		0 : "No"
		1 : "Yes"
	]
	newunit(choices) : "New Level Unit" : 0 = 
	[
		0 : "No, keep current"
		1 : "Yes, clear previous levels"
	]
	mapteams(string) : "Map Team List"
	defaultteam(choices) : "Default Team" : 0 = 
	[
		0 : "Fewest Players"
		1 : "First Team"
	]
	startsuit(choices) : "HUD from start" =
	[
		0 : "No"
		1 : "Yes"
	]
	startflash(choices) : "FlashLight from start" =
	[
		0 : "No"
		1 : "Yes"
	]
]

@BaseClass = ZHLT
[
	zhlt_lightflags(choices) : "ZHLT Lightflags" : 0 =
	[
		0 : "Default"
		1 : "Embedded Fix"
		2 : "Opaque (blocks light)"
		3 : "Opaque + Embedded fix" 		6 : "Opaque + Concave Fix"
	]
	light_origin(string) : "Light Origin Target"
]

@BaseClass = ZHLT_point
[
	_fade(string) : "ZHLT Fade" : "1.0"
	_falloff(choices) : "ZHLT Falloff" : 0 =
	[
		0 : "Default"
		1 : "Inverse Linear"
		2 : "Inverse Square"
	]
]

@BaseClass = Angles
[
	angles(string) : "Pitch Yaw Roll (Y Z X)" : "0 0 0"
]

//
// BaseClasses
//

@BaseClass = Appearflags
[
	spawnflags(Flags) =
	[
		2048 : "Not in Deathmatch" : 0
	]
]

@BaseClass size(0 0 0, 32 32 32) color(80 0 200) base(Appearflags) = Ammo []

@BaseClass = Targetname 
[ 
	targetname(target_source) : "Name"
]
@BaseClass = Target 
[ 
	target(target_destination) : "Target" 
]
@BaseClass size(-16 -16 0, 16 16 32) color(0 0 200) base(Targetname, Appearflags) = Weapon []
@BaseClass = Global 
[ 
	globalname(string) : "Global Entity Name" 
]

@BaseClass base(Target) = Targetx 
[
	delay(string) : "Delay before trigger" : "0"
	killtarget(target_destination) : "KillTarget"
]

@BaseClass = RenderFxChoices
[
	renderfx(choices) :"Render FX" : 0 =
	[
		0: "Normal"
		1: "Slow Pulse"
		2: "Fast Pulse"
		3: "Slow Wide Pulse"
		4: "Fast Wide Pulse"
		9: "Slow Strobe"
		10: "Fast Strobe"
		11: "Faster Strobe"
		12: "Slow Flicker"
		13: "Fast Flicker"
		5: "Slow Fade Away"
		6: "Fast Fade Away"
		7: "Slow Become Solid"
		8: "Fast Become Solid"
		14: "Constant Glow"
		15: "Distort"
		16: "Hologram (Distort + fade)"
		17: "-Efecto 1"
		18: "-Efecto 2"
		19: "-Efecto de brillo desconocido"
		255: "Modelo sin sombras"
	]
]

@BaseClass base(RenderFxChoices) = RenderFields 
[
	rendermode(choices) : "Render Mode" : 0 =
	[
		0: "Normal"
		1: "Color"
		2: "Texture"
		3: "Glow"
		4: "Solid"
		5: "Additive"
	]
	renderamt(choices): "FX Amount (0 - 255)" : 0 =
	[
		0: "Ninguna: 0"
		50: "50"
		100: "100"
		150: "150"
		200: "200"
		255: "Transparencia: 255"
	]
	rendercolor(color255) : "FX Color (R G B)" : "0 0 0"
]

@BaseClass base(Appearflags) size(-16 -16 -36, 16 16 36) color(0 255 0) = PlayerClass []

@BaseClass base(Target, Targetname, RenderFields) color(0 200 200) = Monster 
[
	TriggerTarget(String) : "TriggerTarget"
      TriggerCondition(Choices) : "Trigger Condition" : 0 =
	[
		0 : "No Trigger"
		1 : "See Player, Mad at Player"
		2 : "Take Damage"
		3 : "50% Health Remaining"
		4 : "Death"
		7 : "Hear World"
		8 : "Hear Player"
		9 : "Hear Combat"
		10: "See Player Unconditional"
		11: "See Player, Not In Combat"
		12: "Surrender (only Terrorists)"
	]
	spawnflags(Flags) = 
	[
		1 : "WaitTillSeen" 	: 0
		2 : "Gag"		: 0
		4 : "MonsterClip"	: 0
		16: "Prisoner"		: 0
		128: "WaitForScript" 	: 0
		256: "Pre-Disaster" 	: 0
		512: "Fade Corpse"	: 0
	]
]
@BaseClass = MonsterCH 
[
	health(integer) : "Energia (0= normal)"
	m_iClass(choices) : "Reaccion a los demas" : 0 =
	[
		0 : "Normal"
		3 : "Scientist"
		11: "Barney"
		4 : "Human Military"
		1 : "Machine (Human Military)"
		5 : "Alien Military"
		7 : "Other Alien"
		8 : "Headcrab"
		9 : "Bullsquid"
		14 : "Faction A"
		15 : "Faction B"
		16 : "Faction C"
	]
	m_iPlayerReact(choices) : "Reaccion frente al jugador" : 0 =
	[
		0 : "Normal"
		1 : "Ignorarlo"
		//* Scientists usually use this behaviour.
		2 : "Amigo sin ser herido (SCI)"
		//* Barneys usually use this behaviour.
		3 : "Amigo sin ser provocado (BA)"
		4 : "Enemigo"
		// Not yet implemented, but will allow any monster to act like a barney/scientist.
		//5 : "Follower"
	]
	model(studio) : "Modelo (e.g. models/can.mdl)"

	skin(choices) : "Skin" : 0 =
	[
		-1 : "Al Azar"
		0 : "Skin 0 (Defecto)"
		1 : "Skin 1"
		2 : "Skin 2"
		3 : "Skin 3"
	]
]
@BaseClass base(Targetname, Angles, RenderFields, Appearflags) color(0 200 200) = MonsterBa 
[
	//NEW 0.7.1
	health(integer) : "Initial health (0 = normal)"
	//NEW 0.7.1
	//* Be careful when changing this - a monster's actions are tied closely to its model.
	model(studio) : "Model (e.g. models/can.mdl)"
	//NEW 0.4
	//* If you just want a monster to be ignored, use the "Prisoner" flag instead.
	m_iClass(choices) : "Behave as" : 0 =
	[
		0 : "Normal"
		//* Likes players and barneys; hates Human Military and most aliens; scared of Alien Military and Bullsquids.
		3 : "Scientist"
		//* Likes players and scientists; dislikes Machines, Human Military, and all aliens.
		11: "Barney"
		//* Dislikes scientists and most aliens. Hates players, barneys and Alien Military.
		4 : "Human Military"
		//* Machines go clang when hit, and never gib. Bioweapons (Snarks and Hornets) ignore them.
		//* Otherwise, they're pretty much like Human Military.
		1 : "Machine (Human Military)"
		//* Hates players and Human Military. Dislikes Machines, scientists and barneys.
		5 : "Alien Military"
		//* Dislikes Machines and all humans.
		7 : "Other Alien"
		//* Dislikes all humans. Scared of Bullsquids.
		8 : "Headcrab"
		//* Hates Headcrabs. Dislikes humans and other Bullsquids.
		9 : "Bullsquid"
		//* Dislikes everyone, except other Faction A members.
		14 : "Faction A"
		//* Dislikes everyone, except other Faction B members.
		15 : "Faction B"
		//* Dislikes everyone, except other Faction C members.
		16 : "Faction C"
	]
	//NEW 0.5
	//* Replaces the old "Player Ally" flag.
	m_iPlayerReact(choices) : "Reaction to player" : 0 =
	[
		0 : "Normal"
		1 : "Ignore"
		//* Scientists usually use this behaviour.
		2 : "Friendly until hurt"
		//* Barneys usually use this behaviour.
		3 : "Friendly unless provoked"
		4 : "Enemy"
		// Not yet implemented, but will allow any monster to act like a barney/scientist.
		//5 : "Follower"
	]
	TriggerTarget(String) : "TriggerTarget"
      TriggerCondition(Choices) : "Trigger Condition" =
	[
		0 : "No Trigger"
		1 : "See Player, Mad at Player"
		2 : "Take Damage"
		3 : "50% Health Remaining"
		4 : "Death"
		7 : "Hear World"
		8 : "Hear Player"
		9 : "Hear Combat"
		10: "See Player Unconditional"
		11: "See Player, Not In Combat"
	]
	spawnflags(Flags) = 
	[
		//* Don't attack the player until s/he can see us.
		1 : "WaitTillSeen" 	: 0
		//* Don't speak except when in combat. Don't make "idle" noises.
		2 : "Gag"			: 0
		//* If ticked, the monster can't enter a func_monsterclip area.
		4 : "Monster Clip"	: 0
		//* If ticked, the monster will ignore all other monsters and vice versa.
		16: "Prisoner"		: 0
		//NEW 0.4
		//* The dreaded yellow blobs appear for a good reason; they show a monster is stuck
		//* in a wall and unable to move. Only tick this if you're happy for it to be stuck.
		128: "No yellow blobs"  : 0
		512: "Fade Corpse"	: 0
	]
]
@BaseClass = TalkMonsterBa
[
	//* The sentence (see sound/sentences.txt) to speak when the player tells us to follow.
	UseSentence(String) : "Use Sentence"
	//* The sentence to speak when the player tells us to stop following.
	UnUseSentence(String) : "Un-Use Sentence"
	//NEW 0.4
	//* The sentence to speak when refusing to follow the player.
	RefusalSentence(String) : "Refusal Sentence"
	//NEW 0.4
	//* While locked by the master, this monster will refuse to follow the player.
	master(String) : "Master (prevents following)"
	//NEW 0.4
	//* Mostly provided for mod-makers. In the standard sentences.txt, valid settings for
	//* this are BA (speak as a Barney) and SC (speak as a Scientist). To define a
	//* speech group "XX", you need to define sentences XX_ANSWER, XX_QUESTION, XX_IDLE,
	//* XX_STARE, XX_OK, XX_WAIT, XX_STOP, XX_NOSHOOT, XX_HELLO, XX_SMELL, XX_WOUND and
	//* XX_MORTAL. (as well as some others, if the monsters are going to be Pre-Disaster.)
	//SpeakAs(string) : "Speech Group"
	SpeakAs(choices) : "Hablar como -XX_...-" : "" =
	[
		"BA" : 	"Barney Voice"
		"SC": 	"Scientist Voice"
		"HOS1": 	"Male Voice"
		"FEM": 	"Female Voice"
		"FG": 	"Grunt Ally"
		"HGPI" : 	"OTIS Voice"
		"": 	"Default Voice"
	]
	spawnflags(Flags) =
	[
		//* Unless given a Master, a pre-disaster monster will refuse to follow the player.
		256: "Pre-Disaster" 	: 0
	]
]

@BaseClass = TalkMonster
[
	UseSentence(String) : "Use Sentence"
	UnUseSentence(String) : "Un-Use Sentence"
]

@BaseClass size(-16 -16 -16, 16 16 16) = gibshooterbase
[
	targetname (target_source) : "Name"

	// how many pieces to create
	m_iGibs(integer) : "Number of Gibs" : 3
	
	// delay (in seconds) between shots. If 0, all gibs shoot at once.
	delay(string) : "Delay between shots" : "0"

	// how fast the gibs are fired
	m_flVelocity(integer) : "Gib Velocity" : 200

	// Course variance
	m_flVariance(string) : "Course Variance" : "0.15"

	// Time in seconds for gibs to live +/- 5%
	m_flGibLife(string) : "Gib Life" : "4"

	spawnflags(Flags) = 
	[
		1 : "Repeatable" 	: 0
	]
]

@BaseClass = Light 
[
	_light(color255) : "Brightness" : "255 255 128 200"
      style(Choices) : "Appearance" : 0 =
	[
		0 : "Normal"
		10: "Fluorescent flicker"
		2 : "Slow, strong pulse"
		11: "Slow pulse, noblack"
		5 : "Gentle pulse"
		1 : "Flicker A"
		6 : "Flicker B"
		3 : "Candle A"
		7 : "Candle B"
		8 : "Candle C"
		4 : "Fast strobe"
		9 : "Slow strobe"
	]
	pattern(string) : "Custom Appearance"
]

@BaseClass base(Targetname,Global) = Breakable
[
	target(target_destination) : "Target on break"
	health(integer) : "Strength" : 1
	material(choices) :"Material type" : 0 =
	[
		0: "Glass"
		1: "Wood"
		2: "Metal"
		3: "Flesh"
		4: "Cinder Block"  
		5: "Ceiling Tile"
		6: "Computer"
		7: "Unbreakable Glass"
		8: "Rocks"
	]
	explosion(choices) : "Gibs Direction" : 0 =
	[
		0: "Random"
		1: "Relative to Attack"
	]
	delay(string) : "Delay before fire" : "0"
	gibmodel(studio) : "Gib Model" : ""
	spawnobject(choices) : "Spawn On Break" : 0 =
	[
		0: "Nothing"
		1: "Battery"
		2: "Healthkit"
		3: "9mm Handgun"
		4: "9mm Clip"
		5: "Machine Gun"
		6: "Machine Gun Clip"
		7: "Machine Gun Grenades"
		8: "Shotgun"
		9: "Shotgun Shells"
		10: "Crossbow"
		11: "Crossbow Bolts"
		12: "357"
		13: "357 clip"
		14: "RPG"
		15: "RPG Clip"
		16: "Gauss clip"
		17: "Hand grenade"
		18: "Tripmine"
		19: "Satchel Charge"
		20: "Snark"
		21: "Hornet Gun"
		22: "Brown Coin 1 XP"	// 22
		23: "Plate Coin 5 XP"	// 23
		24: "Gold Coin 10 XP"	// 24
	]
	explodemagnitude(integer) : "Explode Magnitude (0=none)" : 0
	speed(choices) : "Delay before Explode" : 0 =
	[
		-1: "Random (0.5 to 3)"
		0: "No delay"
		1: "1 Second"
		2: "2 Seconds"
		3: "3 Seconds"
		4: "4 Seconds"
		5: "5 Seconds"
		6: "6 Seconds"
		7: "7 Seconds"
		8: "8 Seconds"
		9: "9 Seconds"
		10: "10 Seconds"
	]
]

@BaseClass base(Appearflags, Targetname, RenderFields, Global) = Door
[
	killtarget(target_destination) : "KillTarget"
	speed(integer) : "Speed" : 100
	master(string) : "Master" 
	movesnd(choices) : "Move Sound" : 0 = 
	[
		0: "No Sound"
		1: "Servo (Sliding)"
		2: "Pneumatic (Sliding)"
		3: "Pneumatic (Rolling)"
		4: "Vacuum"
		5: "Power Hydraulic"
		6: "Large Rollers"
		7: "Track Door"
		8: "Snappy Metal Door"
		9: "Squeaky 1"
		10: "Squeaky 2"
	]
	stopsnd(choices) : "Stop Sound" : 0 = 
	[
		0: "No Sound"
		1: "Clang with brake"
		2: "Clang reverb"
		3: "Ratchet Stop"
		4: "Chunk"
		5: "Light airbrake"
		6: "Metal Slide Stop"
		7: "Metal Lock Stop"
		8: "Snappy Metal Stop"
	]
	wait(integer) : "delay before close, -1 stay open " : 4
	lip(integer) : "Lip"
	dmg(integer) : "Damage inflicted when blocked" : 0
	message(string) : "Message if triggered"
	target(target_destination) : "Target"
	delay(integer) : "Delay before fire" 
	netname(string) : "Fire on Close"
	health(integer) : "Health (shoot open)" : 0
	spawnflags(flags) =
	[
		1 : "Starts Open" : 0
		4 : "Don't link" : 0
		8: "Passable" : 0
	    	32: "Toggle" : 0
		256:"Use Only" : 0
		512: "Monsters Can't" : 0
	]
	// NOTE: must be duplicated in BUTTON
	locked_sound(choices) : "Locked Sound" : 0 = 
	[
		0: "None"
		2: "Access Denied"
		8: "Small zap"
		10: "Buzz"
		11: "Buzz Off"
		12: "Latch Locked"
	]
	unlocked_sound(choices) : "Unlocked Sound" : 0 = 
	[
		0: "None"
		1: "Big zap & Warmup"
		3: "Access Granted"
		4: "Quick Combolock"
		5: "Power Deadbolt 1"
		6: "Power Deadbolt 2"
		7: "Plunger"
		8: "Small zap"
		9: "Keycard Sound"
		10: "Buzz"
		13: "Latch Unlocked"
	]
	locked_sentence(choices) : "Locked Sentence" : 0 = 
	[
		0: "None"
		1: "Gen. Access Denied"
		2: "Security Lockout"
		3: "Blast Door"
		4: "Fire Door"
		5: "Chemical Door"
		6: "Radiation Door"
		7: "Gen. Containment"
		8: "Maintenance Door"
		9: "Broken Shut Door"
	]
	unlocked_sentence(choices) : "Unlocked Sentence" : 0 = 
	[
		0: "None"
		1: "Gen. Access Granted"
		2: "Security Disengaged"
		3: "Blast Door"
		4: "Fire Door"
		5: "Chemical Door"
		6: "Radiation Door"
		7: "Gen. Containment"
		8: "Maintenance area"
	]	
	_minlight(string) : "Minimum light level"
]

@BaseClass base(Targetname, Target, RenderFields, Global) = BaseTank
[
	spawnflags(flags) =
	[
		1 : "Active" : 0
		16: "Only Direct" : 0
		32: "Controllable" : 0
	]

	// Mainly for use with 1009 team settings (game_team_master)
	master(string) : "(Team) Master" 

	yawrate(string) : "Yaw rate" : "30"
	yawrange(string) : "Yaw range" : "180"
	yawtolerance(string) : "Yaw tolerance" : "15"
	pitchrate(string) : "Pitch rate" : "0"
	pitchrange(string) : "Pitch range" : "0"
	pitchtolerance(string) : "Pitch tolerance" : "5"
	barrel(string) : "Barrel Length" : "0"
	barrely(string) : "Barrel Horizontal" : "0"
	barrelz(string) : "Barrel Vertical" : "0"
	spritesmoke(string) : "Smoke Sprite" : ""
	spriteflash(string) : "Flash Sprite" : ""
	spritescale(string) : "Sprite scale" : "1"
	rotatesound(sound) : "Rotate Sound" : ""
	firerate(string) : "Rate of Fire" : "1"
	bullet_damage(string) : "Damage Per Bullet" : "0"
	persistence(string) : "Firing persistence" : "1"
	firespread(choices) : "Bullet accuracy" : 0 =
	[
		0: "Perfect Shot"
		1: "Small cone"
		2: "Medium cone"
		3: "Large cone"
		4: "Extra-large cone"
	]
	minRange(string) : "Minmum target range" : "0"
	maxRange(string) : "Maximum target range" : "0"
	_minlight(string) : "Minimum light level"
] 
@BaseClass = PlatSounds 
[
	movesnd(choices) : "Move Sound" : 0 = 
	[
		0: "No Sound"
		1: "big elev 1"
		2: "big elev 2"
		3: "tech elev 1"
		4: "tech elev 2"
		5: "tech elev 3"
		6: "freight elev 1"
		7: "freight elev 2"
		8: "heavy elev" 		9: "rack elev"
		10: "rail elev"
		11: "squeek elev"
		12: "odd elev 1"
		13: "odd elev 2"
	]
	stopsnd(choices) : "Stop Sound" : 0 = 
	[
		0: "No Sound"
		1: "big elev stop1"
		2: "big elev stop2"
		3: "freight elev stop"
		4: "heavy elev stop"
		5: "rack stop"
		6: "rail stop"
		7: "squeek stop"
		8: "quick stop"
	]
	volume(string) : "Sound Volume 0.0 - 1.0" : "0.85"
]

@BaseClass base(Targetname, RenderFields, Global, PlatSounds) = Trackchange
[
	height(integer) : "Travel altitude" : 0
	spawnflags(flags) =
	[
		1: "Auto Activate train" : 0
		2: "Relink track" : 0
		8: "Start at Bottom" : 0
		16: "Rotate Only" : 0
		64: "X Axis" : 0
		128: "Y Axis" : 0
	]
	rotation(integer) : "Spin amount" : 0
	train(target_destination) : "Train to switch"
	toptrack(target_destination) : "Top track"
	bottomtrack(target_destination) : "Bottom track"
	speed(integer) : "Move/Rotate speed" : 0
]

@BaseClass base(Target, Targetname) = Trigger
[
	killtarget(target_destination) : "Kill target"
	netname(target_destination) : "Target Path"
	master(string) : "Master" 
	sounds(choices) : "Sound style" : 0 =
	[
		0 : "No Sound"
	]
	delay(string) : "Delay before trigger" : "0"
	message(string) : "Message (set sound too!)"
	spawnflags(flags) = 
	[
		1: "Monsters" : 0
		2: "No Clients" : 0
		4: "Pushables": 0
	]
]

//
// Entities
//


@PointClass base(Targetname) size(-16 -16 -16, 16 16 16) = monstermaker : "Monster Maker"
[
	target(string) : "Target On Release" 
	monstertype(string) : "Monster Type"

//	monstertype(choices) : "Monster Type" : "monster_zombie" =
//	[
//		"monster_alien_slave" : "Zombie Barney"
//		"monster_human_grunt" : "monster_human_grunt"
//		"monster_human_grunt" : "monster_human_grunt"
//		"monster_human_grunt_opfor" : "monster_human_grunt_opfor"
//		"monster_houndeye" : "monster_houndeye"
//		"monster_zombie" : "monster_zombie"
//		"monster_zombie_barney" : "monster_zombie_barney"
//		"monster_zombie_soldier" : "monster_zombie_soldier"
//	] 
	netname(string) : "Childrens' Name"
	spawnflags(Flags) = 
	[
		1 : "Start ON" 	: 1
		4 : "Cyclic" : 0
		8 : "MonsterClip" : 0
		1024: "No tirar Arma (si posee)" : 0
	]

	// how many monsters the monstermaker can create (-1 = unlimited)
	monstercount(integer) : "Number of Monsters" : 1
	
	// if delay is -1, new monster will be made when last monster dies.
	// else, delay is how often (seconds) a new monster will be dookied out.
	delay(string) : "Frequency" : "2"

	// maximum number of live children allowed at one time. (New ones will not be made until one dies)
	// -1 no limit
	m_imaxlivechildren(integer) : "Max live children" : 5


	model(studio) : "Custom Model"
	health(integer) : "Custom Health" : 100
	weapons(Choices) : "Monster Custom Weapons" : 1 =
	[
		1 : "AR/AK47/MP7"
		3 : "AR/AK47/MP7 + HG"
		5 : "AR/AK47/MP7 + GL"
		8 : "Shotgun/Sniper Rifle"
		10 : "Shotgun/Sniper Rifle + HG"
		16 : "SAW/M249/IRGUN"
		18 : "SAW/M249/IRGUN + HG"
	]
	frags (Choices) : "Terrorists/Agency Members Weapons" : 1 =
	[	
		1 : "MP5/MP5-SD2"
		2 : "SPAS12"
		3 : "LAW"
		4 : "Sig3000"
		5 : "Assault Rifle"
		6 : "Handgun"
		7 : "Desert Eagle"
		8 : "M249"
	]

	skin(choices) : "Custom SKIN" : 0 =
	[
		0 : "Normal"
		1 : "SKIN 1"
		2 : "SKIN 2"
		3 : "SKIN 3"
		4 : "SKIN 4"

	]
	m_iClass(choices) : "Monsters behave as" : 0 =
	[
		0 : "Normal"
		3 : "Scientist"
		11: "Barney"
		4 : "Human Military"
		1 : "Machine (Human Military)"
		5 : "Alien Military"
		7 : "Other Alien"
		8 : "Headcrab"
		9 : "Bullsquid"
		14 : "Faction A"
		15 : "Faction B"
		16 : "Faction C"
	]
	m_iPlayerReact(choices) : "Monsters reaction to player" : 0 =
	[
		0 : "Normal"
		1 : "Ignore"
		2 : "Friendly until hurt"
		3 : "Friendly unless provoked"
		4 : "Enemy"
	]
	TriggerTarget(String) : "AI Trigger Target"
     	TriggerCondition(Choices) : "AI Trigger Condition" =
	[
		0 : "No Trigger"
		1 : "See Player, Mad at Player"
		2 : "Take Damage"
		3 : "50% Health Remaining"
		4 : "Death"
		7 : "Hear World"
		8 : "Hear Player"
		9 : "Hear Combat"
		10: "See Player Unconditional"
		11: "See Player, Not In Combat"
	]
]

@PointClass iconsprite("sprites/am/multi_manager.spr") base(Targetname) color(255 128 0) = multi_manager : "MultiTarget Manager" 
[
	spawnflags(Flags) = 
	[
		1 : "multithreaded" : 0
	]
]

@PointClass iconsprite("sprites/am/multisource.spr") base(Targetname, Target) color(128 255 128) = multisource : "Multisource"
[
	globalstate(string) : "Global State Master"
]

@PointClass base(Targetname, Targetx) size(-16 -16 0, 16 16 72) color(255 0 255) = aiscripted_sequence : "AI Scripted Sequence"
[
	m_iszEntity(string) : "Target Monster"
	m_iszPlay(string) : "Action Animation" : ""
	m_flRadius(integer) : "Search Radius" : 512
	m_flRepeat(integer) : "Repeat Rate ms" : 0
	m_fMoveTo(Choices) : "Move to Position" : 0 =
	[
		0 : "No"
		1 : "Walk"
		2 : "Run"
		4 : "Instantaneous"
		5 : "No - Turn to Face"
	]
	m_iFinishSchedule(Choices) : "AI Schedule when done" : 0 =
	[
		0 : "Default AI"
		1 : "Ambush"
	]
	spawnflags(Flags) = 
	[
		4 : "Repeatable"		: 0
		8 : "Leave Corpse"	: 0
		256: "Monster Die Anim" : 0
	]
]

@PointClass iconsprite("sprites/speaker.spr") base(Targetname) = ambient_generic : "Universal Ambient"
[
	message(sound) : "WAV Name"
	health(integer) : "Volume (10 = loudest)" : 10
	preset(choices) :"Dynamic Presets" : 0 =
	[ 		0: "None"
		1: "Huge Machine"
		2: "Big Machine"
		3: "Machine"
		4: "Slow Fade in"  
		5: "Fade in"
		6: "Quick Fade in"
		7: "Slow Pulse"
		8: "Pulse"
		9: "Quick pulse"
		10: "Slow Oscillator"
		11: "Oscillator"
		12: "Quick Oscillator"
		13: "Grunge pitch"
		14: "Very low pitch"
		15: "Low pitch"
		16: "High pitch"
		17: "Very high pitch"
		18: "Screaming pitch"
		19: "Oscillate spinup/down"
		20: "Pulse spinup/down"
		21: "Random pitch"
		22: "Random pitch fast"
		23: "Incremental Spinup"
		24: "Alien"
		25: "Bizzare"
		26: "Planet X"
		27: "Haunted"
	]
	volstart(integer) : "Start Volume" : 0
	fadein(integer) : "Fade in time (0-100)" : 0
	fadeout(integer) : "Fade out time (0-100)" : 0
	pitch(integer) : "Pitch (> 100 = higher)" : 100
	pitchstart(integer) : "Start Pitch" : 100
	spinup(integer) : "Spin up time (0-100)" : 0
	spindown(integer) : "Spin down time (0-100)" : 0
	lfotype(integer) : "LFO type 0)off 1)sqr 2)tri 3)rnd" : 0
	lforate(integer) : "LFO rate (0-1000)" : 0
	lfomodpitch(integer) : "LFO mod pitch (0-100)" : 0
	lfomodvol(integer) : "LFO mod vol (0-100)" : 0
	cspinup(integer) : "Incremental spinup count" : 0
	spawnflags(flags) =
	[
		1: "Play Everywhere (todos lados)" : 0
		2: "Small Radius (800 units)" : 0
		4: "Medium Radius (1250 units)" : 1
		8: "Large Radius (2000 units)" : 0
		16:"Start Silent":0
		32:"Is NOT Looped":0
	]
]

//
// ammo
//




@SolidClass base(Target) = button_target : "Target Button"
[
	spawnflags(flags) =
	[ 		1: "Use Activates" : 1
		2: "Start On" : 0
	]
	master(string) : "Master" 
	renderfx(choices) :"Render FX" : 0 =
	[
		0: "Normal"
		1: "Slow Pulse"
		2: "Fast Pulse"
		3: "Slow Wide Pulse"
		4: "Fast Wide Pulse"
		9: "Slow Strobe"
		10: "Fast Strobe"
		11: "Faster Strobe"
		12: "Slow Flicker"
		13: "Fast Flicker"
		5: "Slow Fade Away"
		6: "Fast Fade Away"
		7: "Slow Become Solid"
		8: "Fast Become Solid"
		14: "Constant Glow"
		15: "Distort"
		16: "Hologram (Distort + fade)"
	]
	rendermode(choices) : "Render Mode" : 0 =
	[
		0: "Normal"
		1: "Color"
		2: "Texture"
		3: "Glow"
		4: "Solid"
		5: "Additive"
	]
	renderamt(integer) : "FX Amount (1 - 255)"
	rendercolor(color255) : "FX Color (R G B)" : "0 0 0"
]


//
// cyclers
//

@PointClass base(Targetname) size(-16 -16 0, 16 16 72) = cycler : "Monster Cycler" 
[
	model(studio) : "Model"
	renderfx(choices) :"Render FX" : 0 =
	[
		0: "Normal"
		1: "Slow Pulse"
		2: "Fast Pulse"
		3: "Slow Wide Pulse"
		4: "Fast Wide Pulse"
		9: "Slow Strobe"
		10: "Fast Strobe"
		11: "Faster Strobe"
		12: "Slow Flicker"
		13: "Fast Flicker"
		5: "Slow Fade Away"
		6: "Fast Fade Away"
		7: "Slow Become Solid"
		8: "Fast Become Solid"
		14: "Constant Glow"
		15: "Distort" 		16: "Hologram (Distort + fade)"
	]
	rendermode(choices) : "Render Mode" : 0 =
	[
		0: "Normal"
		1: "Color"
		2: "Texture"
		3: "Glow"
		4: "Solid"
		5: "Additive"
	]
	renderamt(integer) : "FX Amount (1 - 255)"
	rendercolor(color255) : "FX Color (R G B)" : "0 0 0"
]

@PointClass base(Targetname) sprite() = cycler_sprite : "Sprite Cycler" 
[
	model(sprite) : "Sprite"
	framerate(integer) : "Frames per second" : 10
	renderfx(choices) :"Render FX" : 0 =
	[
		0: "Normal"
		1: "Slow Pulse"
		2: "Fast Pulse"
		3: "Slow Wide Pulse"
		4: "Fast Wide Pulse"
		9: "Slow Strobe"
		10: "Fast Strobe"
		11: "Faster Strobe"
		12: "Slow Flicker"
		13: "Fast Flicker"
		5: "Slow Fade Away"
		6: "Fast Fade Away"
		7: "Slow Become Solid"
		8: "Fast Become Solid"
		14: "Constant Glow"
		15: "Distort"
		16: "Hologram (Distort + fade)"
	]
	rendermode(choices) : "Render Mode" : 0 =
	[
		0: "Normal"
		1: "Color"
		2: "Texture"
		3: "Glow"
		4: "Solid"
		5: "Additive"
	]
	renderamt(integer) : "FX Amount (1 - 255)"
	rendercolor(color255) : "FX Color (R G B)" : "0 0 0"
]

@PointClass base(Monster) size(-16 -16 -16, 16 16 16) = cycler_weapon : "Weapon Cycler" 
[
	model(studio) : "model"
]

//
// Environmental effects
//

@BaseClass = BeamStartEnd 
[
	LightningStart(target_destination) : "Start Entity" 
	LightningEnd(target_destination) : "Ending Entity" 
]
@PointClass iconsprite("sprites/am/envbeam.spr") base(Targetname, BeamStartEnd, RenderFxChoices) size(-16 -16 -16, 16 16 16) = env_beam : "Energy Beam Effect"
[
	renderamt(integer) : "Brightness (1 - 255)" : 100
	rendercolor(color255) : "Beam Color (R G B)" : "0 0 0"
	Radius(integer) : "Radius" : 256
	life(string) : "Life (seconds 0 = infinite)" : "1"
	BoltWidth(integer) : "Width of beam (pixels*0.1 0-255)" : 20
	NoiseAmplitude(integer) : "Amount of noise (0-255)" : 0
	texture(sprite) : "Sprite Name" : "sprites/laserbeam.spr"
	TextureScroll(integer) : "Texture Scroll Rate (0-100)" : 35
	framerate(integer) : "Frames per 10 seconds" : 0
	framestart(integer) : "Starting Frame" : 0
	StrikeTime(string) : "Strike again time (secs)" : "1"
	damage(string) : "Damage / second" : "0"
	spawnflags(flags) = 
	[
		1 : "Start On" : 0
		2 : "Toggle" : 0
		4 : "Random Strike" : 0
		8 : "Ring" : 0
		16: "StartSparks" : 0
		32: "EndSparks" : 0
		64: "Decal End" : 0
		128: "Shade Start" : 0
		256: "Shade End" : 0
	]
]

@PointClass base(Targetname) size(-4 -4 -4, 4 4 4) = env_beverage : "Beverage Dispenser"
[
	health(integer) : "Capacity" : 10
	skin(choices) : "Beverage Type" : 0 = 
	[
		0 : "Coca-Cola"
		1 : "Sprite"
		2 : "Diet Coke"
		3 : "Orange"
		4 : "Surge"
		5 : "Moxie"
		6 : "Random"
	]
]

@PointClass iconsprite("sprites/am/envblood.spr") base(Targetname) size(-16 -16 -16, 16 16 16) color(255 0 0) = env_blood : "Blood Effects" 
[
	color(choices) : "Blood Color" : 0 =
	[
		0 : "Red (Human)"
		1 : "Yellow (Alien)"
	]
	amount(string) : "Amount of blood (damage to simulate)" : "100"
	spawnflags(flags) =
	[
		1: "Random Direction" : 0
		2: "Blood Stream" : 0
		4: "On Player" : 0
		8: "Spray decals" : 0
	]
]

@SolidClass base(Targetname) = env_bubbles : "Bubble Volume" 
[
	density(integer) : "Bubble density" : 2
	frequency(integer) : "Bubble frequency" : 2
	current(integer) : "Speed of Current" : 0
	spawnflags(Flags) = 
	[
		1 : "Start Off" 	: 0
	]
]

@PointClass base(Targetname) size(-16 -16 -16, 16 16 16) = env_explosion : "Explosion" 
[
	iMagnitude(Integer) : "Magnitude" : 100
	spawnflags(flags) =
	[
		1: "No Damage" : 0
		2: "Repeatable" : 0
		4: "No Fireball" : 0
		8: "No Smoke" : 0
		16: "No Decal" : 0
		32: "No Sparks" : 0
	]
]

@PointClass iconsprite("sprites/am/envglobal.spr") base(Targetname) color(255 255 128) = env_global : "Global State"
[
	globalstate(string) : "Global State to Set"
	triggermode(choices) : "Trigger Mode" : 0 =
	[
		0 : "Off"
		1 : "On"
		2 : "Dead"
		3 : "Toggle"
	]
	initialstate(choices) : "Initial State" : 0 =
	[
		0 : "Off"
		1 : "On"
		2 : "Dead"
	]
	spawnflags(flags) =
	[
		1 : "Set Initial State" : 0
	]
]

@PointClass sprite() base(Targetname, RenderFields) size(-4 -4 -4, 4 4 4) color(30 100 0) = env_glow : "Light Glow/Haze" 
[
	model(sprite) : "Sprite Name" : "sprites/glow01.spr"
	scale(integer) : "Scale" : 1
]


@PointClass iconsprite("sprites/am/envfunnel.spr") base(Targetname) size(-16 -16 -16, 16 16 16) = env_funnel : "Large Portal Funnel" 
[
	spawnflags(flags) =
	[
		1: "Reverse" : 0
	]
] 
@PointClass base(Targetname, RenderFxChoices) size(-16 -16 -16, 16 16 16) = env_laser : "Laser Beam Effect"
[
	LaserTarget(target_destination) : "Target of Laser" 
	renderamt(integer) : "Brightness (1 - 255)" : 100
	rendercolor(color255) : "Beam Color (R G B)" : "0 0 0"
	width(integer) : "Width of beam (pixels*0.1 0-255)" : 20
	NoiseAmplitude(integer) : "Amount of noise (0-255)" : 0
	texture(sprite) : "Sprite Name" : "sprites/laserbeam.spr"
	EndSprite(sprite) : "End Sprite" : ""
	TextureScroll(integer) : "Texture Scroll Rate (0-100)" : 35
	framestart(integer) : "Starting Frame" : 0
	damage(string) : "Damage / second" : "100"
	spawnflags(flags) = 
	[
		1 : "Start On" : 0
		16: "StartSparks" : 0
		32: "EndSparks" : 0
		64: "Decal End" : 0
	]
]

@PointClass base(Targetname, Target) = env_message : "HUD Text Message" 
[
	message(string) : "Message Name"
	spawnflags(flags) =
	[
		1: "Play Once" : 0
		2: "All Clients" : 0
	]
	messagesound(sound) : "Sound Effect"
	messagevolume(string) : "Volume 0-10" : "10"
	messageattenuation(Choices) : "Sound Radius" : 0 =
	[
		0 : "Small Radius"
		1 : "Medium Radius"
		2 : "Large  Radius"
		3 : "Play Everywhere"
	]
]

@PointClass base(Targetname, Target, RenderFields) size(-16 -16 -16, 16 16 16) color(100 100 0) = env_render : "Render Controls"
[
	spawnflags(flags) =
	[
		1: "No Renderfx" : 0
		2: "No Renderamt" : 0
		4: "No Rendermode" : 0
		8: "No Rendercolor" : 0
	]
]

@PointClass base(Targetname) = env_shake : "Screen Shake" 
[
	spawnflags(flags) =
	[
		1: "GlobalShake" : 0
	]
	amplitude(string) : "Amplitude 0-16" : "4"
	radius(string) : "Effect radius" : "500"
	duration(string) : "Duration (seconds)" : "1"
	frequency(string) : "0.1 = jerk, 255.0 = rumble" : "2.5"
]
 @PointClass base(gibshooterbase, RenderFields) size(-16 -16 -16, 16 16 16) = env_shooter : "Model Shooter"
[
	shootmodel(studio) : "Model or Sprite name" : ""
	shootsounds(choices) :"Material Sound" : -1 =
	[
		-1: "None"
		0: "Glass"
		1: "Wood"
		2: "Metal"
		3: "Flesh"
		4: "Concrete"  
	]
	scale(string) : "Gib Sprite Scale" : ""
	skin(integer) : "Gib Skin" : 0
]

@PointClass iconsprite("sprites/speaker.spr") = env_sound : "DSP Sound" 
[
	radius(integer) : "Radius" : 128
	roomtype(Choices) : "Room Type" : 0 =
	[
		0 : "Normal (off)"
		1 : "Generic"
		
		2 : "Metal Small"
		3 : "Metal Medium"
		4 : "Metal Large"
	
		5 : "Tunnel Small"
		6 : "Tunnel Medium"
		7 : "Tunnel Large"
	
		8 : "Chamber Small"
		9 : "Chamber Medium"
		10: "Chamber Large"

		11: "Bright Small"
		12: "Bright Medium"
		13: "Bright Large"

		14: "Water 1"
		15: "Water 2"
		16: "Water 3"

		17: "Concrete Small"
		18: "Concrete Medium"
		19: "Concrete Large"

		20: "Big 1"
		21: "Big 2"
		22: "Big 3"

		23: "Cavern Small"
		24: "Cavern Medium"
		25: "Cavern Large"

		26: "Weirdo 1"
		27: "Weirdo 2"
		28: "Weirdo 3"
	]
]

@PointClass base(Targetname) size(-16 -16 -16, 16 16 16) = env_spark : "Spark" 
[
	MaxDelay(string) : "Max Delay" : "0"
	spawnflags(flags) =
	[
		32: "Toggle" : 0
		64: "Start ON" : 0
	]
]

@PointClass sprite() base(Targetname, RenderFields) size(-4 -4 -4, 4 4 4) = env_sprite : "Sprite Effect" 
[
	framerate(string) : "Framerate" : "10.0"
	model(sprite) : "Sprite Name" : "sprites/glow01.spr"
	scale(string) : "Scale" : ""
	spawnflags(flags) =
	[
		1: "Start on" : 0
		2: "Play Once" : 0
	]
]

@SolidClass base(Breakable, RenderFields) = func_breakable : "Breakable Object" 
[
	spawnflags(flags) =
	[
		1 : "Only Trigger" : 0
		2 : "Touch"	   : 0
		4 : "Pressure"     : 0
		256: "Instant Crowbar" : 1
		1024: "SOLO POR SEMTEX" : 0
	
	]
	_minlight(string) : "Minimum light level"
]

@SolidClass base(Global,Targetname, Target, RenderFields) = func_button : "Button" 
[
	speed(integer) : "Speed" : 5
	health(integer) : "Health (shootable if > 0)"
	lip(integer) : "Lip"
	master(string) : "Master" 
	sounds(choices) : "Sounds" : 0 = 
	[
		0: "None"
		1: "Big zap & Warmup"
		2: "Access Denied"
		3: "Access Granted"
		4: "Quick Combolock"
		5: "Power Deadbolt 1"
		6: "Power Deadbolt 2"
		7: "Plunger"
		8: "Small zap"
		9: "Keycard Sound"
		10: "Buzz"
		11: "Buzz Off"
		14: "Lightswitch"
	]
	wait(integer) : "delay before reset (-1 stay)" : 3
	delay(string) : "Delay before trigger" : "0"
	spawnflags(flags) =
	[
		1: "Don't move" : 0
		32: "Toggle" : 0
		64: "Sparks" : 0
		256:"Touch Activates": 0
	]
	locked_sound(choices) : "Locked Sound" : 0 = 
	[
		0: "None"
		2: "Access Denied"
		8: "Small zap"
		10: "Buzz"
		11: "Buzz Off"
		12: "Latch Locked"
	]
	unlocked_sound(choices) : "Unlocked Sound" : 0 = 
	[
		0: "None"
		1: "Big zap & Warmup"
		3: "Access Granted"
		4: "Quick Combolock"
		5: "Power Deadbolt 1"
		6: "Power Deadbolt 2"
		7: "Plunger"
		8: "Small zap"
		9: "Keycard Sound"
		10: "Buzz"
		13: "Latch Unlocked"
		14: "Lightswitch"
	]
	locked_sentence(choices) : "Locked Sentence" : 0 = 
	[
		0: "None"
		1: "Gen. Access Denied"
		2: "Security Lockout"
		3: "Blast Door"
		4: "Fire Door"
		5: "Chemical Door"
		6: "Radiation Door"
		7: "Gen. Containment"
		8: "Maintenance Door"
		9: "Broken Shut Door"
	]
	unlocked_sentence(choices) : "Unlocked Sentence" : 0 = 
	[
		0: "None"
		1: "Gen. Access Granted"
		2: "Security Disengaged"
		3: "Blast Door"
		4: "Fire Door"
		5: "Chemical Door"
		6: "Radiation Door"
		7: "Gen. Containment"
		8: "Maintenance area"
	]
	_minlight(string) : "Minimum light level"
]
@SolidClass base(Targetname, Target, RenderFields) = func_tbutton : "Time Button" 
[
	starget(string) : "Target when stop" : ""
	on_time(integer) : "Time for activation" : 5
	off_time(integer) : "Time for desactivation" : 0

	noise(string) : "Message when start activating" : "HACKING"

	message(string) : "Message when activated" : "HACKED"


	speed(integer) : "Speed" : 5
	master(string) : "Master" 
	sounds(choices) : "Sounds" : 0 = 
	[
		0: "None"
		1: "Big zap & Warmup"
		2: "Access Denied"
		3: "Access Granted"
		4: "Quick Combolock"
		5: "Power Deadbolt 1"
		6: "Power Deadbolt 2"
		7: "Plunger"
		8: "Small zap"
		9: "Keycard Sound"
		10: "Buzz"
		11: "Buzz Off"
		14: "Lightswitch"
	]
	delay(string) : "Delay before trigger" : "0"
	spawnflags(flags) =
	[
		1: "Don't move" : 0
		32: "Toggle" : 0
		64: "Sparks" : 0
		256:"Touch Activates": 0
	]
	locked_sound(choices) : "Locked Sound" : 0 = 
	[
		0: "None"
		2: "Access Denied"
		8: "Small zap"
		10: "Buzz"
		11: "Buzz Off"
		12: "Latch Locked"
	]
	unlocked_sound(choices) : "Unlocked Sound" : 0 = 
	[
		0: "None"
		1: "Big zap & Warmup"
		3: "Access Granted"
		4: "Quick Combolock"
		5: "Power Deadbolt 1"
		6: "Power Deadbolt 2"
		7: "Plunger"
		8: "Small zap"
		9: "Keycard Sound"
		10: "Buzz"
		13: "Latch Unlocked"
		14: "Lightswitch"
	]
	locked_sentence(choices) : "Locked Sentence" : 0 = 
	[
		0: "None"
		1: "Gen. Access Denied"
		2: "Security Lockout"
		3: "Blast Door"
		4: "Fire Door"
		5: "Chemical Door"
		6: "Radiation Door"
		7: "Gen. Containment"
		8: "Maintenance Door"
		9: "Broken Shut Door"
	]
	unlocked_sentence(choices) : "Unlocked Sentence" : 0 = 
	[
		0: "None"
		1: "Gen. Access Granted"
		2: "Security Disengaged"
		3: "Blast Door"
		4: "Fire Door"
		5: "Chemical Door"
		6: "Radiation Door"
		7: "Gen. Containment"
		8: "Maintenance area"
	]
	_minlight(string) : "Minimum light level"
]
@SolidClass base(Global,RenderFields, Targetname) = func_conveyor : "Conveyor Belt" 
[
	spawnflags(flags) =
	[
		1 : "No Push" : 0
		2 : "Not Solid" : 0
	]
	speed(string) : "Conveyor Speed" : "100"
	_minlight(string) : "Minimum light level"
]

@SolidClass base(Door) = func_door : "Basic door" []

@SolidClass base(Door) = func_door_rotating : "Rotating door" 
[
	spawnflags(flags) =
	[
		2 : "Reverse Dir" : 0
		16: "One-way" : 0
		64: "X Axis" : 0
		128: "Y Axis" : 0
	]
	distance(integer) : "Distance (deg)" : 90
	angles(string) : "Pitch Yaw Roll (Y Z X)" : "0 0 0"
]

@SolidClass base(Appearflags, RenderFields) = func_friction : "Surface with a change in friction" 
[
	modifier(integer) : "Percentage of standard (0 - 100)" : 15
]

@SolidClass base(Targetname, RenderFields, Global) = func_guntarget : "Moving platform" 
[
	speed(integer) : "Speed (units per second)" : 100
	target(target_source) : "First stop target"
	message(target_source) : "Fire on damage"
	health(integer) : "Damage to Take" : 0
	_minlight(string) : "Minimum light level"
]

@SolidClass base(Global, RenderFields) = func_healthcharger: "Wall health recharger" 
[
	// dmdelay(integer) : "Deathmatch recharge delay" : 0
	_minlight(string) : "Minimum light level"
]

@SolidClass base(Targetname, RenderFields) = func_illusionary : "Fake Wall/Light" 
[

	skin(choices) : "Contents" : -1 =
	[
		-1: "Empty"
		-7: "Volumetric Light"
	]
	_minlight(string) : "Minimum light level"
]

@SolidClass base(Targetname) = func_ladder : "Ladder" []

@SolidClass base(Targetname) = func_monsterclip : "Monster clip brush" []

@SolidClass base(Targetname) = func_mortar_field : "Mortar Field" 
[
	m_flSpread(integer) : "Spread Radius" : 64
	m_iCount(integer) : "Repeat Count" : 1
	m_fControl(Choices) : "Targeting" : 0 =
	[
		0 : "Random"
		1 : "Activator"
		2 : "Table"
	]
	m_iszXController(target_destination) : "X Controller"
	m_iszYController(target_destination) : "Y Controller"
]

@SolidClass base(Global,Appearflags, Targetname, RenderFields) = func_pendulum : "Swings back and forth" 
[
	speed(integer) : "Speed" : 100
	distance(integer) : "Distance (deg)" : 90
	damp(integer) : "Damping (0-1000)" : 0
	dmg(integer) : "Damage inflicted when blocked" : 0
	spawnflags(flags) =
	[
		1: "Start ON" : 0
		8: "Passable" : 0
		16: "Auto-return" : 0
		64: "X Axis" : 0
		128: "Y Axis" : 0
	]

	_minlight(integer) : "_minlight"
	angles(string) : "Pitch Yaw Roll (Y Z X)" : "0 0 0"
]

@SolidClass base(Targetname,Global,RenderFields, PlatSounds) = func_plat : "Elevator" 
[
	spawnflags(Flags) =
	[
		1: "Toggle" : 0
	]
	height(integer) : "Travel altitude (can be negative)" : 0
	speed(integer) : "Speed" : 50
	_minlight(string) : "Minimum light level"
]	

@SolidClass base(Targetname, Global, RenderFields, PlatSounds) = func_platrot : "Moving Rotating platform" 
[
	spawnflags(Flags) =
	[
		1: "Toggle" : 1
		64: "X Axis" : 0
		128: "Y Axis" : 0
	]
	speed(integer) : "Speed of rotation" : 50
	height(integer) : "Travel altitude (can be negative)" : 0
	rotation(integer) : "Spin amount" : 0
	angles(string) : "Pitch Yaw Roll (Y Z X)" : "0 0 0"
	_minlight(string) : "Minimum light level"
]

@SolidClass base(Breakable, RenderFields) = func_pushable : "Pushable object"
[
	size(choices) : "Hull Size" : 0 =
	[
		0: "Point size"
		1: "Player size"
		2: "Big Size"
		3: "Player duck"
	]
	spawnflags(flags) =
	[
		128: "Breakable" : 0
	]
	friction(integer) : "Friction (0-400)" : 50
	buoyancy(integer) : "Buoyancy" : 20
	_minlight(string) : "Minimum light level"
]

@SolidClass base(Global,RenderFields) = func_recharge: "Battery recharger" 
[
	// dmdelay(integer) : "Deathmatch recharge delay" : 0
	_minlight(string) : "Minimum light level"
]

@SolidClass base(Targetname, Global, RenderFields) = func_rot_button : "RotatingButton" 
[
	target(target_destination) : "Targetted object"
	// changetarget will change the button's target's TARGET field to the button's changetarget.
	changetarget(target_destination) : "ChangeTarget Name"
	master(string) : "Master" 
	speed(integer) : "Speed" : 50
	health(integer) : "Health (shootable if > 0)"
	sounds(choices) : "Sounds" : 21 = 
	[
		21: "Squeaky"
		22: "Squeaky Pneumatic"
		23: "Ratchet Groan"
		24: "Clean Ratchet"
		25: "Gas Clunk"
	]
	wait(choices) : "Delay before reset" : 3 =
	[
		-1: "Stays pressed"
	]
	delay(string) : "Delay before trigger" : "0"
	distance(integer) : "Distance (deg)" : 90
	spawnflags(flags) =
	[
		1 : "Not solid" : 0
		2 : "Reverse Dir" : 0
		32: "Toggle" : 0
		64: "X Axis" : 0
		128: "Y Axis" : 0
		256:"Touch Activates": 0
	]
	_minlight(integer) : "_minlight"
	angles(string) : "Pitch Yaw Roll (Y Z X)" : "0 0 0"
]

@SolidClass base(Targetname, Global, RenderFields) = func_rotating : "Rotating Object"
[
	speed(integer)	: "Rotation Speed" : 0
	volume(integer) : "Volume (10 = loudest)" : 10
	fanfriction(integer) : "Friction (0 - 100%)" : 20
	sounds(choices) : "Fan Sounds" : 0 =
	[
		0 : "No Sound" 
		1 : "Fast Whine"
		2 : "Slow Rush"
		3 : "Medium Rickety"
		4 : "Fast Beating"
		5 : "Slow Smooth"
	]
	message(sound) : "WAV Name"
	spawnflags(flags) =
	[
		1 : "Start ON" 		: 0
		2 : "Reverse Direction" : 0
		4 : "X Axis" 		: 0
		8 : "Y Axis" 		: 0
		16: "Acc/Dcc"		: 0
		32: "Fan Pain"		: 0
		64: "Not Solid"		: 0
		128: "Small Radius" : 0
		256: "Medium Radius" : 0
		512: "Large Radius" : 1	
	]
	_minlight(integer) : "_minlight"
	angles(string) : "Pitch Yaw Roll (Y Z X)" : "0 0 0"
	spawnorigin(string) : "X Y Z - Move here after lighting" : "0 0 0"
	dmg(integer) : "Damage inflicted when blocked" : 0
]

@SolidClass base(BaseTank) = func_tank : "Brush Gun Turret" 
[
	bullet(choices) : "Bullets" : 0 = 
	[
		0: "None"
		1: "9mm"
		2: "MP5"
		3: "12mm"
	]
]

@SolidClass = func_tankcontrols : "Tank controls"
[
	target(target_destination) : "Tank entity name"
]

@SolidClass base(BaseTank) = func_tanklaser : "Brush Laser Turret" 
[
	laserentity(target_source) : "env_laser Entity"
]

@SolidClass base(BaseTank) = func_tankrocket : "Brush Rocket Turret" []


@SolidClass base(BaseTank) = func_tankmortar : "Brush Mortar Turret" 
[
	iMagnitude(Integer) : "Explosion Magnitude" : 100
]

@SolidClass base(Trackchange) = func_trackautochange : "Automatic track changing platform"
[
	_minlight(string) : "Minimum light level"
]

@SolidClass base(Trackchange) = func_trackchange : "Train track changing platform"
[
	_minlight(string) : "Minimum light level"
]

@SolidClass base(Targetname, Global, RenderFields) = func_tracktrain : "Track Train" 
[
	spawnflags(flags) =
	[
		1 : "No Pitch (X-rot)" : 0
		2 : "No User Control" : 0
		8 : "Passable" : 0
	]
	target(target_destination) : "First stop target"
	sounds(choices) : "Sound" : 0 =
	[
		0: "None"
		1: "Rail 1"
		2: "Rail 2"
		3: "Rail 3"
		4: "Rail 4"
		5: "Rail 6"
		6: "Rail 7"
	]
	wheels(integer) : "Distance between the wheels" : 50
	height(integer) : "Height above track" : 4
	startspeed(integer) : "Initial speed" : 0
	speed(integer) : "Speed (units per second)" : 64
	dmg(integer) : "Damage on crush" : 0	
	volume(integer) : "Volume (10 = loudest)" : 10
	bank(string) : "Bank angle on turns" : "0"
	_minlight(string) : "Minimum light level"
]

@SolidClass = func_traincontrols : "Train Controls"
[
	target(target_destination) : "Train Name"
]

@SolidClass base(Targetname, Global, RenderFields) = func_train : "Moving platform" 
[














	target(target_source) : "First stop target"
	movesnd(choices) : "Move Sound" : 0 = 
	[
		0: "No Sound"
		1: "big elev 1"
		2: "big elev 2"
		3: "tech elev 1"
		4: "tech elev 2"
		5: "tech elev 3"
		6: "freight elev 1"
		7: "freight elev 2"
		8: "heavy elev"
		9: "rack elev"
		10: "rail elev"
		11: "squeek elev"
		12: "odd elev 1"
		13: "odd elev 2"
	]
	stopsnd(choices) : "Stop Sound" : 0 = 
	[
		0: "No Sound"
		1: "big elev stop1"
		2: "big elev stop2"
		3: "freight elev stop"
		4: "heavy elev stop"
		5: "rack stop"
		6: "rail stop"
		7: "squeek stop"
		8: "quick stop"
	]
	speed(integer) : "Speed (units per second)" : 64
	dmg(integer) : "Damage on crush" : 0
	skin(integer) : "Contents" : 0
	volume(string) : "Sound Volume 0.0 - 1.0" : "0.85"
	spawnflags(flags) =
	[
		8 : "Not solid" : 0
	]
	_minlight(string) : "Minimum light level"
]

@SolidClass base(Targetname, Appearflags, RenderFields, Global) = func_wall : "Wall" 
[
	_minlight(string) : "Minimum light level"
]

@SolidClass base(func_wall) = func_wall_toggle : "Toggleable geometry" 
[
	spawnflags(flags) =
	[
		1 : "Starts Invisible" : 0
	]
]

@SolidClass base(Door) = func_water : "Liquid" 
[
	spawnflags(flags) =
	[
		1 : "Starts Open" : 0
		256:"Use Only" : 0
	]
	skin(choices) : "Contents" : -3 =
	[
		-3: "Water"
		-4: "Slime"
		-5: "Lava"
	]
	WaveHeight(string) : "Wave Height" : "3.2"
]

//
// game entities (requires Half-Life 1.0.0.9)
//

@PointClass base(Targetname, Targetx) = game_counter : "Fires when it hits limit"
[
	spawnflags(flags) =
	[
		1: "Remove On fire" : 0
		2: "Reset On fire" : 1
	]
	master(string) : "Master"
	frags(integer) : "Initial Value" : 0
	health(integer) : "Limit Value" : 10
]

@PointClass base(Targetname, Target) = game_counter_set : "Sets a game_counter"
[
	spawnflags(flags) =
	[
		1: "Remove On fire" : 0
	]
	master(string) : "Master"
	frags(integer) : "New Value" : 10
]

@PointClass base(Targetname) = game_end : "End this multiplayer game" 
[
	master(string) : "Master" 
]

@PointClass base(Targetname) = game_player_equip : "Initial player equipment"
[
	spawnflags(flags) =
	[
		1: "Use Only" : 0
	]
	master(string) : "Team Master"
]

@PointClass base(Targetname) = game_player_hurt : "Hurts player who fires"
[
	dmg(string) : "Damage To Apply" : "999"
	spawnflags(flags) =
	[
		1: "Remove On fire" : 0
	]
	master(string) : "Master" 
]

@PointClass base(Targetname) = game_player_team : "Allows player to change teams"
[
	spawnflags(flags) =
	[
		1 : "Remove On fire" : 0
		2 : "Kill Player" : 0
		4 : "Gib Player" : 0
	]
	target(string) : "game_team_master to use" 
	master(string) : "Master"
]

@PointClass base(Targetname) = game_score : "Award/Deduct Points" 
[
	spawnflags(flags) =
	[
		1: "Allow Negative" : 0
		2: "Team Points" : 0
	]

	points(integer) : "Points to add (+/-)" : 1
	master(string) : "Master" 
]

@PointClass base(Targetname, Targetx) = game_team_master : "Team based master/relay"
[
	spawnflags(flags) =
	[
		1: "Remove On fire" : 0
	]
	triggerstate(choices) : "Trigger State" : 0 = 
	[
		0: "Off"
		1: "On"
		2: "Toggle"
	]
	teamindex(integer) : "Team Index (-1 = no team)" : -1
	master(string) : "Master" 
]

@PointClass base(Targetname, Targetx) = game_team_set : "Sets team of team_master"
[
	spawnflags(flags) =
	[
		1: "Remove On fire" : 0
	]
	master(string) : "Master" 
]

@PointClass base(Targetname, Target) = game_text : "HUD Text Message" 
[
	spawnflags(flags) =
	[
		1: "All Players" : 0
	]

	message(string) : "Message Text"
	x(string) : "X (0 - 1.0 = left to right) (-1 centers)" : "-1"
	y(string) : "Y (0 - 1.0 = top to bottom) (-1 centers)" : "-1"
	effect(Choices) : "Text Effect" : 0 =
	[
		0 : "Fade In/Out"
		1 : "Credits"
		2 : "Scan Out"
	]
	color(color255) : "Color1" : "100 100 100"

color2(color255) : "Color2" : "240 110 0"
	fadein(string) : "Fade in Time (or character scan time)" : "1.5"
	fadeout(string) : "Fade Out Time" : "0.5"


holdtime(string) : "Hold Time" : "1.2"
	fxtime(string) : "Scan time (scan effect only)" : "0.25"
	channel(choices) : "Text Channel" : 1 =
	[
		1 : "Channel 1"
		2 : "Channel 2"
		3 : "Channel 3" 
		4 : "Channel 4"
	]
	master(string) : "Master" 
]

@SolidClass base(Targetname) = game_zone_player : "Player Zone brush"
[
	intarget(target_destination) : "Target for IN players"
	outtarget(target_destination) : "Target for OUT players"
	incount(target_destination) : "Counter for IN players"
	outcount(target_destination) : "Counter for OUT players"
	// master(string) : "Master" 
]

@PointClass base(gibshooterbase) = gibshooter : "Gib Shooter" []

//
// info entities
//

@PointClass decal() base(Targetname, Appearflags) = infodecal : "Decal"
[
	texture(decal)
]

@PointClass base(Targetname) size(-24 -24 0, 24 24 16) color(20 190 60) = info_bigmomma : "Big Mamma Node" 
[
	spawnflags(Flags) =
	[
		1 : "Run To Node" : 0
		2 : "Wait Indefinitely" : 0
	]
	target(target_destination) : "Next node"
	radius(string) : "Radius" : "0"
	reachdelay(string) : "Wait after approach" : "0"
	killtarget(target_destination) : "KillTarget"
	reachtarget(target_destination) : "Fire on approach"
	reachsequence(string) : "Sequence on approach" : ""
	health(string) : "Health on approach" : ""
	presequence(string) : "Sequence before approach" : ""
]

@PointClass base(Target) size(-4 -4 -4, 4 4 4) color(0 255 0) = info_intermission : "Intermission Spot" []

@PointClass base(Targetname) = info_landmark : "Transition Landmark" []

@PointClass size(-24 -24 -4, 24 24 4) color(255 255 0) = info_node : "ai node" []

@PointClass size(-32 -32 0, 32 32 64) color(255 255 0) = info_node_air : "ai air node" []

@PointClass base(Targetname) = info_null : "info_null (spotlight target)" []

@PointClass base(PlayerClass) = info_player_coop : "Player cooperative start" []
@PointClass base(PlayerClass) = info_player_deathmatch : "Player deathmatch start" 
[
	target(target_destination) : "Target"
	master(string) : "Master"
]
@PointClass base(PlayerClass) = info_player_start : "Player 1 start" []

@PointClass base(Targetname) size(-4 -4 -4, 4 4 4) color(200 100 50) = info_target : "Beam Target" []
@PointClass size(-8 -8 0, 8 8 16) base(PlayerClass, Targetname) = info_teleport_destination : "Teleport destination" []
 //
// items
//

@PointClass size(-16 -16 0, 16 16 36) base(Weapon, Targetx) = item_airtank : "Oxygen tank" []
@PointClass size(-16 -16 0, 16 16 36) base(Weapon, Targetx) = item_antidote : "Poison antidote" []
@PointClass size(-16 -16 0, 16 16 36) base(Weapon, Targetx) = item_battery : "HEV battery" []
@PointClass size(-16 -16 0, 16 16 36) base(Weapon, Targetx) = item_healthkit : "Small Health Kit" []
@PointClass size(-16 -16 0, 16 16 36) base(Weapon, Targetx) = item_longjump : "Longjump Module" [] @PointClass size(-16 -16 0, 16 16 36) base(Weapon, Targetx) = item_security : "Security card" []
@PointClass size(-16 -16 0, 16 16 36) base(Weapon, Targetx) = item_suit : "HEV Suit" 
[
	model(studio) : "Custom Model Suit" : "models/w_suit.mdl"
	spawnflags(Flags) =
	[
		1 : "Short Logon" : 0
	]
]

//
// lights
//

@PointClass iconsprite("sprites/lightbulb.spr") base(Target, Targetname, Light) = light : "Invisible lightsource"
[
	spawnflags(Flags) = [ 1 : "Initially dark" : 0 ]
]

@PointClass iconsprite("sprites/lightbulb.spr") base(Targetname, Target) = light_spot : "Spotlight" 
[
	_cone(integer) : "Inner (bright) angle" : 30
	_cone2(integer) : "Outer (fading) angle" : 45
	pitch(integer) : "Pitch" : -90
	_light(color255) : "Brightness" : "255 255 128 200"
	_sky(Choices) : "Is Sky" : 0 = 
	[ 
		0 : "No"
		1 : "Yes"
	]
	spawnflags(Flags) = [ 1 : "Initially dark" : 0 ]
      style(Choices) : "Appearance" : 0 =
	[
		0 : "Normal"
		10: "Fluorescent flicker"
		2 : "Slow, strong pulse"
		11: "Slow pulse, noblack"
		5 : "Gentle pulse"
		1 : "Flicker A"
		6 : "Flicker B"
		3 : "Candle A"
		7 : "Candle B"
		8 : "Candle C"
		4 : "Fast strobe"
		9 : "Slow strobe"
	]
	pattern(string) : "Custom Appearance"
]


@PointClass base(Targetname, Angles, ZHLT_point) iconsprite("sprites/lightbulb.spr") = light_environment : "Environment" 
[
	pitch(integer) : "Pitch" : 0
	_light(color255) : "Brightness" : "255 255 128 200"
]

@SolidClass base(Door, ZHLT) = momentary_door : "Momentary/Continuous door" 
[
	spawnflags(flags) =
	[
		1 : "Starts Open" : 0
	]
]

@SolidClass base(Targetname, Target, Angles, RenderFields, ZHLT) = momentary_rot_button : "Direct wheel control" 
[
	speed(integer) : "Speed" : 50
	master(string) : "Master" 
	sounds(choices) : "Sounds" : 0 = 
	[
		0: "None"
		1: "Big zap & Warmup"
		2: "Access Denied"
		3: "Access Granted"
		4: "Quick Combolock"
		5: "Power Deadbolt 1"
		6: "Power Deadbolt 2"
		7: "Plunger"
		8: "Small zap"
		9: "Keycard Sound"
		21: "Squeaky"
		22: "Squeaky Pneumatic"
		23: "Ratchet Groan"
		24: "Clean Ratchet"
		25: "Gas Clunk"
	]
	distance(integer) : "Distance (deg)" : 90
	returnspeed(integer) : "Auto-return speed" : 0
	spawnflags(flags) =
	[
		1: "Door Hack" : 0
		2: "Not useable" : 0
		16: "Auto Return" : 0
		64: "X Axis" : 0
		128: "Y Axis" : 0
	]
	_minlight(integer) : "_minlight"
]

//
// monsters
//



@PointClass base(Monster) size(-16 -16 0, 16 16 72) = monster_alien_controller : "Controller"  []
@PointClass base(Monster) size(-32 -32 0, 32 32 64) = monster_alien_grunt : "Alien Grunt" 
[
	netname(string) : "Squad Name"
	spawnflags(Flags) =
	[
		32 : "SquadLeader" : 0
	]
]


@PointClass base(Monster) size(-16 -16 0, 16 16 36) = monster_babycrab : "Baby Headcrab" []
@PointClass base(RenderFields) size(-16 -16 -36, 16 16 0) = monster_barnacle : "Barnacle Monster" []

@PointClass base(Monster) size(-95 -95 0, 95 95 190) = monster_bigmomma : "Big Mamma" 
[
	netname(string) : "First node" : ""
]

@PointClass base(Monster) size(-32 -32 0, 32 32 64) = monster_bullchicken : "BullChicken" []
@PointClass base(Monster) size(-3 -3 0, 3 3 3) = monster_cockroach : "Cockroach" []
@PointClass base(Monster) size(-16 -16 0, 16 16 16) = monster_flyer_flock : "Flock of Flyers" 
[
	iFlockSize(Integer) : "Flock Size" : 8
	flFlockRadius(Integer) : "Flock Radius" : 128
]
@PointClass base(Monster) size(-16 -16 0, 16 16 72) = monster_furniture : "Monster Furniture" 
[
	model(studio) : "model"

]
@PointClass base(Monster) size(-32 -32 0, 32 32 128) = monster_gargantua : "Gargantua" []
//@PointClass base(Monster, RenderFields) size(-16 -16 -36, 16 16 36) = monster_generic : //"Generic Script Monster" 
//[
//	spawnflags(Flags) = 
//	[
//		4 : "Not solid"	: 0
//	]
//	model(studio) : "model"
//	body(Integer) : "Body" : 0
//]
@PointClass base(Monster) size(-16 -16 0, 16 16 72) = monster_gman : "G-Man"
[
	model(studio) : "model"

]
@PointClass base(Monster) size(-16 -16 0, 16 16 72) = monster_grunt_repel : "Human Grunt (Repel)" []

@PointClass base(Monster) size(-16 -16 0, 16 16 36) = monster_headcrab : "Head Crab" []
@PointClass base(Appearflags,RenderFields) size(-16 -16 0, 16 16 72) = monster_hevsuit_dead : "Dead HEV Suit" 
[
      pose(Choices) : "Pose" : 0 =
	[
		0 : "On back"
		1 : "Seated"
		2 : "On stomach"
		3 : "On Table"
	]
]

@PointClass base(Monster, MonsterCH) size(-16 -16 0, 16 16 36) = monster_houndeye : "Houndeye" 
[
	netname(string) : "Squad Name"
	spawnflags(Flags) =
	[
		32 : "SquadLeader" : 0
	]
]
@PointClass base(Monster,MonsterCH) size(-16 -16 0, 16 16 72) = monster_human_assassin : "Human Assassin" 
[
	//m_iClass(choices) : "16"
	model(studio) : "Modelo" : "models/hassassin.mdl"
]
@PointClass base(Monster) size(-32 -32 0, 32 32 64) = monster_ichthyosaur : "Ichthyosaur" []
@PointClass base(Monster) size(-6 -6 0, 6 6 6) = monster_leech : "Leech" []
@PointClass base(Monster) size(-16 -16 -32, 16 16 32) = monster_miniturret : "Mini Auto Turret"
[
	orientation(Choices) : "Orientation" : 0 =
	[
		0 : "Floor Mount"
		1 : "Ceiling Mount"
	]
	spawnflags(Flags) = 
	[
		32 : "Autostart" : 0
		64 : "Start Inactive" : 0
	]
]
@PointClass base(Monster) size(-192 -192 0, 192 192 384) = monster_nihilanth : "Nihilanth"  []
@PointClass base(Monster) size(-480 -480 -112, 480 480 24) = monster_osprey : "Osprey"
[
	spawnflags(Flags) = 
	[
		64 : "Start Inactive" : 0
	]
]
@PointClass base(Weapon,Targetx,RenderFields) = monster_satchelcharge : "Live Satchel Charge" []

@PointClass base(MonsterBa, TalkMonsterBa) size(-14 -14 22, 14 14 72) = monster_sitting_scientist : "Sitting Scientist" 
[
      body(Choices) : "Body" : -1 =
	[
		-1 : "Random"
		0 : "Glasses"
		1 : "Einstein"
		2 : "Luther"
		3 : "Slick"
	]
]
@PointClass base(Monster) size(-16 -16 0, 16 16 72) = monster_sentry : "Sentry Turret Gun"
[
	spawnflags(Flags) = 
	[
		32 : "Autostart" : 0
		64 : "Start Inactive" : 0
	]
]
@PointClass base(Monster) size(-16 -16 0, 16 16 36) = monster_snark : "Armed Snark" []
@PointClass base(Monster) size(-32 -32 0, 32 32 64) = monster_tentacle : "Tentacle Arm" 
[
	sweeparc(integer) : "Sweep Arc" : 130
	sound(Choices) : "Tap Sound" : -1 =
	[
		-1 : "None"
		0 : "Silo"
		1 : "Dirt"
		2 : "Water"
	]
]
@PointClass base(Monster) = monster_tripmine : "Active Tripmine" 
[
	spawnflags(Flags) =
	[
		1 : "Instant On" : 1
	]
]

@PointClass base(Monster) size(-32 -32 -32, 32 32 32) = monster_turret : "Auto Turret"
[
	orientation(Choices) : "Orientation" : 0 =
	[
		0 : "Floor Mount"
		1 : "Ceiling Mount"
	]

spawnflags(Flags) = 
	[
		32 : "Autostart" : 0
		64 : "Start Inactive" : 0
	]
 ]


@PointClass base(Targetname) size(16 16 16) color(247 181 82) = path_corner : "Moving platform stop"
[
	spawnflags(Flags) =
	[
		1: "Wait for retrigger" : 0
		2: "Teleport" : 0
		4: "Fire once" : 0
	]
	target(target_destination) : "Next stop target"
	message(target_destination) : "Fire On Pass"
	wait(integer) : "Wait here (secs)" : 0
	speed(integer) : "New Train Speed" : 0
	yaw_speed(integer) : "New Train rot. Speed" : 0
	angles(string) : "X Y Z angles" 
]

@PointClass base(Targetname) size(16 16 16) = path_track : "Train Track Path"
[
	spawnflags(Flags) =
	[
		1: "Disabled" : 0
		2: "Fire once" : 0
		4: "Branch Reverse" : 0
		8: "Disable train" : 0
	]
	target(target_destination) : "Next stop target"
	message(target_destination) : "Fire On Pass"
	altpath(target_destination) : "Branch Path"
	netname(target_destination) : "Fire on dead end"
	speed(integer) : "New Train Speed" : 0
]

//
// player effects
//

@PointClass base(Targetname) size(-16 -16 -16, 16 16 16) = player_loadsaved : "Load Auto-Saved game" 
[
	duration(string) : "Fade Duration (seconds)" : "2"
	holdtime(string) : "Hold Fade (seconds)" : "0"
	renderamt(integer) : "Fade Alpha" : 255
	rendercolor(color255) : "Fade Color (R G B)" : "0 0 0"
	messagetime(string) : "Show Message delay" : "0"
	message(string) : "Message To Display" : ""
	loadtime(string) : "Reload delay" : "0"
]

//@PointClass base(Targetname) size(-16 -16 -16, 16 16 16) = player_weaponstrip : "Strips //player's weapons" []

@PointClass base(Targetname, Targetx) size(-16 -16 0, 16 16 72) color(255 0 255) = scripted_sentence : "Scripted Sentence"
[
	spawnflags(Flags) = 
	[
		1 : "Fire Once" 	: 1
		2 : "Followers Only"	: 0
		4 : "Interrupt Speech"	: 1
		8 : "Concurrent"	: 0
	]
	sentence(string) : "Sentence Name" : ""
	entity(string) : "Speaker Type"
	duration(string) : "Sentence Time" : "3"
	radius(integer) : "Search Radius" : 512
	refire(string) : "Delay Before Refire" : "3"
	listener(string) : "Listener Type" 	volume(string) : "Volume 0-10" : "10"
	attenuation(Choices) : "Sound Radius" : 0 =
	[
		0 : "Small Radius"
		1 : "Medium Radius"
		2 : "Large  Radius"
		3 : "Play Everywhere"
	]
]

@PointClass base(Targetname, Targetx) size(-16 -16 0, 16 16 72) color(255 0 255) = scripted_sequence : "Scripted Sequence"
[
	m_iszEntity(string) : "Target Monster"
	m_iszPlay(string) : "Action Animation" : ""
	m_iszIdle(string) : "Idle Animation" : ""
	m_flRadius(integer) : "Search Radius" : 512
	m_flRepeat(integer) : "Repeat Rate ms" : 0
	m_fMoveTo(choices) : "Move to Position" : 0 =
	[
		0 : "No"
		1 : "Walk"
		2 : "Run"
		4 : "Instantaneous"
		5 : "No - Turn to Face"
	]
	spawnflags(Flags) = 
	[

	4 : "Repeatable"	: 0
		8 : "Leave Corpse"	: 0
		32: "No Interruptions"	: 0
		64: "Override AI"	: 0
		128: "No Script Movement" : 0
		256: "Monster Die Anim" : 0
	]
]

@PointClass iconsprite("sprites/speaker.spr") base(Targetname) = speaker : "Announcement Speaker"
[
	preset(choices) :"Announcement Presets" : 0 =
	[
		0: "None"
		1: "C1A0 Announcer"
		2: "C1A1 Announcer"
		3: "C1A2 Announcer"
		4: "C1A3 Announcer"
		5: "C1A4 Announcer"  
		6: "C2A1 Announcer"
		7: "C2A2 Announcer"
		// 8: "C2A3 Announcer"
		9: "C2A4 Announcer" 


		// 10: "C2A5 Announcer"
		11: "C3A1 Announcer"
		12: "C3A2 Announcer"


]
	message(string) : "Sentence Group Name"
	health(integer) : "Volume (10 = loudest)" : 5
	spawnflags(flags) =
	[
		1: "Start Silent" : 0
	]
]

@PointClass base(Targetname) = target_cdaudio : "CD Audio Target"
[
	health(choices) : "Track #" : -1 =
	[
		-1 : "Stop"
		1 : "Track 1"
		2 : "Track 2"
		3 : "Track 3"
		4 : "Track 4"
		5 : "Track 5"
		6 : "Track 6"
		7 : "Track 7"
		8 : "Track 8"
		9 : "Track 9"
		10 : "Track 10"
		11 : "Track 11"
		12 : "Track 12"
		13 : "Track 13"
		14 : "Track 14"
		15 : "Track 15"
		16 : "Track 16"
		17 : "Track 17"
		18 : "Track 18"
		19 : "Track 19"
		20 : "Track 20"
		21 : "Track 21"
		22 : "Track 22"
		23 : "Track 23"
		24 : "Track 24"
		25 : "Track 25"
		26 : "Track 26"
		27 : "Track 27"
		28 : "Track 28"
		29 : "Track 29"
		30 : "Track 30"
	]
	radius(string) : "Player Radius"
]

//
// Triggers
//

@PointClass base(Targetx) = trigger_auto : "AutoTrigger"
[
	spawnflags(Flags) =
	[
		1 : "Remove On fire" : 1
	]
	globalstate(string) : "Global State to Read"
	triggerstate(choices) : "Trigger State" : 0 = 
	[
		0 : "Off"
		1 : "On"
		2 : "Toggle"
	]
]

@SolidClass base(Targetname) = trigger_autosave : "AutoSave Trigger"
[
	master(string) : "Master" 
]

@PointClass base(Targetx, Targetname) = trigger_camera : "Trigger Camera" 
[
	wait(integer) : "Hold time" : 10
	moveto(string) : "Path Corner"
	spawnflags(flags) =
	[
		1: "Start At Player" : 1
		2: "Follow Player" : 1
		4: "Freeze Player" : 0
	]
	speed(string) : "Initial Speed" : "0"
	acceleration(string) : "Acceleration units/sec^2" : "500"
	deceleration(string) : "Stop Deceleration units/sec^2" : "500"
]

@SolidClass base(Targetname) = trigger_cdaudio : "Trigger CD Audio"
[
	health(choices) : "Track #" : -1 =
	[
		-1 : "Stop"
		1 : "Track 1"
		2 : "Track 2"
		3 : "Track 3"
		4 : "Track 4"
		5 : "Track 5"
		6 : "Track 6"
		7 : "Track 7"
		8 : "Track 8"
		9 : "Track 9"
		10 : "Track 10"
		11 : "Track 11"
		12 : "Track 12"
		13 : "Track 13"
		14 : "Track 14"
		15 : "Track 15"
		16 : "Track 16"
		17 : "Track 17"
		18 : "Track 18"
		19 : "Track 19"
		20 : "Track 20"
		21 : "Track 21"
		22 : "Track 22"
		23 : "Track 23"
		24 : "Track 24"
		25 : "Track 25"
		26 : "Track 26"
		27 : "Track 27"
		28 : "Track 28"
		29 : "Track 29"
		30 : "Track 30"
	]
]

@SolidClass = trigger_changelevel : "Trigger: Change level"
[
	targetname(string) : "Name" 	map(string) : "New map name"
	landmark(string) : "Landmark name"
	changetarget(target_destination) : "Change Target"
	changedelay(string) : "Delay before change target" : "0"
	spawnflags(flags) =
	[
		1: "No Intermission" : 0
		2: "USE Only" : 0
	]
]

@PointClass base(Targetx, Targetname) = trigger_changetarget : "Trigger Change Target"
[
	m_iszNewTarget(string) : "New Target"
]

@SolidClass base(Trigger, Targetname) = trigger_counter : "Trigger counter" 
[
	spawnflags(flags) = 
	[ 
		1 : "No Message" : 0 
	]
	master(string) : "Master" 
	count(integer) : "Count before activation" : 2
]

@SolidClass base(Targetname) = trigger_endsection : "EndSection Trigger"
[
	section(string) : "Section"
	spawnflags(flags) =
	[
		1: "USE Only" : 0
	]
]

@SolidClass base(Trigger) = trigger_gravity : "Trigger Gravity"
[
	gravity(integer) : "Gravity (0-1)" : 1
]

@SolidClass base(Targetname,Target) = trigger_hurt : "Trigger player hurt" 
[
	spawnflags(flags) = 

	[ 
		1: "Target Once" : 0 
		2: "Start Off" : 0
		8: "No clients" : 0
		16:"FireClientOnly" : 0
		32:"TouchClientOnly" : 0
	]
	master(string) : "Master" 
	dmg(integer) : "Damage" : 10
	delay(string) : "Delay before trigger" : "0"
	damagetype(choices) : "Damage Type" : 0 =
	[
		0 : "GENERIC"
		1 : "CRUSH"
		2 : "BULLET"
		4 : "SLASH"
		8 : "BURN"
		16 : "FREEZE"
		32 : "FALL"
		64 : "BLAST"
		128 : "CLUB"
		256 : "SHOCK"
		512 : "SONIC"
		1024 : "ENERGYBEAM"
		16384: "DROWN"
		32768 : "PARALYSE"
		65536 : "NERVEGAS"
		131072 : "POISON"
		262144 : "RADIATION"
		524288 : "DROWNRECOVER"
		1048576 : "CHEMICAL"
		2097152 : "SLOWBURN"
		4194304 : "SLOWFREEZE"
	]
]

@SolidClass = trigger_monsterjump : "Trigger monster jump" 
[
	master(string) : "Master" 
	speed(integer) : "Jump Speed" : 40
	height(integer) : "Jump Height" : 128
]

@SolidClass base(Trigger) = trigger_multiple : "Trigger: Activate multiple" 
[
	wait(integer) : "Delay before reset" : 10
]

@SolidClass base(Trigger) = trigger_once : "Trigger: Activate once" []

@SolidClass base(Trigger) = trigger_push : "Trigger player push"
[
	spawnflags(flags) = 
	[ 
		1: "Once Only" : 0 
		2: "Start Off" : 0
	]
	speed(integer) : "Speed of push" : 40
]

@PointClass base(Targetname, Targetx) = trigger_relay : "Trigger Relay"
[
	spawnflags(flags) =
	[
		1: "Remove On fire" : 0
	]
	triggerstate(choices) : "Trigger State" : 0 = 
	[
		0: "Off"
		1: "On"
		2: "Toggle"
	]
]

@SolidClass base(Trigger) = trigger_teleport : "Trigger teleport" []

@SolidClass base(Targetname) = trigger_transition : "Trigger: Select Transition Area" []

//
// weapons
//


@PointClass base(Weapon, Targetx) = weapon_357 : "357 Handgun" []
@PointClass base(Weapon, Targetx) = weapon_rpg : "RPG" []
@PointClass base(Weapon, Targetx) = weapon_gauss : "Gauss Gun" []
@PointClass base(Weapon, Targetx) = weapon_crossbow : "Crossbow" 
[
	sequence(choices) : "Placement" : 0 =
	[
		0 : "Normal (flat)"
		1 : "Realistic (tilted)"
	]
]
@PointClass base(Weapon, Targetx) = weapon_egon : "Egon Gun" []
@PointClass base(Weapon, Targetx) size(-16 -16 -5, 16 16 27) = weapon_tripmine : "Tripmine Ammo" []
@PointClass base(Weapon, Targetx) = weapon_satchel : "Satchel Charge Ammo" []
@PointClass base(Weapon, Targetx) = weapon_HEgrenade : "Handgrenade Ammo" []
@PointClass base(Weapon, Targetx) = weapon_snark : "Squeak Grenade" []
@PointClass base(Weapon, Targetx) = weapon_hornetgun : "Hornet Gun" []
@PointClass size(-16 -16 0, 16 16 64) color(0 128 0) =  weaponbox : "Weapon/Ammo Container" []

@PointClass base(Weapon, Targetx) = world_items : "World Items" 
[
	type(choices) :"types" : 42 =
	[
		42: "Antidote"
		43: "Security Card"
		44: "Battery"
		45: "Suit"
	]
]

@PointClass base(Weapon, Targetx) = ammo_9mmbox : "box of 200 9mm shells" []

@PointClass base(Weapon, Targetx) = ammo_ARgrenades : "Assault Grenades" []
@PointClass base(Weapon, Targetx) = ammo_357 : "357 Ammo" []
@PointClass base(Weapon, Targetx) = ammo_rpgclip : "RPG Ammo" []
@PointClass base(Weapon, Targetx) = ammo_gaussclip : "Gauss Gun Ammo" []
@PointClass base(Weapon, Targetx) = ammo_crossbow : "Crossbow Ammo" []

//
// Xen
//

@PointClass base(Target, Targetname, RenderFields) size(-48 -48 0, 48 48 32 ) = xen_plantlight : "Xen Plant Light" []
@PointClass base(Targetname, RenderFields) size(-8 -8 0, 8 8 32 ) = xen_hair : "Xen Hair" 
[
	spawnflags(Flags) = 
	[
		1 : "Sync Movement" 	: 0
	]
] @PointClass base(Targetname, RenderFields) size(-24 -24 0, 24 24 188 ) = xen_tree : "Xen Tree" []
@PointClass base(Targetname, RenderFields) size(-16 -16 0, 16 16 64 ) = xen_spore_small : "Xen Spore (small)" []
@PointClass base(Targetname, RenderFields) size(-40 -40 0, 40 40 120 ) = xen_spore_medium : "Xen Spore (medium)" []
@PointClass base(Targetname, RenderFields) size(-90 -90 0, 90 90 220 ) = xen_spore_large : "Xen Spore (large)" []



//melee
@PointClass iconsprite("sprites/am/armoury.spr")  base(Weapon, Targetx) = weapon_knife : "Crowbar" []
//deagle
@PointClass base(Weapon, Targetx) = weapon_deagle : "Desert Eagle cal 50." []
@PointClass base(Weapon, Targetx) = ammo_50cal : "50cal ammo" []
//colt 1911 a2
@PointClass base(Weapon, Targetx) = weapon_9mmhandgun : "9mm Handgun" []
@PointClass base(Weapon, Targetx) = ammo_9mmclip : "9mm Pistol Ammo" []
//ber92f
@PointClass base(Weapon, Targetx) = weapon_ber92f : "A silenced weapon" []
@PointClass base(Weapon, Targetx) = ammo_ber92f : "Ammo for MG" []
//glock18
@PointClass base(Weapon, Targetx) = weapon_glock18 : "Assault Shotgun" []
@PointClass base(Weapon, Targetx) = ammo_glock18clip : "Ammo" []
@PointClass base(Weapon, Targetx) = ammo_glock40shots : "40 shots!" []
//navy
@PointClass base(Weapon, Targetx) = weapon_mp5 : "9mm Assault Rifle" []
@PointClass base(Weapon, Targetx) = ammo_mp5clip : "9mm Assault Rifle Ammo" []
//p90
@PointClass base(Weapon, Targetx) = weapon_bizon : "Assault Shotgun" []
@PointClass base(Weapon, Targetx) = ammo_bizonclip : "Ammo" []
//uzi
@PointClass iconsprite("sprites/am/wep_uzi.spr") base(Weapon, Targetx) = weapon_uzi : "Uzi weapon" []
@PointClass base(Weapon, Targetx) = ammo_uziclip : "9mm CLIP UZi" []
//ak47
@PointClass iconsprite("sprites/am/wep_ak47.spr") base(Weapon, Targetx) = weapon_AK47 : "AK74 warfare" 
[
	m_iszModel(string) : "Custom Models v_ p_ w_ (name ej: ak47)"
]
@PointClass base(Weapon, Targetx) = ammo_AK47 : "AK74 Ammo" []
//m4a1
@PointClass base(Weapon, Targetx) = weapon_m4a1 : "M16 Assault Rifle" []
@PointClass base(Weapon, Targetx) = ammo_m4a1 : "m16 Ammo" []
//fa-mas
@PointClass base(Weapon, Targetx) = weapon_famas : "FAMAS" []
@PointClass base(Weapon, Targetx) = ammo_556 : "Ammo .556" []
//escopeta
@PointClass base(Weapon, Targetx) = weapon_shotgun : "Shotgun" []
@PointClass base(Weapon, Targetx) = ammo_buckshot : "Shotgun Ammo" [] //usas
@PointClass base(Weapon, Targetx) = weapon_usas : "Assault Shotgun" []
@PointClass base(Weapon, Targetx) = ammo_usasclip : "Ammo" []
//sig 3000
@PointClass base(Weapon, Targetx) = weapon_sniper : "SIG SGG 3000" []
@PointClass base(Weapon, Targetx) = ammo_sniper : "Sig ammo" []
//
@PointClass base(Weapon, Targetx) = weapon_M249 : "MACHINE GUN" []
@PointClass base(Weapon, Targetx) = ammo_M249 : "Ammo for MG" []
@PointClass base(Weapon, Targetx) = weapon_c4 : "c4" []
@PointClass base(Weapon, Targetx) = weapon_heal : "health" []
@PointClass base(Weapon, Targetx) = ammo_healclip : "health" []
@PointClass iconsprite("sprites/am/extended.spr") base(Weapon, Targetx) = item_all_silencer : "Silencer" []
@PointClass iconsprite("sprites/am/extended.spr") base(Weapon, Targetx) = item_ber92f_silencer : "Silencer" []
@PointClass iconsprite("sprites/am/extended.spr") base(Weapon, Targetx) = item_mp5_silencer : "Silencer" []
@PointClass iconsprite("sprites/am/extended.spr") base(Weapon, Targetx) = item_m4a1_silencer : "Silencer" []
@PointClass iconsprite("sprites/am/extended.spr") base(Weapon, Targetx) = item_uzi_silencer : "Silencer" []
@PointClass size(-16 -16 0, 16 16 36) base(Weapon, Targetx) = item_parachute : "paracaidas" []
@PointClass size(-16 -16 0, 16 16 36) base(Weapon, Targetx) = item_nvg : "NVG al fin" []


@PointClass base(Targetname) = ambient_fmodstream: "FMOD Audio player (MP3/OGG/WMA)"
[
     message(string) : "File Name"
     spawnflags(flags) =
     [
          1: "Remove on fire" : 0
     ]
]

@PointClass iconsprite("sprites/am/envtele.spr") base(Targetname) = env_teleport: "Teleport-in effect"
[
      target(string) : "Initial position (SyS: not used yet)"
	health(string) : "Max lightning-arc length" : "90"
	frags(integer) : "Number of lightning bolts" : 12
]

@PointClass iconsprite("sprites/am/envfade.spr") base(Targetname) = env_fade : "Screen Fade" 
[
	spawnflags(flags) =
	[
		1: "Fade From" : 0
		2: "Modulate" : 0
		4: "Activator Only" : 0
		8: "Permanente"	  : 0
	]
	duration(string) : "Duration (seconds)" : "2"
	holdtime(string) : "Hold Fade (seconds)" : "0"
	renderamt(integer) : "Fade Alpha" : 255
	rendercolor(color255) : "Fade Color (R G B)" : "0 0 0"
]
@PointClass base(Targetname) = env_fog : "Fog effect, DMC stylee"
[
	fadein(integer) : "Fade in time" : 0
	holdtime(string) : "Hold time (0 = permanent)" : "0"
	fadeout(integer) : "Fade out time" : 0
	startdist(integer) : "Fog start position" : 0
      enddist(integer) : "Fog end position" : 1000
	rendercolor(color255) : "Fog Color (R G B)" : "255 255 255"
	spawnflags(flags) =
	[
		1: "Start active" : 0
	]
]
@SolidClass base(Targetname) = env_rain : "Rain Effect"
[
	//* Set this to (for example) "70 0 0" to make slanted rain.
	//angles(string) : "Pitch Yaw Roll (Y Z X)" : "90 0 0"//70 o 0
	angles(choices) : "Direccion de las gotas" : "90 0 0" =
	[
		"90 0 0" : "-ABAJO- Linea recta"
		"80 0 0" : "-ABAJO- Ligeramente Inclinadas"
		"60 0 0" : "-ABAJO- Inclinadas"
		"-90 0 0" : "-ARRIBA- (?) Linea recta"
	]
	//* Negative numbers will make the rain fall upwards.
	//* This is an average; each drip will move at between 75%-125% of this speed.
	m_dripSpeed(integer) : "Drip Speed" : 40
	m_dripSize(integer) : "Drip Width" : 5
	m_brightness(integer) : "Drip Brightness (1 - 255)" : 128
	rendercolor(color255) : "Drip Color (R G B)" : "64 128 255"
	//m_iNoise(integer) : "Beam noise (distortion)" : 0
	m_iNoise(choices) : "Movimiento de las gotas" : "0" =
	[
		"0" : "Nulo"
		"50" : "Medio"
		"100" : "Violento"
	]
	m_burstSize(integer) : "Number of drips per update" : 2
	//* If 0, no updates; all the beams will appear as soon as it's activated.
	m_flUpdateTime(string) : "Time between updates" : "0.5"
	m_flMaxUpdateTime(string) : "Max time between updates (random)"
	target(string) : "Fire on updating"
	m_fLifeTime(string) : "Beam Lifetime (0 = three updates)"
	//texture(sprite) : "Drip Sprite" : "sprites/rain.spr"
	texture(choices) : "Sprite de lluvia o nieve" : "sprites/efectos/rain.spr" =
	[
		"sprites/efectos/rain.spr" : "Lluvia Com�n (media calidad)"
		"sprites/efectos/rain_cs.spr" :"Lluvia Estilo CS (alta calidad)"
		"sprites/efectos/rain_big.spr": "Lluvia Abarcativa (baja calidad)"
		"sprites/efectos/snowflake.spr": "Nieve Estilo CS"
		"sprites/efectos/rainsplash.spr": "Vapor de lluvia (splash)"
		"NULL" : "-Other- -Enter model name here-"
	]
	m_axis(choices) : "Beam Direction" : 0 =
	[
		0 : "Z axis (vertical)"
		1 : "X axis"
		2 : "Y axis"
	]
	m_iExtent(choices) : "Extent type" : 0 =
	[
		0 : "Fill brush"
		1 : "-NO DISPONIBLE-Obstructable"
		3 : "-NO DISPONIBLE-Reverse obstructable"
		2 : "-NO DISPONIBLE-Arcing"
		4 : "-NO DISPONIBLE-Reverse arcing"
	]
	spawnflags(Flags) = 
	[
		1 : "Start Off" 	: 0
	]
]
@PointClass sprite() base(Targetname, RenderFields) iconsprite("sprites/am/ikgrass1.spr") = env_sprite_grass : "Sprite Effect" 
[
	spawnflags(flags) =
	[
		8: "Don't use LOD" : 0
		16: "Use LOD High" : 0
		32: "Use LOD Low" : 0

	//	64: "Low Light" : 0
	//	128: "Snow" : 0

		1024: "DEBUG MODE" : 0
	]
	model(studio) : "Sprite" : "sprites/Grass_Normal.spr"
]

@PointClass sprite() base(Targetname, Angles, RenderFields) size (-4 -4 -4, 4 4 4) iconsprite("sprites/env.spr") = env_particle : "Particle Effect"
[
	message(string) : "Particle file" : "aurora/smoke.aur"
	spawnflags(flags) =
	[
		1: "Start On" : 0
		2: "Spawn Use" : 0
	]
]
@PointClass iconsprite("sprites/am/sunflare.spr") base(Targetname) = env_sunflare : "Trigger when A sees B"
[
	spawnflags(flags) =
	[
		8: "Fade Screen" : 0
		16: "Change Colors" : 0
		32: "Cheap Sunflare" : 0
	]

	scale(string) : "Scale (0=Normal)" : "5"
	rendercolor(color255) : "FX Color (R G B)" : "255 255 150"
	renderamt(integer) : "FX Amount (1 - 255)"
]
@PointClass base(Targetname) iconsprite("sprites/am/env.spr") = env_sky : "Unreal-Tournament style sky view"
[
]

@PointClass base(Targetname, Angles, RenderFields) studio() = env_model : "New alternative to cyclers"
[	
	model(studio) : "Modelo" : "models/PROPS/ERROR.MDL"
	skin(integer) : "Skin" : 0
	body(integer) : "Body" : 0
	m_iszSequence_On(string) : "Sequence when on"
	m_iAction_On(choices) : "Behaviour when on" : 0 =
	[
		0: "Freeze when sequence ends"
		1: "Loop"
		2: "Change state when sequence ends"
	]
	m_iszSequence_Off(string) : "Sequence when off"
	m_iAction_Off(choices) : "Behaviour when off" : 0 =
	[
		0: "Freeze when sequence ends"
		1: "Loop"
		2: "Change state when sequence ends"
	]
	sequence(string)  : "Animacion Test -solo editor-"

	rendercolor(color255) : "Light Color (R G B)" : "255 255 255"
	scale(integer) : "Light Radius" : 15

	spawnflags(flags) =
	[
		1: "Initially Off" : 1
		2: "Drop to Floor" : 0
		4: "Solid" : 0

		8: "Don't use LOD" : 0
		16: "Use LOD High" : 0
		32: "Use LOD Low" : 0
		64: "Don't Check FOV" : 0
		128: "Create Light" : 0
	]
]
@PointClass = env_smoker : "humo"
[
	health(string)  : "Cuantas bolas?" : 9999999999999
	scale(string)  : "Tama�o" : 46
	dmg(string)  : "Distribucion Radial" : 10
]

@PointClass base(Monster, TalkMonster) size(-16 -16 0, 16 16 72) color(170 170 170) = hostage_male : "Scared Scientist" 
[
      body(Choices) : "Body" : -1 =
	[
		-1 : "Random"
		0 : "Glasses"
		1 : "Einstein"
		2 : "Luther"
		3 : "Slick"
	]
	model(studio) : "Modelo" : "models/hostage_male.mdl"
]
@PointClass base(Monster) size(-14 -14 22, 14 14 72) = hostage_male_sitting : "Sitting Scientist" 
[
      body(Choices) : "Body" : -1 =
	[
		-1 : "Random"
		0 : "Young men"
		1 : "Japanese"
		2 : "Worker"
		3 : "Old Men"
	]
]
@PointClass base(Appearflags,RenderFields) size(-16 -16 0, 16 16 72) = hostage_male_dead : "Dead Scientist" 
[
      pose(Choices) : "Pose" : 0 =
	[
		0 : "On back"
		1 : "On Stomach"
		2 : "Sitting"
		3 : "Hanging"
		4 : "Table1"
		5 : "Table2"
		6 : "Table3"
	]
]

@PointClass base(Targetname) = hud_sprite : "Hud Sprite Display"
[
	model(choices) : "Icono de Sprite" : "icon_radio" =
	[
		"icon_radio" : "Llamada entrante (RADIO)"
		"dmg_bio" :	"dmg_bio"
		"dmg_poison" : "dmg_poison"
		"dmg_chem" : "dmg_chem"
		"dmg_cold" : "dmg_cold"
		"dmg_drown" : "dmg_drown"
		"dmg_heat" : "dmg_heat"
		"dmg_gas" : "dmg_gas" 
		"dmg_rad" : "dmg_rad"
		"dmg_shock" : "dmg_shock"	
		"none" : "-Other- -Enter model name here-"
	]
	rendercolor(color255) : "Color" : "255 255 255"
	spawnflags(flags) =
	[
		1: "Start on" : 0
	]
]
@PointClass iconsprite("sprites/am/TestEffect.spr") base(Targetname) = test_effect : "yellow charge" []

@PointClass base(Appearflags,RenderFields) size(-16 -16 0, 16 16 72) = monster_hgrunt_dead : "Dead Human Grunt" 
[
      pose(Choices) : "Pose" : 0 =
	[
		0 : "On stomach"
		1 : "On side"
		2 : "Seated"
	]
	body(Choices) : "Body" : 0 =
	[
		0 : "Grunt with Gun"
		1 : "Commander with Gun"
		2 : "Grunt no Gun"
		3 : "Commander no Gun"
	]
	model(studio) : "Modelo" : "models/hgrunt.mdl"
]



@PointClass base(RenderFields,Appearflags) size(-16 -16 0, 16 16 72) = monster_otis_dead : "Dead Otis" 
[
      pose(Choices) : "Pose" : 0 =
	[
		0 : "On back"
		1 : "On side"
		2 : "On stomach"
	]
]
//@PointClass base(Monster,TalkMonster) size(-16 -16 0, 16 16 72)color(0 50 205) = //monster_barney : "Barney" 
//[
//	model(studio) : "Modelo" : "models/barney.mdl"

//]
@PointClass base(RenderFields,Appearflags) size(-16 -16 0, 16 16 72) = monster_barney_dead : "Dead Barney" 
[
      pose(Choices) : "Pose" : 0 =
	[
		0 : "On back" 		1 : "On side"
		2 : "On stomach"
	]
	model(studio) : "Modelo" : "models/barney.mdl"
]
@PointClass base(Monster) size(-16 -16 0, 16 16 72) = monster_grunt_repel_de : "Human Grunt Mac (Repel)" []
@PointClass base(MonsterBa, TalkMonsterBa) size(-16 -16 0, 16 16 72) color(170 170 170) = monster_scientist : "Scared Scientist" 
[
      body(Choices) : "Body" : -1 =
	[
		-1 : "Random"
		0 : "Glasses"
		1 : "Einstein"
		2 : "Luther"
		3 : "Slick"
	]
	model(studio) : "Modelo" : "models/scientist.mdl"
]
@PointClass base(Appearflags,RenderFields) size(-16 -16 0, 16 16 72) = monster_scientist_dead : "Dead Scientist" 
[
      body(Choices) : "Body" : -1 =
	[
		-1 : "Random"
		0 : "Glasses"
		1 : "Einstein"
		2 : "Luther"
		3 : "Slick"
	]
      pose(Choices) : "Pose" : 0 =
	[
		0 : "On back"
		1 : "On Stomach"
		2 : "Sitting"
		3 : "Hanging"
		4 : "Table1"
		5 : "Table2"
		6 : "Table3"
	]
]
@PointClass base(Monster,MonsterCH) size(-16 -16 0, 16 16 72) = monster_alien_slave : "Vortigaunt" 
[
	netname(string) : "Squad Name"
	spawnflags(Flags) =
	[
		32 : "SquadLeader" : 0
		64 : "IgnorePlayer" : 0
	]
	model(studio) : "Modelo" : "models/islave.mdl"
	//m_iClass(choices) : "5"
]
@PointClass base(Monster,MonsterCH) size(-16 -16 0, 16 16 72) = monster_zombie : "Scientist Zombie" 
[
	model(studio) : "Modelo" : "models/zombie.mdl"

//	model(choices) : "Modelo" : "models/zombie.mdl" =
//	[
//		"models/zombie.mdl" : "Zombie Scientist "
//		"models/zombie_soldier.mdl" : "Zombie Soldier"
//		"models/zombie_barney.mdl" : "Zombie Barney"
//		"models/hgrunt_opfor.mdl" : "-Otro- -Enter model name here-"
//	]
]
@PointClass base(Monster,MonsterCH) size(-16 -16 0, 16 16 72) = monster_zombie_barney : "Scientist Zombie"  [
	model(studio) : "Modelo" : "models/zombie_barney.mdl"
]
@PointClass base(Monster,MonsterCH) size(-16 -16 0, 16 16 72) = monster_zombie_soldier : "Scientist Zombie" 
[
	model(studio) : "Modelo" : "models/zombie_soldier.mdl"
]
@PointClass base(Monster,MonsterCH) size(-16 -16 0, 16 16 72) = monster_zombie_human : "Scientist Zombie" 
[
	model(studio) : "Modelo" : "models/zombie_human.mdl"
]
@PointClass base(Monster) size(-360 -360 -172, 360 360 8) = monster_apache : "Apache" 
[
	spawnflags(Flags) = 
	[
		8 : "NoWreckage"	: 0
		64 : "Start Inactive" : 0
	]
	model(studio) : "Modelo" : "models/apache.mdl"
]

@PointClass base(Monster) size(-16 -16 0, 16 16 72) color (255 0 0) = monster_robot: "A securiry Robot"
[
	spawnflags(Flags) =
	[
		32 : "SquadLeader" : 0
	]
	netname(string) : "Nombre de Equipo"
	weapons(Choices) : "Armas" : 1 =
	[
		1 : "MP5"
		3 : "MP5 + HG"
		5 : "MP5 + GL"
		8 : "Escopeta"
		10 : "Escopeta + HG"
	]
	model(studio) : "Modelo" : "models/robot.mdl"
]
@PointClass base(Monster) size(-16 -16 0, 16 16 72) = monster_robot_repel : "rb (Repel)" []
@PointClass base(Appearflags,RenderFields) size(-16 -16 0, 16 16 72) = monster_robot_dead : "Dead Robot" 
[
      pose(Choices) : "Pose" : 0 =
	[
		0 : "On stomach"
		1 : "On side"
		2 : "Seated"
	]
	body(Choices) : "Body" : 0 =
	[
		0 : "Grunt with Gun"
		1 : "Commander with Gun"
		2 : "Grunt no Gun"
		3 : "Commander no Gun"
	]
	model(studio) : "Modelo" : "models/robot.mdl"
]

@PointClass base(MonsterBa,TalkMonsterBa) size(-16 -16 0, 16 16 72) = monster_barney : "Barney"
[
	frags(choices) : "Weapon" : 0 =
	[
		1 : "Beretta (normal)"
		2 : "Deagle"
		3 : "M4A1"
		4 : "Uzi"
		5 : "SPAS12"
	]
	spawnflags(Flags) =
	[
		1024: "Don't Drop Gun" : 0
	]
]
@PointClass base(Monster,MonsterCH) size(-16 -16 0, 16 16 72) color (255 0 0) = monster_sniper : "Human Grunt (camo)" 
[
	spawnflags(Flags) =
	[
		32 : "SquadLeader" : 0
		1024: "Don't Drop Gun" : 0
	]
	netname(string) : "Nombre de Equipo"
	weapons(Choices) : "Armas" : 1 =
	[
		1 : "Sniper"
		3 : "Sniper + HG"
		8 : "Glock18"
		10 : "Glock18 + HG"
	]
	model(studio) : "Modelo" : "models/sniper.mdl"
	skin(choices) : "Skin" : 0 = 
	[
		0 : "Artic"
		1 : "Desert"
		2 : "Jungle"
		3 : "Black"
	]
]
@PointClass base(Monster,MonsterCH) size(-16 -16 0, 16 16 72) color (255 0 0) = monster_sniper_dead : "Human Grunt (camo)" 
[
	spawnflags(Flags) =
	[
		32 : "SquadLeader" : 0
		1024: "Don't Drop Gun" : 0
	]
	netname(string) : "Nombre de Equipo"
	weapons(Choices) : "Armas" : 1 =
	[
		1 : "Sniper"
		3 : "Sniper + HG"
		8 : "Escopeta"
		10 : "Escopeta + HG"
	]
	model(studio) : "Modelo" : "models/sniper.mdl"
]

@PointClass base(Monster,MonsterCH) size(-16 -16 0, 16 16 72) color (255 0 0) = monster_male_assassin: "Human Grunt (camo)" 
[
	spawnflags(Flags) =
	[
		32 : "SquadLeader" : 0
		1024: "Don't Drop Gun" : 0
	]
	netname(string) : "Nombre de Equipo"
	weapons(Choices) : "Armas" : 1 =
	[
		1 : "COLT M16"
		3 : "COLT M16 + HG"
		8 : "SNIPER"
		10 : "SNIPER+ HG"
	]
	model(studio) : "Modelo" : "models/massn.mdl"
	//m_iClass(choices) : "5"
]

@PointClass base(Monster) size(-16 -16 0, 16 16 72) = monster_male_repel : "Human Grunt (Repel)" []
@PointClass base(Appearflags,RenderFields) size(-16 -16 0, 16 16 72) = monster_male_assassin_dead : "Dead Robot" 
[
      pose(Choices) : "Pose" : 0 =
	[
		0 : "On stomach"
		1 : "On side"
		2 : "Seated"
	]
	body(Choices) : "Body" : 0 =
	[
		0 : "Mask White with Gun"
		1 : "Mask Black with Gun"
		2 : "Mask White no Gun"
		3 : "Mask Black no Gun"
	]
	model(studio) : "Modelo" : "models/robot.mdl"
]


@PointClass base(Monster,MonsterCH) size(-16 -16 0, 16 16 72) = monster_bloater : "Bloater" []
@PointClass base(Monster,MonsterCH) size(-16 -16 -36, 16 16 36) = monster_generic : "Generic Script Monster" 
[
	spawnflags(Flags) = 
	[
		4 : "Not solid"	: 0
		//NEW 0.4
		//* Tick here if you're using a model from the models/player/ directories.
		//*   This option sets it up so that the model's bounding box is centered on its origin (the X in
		//* the middle of the entity, in WorldCraft), instead of being the middle of its bottom face.
		8 : "Player model" : 0
		//NEW 0.4
		32: "Invulnerable" : 0
	]
	//NEW 0.4
	//*   <b>Headcrab:</b> 24 24 24
	//*   <b>Houndeye:</b> 32 32 36
	//*   <b>Human:</b> 32 32 72
	//*   <b>Most Aliens:</b> 64 64 64
	size(string) : "Size (X Y Z)"
	//NEW 0.4
	//*   <b>Player:</b> 0 = gordon's head, 1 = hooded.
	//*   <b>Gina, Gordon, Helmet and Scientist player models:</b> 0 = original design, 1 = updated (better looking) version.
	//*   <b>Barneys:</b> 0 = holstered gun, 1 = holding gun, 2 = missing gun.
	//*   <b>Scientists:</b> 0-3 = no syringe, 4-7 = syringe in hand. 4 different heads in each set. (0 = Glasses, 1 = Einstein, 2 = Luther, 3 = Slick)
	//*   <b>Human Grunts:</b> 0-3 = Mp5, 4-7 = Shotgun, 8-11 = No gun. 4 different heads in each set. (0 = Gasmask, 1 = Beret, 2 = Skimask, 3 = Cigar)
	body(Integer) : "Body" : 0
	//NEW 0.4
	//* If not set, health is 8.
	health(Integer) : "Initial Health" : 0
	//NEW 0.4
	//* Experiment with other values (1-255) for different blood colors.
	m_bloodColor(choices) : "Blood Color" : 0 =
	[
		-1 : "Don't Bleed"
		0 : "Red (Human)"
		195 : "Yellow (Alien)"
	]
	//NEW 0.5
	//* If you don't specify a gib model, one will be chosen based on
	//* the Blood Colour you set.
	m_iszGibModel(string) : "Gib Model"
	model(studio) : "Modelo" : "models/MODELNAME.mdl"

]

//NEW 0.5
@PointClass base(Targetname, Angles, Appearflags,RenderFields) size(-16 -16 0, 16 16 72) = monster_generic_dead : "Generic Dead Body" 
[
	spawnflags(Flags) = 
	[
		8 : "Player model" : 0
	]
	//* The corpse's pose will be the last frame of this sequence.
	//* This overrides the 'death type' value.
	netname(string) : "Sequence name"
	//* If you don't specify a 'Sequence name', the monster will select a random death
	//* animation of the type you specify here. Not all models have all these death types.
	frags(choices): "Death Type" : 36 =
	[
		36 : "Just dead"
		37 : "Fell backwards"
		38 : "Fell forwards"
		39 : "Died violently"
		66 : "Head shot"
		67 : "Chest shot"
		68 : "Gut shot"
		69 : "Shot in the back"
	]
	//*   <b>Player:</b> 0 = gordon's head, 1 = hooded.
	//*   <b>Gina, Gordon, Helmet and Scientist player models:</b> 0 = original design, 1 = updated (better looking) version.
	//*   <b>Barneys:</b> 0 = holstered gun, 1 = holding gun, 2 = missing gun.
	//*   <b>Scientists:</b> 0-3 = no syringe, 4-7 = syringe in hand. 4 different heads in each set. (0 = Glasses, 1 = Einstein, 2 = Luther, 3 = Slick)
	//*   <b>Human Grunts:</b> 0-3 = Mp5, 4-7 = Shotgun, 8-11 = No gun. 4 different heads in each set. (0 = Gasmask, 1 = Beret, 2 = Skimask, 3 = Cigar)
	body(Integer) : "Body" : 0
	//* Experiment with other values (1-255) for different blood colors.
	m_bloodColor(choices) : "Blood Color" : 0 =
	[
		-1 : "Don't Bleed"
		0 : "Red (Human)"
		195 : "Yellow (Alien)"
	]
	//* If you don't specify a gib model, one will be chosen based on
	//* the Blood Colour you set.
	m_iszGibModel(string) : "Gib Model"
	model(studio) : "Modelo" : "models/MODELNAME.mdl"
]


@PointClass base(Monster,MonsterCH) size(-16 -16 0, 16 16 72) color (255 0 0) = monster_human_rpg: "Human Grunt (camo)" 
[
	spawnflags(Flags) =
	[
		32 : "SquadLeader" : 0
		1024: "Don't Drop Gun" : 0
	]
	netname(string) : "Nombre de Equipo"
	weapons(Choices) : "Armas" : 8 =
	[
		8 : "RPG"
		10 : "RPG + HE"
	]
	model(studio) : "Modelo" : "models/human_rpg.mdl"
	//m_iClass(choices) : "5"
]

@PointClass base(Monster) size(-16 -16 0, 16 16 72) = monster_human_rpg_repel : "Human Grunt (Repel)" []
@PointClass base(Appearflags,RenderFields) size(-16 -16 0, 16 16 72) = monster_human_rpg_dead : "Dead Robot" []


@PointClass base(Monster,MonsterCH)size(-16 -16 0, 16 16 72) color(255 0 0)  = monster_human_ak : "Human Grunt whit Ak (camo)" 
[
	spawnflags(Flags) =
	[
		32 : "SquadLeader" : 0
		1024: "Don't Drop Gun" : 0

	]
	netname(string) : "Squad Name"
	weapons(Choices) : "Weapons" : 1 =
	[
		1 : "AK-47"
		3 : "AK-47 + HE"
		8 : "Shotgun"
		10 : "Shotgun + HG"
		//12 : "Escopeta + GL"
		16 : "SAW"
		18 : "SAW + HG"
	]
	model(studio) : "Modelo" : "models/human_ak.mdl"
	skin(choices) : "Skin" : 1 = 
	[
		0 : "Artic"
		1 : "Desert"
		2 : "Jungle"
		3 : "Black"
	]
]
@PointClass base(Monster) size(-16 -16 0, 16 16 72) = monster_human_ak : "Human Grunt AK (Repel)" []
@PointClass base(Monster) size(-16 -16 0, 16 16 72) = monster_human_ak_dead : "Human Grunt AK (Repel)" []

@PointClass base(Monster,MonsterCH)size(-16 -16 0, 16 16 72) color(0 50 205)  = monster_ct_m4a1 : "Human Grunt whit Ak (camo)" 
[
	spawnflags(Flags) =
	[
		32 : "SquadLeader" : 0
		1024: "Don't Drop Gun" : 0

	]
	netname(string) : "Squad Name"
	weapons(Choices) : "Weapons" : 1 =
	[
		1 : "M4A1"
		3 : "M4A1 + HE"
		8 : "Shotgun"
		10 : "Shotgun + HG"
	]
	model(studio) : "Modelo" : "models/human_m4a1.mdl"
	skin(choices) : "Skin" : 1 = 
	[
		1 : "-1-"
		2 : "-2-"
		3 : "-3-"
		4 : "-4-"
	]
]
@PointClass base(Monster) size(-16 -16 0, 16 16 72) = monster_ct_m4a1_repel : "Human Grunt AK (Repel)" []
@PointClass base(Monster) size(-16 -16 0, 16 16 72) = monster_ct_m4a1_dead : "Human Grunt AK (Repel)" []
@PointClass color(0 200 200) base(Targetname) size(-16 -16 -16, 16 16 16) = monster_target : "Target for monsters to attack"
[
	targetname(target_source) : "Name (para ser activado/desactivado)"

	frags(choices) : "Al activarse ser como:" : 16 =
	[
		0 : "Ignored"
		3 : "Scientist"
		11: "Barney"
		4 : "Human Military"
		5 : "Alien Military"
		7 : "Other Alien"
		8 : "Headcrab"
		9 : "Bullsquid"
		14 : "Faction A"
		15 : "Faction B"
		16 : "Faction C"
	]
	spawnflags(Flags) =
	[
		1: "Start inactive" : 0
	]
]
@PointClass base(Monster) size(-24 -24 0, 24 24 32) = monster_shocktrooper : "Shock Trooper" 
[
    netname(string) : "Squad Name"
    spawnflags(Flags) =
    [
        32 : "SquadLeader" : 0
	1024: "No Shockroach" : 0
    ]
	weapons(Choices) : "Weapons" : 1 =
	[
		1 : "Shockroach"
	]
]

@PointClass base(Monster) size(-6 -6 0, 6 6 6) = monster_rat : "Better Ai"[]
@PointClass base(Monster) size(-16 -16 0, 16 16 16) = monster_bird: "Flock of Flyers" []	
@PointClass base(Monster) size(-16 -16 0, 16 16 16) = monster_bird_flock : "Flock of Flyers" 
[
	spawnflags(Flags) = 
	[
		2 : "NO hacer sonidos"	: 0
	]

	iFlockSize(Integer) : "Numero de Aves" : 8
	flFlockRadius(Integer) : "Radio a volar" : 256
	model(studio) : "Modelo" : "models/bird.mdl"
]


@PointClass base(Monster,MonsterCH) size(-16 -16 0, 16 16 72) = monster_gonome : "Scientist Zombie" 
[
	model(studio) : "Modelo" : "models/gonome.mdl"

]

@PointClass base(MonsterBa,TalkMonsterBa) size(-16 -16 0, 16 16 72) = monster_friend : "Friend"
[
	frags(choices) : "Weapon" : 0 =
	[
		0 : "-Mp5-"
		1 : "-Usas-"
	]
	spawnflags(Flags) =
	[
		1024: "Don't Drop Gun" : 0
	]
]
@PointClass base(MonsterBa,TalkMonsterBa) size(-16 -16 0, 16 16 72) = monster_ct_m4a1_ally : "Friend"
[
	frags(choices) : "Weapon" : 0 =
	[
		0 : "M4A1"
		1 : "SHOTGUN"
	]
	spawnflags(Flags) =
	[
		1024: "Don't Drop Gun" : 0
	]
]
@PointClass base(MonsterBa,TalkMonsterBa) size(-16 -16 0, 16 16 72) = monster_scientist_crowbar : "Friend"
[
      body(Choices) : "Body" : -1 =
	[
		-1 : "Random"
		0 : "Glasses"
		1 : "Einstein"
		2 : "Luther"
		3 : "Slick"
	]
	frags(choices) : "Weapon" : 0 =
	[
		0 : "Crowbar"
	]
	spawnflags(Flags) =
	[
		1024: "Don't Drop Gun" : 0
	]
]

@PointClass base(Monster, MonsterCH) size(-32 -32 0, 32 32 128) = monster_mini_gargantua : "Gargantua" 
[
	model(studio) : "Modelo" : "models/minigarg.mdl"

]

@PointClass base(Monster,MonsterCH) size(-16 -16 0, 16 16 72) color (255 0 0) = monster_soldier_russian : "Human Grunt (camo)" 
[
	spawnflags(Flags) =
	[
		32 : "SquadLeader" : 0
		1024: "No arrojar arma" : 0
	]
	netname(string) : "Nombre de Equipo"

	weapons(Choices) : "Armas" : 0 =
	[
		0 : "-AL AZAR-"
		1 : "M16"
		3 : "M16 + HG"
		5 : "M16 + GL"
		8 : "Escopeta"
		10 : "Escopeta + HG"
	]

	model(studio) : "Modelo" : "models/hgrunt_film.mdl"
	frags(Choices) : "Version de Modelo (modelo = version)!": 0 =
	[
		0 : "Original Grunt"
	]
]
@PointClass base(Monster,MonsterCH) size(-16 -16 0, 16 16 72) color (255 0 0) = monster_human_grunt : "Human Grunt (camo)" 
[
	spawnflags(Flags) =
	[
		32 : "SquadLeader" : 0
		1024: "No arrojar arma" : 0
	]
	netname(string) : "Nombre de Equipo"

	weapons(Choices) : "Armas" : 0 =
	[
		0 : "-AL AZAR-"
		1 : "MP5"
		3 : "MP5 + HG"
		5 : "MP5 + GL"
		8 : "Escopeta"
		10 : "Escopeta + HG"
	]

	model(studio) : "Modelo" : "models/hgrunt.mdl"

	frags(Choices) : "Version de Modelo (modelo = version)!": 0 =
	[
		0 : "Original Grunt"
	]
]
@PointClass base(Monster,MonsterCH) size(-16 -16 0, 16 16 72) color (255 0 0) = monster_human_grunt_swat : "Human Grunt (camo)" 
[
	spawnflags(Flags) =
	[
		32 : "SquadLeader" : 0
		1024: "No arrojar arma" : 0
	]
	netname(string) : "Nombre de Equipo"

	weapons(Choices) : "Armas" : 0 =
	[
		0 : "-AL AZAR-"
		1 : "M16"
		3 : "M16 + HG"
		5 : "M16 + GL"
		8 : "Escopeta"
		10 : "Escopeta + HG"
		//12 : "Escopeta + GL"
		16 : "SAW"
		18 : "SAW + HG"
	]

	model(studio) : "Modelo" : "models/hgrunt/swat/hgrunt.mdl"
	frags(Choices) : "Version de Modelo (modelo = version)!": 0 =
	[
		0 : "Original Grunt"
	]
]
@PointClass base(Monster,MonsterCH) size(-16 -16 0, 16 16 72) color (255 0 0) = monster_human_grunt_jungle : "Human Grunt (camo)" 
[
	spawnflags(Flags) =
	[
		32 : "SquadLeader" : 0
		1024: "No arrojar arma" : 0
	]
	netname(string) : "Nombre de Equipo"

	weapons(Choices) : "Armas" : 0 =
	[
		0 : "-AL AZAR-"
		1 : "M16"
		3 : "M16 + HG"
		5 : "M16 + GL"
		8 : "Escopeta"
		10 : "Escopeta + HG"
	]

	model(studio) : "Modelo" : "models/hgrunt/jungle/hgrunt.mdl"
	frags(Choices) : "Version de Modelo (modelo = version)!": 0 =
	[
		0 : "Original Grunt"
	]
] @PointClass base(Monster,MonsterCH) size(-16 -16 0, 16 16 72) color (255 0 0) = monster_hgrunt_opfor : "Human Grunt (camo)" 
[
	spawnflags(Flags) =
	[
		32 : "SquadLeader" : 0
		1024: "No arrojar arma" : 0
	]
	netname(string) : "Nombre de Equipo"

	weapons(Choices) : "Armas" : 0 =
	[
		0 : "-AL AZAR-"
		1 : "M16"
		3 : "M16 + HG"
		5 : "M16 + GL"
		8 : "Escopeta"
		10 : "Escopeta + HG"
		//12 : "Escopeta + GL"
		16 : "SAW"
		18 : "SAW + HG"
	]

	model(studio) : "Modelo" : "models/hgrunt_opfor.mdl"
	frags(Choices) : "Version de Modelo (modelo = version)!": 1 =
	[
		1 : "Opposing Force Grunt"
	]
]
@PointClass base(Monster,MonsterCH) size(-16 -16 0, 16 16 72) color (255 0 0) = monster_hgrunt_opfor_usmc : "Human Grunt (camo)" 
[
	spawnflags(Flags) =
	[
		32 : "SquadLeader" : 0
		1024: "No arrojar arma" : 0
	]
	netname(string) : "Nombre de Equipo"

	weapons(Choices) : "Armas" : 0 =
	[
		0 : "-AL AZAR-"
		1 : "M16"
		3 : "M16 + HG"
		5 : "M16 + GL"
		8 : "Escopeta"
		10 : "Escopeta + HG"
		//12 : "Escopeta + GL"
		16 : "SAW"
		18 : "SAW + HG"
	]

	model(studio) : "Modelo" : "models/hgrunt/usmc/hgrunt_opfor.mdl"
	frags(Choices) : "Version de Modelo (modelo = version)!": 1 =
	[
		1 : "Opposing Force Grunt"
	]
]
@PointClass base(Monster,MonsterCH) size(-16 -16 0, 16 16 72) color (255 0 0) = monster_hgrunt_opfor_snow : "Human Grunt (camo)" 
[
	spawnflags(Flags) =
	[
		32 : "SquadLeader" : 0
		1024: "No arrojar arma" : 0
	]
	netname(string) : "Nombre de Equipo"

	weapons(Choices) : "Armas" : 0 =
	[
		0 : "-AL AZAR-"
		1 : "M16"
		3 : "M16 + HG"
		5 : "M16 + GL"
		8 : "Escopeta"
		10 : "Escopeta + HG"
		//12 : "Escopeta + GL"
		16 : "SAW"
		18 : "SAW + HG"
	]

	model(studio) : "Modelo" : "models/hgrunt/snow/hgrunt_opfor.mdl"

	frags(Choices) : "Version de Modelo (modelo = version)!": 1 =
	[
		1 : "Opposing Force Grunt"
	]
]
@PointClass base(Monster,MonsterCH) size(-16 -16 0, 16 16 72) color (255 0 0) = monster_hgrunt_opfor_desert : "Human Grunt (camo)" 
[
	spawnflags(Flags) =
	[
		32 : "SquadLeader" : 0
		1024: "No arrojar arma" : 0
	]
	netname(string) : "Nombre de Equipo"

	weapons(Choices) : "Armas" : 0 =
	[
		0 : "-AL AZAR-"
		1 : "M16"
		3 : "M16 + HG"
		5 : "M16 + GL"
		8 : "Escopeta"
		10 : "Escopeta + HG"
		//12 : "Escopeta + GL"
		16 : "SAW"
		18 : "SAW + HG"
	]

	model(studio) : "Modelo" : "models/hgrunt/desert/hgrunt_opfor.mdl"

	frags(Choices) : "Version de Modelo (modelo = version)!": 1 =
	[
		1 : "Opposing Force Grunt"
	]
]


@PointClass base(Monster,MonsterCH) size(-16 -16 0, 16 16 72) = monster_pit_drone : "Scientist Zombie" 
[
	model(studio) : "Modelo" : "models/pit_drone.mdl"
]
@PointClass base(MonsterBa, TalkMonsterBa) size(-16 -16 0, 16 16 72) color(0 50 205)  = monster_otis : "Men!"
[
	frags(choices) : "Weapon" : 0 =
	[
		1 : "Desert Eagle"
	]
	SpeakAs(choices) : "Hablar como -XX_...-" : "HGPI"
	model(studio) : "Modelo" : "models/otis.mdl"
]
@PointClass base(MonsterBa, TalkMonsterBa) size(-16 -16 0, 16 16 72) color(0 50 205)  = monster_barney_mp5 : "Barney whit new weapons"
[
	frags(choices) : "Weapon" : -1 =
	[
		-1 : "Random"
		1 : "IMI UZI"
		2 : "MP5"
		3 : "M4A1"
	]
	SpeakAs(choices) : "Hablar como -XX_...-" : "BA"
	model(studio) : "Modelo" : "models/barney_mp5.mdl"
]

@PointClass base(Monster,MonsterCH)size(-16 -16 0, 16 16 72) color(0 50 205)  = monster_ally_swat_mp5 : "Human Grunt whit Ak (camo)" 
[
	spawnflags(Flags) =
	[
		32 : "SquadLeader" : 0
		1024: "Don't Drop Gun" : 0

	]
	netname(string) : "Squad Name"

	model(studio) : "Modelo" : "models/swat.mdl"
]
@PointClass base(Monster,MonsterCH)size(-16 -16 0, 16 16 72) color(0 50 205)  = monster_ally_swat_shotgun : "Human Grunt whit Ak (camo)" 
[
	spawnflags(Flags) =
	[
		32 : "SquadLeader" : 0
		1024: "Don't Drop Gun" : 0

	]
	netname(string) : "Squad Name"

	model(studio) : "Modelo" : "models/swat.mdl"
]
@PointClass base(Monster,MonsterCH)size(-16 -16 0, 16 16 72) color(0 50 205)  = monster_ally_swat_law : "Human Grunt whit Ak (camo)" 
[
	spawnflags(Flags) =
	[
		32 : "SquadLeader" : 0
		1024: "Don't Drop Gun" : 0

	]
	netname(string) : "Squad Name"

	model(studio) : "Modelo" : "models/swat.mdl"
]
@PointClass base(Monster,MonsterCH)size(-16 -16 0, 16 16 72) color(0 50 205)  = monster_ally_swat_sniper : "Human Grunt whit Ak (camo)" 
[
	spawnflags(Flags) =
	[
		32 : "SquadLeader" : 0
		1024: "Don't Drop Gun" : 0

	]
	netname(string) : "Squad Name"

	model(studio) : "Modelo" : "models/swat.mdl"
]
@PointClass base(Monster,MonsterCH)size(-16 -16 0, 16 16 72) color(0 50 205)  = monster_ally_swat_assault : "Human Grunt whit Ak (camo)" 
[
	spawnflags(Flags) =
	[
		32 : "SquadLeader" : 0
		1024: "Don't Drop Gun" : 0

	] 	netname(string) : "Squad Name"

	model(studio) : "Modelo" : "models/swat.mdl"
]
@PointClass base(Monster,MonsterCH)size(-16 -16 0, 16 16 72) color(0 50 205)  = monster_ally_swat_pistol : "Human Grunt whit Ak (camo)" 
[
	spawnflags(Flags) =
	[
		32 : "SquadLeader" : 0
		1024: "Don't Drop Gun" : 0

	]
	netname(string) : "Squad Name"

	model(studio) : "Modelo" : "models/swat.mdl"
]
@PointClass base(Monster,MonsterCH)size(-16 -16 0, 16 16 72) color(0 50 205)  = monster_ally_swat_machete : "Human Grunt whit Ak (camo)" 
[
	spawnflags(Flags) =
	[
		32 : "SquadLeader" : 0
		1024: "Don't Drop Gun" : 0

	]
	netname(string) : "Squad Name"

	model(studio) : "Modelo" : "models/swat.mdl"
]
@PointClass base(Monster,MonsterCH)size(-16 -16 0, 16 16 72) color(0 50 205)  = monster_ally_swat_m249 : "Human Grunt whit Ak (camo)" 
[
	spawnflags(Flags) =
	[
		32 : "SquadLeader" : 0
		1024: "Don't Drop Gun" : 0

	]
	netname(string) : "Squad Name"

	model(studio) : "Modelo" : "models/swat.mdl"
]
@PointClass base(Monster,MonsterCH)size(-16 -16 0, 16 16 72) color(0 50 205)  = monster_ally_swat_smg : "Human Grunt whit Ak (camo)" 
[
	spawnflags(Flags) =
	[
		32 : "SquadLeader" : 0
		1024: "Don't Drop Gun" : 0

	]
	netname(string) : "Squad Name"

	model(studio) : "Modelo" : "models/swat.mdl"
]



//NEW 0.5
@PointClass base(Targetname) = trigger_command : "Console Command"
[
	netname(string) : "Command String"
]
@PointClass base(Targetname) = trigger_changecvar : "Change Console Variable"
[
	netname(string) : "CVar to change"
	message(string) : "Value to set"
	armorvalue(string) : "Duration (-1 = until triggered)"
]
@PointClass base(Targetname) = trigger_changevalue : "Change any entity's values"
[
	target(string) : "Entidad a cambiar"
	netname(string) : "Nuevo Keyname"
	m_iszNewValue(string) : "Nuevo valor a Setear"
]

@PointClass base(Targetname) = trigger_displaymenu: "Wep Menu Selection" []

@PointClass base(Targetname) = trigger_dialogue : "dialogue whit others"
[
	noise(string) : "Their Initial Question" : "INITIALQUEST"

	message(string) : "My Responses List" : "DEFAULT_LIST"

	noise1(string) : "Their First Response" : "HISRESPONSE1"
	noise2(string) : "Their Second Response" : "HISRESPONSE2" 	noise3(string) : "Their Third Response" : "HISRESPONSE3"

	delay_their_response(string) : "Delay before their response" : "5"
	
	response_one_points(Choices) : "Points whit my First Response" : 1 =
	[
		1 : "1 point"
		5 : "5 points"
		10 : "10 points"
		0 : "No points"
		-1 : "1 point less"
		-5 : "5 points less"
		-10 : "10 points less"
	]
	response_two_points(Choices) : "Points whit my Second Response" : 1 =
	[
		1 : "1 point"
		5 : "5 points"
		10 : "10 points"
		0 : "No points"
		-1 : "1 point less"
		-5 : "5 points less"
		-10 : "10 points less"
	]
	response_third_points(Choices) : "Points whit my Third Response" : 1 =
	[
		1 : "1 point"
		5 : "5 points"
		10 : "10 points"
		0 : "No points"
		-1 : "1 point less"
		-5 : "5 points less"
		-10 : "10 points less"
	]
	response_one_fire(string) : "Fire after my 1 Response"
	response_two_fire(string) : "Fire after my 2 Response"
	response_third_fire(string) : "Fire after my 3 Response"
	
	fire_after(string) : "Fire this Target..." : "nextdialogue_1"

	fire_after_delay(string) : "...after this time" : "2"

	spawnflags(flags) =
	[
		1: "Remove when d. ends" : 0
		2: "Don't send Cinebars" : 0
	]
]
@PointClass base(Targetname) = trigger_dialogcheck : "checks the points of the dialogue"
[
	points_needed(Choices) : "Total Points Needed" : 20 =
	[
		1 : "1 point"
		5 : "5 points"
		10 : "10 points"
		15 : "15 points"
		20 : "20 points"
		25 : "25 points"
		30 : "30 points"
		40 : "40 points"
		50 : "50 points"
	]
	fire_points_good(string) : "If points >= needed, fire..."  : "dialogue_good"
	fire_points_bad(string) : "If points < needed, fire..."  : "dialogue_bad"

	reset_total_points(Choices) : "Reset the total points?" : 1 =
	[
		1 : "Yes, I need new points for other dialogue"
		0 : "No, I will use it later..."
	]
]

@PointClass base(Targetname) = trigger_onsight : "Trigger when A sees B"
[
	//* Put the targetname of the entity whose eyes the trigger_onsight should look through.
	//*   (if you want to trigger when the trigger_onsight itself sees something, i.e.
	//* simulating a security camera, put the name of the trigger_onsight.)
	netname(string) : "Looking entity (blank=player)"
	//* Leave this blank to have it trigger when something sees the trigger_onsight.
	//*   You can also put a classname here, to trigger when the Looking Entity sees
	//* any entity of that class.
	message(string) : "Entity/classname to look at"
	target(string) : "Fire when seen"
	noise(string) : "Fire when no longer seen"
	noise1(string) : "Fire on/off (seen/not seen)"
	frags(string) : "View range (0=unlimited)" : "512"
	//* Currently, only the horizontal view will be checked.
	max_health(choices) : "Field of view (degrees)" : 90 =
	[
		-1 : "(-1): Use monster's view"
	]
	spawnflags(flags) =
	[
		//* Don't check line of sight: i.e. it doesn't matter if there's something
		//* in the way.
		1: "No LOS check" : 0
		2: "Seethru glass" : 0
	]
]

@PointClass base(Targetname) = trigger_changebrief_info : "Una perezosa manera de hacer mis cosas"
[		
	netname(choices) : "Texto a mostrar..." : "MAPS/Training/tr_welcome01.txt" =
	[
		"mp_am_brief MAPS/Training/tr_welcome01.txt" : "Bienvenido..."
		"mp_am_brief MAPS/Training/tr_movement01.txt" : "Avanzar, retroceder..."
		"mp_am_brief MAPS/Training/tr_movement02.txt" : "Saltar..."
		"mp_am_brief MAPS/Training/tr_movement03.txt" : "Agacharse..."
		"mp_am_brief MAPS/Training/tr_movement04.txt" : "Saltar + Agacharse..."
		"mp_am_brief MAPS/Training/tr_movement05.txt" : "Escalera"
		"mp_am_brief MAPS/Training/tr_movement06.txt" : "Nadar..."
	]
]
@PointClass  iconsprite("sprites/trigger.spr") base(Targetname)= trigger_startpatrol : "Trigger Start Patrol"
[
	target(string) : "Target monster"
	m_iszPath(string) : "Patrol path start"
]

@PointClass base(Targetname) = trigger_random : "Trigger random" 
[
	noise(string) : "Target 1"
	frags(string) : "Target 2"
	enemy(string) : "Target 3"
	dmg(string) : "Target 4"
]

@PointClass base(Targetname) size(-16 -16 -16, 16 16 16) = player_weaponstrip : "Strip player's weapons"
[
      bullets(choices) : "Take 9mm bullets" : 0 =
	[
		0: "All"
		-2: "All except clips"
		-1: "Empty clips only"
		-3: "None"
	]
      magnum(choices) : "Take 357 bullets" : 0 =
	[
		0: "All"
		-2: "All except clip"
		-1: "Empty clip only"
		-3: "None"
	]
      shotgun(choices) : "Take shotgun ammo" : 0 =
	[
		0: "All"
		-2: "All except clip"
		-1: "Empty clip only"
		-3: "None"
	]
      crossbow(choices) : "Take crossbow bolts" : 0 =
	[
		0: "All"
		-2: "All except clip"
		-1: "Empty clip only"
		-3: "None"
	]
      argrenades(choices) : "Take AR grenades" : 0 =
	[
		0: "All"
		-1: "None"
	]
      rockets(choices) : "Take rockets" : 0 =
	[
		0: "All"
		-2: "All except clip"
		-1: "Empty clip only"
		-3: "None"
	]
      uranium(choices) : "Take uranium ammo" : 0 =
	[
		0: "All"
		-2: "All except clips"
		-1: "Empty clips only"
		-3: "None"
	]
      satchels(choices) : "Take satchel charges" : 0 =
	[
		0: "All"
		-1: "None"
	]
	snarks(choices) : "Take snarks" : 0 =
	[
		0: "All"
		-1: "None"
	]
	tripmines(choices) : "Take tripmines" : 0 =
	[
		0: "All"
		-1: "None"
	]
	handgrenades(choices) : "Take handgrenades" : 0 =
	[
		0: "All"
		-1: "None"
	]
	hornetgun(choices) : "Take Hornet Gun" : 0 =
	[
		0: "Gun & ammo"
		-3: "Ammo"
		-1: "None"
	]
	spawnflags(Flags) =
	[
		1: "Remove suit" : 0
		2: "Leave crowbar" : 0
		4: "Leave glock" : 0
		8: "Leave 357" : 0
		16: "Leave mp5" : 0
		64: "Leave crossbow" : 0
		128: "Leave shotgun" : 0
		256: "Leave rpg" : 0
		512: "Leave gauss" : 0
		1024: "Leave egon" : 0
	]
]
@SolidClass base(Targetname) = func_shine : "Shiny Surface"
[
	message(sprite) : "Shine sprite" : "sprites/bgspr.spr"
	scale(integer) : "Shine scale" : 10
	renderamt(integer) : "Shine brightness (0-255)" : 111
]


@SolidClass base(Breakable, RenderFields) = func_phy : "Objeto con propiedades Fisicas"
[
	spawnflags(flags) =
	[
		1 : "Dont Take Damage" : 0
		2 : "Dont Pick Off the floor"	   : 0
		128: "Is Not in the Floor" : 0
		256: "SOLID_BSP" : 0
	]

	frags(Choices) : "MATERIAL": 0 =
	[
		0 : "No Definido"
		1 : "Metal"
		2 : "Plastico"
		3 : "Vidrio"
		4 : "Concreto-Piedra"
		5 : "Madera"
	]


//	friction(integer) : "Friccion (0-1)" : "0.5"
	gravity(integer) : "Gravedad (0-1)" : 1

	_minlight(string) : "Minimum light level"
]
@SolidClass base(Targetname) = func_secret_zone : "SecretPlace" []
@SolidClass base(Targetname) = func_semtex_zone : "asd" 
[
	target(Choices) : "Target of semtex" : 1 =
	[
		1 : "semtex_obj"
	]
]

@SolidClass base(Targetname, Appearflags, RenderFields, Global) = func_wall_detail : "Wall detailed" 
[
	m_iszWallLow(string) : "Wall LEJOS" : "wall_low"
	m_iszWallNormal(string) : "Wall NORMAL" : "wall_normal"
	m_iszWallDetail(string) : "Wall DETALLADA" : "wall_detail"
	_minlight(string) : "Minimum light level"
]

@PointClass size(-16 -16 0, 16 16 36) base(Weapon) = xp_point_coin : "xp point" []
@PointClass size(-16 -16 0, 16 16 36) base(Weapon) = xp_point_gold : "10 xp point" []
@PointClass size(-16 -16 0, 16 16 36) base(Weapon) = xp_point_plate : "5 xp point" []
@PointClass size(-16 -16 0, 16 16 36) base(Weapon) = xp_point_brown : "1 xp point" []
@PointClass size(-4 -4 -4, 4 4 4) color(200 100 50) = info_savetitle : "savetitle" 
[
	netname(string) : "Map's Name"
]
@PointClass iconsprite("sprites/am/MapParams.spr") color(255 128 0) = info_texlights : "Textur lights" 
[	
// not shure if the spawn flag is supported
	spawnflags(flags) =
	[
              1 : "Override?"       : 1
	]
]

@PointClass iconsprite("sprites/am/InfoCompileParameters.spr") = info_compile_parameters : "Compile Options"
[
	texdata(string) : "Texture Data Memory" : "4096"
   	estimate(choices) :"Estimate Compile Times?" : "" =
	[
		"": "No"
		1: "yes"
	]

   	priority(choices) : "Priority Level" : "" =
	[
		"" : "Normal"
		1 : "High"
		-1 : "Low"
	]
    verbose(choices) : "Verbose compile messages" : "" =
    [
        "" : "Off"
        1 : "On"
    ]

hlcsg(choices) : "HLCSG" : 1 =
    [
        1 : "Normal"
        2 : "Onlyents"
        "" : "Off"
    ]
    wadautodetect(choices) : "Wad Auto Detect" : 1 =
    [
        1 : "On"
	"" : "Off"
    ]
    noclipeconomy(choices) : "Strip Uneeded Clipnodes?" : "" = 
    [
        "" : "Yes"
        1 : "No"
    ]
    noskyclip(choices) : "Clip sky" : "" =
    [
        "" : "Yes"
        1 : "No"
    ]
    nocliphull(choices) : "Generate clipping hulls" : "" =
    [
        "" : "Yes"
        1 : "No"
    ]
    cliptype(choices) : "clipping type" : 3 =
    [
        "" : "Smallest"
        1 : "Normalized"
        2 : "simple"
        3 : "Precise"
        4 : "Legacy"
    ]
    hullfile(string) : "Custom Hullfile"
    wadconfig(string) : "Custom Wad Configuration"

hlbsp(choices) : "HLBSP" : 1 =
    [
        "" : "Off" 
        1 : "Normal"
        2 : "Leakonly"
    ]

hlvis(choices) : "HLVIS" : 2 = 
    [ 
        "" : "Off"
        1 : "Fast"
        2 : "Normal" 
        3 : "Full"
    ]

hlrad(choices) : "HLRAD" : 1 =
    [
        "" : "Off"
        1 : "Normal"
        2 : "Extra"
    ]
    sparse(choices) : "Vismatrix Method" : 1 =
    [
        "" : "No Vismatrix"
        1 : "Sparse Vismatrix"
        2 : "Normal"
    ]
    bounce(integer) : "Number of radiosity bounces" : 1
    ambient(string) : "Ambient light (0.000 to 1.000, R G B)" : "0 0 0"
    smooth(integer) : "Smoothing threshold (in degrees)" : 0
    dscale(integer) : "Direct Lighting Scale" : 1
    chop(integer) : "Chop Size" : 64
    texchop(integer) : "Texture Light Chop Size" : 32
    lightdata(string) : "Light Data Memory in KB" : "6144"
    circus(choices) : "Circus RAD lighting" : "" =
    [
        "" : "Off"
        1 : "On"
    ]

]


@PointClass base(Targetname) = pys_rope : "rope"
[
	targetname(target_source) : "Nombre" : "rope_start"
	target(string) : "Objetivo" : "rope_end"
	message(string) : "Rope Filename" : "ropetest"
]

@PointClass base(Monster,MonsterCH) size(-16 -16 0, 16 16 72) = npc_antlion : "antlion" 
[
	model(studio) : "Modelo" : "models/hl2/Antlion.mdl"
]
@PointClass base(Monster,MonsterCH) size(-16 -16 0, 16 16 72) color (255 0 0) = npc_combine : "Human Grunt (camo)" 
[
	spawnflags(Flags) =
	[
		32 : "SquadLeader" : 0
		1024: "No arrojar arma" : 0
	]
	netname(string) : "Nombre de Equipo" 
	weapons(Choices) : "Armas" : 0 =
	[
		0 : "-AL AZAR-"
		1 : "MP7"
		3 : "MP7 + HG"
		5 : "MP7 + GL"
		8 : "Spas12"
		10 : "Spas12 + HG"
		16 : "I Rifle"
		18 : "I Rifle + HG"
	]

	model(studio) : "Modelo" : "models/hl2/combine.mdl"
]
@PointClass base(Monster,MonsterCH) size(-16 -16 0, 16 16 72) color (255 0 0) = npc_combine_metrocop : "Human Grunt (camo)" 
[
	spawnflags(Flags) =
	[
		32 : "SquadLeader" : 0
		1024: "No arrojar arma" : 0
	]
	netname(string) : "Nombre de Equipo"

	weapons(Choices) : "Armas" : 0 =
	[
		0 : "-AL AZAR-"
		1 : "MP7"
		3 : "MP7 + HG"
		5 : "MP7 + GL"
		8 : "Pistol"
		10 : "Pistol+ HG"
	]

	model(studio) : "Modelo" : "models/hl2/combine_metrocop.mdl"
]
@PointClass base(Monster,MonsterCH) size(-16 -16 0, 16 16 72) color (255 0 0) = npc_combine_supersoldier : "Human Grunt (camo)" 
[
	spawnflags(Flags) =
	[
		32 : "SquadLeader" : 0
		1024: "No arrojar arma" : 0
	]
	netname(string) : "Nombre de Equipo"

	weapons(Choices) : "Armas" : 0 =
	[ 		0 : "-AL AZAR-"
		1 : "MP7"
		3 : "MP7 + HG"
		5 : "MP7 + GL"
		8 : "Spas12"
		10 : "Spas12 + HG"
		16 : "I Rifle"
		18 : "I Rifle + HG"
	]

	model(studio) : "Modelo" : "models/hl2/combine_supersoldier.mdl"
]
@PointClass base(Monster) size(-360 -360 -172, 360 360 8) = npc_combine_helicopter : "C Helicopter" 
[
	spawnflags(Flags) = 
	[
		8 : "NoWreckage"	: 0
		64 : "Start Inactive" : 0
	]
	model(studio) : "Modelo" : "models/hl2/Combine_Helicopter.mdl"
]
@PointClass base(Monster) size(-16 -16 0, 16 16 72) = npc_combine_turret : "Sentry Turret Gun"
[
	model(studio) : "Modelo" : "models/hl2/combine_turret.mdl"

	spawnflags(Flags) = 
	[
		32 : "Autostart" : 0
		64 : "Start Inactive" : 0
	]
]

@PointClass base(Monster,MonsterCH) size(-16 -16 0, 16 16 72) = npc_zombie : "Zombie" 
[
	model(studio) : "Modelo" : "models/hl2/zombie.mdl"
]
@PointClass base(Monster,MonsterCH) size(-16 -16 0, 16 16 72) = npc_zombie_poison : "Zombie" 
[
	model(studio) : "Modelo" : "models/hl2/zombie_poison.mdl"
]
@PointClass base(Monster,MonsterCH) size(-16 -16 0, 16 16 72) = npc_zombie_fast : "Zombie" 
[
	model(studio) : "Modelo" : "models/hl2/Zombie_Fast.mdl"
]
@PointClass base(Monster,MonsterCH) size(-16 -16 0, 16 16 72) = npc_vortigaunt : "Vortigaunt" 
[
	netname(string) : "Squad Name"
	model(studio) : "Modelo" : "models/hl2/Vortigaunt.mdl"

	spawnflags(Flags) =
	[
		32 : "SquadLeader" : 0
		64 : "IgnorePlayer" : 0
	]
]
@PointClass base(Weapon, Targetx, RenderFields) = monster_he_grenade : "Live Handgrenade" 
[
	spawnflags(Flags) =
	[
		1 : "Start Active" : 0
	]
]
@PointClass base(Weapon, Targetx, RenderFields) = monster_smoke_grenade : "Live Handgrenade" 
[
	spawnflags(Flags) =
	[
		1 : "Start Active" : 0
	]
]
@PointClass base(Targetname, Angles, RenderFields) studio("models/am/prop_cable.mdl") = prop_cable : "New alternative to cyclers"
[	
	m_iszSequence_On(choices) : "Space Between Points" : "normal" =
	[
		"closer" : "Closer"
		"up-down" : "Closer Up-Down"
		"far" : "Far"
	]
	skin(choices) : "Rope Color" : 0 =
	[
		0: "Black"
		1: "Green"
		2: "Red"
		3: "Blue"
		4: "Random"
	]
	m_iAction_On(choices) : "Behaviour when on" : 0 =
	[
		1: "Loop"
	]

] 
@PointClass base(Targetname, Angles, RenderFields) studio("models/am/prop_cable_small.mdl") = prop_cable_small : "New alternative to cyclers"
[	
	m_iszSequence_On(choices) : "Space Between Points" : "closer" =
	[
		"closer" : "Closer"
		"up-down" : "Closer Up-Down"
		"far" : "Far"
	]
	skin(choices) : "Rope Color" : 0 =
	[
		0: "Black"
		1: "Green"
		2: "Red"
		3: "Blue"
		4: "Random"
	]
	m_iAction_On(choices) : "Behaviour when on" : 0 =
	[
		1: "Loop"
	]
]
@PointClass iconsprite("sprites/am/bugs.spr") base(Targetname, Angles, RenderFields)= prop_bugs : "New alternative to cyclers"
[	
	body(choices) : "Bugs Size" : "Normal" =
	[
		"0" : "Normal"
		"1" : "Small"
	]
	skin(choices) : "Bugs Type" : 0 =
	[
		0: "Flyers"
		1: "Lucierns"
	]
	m_iszSequence_On(choices) : "Bugs Speed" : "normal" =
	[
		"slow" : "Slow"
		"normal" : "Normal"
		"fast" : "Fast"
	]
	m_iAction_On(choices) : "Behaviour when on" : 1 =
	[
		1: "Loop"
	]
]

@PointClass base(Monster,MonsterCH)size(-16 -16 0, 16 16 72) color(255 1 1)  = monster_terrorist : "Terrorist" 
[
	spawnflags(Flags) =
	[
		32 : "SquadLeader" : 0
		1024: "Don't Drop Gun" : 0
		2048: "Don't Surrender" : 0
	]
	netname(string) : "Squad Name"
	frags(Choices) : "Weapons" : -1 =
	[
		-1: "Random"
		1 : "MP5/MP5-SD2"
		2 : "SPAS12"
		3 : "LAW"
		4 : "Sig3000"
		5 : "Assault -AK47-"
		6 : "Pistol -Glock18-"
		7 : "Desert Eagle"
		8 : "M249"
		9 : "KAMIKAZE"
	]
	model(studio) : "Modelo"
	skin(choices) : "Skin" : 1 = 
	[
		1 : "-1-"
		2 : "-2-"
		3 : "-3-"
		4 : "-4-"
	]
	asd(studio): "Fire when surrendered" : "surrendered"
]
@PointClass base(Monster,MonsterCH)size(-16 -16 0, 16 16 72) color(0 50 205)  = monster_agency_member : "Human Grunt whit Ak (camo)" 
[
	spawnflags(Flags) =
	[
		32 : "SquadLeader" : 0
		1024: "Don't Drop Gun" : 0
	]
	netname(string) : "Squad Name"
	frags(Choices) : "Weapons" : -1 =
	[
		-1: "Random"
		1 : "MP5/MP5-SD2"
		2 : "SPAS12"
		3 : "LAW"
		4 : "Sig3000"
		5 : "Assault -M4A1-"
		6 : "Pistol -Colt1911-"
		7 : "Desert Eagle"
		8 : "M249"
	]
	model(studio) : "Modelo"
	skin(choices) : "Skin" : 0 = 
	[
		0 : "Ninguno"
		1 : "-1-"
		2 : "-2-"
		1 : "-3-"
	]
]
@PointClass base(Targetname) = trigger_xppoints : "hi"
[
	frags(string) : "Points to change (+/-)"
	target(string) : "If we have points, fire..."
	noise1(string) : "...and show this message..." : "XP_GOOD"
	enemy(string) : "If we don't have points, fire..."
	noise2(string) : "...and show this message..." : "XP_BAD"
]
@PointClass base(Targetname) = trigger_check_cvar : "hi"
[
	netname(string) : "CVAR to Check"
	speed(integer) : "Value to Check"
	target(string) : "If ==, Fire..."
	noise1(string) : "...and show this msg" : "CVAR_OK"
	message(string) : "If !=, Fire..."
	noise2(string) : "...and show this msg" : "CVAR_FAILED"
	delay(integer) : "Delay before Fire"
	frags(string) : "Change Cvar (command value)"
]
@PointClass color(0 200 200) base(Targetname) size(-16 -16 -16, 16 16 16) = prop_fire : "Hello Kitty"
[
	spawnflags(Flags) =
	[
		1: "Start inactive" : 0
	]
	health(integer) : "Life (0 = Forever)"
]
@SolidClass base(Targetname, Angles) = func_grass: "Area Grass"
[
	message(string) : "Definition File" : "particles/generic_grass_example.txt"
]
@PointClass base(Targetname, Angles) = env_particleemitter: "Particle System Emitter"
[
	spawnflags(flags) =
	[
		1: "Start On" : 1
		2: "Triggerable" : 0
	]

	message(string) : "Definition File" : "particles/generic_particle_example.txt"

//	message (choices) : "Presets" : //"particles/generic_particle_example.txt"=
//	[
//		"particles/generic_particle_example.txt": "Default Particle
//		"particles/fog.txt": "Volumetric Fog"
//	]
]

@PointClass base(Targetname, Angles, RenderFields) size(-32 -32 0, 32 32 0) studio("models/am/prop_palm01.mdl") = prop_palm01: "Prop"
[	
	model(studio) : "Modelo" : "models/props/prop_palm01.mdl"

	spawnflags(flags) =
	[
		8: "Don't use LOD" : 0
		64: "Don't Check FOV" : 0
	]
]
@PointClass base(Targetname, Angles, RenderFields) size(-32 -32 0, 32 32 0) studio("models/am/prop_palm02.mdl") = prop_palm02: "Prop"
[	
	model(studio) : "Modelo" : "models/props/prop_palm02.mdl"

	spawnflags(flags) =
	[
		8: "Don't use LOD" : 0
		64: "Don't Check FOV" : 0
	]
]
@PointClass base(Targetname, Angles, RenderFields) size(-32 -32 0, 32 32 0) studio("models/am/prop_palmC01.mdl") = prop_palmC01: "Prop"
[	
	model(studio) : "Modelo" : "models/props/prop_palmC01.mdl"

	spawnflags(flags) =
	[
		8: "Don't use LOD" : 0
		64: "Don't Check FOV" : 0
	]
]
@PointClass base(Targetname, Angles, RenderFields) size(-32 -32 0, 32 32 0) studio("models/am/prop_bush01.mdl") = prop_bush01: "Prop"
[	
	model(studio) : "Modelo" : "models/props/prop_bush01.mdl"

	spawnflags(flags) =
	[
		8: "Don't use LOD" : 0
		64: "Don't Check FOV" : 0
	]
]
@PointClass base(Targetname, Angles, RenderFields) size(-32 -32 0, 32 32 0) studio("models/am/prop_bush02.mdl") = prop_bush02: "Prop"
[	
	model(studio) : "Modelo" : "models/props/prop_bush02.mdl"

	spawnflags(flags) =
	[
		8: "Don't use LOD" : 0
		64: "Don't Check FOV" : 0
	]
]
@PointClass base(Targetname, Angles, RenderFields) size(-32 -32 0, 32 32 0) studio("models/am/prop_fern01.mdl") = prop_fern01: "Prop"
[	
	model(studio) : "Modelo" : "models/props/prop_fern01.mdl"

	spawnflags(flags) =
	[
		8: "Don't use LOD" : 0
		64: "Don't Check FOV" : 0
	]
]
@PointClass base(Targetname) iconsprite("sprites/am/InfoCompileParameters.spr") = trigger_sequence : "Sequence File trigger"
[
	sequence_file(string):"Sequence File": "SEQUENCE_FILE.seq"
	sequence_id(string):"Sequence Name":"SequenceNameHere"
	spawnflags(flags) =
	[
		1: "???" : 0
	]
]
@SolidClass base(Breakable, RenderFields) = func_lamp : "Breakable Object" 
[
	spawnflags(Flags) = 
	[
		1 : "Start ON" 	: 1
	]
	_minlight(string) : "Minimum light level"
]
@SolidClass base(Targetname ) = func_mirror : "Mirror" 
[
	alpha(integer) : "Alpha"
	spawnflags(flags) =
	[
		2 : "NOT SOLID" : 0
	]
]
@SolidClass base(Targetname) = func_monitor : "Monitor" 
[
	mode(choices) : "Mode" : 0 =
	[
		0 : "black&white"
		1 : "color"
	]
	type(choices) : "Type" : 0 =
	[
		0 : "HL2 Style"
		1 : "DN3D Style"
	]

	camera(string) : "Camera"
	spawnflags(flags) =
	[
		1 : "START ON" : 0
		2 : "NOT SOLID" : 0
	]
]
@SolidClass base(func_wall) = func_collision : "Toggleable geometry" 
[
	spawnflags(flags) =
	[
		1 : "Starts Invisible" : 0
		8: "Don't Collidable" : 0
	]

	frags(Choices) : "Material": 0 =
	[
		0 : "No Definido (Concreto)"
		1 : "Metal"
		5 : "Madera"
		6 : "WaterSplash"
	]
]
*/